#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define OTP_DEV "/dev/ar_otp"
//#define OTP_DEV "./otp_test.txt"

static int otp_read(int fd, int addr, int *value)
{
	int ret;

	ret = lseek(fd, addr, SEEK_SET);
	if(ret < 0) {
		printf("lseek otp fail\n");
		return -1;
	}

	ret = read(fd, value, 4);
	if(ret < 0) {
		printf("read otp fail\n");
		return -1;
	}
	return 0;
}

static int otp_write(int fd, int addr, int value)
{
	int ret;
	int tmp;

	ret = lseek(fd, addr, SEEK_SET);
	if(ret < 0) {
		printf("lseek otp fail\n");
		return -1;
	}

	ret = write(fd, &value, 4);
	if(ret < 0) {
		printf("write otp fail\n");
		return -1;
	}

	ret = otp_read(fd, addr, &tmp);
	if(ret < 0) {
		printf("read otp fail\n");
		return -1;
	}

	if(value != tmp) {
		printf("error, write %08x, read back %08x\n", value, tmp);
		return -1;
	}
	return 0;
}

void show_usage(void)
{
	printf("otputil usage\n\n");
	printf("otp read:\n");
	printf("   otputil -r <addr> <size>\n\n");
	printf("otp write(one word):\n");
	printf("   otputil -w <addr> <value>\n\n");
	printf("otp program from config file:\n");
	printf("   otputil -pc <config file>\n\n");
	printf("otp program from bin file:\n");
	printf("   otputil -pb <addr> <bin file>\n\n");
	printf("config file format:<addr:value>\n");
	printf("   example\n");
	printf("   0x00000000:0xffff0000\n");
	printf("   0x00000004:0xffff0001\n");
	printf("   0x00000008:0xffff0002\n");
}

int main(int argc, char *argv[])
{
	int i, fd_dev, ret;
	char *endp;

	if(argc < 2) {
		show_usage();
		return 0;
	}

	if(strcmp(argv[1], "-h") == 0 ||
		strcmp(argv[1], "--help") == 0) {
		show_usage();
	}

	fd_dev = open(OTP_DEV, O_RDWR);
	if(fd_dev < 0) {
		printf("open %s fail\n", OTP_DEV);
		return 0;
	}

	if(strcmp(argv[1], "-r") == 0) {
		int addr, size;
		unsigned char *buffer;

		if(argc < 4) {
			show_usage();
			goto error;
		}

		addr = strtoul(argv[2], &endp, 16);
		size = strtoul(argv[3], &endp, 16);

		if(addr & 0x3) {
			printf("error, address is not 4 bytes aligned\n");
			goto error;
		}

		buffer = malloc(size);
		if(!buffer) {
			printf("malloc %x bytes fail\n", size);
			goto error;
		}

		printf("Read addr 0x%08x, size 0x%08x\n", addr, size);

		ret = lseek(fd_dev, addr, SEEK_SET);
		if(ret < 0) {
			printf("lseek otp fail\n");
			free(buffer);
			goto error;
		}

		ret = read(fd_dev, buffer, size);
		if(ret < 0) {
			printf("read otp fail\n");
			free(buffer);
			goto error;
		}

		for(i = 0; i < ret; i++) {
			printf("%02x ", buffer[i]);
			if((i + 1) % 16 == 0 || (i + 1) == ret)
				printf("\n");
		}
		free(buffer);
	}
	else if(strcmp(argv[1], "-w") == 0) {
		int addr, value;

		if(argc < 4) {
			show_usage();
			goto error;
		}

		addr = strtoul(argv[2], &endp, 16);
		value = strtoul(argv[3], &endp, 16);

		if(addr & 0x3) {
			printf("error, address is not 4 bytes aligned\n");
			goto error;
		}

		ret = lseek(fd_dev, addr, SEEK_SET);
		if(ret < 0) {
			printf("lseek otp fail\n");
			goto error;
		}

		printf("Write addr 0x%08x, value 0x%08x\n", addr, value);

		ret = write(fd_dev, &value, 4);
		if(ret < 0) {
			printf("write otp fail\n");
			goto error;
		}
	}
	else if(strcmp(argv[1], "-pc") == 0) {
		FILE *file;
		int addr, value;
		char buffer[64], *res;

		if(argc < 3) {
			show_usage();
			goto error;
		}

		file = fopen(argv[2], "r");
		if(!file) {
			printf("open %s fail\n", argv[1]);
			goto error;
		}

		while(1) {
			memset(buffer, 0, sizeof(buffer));

			res = fgets(buffer, sizeof(buffer), file);
			if(!res)
				break;

			sscanf(buffer, "0x%08x:0x%08x\n", &addr, &value);

			if(addr & 0x3) {
				printf("error, address is not 4 bytes aligned\n");
				goto error;
			}

			ret = lseek(fd_dev, addr, SEEK_SET);
			if(ret < 0) {
				printf("seek otp fail\n");
				break;
			}

			printf("Write addr %08x, value %08x\n", addr, value);

			ret = write(fd_dev, &value, 4);
			if(ret < 0) {
				printf("write otp fail\n");
				break;
			}

		}
		fclose(file);
	}
	else if(strcmp(argv[1], "-pb") == 0) {
		int fd, addr, value, size;
		char *buffer;
		struct stat st;

		if(argc < 4) {
			show_usage();
			goto error;
		}

		addr = strtoul(argv[2], &endp, 16);
		if(addr & 0x3) {
			printf("error, address is not 4 bytes aligned\n");
			goto error;
		}

		ret = stat(argv[3], &st);
		if(ret < 0) {
			printf("stat %s fail\n", argv[3]);
			goto error;
		}

		size = st.st_size;
		if(size & 0x3) {
			printf("error, bin size is not 4 bytes aligned\n");
			goto error;
		}

		fd = open(argv[3], O_RDONLY);
		if(fd < 0) {
			printf("open %s fail\n", argv[3]);
			goto error;
		}

		buffer = malloc(size);
		if(!buffer) {
			printf("malloc buffer fail\n");
			close(fd);
			goto error;
		}

		ret = read(fd, buffer, size);
		if(ret < 0) {
			printf("read %s fail\n", argv[3]);
			close(fd);
			free(buffer);
			goto error;
		}

		ret = lseek(fd_dev, addr, SEEK_SET);
		if(ret < 0) {
			printf("seek otp fail\n");
			close(fd);
			free(buffer);
			goto error;
		}

		printf("Write addr %08x, size %08x\n", addr, size);

		ret = write(fd_dev, buffer, size);
		if(ret < 0) {
			printf("write otp fail\n");
			close(fd);
			free(buffer);
			goto error;
		}

		free(buffer);
		close(fd);
	}
	else {
		show_usage();
		goto error;
	}
error:
	close(fd_dev);
	return 0;
}
