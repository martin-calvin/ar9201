/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : usb_op_test.c
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/8/29
*  Last Modified :
*  Description   : 
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/8/29
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "stdio.h"
#include "basic_typedef.h"
#include "logutil.h"
#include "usb_op_test.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/

int32_t usb_op_test_process(unsigned char cmd_name[])
{
    unsigned char cmd[128];

    memset(cmd, 0, sizeof(cmd));
    strcpy(cmd, cmd_name+9); // "/stroage/"
    
    INFO("cmd: %s\n", cmd);


    if (0 == strcmp(cmd, "ob_adb_on"))
    {
        system("/usrdata/usr/data/doraemon/adb_control.sh adb_on");
    }
    else if (0 == strcmp(cmd, "ob_adb_off"))
    {
        system("/usrdata/usr/data/doraemon/adb_control.sh adb_off");    
    }
    else if (0 == strcmp(cmd, "ob_force_upgrade"))
    {
        system("fw_setenv orbbec_force_upgrade_flag y");
    }
    else
    {

    }

    return 0;
}

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

