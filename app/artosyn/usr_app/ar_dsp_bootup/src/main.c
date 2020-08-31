#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include "ar_dsp_bootup.h"

int main(int argc,char* argv[])
{
    int ret = 0;
	int flag = 0;
	int dsp_id = MAX_DSP_CORE;
	
    if(argc < 3)
    {
        printf("Usage: ar_dsp_bootup [0,1,2,3] [/mnt/ceva0.bin] \r\n");
		return -1;
    }


	dsp_id = atoi(argv[1]);
		
	if(dsp_id < 0 || dsp_id >= MAX_DSP_CORE)
	{
		printf("Usage: ar_dsp_bootup [0,1,2,3] [/mnt/ceva0.bin] \r\n");
		return -1;
	}
   
	printf("sirius boot ceva %d ...\n",dsp_id);
	ret = sirius_boot_ceva(argv[2],dsp_id);  
	if(ret < 0)
	{
		printf("sirius boot ceva %d failed...\n",dsp_id);
		return -1;
	}
	printf("sirius boot ceva %d finished...\n",dsp_id);

	return 0;
}




