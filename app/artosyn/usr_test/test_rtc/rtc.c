#include <stdio.h>
#include <linux/rtc.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>

static const char default_rtc[] = "/dev/rtc0";

static void usage(const char *argv0)
{
	printf("Usage: %s [options]\n", argv0);
	printf("Available options are\n");
	printf(" -d /dev/rtcN   		Set rtc device\n");
	printf(" -s \"YYYY-MM-DDD HH:MM:SS\"	Set rtc time\n");
	printf(" -g             		Get rtc time\n");
	printf(" -h             		Display help\n");
}

int main(int argc, char **argv)
{
	int i, fd, retval, opt = 0;
	unsigned long tmp, data;
	struct rtc_time current, new;
	const char *rtc = default_rtc;
	char *input = NULL;

	while ((opt = getopt(argc, argv, "d:s:gh")) != -1) 
	{
		switch (opt) 
		{
			case 'd':
				rtc = optarg;
				break;
			case 's':
				input = optarg;
				break;
			case 'h':
				usage(argv[0]);
				return 0;
			case 'g':
			default :
				break;				
		}
	}

	fd = open(rtc, O_RDONLY);
	if (fd ==  -1) 
	{
		perror(rtc);
		exit(errno);
	}

	if(input)
	{
		sscanf(input, "%d-%d-%d %d:%d:%d", &new.tm_year, &new.tm_mon, &new.tm_mday, &new.tm_hour, &new.tm_min, &new.tm_sec);

		new.tm_mon -= 1;
		new.tm_year -= 1900;

		printf("Test will set RTC date/time to %d-%d-%d, %02d:%02d:%02d.\n",
			new.tm_year + 1900, new.tm_mon + 1, new.tm_mday,
			new.tm_hour, new.tm_min, new.tm_sec);

		/* Write the new date in RTC */
		retval = ioctl(fd, RTC_SET_TIME, &new);
		if (retval == -1) {
			perror("RTC_SET_TIME ioctl");
			close(fd);
			exit(errno);
		}
	}

	/* Read back */
	retval = ioctl(fd, RTC_RD_TIME, &current);
	if (retval == -1) {
		perror("RTC_RD_TIME ioctl");
		exit(errno);
	}

	printf("\n\nCurrent RTC date/time is %d-%d-%d, %02d:%02d:%02d.\n",
		current.tm_year + 1900, current.tm_mon + 1, current.tm_mday,
		current.tm_hour, current.tm_min, current.tm_sec);

	close(fd);

	return 0;
}
