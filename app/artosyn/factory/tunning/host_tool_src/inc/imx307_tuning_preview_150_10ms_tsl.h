
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
	    /* isp_sub_module_ccm1_pra pra[5][7] */
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
                        {60,180,171},
                        //g channel
                        {60,180,171},
                        //b channel
                        {60,180,171},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {35,105,70},
                        //g channel
                        {35,105,70},
                        //b channel
                        {35,105,70},
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
        6,//awb count
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
     			2000,
     			2500,
     		},
     		/*awb trigger 2*/
     		{
     			2700,
     			2800,
     		},
     		/*awb trigger 3*/
     		{
     			3900,
     			4200,
     		},
     		/*awb trigger 4*/
     		{
     			4900,
     			5100,
     		},
     		/*awb trigger 5*/
     		{
     			6400,
     			6600,
     		},
     		/*awb trigger 6*/
     		{
     			7500,
     			8000,
     		},
        },
        /* isp_sub_module_lsc_pra */
        {
			{
				/* para 1 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  4.9043, 1.5220, 1.5664, 1.1528, 1.0659, 1.0620, 1.1387, 1.3369, 1.5225, 2.9736, 
					  2.4712, 1.4775, 1.2368, 1.0659, 1.0825, 1.0522, 1.0542, 1.1211, 1.3809, 1.9355, 
					  2.0254, 1.3525, 1.0869, 1.0361, 1.0474, 1.0186, 1.0444, 0.9712, 1.3525, 1.2129, 
					  1.8257, 1.3228, 1.0737, 1.0552, 1.0317, 1.0361, 1.0493, 1.1147, 1.1504, 2.0796, 
					  1.8389, 1.2290, 1.0591, 1.0283, 1.0127, 0.9854, 1.0444, 0.9673, 1.1563, 1.1895, 
					  1.8301, 1.2202, 1.0825, 1.0234, 1.0254, 1.0327, 1.0459, 1.0728, 1.0698, 1.6670, 
					  1.8774, 1.2622, 1.0737, 1.0435, 1.0181, 1.0156, 1.0410, 1.0220, 1.1929, 1.4995, 
					  1.7710, 1.3145, 1.0288, 1.0225, 1.0005, 1.0015, 1.0215, 1.0493, 1.1875, 1.6494, 
					  2.3472, 1.3623, 1.2246, 1.0513, 1.0381, 1.0728, 0.9878, 1.1245, 1.2700, 1.9019, 
					  2.9727, 1.5591, 1.2100, 1.0850, 0.9951, 1.0371, 1.0166, 1.2300, 1.3711, 2.4531, 
					  4.5176, 1.4365, 1.4609, 1.0854, 1.0439, 1.0371, 1.0840, 1.2949, 1.4238, 2.8940, 
					  2.3374, 1.3862, 1.1587, 1.0249, 1.0347, 1.0195, 1.0166, 1.0913, 1.3042, 1.8857, 
					  1.9194, 1.2739, 1.0405, 0.9985, 1.0396, 1.0103, 1.0132, 0.9473, 1.2705, 1.1475, 
					  1.7441, 1.2432, 1.0317, 1.0332, 1.0239, 1.0283, 1.0269, 1.0835, 1.0928, 1.9849, 
					  1.6885, 1.1680, 1.0127, 1.0161, 1.0117, 0.9888, 1.0410, 0.9482, 1.0898, 1.1108, 
					  1.7280, 1.1597, 1.0361, 1.0117, 1.0229, 1.0278, 1.0454, 1.0303, 1.0342, 1.5493, 
					  1.7231, 1.1938, 1.0225, 1.0332, 1.0112, 1.0200, 1.0313, 1.0034, 1.1265, 1.4399, 
					  1.6797, 1.2295, 0.9980, 0.9951, 0.9937, 0.9980, 1.0010, 1.0034, 1.1353, 1.5420, 
					  2.2178, 1.2949, 1.1626, 1.0264, 1.0083, 1.0605, 0.9609, 1.1011, 1.2031, 1.8579, 
					  2.8350, 1.4336, 1.1499, 1.0430, 0.9624, 1.0093, 0.9893, 1.1494, 1.3130, 2.3228, 
					  3.8008, 1.4917, 1.3730, 1.1118, 1.0225, 1.0635, 1.0928, 1.2671, 1.4409, 2.8027, 
					  2.2256, 1.3647, 1.1440, 1.0298, 1.0283, 1.0400, 1.0259, 1.1172, 1.2993, 1.8838, 
					  1.8760, 1.2539, 1.0410, 0.9883, 1.0410, 1.0020, 1.0283, 0.9468, 1.2803, 1.1274, 
					  1.7271, 1.2212, 1.0420, 1.0449, 1.0107, 1.0420, 1.0210, 1.0859, 1.0981, 1.9194, 
					  1.6460, 1.1641, 1.0088, 1.0029, 1.0386, 0.9614, 1.0815, 0.9443, 1.1143, 1.1001, 
					  1.6523, 1.1519, 1.0420, 1.0132, 1.0044, 1.0308, 1.0425, 1.0303, 1.0532, 1.5181, 
					  1.6982, 1.2041, 1.0244, 1.0352, 1.0181, 1.0352, 1.0508, 1.0122, 1.1567, 1.3828, 
					  1.5645, 1.2432, 0.9873, 1.0020, 0.9858, 1.0083, 0.9937, 1.0078, 1.1416, 1.5151, 
					  2.1909, 1.2632, 1.1895, 1.0195, 1.0249, 1.0679, 0.9873, 1.1089, 1.2261, 1.8037, 
					  2.6221, 1.4756, 1.1372, 1.0732, 1.0073, 1.0430, 1.0103, 1.1729, 1.3037, 2.2368, 
					},
				},
				/* para 2 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  5.0215, 1.6143, 1.6387, 1.2090, 1.1309, 1.1226, 1.1870, 1.4189, 1.6025, 3.0981, 
					  2.4839, 1.4609, 1.2334, 1.0596, 1.0791, 1.0542, 1.0542, 1.1318, 1.3774, 2.0503, 
					  2.0039, 1.3350, 1.0742, 1.0210, 1.0444, 1.0068, 1.0391, 0.9517, 1.3457, 1.1167, 
					  1.9014, 1.3721, 1.1162, 1.1025, 1.0791, 1.0845, 1.1006, 1.1772, 1.1968, 2.2656, 
					  1.7725, 1.1924, 1.0254, 0.9980, 0.9888, 0.9624, 1.0156, 0.9287, 1.1270, 1.0688, 
					  1.8896, 1.2495, 1.1084, 1.0596, 1.0547, 1.0620, 1.0884, 1.1050, 1.1040, 1.7100, 
					  1.8638, 1.2700, 1.0693, 1.0464, 1.0386, 1.0181, 1.0591, 1.0234, 1.2056, 1.4917, 
					  1.7358, 1.2910, 1.0049, 1.0098, 0.9751, 0.9980, 1.0029, 1.0332, 1.1685, 1.6099, 
					  2.4458, 1.4106, 1.2764, 1.0786, 1.0879, 1.0991, 1.0347, 1.1665, 1.3262, 1.9790, 
					  2.8506, 1.5068, 1.1563, 1.0513, 0.9536, 1.0107, 0.9873, 1.1826, 1.3442, 2.3691, 
					  4.6333, 1.5347, 1.5166, 1.1460, 1.0898, 1.0874, 1.1499, 1.3516, 1.5142, 3.0469, 
					  2.3218, 1.3730, 1.1523, 1.0225, 1.0317, 1.0142, 1.0176, 1.0938, 1.2949, 1.9609, 
					  1.9351, 1.2446, 1.0293, 0.9790, 1.0171, 0.9951, 0.9917, 0.9243, 1.2583, 1.0894, 
					  1.8350, 1.2847, 1.0825, 1.0786, 1.0786, 1.0747, 1.0894, 1.1455, 1.1377, 2.1572, 
					  1.6489, 1.1152, 0.9854, 0.9834, 0.9702, 0.9702, 0.9966, 0.9087, 1.0659, 1.0161, 
					  1.7856, 1.1904, 1.0718, 1.0493, 1.0620, 1.0630, 1.0938, 1.0640, 1.0693, 1.6016, 
					  1.7515, 1.1938, 1.0293, 1.0366, 1.0210, 1.0273, 1.0444, 1.0063, 1.1406, 1.4453, 
					  1.6040, 1.2178, 0.9575, 0.9839, 0.9766, 0.9819, 0.9878, 0.9834, 1.1104, 1.5210, 
					  2.3271, 1.3306, 1.2183, 1.0688, 1.0454, 1.1113, 1.0083, 1.1436, 1.2656, 1.9131, 
					  2.7207, 1.4053, 1.0957, 1.0078, 0.9419, 0.9731, 0.9463, 1.1270, 1.2529, 2.2861, 
					  4.2646, 1.5786, 1.5151, 1.1636, 1.0962, 1.1455, 1.1577, 1.3716, 1.5322, 3.0029, 
					  2.2681, 1.3667, 1.1152, 1.0298, 1.0195, 1.0166, 1.0249, 1.1177, 1.2866, 1.9512, 
					  1.9170, 1.2354, 1.0503, 0.9849, 1.0225, 1.0103, 0.9990, 0.9360, 1.2607, 1.0884, 
					  1.8804, 1.2856, 1.0928, 1.0923, 1.0771, 1.0864, 1.0928, 1.1636, 1.1465, 2.1226, 
					  1.5718, 1.1157, 0.9780, 0.9761, 0.9810, 0.9585, 1.0029, 0.9063, 1.0654, 1.0161, 
					  1.7720, 1.1973, 1.0879, 1.0547, 1.0786, 1.0552, 1.1226, 1.0762, 1.0908, 1.5952, 
					  1.6953, 1.2085, 1.0415, 1.0454, 1.0435, 1.0337, 1.0542, 1.0176, 1.1362, 1.4580, 
					  1.5630, 1.2148, 0.9629, 0.9800, 0.9839, 0.9878, 0.9883, 0.9824, 1.1147, 1.5093, 
					  2.2676, 1.3320, 1.2461, 1.0786, 1.0645, 1.1167, 1.0269, 1.1567, 1.2793, 1.9155, 
					  2.6558, 1.4004, 1.1221, 1.0273, 0.9531, 0.9888, 0.9697, 1.0928, 1.2744, 2.1953, 
					},
				},
				/* para 3 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  4.3750, 1.4307, 1.4204, 1.0640, 1.0225, 0.9961, 1.0786, 1.1504, 1.4639, 2.7261, 
					  2.3975, 1.3613, 1.1963, 1.0200, 1.0449, 1.0313, 1.0117, 1.1094, 1.2710, 2.0303, 
					  1.9741, 1.3037, 1.0688, 1.0298, 1.0562, 1.0234, 1.0313, 0.9585, 1.2798, 1.1626, 
					  1.6929, 1.2070, 1.0317, 1.0107, 0.9946, 1.0146, 1.0039, 1.0752, 1.0708, 1.9331, 
					  1.6582, 1.1992, 1.0249, 1.0332, 1.0161, 1.0059, 1.0425, 0.9434, 1.1226, 1.1587, 
					  1.5898, 1.1680, 1.0142, 1.0073, 1.0049, 1.0190, 1.0259, 1.0234, 1.0225, 1.5396, 
					  1.7378, 1.1890, 1.0176, 1.0112, 1.0166, 1.0010, 1.0273, 0.9839, 1.1128, 1.4561, 
					  1.6953, 1.2705, 0.9834, 1.0254, 0.9868, 1.0132, 1.0044, 1.0166, 1.1230, 1.5996, 
					  2.1934, 1.2549, 1.1221, 0.9727, 0.9980, 1.0146, 0.9463, 1.0029, 1.1753, 1.7246, 
					  2.9072, 1.4907, 1.1494, 1.0576, 0.9590, 0.9961, 0.9692, 1.1455, 1.2739, 2.2773, 
					  4.0894, 1.4185, 1.3608, 1.0488, 1.0107, 0.9912, 1.0542, 1.1416, 1.4312, 2.6348, 
					  2.3027, 1.3276, 1.1396, 1.0098, 1.0103, 1.0146, 0.9917, 1.0996, 1.2334, 1.9917, 
					  1.9556, 1.2422, 1.0669, 0.9995, 1.0405, 1.0210, 1.0029, 0.9502, 1.2407, 1.1348, 
					  1.6738, 1.1772, 1.0112, 1.0024, 1.0000, 1.0083, 1.0010, 1.0625, 1.0459, 1.8911, 
					  1.5967, 1.1577, 1.0024, 1.0186, 1.0127, 1.0039, 1.0332, 0.9341, 1.0898, 1.1157, 
					  1.5791, 1.1440, 1.0127, 0.9990, 1.0127, 1.0176, 1.0337, 1.0112, 1.0122, 1.5098, 
					  1.6665, 1.1606, 0.9985, 1.0034, 1.0063, 0.9966, 1.0176, 0.9736, 1.0869, 1.4199, 
					  1.6196, 1.2402, 0.9751, 1.0068, 0.9961, 1.0059, 1.0020, 1.0005, 1.1089, 1.5571, 
					  2.1279, 1.2285, 1.1240, 0.9771, 0.9741, 1.0225, 0.9258, 1.0142, 1.1621, 1.7065, 
					  2.8096, 1.4165, 1.1387, 1.0420, 0.9775, 1.0005, 0.9658, 1.1191, 1.2700, 2.2168, 
					  3.6123, 1.4717, 1.3257, 1.0811, 1.0005, 1.0273, 1.0591, 1.1626, 1.4209, 2.5835, 
					  2.2139, 1.3447, 1.1191, 1.0107, 1.0176, 1.0083, 1.0044, 1.1035, 1.2607, 1.9521, 
					  2.0054, 1.2432, 1.0864, 1.0142, 1.0254, 1.0234, 1.0068, 0.9644, 1.2505, 1.1260, 
					  1.6724, 1.1807, 1.0127, 1.0000, 0.9976, 1.0068, 0.9941, 1.0654, 1.0576, 1.8975, 
					  1.5991, 1.1831, 1.0127, 1.0332, 1.0166, 1.0059, 1.0366, 0.9414, 1.1069, 1.0952, 
					  1.5801, 1.1450, 1.0234, 0.9834, 1.0205, 1.0137, 1.0396, 1.0059, 1.0283, 1.4995, 
					  1.6753, 1.1846, 1.0088, 1.0127, 1.0151, 1.0068, 1.0249, 0.9990, 1.1035, 1.4414, 
					  1.5864, 1.2578, 0.9902, 1.0171, 0.9980, 1.0137, 1.0083, 0.9951, 1.1274, 1.5469, 
					  2.0688, 1.2334, 1.1411, 0.9766, 0.9883, 1.0308, 0.9341, 1.0449, 1.1768, 1.7046, 
					  2.7334, 1.4448, 1.1460, 1.0737, 0.9819, 1.0308, 1.0122, 1.1143, 1.3145, 2.2065, 
					},
				},
				/* para 4 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  4.5415, 1.3564, 1.4512, 1.0317, 0.9829, 0.9961, 1.0503, 1.3013, 1.3545, 3.1987, 
					  2.5313, 1.4468, 1.2583, 1.0767, 1.0742, 1.0571, 1.0537, 1.1152, 1.4072, 1.8892, 
					  2.0425, 1.3188, 1.1187, 1.0308, 1.0581, 1.0352, 1.0552, 0.9800, 1.3530, 1.4155, 
					  1.7041, 1.2056, 1.0122, 0.9883, 0.9673, 0.9795, 0.9805, 1.0645, 1.0605, 1.9556, 
					  1.7324, 1.2764, 1.0796, 1.0718, 1.0542, 1.0464, 1.0850, 0.9971, 1.2051, 1.2642, 
					  1.4985, 1.1611, 0.9785, 0.9717, 0.9634, 0.9746, 0.9839, 0.9941, 0.9927, 1.5068, 
					  1.7822, 1.2368, 1.0552, 1.0313, 1.0337, 1.0249, 1.0527, 1.0410, 1.1577, 1.5615, 
					  1.7495, 1.2988, 1.0322, 1.0313, 0.9976, 1.0186, 1.0161, 1.0327, 1.1812, 1.6357, 
					  2.1782, 1.2349, 1.1235, 0.9663, 0.9585, 0.9863, 0.9111, 1.0029, 1.1758, 1.6563, 
					  3.0073, 1.6045, 1.2456, 1.1392, 1.0264, 1.1069, 1.0337, 1.2598, 1.3364, 2.3481, 
					  4.0977, 1.2954, 1.3364, 0.9907, 0.9390, 0.9565, 0.9849, 1.1899, 1.2739, 2.9692, 
					  2.3267, 1.3774, 1.1709, 1.0396, 1.0342, 1.0381, 1.0225, 1.0894, 1.3311, 1.8208, 
					  1.9678, 1.2427, 1.0786, 0.9995, 1.0410, 1.0200, 1.0156, 0.9468, 1.2813, 1.3193, 
					  1.6055, 1.1416, 0.9663, 0.9648, 0.9575, 0.9614, 0.9678, 1.0146, 1.0156, 1.8477, 
					  1.6538, 1.2168, 1.0474, 1.0669, 1.0493, 1.0518, 1.0747, 0.9868, 1.1494, 1.1729, 
					  1.3945, 1.1001, 0.9458, 0.9492, 0.9668, 0.9688, 0.9878, 0.9556, 0.9727, 1.4136, 
					  1.6411, 1.1904, 1.0049, 1.0273, 1.0161, 1.0229, 1.0386, 1.0161, 1.1143, 1.4819, 
					  1.6118, 1.2393, 0.9868, 1.0059, 0.9883, 1.0132, 1.0039, 1.0010, 1.1353, 1.5591, 
					  2.0151, 1.1709, 1.0664, 0.9419, 0.9248, 0.9746, 0.8838, 0.9727, 1.1157, 1.5962, 
					  2.8906, 1.4839, 1.1997, 1.0928, 1.0117, 1.0728, 1.0161, 1.1904, 1.3037, 2.2925, 
					  3.5347, 1.3267, 1.2568, 1.0000, 0.9336, 0.9639, 0.9897, 1.1816, 1.2827, 2.8892, 
					  2.2510, 1.4121, 1.1558, 1.0596, 1.0381, 1.0493, 1.0410, 1.1040, 1.3335, 1.8667, 
					  2.0122, 1.2305, 1.0938, 0.9995, 1.0415, 1.0161, 1.0171, 0.9653, 1.2778, 1.2954, 
					  1.5601, 1.1460, 0.9556, 0.9746, 0.9414, 0.9609, 0.9556, 1.0142, 1.0161, 1.8267, 
					  1.6729, 1.2388, 1.0664, 1.0669, 1.0723, 1.0527, 1.0928, 0.9849, 1.1812, 1.1431, 
					  1.4380, 1.0732, 0.9580, 0.9385, 0.9541, 0.9590, 0.9878, 0.9468, 0.9800, 1.4077, 
					  1.6162, 1.2173, 1.0161, 1.0313, 1.0298, 1.0376, 1.0444, 1.0264, 1.1318, 1.4526, 
					  1.6094, 1.2334, 1.0024, 1.0024, 1.0068, 1.0112, 1.0103, 1.0137, 1.1313, 1.5791, 
					  1.9521, 1.1665, 1.0762, 0.9316, 0.9287, 0.9766, 0.8813, 0.9761, 1.1206, 1.5513, 
					  2.8867, 1.4932, 1.2217, 1.1182, 1.0405, 1.0967, 1.0493, 1.2168, 1.3262, 2.3149, 
					},
				},
				/* para 5 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  4.1045, 1.4541, 1.4150, 1.0664, 1.0146, 1.0054, 1.0664, 1.2026, 1.4287, 2.9727, 
					  2.3525, 1.3613, 1.1777, 1.0171, 1.0093, 1.0068, 0.9932, 1.0547, 1.3198, 1.7388, 
					  2.0278, 1.3521, 1.1230, 1.0503, 1.0718, 1.0513, 1.0493, 0.9800, 1.3589, 1.3613, 
					  1.6587, 1.1895, 0.9854, 0.9775, 0.9482, 0.9648, 0.9731, 1.0381, 1.0532, 1.9009, 
					  1.6509, 1.2446, 1.0386, 1.0342, 1.0151, 1.0142, 1.0488, 0.9619, 1.1475, 1.2349, 
					  1.5283, 1.1792, 1.0142, 0.9819, 0.9946, 0.9995, 1.0283, 1.0117, 1.0547, 1.5366, 
					  1.7144, 1.1821, 1.0039, 0.9912, 0.9702, 0.9707, 0.9902, 0.9678, 1.0952, 1.4551, 
					  1.7686, 1.3120, 1.0347, 1.0366, 1.0244, 1.0273, 1.0283, 1.0518, 1.1865, 1.6650, 
					  2.1416, 1.2422, 1.1201, 0.9663, 0.9463, 0.9951, 0.8955, 0.9863, 1.1499, 1.6294, 
					  2.9346, 1.4668, 1.1973, 1.0718, 0.9819, 1.0273, 0.9902, 1.2061, 1.2759, 2.3027, 
					  3.6396, 1.3496, 1.2881, 1.0000, 0.9551, 0.9517, 1.0122, 1.1553, 1.3052, 2.8740, 
					  2.2129, 1.2749, 1.1123, 0.9722, 0.9766, 0.9736, 0.9575, 1.0239, 1.2446, 1.6631, 
					  1.9526, 1.2559, 1.0840, 1.0146, 1.0459, 1.0288, 1.0234, 0.9634, 1.2788, 1.3267, 
					  1.5522, 1.1187, 0.9438, 0.9473, 0.9419, 0.9487, 0.9429, 1.0024, 0.9932, 1.7871, 
					  1.5913, 1.1748, 1.0029, 1.0273, 1.0059, 1.0059, 1.0366, 0.9390, 1.0942, 1.1387, 
					  1.4526, 1.1343, 0.9751, 0.9790, 0.9951, 0.9932, 1.0156, 0.9844, 1.0098, 1.4551, 
					  1.5981, 1.1191, 0.9570, 0.9683, 0.9585, 0.9541, 0.9746, 0.9429, 1.0425, 1.3794, 
					  1.6343, 1.2612, 1.0024, 1.0229, 1.0176, 1.0234, 1.0151, 1.0146, 1.1445, 1.5723, 
					  2.0356, 1.1714, 1.0698, 0.9399, 0.9224, 0.9746, 0.8711, 0.9692, 1.0967, 1.5864, 
					  2.7168, 1.3970, 1.1504, 1.0347, 0.9834, 1.0015, 0.9692, 1.1353, 1.2266, 2.2153, 
					  3.2192, 1.3765, 1.2510, 0.9971, 0.9546, 0.9683, 0.9941, 1.1416, 1.3047, 2.7163, 
					  2.0996, 1.2871, 1.0859, 0.9653, 0.9692, 0.9668, 0.9590, 1.0327, 1.2412, 1.7207, 
					  2.0010, 1.2573, 1.1011, 1.0234, 1.0449, 1.0396, 1.0210, 0.9849, 1.2705, 1.2813, 
					  1.5454, 1.1104, 0.9399, 0.9443, 0.9277, 0.9360, 0.9292, 0.9912, 0.9951, 1.7471, 
					  1.5850, 1.1807, 1.0156, 1.0210, 1.0127, 1.0093, 1.0327, 0.9482, 1.1050, 1.1240, 
					  1.4712, 1.1284, 0.9824, 0.9722, 0.9912, 0.9873, 1.0190, 0.9834, 1.0127, 1.4497, 
					  1.5596, 1.1260, 0.9629, 0.9634, 0.9609, 0.9639, 0.9746, 0.9497, 1.0581, 1.3511, 
					  1.6118, 1.2686, 1.0103, 1.0215, 1.0171, 1.0254, 1.0239, 1.0156, 1.1558, 1.5850, 
					  1.9316, 1.1597, 1.0703, 0.9395, 0.9180, 0.9800, 0.8838, 0.9824, 1.1123, 1.5913, 
					  2.6816, 1.4038, 1.1563, 1.0366, 0.9961, 1.0073, 0.9756, 1.1240, 1.2520, 2.2026, 
					},
				},
				/* para 6 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  4.4287, 1.4043, 1.4341, 1.0625, 0.9990, 1.0205, 1.0679, 1.2734, 1.3945, 3.1519, 
					  2.3228, 1.3477, 1.1709, 0.9971, 1.0098, 0.9888, 0.9873, 1.0366, 1.3140, 1.7251, 
					  2.0742, 1.3223, 1.1187, 1.0405, 1.0576, 1.0459, 1.0576, 0.9756, 1.3608, 1.4116, 
					  1.6499, 1.1724, 0.9854, 0.9619, 0.9502, 0.9585, 0.9614, 1.0332, 1.0381, 1.8989, 
					  1.6255, 1.2178, 1.0161, 1.0161, 1.0127, 0.9883, 1.0444, 0.9536, 1.1445, 1.1763, 
					  1.5674, 1.1763, 1.0024, 1.0005, 0.9849, 1.0151, 1.0068, 1.0151, 1.0313, 1.5303, 
					  1.6553, 1.1636, 0.9741, 0.9673, 0.9731, 0.9507, 0.9956, 0.9712, 1.0850, 1.4316, 
					  1.7749, 1.3022, 1.0400, 1.0356, 1.0103, 1.0264, 1.0361, 1.0239, 1.2056, 1.6299, 
					  2.1367, 1.2256, 1.1030, 0.9512, 0.9526, 0.9727, 0.9038, 0.9902, 1.1563, 1.6250, 
					  2.8242, 1.4722, 1.1724, 1.0596, 0.9517, 1.0244, 0.9717, 1.1299, 1.2803, 2.1636, 
					  4.0625, 1.3672, 1.3271, 1.0376, 0.9619, 0.9985, 1.0073, 1.2144, 1.3096, 2.9756, 
					  2.1772, 1.2861, 1.1113, 0.9697, 0.9736, 0.9673, 0.9629, 1.0117, 1.2607, 1.6929, 
					  1.9824, 1.2739, 1.0815, 1.0220, 1.0542, 1.0391, 1.0342, 0.9688, 1.2900, 1.3545, 
					  1.5571, 1.1191, 0.9595, 0.9429, 0.9448, 0.9473, 0.9458, 1.0010, 1.0034, 1.8066, 
					  1.5757, 1.1709, 0.9980, 1.0234, 1.0020, 1.0063, 1.0347, 0.9424, 1.0952, 1.1284, 
					  1.4521, 1.1406, 0.9814, 0.9868, 1.0044, 1.0059, 1.0146, 0.9893, 1.0073, 1.4497, 
					  1.5586, 1.1147, 0.9473, 0.9644, 0.9487, 0.9629, 0.9761, 0.9536, 1.0425, 1.3916, 
					  1.6597, 1.2534, 1.0059, 1.0186, 1.0210, 1.0229, 1.0244, 1.0142, 1.1528, 1.5908, 
					  2.0415, 1.1621, 1.0786, 0.9390, 0.9219, 0.9829, 0.8745, 0.9780, 1.1152, 1.5840, 
					  2.7002, 1.3994, 1.1064, 1.0161, 0.9478, 0.9902, 0.9600, 1.1030, 1.2168, 2.1377, 
					  3.5420, 1.3892, 1.2900, 1.0205, 0.9600, 0.9790, 1.0112, 1.1841, 1.3096, 2.8418, 
					  2.0625, 1.2910, 1.0732, 0.9712, 0.9644, 0.9590, 0.9766, 1.0200, 1.2603, 1.7207, 
					  2.0229, 1.2695, 1.1055, 1.0249, 1.0532, 1.0474, 1.0264, 0.9844, 1.2876, 1.3047, 
					  1.5679, 1.1113, 0.9521, 0.9468, 0.9297, 0.9365, 0.9380, 0.9883, 1.0034, 1.7681, 
					  1.5571, 1.1758, 1.0068, 1.0122, 1.0195, 1.0034, 1.0391, 0.9375, 1.1143, 1.0942, 
					  1.5078, 1.1387, 0.9946, 0.9854, 0.9966, 1.0024, 1.0195, 0.9922, 1.0190, 1.4448, 
					  1.5210, 1.1211, 0.9453, 0.9517, 0.9614, 0.9541, 0.9746, 0.9463, 1.0483, 1.3643, 
					  1.6440, 1.2642, 1.0210, 1.0313, 1.0200, 1.0356, 1.0259, 1.0303, 1.1611, 1.5908, 
					  1.9434, 1.1602, 1.0674, 0.9224, 0.9243, 0.9731, 0.8799, 0.9868, 1.1191, 1.5977, 
					  2.6885, 1.3740, 1.1343, 1.0269, 0.9712, 1.0034, 0.9761, 1.1040, 1.2402, 2.1323, 
					},
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
        		2700,
        		2800,
        	},
        	/*trigger 1*/
        	{
        		4000,
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
                     1.6739, -0.8203, 0.1464,
                     -0.5249, 1.5335, -0.0086,
                     -0.1195, -1.0457, 2.1652,
                },
                /* ccm tl84 matrix */
                {
                     1.8439, -1.0506, 0.2067,
                     -0.3904, 1.5797, -0.1893,
                     0.1631, -1.0512, 1.8881,
                },
                /* ccm d50 matrix */
                {
                     1.8584, -0.9873, 0.1289,
                     -0.3914, 1.5681, -0.1767,
                     0.1072, -1.0912, 1.9840,
                },
                /* ccm d65 matrix */
                {
                     1.8243, -0.9433, 0.1190,
                     -0.2960, 1.5353, -0.2393,
                     0.1556, -1.0203, 1.8647,
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
                /* ccm a matrix */
                {
                     1.6394, -0.5786, -0.0607,
                     -0.4468, 1.5291, -0.0822,
                     -0.0691, -0.6545, 1.7236,
                },
                /* ccm tl84 matrix */
                {
                     1.5663, -0.5921, 0.0258,
                     -0.3891, 1.5521, -0.1630,
                     0.0830, -0.9642, 1.8813,
                },
                /* ccm d50 matrix */
                {
                     1.7128, -0.6282, -0.0846,
                     -0.3074, 1.5268, -0.2194,
                     0.1408, -1.1336, 1.9928,
                },
                /* ccm d65 matrix */
                {
                     1.7753, -0.7842, 0.0089,
                     -0.2658, 1.5580, -0.2922,
                     0.0835, -0.9789, 1.8954,
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
            110.000,
          },
          /*aec trigger 2*/
          {
            160,
            340,
          },
          /*aec trigger 3*/
          {
            370,
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
                  0,  59, 120, 179, 234, 283, 327, 372, 415, 456, 492, 527, 562, 596, 629, 658, 688, 717, 747, 774, 799, 824, 848, 869, 894, 914, 937,
                958, 979,1000,1020,1041,1060,1080,1096,1115,1134,1151,1169,1188,1206,1225,1243,1257,1275,1292,1309,1324,1343,1358,1375,1393,1408,1423,
               1442,1457,1471,1485,1503,1517,1531,1546,1560,1576,1589,1604,1619,1633,1646,1662,1675,1688,1701,1717,1729,1742,1757,1769,1781,1793,1808,
               1819,1831,1844,1856,1867,1881,1892,1904,1916,1929,1944,1955,1967,1979,1993,2004,2015,2027,2039,2049,2062,2073,2085,2096,2106,2116,2128,
               2139,2148,2158,2169,2177,2189,2198,2208,2222,2232,2243,2248,2260,2271,2283,2289,2302,2315,2321,2333,2340,2352,2364,2370,2382,2388,2400,
               2412,2418,2429,2435,2447,2458,2464,2475,2481,2492,2503,2508,2519,2524,2535,2545,2551,2561,2566,2576,2586,2591,2601,2606,2616,2626,2631,
               2640,2645,2654,2663,2668,2677,2685,2693,2697,2705,2712,2723,2729,2736,2745,2750,2758,2765,2772,2780,2788,2795,2802,2810,2818,2826,2831,
               2835,2843,2851,2859,2863,2867,2875,2879,2883,2891,2899,2907,2911,2915,2923,2927,2931,2939,2947,2955,2959,2963,2971,2975,2979,2987,2991,
               2995,3003,3007,3011,3019,3023,3027,3035,3039,3043,3051,3055,3059,3067,3071,3075,3083,3088,3092,3096,3100,3104,3108,3116,3120,3124,3132,
               3136,3140,3148,3152,3156,3160,3164,3168,3172,3180,3184,3188,3192,3196,3200,3204,3212,3216,3220,3224,3228,3232,3236,3244,3248,3252,3256,
               3260,3264,3268,3276,3280,3284,3288,3292,3296,3300,3304,3308,3312,3316,3324,3328,3332,3336,3340,3345,3349,3353,3357,3361,3365,3369,3373,
               3377,3381,3385,3389,3393,3397,3401,3405,3409,3413,3417,3421,3425,3429,3433,3437,3441,3445,3449,3453,3457,3461,3465,3469,3473,3477,3481,
               3485,3489,3493,3497,3501,3505,3509,3513,3515,3517,3521,3525,3529,3533,3537,3541,3545,3549,3553,3557,3561,3563,3565,3569,3573,3577,3581,
               3585,3589,3593,3597,3601,3605,3610,3612,3614,3618,3622,3626,3630,3634,3638,3642,3644,3646,3650,3654,3658,3660,3662,3666,3670,3674,3678,
               3682,3686,3690,3692,3694,3698,3702,3704,3707,3710,3713,3716,3718,3721,3724,3727,3729,3732,3736,3739,3741,3743,3746,3749,3752,3754,3757,
               3761,3763,3766,3768,3771,3775,3777,3780,3782,3785,3789,3791,3794,3796,3800,3803,3805,3809,3810,3814,3818,3820,3823,3825,3829,3832,3834,
               3838,3840,3844,3847,3849,3853,3855,3859,3862,3864,3868,3870,3874,3878,3879,3883,3886,3890,3891,3894,3897,3902,3904,3907,3911,3913,3916,
               3919,3922,3925,3928,3931,3934,3937,3941,3944,3947,3950,3953,3957,3959,3963,3966,3969,3973,3976,3980,3981,3985,3988,3992,3994,3998,4002,
               4004,4007,4011,4013,4016,4020,4023,4026,4029,4032,4035,4040,4042,4045,4049,4052,4056,4059,4062,4066,4069,4073,4077,4082,4086,4090,4095,
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
       6,
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
            320.000,
            500.000,
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
            2800.000,
          },
          /* awb trigger 2 */
          {
            3800.000,
            4200.000,
          },
          /* awb trigger 3 */
          {
            4800.000,
            5200.000,
          },
          /* awb trigger 4 */
          {
            5600.000,
            5700.000,
          },
          /* awb trigger 5 */
          {
            6200.000,
            6300.000,
          },
          /* awb trigger 6 */
          {
            7000.000,
            7100.000,
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
                        1024, 1024,  102,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,  204,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,  307,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,  409,
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
                        3072, 2621,  819,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3642,  921,
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
                        3072, 1966, 1177,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1382,
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
                        2560, 2037, 1663,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2486, 1740,
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
                        2560, 2099,  255,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3123,  358,
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
                        2048, 2047,  716,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  819,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  921,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1510, 1126,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3652, 1433,
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
                        4095, 2957, 1740,
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
                        3584, 3018, 2227,
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
                        4095, 3618, 3276,
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
                         512,  512,   51,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,  153,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,  255,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,  358,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536,  983,  588,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3131,  870,
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
                        4095, 4094, 1433,
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
                        3072, 2496, 1689,
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
                        4095, 3020, 2252,
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
                        3584, 3091, 2739,
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
                        3072, 2611,  307,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3635,  409,
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
                        2560, 2560,  767,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  870,
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
                        2560, 1973, 1152,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3143, 1382,
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
                        3584, 2493, 1715,
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
                        3072, 2564, 2201,
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
                        4095, 3097, 2764,
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
                        1024, 1024,  102,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,  204,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,  307,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,  409,
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
                        3072, 2621,  819,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3642,  921,
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
                        3072, 2030, 1177,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1382,
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
                        2560, 2067, 1663,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2565, 1740,
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
                        2560, 2099,  255,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3123,  358,
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
                        2048, 2047,  716,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  819,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  921,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1541, 1126,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3652, 1433,
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
                        4095, 3036, 1740,
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
                        3584, 3063, 2227,
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
                        4095, 3645, 3276,
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
                         512,  512,   51,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,  153,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,  255,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,  358,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1015,  588,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3131,  870,
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
                        4095, 4094, 1433,
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
                        3072, 2542, 1689,
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
                        4095, 3082, 2252,
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
                        3584, 3119, 2739,
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
                        3072, 2611,  307,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3635,  409,
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
                        2560, 2560,  767,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  870,
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
                        2560, 2020, 1152,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3143, 1382,
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
                        3584, 2556, 1715,
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
                        3072, 2593, 2201,
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
                        4095, 3141, 2764,
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
                        1024, 1024,  102,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,  204,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,  307,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,  409,
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
                        3072, 2621,  819,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3642,  921,
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
                        3072, 2030, 1177,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1382,
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
                        2560, 2067, 1663,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2565, 1740,
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
                        2560, 2099,  255,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3123,  358,
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
                        2048, 2047,  716,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  819,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095,  921,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1541, 1126,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3652, 1433,
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
                        4095, 3036, 1740,
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
                        3584, 3063, 2227,
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
                        4095, 3645, 3276,
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
                         512,  512,   51,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,  153,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,  255,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,  358,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1015,  588,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3131,  870,
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
                        4095, 4094, 1433,
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
                        3072, 2542, 1689,
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
                        4095, 3082, 2252,
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
                        3584, 3119, 2739,
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
                        3072, 2611,  307,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3635,  409,
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
                        2560, 2560,  767,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583,  870,
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
                        2560, 2020, 1152,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3143, 1382,
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
                        3584, 2556, 1715,
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
                        3072, 2593, 2201,
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
                        4095, 3141, 2764,
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
                        1024, 1024,  153,
                        3072, 1023,    0,
                         511, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,  307,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1023, 3072,    0,
                        3072, 3071,  460,
                         511, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,  614,
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
                        3072, 2652,  972,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3671, 1126,
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
                        3072, 2030, 1177,
                         511, 2560, 1023,
                        2560, 2559, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1561,
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
                        2560, 2067, 1663,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2565, 1740,
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
                        2560, 2124,  384,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 3148,  537,
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
                        2048, 2047,  819,
                        4095, 2048,  512,
                        1536, 2560,  511,
                        3584, 2559,  511,
                        1023, 3072,  511,
                        3072, 3072,  972,
                         511, 3584,  511,
                        2560, 3584,  511,
                           0, 4095,  512,
                        2047, 4095,  512,
                        4095, 4095, 1126,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  511, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1023,
                        2048, 1541, 1126,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2559, 1023,
                         511, 3072, 1024,
                        2559, 3072, 1023,
                           0, 3584, 1023,
                        2048, 3584, 1024,
                        4095, 3686, 1638,
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
                        4095, 3036, 1740,
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
                        3584, 3063, 2227,
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
                        4095, 3645, 3276,
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
                         512,  512,   76,
                        2560,  511,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1535,  230,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         511, 2560,    0,
                        2560, 2560,  384,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3071,    0,
                        1535, 3584,    0,
                        3584, 3584,  537,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1015,  588,
                        3584, 1023,  511,
                        1024, 1536,  511,
                        3072, 1536,  511,
                         512, 2048,  512,
                        2560, 2048,  511,
                           0, 2560,  512,
                        2048, 2560,  511,
                        4095, 2560,  512,
                        1535, 3072,  511,
                        3584, 3161, 1049,
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
                        4095, 4094, 1638,
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
                        3072, 2542, 1689,
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
                        4095, 3082, 2252,
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
                        3584, 3119, 2739,
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
                        3072, 2636,  460,
                         512, 3072,    0,
                        2559, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3660,  614,
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
                        2560, 2560,  895,
                           0, 3072,  511,
                        2048, 3072,  511,
                        4095, 3072,  512,
                        1535, 3584,  511,
                        3584, 3583, 1049,
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
                        2560, 2020, 1152,
                           0, 2560, 1023,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1023,
                        3584, 3179, 1561,
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
                        3584, 2556, 1715,
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
                        3072, 2593, 2201,
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
                        4095, 3141, 2764,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
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
                        3072, 3072,    0,
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
                        1535, 4095,  512,
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
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1023,
                        4095, 3072, 1024,
                        1535, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         511,    0, 1536,
                        2560,    0, 1535,
                           0,  511, 1536,
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
                           0, 1023, 3072,
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
                         511,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  511, 3584,
                        4095,  512, 3583,
                        1535, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         511, 2048, 3584,
                        2559, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2559, 3584,
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
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2559, 4095,
                        3584, 2560, 4095,
                        1024, 3071, 4095,
                        3072, 3072, 4095,
                         512, 3583, 4095,
                        2560, 3583, 4095,
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
                        1024, 3584,    0,
                        3071, 3584,    0,
                         511, 4095,    0,
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
                        2048, 2048,  512,
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
                        1023,  511, 3072,
                        3072,  511, 3072,
                         511, 1024, 3072,
                        2559, 1023, 3072,
                           0, 1536, 3072,
                        2047, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2047, 3072,
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
                        1024, 1536, 4095,
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
                        1536, 1536,    0,
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
                        1023, 3584,  511,
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
                        4095, 4095, 1024,
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
                         511,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  511, 2560,
                        4095,  512, 2559,
                        1535, 1024, 2560,
                        3584, 1024, 2559,
                        1024, 1535, 2560,
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
                         511, 1024, 3584,
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
                           0, 1023, 4095,
                        2047, 1024, 4095,
                        4095, 1024, 4095,
                        1536, 1536, 4095,
                        3584, 1536, 4095,
                        1024, 2048, 4095,
                        3072, 2048, 4095,
                         512, 2559, 4095,
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
                         511, 3072,    0,
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
                        3584, 3584,  511,
                        1024, 4095,  512,
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
                        2047, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2047,
                        1023,  512, 2048,
                        3072,  511, 2047,
                         512, 1023, 2048,
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
                        3071, 4095, 2560,
                         512,    0, 3072,
                        2559,    0, 3072,
                           0,  512, 3072,
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
                         511, 1535, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
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
                        1536, 2047, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3071, 2560, 4095,
                         512, 3072, 4095,
                        2560, 3072, 4095,
                           0, 3584, 4095,
                        2048, 3584, 4095,
                        4095, 3584, 4095,
                        1536, 4095, 4095,
                        3584, 4095, 4095,
                           0,    0,    0,
                           0,    0,    0,
                  },
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
            1.000,
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
          /* aec tigger 3 */
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
          /* aec tigger 4 */
          {
              /* awb tigger 1 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.800000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.800000, //saturation
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
               70,  //sharpen_pos
               90,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 400, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               65,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               110, //limit_max
               110, //limit_min
               0, 1, 40, 400, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   20,50,20,//gaussian(1,1:3)
                   50,300,50,//gaussian(2,1:3)
                   20,50,20,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               70,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 400, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               50,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               80, //limit_max
               80, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               50,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               35,  //sharpen_pos
               55,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               50,  //sharpen_fu
               25,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
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
          /* para 4 */
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
          /* para 5 */
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
          /* para 6 */
          {
             1,  //enable
             5,  //zoom_par
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
          /* para 8 */
          {
             1,  //enable
             7,  //zoom_par
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
          /* para 10 */
          {
             1,  //enable
             9,  //zoom_par
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
                   213,174,149,132,118,106,96,88,81,74,68,62,57,52,48,44,40,36,33,29,26,23,20,18,15,13,10,8,5,3,1,0,
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
                   213,174,149,132,118,106,96,88,81,74,68,62,57,52,48,44,40,36,33,29,26,23,20,18,15,13,10,8,5,3,1,0,
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
                   262,214,184,162,145,131,119,108,99,91,83,77,70,65,59,54,49,45,40,36,32,29,25,22,19,16,13,10,7,4,2,0,
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
                   361,294,253,223,199,180,164,149,137,125,115,106,97,89,81,74,68,62,56,50,45,40,35,30,26,22,17,13,10,6,2,0,
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
        482,
        /* ev0_count */
        482,
        /* ev2_count */
        482,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        2028,
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
          {1024,  347  },        /* Gain= 4.000000 Exposure Index= 233 */
          {1024,  358  },        /* Gain= 4.000000 Exposure Index= 234 */
          {1024,  369  },        /* Gain= 4.000000 Exposure Index= 235 */
          {1024,  381  },        /* Gain= 4.000000 Exposure Index= 236 */
          {1024,  393  },        /* Gain= 4.000000 Exposure Index= 237 */
          {1024,  405  },        /* Gain= 4.000000 Exposure Index= 238 */
          {1024,  418  },        /* Gain= 4.000000 Exposure Index= 239 */
          {1024,  431  },        /* Gain= 4.000000 Exposure Index= 240 */
          {1024,  444  },        /* Gain= 4.000000 Exposure Index= 241 */
          {1024,  458  },        /* Gain= 4.000000 Exposure Index= 242 */
          {1024,  472  },        /* Gain= 4.000000 Exposure Index= 243 */
          {1024,  487  },        /* Gain= 4.000000 Exposure Index= 244 */
          {1024,  502  },        /* Gain= 4.000000 Exposure Index= 245 */
          {1024,  518  },        /* Gain= 4.000000 Exposure Index= 246 */
          {1024,  534  },        /* Gain= 4.000000 Exposure Index= 247 */
          {1024,  551  },        /* Gain= 4.000000 Exposure Index= 248 */
          {1024,  568  },        /* Gain= 4.000000 Exposure Index= 249 */
          {1024,  586  },        /* Gain= 4.000000 Exposure Index= 250 */
          {1024,  604  },        /* Gain= 4.000000 Exposure Index= 251 */
          {1024,  623  },        /* Gain= 4.000000 Exposure Index= 252 */
          {1024,  642  },        /* Gain= 4.000000 Exposure Index= 253 */
          {1055,  642  },        /* Gain= 4.121094 Exposure Index= 254 */
          {1087,  642  },        /* Gain= 4.246094 Exposure Index= 255 */
          {1120,  642  },        /* Gain= 4.375000 Exposure Index= 256 */
          {1154,  642  },        /* Gain= 4.507813 Exposure Index= 257 */
          {1189,  642  },        /* Gain= 4.644531 Exposure Index= 258 */
          {1225,  642  },        /* Gain= 4.785156 Exposure Index= 259 */
          {1262,  642  },        /* Gain= 4.929688 Exposure Index= 260 */
          {1300,  642  },        /* Gain= 5.078125 Exposure Index= 261 */
          {1339,  642  },        /* Gain= 5.230469 Exposure Index= 262 */
          {1380,  642  },        /* Gain= 5.390625 Exposure Index= 263 */
          {1422,  642  },        /* Gain= 5.554688 Exposure Index= 264 */
          {1465,  642  },        /* Gain= 5.722656 Exposure Index= 265 */
          {1509,  642  },        /* Gain= 5.894531 Exposure Index= 266 */
          {1555,  642  },        /* Gain= 6.074219 Exposure Index= 267 */
          {1602,  642  },        /* Gain= 6.257813 Exposure Index= 268 */
          {1651,  642  },        /* Gain= 6.449219 Exposure Index= 269 */
          {1701,  642  },        /* Gain= 6.644531 Exposure Index= 270 */
          {1753,  642  },        /* Gain= 6.847656 Exposure Index= 271 */
          {1806,  642  },        /* Gain= 7.054688 Exposure Index= 272 */
          {1861,  642  },        /* Gain= 7.269531 Exposure Index= 273 */
          {1917,  642  },        /* Gain= 7.488281 Exposure Index= 274 */
          {1975,  642  },        /* Gain= 7.714844 Exposure Index= 275 */
          {2035,  642  },        /* Gain= 7.949219 Exposure Index= 276 */
          {2097,  642  },        /* Gain= 8.191406 Exposure Index= 277 */
          {2160,  642  },        /* Gain= 8.437500 Exposure Index= 278 */
          {2225,  642  },        /* Gain= 8.691406 Exposure Index= 279 */
          {2292,  642  },        /* Gain= 8.953125 Exposure Index= 280 */
          {2361,  642  },        /* Gain= 9.222656 Exposure Index= 281 */
          {2432,  642  },        /* Gain= 9.500000 Exposure Index= 282 */
          {2505,  642  },        /* Gain= 9.785156 Exposure Index= 283 */
          {2581,  642  },        /* Gain= 10.082031 Exposure Index= 284 */
          {2659,  642  },        /* Gain= 10.386719 Exposure Index= 285 */
          {2739,  642  },        /* Gain= 10.699219 Exposure Index= 286 */
          {2822,  642  },        /* Gain= 11.023438 Exposure Index= 287 */
          {2907,  642  },        /* Gain= 11.355469 Exposure Index= 288 */
          {2995,  642  },        /* Gain= 11.699219 Exposure Index= 289 */
          {3085,  642  },        /* Gain= 12.050781 Exposure Index= 290 */
          {3178,  642  },        /* Gain= 12.414063 Exposure Index= 291 */
          {3274,  642  },        /* Gain= 12.789063 Exposure Index= 292 */
          {3373,  642  },        /* Gain= 13.175781 Exposure Index= 293 */
          {3475,  642  },        /* Gain= 13.574219 Exposure Index= 294 */
          {3580,  642  },        /* Gain= 13.984375 Exposure Index= 295 */
          {3688,  642  },        /* Gain= 14.406250 Exposure Index= 296 */
          {3799,  642  },        /* Gain= 14.839844 Exposure Index= 297 */
          {3913,  642  },        /* Gain= 15.285156 Exposure Index= 298 */
          {4031,  642  },        /* Gain= 15.746094 Exposure Index= 299 */
          {4096,  651  },        /* Gain= 16.000000 Exposure Index= 300 */
          {4096,  671  },        /* Gain= 16.000000 Exposure Index= 301 */
          {4096,  692  },        /* Gain= 16.000000 Exposure Index= 302 */
          {4096,  713  },        /* Gain= 16.000000 Exposure Index= 303 */
          {4096,  735  },        /* Gain= 16.000000 Exposure Index= 304 */
          {4096,  758  },        /* Gain= 16.000000 Exposure Index= 305 */
          {4096,  781  },        /* Gain= 16.000000 Exposure Index= 306 */
          {4096,  805  },        /* Gain= 16.000000 Exposure Index= 307 */
          {4096,  830  },        /* Gain= 16.000000 Exposure Index= 308 */
          {4096,  855  },        /* Gain= 16.000000 Exposure Index= 309 */
          {4096,  881  },        /* Gain= 16.000000 Exposure Index= 310 */
          {4096,  908  },        /* Gain= 16.000000 Exposure Index= 311 */
          {4096,  936  },        /* Gain= 16.000000 Exposure Index= 312 */
          {4096,  965  },        /* Gain= 16.000000 Exposure Index= 313 */
          {4096,  994  },        /* Gain= 16.000000 Exposure Index= 314 */
          {4096,  1024  },        /* Gain= 16.000000 Exposure Index= 315 */
          {4096,  1055  },        /* Gain= 16.000000 Exposure Index= 316 */
          {4096,  1087  },        /* Gain= 16.000000 Exposure Index= 317 */
          {4096,  1120  },        /* Gain= 16.000000 Exposure Index= 318 */
          {4201,  1125  },        /* Gain= 16.410156 Exposure Index= 319 */
          {4328,  1125  },        /* Gain= 16.906250 Exposure Index= 320 */
          {4458,  1125  },        /* Gain= 17.414063 Exposure Index= 321 */
          {4592,  1125  },        /* Gain= 17.937500 Exposure Index= 322 */
          {4730,  1125  },        /* Gain= 18.476563 Exposure Index= 323 */
          {4872,  1125  },        /* Gain= 19.031250 Exposure Index= 324 */
          {5019,  1125  },        /* Gain= 19.605469 Exposure Index= 325 */
          {5170,  1125  },        /* Gain= 20.195313 Exposure Index= 326 */
          {5326,  1125  },        /* Gain= 20.804688 Exposure Index= 327 */
          {5486,  1125  },        /* Gain= 21.429688 Exposure Index= 328 */
          {5651,  1125  },        /* Gain= 22.074219 Exposure Index= 329 */
          {5821,  1125  },        /* Gain= 22.738281 Exposure Index= 330 */
          {5996,  1125  },        /* Gain= 23.421875 Exposure Index= 331 */
          {6176,  1125  },        /* Gain= 24.125000 Exposure Index= 332 */
          {6362,  1125  },        /* Gain= 24.851563 Exposure Index= 333 */
          {6553,  1125  },        /* Gain= 25.597656 Exposure Index= 334 */
          {6750,  1125  },        /* Gain= 26.367188 Exposure Index= 335 */
          {6953,  1125  },        /* Gain= 27.160156 Exposure Index= 336 */
          {7162,  1125  },        /* Gain= 27.976563 Exposure Index= 337 */
          {7377,  1125  },        /* Gain= 28.816406 Exposure Index= 338 */
          {7599,  1125  },        /* Gain= 29.683594 Exposure Index= 339 */
          {7827,  1125  },        /* Gain= 30.574219 Exposure Index= 340 */
          {8062,  1125  },        /* Gain= 31.492188 Exposure Index= 341 */
          {8304,  1125  },        /* Gain= 32.437500 Exposure Index= 342 */
          {8554,  1125  },        /* Gain= 33.414063 Exposure Index= 343 */
          {8811,  1125  },        /* Gain= 34.417969 Exposure Index= 344 */
          {9076,  1125  },        /* Gain= 35.453125 Exposure Index= 345 */
          {9349,  1125  },        /* Gain= 36.519531 Exposure Index= 346 */
          {9630,  1125  },        /* Gain= 37.617188 Exposure Index= 347 */
          {9919,  1125  },        /* Gain= 38.746094 Exposure Index= 348 */
          {10217,  1125  },        /* Gain= 39.910156 Exposure Index= 349 */
          {10524,  1125  },        /* Gain= 41.109375 Exposure Index= 350 */
          {10840,  1125  },        /* Gain= 42.343750 Exposure Index= 351 */
          {11166,  1125  },        /* Gain= 43.617188 Exposure Index= 352 */
          {11501,  1125  },        /* Gain= 44.925781 Exposure Index= 353 */
          {11847,  1125  },        /* Gain= 46.277344 Exposure Index= 354 */
          {12203,  1125  },        /* Gain= 47.667969 Exposure Index= 355 */
          {12570,  1125  },        /* Gain= 49.101563 Exposure Index= 356 */
          {12948,  1125  },        /* Gain= 50.578125 Exposure Index= 357 */
          {13337,  1125  },        /* Gain= 52.097656 Exposure Index= 358 */
          {13738,  1125  },        /* Gain= 53.664063 Exposure Index= 359 */
          {14151,  1125  },        /* Gain= 55.277344 Exposure Index= 360 */
          {14576,  1125  },        /* Gain= 56.937500 Exposure Index= 361 */
          {15014,  1125  },        /* Gain= 58.648438 Exposure Index= 362 */
          {15465,  1125  },        /* Gain= 60.410156 Exposure Index= 363 */
          {15929,  1125  },        /* Gain= 62.222656 Exposure Index= 364 */
          {16407,  1125  },        /* Gain= 64.089844 Exposure Index= 365 */
          {16900,  1125  },        /* Gain= 66.015625 Exposure Index= 366 */
          {17407,  1125  },        /* Gain= 67.996094 Exposure Index= 367 */
          {17930,  1125  },        /* Gain= 70.039063 Exposure Index= 368 */
          {18468,  1125  },        /* Gain= 72.140625 Exposure Index= 369 */
          {19023,  1125  },        /* Gain= 74.308594 Exposure Index= 370 */
          {19594,  1125  },        /* Gain= 76.539063 Exposure Index= 371 */
          {20182,  1125  },        /* Gain= 78.835938 Exposure Index= 372 */
          {20788,  1125  },        /* Gain= 81.203125 Exposure Index= 373 */
          {21412,  1125  },        /* Gain= 83.640625 Exposure Index= 374 */
          {22055,  1125  },        /* Gain= 86.152344 Exposure Index= 375 */
          {22717,  1125  },        /* Gain= 88.738281 Exposure Index= 376 */
          {23399,  1125  },        /* Gain= 91.402344 Exposure Index= 377 */
          {24101,  1125  },        /* Gain= 94.144531 Exposure Index= 378 */
          {24825,  1125  },        /* Gain= 96.972656 Exposure Index= 379 */
          {25570,  1125  },        /* Gain= 99.882813 Exposure Index= 380 */
          {26338,  1125  },        /* Gain= 102.882813 Exposure Index= 381 */
          {27129,  1125  },        /* Gain= 105.972656 Exposure Index= 382 */
          {27943,  1125  },        /* Gain= 109.152344 Exposure Index= 383 */
          {28782,  1125  },        /* Gain= 112.429688 Exposure Index= 384 */
          {29646,  1125  },        /* Gain= 115.804688 Exposure Index= 385 */
          {30536,  1125  },        /* Gain= 119.281250 Exposure Index= 386 */
          {31453,  1125  },        /* Gain= 122.863281 Exposure Index= 387 */
          {32397,  1125  },        /* Gain= 126.550781 Exposure Index= 388 */
          {33369,  1125  },        /* Gain= 130.347656 Exposure Index= 389 */
          {34371,  1125  },        /* Gain= 134.261719 Exposure Index= 390 */
          {35403,  1125  },        /* Gain= 138.292969 Exposure Index= 391 */
          {36466,  1125  },        /* Gain= 142.445313 Exposure Index= 392 */
          {37560,  1125  },        /* Gain= 146.718750 Exposure Index= 393 */
          {38687,  1125  },        /* Gain= 151.121094 Exposure Index= 394 */
          {39848,  1125  },        /* Gain= 155.656250 Exposure Index= 395 */
          {41044,  1125  },        /* Gain= 160.328125 Exposure Index= 396 */
          {42276,  1125  },        /* Gain= 165.140625 Exposure Index= 397 */
          {43545,  1125  },        /* Gain= 170.097656 Exposure Index= 398 */
          {44852,  1125  },        /* Gain= 175.203125 Exposure Index= 399 */
          {46198,  1125  },        /* Gain= 180.460938 Exposure Index= 400 */
          {47584,  1125  },        /* Gain= 185.875000 Exposure Index= 401 */
          {49012,  1125  },        /* Gain= 191.453125 Exposure Index= 402 */
          {50483,  1125  },        /* Gain= 197.199219 Exposure Index= 403 */
          {51998,  1125  },        /* Gain= 203.117188 Exposure Index= 404 */
          {53558,  1125  },        /* Gain= 209.210938 Exposure Index= 405 */
          {55165,  1125  },        /* Gain= 215.488281 Exposure Index= 406 */
          {56820,  1125  },        /* Gain= 221.953125 Exposure Index= 407 */
          {58525,  1125  },        /* Gain= 228.613281 Exposure Index= 408 */
          {60281,  1125  },        /* Gain= 235.472656 Exposure Index= 409 */
          {62090,  1125  },        /* Gain= 242.539063 Exposure Index= 410 */
          {63953,  1125  },        /* Gain= 249.816406 Exposure Index= 411 */
          {65872,  1125  },        /* Gain= 257.312500 Exposure Index= 412 */
          {67849,  1125  },        /* Gain= 265.035156 Exposure Index= 413 */
          {69885,  1125  },        /* Gain= 272.988281 Exposure Index= 414 */
          {71982,  1125  },        /* Gain= 281.179688 Exposure Index= 415 */
          {74142,  1125  },        /* Gain= 289.617188 Exposure Index= 416 */
          {76367,  1125  },        /* Gain= 298.308594 Exposure Index= 417 */
          {78659,  1125  },        /* Gain= 307.261719 Exposure Index= 418 */
          {81019,  1125  },        /* Gain= 316.480469 Exposure Index= 419 */
          {83450,  1125  },        /* Gain= 325.976563 Exposure Index= 420 */
          {85954,  1125  },        /* Gain= 335.757813 Exposure Index= 421 */
          {88533,  1125  },        /* Gain= 345.832031 Exposure Index= 422 */
          {91189,  1125  },        /* Gain= 356.207031 Exposure Index= 423 */
          {93925,  1125  },        /* Gain= 366.894531 Exposure Index= 424 */
          {96743,  1125  },        /* Gain= 377.902344 Exposure Index= 425 */
          {99646,  1125  },        /* Gain= 389.242188 Exposure Index= 426 */
          {102636,  1125  },        /* Gain= 400.921875 Exposure Index= 427 */
          {105716,  1125  },        /* Gain= 412.953125 Exposure Index= 428 */
          {108888,  1125  },        /* Gain= 425.343750 Exposure Index= 429 */
          {112155,  1125  },        /* Gain= 438.105469 Exposure Index= 430 */
          {115520,  1125  },        /* Gain= 451.250000 Exposure Index= 431 */
          {118986,  1125  },        /* Gain= 464.789063 Exposure Index= 432 */
          {122556,  1125  },        /* Gain= 478.734375 Exposure Index= 433 */
          {126233,  1125  },        /* Gain= 493.097656 Exposure Index= 434 */
          {130020,  1125  },        /* Gain= 507.890625 Exposure Index= 435 */
          {133921,  1125  },        /* Gain= 523.128906 Exposure Index= 436 */
          {137939,  1125  },        /* Gain= 538.824219 Exposure Index= 437 */
          {142078,  1125  },        /* Gain= 554.992188 Exposure Index= 438 */
          {146341,  1125  },        /* Gain= 571.644531 Exposure Index= 439 */
          {150732,  1125  },        /* Gain= 588.796875 Exposure Index= 440 */
          {155254,  1125  },        /* Gain= 606.460938 Exposure Index= 441 */
          {159912,  1125  },        /* Gain= 624.656250 Exposure Index= 442 */
          {164710,  1125  },        /* Gain= 643.398438 Exposure Index= 443 */
          {169652,  1125  },        /* Gain= 662.703125 Exposure Index= 444 */
          {174742,  1125  },        /* Gain= 682.585938 Exposure Index= 445 */
          {179985,  1125  },        /* Gain= 703.066406 Exposure Index= 446 */
          {185385,  1125  },        /* Gain= 724.160156 Exposure Index= 447 */
          {190947,  1125  },        /* Gain= 745.886719 Exposure Index= 448 */
          {196676,  1125  },        /* Gain= 768.265625 Exposure Index= 449 */
          {202577,  1125  },        /* Gain= 791.316406 Exposure Index= 450 */
          {208655,  1125  },        /* Gain= 815.058594 Exposure Index= 451 */
          {214915,  1125  },        /* Gain= 839.511719 Exposure Index= 452 */
          {221363,  1125  },        /* Gain= 864.699219 Exposure Index= 453 */
          {228004,  1125  },        /* Gain= 890.640625 Exposure Index= 454 */
          {234845,  1125  },        /* Gain= 917.363281 Exposure Index= 455 */
          {241891,  1125  },        /* Gain= 944.886719 Exposure Index= 456 */
          {249148,  1125  },        /* Gain= 973.234375 Exposure Index= 457 */
          {256623,  1125  },        /* Gain= 1002.433594 Exposure Index= 458 */
          {264322,  1125  },        /* Gain= 1032.507813 Exposure Index= 459 */
          {272252,  1125  },        /* Gain= 1063.484375 Exposure Index= 460 */
          {280420,  1125  },        /* Gain= 1095.390625 Exposure Index= 461 */
          {288833,  1125  },        /* Gain= 1128.253906 Exposure Index= 462 */
          {297498,  1125  },        /* Gain= 1162.101563 Exposure Index= 463 */
          {306423,  1125  },        /* Gain= 1196.964844 Exposure Index= 464 */
          {315616,  1125  },        /* Gain= 1232.875000 Exposure Index= 465 */
          {325085,  1125  },        /* Gain= 1269.863281 Exposure Index= 466 */
          {334838,  1125  },        /* Gain= 1307.960938 Exposure Index= 467 */
          {344884,  1125  },        /* Gain= 1347.203125 Exposure Index= 468 */
          {355231,  1125  },        /* Gain= 1387.621094 Exposure Index= 469 */
          {365888,  1125  },        /* Gain= 1429.250000 Exposure Index= 470 */
          {376865,  1125  },        /* Gain= 1472.128906 Exposure Index= 471 */
          {388171,  1125  },        /* Gain= 1516.292969 Exposure Index= 472 */
          {399817,  1125  },        /* Gain= 1561.785156 Exposure Index= 473 */
          {411812,  1125  },        /* Gain= 1608.640625 Exposure Index= 474 */
          {424167,  1125  },        /* Gain= 1656.902344 Exposure Index= 475 */
          {436893,  1125  },        /* Gain= 1706.613281 Exposure Index= 476 */
          {450000,  1125  },        /* Gain= 1757.812500 Exposure Index= 477 */
          {463500,  1125  },        /* Gain= 1810.546875 Exposure Index= 478 */
          {477405,  1125  },        /* Gain= 1864.863281 Exposure Index= 479 */
          {491728,  1125  },        /* Gain= 1920.812500 Exposure Index= 480 */
          {506480,  1125  },        /* Gain= 1978.437500 Exposure Index= 481 */
        },
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            57,  /* outdoor_luma_target_compensated */
            57,  /* default_luma_target_compensated */
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
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
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
	2,
	/* trigger_mode */
	1,
	/* aec_trigger */
    {
		{
            0,
            400,
        },
        {
            401,
            550,
        },
        {
            0,
            0,
        },
	},
    /* awb_point */
    {
        { 0.4544, 0.7793 },    /* d75 */
        { 0.4757, 0.6987 },    /* d65 */
        { 0.5448, 0.5953 },    /* d50 */
        { 0.5448, 0.5953 },    /* noon */
        { 0.5537, 0.4101 },    /* cw */
        { 0.6893, 0.4298 },    /* tl84 */
        { 0.7950, 0.3552 },    /* a */
        { 0.9548, 0.3141 },    /* h */
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
        { 2, 8, 2, 1 },   /*   d65    */
        {10,10, 10, 2 },   /*   d50    */
        {10,10, 10, 2 },   /*   noon   */
        { 1, 1, 1, 1 },   /*   cw     */
        { 1, 1, 1, 3 },   /*   tl84   */
        { 0, 0, 1, 1 },   /*   a      */
        { 0, 0, 1, 1 },   /*   h      */
        { 0, 0, 1, 1 },   /*   custom1*/
        { 0, 0, 1, 1 },   /*   custom2*/
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
      	   0x00000005,
           0x00000009,
           0x00000002,
           0x00000005,
           0x0000000b,
           0x00000010,
           0x00000010,
           0x0000000d,
           0x00000003,
           0x00000004,
           0x00000000,
           0x00000000,
           0x00000000, /* gbBL */
           0x00000000, /* bbBL */
           0x00000100, /* rrGain */
           0x00000100, /* grGain */
           0x00000100, /* gbGain */
           0x00000100, /* bbGain */
           0x000003e8,	/* Y max  0.80*1024	*/
           0x0000000a,	/* Y min  0.05*1024	*/
           0x00000010,
           0x00010100,
           0x00000100,
           0x000100c8,
           0x00000014,
           0x00010320,
           0x00010258,
           0x00000028,
           0x000000a1, /* Green_BGmax */
           0x00000037, /* Green_BGmin */
           0x00000085, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000144, /* Green_Rmul */
           0x000000c2, /* Green_Bmul */
           0x000000cc,	/* extreme B, B/G */	//	D50 0.8
           0x00000500,	/* extreme B, R/G */
           0x00000133,	/* extreme R, R/G */	//	TL84
           0x00000191,	/* extreme R, B/G */
		   2, //zoom
    	},
    	{
    	   0x00000005,
           0x00000009,
           0x00000002,
           0x00000005,
           0x0000000b,
           0x00000010,
           0x00000010,
           0x0000000d,
           0x00000003,
           0x00000004,
           0x00000000,
           0x00000000,
           0x00000000, /* gbBL */
           0x00000000, /* bbBL */
           0x00000100, /* rrGain */
           0x00000100, /* grGain */
           0x00000100, /* gbGain */
           0x00000100, /* bbGain */
           0x00000333,	/* Y max  0.80*1024	*/
           0x00000000,	/* Y min  0.05*1024	*/
           0x00000010,
           0x00010100,
           0x00000100,
           0x000100c8,
           0x00000014,
           0x00010320,
           0x00010258,
           0x00000028,
           0x000000a1, /* Green_BGmax */
           0x00000037, /* Green_BGmin */
           0x00000085, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000144, /* Green_Rmul */
           0x000000c2, /* Green_Bmul */
           0x000000c0, /* ExtremeB_BG_TH */
           0x00001480, /* ExtremeB_RG_TH */
           0x00000119, /* ExtremeR_RG_TH */
           0x00001980, /* ExtremeR_BG_TH */
		   2, //zoom
    	},
    	{
    	},
  },
},
/*af_tuning_t  af_tuning*/
{

},
