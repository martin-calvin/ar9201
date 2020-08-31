#ifndef     __SYS_CALIBRATION_UPGRADE_H__
#define     __SYS_CALIBRATION_UPGRADE_H__

unsigned int write_to_file(char * data, unsigned char * path, unsigned int len);
int magic_num_check(unsigned char * data);
int compare_chars(unsigned char * data1, unsigned char * data2, int len);
int md5_sum(unsigned char *encrypt, int len, unsigned char *decrypt);

#endif