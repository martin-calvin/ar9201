
/*---------------header of imx307 tuing-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x20190910,
/*tuning_ctl_t tuning_ctl  */
{
  //float aec_trigger_tolerence;
  3,
  //float aec_trigger_tolerence_gain
  0.3,
  //float awb_trigger_tolerence; /
  50,
},
/*isp_tuning_t isp_tuning */
{
  /*isp version */
  0x00000001,
    /*isp_sub_module_raw_crop_tuning_t isp_sub_module_raw_crop_tuning*/
    {
       /*enable:*/
       1,
       /*interpolation enable*/
       0,
    },
    /* isp_sub_module_blc_tuning_t isp_sub_module_blc_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       5,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       {
          /*region 1 */
          {
            1.000,
            32.000,
          },
          /*region 2 */
          {
            120.000,
            130.000,
          },
          /*region 3 */
          {
            510.000,
            520.000,
          },
          /*region 4 */
          {
            1020.000,
            1030.000,
          },
          /*region 5 */
          {
            2000.000,
            2100.000,
          },
       },
       {
           /*parameter 1 */
           {
               958,
               958,
               958,
               958,
               272,
               272,
               272,
               272,
           },
           /*parameter 2 */
           {
               946,
               944,
               946,
               944,
               272,
               272,
               272,
               272,
           },
           /*parameter 3 */
           {
               1048,
               1061,
               1047,
               1063,
               274,
               274,
               274,
               274,
           },
           /*parameter 4 */
           {
               1586,
               1625,
               1591,
               1624,
               284,
               285,
               284,
               285,
           },
           /*parameter 5 */
           {
               2628,
               2601,
               2633,
               2591,
               305,
               305,
               306,
               305,
           },
       },
    },
    /*isp_sub_module_hdr_mix_tuning_t isp_sub_module_hdr_mix_tuning;*/
    {

    },
    /* isp_sub_module_compander_tuning_t isp_sub_module_compander_tuning*/
    {
    },
    /* isp_sub_module_dpc_tuning_t isp_sub_module_dpc_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       0,
       /*count_ae*/
       5,
       /*0 for dynamic dpc, 1 for static dpc*/
       0,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       {
            0,
            0,
            1,
            1,
            1,
       },
       {
          /*aec trigger 1 */
          {
            1.000,
            3.000,
          },
          /*aec trigger 2 */
          {
            4.000,
            6.000,
          },
          /*aec trigger 3 */
          {
            8.000,
            12.000,
          },
          /*aec trigger 4 */
          {
            16.000,
            32.000,
          },
          /*aec trigger 5 */
          {
            128.000,
            130.000,
          },
       },
       /*aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT] MIDDLE_TRIGGER_COUNT==5 */
       {
           /*parameter 1 */
           {
               0x0000004c,0x00000000,0x00000fff,0x000000c8,0x00000320,0x00000fff,0x000000c8,0x00000320,0x00000fff,0x00000190,               
               0x00000320,0x00000fff,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,               
               0x00000000,0x00000020,0x00000060,0x000000a0,0x000000e0,           
           },
           /*parameter 2 */
           {
               0x00000019,0x00000000,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x00000190,               
               0x00000320,0x0000003c,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,               
               0x00000000,0x00000020,0x00000060,0x000000a0,0x000000e0,           
           },
           /*parameter 3 */
           {
               0x00000026,0x00000000,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x00000190,               
               0x00000320,0x0000003c,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,               
               0x00000000,0x00000020,0x00000060,0x000000a0,0x000000e0,           
           },
           /*parameter 4 */
           {
               0x0000004c,0x00000000,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x00000190,               
               0x00000320,0x0000003c,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,               
               0x00000000,0x00000020,0x00000060,0x000000a0,0x000000e0,           
           },
           /*parameter 5 */
           {
               0x0000004c,0x00000000,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x00000190,               
               0x00000320,0x0000003c,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,               
               0x00000000,0x00000020,0x00000060,0x000000a0,0x000000e0,           
           },
       },
    },
    /*isp_sub_module_cac_tuning_t isp_sub_module_cac_tuning*/
    {
        0,//enable
        1,//interpolation enable
        1,//ae count
        0,//0:1/2 size  1:true center_height
		1,// center_width ratio
		1,// center_height ratio
        1,//trigger_mode : 0 gain trigger 1 lux trigger
        /* aec trigger */
        {
        	/*trigger 0*/
        	{
        		0,
        		345,
        	},
        	/*trigger 1*/
        	{
        	},
        	/*trigger 2*/
        	{
        	},
        	/*trigger 3*/
        	{
        	},
        	/*trigger 4*/
        	{
        	},
        },
	    /* isp_sub_module_cac_pra pra[5][7] */
        {
		   /* para 0 */
		   {
		      /* rx_p[20] */
		      {
			      -49,447,-218,1228,-428,-5424,-7057,-308,16960,
				  24,-53,-48,-142,197,60,233,-159,584,-1338,
			  },
			  /* bx_p[20] */
			  {
			      98,1995,215,-1563,-498,-60,6672,4439,-3163,-9765,
				  56,246,2908,-268,-538,-244,-270,-2557,1128,-2995,
			  },
		   },
		   /* para 1 */
		   {
		   },
		   /* para 1 */
		   {
		   },
		   /* para 1 */
		   {
		   },
		   /* para 1 */
		   {
		   },
	    },
	},
    /* isp_sub_module_ata_tuning_t isp_sub_module_ata_tuning;*/
    {

    },
    /* isp_sub_module_rnr_tuning_t isp_sub_module_rnr_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       13,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       /*aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT] MIDDLE_TRIGGER_COUNT==5 */
       {
          /*aec trigger 1 */
          {
            1.000,
            1.100,
          },
          /*aec trigger 2 */
          {
            2.000,
            2.100,
          },
          /*aec trigger 3 */
          {
            4.000,
            4.100,
          },
          /*aec trigger 4 */
          {
            8.000,
            8.100,
          },
          /*aec trigger 5 */
          {
            12.000,
            12.100,
          },
          /*aec trigger 6 */
          {
            16.000,
            16.100,
          },
          /*aec trigger 7 */
          {
            32.000,
            32.100,
          },
          /*aec trigger 8 */
          {
            64.000,
            64.100,
          },
          /*aec trigger 9 */
          {
            128.000,
            128.100,
          },
          /*aec trigger 10 */
          {
            256.000,
            256.100,
          },
          /*aec trigger 11 */
          {
            512.000,
            512.100,
          },
          /*aec trigger 12 */
          {
            1024.000,
            1024.100,
          },
          /*aec trigger 13 */
          {
            2048.000,
            2048.100,
          },
       },
       /*isp_sub_module_rnr_pra pra[MIDDLE_TRIGGER_COUNT]*/
       {
            /* para 1 */
            {
                1,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {45,135,127},
                        //g channel
                        {45,135,127},
                        //b channel
                        {45,135,127},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {30,90,60},
                        //g channel
                        {30,90,60},
                        //b channel
                        {30,90,60},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {15,45,29},
                        //g channel
                        {15,45,29},
                        //b channel
                        {15,45,29},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 2 */
            {
                1,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {50,150,142},
                        //g channel
                        {50,150,142},
                        //b channel
                        {50,150,142},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {40,120,80},
                        //g channel
                        {40,120,80},
                        //b channel
                        {40,120,80},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {20,60,39},
                        //g channel
                        {20,60,39},
                        //b channel
                        {20,60,39},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 3 */
            {
                1,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {70,210,200},
                        //g channel
                        {70,210,200},
                        //b channel
                        {70,210,200},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {40,120,80},
                        //g channel
                        {40,120,80},
                        //b channel
                        {40,120,80},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {30,90,60},
                        //g channel
                        {30,90,60},
                        //b channel
                        {30,90,60},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 4 */
            {
                2,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {90,270,258},
                        //g channel
                        {90,270,258},
                        //b channel
                        {90,270,258},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {75,225,153},
                        //g channel
                        {75,225,153},
                        //b channel
                        {75,225,153},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {30,90,60},
                        //g channel
                        {30,90,60},
                        //b channel
                        {30,90,60},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 5 */
            {
                2,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {120,360,345},
                        //g channel
                        {120,360,345},
                        //b channel
                        {120,360,345},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {90,270,184},
                        //g channel
                        {90,270,184},
                        //b channel
                        {90,270,184},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {40,120,80},
                        //g channel
                        {40,120,80},
                        //b channel
                        {40,120,80},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 6 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {150,450,432},
                        //g channel
                        {150,450,432},
                        //b channel
                        {150,450,432},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {120,360,246},
                        //g channel
                        {120,360,246},
                        //b channel
                        {120,360,246},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {60,180,122},
                        //g channel
                        {60,180,122},
                        //b channel
                        {60,180,122},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 7 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {180,540,519},
                        //g channel
                        {180,540,519},
                        //b channel
                        {180,540,519},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {150,450,308},
                        //g channel
                        {150,450,308},
                        //b channel
                        {150,450,308},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {100,300,205},
                        //g channel
                        {100,300,205},
                        //b channel
                        {100,300,205},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 8 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {220,660,635},
                        //g channel
                        {220,660,635},
                        //b channel
                        {220,660,635},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {180,540,370},
                        //g channel
                        {180,540,370},
                        //b channel
                        {180,540,370},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {150,450,308},
                        //g channel
                        {150,450,308},
                        //b channel
                        {150,450,308},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 9 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {300,900,867},
                        //g channel
                        {300,900,867},
                        //b channel
                        {300,900,867},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {260,780,536},
                        //g channel
                        {260,780,536},
                        //b channel
                        {260,780,536},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {200,600,412},
                        //g channel
                        {200,600,412},
                        //b channel
                        {200,600,412},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 10 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {400,1200,1157},
                        //g channel
                        {400,1200,1157},
                        //b channel
                        {400,1200,1157},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {350,1050,723},
                        //g channel
                        {350,1050,723},
                        //b channel
                        {350,1050,723},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {300,900,619},
                        //g channel
                        {300,900,619},
                        //b channel
                        {300,900,619},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 11 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {650,1950,1882},
                        //g channel
                        {650,1950,1882},
                        //b channel
                        {650,1950,1882},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {600,1800,1240},
                        //g channel
                        {600,1800,1240},
                        //b channel
                        {600,1800,1240},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {550,1650,1137},
                        //g channel
                        {550,1650,1137},
                        //b channel
                        {550,1650,1137},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 12 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {750,2250,2172},
                        //g channel
                        {750,2250,2172},
                        //b channel
                        {750,2250,2172},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {700,2100,1448},
                        //g channel
                        {700,2100,1448},
                        //b channel
                        {700,2100,1448},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {650,1950,1344},
                        //g channel
                        {650,1950,1344},
                        //b channel
                        {650,1950,1344},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
            /* para 13 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {800,2400,2317},
                        //g channel
                        {800,2400,2317},
                        //b channel
                        {800,2400,2317},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {800,2400,1655},
                        //g channel
                        {800,2400,1655},
                        //b channel
                        {800,2400,1655},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {800,2400,1655},
                        //g channel
                        {800,2400,1655},
                        //b channel
                        {800,2400,1655},
                    },
                },
                /* profile_t profile[RNR_CHANNEL_COUMT] */
                {
                    /* r channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* g channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                    /* b channel */
                    {
                        /* noise profile */
                        {3000,1500,500},
                        /* noise profile gain */
                        {16,16,14,13},
                    },
                },
                /* edge_t edge */
                {
                     /* edge_V */
                     {13,16,20,26,40,53,80,160},
                     /* edge_Level */
                     {10,10,10,12,12,13,14,15,16},
                },
            },
       },
    },
    /* isp_sub_module_decompader_tuning_t isp_sub_module_decompader_tuning*/
    {

    },
    /* isp_sub_module_lsc_tuning_t isp_sub_module_lsc_tuning*/
    {
        1,//enable
        1,//interpolation enable
		1,//count ae
        4,//awb count
		1,//trigger_mode : 0 gain trigger 1 lux trigger
		{
     		/*aec trigger 1*/
     		{
     			0,
     			500,
     		},
		},
        {
     		/*awb trigger 1*/
     		{
     			2700,
     			2800,
     		},
     		/*awb trigger 2*/
     		{
     			3900,
     			4200,
     		},
     		/*awb trigger 3*/
     		{
     			4900,
     			5100,
     		},
     		/*awb trigger 4*/
     		{
     			6400,
     			6600,
     		},
     		/*awb trigger 5*/
     		{
     			0,
     			0,
     		},
     		/*awb trigger 6*/
     		{
     			0,
     			0,
     		},
        },
        /* isp_sub_module_lsc_pra */
        {
			{
				/* para 1 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.2202, 2.3086, 1.7324, 1.4585, 1.3359, 1.3369, 1.4771, 1.7173, 2.1641, 3.1294, 
					  2.9429, 2.0015, 1.5903, 1.3237, 1.2026, 1.1982, 1.2744, 1.5166, 1.8950, 2.6621, 
					  2.5537, 1.8838, 1.4634, 1.2158, 1.1045, 1.0791, 1.2070, 1.4092, 1.7739, 2.4717, 
					  2.4224, 1.7769, 1.3706, 1.1519, 1.0176, 0.9937, 1.1099, 1.3359, 1.6826, 2.2935, 
					  2.3706, 1.7085, 1.3628, 1.1089, 0.9907, 0.9839, 1.0698, 1.2900, 1.6182, 2.2100, 
					  2.3389, 1.7129, 1.3481, 1.1069, 0.9873, 0.9736, 1.0669, 1.2935, 1.6265, 2.2837, 
					  2.3833, 1.7578, 1.3618, 1.1489, 0.9990, 0.9800, 1.1069, 1.3267, 1.6602, 2.2446, 
					  2.5825, 1.8315, 1.4663, 1.2026, 1.0845, 1.0781, 1.1733, 1.3975, 1.7368, 2.4448, 
					  2.7334, 1.9873, 1.5347, 1.3198, 1.1758, 1.1870, 1.2588, 1.4907, 1.8638, 2.5908, 
					  3.2158, 2.1929, 1.7383, 1.4399, 1.3359, 1.2925, 1.4067, 1.6577, 2.0420, 2.9688, 
					  3.2300, 2.2642, 1.7559, 1.4375, 1.3403, 1.3687, 1.4766, 1.7412, 2.1914, 3.1934, 
					  2.8931, 2.0259, 1.5732, 1.3345, 1.2139, 1.1812, 1.2988, 1.5000, 1.9131, 2.6558, 
					  2.5869, 1.8594, 1.4688, 1.2134, 1.1060, 1.0908, 1.2070, 1.4238, 1.7803, 2.4834, 
					  2.3833, 1.7832, 1.3618, 1.1587, 1.0176, 0.9980, 1.1206, 1.3237, 1.7007, 2.3164, 
					  2.3706, 1.7075, 1.3535, 1.1133, 0.9883, 0.9844, 1.0757, 1.3057, 1.6162, 2.2627, 
					  2.3501, 1.6958, 1.3555, 1.1123, 0.9854, 0.9824, 1.0698, 1.2974, 1.6328, 2.2813, 
					  2.3784, 1.7744, 1.3643, 1.1489, 1.0146, 0.9897, 1.1182, 1.3354, 1.6709, 2.2788, 
					  2.5972, 1.8105, 1.4692, 1.2104, 1.0811, 1.0820, 1.1831, 1.3936, 1.7568, 2.4326, 
					  2.7529, 1.9956, 1.5366, 1.3203, 1.1890, 1.1865, 1.2788, 1.5020, 1.8721, 2.6353, 
					  3.2314, 2.1816, 1.7261, 1.4561, 1.3247, 1.3208, 1.4219, 1.6460, 2.1235, 2.9644, 
					  3.1064, 2.2056, 1.7026, 1.4136, 1.3306, 1.3408, 1.4243, 1.6704, 2.1284, 2.9355, 
					  2.8926, 1.9487, 1.5615, 1.3315, 1.2002, 1.2080, 1.2808, 1.5205, 1.8569, 2.6416, 
					  2.4482, 1.8369, 1.4360, 1.2031, 1.1011, 1.0776, 1.1992, 1.3906, 1.7559, 2.4126, 
					  2.4160, 1.7188, 1.3652, 1.1514, 1.0229, 1.0020, 1.0967, 1.3472, 1.6382, 2.3301, 
					  2.2910, 1.6880, 1.3403, 1.0981, 0.9893, 0.9810, 1.0752, 1.2622, 1.6123, 2.1738, 
					  2.2607, 1.6621, 1.3433, 1.0859, 0.9771, 0.9683, 1.0757, 1.2910, 1.6138, 2.2729, 
					  2.3618, 1.7202, 1.3457, 1.1348, 1.0146, 0.9541, 1.1064, 1.2920, 1.6504, 2.1758, 
					  2.5161, 1.7637, 1.4526, 1.1846, 1.0571, 1.0928, 1.1660, 1.3828, 1.7158, 2.3599, 
					  2.5825, 1.9370, 1.4985, 1.3052, 1.1880, 1.1685, 1.2598, 1.4736, 1.8267, 2.5317, 
					  3.1626, 2.0835, 1.7041, 1.4131, 1.3174, 1.3242, 1.3965, 1.6318, 2.0303, 2.7891, 
					},
				},
				/* para 2 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.3242, 2.4097, 1.8091, 1.5098, 1.3809, 1.3667, 1.4922, 1.7446, 2.2568, 3.1216, 
					  3.0313, 2.0576, 1.6299, 1.3457, 1.2100, 1.1851, 1.3062, 1.5142, 1.9614, 2.6587, 
					  2.6812, 1.9736, 1.5044, 1.2505, 1.1245, 1.0835, 1.2109, 1.4375, 1.8213, 2.5083, 
					  2.5083, 1.8140, 1.4087, 1.1602, 1.0142, 0.9839, 1.1250, 1.3164, 1.7407, 2.2866, 
					  2.4243, 1.7749, 1.3794, 1.1260, 0.9956, 0.9829, 1.0767, 1.3047, 1.6558, 2.2954, 
					  2.4253, 1.7461, 1.3882, 1.1143, 0.9893, 0.9780, 1.0596, 1.2900, 1.6699, 2.2695, 
					  2.4692, 1.8037, 1.3936, 1.1655, 1.0010, 0.9883, 1.1216, 1.3306, 1.7280, 2.2710, 
					  2.6851, 1.8774, 1.5103, 1.2266, 1.1025, 1.0835, 1.1880, 1.4072, 1.7861, 2.4180, 
					  2.8809, 2.0283, 1.5977, 1.3452, 1.1938, 1.1880, 1.3003, 1.5166, 1.9385, 2.6465, 
					  3.3057, 2.2300, 1.7520, 1.4824, 1.3584, 1.3291, 1.4282, 1.6953, 2.0923, 2.9990, 
					  3.4385, 2.3442, 1.7939, 1.4839, 1.3394, 1.3735, 1.4873, 1.7368, 2.2422, 3.1455, 
					  2.9839, 2.0483, 1.5972, 1.3369, 1.2173, 1.1963, 1.2974, 1.5068, 1.9307, 2.6523, 
					  2.6411, 1.9136, 1.4795, 1.2393, 1.0991, 1.0884, 1.2075, 1.4170, 1.7983, 2.4956, 
					  2.5264, 1.7847, 1.3955, 1.1582, 1.0161, 0.9946, 1.1172, 1.3228, 1.7090, 2.2930, 
					  2.3936, 1.7368, 1.3633, 1.1157, 0.9966, 0.9854, 1.0742, 1.2954, 1.6328, 2.2607, 
					  2.4063, 1.7188, 1.3672, 1.1221, 0.9902, 0.9839, 1.0630, 1.3008, 1.6401, 2.2998, 
					  2.4692, 1.7734, 1.3784, 1.1533, 1.0093, 0.9961, 1.1147, 1.3364, 1.6948, 2.3091, 
					  2.6133, 1.8677, 1.4805, 1.2246, 1.0957, 1.0757, 1.1821, 1.3970, 1.7651, 2.4458, 
					  2.8486, 2.0010, 1.5508, 1.3203, 1.1885, 1.1885, 1.2900, 1.5083, 1.9214, 2.6592, 
					  3.2656, 2.2427, 1.7539, 1.4771, 1.3447, 1.3271, 1.4238, 1.6636, 2.1104, 3.0825, 
					  3.2393, 2.3042, 1.7720, 1.4248, 1.3330, 1.3447, 1.4702, 1.7173, 2.2124, 3.1265, 
					  2.9688, 2.0127, 1.5586, 1.3491, 1.1982, 1.2075, 1.2964, 1.5283, 1.8862, 2.7227, 
					  2.5674, 1.8921, 1.4702, 1.2139, 1.0972, 1.0811, 1.1885, 1.4058, 1.7793, 2.4126, 
					  2.4736, 1.7661, 1.3560, 1.1504, 1.0225, 0.9878, 1.1191, 1.3384, 1.6680, 2.3628, 
					  2.3755, 1.7012, 1.3730, 1.1079, 0.9922, 0.9927, 1.0596, 1.2822, 1.6182, 2.1987, 
					  2.3408, 1.7183, 1.3403, 1.1025, 0.9980, 0.9834, 1.0513, 1.2969, 1.6094, 2.3120, 
					  2.4326, 1.7500, 1.3765, 1.1343, 1.0132, 0.9829, 1.1162, 1.3130, 1.6836, 2.2646, 
					  2.5845, 1.8486, 1.4624, 1.2080, 1.0918, 1.0703, 1.1826, 1.3901, 1.7568, 2.4556, 
					  2.7700, 1.9771, 1.5420, 1.2988, 1.1938, 1.1870, 1.2705, 1.5020, 1.9102, 2.6489, 
					  3.3540, 2.2363, 1.7700, 1.4355, 1.3579, 1.2837, 1.4355, 1.6821, 2.0933, 3.0884, 
					},
				},
				/* para 3 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.3203, 2.3174, 1.7559, 1.4561, 1.3477, 1.3345, 1.4624, 1.7192, 2.1875, 3.0459, 
					  2.9595, 2.0127, 1.5908, 1.3335, 1.2051, 1.1812, 1.2944, 1.5132, 1.9111, 2.7080, 
					  2.6099, 1.8887, 1.4595, 1.2222, 1.1123, 1.0879, 1.1987, 1.4243, 1.7744, 2.4478, 
					  2.4585, 1.7642, 1.3813, 1.1543, 1.0190, 0.9868, 1.1211, 1.3267, 1.7061, 2.2964, 
					  2.3672, 1.7080, 1.3525, 1.1167, 0.9961, 0.9946, 1.0635, 1.3062, 1.6138, 2.2603, 
					  2.3940, 1.6855, 1.3608, 1.1094, 0.9854, 0.9805, 1.0732, 1.2920, 1.6484, 2.2876, 
					  2.4009, 1.7764, 1.3716, 1.1582, 1.0068, 0.9956, 1.1064, 1.3398, 1.6567, 2.2969, 
					  2.6035, 1.8071, 1.4727, 1.2109, 1.0874, 1.0703, 1.1904, 1.3965, 1.7485, 2.4580, 
					  2.7954, 1.9854, 1.5498, 1.3164, 1.1807, 1.1865, 1.2705, 1.5200, 1.8667, 2.6094, 
					  3.2036, 2.1855, 1.7275, 1.4634, 1.3208, 1.3076, 1.4067, 1.6382, 2.0605, 3.0635, 
					  3.2549, 2.3022, 1.7456, 1.4570, 1.3447, 1.3408, 1.4829, 1.7383, 2.1909, 3.2676, 
					  2.9541, 2.0000, 1.5845, 1.3306, 1.2051, 1.1978, 1.2979, 1.5156, 1.9248, 2.6597, 
					  2.5776, 1.8818, 1.4624, 1.2202, 1.1064, 1.0815, 1.2036, 1.4180, 1.7773, 2.5190, 
					  2.4824, 1.7451, 1.3882, 1.1489, 1.0146, 0.9937, 1.1230, 1.3291, 1.7134, 2.2939, 
					  2.3672, 1.7070, 1.3428, 1.1113, 0.9922, 0.9883, 1.0723, 1.2988, 1.6172, 2.2886, 
					  2.3931, 1.6865, 1.3672, 1.1113, 0.9922, 0.9878, 1.0684, 1.2998, 1.6460, 2.2896, 
					  2.3696, 1.7695, 1.3613, 1.1514, 1.0122, 1.0015, 1.1167, 1.3369, 1.6826, 2.2832, 
					  2.6099, 1.8291, 1.4629, 1.2227, 1.0898, 1.0830, 1.1997, 1.3950, 1.7661, 2.4458, 
					  2.7808, 1.9956, 1.5415, 1.3213, 1.1885, 1.1851, 1.2715, 1.5259, 1.8726, 2.6787, 
					  3.1460, 2.2002, 1.7251, 1.4380, 1.3428, 1.3232, 1.4434, 1.6226, 2.1245, 2.9614, 
					  3.2598, 2.2085, 1.7520, 1.3755, 1.3252, 1.3223, 1.4585, 1.6851, 2.1846, 3.1816, 
					  2.8423, 1.9780, 1.5503, 1.3286, 1.1973, 1.1855, 1.2915, 1.5107, 1.8779, 2.6699, 
					  2.5400, 1.8389, 1.4492, 1.2041, 1.0889, 1.0781, 1.1914, 1.4160, 1.7671, 2.4912, 
					  2.3843, 1.7202, 1.3364, 1.1421, 1.0107, 0.9868, 1.1211, 1.3130, 1.6802, 2.2920, 
					  2.3848, 1.6479, 1.3657, 1.0889, 0.9907, 0.9917, 1.0645, 1.2979, 1.6172, 2.2007, 
					  2.3218, 1.6797, 1.3232, 1.1143, 0.9839, 0.9824, 1.0576, 1.2954, 1.6011, 2.3086, 
					  2.3560, 1.7349, 1.3452, 1.1328, 1.0122, 1.0005, 1.1128, 1.3242, 1.6943, 2.2251, 
					  2.6279, 1.7813, 1.4668, 1.2007, 1.0854, 1.0596, 1.1826, 1.3921, 1.7090, 2.4258, 
					  2.6489, 1.9648, 1.5073, 1.3193, 1.1831, 1.1978, 1.2627, 1.5171, 1.8809, 2.6104, 
					  3.3711, 2.1440, 1.7568, 1.4302, 1.3325, 1.2969, 1.4238, 1.6494, 2.0381, 3.1089, 
					},
				},
				/* para 4 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.3579, 2.3315, 1.8081, 1.4736, 1.3672, 1.3672, 1.4556, 1.7192, 2.2114, 3.1318, 
					  2.9688, 2.0161, 1.5894, 1.3188, 1.2163, 1.1802, 1.2915, 1.5059, 1.8853, 2.6230, 
					  2.6040, 1.9097, 1.4717, 1.2397, 1.1084, 1.0864, 1.1997, 1.4028, 1.7886, 2.4629, 
					  2.4824, 1.7764, 1.3945, 1.1465, 1.0210, 0.9868, 1.1172, 1.3330, 1.6875, 2.3047, 
					  2.4355, 1.7090, 1.3691, 1.1245, 0.9980, 0.9858, 1.0752, 1.2769, 1.6304, 2.1978, 
					  2.3906, 1.7056, 1.3574, 1.1152, 0.9932, 0.9824, 1.0645, 1.2930, 1.6338, 2.2788, 
					  2.4956, 1.7480, 1.4082, 1.1450, 1.0117, 0.9844, 1.1172, 1.3169, 1.6890, 2.2383, 
					  2.5923, 1.8867, 1.4478, 1.2324, 1.0947, 1.0835, 1.1670, 1.4033, 1.7305, 2.4106, 
					  2.8452, 1.9746, 1.5830, 1.3101, 1.1836, 1.1768, 1.2803, 1.4902, 1.8979, 2.6074, 
					  3.1982, 2.2710, 1.7158, 1.4512, 1.3438, 1.3267, 1.3647, 1.6924, 2.0332, 3.0142, 
					  3.3335, 2.3267, 1.7471, 1.4556, 1.3330, 1.3384, 1.4814, 1.7173, 2.1909, 3.1211, 
					  2.9404, 2.0229, 1.5869, 1.3408, 1.2144, 1.1890, 1.2905, 1.5010, 1.9116, 2.6226, 
					  2.6396, 1.8906, 1.4712, 1.2227, 1.1016, 1.0864, 1.2007, 1.4238, 1.7734, 2.4897, 
					  2.4487, 1.7798, 1.3779, 1.1621, 1.0171, 0.9897, 1.1182, 1.3198, 1.6919, 2.2656, 
					  2.3984, 1.7104, 1.3599, 1.1060, 0.9956, 0.9805, 1.0737, 1.2979, 1.6187, 2.2529, 
					  2.3872, 1.6978, 1.3652, 1.1172, 0.9917, 0.9873, 1.0586, 1.2979, 1.6245, 2.2837, 
					  2.4160, 1.7568, 1.3696, 1.1479, 1.0088, 0.9961, 1.1104, 1.3330, 1.6670, 2.2866, 
					  2.6279, 1.8364, 1.4795, 1.2119, 1.0996, 1.0684, 1.1860, 1.3823, 1.7612, 2.4150, 
					  2.7930, 1.9878, 1.5498, 1.3149, 1.1821, 1.1982, 1.2739, 1.5127, 1.8779, 2.6504, 
					  3.1880, 2.2402, 1.7168, 1.4653, 1.3398, 1.2964, 1.4102, 1.6304, 2.1050, 2.9434, 
					  3.2754, 2.2573, 1.7183, 1.4238, 1.3003, 1.3374, 1.4624, 1.6851, 2.2012, 3.1011, 
					  2.9058, 2.0117, 1.5664, 1.3491, 1.2061, 1.1821, 1.2905, 1.4897, 1.8911, 2.5615, 
					  2.5483, 1.8447, 1.4458, 1.1987, 1.0840, 1.0786, 1.1816, 1.4106, 1.7549, 2.4653, 
					  2.4644, 1.7495, 1.3760, 1.1484, 1.0161, 0.9937, 1.1079, 1.3247, 1.6851, 2.2397, 
					  2.3203, 1.6836, 1.3491, 1.1025, 0.9819, 0.9888, 1.0552, 1.2852, 1.6006, 2.2241, 
					  2.3970, 1.6631, 1.3540, 1.1021, 0.9863, 0.9907, 1.0474, 1.2969, 1.6133, 2.2778, 
					  2.3652, 1.7490, 1.3540, 1.1299, 1.0112, 0.9844, 1.1064, 1.3130, 1.6680, 2.2549, 
					  2.5825, 1.7808, 1.4736, 1.1924, 1.0850, 1.0757, 1.1582, 1.3936, 1.7124, 2.3936, 
					  2.6953, 1.9932, 1.5073, 1.3071, 1.1841, 1.1772, 1.2686, 1.5117, 1.8677, 2.6621, 
					  3.1992, 2.1631, 1.7378, 1.4194, 1.3438, 1.2959, 1.3843, 1.6416, 2.0410, 2.9609, 
					},
				},
				/* para 5 */
				{
				},
				/* para 6 */
				{
				},
			},
        },
    },
    /* isp_sub_module_drc_tuning_t isp_sub_module_drc_tuning */
    {
       /*enable*/
       0,
       /*interpolation enable*/
       1,
       /*count_ae*/
       3,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /*drc_point_size*/
       257,
       /* aec trigger */
       {
          /*aec trigger 1 */
          {
            0.000,
            130.000,
          },
          /*aec trigger 2 */
          {
            180.000,
            300.000,
          },
          /*aec trigger 3 */
          {
            330.000,
            550.000,
          },
          /*aec trigger 4 */
          {
            0.000,
            0.000,
          },
          /*aec trigger 5 */
          {
            0.000,
            0.000,
          },
       },
       /*isp_sub_module_drc_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               /* drc_low_LUT_point */
               {
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* drc_high_LUT_point */
               {
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* saturation */
               100,
               /* filter 1 */
               {
                  3,17,29,17,3,
                  7,29,46,29,7,
                  3,17,29,17,3,
               },
               /* filter 2 */
               {
                  12,18,21,18,12,
                  14,21,24,21,14,
                  12,18,21,18,12,
               },
               /* filter 3 */
               {
                  14,18,19,18,14,
                  16,19,20,19,16,
                  14,18,19,18,14,
               },
			   1.000000,
               4.000000,
               1.000000,
           },
           /* parameter 2 */
           {
               /* drc_low_LUT_point */
               {
                     0, 819, 819, 819, 819, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818, 818,
                   817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 817, 816, 816, 816, 816, 816,
                   816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 815, 815, 815, 815, 815, 815, 815, 815, 815, 815,
                   815, 815, 815, 815, 815, 815, 815, 815, 815, 815, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814, 814,
                   814, 814, 814, 814, 814, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813, 813,
                   812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 812, 811, 811, 811, 811, 811,
                   811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 811, 810, 810, 810, 810, 810, 810, 810, 810, 810, 810,
                   810, 810, 810, 810, 810, 810, 810, 810, 810, 810, 810, 809, 809, 809, 809, 809, 809, 809, 809, 809, 809, 809, 809, 809, 809,
                   809, 809, 809, 809, 809, 809, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808, 808,
                   808, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 807, 806, 806, 806, 806,
                   806, 806, 806, 806, 806, 806, 806,
               },
               /* drc_high_LUT_point */
               {
                     0, 806, 793, 781, 769, 757, 745, 734, 722, 711, 700, 689, 679, 668, 658, 648, 637, 628, 618, 608, 599, 590, 580, 571, 563,
                   554, 545, 537, 528, 520, 512, 504, 496, 489, 481, 474, 466, 459, 452, 445, 438, 431, 424, 418, 411, 405, 399, 393, 386, 380,
                   375, 369, 363, 357, 352, 346, 341, 336, 330, 325, 320, 315, 310, 306, 301, 296, 292, 287, 283, 278, 274, 270, 265, 261, 257,
                   253, 249, 245, 242, 238, 234, 231, 227, 223, 220, 217, 213, 210, 207, 203, 200, 197, 194, 191, 188, 185, 182, 179, 177, 174,
                   171, 169, 166, 163, 161, 158, 156, 153, 151, 149, 146, 144, 142, 140, 137, 135, 133, 131, 129, 127, 125, 123, 121, 119, 118,
                   116, 114, 112, 110, 109, 107, 105, 104, 102, 100,  99,  97,  96,  94,  93,  91,  90,  89,  87,  86,  85,  83,  82,  81,  79,
                    78,  77,  76,  75,  73,  72,  71,  70,  69,  68,  67,  66,  65,  64,  63,  62,  61,  60,  59,  58,  57,  56,  55,  54,  54,
                    53,  52,  51,  50,  49,  49,  48,  47,  46,  46,  45,  44,  44,  43,  42,  42,  41,  40,  40,  39,  38,  38,  37,  37,  36,
                    35,  35,  34,  34,  33,  33,  32,  32,  31,  31,  30,  30,  29,  29,  28,  28,  28,  27,  27,  26,  26,  25,  25,  25,  24,
                    24,  23,  23,  23,  22,  22,  22,  21,  21,  21,  20,  20,  20,  19,  19,  19,  18,  18,  18,  18,  17,  17,  17,  17,  16,
                    16,  16,  15,  15,  15,  15,  15,
               },
               /* saturation */
               180,
               /* filter 1 */
               {
                  3,17,29,17,3,
                  7,29,46,29,7,
                  3,17,29,17,3,
               },
               /* filter 2 */
               {
                  12,18,21,18,12,
                  14,21,24,21,14,
                  12,18,21,18,12,
               },
               /* filter 3 */
               {
                  14,18,19,18,14,
                  16,19,20,19,16,
                  14,18,19,18,14,
               },
               1.000000,
               4.000000,
               1.000000,
           },
           /* parameter 3 */
           {
               /* drc_low_LUT_point */
               {
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* drc_high_LUT_point */
               {
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* saturation */
               100,
               /* filter 1 */
               {
                  3,17,29,17,3,
                  7,29,46,29,7,
                  3,17,29,17,3,
               },
               /* filter 2 */
               {
                  12,18,21,18,12,
                  14,21,24,21,14,
                  12,18,21,18,12,
               },
               /* filter 3 */
               {
                  14,18,19,18,14,
                  16,19,20,19,16,
                  14,18,19,18,14,
               },
               1.000000,
               4.000000,
               1.000000,
           },
           /* parameter 4 */
           {
               /* drc_low_LUT_point */
               {
                     0,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,
                  6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,
                  6143,6143,6143,6143,6143,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,
                  6142,6142,6142,6142,6142,6142,6142,6142,6142,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,
                  6141,6141,6141,6141,6141,6141,6141,6141,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,
                  6140,6140,6140,6140,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6138,6138,
                  6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6137,6137,6137,6137,6137,6137,6137,6137,6137,
                  6137,6137,6137,6137,6137,6137,6137,6137,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6135,
                  6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6134,6134,6134,6134,6134,6134,6134,6134,6134,6134,6134,
                  6134,6134,6134,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6132,6132,6132,6132,6132,6132,6132,6132,
                  6132,6132,6132,6132,6132,6132,6131,
               },
               /* drc_high_LUT_point */
               {
                     0,6131,6107,6074,6034,5987,5935,5878,5817,5751,5682,5609,5533,5455,5374,5290,5205,5118,5029,4939,4847,4755,4662,4568,4474,
                  4379,4284,4189,4094,3999,3904,3810,3717,3623,3531,3439,3349,3259,3170,3082,2996,2910,2826,2743,2661,2581,2502,2425,2349,2274,
                  2201,2129,2059,1991,1924,1859,1795,1732,1672,1612,1555,1498,1444,1390,1339,1288,1240,1192,1146,1102,1058,1016, 976, 937, 899,
                   862, 826, 792, 759, 727, 696, 666, 638, 610, 583, 557, 533, 509, 486, 464, 443, 423, 403, 384, 366, 349, 333, 317, 302, 287,
                   273, 260, 247, 235, 223, 212, 201, 191, 182, 172, 163, 155, 147, 139, 132, 125, 118, 112, 106, 100,  95,  90,  85,  80,  76,
                    72,  68,  64,  60,  57,  53,  50,  48,  45,  42,  40,  37,  35,  33,  31,  29,  27,  26,  24,  23,  21,  20,  19,  18,  17,
                    15,  14,  14,  13,  12,  11,  10,  10,   9,   8,   8,   7,   7,   6,   6,   5,   5,   5,   4,   4,   4,   3,   3,   3,   3,
                     3,   2,   2,   2,   2,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* saturation */
               100,
               /* filter 1 */
               {
                  3,17,29,17,3,
                  7,29,46,29,7,
                  3,17,29,17,3,
               },
               /* filter 2 */
               {
                  12,18,21,18,12,
                  14,21,24,21,14,
                  12,18,21,18,12,
               },
               /* filter 3 */
               {
                  14,18,19,18,14,
                  16,19,20,19,16,
                  14,18,19,18,14,
               },
               1.000000,
               4.000000,
               1.000000,
           },
           /* parameter 5 */
           {
               /* drc_low_LUT_point */
               {
                     0,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,
                  6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,6143,
                  6143,6143,6143,6143,6143,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,6142,
                  6142,6142,6142,6142,6142,6142,6142,6142,6142,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,6141,
                  6141,6141,6141,6141,6141,6141,6141,6141,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,6140,
                  6140,6140,6140,6140,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6139,6138,6138,
                  6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6138,6137,6137,6137,6137,6137,6137,6137,6137,6137,
                  6137,6137,6137,6137,6137,6137,6137,6137,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6136,6135,
                  6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6135,6134,6134,6134,6134,6134,6134,6134,6134,6134,6134,6134,
                  6134,6134,6134,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6133,6132,6132,6132,6132,6132,6132,6132,6132,
                  6132,6132,6132,6132,6132,6132,6131,
               },
               /* drc_high_LUT_point */
               {
                     0,6131,6107,6074,6034,5987,5935,5878,5817,5751,5682,5609,5533,5455,5374,5290,5205,5118,5029,4939,4847,4755,4662,4568,4474,
                  4379,4284,4189,4094,3999,3904,3810,3717,3623,3531,3439,3349,3259,3170,3082,2996,2910,2826,2743,2661,2581,2502,2425,2349,2274,
                  2201,2129,2059,1991,1924,1859,1795,1732,1672,1612,1555,1498,1444,1390,1339,1288,1240,1192,1146,1102,1058,1016, 976, 937, 899,
                   862, 826, 792, 759, 727, 696, 666, 638, 610, 583, 557, 533, 509, 486, 464, 443, 423, 403, 384, 366, 349, 333, 317, 302, 287,
                   273, 260, 247, 235, 223, 212, 201, 191, 182, 172, 163, 155, 147, 139, 132, 125, 118, 112, 106, 100,  95,  90,  85,  80,  76,
                    72,  68,  64,  60,  57,  53,  50,  48,  45,  42,  40,  37,  35,  33,  31,  29,  27,  26,  24,  23,  21,  20,  19,  18,  17,
                    15,  14,  14,  13,  12,  11,  10,  10,   9,   8,   8,   7,   7,   6,   6,   5,   5,   5,   4,   4,   4,   3,   3,   3,   3,
                     3,   2,   2,   2,   2,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                     0,   0,   0,   0,   0,   0,   0,
               },
               /* saturation */
               100,
               /* filter 1 */
               {
                  3,17,29,17,3,
                  7,29,46,29,7,
                  3,17,29,17,3,
               },
               /* filter 2 */
               {
                  12,18,21,18,12,
                  14,21,24,21,14,
                  12,18,21,18,12,
               },
               /* filter 3 */
               {
                  14,18,19,18,14,
                  16,19,20,19,16,
                  14,18,19,18,14,
               },
               1.000000,
               4.000000,
               1.000000,
           },
       },
       /*auto gen*/
       0,
    },
    /* isp_sub_module_gic_tuning_t isp_sub_module_gic_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       3,
       /*tigger_mode : 0 gain ,1 lux */
       1,
       {
          /*region 1 */
          {
            0.000,
            180.000,
          },
          /*region 2 */
          {
            240.000,
            300.000,
          },
          /*region 3 */
          {
            400.000,
            500.000,
          },
          /*region 4 */
          {
            0.000,
            0.000,
          },
          /*region 5 */
          {
            0.000,
            0.000,
          },
       },
       {
           /*parameter 1 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               0, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               60, //k_thres
               25, //limit_base_green
               25, //limit_base_red
               875, //limit_end_green
               1000, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 2 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               0, //k_filter_power
               11468, //b_value
               20, //ge_thres
               164, //g_slope
               70, //max_thres
               90, //k_thres
               38, //limit_base_green
               38, //limit_base_red
               1313, //limit_end_green
               1500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 3 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               32, //k_filter_power
               13107, //b_value
               30, //ge_thres
               164, //g_slope
               80, //max_thres
               120, //k_thres
               50, //limit_base_green
               50, //limit_base_red
               1750, //limit_end_green
               2000, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 4 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               32, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               120, //k_thres
               50, //limit_base_green
               50, //limit_base_red
               1750, //limit_end_green
               2000, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 5 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               32, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               120, //k_thres
               50, //limit_base_green
               50, //limit_base_red
               1750, //limit_end_green
               2000, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
       },
    },
    /*isp_sub_module_cfai_tuning_t isp_sub_module_cfai_tuning;*/
    {
    },
    /*isp_sub_module_depurple_tuning_t isp_sub_module_depurple_tuning;*/
    {
    },
    /*isp_sub_module_ccm1_tuning_t isp_sub_module_ccm1_tuning;*/
    {
        1,//enable
        1,//interpolation enable
        2,//ae count
        4,//awb count
        1,//trigger_mode : 0 gain trigger 1 lux trigger
      /* aec trigger */
      {
        	/*trigger 0*/
        	{
        		0,
        		455,
        	},
        	/*trigger 1*/
        	{
				490,
				550,
        	},
        	/*trigger 2*/
        	{
        	},
        	/*trigger 3*/
        	{
        	},
        	/*trigger 4*/
        	{
        	},
      },
      /* awb trigger */
      {
        	/*trigger 0*/
        	{
        		2800,
        		3000,
        	},
        	/*trigger 1*/
        	{
        		3800,
        		4100,
        	},
        	/*trigger 2*/
        	{
        		4900,
        		5100,
        	},
        	/*trigger 3*/
        	{
        		6400,
        		6600,
        	},
        	/*trigger 4*/
        	{
        	},
        	/*trigger 5*/
        	{
        	},
        	/*trigger 6*/
        	{
        	},
      },
      /* isp_sub_module_ccm1_pra pra[5][7] */
       {
        	/*ae region 0*/
         {
                /* ccm a matrix */
                {
                     1.6854, -0.6287, -0.0567,
                     -0.3970, 1.4570, -0.0600,
                     -0.0941, -0.4842, 1.5783,
                },
                /* ccm tl84 matrix */
                {
                     1.6703, -0.7135, 0.0432,
                     -0.3302, 1.5198, -0.1896,
                     0.1008, -0.6340, 1.5331,
                },
                /* ccm d50 matrix */
                {
                     1.7217, -0.6218, -0.0999,
                     -0.2794, 1.5049, -0.2255,
                     0.0545, -0.6195, 1.5649,
                },
                /* ccm d65 matrix */
                {
                     1.6322, -0.5593, -0.0729,
                     -0.2657, 1.5450, -0.2793,
                     0.0419, -0.5475, 1.5056,
                },
                /* ccm region 4 */
                {
                },
                /* ccm region 5 */
                {
                },
                /* ccm region 6 */
                {
                },
        	},
        	/*ae region 1*/
        	{
                /* ccm a matrix */
                {
                     1, 0, 0,
                     0, 1, 0,
                     0, 0, 1,
                },
                /* ccm tl84 matrix */
                {
                     1, 0, 0,
                     0, 1, 0,
                     0, 0, 1,
                },
                /* ccm d50 matrix */
                {
                     1, 0, 0,
                     0, 1, 0,
                     0, 0, 1,
                },
                /* ccm d65 matrix */
                {
                     1, 0, 0,
                     0, 1, 0,
                     0, 0, 1,
                },
                /* ccm region 4 */
                {
                },
                /* ccm region 5 */
                {
                },
                /* ccm region 6 */
                {
                },
        	},
        	/*ae region 2*/
        	{
                /* ccm region 0 */
                {
                },
                /* ccm region 1 */
                {
                },
                /* ccm region 2 */
                {
                },
                /* ccm region 3 */
                {
                },
                /* ccm region 4 */
                {
                },
                /* ccm region 5 */
                {
                },
                /* ccm region 6 */
                {
                },
        	},
        	/*ae region 3*/
        	{
                /* ccm region 0 */
                {
                },
                /* ccm region 1 */
                {
                },
                /* ccm region 2 */
                {
                },
                /* ccm region 3 */
                {
                },
                /* ccm region 4 */
                {
                },
                /* ccm region 5 */
                {
                },
                /* ccm region 6 */
                {
                },
        	},
        	/*ae region 4*/
        	{
                /* ccm region 0 */
                {
                },
                /* ccm region 1 */
                {
                },
                /* ccm region 2 */
                {
                },
                /* ccm region 3 */
                {
                },
                /* ccm region 4 */
                {
                },
                /* ccm region 5 */
                {
                },
                /* ccm region 6 */
                {
                },
        	},
       },
    },
    /*isp_sub_module_ccm2_tuning_t isp_sub_module_ccm2_tuning;*/
    {
      0, //enable
    },
    /*isp_sub_module_gtm1_lut_tuning_t isp_sub_module_gtm1_lut_tuning;*/
    {
       /*int enable*/
	   0,
	   /*int interpolation_enable;*/
	   1,
       /*int count_ae;*/
	   2,
	   /*int trigger_mode;*/
	   1,
      /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT];*/
       {
          /*aec trigger 1*/
          {
            1.000,
            100.000,
          },
          /*aec trigger 2*/
          {
            180,
            370,
          },
          /*aec trigger 3*/
          {
            435,
            550,
          },
       },
       /*isp_sub_module_gtm1_lut_pra pra[MIN_TRIGGER_COUNT];*/
       {
       		/*gtm1 para 0*/
            {
                   1,
				   {
                        16,  32,  48,  64,  80,  96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 272, 288, 304, 320,
                       336, 352, 368, 384, 400, 416, 432, 448, 464, 480, 496, 512, 528, 544, 560, 576, 592, 608, 624, 640,
                       656, 672, 688, 704, 720, 736, 752, 768, 784, 800, 816, 832, 848, 864, 880, 896, 912, 928, 944, 960,
                       976, 992,1008,1024,1040,1056,1072,1088,1104,1120,1136,1152,1168,1184,1200,1216,1232,1248,1264,1280,
                      1296,1312,1328,1344,1360,1376,1392,1408,1424,1440,1456,1472,1488,1504,1520,1536,1552,1568,1584,1600,
                      1616,1632,1648,1664,1680,1696,1712,1728,1744,1760,1776,1792,1808,1824,1840,1856,1872,1888,1904,1920,
                      1936,1952,1968,1984,2000,2016,2032,2048,2064,2080,2096,2112,2128,2144,2160,2176,2192,2208,2224,2240,
                      2256,2272,2288,2304,2320,2336,2352,2368,2384,2400,2416,2432,2448,2464,2480,2496,2512,2528,2544,2560,
                      2576,2592,2608,2624,2640,2656,2672,2688,2704,2720,2736,2752,2768,2784,2800,2816,2832,2848,2864,2880,
                      2896,2912,2928,2944,2960,2976,2992,3008,3024,3040,3056,3072,3088,3104,3120,3136,3152,3168,3184,3200,
                      3216,3232,3248,3264,3280,3296,3312,3328,3344,3360,3376,3392,3408,3424,3440,3456,3472,3488,3504,3520,
                      3536,3552,3568,3584,3600,3616,3632,3648,3664,3680,3696,3712,3728,3744,3760,3776,3792,3808,3824,3840,
                      3856,3872,3888,3904,3920,3936,3952,3968,3984,4000,4016,4032,4048,4064,4080,4095,4095,
				   },
			},
			/*gtm1 para 1*/
            {
                   1,
				   {
                        13,  27,  40,  53,  66,  80,  93, 106, 119, 133, 146, 159, 172, 186, 199, 212, 226, 240, 255, 271,
                       289, 307, 324, 343, 362, 381, 400, 420, 439, 458, 477, 496, 515, 534, 553, 573, 592, 611, 630, 649,
                       668, 687, 706, 726, 745, 764, 783, 802, 821, 840, 860, 879, 898, 917, 936, 955, 974, 993,1013,1032,
                      1051,1070,1089,1108,1127,1147,1166,1185,1204,1223,1242,1261,1280,1300,1319,1338,1357,1376,1395,1414,
                      1434,1453,1472,1491,1510,1529,1548,1567,1587,1606,1625,1644,1663,1682,1701,1720,1740,1759,1778,1797,
                      1816,1835,1854,1874,1893,1912,1931,1950,1969,1988,2007,2027,2046,2065,2084,2103,2122,2141,2161,2178,
                      2197,2216,2234,2252,2271,2288,2308,2327,2346,2365,2384,2403,2422,2441,2458,2473,2490,2507,2525,2543,
                      2561,2578,2592,2606,2619,2632,2645,2659,2673,2687,2701,2715,2728,2741,2755,2768,2783,2796,2809,2823,
                      2836,2849,2862,2876,2889,2902,2915,2929,2942,2955,2968,2982,2995,3008,3021,3035,3048,3061,3075,3088,
                      3101,3114,3128,3141,3154,3167,3181,3194,3207,3220,3234,3247,3260,3274,3287,3300,3313,3327,3340,3353,
                      3366,3380,3393,3406,3419,3433,3446,3459,3473,3486,3499,3512,3526,3539,3552,3565,3579,3592,3605,3618,
                      3632,3645,3658,3672,3685,3698,3711,3725,3738,3751,3764,3778,3791,3804,3817,3831,3844,3857,3870,3884,
                      3897,3910,3924,3937,3950,3963,3977,3990,4003,4016,4030,4043,4056,4069,4083,4095,4095,
				   },
			},
			/*gtm1 para 2*/
            {
                   1,
				   {
                        16,  32,  48,  64,  80,  96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 272, 288, 304, 320,
                       336, 352, 368, 384, 400, 416, 432, 448, 464, 480, 496, 512, 528, 544, 560, 576, 592, 608, 624, 640,
                       656, 672, 688, 704, 720, 736, 752, 768, 784, 800, 816, 832, 848, 864, 880, 896, 912, 928, 944, 960,
                       976, 992,1008,1024,1040,1056,1072,1088,1104,1120,1136,1152,1168,1184,1200,1216,1232,1248,1264,1280,
                      1296,1312,1328,1344,1360,1376,1392,1408,1424,1440,1456,1472,1488,1504,1520,1536,1552,1568,1584,1600,
                      1616,1632,1648,1664,1680,1696,1712,1728,1744,1760,1776,1792,1808,1824,1840,1856,1872,1888,1904,1920,
                      1936,1952,1968,1984,2000,2016,2032,2048,2064,2080,2096,2112,2128,2144,2160,2176,2192,2208,2224,2240,
                      2256,2272,2288,2304,2320,2336,2352,2368,2384,2400,2416,2432,2448,2464,2480,2496,2512,2528,2544,2560,
                      2576,2592,2608,2624,2640,2656,2672,2688,2704,2720,2736,2752,2768,2784,2800,2816,2832,2848,2864,2880,
                      2896,2912,2928,2944,2960,2976,2992,3008,3024,3040,3056,3072,3088,3104,3120,3136,3152,3168,3184,3200,
                      3216,3232,3248,3264,3280,3296,3312,3328,3344,3360,3376,3392,3408,3424,3440,3456,3472,3488,3504,3520,
                      3536,3552,3568,3584,3600,3616,3632,3648,3664,3680,3696,3712,3728,3744,3760,3776,3792,3808,3824,3840,
                      3856,3872,3888,3904,3920,3936,3952,3968,3984,4000,4016,4032,4048,4064,4080,4095,4095,
				   },
			},
       },
    },
    /*isp_sub_module_gamma_lut_tuning_t isp_sub_module_gamma_lut_tuning;*/
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       3,
       /*tigger_mode : 0 gain ,1 lux */
       1,
       /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==3 */
       {
          /*aec trigger 1*/
          {
            0.000,
            90.000,
          },
          /*aec trigger 2*/
          {
            160.000,
            360.000,
          },
          /*aec trigger 3*/
          {
            400.000,
            550.000,
          },
       },
       513,//gamma lut count
       /*isp_sub_module_gamma_lut_pra pra[MIN_TRIGGER_COUNT]; MIN_TRIGGER_COUNT=3*/
       {
          /* outdoor */
          {
                  0,  32,  48,  72,  96, 120, 144, 168, 184, 216, 241, 265, 297, 313, 345, 369, 393, 425, 449, 473, 506, 530, 554, 586, 602, 634, 650,
                682, 698, 730, 755, 779, 803, 827, 843, 867, 883, 907, 923, 955, 971, 995,1012,1036,1052,1076,1092,1108,1124,1148,1164,1188,1204,1220,
               1236,1252,1269,1285,1301,1317,1333,1349,1365,1381,1389,1405,1413,1429,1445,1461,1477,1493,1509,1525,1534,1550,1558,1574,1590,1598,1614,
               1622,1638,1654,1670,1678,1694,1702,1718,1734,1742,1758,1766,1774,1791,1799,1815,1831,1839,1855,1863,1871,1887,1895,1903,1919,1927,1943,
               1959,1967,1975,1983,1999,2007,2015,2031,2039,2048,2064,2072,2080,2096,2104,2112,2128,2136,2144,2152,2160,2168,2176,2192,2200,2208,2224,
               2232,2240,2256,2264,2272,2280,2288,2296,2304,2313,2321,2329,2337,2345,2353,2361,2369,2385,2393,2401,2409,2417,2425,2433,2441,2449,2457,
               2465,2473,2481,2489,2497,2505,2513,2521,2525,2529,2537,2545,2553,2561,2570,2578,2586,2594,2602,2610,2618,2626,2634,2642,2650,2658,2666,
               2674,2682,2686,2690,2698,2706,2714,2718,2722,2730,2738,2746,2750,2754,2762,2770,2778,2786,2794,2798,2802,2810,2814,2818,2827,2835,2843,
               2847,2851,2859,2863,2867,2875,2883,2891,2895,2899,2907,2911,2915,2923,2931,2939,2943,2947,2955,2963,2971,2975,2979,2987,2991,2995,3003,
               3007,3011,3019,3023,3027,3035,3039,3043,3051,3055,3059,3067,3071,3075,3083,3088,3092,3100,3104,3108,3116,3120,3124,3132,3136,3140,3148,
               3152,3156,3164,3168,3172,3180,3184,3188,3196,3200,3204,3212,3216,3220,3228,3232,3236,3244,3248,3252,3260,3264,3268,3276,3280,3284,3288,
               3292,3296,3300,3304,3308,3312,3316,3320,3324,3328,3332,3340,3345,3349,3357,3361,3365,3373,3377,3381,3385,3389,3393,3397,3405,3409,3413,
               3417,3421,3425,3429,3433,3437,3441,3445,3453,3457,3461,3465,3469,3473,3477,3481,3485,3489,3493,3497,3501,3505,3509,3513,3517,3521,3525,
               3529,3533,3537,3541,3545,3549,3553,3557,3561,3565,3569,3573,3577,3581,3585,3589,3593,3597,3601,3605,3610,3614,3618,3622,3626,3630,3634,
               3638,3642,3646,3650,3654,3658,3660,3662,3666,3670,3674,3678,3682,3686,3690,3692,3694,3698,3702,3706,3710,3714,3718,3722,3724,3726,3730,
               3734,3738,3740,3742,3746,3750,3754,3758,3762,3766,3770,3774,3778,3782,3786,3788,3790,3794,3798,3802,3806,3810,3814,3818,3820,3822,3826,
               3830,3834,3838,3842,3846,3850,3852,3854,3858,3862,3867,3869,3871,3875,3879,3883,3885,3887,3891,3895,3899,3901,3902,3903,3907,3911,3915,
               3919,3923,3927,3931,3933,3935,3939,3943,3947,3949,3951,3955,3959,3963,3967,3971,3975,3979,3981,3983,3987,3991,3995,3999,4003,4007,4011,
               4013,4014,4015,4019,4023,4027,4029,4031,4035,4039,4043,4045,4047,4051,4055,4059,4061,4062,4063,4067,4071,4075,4077,4079,4083,4087,4095,
          },
          /* indoor */
          {
                  0,  11,  23,  35,  52,  73, 100, 132, 166, 202, 236, 295, 354, 412, 472, 527, 586, 642, 701, 753, 797, 840, 876, 906, 939, 963, 989,
               1014,1035,1061,1082,1106,1126,1148,1165,1186,1206,1225,1245,1264,1284,1303,1321,1336,1353,1368,1383,1397,1414,1427,1442,1458,1471,1485,
               1501,1514,1527,1540,1555,1567,1579,1594,1606,1617,1628,1642,1653,1663,1675,1687,1697,1709,1720,1731,1742,1753,1767,1778,1789,1800,1814,
               1825,1835,1848,1859,1870,1882,1893,1905,1916,1925,1934,1943,1953,1961,1970,1980,1989,1998,2007,2019,2028,2039,2050,2057,2067,2077,2088,
               2099,2107,2117,2127,2135,2147,2155,2164,2178,2188,2198,2203,2214,2225,2236,2242,2254,2266,2272,2284,2290,2302,2314,2320,2332,2338,2350,
               2361,2367,2379,2385,2396,2408,2414,2425,2431,2442,2450,2458,2467,2475,2482,2490,2499,2505,2514,2521,2528,2539,2547,2555,2559,2568,2577,
               2586,2591,2601,2610,2615,2625,2630,2639,2649,2654,2663,2668,2678,2687,2692,2702,2706,2716,2725,2730,2739,2744,2754,2760,2766,2773,2779,
               2784,2790,2797,2802,2809,2814,2820,2828,2834,2841,2844,2850,2857,2864,2868,2875,2883,2887,2894,2898,2905,2913,2916,2924,2928,2935,2943,
               2946,2954,2957,2965,2972,2976,2983,2987,2994,2999,3005,3010,3016,3020,3025,3030,3034,3040,3045,3049,3057,3062,3067,3070,3075,3081,3087,
               3090,3096,3102,3105,3112,3115,3121,3127,3130,3137,3140,3146,3152,3155,3162,3165,3171,3177,3180,3187,3190,3196,3201,3205,3211,3215,3220,
               3224,3229,3233,3238,3242,3247,3253,3258,3263,3265,3270,3275,3281,3284,3289,3295,3298,3304,3306,3312,3318,3320,3326,3329,3334,3340,3342,
               3348,3351,3356,3361,3364,3369,3372,3377,3383,3385,3390,3393,3398,3403,3406,3411,3413,3418,3423,3426,3431,3433,3438,3443,3446,3450,3453,
               3458,3462,3464,3469,3473,3477,3479,3483,3487,3492,3496,3499,3504,3507,3511,3514,3518,3522,3526,3529,3533,3536,3539,3543,3546,3549,3552,
               3556,3558,3562,3564,3567,3572,3575,3578,3580,3583,3587,3591,3593,3596,3600,3602,3606,3608,3612,3616,3618,3621,3623,3627,3631,3633,3637,
               3638,3642,3646,3648,3652,3653,3657,3661,3663,3666,3668,3672,3675,3677,3681,3682,3686,3690,3691,3695,3697,3700,3704,3705,3709,3711,3714,
               3717,3719,3722,3725,3728,3730,3733,3735,3739,3742,3744,3747,3750,3752,3755,3758,3760,3763,3766,3768,3771,3772,3775,3776,3779,3782,3784,
               3787,3788,3791,3794,3796,3799,3801,3804,3808,3810,3813,3815,3819,3822,3824,3828,3831,3834,3836,3839,3842,3846,3849,3851,3855,3857,3860,
               3863,3866,3869,3872,3875,3877,3880,3882,3885,3887,3890,3894,3895,3899,3901,3905,3909,3911,3916,3918,3922,3927,3929,3934,3937,3942,3947,
               3949,3954,3958,3963,3965,3969,3973,3979,3983,3986,3991,3994,3998,4002,4006,4010,4015,4018,4022,4028,4034,4041,4051,4062,4073,4084,4095,
          },
          /* lowlight */
          {
                  0,  24,  40,  72,  88, 112, 136, 152, 176, 200, 216, 241, 265, 281, 305, 321, 345, 361, 385, 401, 425, 441, 465, 481, 498, 522, 538,
                562, 578, 594, 610, 634, 650, 674, 690, 706, 722, 738, 755, 771, 795, 811, 835, 851, 867, 883, 899, 915, 931, 947, 963, 979, 995,1012,
               1028,1044,1060,1076,1092,1108,1124,1140,1156,1172,1188,1196,1212,1220,1236,1252,1269,1285,1301,1317,1333,1341,1357,1365,1381,1397,1413,
               1429,1437,1453,1461,1477,1493,1509,1517,1534,1542,1558,1574,1582,1598,1606,1622,1638,1646,1662,1670,1686,1694,1710,1718,1734,1742,1758,
               1766,1782,1791,1807,1815,1823,1839,1847,1863,1871,1887,1895,1903,1919,1927,1935,1951,1959,1967,1983,1991,1999,2015,2023,2031,2048,2056,
               2064,2080,2088,2096,2104,2112,2128,2136,2144,2152,2160,2176,2184,2192,2200,2208,2224,2232,2240,2248,2256,2272,2280,2288,2296,2304,2313,
               2321,2337,2345,2353,2361,2369,2377,2385,2393,2401,2409,2417,2433,2441,2449,2457,2465,2473,2481,2489,2497,2505,2513,2521,2529,2537,2545,
               2553,2561,2570,2578,2586,2594,2602,2610,2618,2626,2634,2642,2650,2658,2666,2674,2682,2686,2690,2698,2706,2714,2722,2730,2738,2746,2754,
               2762,2766,2770,2778,2786,2794,2802,2810,2818,2826,2831,2835,2843,2851,2859,2867,2875,2879,2883,2891,2899,2907,2911,2915,2923,2931,2939,
               2947,2955,2959,2963,2971,2979,2987,2991,2995,3003,3007,3011,3019,3027,3035,3039,3043,3051,3059,3067,3071,3075,3083,3088,3092,3100,3108,
               3116,3120,3124,3132,3136,3140,3148,3152,3156,3164,3168,3172,3180,3184,3188,3196,3204,3212,3216,3220,3228,3232,3236,3244,3248,3252,3260,
               3264,3268,3276,3280,3284,3292,3296,3300,3304,3308,3312,3316,3324,3328,3332,3340,3345,3349,3357,3361,3365,3373,3377,3381,3385,3389,3393,
               3397,3405,3409,3413,3421,3425,3429,3433,3437,3441,3445,3453,3457,3461,3465,3469,3473,3477,3485,3489,3493,3497,3501,3505,3509,3517,3521,
               3525,3529,3533,3537,3541,3545,3549,3553,3557,3565,3569,3573,3577,3581,3585,3589,3593,3597,3601,3605,3610,3614,3618,3622,3626,3630,3634,
               3638,3642,3646,3650,3654,3658,3662,3666,3670,3674,3678,3682,3686,3690,3694,3698,3702,3706,3710,3714,3718,3722,3726,3730,3734,3738,3742,
               3746,3750,3754,3756,3758,3762,3766,3770,3774,3778,3782,3786,3790,3794,3798,3802,3804,3806,3810,3814,3818,3822,3826,3830,3834,3836,3838,
               3842,3846,3850,3852,3854,3858,3862,3867,3871,3875,3879,3883,3885,3887,3891,3895,3899,3901,3903,3907,3911,3915,3917,3919,3923,3927,3931,
               3933,3935,3939,3943,3947,3949,3951,3955,3959,3963,3965,3967,3971,3975,3979,3981,3983,3987,3991,3995,3997,3999,4003,4007,4011,4013,4014,
               4015,4019,4023,4027,4029,4031,4035,4039,4043,4045,4047,4051,4055,4059,4061,4062,4063,4067,4071,4075,4077,4078,4079,4083,4087,4090,4095,
          },
       },
    },
    /*isp_sub_module_gtm2_lut_tuning_t isp_sub_module_gtm2_lut_tuning;*/
    {
		0, //enable
    },
    /* isp_sub_module_3d_lut_tuning_t isp_sub_module_3d_lut_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       2,
       /*count_awb*/
       5,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            0.000,
            300.000,
          },
          /* aec trigger 2 */
          {
            400.000,
            550.000,
          },
          /* aec trigger 3 */
          {
            0.000,
            0.000,
          },
          /* aec trigger 4 */
          {
            0.000,
            0.000,
          },
          /* aec trigger 5 */
          {
            0.000,
            0.000,
          },
       },
       /* awb trigger */
       {
          /* awb trigger 1 */
          {
            0.000,
            3000.000,
          },
          /* awb trigger 2 */
          {
            3900.000,
            4100.000,
          },
          /* awb trigger 3 */
          {
            4900.000,
            5100.000,
          },
          /* awb trigger 4 */
          {
            6400.000,
            6600.000,
          },
          /* awb trigger 5 */
          {
            7400.000,
            7600.000,
          },
          /* awb trigger 6 */
          {
            0.000,
            0.000,
          },
          /* awb trigger 7 */
          {
            0.000,
            0.000,
          },
       },
       /*isp_sub_module_3d_lut_pra pra[MIDDLE_TRIGGER_COUNT=5][MIDDLE_TRIGGER_COUNT=7]*/
       {
          /* aec tigger 1 */
          {
              /* awb tigger 1 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 2 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024,  938,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1408,    0,
                           0, 2048,    0,
                        2048, 1877,    0,
                        4095, 1843,    0,
                        1536, 2560,    0,
                        3584, 2261,    0,
                        1023, 3072,    0,
                        3072, 2815,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 3753,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1459,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2346,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3285,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 2816, 1024,
                        1535, 3584, 1024,
                        3584, 3370, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536,  947,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 1834,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2355,    0,
                        1536, 3072,    0,
                        3584, 2773,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 1919,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2406,  511,
                        1023, 3072,  511,
                        3072, 2858,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 3796,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3328, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  469,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1407,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 1894,    0,
                         511, 2560,    0,
                        2560, 2346,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 2730,    0,
                        1535, 3584,    0,
                        3584, 3285,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 1877,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2380,  512,
                        1535, 3072,  511,
                        3584, 2816,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2432, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 3839, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1365,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 1868,    0,
                        1023, 2560,    0,
                        3072, 2304,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3242,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 1920,  511,
                         511, 2560,  511,
                        2560, 2389,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 2773,  512,
                        1535, 3584,  511,
                        3584, 3327,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2406, 1024,
                        1536, 3072, 1023,
                        3584, 2858, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 3 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1322,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2261,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1408,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2346,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3285,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 2816, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536,  896,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 1834,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2218,    0,
                        1536, 3072,    0,
                        3584, 2773,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2303,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3328, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 1792,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 2730,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 1877,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 2816,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2346, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1365,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2304,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3242,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 1834,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 2773,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 2858, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 4 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1194,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2082,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1331,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2218,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3106,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 2662, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536,  819,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 1706,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2014,    0,
                        1536, 3072,    0,
                        3584, 2594,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2150,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3174, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 1638,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 2525,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 1774,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 2662,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2218, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1262,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2150,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3037,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 1706,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 2594,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 2730, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 5 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 6 */
              {
              },
              /* awb tigger 7 */
              {
              },
          },
          /* aec tigger 2 */
          {
              /* awb tigger 1 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 2 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 3 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 4 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 5 */
              {
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  511,    0,
                        3584,  511,    0,
                        1024, 1024,    0,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,    0,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  511,
                        3584,    0,  511,
                        1024,  512,  512,
                        3072,  511,  511,
                         512, 1024,  512,
                        2560, 1023,  511,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  511,
                        1023, 2560,  511,
                        3072, 2560,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3583,  512,
                        1536, 4095,  512,
                        3583, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1023,
                         512,  512, 1024,
                        2560,  511, 1023,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1535, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1023,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1535,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1535,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  511, 2048,
                        1024, 1024, 2048,
                        3072, 1023, 2048,
                         512, 1535, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2559, 2048,
                        1023, 3072, 2048,
                        3072, 3072, 2048,
                         511, 3584, 2048,
                        2559, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1535,    0, 2560,
                        3584,    0, 2560,
                        1023,  511, 2560,
                        3072,  511, 2559,
                         511, 1023, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2559,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         511, 3072, 2559,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3583, 4095, 2560,
                        1023,    0, 3072,
                        3072,    0, 3072,
                         511,  511, 3072,
                        2559,  511, 3072,
                           0, 1024, 3072,
                        2048, 1023, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1023, 2048, 3072,
                        3072, 2048, 3072,
                         511, 2559, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3071,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3583,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3583,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1535, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3584, 4095,
                           0, 4095, 4095,
                        2048, 4095, 4095,
                        4095, 4095, 4095,
                           0,    0,    0,
                  },
                  /* lut3d table 2 */
                  {
                         512,    0,    0,
                        2560,    0,    0,
                           0,  512,    0,
                        2048,  512,    0,
                        4095,  512,    0,
                        1536, 1024,    0,
                        3584, 1024,    0,
                        1024, 1536,    0,
                        3072, 1536,    0,
                         512, 2048,    0,
                        2560, 2048,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3072,    0,
                        1023, 3584,    0,
                        3071, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  511,
                        1536,  511,  511,
                        3584,  511,  511,
                        1024, 1024,  512,
                        3072, 1023,  511,
                         511, 1536,  511,
                        2560, 1536,  511,
                           0, 2048,  512,
                        2048, 2047,  512,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  511,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         511,  511, 1536,
                        2560,  511, 1536,
                           0, 1023, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         511, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1535,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2047,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2047,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2047,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2047,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2047,    0, 2560,
                        4095,    0, 2559,
                        1536,  511, 2560,
                        3584,  511, 2560,
                        1024, 1024, 2560,
                        3072, 1023, 2559,
                         511, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2047, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1023, 3072, 2559,
                        3072, 3072, 2560,
                         511, 3584, 2559,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1023, 2559, 3072,
                        3072, 2560, 3072,
                         511, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3071,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3071,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         511,  511, 3584,
                        2560,  511, 3584,
                           0, 1023, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         511, 2559, 3584,
                        2560, 2560, 3584,
                           0, 3071, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3583,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2559,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1535, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1535, 4095,
                        3072, 1536, 4095,
                         512, 2047, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3071, 4095,
                        3583, 3072, 4095,
                        1024, 3584, 4095,
                        3072, 3584, 4095,
                         512, 4095, 4095,
                        2560, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 3 */
                  {
                        1024,    0,    0,
                        3072,    0,    0,
                         512,  512,    0,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  511,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3072,  511,
                        1024, 3584,  511,
                        3072, 3584,  511,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  511, 1024,
                        3584,  511, 1024,
                        1024, 1024, 1024,
                        3072, 1023, 1023,
                         511, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2559, 1024,
                        1023, 3072, 1023,
                        3072, 3072, 1023,
                         511, 3584, 1023,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2047, 4095, 1024,
                        4095, 4094, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  511, 1536,
                        3072,  511, 1536,
                         511, 1024, 1536,
                        2560, 1024, 1535,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2559, 1536,
                         511, 3072, 1535,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  511, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2047,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         511, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2047,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         511, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2559,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  511, 3072,
                        3584,  511, 3071,
                        1023, 1023, 3072,
                        3072, 1023, 3072,
                         511, 1535, 3072,
                        2560, 1536, 3072,
                           0, 2047, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2559, 3072,
                        3584, 2560, 3072,
                        1023, 3072, 3072,
                        3072, 3072, 3072,
                         511, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  511, 3584,
                        3071,  511, 3584,
                         511, 1023, 3584,
                        2559, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         511, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2559,  512, 4095,
                           0, 1024, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2560, 4095,
                        2560, 2560, 4095,
                           0, 3072, 4095,
                        2048, 3072, 4095,
                        4095, 3072, 4095,
                        1536, 3584, 4095,
                        3584, 3584, 4095,
                        1024, 4095, 4095,
                        3072, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
                  /* lut3d table 4 */
                  {
                        1536,    0,    0,
                        3584,    0,    0,
                        1024,  512,    0,
                        3072,  511,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1023, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  511,  511,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  511,
                        3584, 1535,  511,
                        1024, 2048,  512,
                        3072, 2048,  511,
                         511, 2560,  511,
                        2560, 2560,  511,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  511,
                        1023, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1023,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1023,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1535,
                        1536,  511, 1536,
                        3584,  511, 1535,
                        1024, 1024, 1536,
                        3072, 1023, 1536,
                         511, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1023, 3072, 1536,
                        3072, 3072, 1536,
                         511, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2559, 2048,
                         511, 3072, 2048,
                        2559, 3072, 2048,
                           0, 3584, 2047,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2559,
                         511,  511, 2560,
                        2560,  511, 2560,
                           0, 1023, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2559,
                         511, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2559,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  511, 3072,
                        2047,  511, 3072,
                        4095,  512, 3072,
                        1536, 1023, 3072,
                        3584, 1024, 3071,
                        1023, 1536, 3072,
                        3072, 1536, 3072,
                         511, 2048, 3072,
                        2559, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2559, 3072,
                        4095, 2560, 3071,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3071,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2047,    0, 3584,
                        4095,    0, 3583,
                        1535,  511, 3584,
                        3584,  511, 3584,
                        1024, 1024, 3584,
                        3071, 1024, 3584,
                         511, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2047, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3071, 3584,
                        3072, 3072, 3584,
                         511, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3583,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1535,    0, 4095,
                        3583,    0, 4095,
                        1023,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3583, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
              },
              /* awb tigger 6 */
              {
              },
              /* awb tigger 7 */
              {
              },
          },
          /* aec tigger 3 */
          {
              /* awb tigger 1 */
              {
              },
              /* awb tigger 2 */
              {
              },
              /* awb tigger 3 */
              {
              },
              /* awb tigger 4 */
              {
              },
              /* awb tigger 5 */
              {
              },
              /* awb tigger 6 */
              {
              },
              /* awb tigger 7 */
              {
              },
          },
          /* aec tigger 4 */
          {
              /* awb tigger 1 */
              {
              },
              /* awb tigger 2 */
              {
              },
              /* awb tigger 3 */
              {
              },
              /* awb tigger 4 */
              {
              },
              /* awb tigger 5 */
              {
              },
              /* awb tigger 6 */
              {
              },
              /* awb tigger 7 */
              {
              },
          },
          /* aec tigger 5 */
          {
              /* awb tigger 1 */
              {
              },
              /* awb tigger 2 */
              {
              },
              /* awb tigger 3 */
              {
              },
              /* awb tigger 4 */
              {
              },
              /* awb tigger 5 */
              {
              },
              /* awb tigger 6 */
              {
              },
              /* awb tigger 7 */
              {
              },
          },
       },
    },
    /*isp_sub_module_rgbyuv_tuning_t isp_sub_module_rgbyuv_tuning;*/
    {
      1,
    },
    /* isp_sub_module_cm_tuning_t isp_sub_module_cm_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       4,
       /*count_awb*/
       7,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            0.000,
            360.000,
          },
          /* aec trigger 2 */
          {
            440.000,
            455.000,
          },
          /* aec trigger 3 */
          {
            470.000,
            495.000,
          },
          /* aec trigger 4 */
          {
            510.000,
            550.000,
          },
          /* aec trigger 5 */
          {
            0.000,
            0.000,
          },
       },
       /* awb trigger */
       {
          /* awb trigger 1 */
          {
            0.000,
            2000.000,
          },
          /* awb trigger 2 */
          {
            2900.000,
            3000.000,
          },
          /* awb trigger 3 */
          {
            3900.000,
            4000.000,
          },
          /* awb trigger 4 */
          {
            4900.000,
            5000.000,
          },
          /* awb trigger 5 */
          {
            5500.000,
            5700.000,
          },
          /* awb trigger 6 */
          {
            6400.000,
            6500.000,
          },
          /* awb trigger 7 */
          {
            7400.000,
            7500.000,
          },
       },
       /*isp_sub_module_cm_pra pra[MIDDLE_TRIGGER_COUNT=5][MIDDLE_TRIGGER_COUNT=7]*/
       {
          /* aec tigger 1 */
          {
              /* awb tigger 1 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 2 */
          {
              /* awb tigger 1 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.950000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 3 */
          {
              /* awb tigger 1 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.900000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 4 */
          {
              /* awb tigger 1 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.850000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 5 */
          {
              /* awb tigger 1 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  1.000000, //saturation
                  0.000000, //hue
              },
          },
       },
    },
    /* isp_sub_module_lee_tuning_t isp_sub_module_lee_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       7,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       0,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            1.100,
          },
          /* aec trigger 2 */
          {
            2.000,
            2.100,
          },
          /* aec trigger 3 */
          {
            4.000,
            4.100,
          },
          /* aec trigger 4 */
          {
            8.000,
            8.100,
          },
          /* aec trigger 5 */
          {
            16.000,
            16.100,
          },
          /* aec trigger 6 */
          {
            32.000,
            32.100,
          },
          /* aec trigger 7 */
          {
            64.000,
            64.100,
          },
       },
       /*isp_sub_module_lee_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               80,  //sharpen_pos
               95,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 100, 240, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               80,  //sharpen_pos
               90,  //sharpen_fu
               3,  //noise_th
               0,  //order_en
               110, //limit_max
               110, //limit_min
               0, 1, 100, 240, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               75,  //sharpen_pos
               85,  //sharpen_fu
               4,  //noise_th
               0,  //order_en
               105, //limit_max
               105, //limit_min
               0, 1, 100, 240, //edge_th 0 ~3
               8, 60, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 100, 240, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               65,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 100, 240, //edge_th 0 ~3
               8, 60, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               35,  //sharpen_pos
               45,  //sharpen_fu
               20,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               40,  //sharpen_fu
               25,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
       },
    },
    /* isp_sub_module_cnf_tuning_t isp_sub_module_cnf_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       12,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       0,
       /* cof */
       {
          256,
          1025,
          358,
          256,
          1113,
          1207,
          256,
          453,
          0,
          0,
          128,
          128,
       },
       256,//lut_size
       /* aec trigger */
       {
          /*aec trigger 1 */
          {
            1.000,
            1.200,
          },
          /*aec trigger 2 */
          {
            2.000,
            2.100,
          },
          /*aec trigger 3 */
          {
            4.000,
            4.100,
          },
          /*aec trigger 4 */
          {
            8.000,
            8.100,
          },
          /*aec trigger 5 */
          {
            12.000,
            12.100,
          },
          /*aec trigger 6 */
          {
            16.000,
            16.100,
          },
          /*aec trigger 7 */
          {
            32.000,
            32.100,
          },
          /*aec trigger 8 */
          {
            64.000,
            64.100,
          },
          /*aec trigger 9 */
          {
            128.000,
            128.100,
          },
          /*aec trigger 10 */
          {
            256.000,
            256.100,
          },
          /*aec trigger 11 */
          {
            512.000,
            512.100,
          },
          /*aec trigger 12 */
          {
            1024.000,
            1024.100,
          },
       },
       /* isp_sub_module_cnf_pra pra[MIDDLE_TRIGGER_COUNT] */
       {
          /* para 1 */
          {
             1,  //enable
             2,  //zoom_par
             2,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 2 */
          {
             1,  //enable
             2,  //zoom_par
             2,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 3 */
          {
             1,  //enable
             3,  //zoom_par
             2,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 4 */
          {
             1,  //enable
             4,  //zoom_par
             2,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 5 */
          {
             1,  //enable
             5,  //zoom_par
             2,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 6 */
          {
             1,  //enable
             6,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 7 */
          {
             1,  //enable
             8,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 8 */
          {
             1,  //enable
             10,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 9 */
          {
             1,  //enable
             10,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 10 */
          {
             1,  //enable
             10,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 11 */
          {
             1,  //enable
             10,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
          /* para 12 */
          {
             1,  //enable
             10,  //zoom_par
             3,  //dn_level
             {
                255, 255, 254, 252, 250, 248, 246, 244, 242, 241, 239, 237, 235, 233, 231, 229, 228, 226, 224, 222, 221, 219, 217, 216, 214, 212, 211, 209, 207, 206, 204, 202, 
                201, 199, 198, 196, 195, 193, 192, 190, 189, 187, 186, 184, 183, 181, 180, 179, 177, 176, 174, 173, 172, 170, 169, 168, 166, 165, 164, 163, 161, 160, 159, 158, 
                156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 
                122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 106, 105, 104, 103, 102, 102, 101, 100,  99,  98,  98,  97,  96,  95, 
                 95,  94,  93,  92,  92,  91,  90,  90,  89,  88,  87,  87,  86,  85,  85,  84,  83,  83,  82,  82,  81,  80,  80,  79,  78,  78,  77,  77,  76,  75,  75,  74, 
                 74,  73,  72,  72,  71,  71,  70,  70,  69,  69,  68,  67,  67,  66,  66,  65,  65,  64,  64,  63,  63,  62,  62,  61,  61,  60,  60,  59,  59,  59,  58,  58, 
                 57,  57,  56,  56,  55,  55,  55,  54,  54,  53,  53,  52,  52,  52,  51,  51,  50,  50,  50,  49,  49,  48,  48,  48,  47,  47,  47,  46,  46,  45,  45,  45, 
                 44,  44,  44,  43,  43,  43,  42,  42,  42,  41,  41,  41,  40,  40,  40,  39,  39,  39,  39,  38,  38,  38,  37,  37,  37,  36,  36,  36,  36,  35,  35,  35, 
             },//lut0
             {
                255, 253, 245, 237, 230, 223, 216, 209, 203, 197, 191, 185, 179, 173, 168, 163, 158, 153, 148, 144, 139, 135, 131, 127, 123, 119, 115, 112, 108, 105, 102,  99, 
                 96,  93,  90,  87,  84,  82,  79,  77,  74,  72,  70,  68,  66,  64,  62,  60,  58,  56,  54,  53,  51,  49,  48,  46,  45,  43,  42,  41,  40,  38,  37,  36, 
                 35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  25,  24,  23,  22,  22,  21,  20,  20,  19,  18,  18,  17,  17,  16,  16,  15,  15,  14,  14,  13,  13, 
                 13,  12,  12,  11,  11,  11,  10,  10,  10,   9,   9,   9,   8,   8,   8,   8,   7,   7,   7,   7,   6,   6,   6,   6,   6,   5,   5,   5,   5,   5,   5,   4, 
                  4,   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   1,   1,   1,   1, 
                  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
             },//lut1
          },
       },
    },
    /* isp_sub_module_3d_2d_nr_tuning_t isp_sub_module_3d_2d_nr_tuning */
    {
       1, //enable
       1, //interpolation enable
       13, //ae count
       0, //trigger mode : 0 gain trigger 1 lux trigger
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            1.100,
          },
          /* aec trigger 2 */
          {
            2.000,
            2.100,
          },
          /* aec trigger 3 */
          {
            4.000,
            4.100,
          },
          /* aec trigger 4 */
          {
            8.000,
            8.100,
          },
          /* aec trigger 5 */
          {
            12.000,
            12.100,
          },
          /* aec trigger 6 */
          {
            16.000,
            16.100,
          },
          /* aec trigger 7 */
          {
            32.000,
            32.100,
          },
          /* aec trigger 8 */
          {
            64.000,
            64.100,
          },
          /* aec trigger 9 */
          {
            128.000,
            128.100,
          },
          /* aec trigger 10 */
          {
            256.000,
            256.100,
          },
          /* aec trigger 11 */
          {
            512.000,
            512.100,
          },
          /* aec trigger 12 */
          {
            1024.000,
            1024.100,
          },
          /* aec trigger 13 */
          {
            2048.000,
            2048.100,
          },
       },
       /*isp_sub_module_3d_2d_nr_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   131,107,92,81,72,65,59,54,49,45,42,38,35,32,29,27,24,22,20,18,16,14,12,11,9,8,6,5,3,2,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 2 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   131,107,92,81,72,65,59,54,49,45,42,38,35,32,29,27,24,22,20,18,16,14,12,11,9,8,6,5,3,2,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 3 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   131,107,92,81,72,65,59,54,49,45,42,38,35,32,29,27,24,22,20,18,16,14,12,11,9,8,6,5,3,2,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 4 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   164,133,115,101,90,82,74,68,62,57,52,48,44,40,37,34,31,28,25,23,20,18,16,13,11,10,8,6,4,2,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 5 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   164,133,115,101,90,82,74,68,62,57,52,48,44,40,37,34,31,28,25,23,20,18,16,13,11,10,8,6,4,2,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 6 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   197,160,138,121,109,98,89,81,74,68,62,57,53,48,44,40,37,33,30,27,24,21,19,16,14,12,9,7,5,3,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 7 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   197,160,138,121,109,98,89,81,74,68,62,57,53,48,44,40,37,33,30,27,24,21,19,16,14,12,9,7,5,3,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 8 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   229,187,161,142,127,114,104,95,87,80,73,67,61,56,52,47,43,39,35,32,28,25,22,19,16,14,11,8,6,4,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 9 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   229,187,161,142,127,114,104,95,87,80,73,67,61,56,52,47,43,39,35,32,28,25,22,19,16,14,11,8,6,4,1,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 10 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   295,240,207,182,163,147,134,122,112,102,94,86,79,73,67,61,55,50,45,41,37,32,28,25,21,18,14,11,8,5,2,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 11 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   328,267,230,203,181,164,149,136,124,114,104,96,88,81,74,68,62,56,51,46,41,36,32,27,23,20,16,12,9,5,2,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 12 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   394,321,276,243,218,196,179,163,149,137,125,115,106,97,89,81,74,67,61,55,49,43,38,33,28,24,19,15,10,6,3,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
           /* parameter 13 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   492,401,345,304,272,246,223,204,186,171,157,144,132,121,111,102,93,84,76,69,61,54,48,41,35,30,24,18,13,8,3,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               200, //th222
               //noise_profile[8]
               {
                   1,2,3,4,5,6,7,8,
               },
           },
       },
    },
    //isp_sub_module_dithering_tuning_t isp_sub_module_dithering_tuning;
    {
    },
    {
           /*int enable;*/
           1,
           /* int interpolation_enable;*/
           0,
           /*int count_ae;*/
           1,
           /*int trigger_mode;*/
           0,
           /* aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT];*/
           {
                   /*trigger 0*/
                   {
                           0,
                           400,
                   },
                   /*trigger 1*/
                   {
                           1,
                           400,
                   },
                   /*trigger 2*/
                   {
                           1,
                           400,
                   },
                        /*trigger 3*/
                   {
                           1,
                           400,
                   },
                   /*trigger 4*/
                   {
                           1,
                           400,
                   },
           },
           /* isp_sub_module_ceva_vfe_pra pra[MIDDLE_TRIGGER_COUNT];*/
           {
                   //pra0
                   {
                           0,
                           0,
                           4,
                           512,     //factor not used
                           2048,   //t1
                           18,     //1/(t2 - t1) u1.15
                           465,        //gain00 new add by zyue @1218
                           256,        //gain01 new add by zyue @1218
                           256,        //gain10 new add by zyue @1218
                           465,        //gain11 new add by zyue @1218
                           /*noise_lut*/
                           {
                                  151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,151521286,
                                  168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,168364297,
                                  202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,202050314,
                                  218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,218893324,
                                  235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,235802125,
                                  252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,252645134,
                                  286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,286265359,
                                  303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,303108369,
                                  303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,303174162,
                                  320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,320017170,
                                  336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,336860179,
                                  353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,353703188,
                                  370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,370480405,
                                  387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,387323414,
                                  387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,387389207,
                                  404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,404232215,
                           },
                           /*int drc_lut_pra_talbe_size;*/
                           //16,
                           5,
                           /* int inter_en;*/
                           1,
                           /*enable low gain clamp*/
                           0,
                           /*drc_lut_pra_t drc_lut_pra[DRC_LUT_PRA_TALBE_SIZE];*/
                           {
                                   //{10, 1<<13, 1, 6,0.50,0.1,0.5},
                                   //{20, 1<<13, 1, 6,0.36,0.1,0.5},
                                   //{30, 1<<13, 1, 6,0.32,0.1,0.5},
                                   //{35, 1<<13, 1, 6,0.31,0.1,0.5},
                                   //{40, 1<<13, 1, 6,0.30,0.1,0.5},
                                   {10, 1<<13, 0.3, 3, 1, 0.1, 0.5},
                                   {20, 1<<13, 0.3, 3, 1, 0.1, 0.5},
                                   {30, 1<<13, 0.3, 3, 1, 0.1, 0.5},
                                   {35, 1<<13, 0.3, 3, 1, 0.1, 0.5},
                                   {40, 1<<13, 0.3, 3, 1, 0.1, 0.5},
                           },

                   },
                   //pra1
                   {
                           240,
                           240,
                           4,
                           16,
                           3820,
                           1,
                           465,        //gain00 new add by zyue @1218
                           256,        //gain01 new add by zyue @1218
                           256,        //gain10 new add by zyue @1218
                           465,        //gain11 new add by zyue @1218
                           /*lut3*/
                           {},
                   },
                   //pra2
                   {
                           240,
                           240,
                           4,
                           16,
                           3820,
                           1,
                           465,        //gain00 new add by zyue @1218
                           256,        //gain01 new add by zyue @1218
                           256,        //gain10 new add by zyue @1218
                           465,        //gain11 new add by zyue @1218
                           /*lut3*/
                           {},
                   },
                   //pra3
                   {
                           240,
                           240,
                           4,
                           16,
                           3820,
                           1,
                           465,        //gain00 new add by zyue @1218
                           256,        //gain01 new add by zyue @1218
                           256,        //gain10 new add by zyue @1218
                           465,        //gain11 new add by zyue @1218
                           /*lut3*/
                           {},
                   },
                   //pra4
                   {
                           240,
                           240,
                           4,
                           16,
                           3820,
                           1,
                           465,        //gain00 new add by zyue @1218
                           256,        //gain01 new add by zyue @1218
                           256,        //gain10 new add by zyue @1218
                           465,        //gain11 new add by zyue @1218
                           /*lut3*/
                           {},
                   },
           },
    },
},
/*stats_config_t stats_config*/
{
},
/* aec_tuning_t aec_tuning*/
{
	/* ae version  */
	0x00000001,
	/*enbale*/
	1,
	/*ae start_exp_index*/
    160,
	/*ae start_skip_count*/
	1,
	/*ae torlerence*/
	2,
    /* ae exp_table_para */
    {
        /* count */
        502,
        /* ev0_count */
        502,
        /* ev2_count */
        502,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        1500,
        /* max_isp_gain */
        1,
        /* exp_table */
        {
          {256,  1  },        /* Gain= 1.000000 Exposure Index= 0 */
          {264,  1  },        /* Gain= 1.031250 Exposure Index= 1 */
          {272,  1  },        /* Gain= 1.062500 Exposure Index= 2 */
          {281,  1  },        /* Gain= 1.097656 Exposure Index= 3 */
          {290,  1  },        /* Gain= 1.132813 Exposure Index= 4 */
          {299,  1  },        /* Gain= 1.167969 Exposure Index= 5 */
          {308,  1  },        /* Gain= 1.203125 Exposure Index= 6 */
          {318,  1  },        /* Gain= 1.242188 Exposure Index= 7 */
          {328,  1  },        /* Gain= 1.281250 Exposure Index= 8 */
          {338,  1  },        /* Gain= 1.320313 Exposure Index= 9 */
          {349,  1  },        /* Gain= 1.363281 Exposure Index= 10 */
          {360,  1  },        /* Gain= 1.406250 Exposure Index= 11 */
          {371,  1  },        /* Gain= 1.449219 Exposure Index= 12 */
          {383,  1  },        /* Gain= 1.496094 Exposure Index= 13 */
          {395,  1  },        /* Gain= 1.542969 Exposure Index= 14 */
          {407,  1  },        /* Gain= 1.589844 Exposure Index= 15 */
          {420,  1  },        /* Gain= 1.640625 Exposure Index= 16 */
          {433,  1  },        /* Gain= 1.691406 Exposure Index= 17 */
          {446,  1  },        /* Gain= 1.742188 Exposure Index= 18 */
          {460,  1  },        /* Gain= 1.796875 Exposure Index= 19 */
          {474,  1  },        /* Gain= 1.851563 Exposure Index= 20 */
          {489,  1  },        /* Gain= 1.910156 Exposure Index= 21 */
          {504,  1  },        /* Gain= 1.968750 Exposure Index= 22 */
          {260,  2  },        /* Gain= 1.015625 Exposure Index= 23 */
          {268,  2  },        /* Gain= 1.046875 Exposure Index= 24 */
          {277,  2  },        /* Gain= 1.082031 Exposure Index= 25 */
          {286,  2  },        /* Gain= 1.117188 Exposure Index= 26 */
          {295,  2  },        /* Gain= 1.152344 Exposure Index= 27 */
          {304,  2  },        /* Gain= 1.187500 Exposure Index= 28 */
          {314,  2  },        /* Gain= 1.226563 Exposure Index= 29 */
          {324,  2  },        /* Gain= 1.265625 Exposure Index= 30 */
          {334,  2  },        /* Gain= 1.304688 Exposure Index= 31 */
          {345,  2  },        /* Gain= 1.347656 Exposure Index= 32 */
          {356,  2  },        /* Gain= 1.390625 Exposure Index= 33 */
          {367,  2  },        /* Gain= 1.433594 Exposure Index= 34 */
          {379,  2  },        /* Gain= 1.480469 Exposure Index= 35 */
          {261,  3  },        /* Gain= 1.019531 Exposure Index= 36 */
          {269,  3  },        /* Gain= 1.050781 Exposure Index= 37 */
          {278,  3  },        /* Gain= 1.085938 Exposure Index= 38 */
          {287,  3  },        /* Gain= 1.121094 Exposure Index= 39 */
          {296,  3  },        /* Gain= 1.156250 Exposure Index= 40 */
          {305,  3  },        /* Gain= 1.191406 Exposure Index= 41 */
          {315,  3  },        /* Gain= 1.230469 Exposure Index= 42 */
          {325,  3  },        /* Gain= 1.269531 Exposure Index= 43 */
          {335,  3  },        /* Gain= 1.308594 Exposure Index= 44 */
          {259,  4  },        /* Gain= 1.011719 Exposure Index= 45 */
          {267,  4  },        /* Gain= 1.042969 Exposure Index= 46 */
          {276,  4  },        /* Gain= 1.078125 Exposure Index= 47 */
          {285,  4  },        /* Gain= 1.113281 Exposure Index= 48 */
          {294,  4  },        /* Gain= 1.148438 Exposure Index= 49 */
          {303,  4  },        /* Gain= 1.183594 Exposure Index= 50 */
          {313,  4  },        /* Gain= 1.222656 Exposure Index= 51 */
          {258,  5  },        /* Gain= 1.007813 Exposure Index= 52 */
          {266,  5  },        /* Gain= 1.039063 Exposure Index= 53 */
          {274,  5  },        /* Gain= 1.070313 Exposure Index= 54 */
          {283,  5  },        /* Gain= 1.105469 Exposure Index= 55 */
          {292,  5  },        /* Gain= 1.140625 Exposure Index= 56 */
          {301,  5  },        /* Gain= 1.175781 Exposure Index= 57 */
          {259,  6  },        /* Gain= 1.011719 Exposure Index= 58 */
          {267,  6  },        /* Gain= 1.042969 Exposure Index= 59 */
          {276,  6  },        /* Gain= 1.078125 Exposure Index= 60 */
          {285,  6  },        /* Gain= 1.113281 Exposure Index= 61 */
          {294,  6  },        /* Gain= 1.148438 Exposure Index= 62 */
          {260,  7  },        /* Gain= 1.015625 Exposure Index= 63 */
          {268,  7  },        /* Gain= 1.046875 Exposure Index= 64 */
          {277,  7  },        /* Gain= 1.082031 Exposure Index= 65 */
          {286,  7  },        /* Gain= 1.117188 Exposure Index= 66 */
          {258,  8  },        /* Gain= 1.007813 Exposure Index= 67 */
          {266,  8  },        /* Gain= 1.039063 Exposure Index= 68 */
          {274,  8  },        /* Gain= 1.070313 Exposure Index= 69 */
          {283,  8  },        /* Gain= 1.105469 Exposure Index= 70 */
          {260,  9  },        /* Gain= 1.015625 Exposure Index= 71 */
          {268,  9  },        /* Gain= 1.046875 Exposure Index= 72 */
          {277,  9  },        /* Gain= 1.082031 Exposure Index= 73 */
          {257,  10  },        /* Gain= 1.003906 Exposure Index= 74 */
          {265,  10  },        /* Gain= 1.035156 Exposure Index= 75 */
          {273,  10  },        /* Gain= 1.066406 Exposure Index= 76 */
          {256,  11  },        /* Gain= 1.000000 Exposure Index= 77 */
          {264,  11  },        /* Gain= 1.031250 Exposure Index= 78 */
          {272,  11  },        /* Gain= 1.062500 Exposure Index= 79 */
          {257,  12  },        /* Gain= 1.003906 Exposure Index= 80 */
          {265,  12  },        /* Gain= 1.035156 Exposure Index= 81 */
          {273,  12  },        /* Gain= 1.066406 Exposure Index= 82 */
          {260,  13  },        /* Gain= 1.015625 Exposure Index= 83 */
          {268,  13  },        /* Gain= 1.046875 Exposure Index= 84 */
          {257,  14  },        /* Gain= 1.003906 Exposure Index= 85 */
          {265,  14  },        /* Gain= 1.035156 Exposure Index= 86 */
          {273,  14  },        /* Gain= 1.066406 Exposure Index= 87 */
          {263,  15  },        /* Gain= 1.027344 Exposure Index= 88 */
          {271,  15  },        /* Gain= 1.058594 Exposure Index= 89 */
          {262,  16  },        /* Gain= 1.023438 Exposure Index= 90 */
          {270,  16  },        /* Gain= 1.054688 Exposure Index= 91 */
          {262,  17  },        /* Gain= 1.023438 Exposure Index= 92 */
          {270,  17  },        /* Gain= 1.054688 Exposure Index= 93 */
          {263,  18  },        /* Gain= 1.027344 Exposure Index= 94 */
          {257,  19  },        /* Gain= 1.003906 Exposure Index= 95 */
          {265,  19  },        /* Gain= 1.035156 Exposure Index= 96 */
          {260,  20  },        /* Gain= 1.015625 Exposure Index= 97 */
          {268,  20  },        /* Gain= 1.046875 Exposure Index= 98 */
          {263,  21  },        /* Gain= 1.027344 Exposure Index= 99 */
          {259,  22  },        /* Gain= 1.011719 Exposure Index= 100 */
          {267,  22  },        /* Gain= 1.042969 Exposure Index= 101 */
          {264,  23  },        /* Gain= 1.031250 Exposure Index= 102 */
          {261,  24  },        /* Gain= 1.019531 Exposure Index= 103 */
          {259,  25  },        /* Gain= 1.011719 Exposure Index= 104 */
          {257,  26  },        /* Gain= 1.003906 Exposure Index= 105 */
          {265,  26  },        /* Gain= 1.035156 Exposure Index= 106 */
          {263,  27  },        /* Gain= 1.027344 Exposure Index= 107 */
          {262,  28  },        /* Gain= 1.023438 Exposure Index= 108 */
          {261,  29  },        /* Gain= 1.019531 Exposure Index= 109 */
          {260,  30  },        /* Gain= 1.015625 Exposure Index= 110 */
          {260,  31  },        /* Gain= 1.015625 Exposure Index= 111 */
          {260,  32  },        /* Gain= 1.015625 Exposure Index= 112 */
          {260,  33  },        /* Gain= 1.015625 Exposure Index= 113 */
          {260,  34  },        /* Gain= 1.015625 Exposure Index= 114 */
          {261,  35  },        /* Gain= 1.019531 Exposure Index= 115 */
          {262,  36  },        /* Gain= 1.023438 Exposure Index= 116 */
          {256,  38  },        /* Gain= 1.000000 Exposure Index= 117 */
          {257,  39  },        /* Gain= 1.003906 Exposure Index= 118 */
          {259,  40  },        /* Gain= 1.011719 Exposure Index= 119 */
          {261,  41  },        /* Gain= 1.019531 Exposure Index= 120 */
          {257,  43  },        /* Gain= 1.003906 Exposure Index= 121 */
          {259,  44  },        /* Gain= 1.011719 Exposure Index= 122 */
          {261,  45  },        /* Gain= 1.019531 Exposure Index= 123 */
          {258,  47  },        /* Gain= 1.007813 Exposure Index= 124 */
          {261,  48  },        /* Gain= 1.019531 Exposure Index= 125 */
          {259,  50  },        /* Gain= 1.011719 Exposure Index= 126 */
          {257,  52  },        /* Gain= 1.003906 Exposure Index= 127 */
          {260,  53  },        /* Gain= 1.015625 Exposure Index= 128 */
          {259,  55  },        /* Gain= 1.011719 Exposure Index= 129 */
          {258,  57  },        /* Gain= 1.007813 Exposure Index= 130 */
          {257,  59  },        /* Gain= 1.003906 Exposure Index= 131 */
          {257,  61  },        /* Gain= 1.003906 Exposure Index= 132 */
          {257,  63  },        /* Gain= 1.003906 Exposure Index= 133 */
          {257,  65  },        /* Gain= 1.003906 Exposure Index= 134 */
          {257,  67  },        /* Gain= 1.003906 Exposure Index= 135 */
          {258,  69  },        /* Gain= 1.007813 Exposure Index= 136 */
          {259,  71  },        /* Gain= 1.011719 Exposure Index= 137 */
          {256,  74  },        /* Gain= 1.000000 Exposure Index= 138 */
          {257,  76  },        /* Gain= 1.003906 Exposure Index= 139 */
          {258,  78  },        /* Gain= 1.007813 Exposure Index= 140 */
          {256,  81  },        /* Gain= 1.000000 Exposure Index= 141 */
          {258,  83  },        /* Gain= 1.007813 Exposure Index= 142 */
          {257,  86  },        /* Gain= 1.003906 Exposure Index= 143 */
          {256,  89  },        /* Gain= 1.000000 Exposure Index= 144 */
          {258,  91  },        /* Gain= 1.007813 Exposure Index= 145 */
          {258,  94  },        /* Gain= 1.007813 Exposure Index= 146 */
          {258,  97  },        /* Gain= 1.007813 Exposure Index= 147 */
          {258,  100  },        /* Gain= 1.007813 Exposure Index= 148 */
          {258,  103  },        /* Gain= 1.007813 Exposure Index= 149 */
          {256,  107  },        /* Gain= 1.000000 Exposure Index= 150 */
          {257,  110  },        /* Gain= 1.003906 Exposure Index= 151 */
          {258,  113  },        /* Gain= 1.007813 Exposure Index= 152 */
          {257,  117  },        /* Gain= 1.003906 Exposure Index= 153 */
          {256,  121  },        /* Gain= 1.000000 Exposure Index= 154 */
          {258,  124  },        /* Gain= 1.007813 Exposure Index= 155 */
          {256,  129  },        /* Gain= 1.000000 Exposure Index= 156 */
          {256,  133  },        /* Gain= 1.000000 Exposure Index= 157 */
          {256,  137  },        /* Gain= 1.000000 Exposure Index= 158 */
          {257,  141  },        /* Gain= 1.003906 Exposure Index= 159 */
          {256,  146  },        /* Gain= 1.000000 Exposure Index= 160 */
          {257,  150  },        /* Gain= 1.003906 Exposure Index= 161 */
          {257,  155  },        /* Gain= 1.003906 Exposure Index= 162 */
          {257,  160  },        /* Gain= 1.003906 Exposure Index= 163 */
          {257,  165  },        /* Gain= 1.003906 Exposure Index= 164 */
          {257,  170  },        /* Gain= 1.003906 Exposure Index= 165 */
          {256,  176  },        /* Gain= 1.000000 Exposure Index= 166 */
          {257,  181  },        /* Gain= 1.003906 Exposure Index= 167 */
          {257,  187  },        /* Gain= 1.003906 Exposure Index= 168 */
          {257,  193  },        /* Gain= 1.003906 Exposure Index= 169 */
          {257,  199  },        /* Gain= 1.003906 Exposure Index= 170 */
          {257,  205  },        /* Gain= 1.003906 Exposure Index= 171 */
          {256,  212  },        /* Gain= 1.000000 Exposure Index= 172 */
          {257,  218  },        /* Gain= 1.003906 Exposure Index= 173 */
          {257,  225  },        /* Gain= 1.003906 Exposure Index= 174 */
          {257,  232  },        /* Gain= 1.003906 Exposure Index= 175 */
          {257,  239  },        /* Gain= 1.003906 Exposure Index= 176 */
          {257,  247  },        /* Gain= 1.003906 Exposure Index= 177 */
          {257,  255  },        /* Gain= 1.003906 Exposure Index= 178 */
          {256,  264  },        /* Gain= 1.000000 Exposure Index= 179 */
          {256,  272  },        /* Gain= 1.000000 Exposure Index= 180 */
          {256,  281  },        /* Gain= 1.000000 Exposure Index= 181 */
          {256,  290  },        /* Gain= 1.000000 Exposure Index= 182 */
          {256,  299  },        /* Gain= 1.000000 Exposure Index= 183 */
          {256,  308  },        /* Gain= 1.000000 Exposure Index= 184 */
          {256,  318  },        /* Gain= 1.000000 Exposure Index= 185 */
          {256,  328  },        /* Gain= 1.000000 Exposure Index= 186 */
          {256,  338  },        /* Gain= 1.000000 Exposure Index= 187 */
          {262,  341  },        /* Gain= 1.023438 Exposure Index= 188 */
          {270,  341  },        /* Gain= 1.054688 Exposure Index= 189 */
          {279,  341  },        /* Gain= 1.089844 Exposure Index= 190 */
          {288,  341  },        /* Gain= 1.125000 Exposure Index= 191 */
          {297,  341  },        /* Gain= 1.160156 Exposure Index= 192 */
          {306,  341  },        /* Gain= 1.195313 Exposure Index= 193 */
          {316,  341  },        /* Gain= 1.234375 Exposure Index= 194 */
          {326,  341  },        /* Gain= 1.273438 Exposure Index= 195 */
          {336,  341  },        /* Gain= 1.312500 Exposure Index= 196 */
          {347,  341  },        /* Gain= 1.355469 Exposure Index= 197 */
          {358,  341  },        /* Gain= 1.398438 Exposure Index= 198 */
          {369,  341  },        /* Gain= 1.441406 Exposure Index= 199 */
          {381,  341  },        /* Gain= 1.488281 Exposure Index= 200 */
          {393,  341  },        /* Gain= 1.535156 Exposure Index= 201 */
          {405,  341  },        /* Gain= 1.582031 Exposure Index= 202 */
          {418,  341  },        /* Gain= 1.632813 Exposure Index= 203 */
          {431,  341  },        /* Gain= 1.683594 Exposure Index= 204 */
          {444,  341  },        /* Gain= 1.734375 Exposure Index= 205 */
          {458,  341  },        /* Gain= 1.789063 Exposure Index= 206 */
          {472,  341  },        /* Gain= 1.843750 Exposure Index= 207 */
          {487,  341  },        /* Gain= 1.902344 Exposure Index= 208 */
          {502,  341  },        /* Gain= 1.960938 Exposure Index= 209 */
          {518,  341  },        /* Gain= 2.023438 Exposure Index= 210 */
          {534,  341  },        /* Gain= 2.085938 Exposure Index= 211 */
          {551,  341  },        /* Gain= 2.152344 Exposure Index= 212 */
          {568,  341  },        /* Gain= 2.218750 Exposure Index= 213 */
          {586,  341  },        /* Gain= 2.289063 Exposure Index= 214 */
          {604,  341  },        /* Gain= 2.359375 Exposure Index= 215 */
          {623,  341  },        /* Gain= 2.433594 Exposure Index= 216 */
          {642,  341  },        /* Gain= 2.507813 Exposure Index= 217 */
          {662,  341  },        /* Gain= 2.585938 Exposure Index= 218 */
          {682,  341  },        /* Gain= 2.664063 Exposure Index= 219 */
          {703,  341  },        /* Gain= 2.746094 Exposure Index= 220 */
          {725,  341  },        /* Gain= 2.832031 Exposure Index= 221 */
          {747,  341  },        /* Gain= 2.917969 Exposure Index= 222 */
          {770,  341  },        /* Gain= 3.007813 Exposure Index= 223 */
          {794,  341  },        /* Gain= 3.101563 Exposure Index= 224 */
          {818,  341  },        /* Gain= 3.195313 Exposure Index= 225 */
          {843,  341  },        /* Gain= 3.292969 Exposure Index= 226 */
          {869,  341  },        /* Gain= 3.394531 Exposure Index= 227 */
          {896,  341  },        /* Gain= 3.500000 Exposure Index= 228 */
          {923,  341  },        /* Gain= 3.605469 Exposure Index= 229 */
          {951,  341  },        /* Gain= 3.714844 Exposure Index= 230 */
          {980,  341  },        /* Gain= 3.828125 Exposure Index= 231 */
          {1010,  341  },        /* Gain= 3.945313 Exposure Index= 232 */
          {1041,  341  },        /* Gain= 4.066406 Exposure Index= 233 */
          {1073,  341  },        /* Gain= 4.191406 Exposure Index= 234 */
          {1106,  341  },        /* Gain= 4.320313 Exposure Index= 235 */
          {1140,  341  },        /* Gain= 4.453125 Exposure Index= 236 */
          {1175,  341  },        /* Gain= 4.589844 Exposure Index= 237 */
          {1211,  341  },        /* Gain= 4.730469 Exposure Index= 238 */
          {1248,  341  },        /* Gain= 4.875000 Exposure Index= 239 */
          {1286,  341  },        /* Gain= 5.023438 Exposure Index= 240 */
          {1325,  341  },        /* Gain= 5.175781 Exposure Index= 241 */
          {1365,  341  },        /* Gain= 5.332031 Exposure Index= 242 */
          {1406,  341  },        /* Gain= 5.492188 Exposure Index= 243 */
          {1449,  341  },        /* Gain= 5.660156 Exposure Index= 244 */
          {1493,  341  },        /* Gain= 5.832031 Exposure Index= 245 */
          {1538,  341  },        /* Gain= 6.007813 Exposure Index= 246 */
          {1585,  341  },        /* Gain= 6.191406 Exposure Index= 247 */
          {1633,  341  },        /* Gain= 6.378906 Exposure Index= 248 */
          {1682,  341  },        /* Gain= 6.570313 Exposure Index= 249 */
          {1733,  341  },        /* Gain= 6.769531 Exposure Index= 250 */
          {1785,  341  },        /* Gain= 6.972656 Exposure Index= 251 */
          {1839,  341  },        /* Gain= 7.183594 Exposure Index= 252 */
          {1895,  341  },        /* Gain= 7.402344 Exposure Index= 253 */
          {1952,  341  },        /* Gain= 7.625000 Exposure Index= 254 */
          {2011,  341  },        /* Gain= 7.855469 Exposure Index= 255 */
          {2048,  345  },        /* Gain= 8.000000 Exposure Index= 256 */
          {2048,  356  },        /* Gain= 8.000000 Exposure Index= 257 */
          {2048,  367  },        /* Gain= 8.000000 Exposure Index= 258 */
          {2048,  379  },        /* Gain= 8.000000 Exposure Index= 259 */
          {2048,  391  },        /* Gain= 8.000000 Exposure Index= 260 */
          {2048,  403  },        /* Gain= 8.000000 Exposure Index= 261 */
          {2048,  416  },        /* Gain= 8.000000 Exposure Index= 262 */
          {2048,  429  },        /* Gain= 8.000000 Exposure Index= 263 */
          {2048,  442  },        /* Gain= 8.000000 Exposure Index= 264 */
          {2048,  456  },        /* Gain= 8.000000 Exposure Index= 265 */
          {2048,  470  },        /* Gain= 8.000000 Exposure Index= 266 */
          {2048,  485  },        /* Gain= 8.000000 Exposure Index= 267 */
          {2048,  500  },        /* Gain= 8.000000 Exposure Index= 268 */
          {2048,  515  },        /* Gain= 8.000000 Exposure Index= 269 */
          {2048,  531  },        /* Gain= 8.000000 Exposure Index= 270 */
          {2048,  547  },        /* Gain= 8.000000 Exposure Index= 271 */
          {2048,  564  },        /* Gain= 8.000000 Exposure Index= 272 */
          {2048,  581  },        /* Gain= 8.000000 Exposure Index= 273 */
          {2048,  599  },        /* Gain= 8.000000 Exposure Index= 274 */
          {2048,  617  },        /* Gain= 8.000000 Exposure Index= 275 */
          {2048,  636  },        /* Gain= 8.000000 Exposure Index= 276 */
          {2048,  656  },        /* Gain= 8.000000 Exposure Index= 277 */
          {2048,  676  },        /* Gain= 8.000000 Exposure Index= 278 */
          {2091,  682  },        /* Gain= 8.167969 Exposure Index= 279 */
          {2154,  682  },        /* Gain= 8.414063 Exposure Index= 280 */
          {2219,  682  },        /* Gain= 8.667969 Exposure Index= 281 */
          {2286,  682  },        /* Gain= 8.929688 Exposure Index= 282 */
          {2355,  682  },        /* Gain= 9.199219 Exposure Index= 283 */
          {2426,  682  },        /* Gain= 9.476563 Exposure Index= 284 */
          {2499,  682  },        /* Gain= 9.761719 Exposure Index= 285 */
          {2574,  682  },        /* Gain= 10.054688 Exposure Index= 286 */
          {2652,  682  },        /* Gain= 10.359375 Exposure Index= 287 */
          {2732,  682  },        /* Gain= 10.671875 Exposure Index= 288 */
          {2814,  682  },        /* Gain= 10.992188 Exposure Index= 289 */
          {2899,  682  },        /* Gain= 11.324219 Exposure Index= 290 */
          {2986,  682  },        /* Gain= 11.664063 Exposure Index= 291 */
          {3076,  682  },        /* Gain= 12.015625 Exposure Index= 292 */
          {3169,  682  },        /* Gain= 12.378906 Exposure Index= 293 */
          {3265,  682  },        /* Gain= 12.753906 Exposure Index= 294 */
          {3363,  682  },        /* Gain= 13.136719 Exposure Index= 295 */
          {3464,  682  },        /* Gain= 13.531250 Exposure Index= 296 */
          {3568,  682  },        /* Gain= 13.937500 Exposure Index= 297 */
          {3676,  682  },        /* Gain= 14.359375 Exposure Index= 298 */
          {3787,  682  },        /* Gain= 14.792969 Exposure Index= 299 */
          {3901,  682  },        /* Gain= 15.238281 Exposure Index= 300 */
          {4019,  682  },        /* Gain= 15.699219 Exposure Index= 301 */
          {4096,  690  },        /* Gain= 16.000000 Exposure Index= 302 */
          {4096,  711  },        /* Gain= 16.000000 Exposure Index= 303 */
          {4096,  733  },        /* Gain= 16.000000 Exposure Index= 304 */
          {4096,  755  },        /* Gain= 16.000000 Exposure Index= 305 */
          {4096,  778  },        /* Gain= 16.000000 Exposure Index= 306 */
          {4096,  802  },        /* Gain= 16.000000 Exposure Index= 307 */
          {4096,  827  },        /* Gain= 16.000000 Exposure Index= 308 */
          {4096,  852  },        /* Gain= 16.000000 Exposure Index= 309 */
          {4096,  878  },        /* Gain= 16.000000 Exposure Index= 310 */
          {4096,  905  },        /* Gain= 16.000000 Exposure Index= 311 */
          {4096,  933  },        /* Gain= 16.000000 Exposure Index= 312 */
          {4096,  961  },        /* Gain= 16.000000 Exposure Index= 313 */
          {4096,  990  },        /* Gain= 16.000000 Exposure Index= 314 */
          {4096,  1020  },        /* Gain= 16.000000 Exposure Index= 315 */
          {4207,  1023  },        /* Gain= 16.433594 Exposure Index= 316 */
          {4334,  1023  },        /* Gain= 16.929688 Exposure Index= 317 */
          {4465,  1023  },        /* Gain= 17.441406 Exposure Index= 318 */
          {4599,  1023  },        /* Gain= 17.964844 Exposure Index= 319 */
          {4737,  1023  },        /* Gain= 18.503906 Exposure Index= 320 */
          {4880,  1023  },        /* Gain= 19.062500 Exposure Index= 321 */
          {5027,  1023  },        /* Gain= 19.636719 Exposure Index= 322 */
          {5178,  1023  },        /* Gain= 20.226563 Exposure Index= 323 */
          {5334,  1023  },        /* Gain= 20.835938 Exposure Index= 324 */
          {5495,  1023  },        /* Gain= 21.464844 Exposure Index= 325 */
          {5660,  1023  },        /* Gain= 22.109375 Exposure Index= 326 */
          {5830,  1023  },        /* Gain= 22.773438 Exposure Index= 327 */
          {6005,  1023  },        /* Gain= 23.457031 Exposure Index= 328 */
          {6186,  1023  },        /* Gain= 24.164063 Exposure Index= 329 */
          {6372,  1023  },        /* Gain= 24.890625 Exposure Index= 330 */
          {6564,  1023  },        /* Gain= 25.640625 Exposure Index= 331 */
          {6761,  1023  },        /* Gain= 26.410156 Exposure Index= 332 */
          {6964,  1023  },        /* Gain= 27.203125 Exposure Index= 333 */
          {7173,  1023  },        /* Gain= 28.019531 Exposure Index= 334 */
          {7389,  1023  },        /* Gain= 28.863281 Exposure Index= 335 */
          {7611,  1023  },        /* Gain= 29.730469 Exposure Index= 336 */
          {7840,  1023  },        /* Gain= 30.625000 Exposure Index= 337 */
          {8076,  1023  },        /* Gain= 31.546875 Exposure Index= 338 */
          {8319,  1023  },        /* Gain= 32.496094 Exposure Index= 339 */
          {8569,  1023  },        /* Gain= 33.472656 Exposure Index= 340 */
          {8827,  1023  },        /* Gain= 34.480469 Exposure Index= 341 */
          {9092,  1023  },        /* Gain= 35.515625 Exposure Index= 342 */
          {9365,  1023  },        /* Gain= 36.582031 Exposure Index= 343 */
          {9646,  1023  },        /* Gain= 37.679688 Exposure Index= 344 */
          {9936,  1023  },        /* Gain= 38.812500 Exposure Index= 345 */
          {10235,  1023  },        /* Gain= 39.980469 Exposure Index= 346 */
          {10543,  1023  },        /* Gain= 41.183594 Exposure Index= 347 */
          {10860,  1023  },        /* Gain= 42.421875 Exposure Index= 348 */
          {11186,  1023  },        /* Gain= 43.695313 Exposure Index= 349 */
          {11522,  1023  },        /* Gain= 45.007813 Exposure Index= 350 */
          {11868,  1023  },        /* Gain= 46.359375 Exposure Index= 351 */
          {12225,  1023  },        /* Gain= 47.753906 Exposure Index= 352 */
          {12592,  1023  },        /* Gain= 49.187500 Exposure Index= 353 */
          {12970,  1023  },        /* Gain= 50.664063 Exposure Index= 354 */
          {13360,  1023  },        /* Gain= 52.187500 Exposure Index= 355 */
          {13761,  1023  },        /* Gain= 53.753906 Exposure Index= 356 */
          {14174,  1023  },        /* Gain= 55.367188 Exposure Index= 357 */
          {14600,  1023  },        /* Gain= 57.031250 Exposure Index= 358 */
          {15038,  1023  },        /* Gain= 58.742188 Exposure Index= 359 */
          {15490,  1023  },        /* Gain= 60.507813 Exposure Index= 360 */
          {15955,  1023  },        /* Gain= 62.324219 Exposure Index= 361 */
          {16434,  1023  },        /* Gain= 64.195313 Exposure Index= 362 */
          {16928,  1023  },        /* Gain= 66.125000 Exposure Index= 363 */
          {17436,  1023  },        /* Gain= 68.109375 Exposure Index= 364 */
          {17960,  1023  },        /* Gain= 70.156250 Exposure Index= 365 */
          {18499,  1023  },        /* Gain= 72.261719 Exposure Index= 366 */
          {19054,  1023  },        /* Gain= 74.429688 Exposure Index= 367 */
          {19626,  1023  },        /* Gain= 76.664063 Exposure Index= 368 */
          {20215,  1023  },        /* Gain= 78.964844 Exposure Index= 369 */
          {20822,  1023  },        /* Gain= 81.335938 Exposure Index= 370 */
          {21447,  1023  },        /* Gain= 83.777344 Exposure Index= 371 */
          {22091,  1023  },        /* Gain= 86.292969 Exposure Index= 372 */
          {22754,  1023  },        /* Gain= 88.882813 Exposure Index= 373 */
          {23437,  1023  },        /* Gain= 91.550781 Exposure Index= 374 */
          {24141,  1023  },        /* Gain= 94.300781 Exposure Index= 375 */
          {24866,  1023  },        /* Gain= 97.132813 Exposure Index= 376 */
          {25600,  1024  },        /* Gain= 100.000000 Exposure Index= 377 */
          {25600,  1055  },        /* Gain= 100.000000 Exposure Index= 378 */
          {25600,  1087  },        /* Gain= 100.000000 Exposure Index= 379 */
          {25600,  1120  },        /* Gain= 100.000000 Exposure Index= 380 */
          {25600,  1154  },        /* Gain= 100.000000 Exposure Index= 381 */
          {25600,  1189  },        /* Gain= 100.000000 Exposure Index= 382 */
          {25600,  1225  },        /* Gain= 100.000000 Exposure Index= 383 */
          {25600,  1262  },        /* Gain= 100.000000 Exposure Index= 384 */
          {25600,  1300  },        /* Gain= 100.000000 Exposure Index= 385 */
          {25600,  1339  },        /* Gain= 100.000000 Exposure Index= 386 */
          {25600,  1380  },        /* Gain= 100.000000 Exposure Index= 387 */
          {25600,  1422  },        /* Gain= 100.000000 Exposure Index= 388 */
          {25600,  1465  },        /* Gain= 100.000000 Exposure Index= 389 */
          {25600,  1509  },        /* Gain= 100.000000 Exposure Index= 390 */
          {25600,  1555  },        /* Gain= 100.000000 Exposure Index= 391 */
          {25600,  1602  },        /* Gain= 100.000000 Exposure Index= 392 */
          {25600,  1651  },        /* Gain= 100.000000 Exposure Index= 393 */
          {25600,  1701  },        /* Gain= 100.000000 Exposure Index= 394 */
          {25600,  1753  },        /* Gain= 100.000000 Exposure Index= 395 */
          {25600,  1806  },        /* Gain= 100.000000 Exposure Index= 396 */
          {25600,  1861  },        /* Gain= 100.000000 Exposure Index= 397 */
          {25600,  1917  },        /* Gain= 100.000000 Exposure Index= 398 */
          {25600,  1975  },        /* Gain= 100.000000 Exposure Index= 399 */
          {25600,  2035  },        /* Gain= 100.000000 Exposure Index= 400 */
          {25600,  2097  },        /* Gain= 100.000000 Exposure Index= 401 */
          {25600,  2160  },        /* Gain= 100.000000 Exposure Index= 402 */
          {25600,  2225  },        /* Gain= 100.000000 Exposure Index= 403 */
          {25600,  2292  },        /* Gain= 100.000000 Exposure Index= 404 */
          {25600,  2361  },        /* Gain= 100.000000 Exposure Index= 405 */
          {25600,  2432  },        /* Gain= 100.000000 Exposure Index= 406 */
          {25600,  2505  },        /* Gain= 100.000000 Exposure Index= 407 */
          {25600,  2581  },        /* Gain= 100.000000 Exposure Index= 408 */
          {25600,  2659  },        /* Gain= 100.000000 Exposure Index= 409 */
          {25968,  2700  },        /* Gain= 101.437500 Exposure Index= 410 */
          {26748,  2700  },        /* Gain= 104.484375 Exposure Index= 411 */
          {27551,  2700  },        /* Gain= 107.621094 Exposure Index= 412 */
          {28378,  2700  },        /* Gain= 110.851563 Exposure Index= 413 */
          {29230,  2700  },        /* Gain= 114.179688 Exposure Index= 414 */
          {30107,  2700  },        /* Gain= 117.605469 Exposure Index= 415 */
          {31011,  2700  },        /* Gain= 121.136719 Exposure Index= 416 */
          {31942,  2700  },        /* Gain= 124.773438 Exposure Index= 417 */
          {32901,  2700  },        /* Gain= 128.519531 Exposure Index= 418 */
          {33889,  2700  },        /* Gain= 132.378906 Exposure Index= 419 */
          {34906,  2700  },        /* Gain= 136.351563 Exposure Index= 420 */
          {35954,  2700  },        /* Gain= 140.445313 Exposure Index= 421 */
          {37033,  2700  },        /* Gain= 144.660156 Exposure Index= 422 */
          {38144,  2700  },        /* Gain= 149.000000 Exposure Index= 423 */
          {39289,  2700  },        /* Gain= 153.472656 Exposure Index= 424 */
          {40468,  2700  },        /* Gain= 158.078125 Exposure Index= 425 */
          {41683,  2700  },        /* Gain= 162.824219 Exposure Index= 426 */
          {42934,  2700  },        /* Gain= 167.710938 Exposure Index= 427 */
          {44223,  2700  },        /* Gain= 172.746094 Exposure Index= 428 */
          {45550,  2700  },        /* Gain= 177.929688 Exposure Index= 429 */
          {46917,  2700  },        /* Gain= 183.269531 Exposure Index= 430 */
          {48325,  2700  },        /* Gain= 188.769531 Exposure Index= 431 */
          {49775,  2700  },        /* Gain= 194.433594 Exposure Index= 432 */
          {51269,  2700  },        /* Gain= 200.269531 Exposure Index= 433 */
          {52808,  2700  },        /* Gain= 206.281250 Exposure Index= 434 */
          {54393,  2700  },        /* Gain= 212.472656 Exposure Index= 435 */
          {56025,  2700  },        /* Gain= 218.847656 Exposure Index= 436 */
          {57706,  2700  },        /* Gain= 225.414063 Exposure Index= 437 */
          {59438,  2700  },        /* Gain= 232.179688 Exposure Index= 438 */
          {61222,  2700  },        /* Gain= 239.148438 Exposure Index= 439 */
          {63059,  2700  },        /* Gain= 246.324219 Exposure Index= 440 */
          {64951,  2700  },        /* Gain= 253.714844 Exposure Index= 441 */
          {66900,  2700  },        /* Gain= 261.328125 Exposure Index= 442 */
          {68907,  2700  },        /* Gain= 269.167969 Exposure Index= 443 */
          {70975,  2700  },        /* Gain= 277.246094 Exposure Index= 444 */
          {73105,  2700  },        /* Gain= 285.566406 Exposure Index= 445 */
          {75299,  2700  },        /* Gain= 294.136719 Exposure Index= 446 */
          {77558,  2700  },        /* Gain= 302.960938 Exposure Index= 447 */
          {79885,  2700  },        /* Gain= 312.050781 Exposure Index= 448 */
          {82282,  2700  },        /* Gain= 321.414063 Exposure Index= 449 */
          {84751,  2700  },        /* Gain= 331.058594 Exposure Index= 450 */
          {87294,  2700  },        /* Gain= 340.992188 Exposure Index= 451 */
          {89913,  2700  },        /* Gain= 351.222656 Exposure Index= 452 */
          {92611,  2700  },        /* Gain= 361.761719 Exposure Index= 453 */
          {95390,  2700  },        /* Gain= 372.617188 Exposure Index= 454 */
          {98252,  2700  },        /* Gain= 383.796875 Exposure Index= 455 */
          {101200,  2700  },        /* Gain= 395.312500 Exposure Index= 456 */
          {104236,  2700  },        /* Gain= 407.171875 Exposure Index= 457 */
          {107364,  2700  },        /* Gain= 419.390625 Exposure Index= 458 */
          {110585,  2700  },        /* Gain= 431.972656 Exposure Index= 459 */
          {113903,  2700  },        /* Gain= 444.933594 Exposure Index= 460 */
          {117321,  2700  },        /* Gain= 458.285156 Exposure Index= 461 */
          {120841,  2700  },        /* Gain= 472.035156 Exposure Index= 462 */
          {124467,  2700  },        /* Gain= 486.199219 Exposure Index= 463 */
          {128202,  2700  },        /* Gain= 500.789063 Exposure Index= 464 */
          {132049,  2700  },        /* Gain= 515.816406 Exposure Index= 465 */
          {136011,  2700  },        /* Gain= 531.292969 Exposure Index= 466 */
          {140092,  2700  },        /* Gain= 547.234375 Exposure Index= 467 */
          {144295,  2700  },        /* Gain= 563.652344 Exposure Index= 468 */
          {148624,  2700  },        /* Gain= 580.562500 Exposure Index= 469 */
          {153083,  2700  },        /* Gain= 597.980469 Exposure Index= 470 */
          {157676,  2700  },        /* Gain= 615.921875 Exposure Index= 471 */
          {162407,  2700  },        /* Gain= 634.402344 Exposure Index= 472 */
          {167280,  2700  },        /* Gain= 653.437500 Exposure Index= 473 */
          {172299,  2700  },        /* Gain= 673.042969 Exposure Index= 474 */
          {177468,  2700  },        /* Gain= 693.234375 Exposure Index= 475 */
          {182793,  2700  },        /* Gain= 714.035156 Exposure Index= 476 */
          {188277,  2700  },        /* Gain= 735.457031 Exposure Index= 477 */
          {193926,  2700  },        /* Gain= 757.523438 Exposure Index= 478 */
          {199744,  2700  },        /* Gain= 780.250000 Exposure Index= 479 */
          {205737,  2700  },        /* Gain= 803.660156 Exposure Index= 480 */
          {211910,  2700  },        /* Gain= 827.773438 Exposure Index= 481 */
          {218268,  2700  },        /* Gain= 852.609375 Exposure Index= 482 */
          {224817,  2700  },        /* Gain= 878.191406 Exposure Index= 483 */
          {231562,  2700  },        /* Gain= 904.539063 Exposure Index= 484 */
          {238509,  2700  },        /* Gain= 931.675781 Exposure Index= 485 */
          {245665,  2700  },        /* Gain= 959.628906 Exposure Index= 486 */
          {253035,  2700  },        /* Gain= 988.417969 Exposure Index= 487 */
          {260627,  2700  },        /* Gain= 1018.074219 Exposure Index= 488 */
          {268446,  2700  },        /* Gain= 1048.617188 Exposure Index= 489 */
          {276500,  2700  },        /* Gain= 1080.078125 Exposure Index= 490 */
          {284795,  2700  },        /* Gain= 1112.480469 Exposure Index= 491 */
          {293339,  2700  },        /* Gain= 1145.855469 Exposure Index= 492 */
          {302140,  2700  },        /* Gain= 1180.234375 Exposure Index= 493 */
          {311205,  2700  },        /* Gain= 1215.644531 Exposure Index= 494 */
          {320542,  2700  },        /* Gain= 1252.117188 Exposure Index= 495 */
          {330159,  2700  },        /* Gain= 1289.683594 Exposure Index= 496 */
          {340064,  2700  },        /* Gain= 1328.375000 Exposure Index= 497 */
          {350266,  2700  },        /* Gain= 1368.226563 Exposure Index= 498 */
          {360774,  2700  },        /* Gain= 1409.273438 Exposure Index= 499 */
          {371598,  2700  },        /* Gain= 1451.554688 Exposure Index= 500 */
          {382746,  2700  },        /* Gain= 1495.101563 Exposure Index= 501 */
        },
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            50,  /* outdoor_luma_target_compensated */
            50,  /* default_luma_target_compensated */
            31,/* low_light.luma_target */
            80,  /* outdoor_index */
            190,  /* indoor_index */
			340, /* lowlight_start_idx */
			//300, /* lowlight_end_idx */
			405, /* lowlight_end_idx */
		},
		5,  /* snow_scene_detect.extreme_luma_target_offset */
		5,  /* backlit_scene_detect.backlight_max_la_luma_target_offset */
		1,	/* aec_motion_iso_preview */
		512,/* R_WEIGHT */
		1024,/* G_WEIGHT */
		512,/* B_WEIGHT */
		11, /* WT_Q */
		{
			25, /* fast_conv.speed */
			2,  /* fast_conv.luma_tolerance */
			0,  /* fast_conv.frame_skip */
		},
		1, /* metering_type 0:SPOT_METERING,1:CENTER_WEIGHTED,2: ADVANCE_FRAME_AVERAGE*/
		0, /*full_sweep_en ,set to 1 to fullsweep exp table*/
		77.894, /* exposure_index_adj_step ,NEED 1 / log10(1.03) */
		0, /* 0: no antibanding; 1: 50Hz antibanding; 2: 60Hz antibanding */
		{
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		},
		/*
		{
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		}*/
        {
            0,       //int   hist_target_adjust_enable;    0: disable;  1: enable;
            1.2,     //float outdoor_max_target_adjust_ratio;   1.0-2.0
            0.8,     //float outdoor_min_target_adjust_ratio;    0.8-1.0
            1.2,     //float indoor_max_target_adjust_ratio;     1.0-2.0
            0.8,     //float indoor_min_target_adjust_ratio;      0.8-1.0
            1.2,     //float lowlight_max_target_adjust_ratio;   1.0-2.0
            0.8,     //float lowlight_min_target_adjust_ratio;    0.8-1.0
            0.5,     //float target_filter_factor;                      0-0.99
            0.6,    //float hist_sat_pct;                               0.1-0.2
            0.5,    //float hist_dark_pct;                             0.1-0.3
            200,      //float hist_sat_low_ref;
            230,     //float hist_sat_high_ref;
            3,       //float hist_dark_low_ref;
            10,      //float hist_dark_high_ref;

        },
        {
            0,  /* over_exp_enable */
            245,  /* high_luma_region_threshold */
            1.000000,  /* outdoor_over_exp_adjust_ratio */
            1.000000,  /* indoor_over_exp_adjust_ratio */
            0.900000,  /* lowlight_over_exp_adjust_ratio */
            15.000000,  /* outdoor_over_exp_adjust_offset */
            12.000000,  /* indoor_over_exp_adjust_offset */
            10.000000,  /* lowlight_over_exp_adjust_offset */
            260,  /* outdoor_over_exp_max_count */
            230,  /* indoor_over_exp_max_count */
            144,  /* lowlight_over_exp_max_count */
            120,  /* outdoor_over_exp_min_count */
            100,  /* indoor_over_exp_min_count */
            60,  /* lowlight_over_exp_min_count */
        },
        /*sensor hdr tuning pra */
        {
		 	 /*int enable;*/
			 0,
             /*int enable_hdr_luma_tartget;*/
			 1,
			 /*int short_exp_max_index;*/
			 //132,
			 121,
             /*float max_exp_ration;*/
			 64,
			 /*int enble_ration_table;*/
			 1,
			 /*int ration_talbe_size;*/
			 6,
			 /*int over_exp_per_high; x/10000*/
			 255,
                         /*int over_exp_per_low;*/
			 235,
			 /*int  shor adjust step exp index;*/
			 1,
			 /*ration iner enale*/
			 1,
			 /*ration_table_t ration_table[HDR_RATION_TALBE_SIZE];*/
		 	 {
		 	    /*sexp_index  ration0 ration1 ration2 ration3 luma_target drc gain max, ceva drc gain min  ceva_drc_gain_max1  luma convegence th */
		 	        {52,        4,      1,      1,	   1, 	     80,           4,                4,               4,               5 },
		 	        {76,        4,      1,      1,	   1, 	     78,           4,                4,               4,               5 },
		 	        {86,        4,      1,      1,	   1, 	     75,           4,                4,               4,               5 },
		 	        {96,        4,      1,      1,	   1, 	     73,           4,                4,               4,               5 },
		 	        {110,       6,      1,      1,	   1, 	     70,           6,                4,               4,               5 },
			        {121,       6,      1,      1,	   1,        55,          90,                4,               4,               4 },
		 	 },
			 /* int over_exp_bin_th;//max 127 min 0 */
             60,
                         /*int short_exp_skip_count;*/
			 0,
                         /*float current weight*/
			 0.5,
			 /*int use average hist */
			 0,
			 /*int   short_target_th;*/
			 4,
			 /*int enable_short_exp_luma_adjust*/
			 1,
			 /*int full sweep*/
			 0,
			  /*int  enable the drc gain adjust*/
			 1,
			 /*drc gain adjust factor*/
			 1.03,
             /*over exp bright luma enable*/
             1,
             {
                1,  /* enable */
                75821,  /* low th */
                758210,  /* high th*/
                5621,
				56210,
				50,
				1,
				400,
				340,
				400,
				340,
             },
		},
        /* night detect */
	    {
	     
	    },
	    /* motion detect */
	    {
	     
	    },
	    /*  face ae */
	    {
	     
	    },
	    /*  extreme color */
	    {
	     
	    },
	    /*  bright dark */
	    {
	         1,//bright_dark_enable
			 3,//bright_dark_count
			 1,//bright_enable
			 1,//dark_enable
			 1,//inter_enable
			 /* bright_dark_pra[MIDDLE_TRIGGER_COUNT] */
			 {
				 /* para 1 */
				 {
					 0,//lux index
					 15,//dark th low
					 30,//dark th high
					 220,//bright th low
					 240,//bright th high
					 4,//dark th low weight
					 2,//dark th high weight
					 0.5,//bright low weight
					 0.3,//bright hight weight
				 },
				 /* para 2 */
				 {
					 100,//lux index
					 15,//dark th low
					 30,//dark th high
					 210,//bright th low
					 230,//bright th high
					 4,//dark th low weight
					 2,//dark th high weight
					 0.4,//bright low weight
					 0.3,//bright hight weight
				 },
				 /* para 3 */
				 {
					 190,//lux index
					 15,//dark th low
					 30,//dark th high
					 210,//bright th low
					 230,//bright th high
					 1,//dark th low weight
					 1,//dark th high weight
					 1,//bright low weight
					 1,//bright hight weight
				 },
			 },
	    },
	},
},
/*awb_tuning_t awb_tuning*/
{
    /* awb version  */
	0x00000001,
	/* enable */
	1,
	/* interpolation_enable */
	0,
	/* num_point */
	8,
	/* count_ae */
	1,
	/* trigger_mode */
	1,
	/* aec_trigger */
    {
        {
            0,
            347,
        },
        {
            0,
            347,
        },
        {
            0,
            347,
        },
	},
    /* awb_point */
    {
        { 0.4247, 0.6894 },    /* d75 */
        { 0.4538, 0.6333 },    /* d65 */
        { 0.5350, 0.5582 },    /* d50 */
        { 0.5350, 0.5582 },    /* noon */
        { 0.5428, 0.3949 },    /* cw */
        { 0.6627, 0.4192 },    /* tl84 */
        { 0.7829, 0.3529 },    /* a */
        { 0.9362, 0.3090 },    /* h */
        {},    /* custom1 */
        {},    /* custom2 */
    },
	/* awb_gain_adj */
    {
    	 { 1.00, 1.00 },   /* d75 */
    	 { 1.00, 1.00 },   /* d65 */
    	 { 1.00, 1.00 },   /* d50 */
    	 { 1.00, 1.00 },   /* noon */
    	 { 1.00, 1.00 },   /* cw */		// use tl84 lsc
    	 { 1.00, 1.00 },   /* tl84 */
    	 { 1.00, 1.00 },   /* a */
    	 { 1.00, 1.00 },   /* h */
    	 { 1.00, 1.00 },   /* custom_daylight */
         { 1.00, 1.00 },   /* custom_a */
    },
      /* awb cct */
    {
        7442,  /* d75 */
        6575,  /* d65 */
        5045,  /* d50 */
        5045,  /* noon */
        4050,  /* cw */
        3960,  /* tl84 */
        2892,  /* a */
        2336,  /* h */
    	0,  /* custom1 */
    	0, /* custom_a */
    },
    /* distance */
    {

    },
    /* index name */
    {
    	0,     /* d75 */
    	1,     /* d65 */
    	2,     /* d50 */
    	3,     /* noon */
    	4,     /* cw */
    	5,     /* tl84 */
    	6,     /* a */
    	7,     /* h */
    	0,     /* custom_daylight */
    	0,     /* custom_a */
    },
    /* awb_light_weight_table */
    {
		/*awb_light_weight_table 1*/
  	    {
			0, 0, 2,10, 5, 0, 0, 0, 0, 0, 0,
		},
		/*awb_light_weight_table 2*/
  	    {
			100, 6, 8,10, 5, 0, 0, 0, 0, 0, 0,
		},
		/*awb_light_weight_table 3*/
  	    {
			125,10,10,10, 5, 1, 1, 1, 1, 10, 0,
		},
		/*awb_light_weight_table 4*/
  	    {
			150, 1, 6,  6, 1, 1, 1, 1, 1, 10, 0,
		},
    },
	/* light_weight_table2 */
	{	/*Exp Index: 0, Outdoor_Index, Inoutdoor_Midpoint, Indoor_index*/
        { 0, 2, 1, 0 },   /*   d75    */
        { 2, 4, 2, 1 },   /*   d65    */
        { 6, 5, 4, 2 },   /*   d50    */
        { 6, 5, 4, 2 },   /*   noon   */
        { 1, 1, 1, 1 },   /*   cw     */
        { 1, 1, 1, 3 },   /*   tl84   */
        { 0, 1, 1, 1 },   /*   a      */
        { 0, 0, 1, 1 },   /*   h      */
        { 0, 0, 1, 1 },   /*   custom1*/
        { 0, 0, 0, 0 },   /*   custom2*/
	},
    /* AWB_lowlight_LUT */
    /* lux_index, green_rg_offset_adj, green_bg_offset_adj, outlier_dist_adj */
    {
		/*entry 0: 1000 Lux */
  	    {
			282, 0.000, 0.000, 0.000,
		},
		/*entry 1: 400 Lux*/
  	    {
			298, 0.000, 0.000, 0.000,
		},
		/*entry 2: 200 Lux */
  	    {
			317, 0.000, 0.000, 0.000,
		},
		/*entry 3: 100 Lux */
  	    {
			342, 0.000, 0.000, 0.000,
		},
		/*entry 4: 50 Lux */
  	    {
			369, 0.000, 0.000, 0.000,
		},
		/*entry 5: 20 Lux */
  	    {
			402, 0.000, 0.000, 0.000,
		},
    },
    /* awb_tuning_para */
    {
    	80,     /* outdoor_midpoint */
    	150,    /* outdoor_index */
    	175,    /* inoutdoor_midpoint */
    	195,    /* indoor_index */
    	10,     /* exposure_adjustment */
        0.75,   /* awb_tuning_params */
		0.50,	/* d50_d65_weighted_samaple_boundary */
		0.20,	/* blue_sky_pec */
		0.15,	/* blue_sky_pec_buffer */
        8,     /* num_of_reference_point */
        0.0064, /* outline */
        1023, /* white_stat_y_thd_low */
        1023, /* white_stat_y_thd_high */
        2,      /* dominant_cluster_threshold */
        100,      /* white_stat_cnt_thd */
        1,   /* grey_weight_day */
        0,   /* white_weight_day */
        1,   /* grey_weight_f */
        0,   /* white_weight_f */
        1,   /* grey_weight_h */
        0,   /* white_weight_h */
        1,      /* all_outlier_heuristic_flag */
        0,      /* special_bayer_en */
        0.20,   /* green_threshold */
		0.20,	/* threshold_extreme_b_percent */
        0.0064, /* compact_to_grey_dis */
    	0.45,   /* cluster_high_pec */
    	0.25,   /* cluster_mid_pec */
    	0.15,   /* cluster_low_pec */
        10,     /* BitsSum */
        3,      /* FrameNum */
        0,//enable stats filter
        1,//stats filter count
        {
            {
               500,//lux index
               0.05,//current weight
            },
        },
        0,//enable gain filter
        1,//gain filter count
        {
             {
               500,//lux index
               0.05,
             },
        },
        1, //enable the awb limit
        5, //rg limit max
        0.2, //rg limit min
        5, //bg limit max
        0.2, //bg limit min
        2, //d50
        1, //when after this frames. the stats filter will have func
        1, //when after this frames the gain filter will have func		
    },

    /* awb_statistics awbs[MIN_TRIGGER_COUNT] */
    {
    	{
           0x00000005, /* coef_y_r */
           0x00000009, /* coef_y_g */
           0x00000002, /* coef_y_b */
           0x00000005, /* coef_cb_r */
           0x0000000b, /* coef_cb_g */
           0x00000010, /* coef_cb_b */
           0x00000010, /* coef_cr_r */
           0x0000000d, /* coef_cr_g */
           0x00000003, /* coef_cr_b */
           0x00000004, /* coef_rsh */
           0x00000000, /* rrBL */
           0x00000000, /* grBL */
           0x00000000, /* gbBL */
           0x00000000, /* bbBL */
           0x00000100, /* rrGain */
           0x00000100, /* grGain */
           0x00000100, /* gbGain */
           0x00000100, /* bbGain */
           0x000003e8, /* Ymax */
           0x00000000, /* Ymin */
           0x00000100, /* Gray_m1 */
           0x00010100, /* Gray_m2 */
           0x00000100, /* Gray_m3 */
           0x00010100, /* Gray_m4 */
           0x00000320, /* Gray_c1 */
           0x000102bc, /* Gray_c2 */
           0x00010320, /* Gray_c3 */
           0x000002bc, /* Gray_c4 */
           0x00000098, /* Green_BGmax */
           0x0000003b, /* Green_BGmin */
           0x00000088, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000132, /* Green_Rmul */
           0x0000014b, /* Green_Bmul */
           0x000000ae, /* ExtremeB_BG_TH */
           0x00001480, /* ExtremeB_RG_TH */
           0x00000100, /* ExtremeR_RG_TH */
           0x00001980, /* ExtremeR_BG_TH */
		   2, //zoom
    	},
    	{
    	},
    	{
    	},
    },
},
/*af_tuning_t  af_tuning*/
{

},
