
/*---------------header of imx307 tuing-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x00000001,
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
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {15,45,40},
                        //g channel
                        {15,45,40},
                        //b channel
                        {15,45,40},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {8,24,14},
                        //g channel
                        {8,24,14},
                        //b channel
                        {8,24,14},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {5,15,8},
                        //g channel
                        {5,15,8},
                        //b channel
                        {5,15,8},
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
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {25,75,69},
                        //g channel
                        {25,75,69},
                        //b channel
                        {25,75,69},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {15,45,29},
                        //g channel
                        {15,45,29},
                        //b channel
                        {15,45,29},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {10,30,18},
                        //g channel
                        {10,30,18},
                        //b channel
                        {10,30,18},
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
                3,//denoise_layer
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
                        {25,75,49},
                        //g channel
                        {25,75,49},
                        //b channel
                        {25,75,49},
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
            /* para 4 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {75,225,214},
                        //g channel
                        {75,225,214},
                        //b channel
                        {75,225,214},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {45,135,91},
                        //g channel
                        {45,135,91},
                        //b channel
                        {45,135,91},
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
                3,//denoise_layer
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
                        {60,180,122},
                        //g channel
                        {60,180,122},
                        //b channel
                        {60,180,122},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {45,135,91},
                        //g channel
                        {45,135,91},
                        //b channel
                        {45,135,91},
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
                        {110,330,316},
                        //g channel
                        {110,330,316},
                        //b channel
                        {110,330,316},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {80,240,163},
                        //g channel
                        {80,240,163},
                        //b channel
                        {80,240,163},
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
                        {80,240,163},
                        //g channel
                        {80,240,163},
                        //b channel
                        {80,240,163},
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
                        {200,600,577},
                        //g channel
                        {200,600,577},
                        //b channel
                        {200,600,577},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {160,480,329},
                        //g channel
                        {160,480,329},
                        //b channel
                        {160,480,329},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {120,360,246},
                        //g channel
                        {120,360,246},
                        //b channel
                        {120,360,246},
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
                        {240,720,495},
                        //g channel
                        {240,720,495},
                        //b channel
                        {240,720,495},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {180,540,370},
                        //g channel
                        {180,540,370},
                        //b channel
                        {180,540,370},
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
                        {550,1650,1137},
                        //g channel
                        {550,1650,1137},
                        //b channel
                        {550,1650,1137},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {500,1500,1033},
                        //g channel
                        {500,1500,1033},
                        //b channel
                        {500,1500,1033},
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
        1,//count_ae
        1,//awb count
        1,//trigger_mode
        /*aec_trigger_t aec_trigger[LSC_TRIGGER_COUNT];*/
        {
            /*aec trigger 1*/
            {
              0.000,
              2000.000,
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
                      4.0571, 1.5801, 1.3872, 1.1582, 1.1074, 1.1167, 1.1367, 1.2324, 1.4136, 2.3062,
                      2.6206, 1.4556, 1.2192, 1.1182, 1.0635, 1.0615, 1.0884, 1.1260, 1.2690, 1.8110,
                      2.0903, 1.3584, 1.1519, 1.0879, 1.0371, 1.0405, 1.0581, 1.1182, 1.2051, 1.6563,
                      1.9482, 1.2681, 1.1362, 1.0615, 1.0132, 1.0088, 1.0405, 1.0825, 1.1670, 1.5308,
                      1.8433, 1.2446, 1.1138, 1.0435, 1.0068, 1.0010, 1.0215, 1.0874, 1.1548, 1.4819,
                      1.8638, 1.2437, 1.1211, 1.0493, 0.9990, 0.9985, 1.0229, 1.0874, 1.1455, 1.4814,
                      1.9146, 1.2754, 1.1294, 1.0708, 1.0107, 1.0195, 1.0371, 1.0947, 1.1606, 1.5342,
                      2.1118, 1.3252, 1.1602, 1.0835, 1.0317, 1.0313, 1.0488, 1.1099, 1.1895, 1.6143,
                      2.4585, 1.4434, 1.1992, 1.1162, 1.0552, 1.0405, 1.0854, 1.1196, 1.2583, 1.7998,
                      3.5869, 1.6157, 1.3730, 1.1514, 1.1216, 1.0869, 1.1519, 1.1924, 1.4204, 2.1289,
                      3.8154, 1.4814, 1.2793, 1.1030, 1.0693, 1.0791, 1.1001, 1.1245, 1.3809, 2.1230,
                      2.4321, 1.3438, 1.1606, 1.0640, 1.0415, 1.0337, 1.0659, 1.0903, 1.1943, 1.7437,
                      1.9727, 1.2769, 1.0913, 1.0591, 1.0225, 1.0215, 1.0347, 1.0542, 1.1499, 1.5288,
                      1.8325, 1.1831, 1.0942, 1.0400, 1.0078, 1.0010, 1.0332, 1.0688, 1.1089, 1.4819,
                      1.7173, 1.1729, 1.0635, 1.0200, 1.0024, 0.9946, 1.0161, 1.0542, 1.1089, 1.3877,
                      1.7485, 1.1582, 1.0869, 1.0225, 1.0024, 1.0000, 1.0127, 1.0693, 1.0923, 1.4180,
                      1.7871, 1.2041, 1.0723, 1.0493, 1.0029, 1.0078, 1.0205, 1.0615, 1.1055, 1.4424,
                      2.0010, 1.2354, 1.1133, 1.0586, 1.0117, 1.0234, 1.0283, 1.0703, 1.1274, 1.5313,
                      2.3086, 1.3574, 1.1372, 1.0786, 1.0415, 1.0254, 1.0581, 1.0786, 1.1987, 1.6865,
                      3.3818, 1.4888, 1.2949, 1.0991, 1.0664, 1.0708, 1.0835, 1.1465, 1.3037, 2.0596,
                      3.7031, 1.3970, 1.2764, 1.0620, 1.0581, 1.0527, 1.0811, 1.0986, 1.3506, 2.0625,
                      2.3340, 1.3335, 1.1064, 1.0605, 1.0264, 1.0186, 1.0615, 1.0576, 1.1821, 1.6934,
                      1.9346, 1.2363, 1.0703, 1.0425, 1.0127, 1.0063, 1.0273, 1.0449, 1.1152, 1.5127,
                      1.7378, 1.1558, 1.0635, 1.0190, 0.9985, 1.0083, 1.0225, 1.0439, 1.0977, 1.4131,
                      1.6572, 1.1460, 1.0425, 1.0151, 1.0029, 0.9907, 1.0151, 1.0439, 1.0864, 1.3652,
                      1.6934, 1.1240, 1.0571, 1.0073, 0.9897, 1.0063, 1.0000, 1.0566, 1.0645, 1.3701,
                      1.7744, 1.1777, 1.0615, 1.0361, 1.0078, 1.0020, 1.0244, 1.0508, 1.0894, 1.4380,
                      1.8892, 1.2188, 1.0723, 1.0410, 1.0049, 1.0103, 1.0142, 1.0493, 1.1025, 1.5107,
                      2.2954, 1.3311, 1.1118, 1.0708, 1.0186, 1.0186, 1.0469, 1.0649, 1.1738, 1.6426,
                      3.2813, 1.4907, 1.2451, 1.0752, 1.0674, 1.0234, 1.0786, 1.1016, 1.3066, 2.0259,
                    },
         		},
         		/* para 2 */
         		{
                   	0.500000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.0571, 1.5801, 1.3872, 1.1582, 1.1074, 1.1167, 1.1367, 1.2324, 1.4136, 2.3062,
                      2.6206, 1.4556, 1.2192, 1.1182, 1.0635, 1.0615, 1.0884, 1.1260, 1.2690, 1.8110,
                      2.0903, 1.3584, 1.1519, 1.0879, 1.0371, 1.0405, 1.0581, 1.1182, 1.2051, 1.6563,
                      1.9482, 1.2681, 1.1362, 1.0615, 1.0132, 1.0088, 1.0405, 1.0825, 1.1670, 1.5308,
                      1.8433, 1.2446, 1.1138, 1.0435, 1.0068, 1.0010, 1.0215, 1.0874, 1.1548, 1.4819,
                      1.8638, 1.2437, 1.1211, 1.0493, 0.9990, 0.9985, 1.0229, 1.0874, 1.1455, 1.4814,
                      1.9146, 1.2754, 1.1294, 1.0708, 1.0107, 1.0195, 1.0371, 1.0947, 1.1606, 1.5342,
                      2.1118, 1.3252, 1.1602, 1.0835, 1.0317, 1.0313, 1.0488, 1.1099, 1.1895, 1.6143,
                      2.4585, 1.4434, 1.1992, 1.1162, 1.0552, 1.0405, 1.0854, 1.1196, 1.2583, 1.7998,
                      3.5869, 1.6157, 1.3730, 1.1514, 1.1216, 1.0869, 1.1519, 1.1924, 1.4204, 2.1289,
                      3.8154, 1.4814, 1.2793, 1.1030, 1.0693, 1.0791, 1.1001, 1.1245, 1.3809, 2.1230,
                      2.4321, 1.3438, 1.1606, 1.0640, 1.0415, 1.0337, 1.0659, 1.0903, 1.1943, 1.7437,
                      1.9727, 1.2769, 1.0913, 1.0591, 1.0225, 1.0215, 1.0347, 1.0542, 1.1499, 1.5288,
                      1.8325, 1.1831, 1.0942, 1.0400, 1.0078, 1.0010, 1.0332, 1.0688, 1.1089, 1.4819,
                      1.7173, 1.1729, 1.0635, 1.0200, 1.0024, 0.9946, 1.0161, 1.0542, 1.1089, 1.3877,
                      1.7485, 1.1582, 1.0869, 1.0225, 1.0024, 1.0000, 1.0127, 1.0693, 1.0923, 1.4180,
                      1.7871, 1.2041, 1.0723, 1.0493, 1.0029, 1.0078, 1.0205, 1.0615, 1.1055, 1.4424,
                      2.0010, 1.2354, 1.1133, 1.0586, 1.0117, 1.0234, 1.0283, 1.0703, 1.1274, 1.5313,
                      2.3086, 1.3574, 1.1372, 1.0786, 1.0415, 1.0254, 1.0581, 1.0786, 1.1987, 1.6865,
                      3.3818, 1.4888, 1.2949, 1.0991, 1.0664, 1.0708, 1.0835, 1.1465, 1.3037, 2.0596,
                      3.7031, 1.3970, 1.2764, 1.0620, 1.0581, 1.0527, 1.0811, 1.0986, 1.3506, 2.0625,
                      2.3340, 1.3335, 1.1064, 1.0605, 1.0264, 1.0186, 1.0615, 1.0576, 1.1821, 1.6934,
                      1.9346, 1.2363, 1.0703, 1.0425, 1.0127, 1.0063, 1.0273, 1.0449, 1.1152, 1.5127,
                      1.7378, 1.1558, 1.0635, 1.0190, 0.9985, 1.0083, 1.0225, 1.0439, 1.0977, 1.4131,
                      1.6572, 1.1460, 1.0425, 1.0151, 1.0029, 0.9907, 1.0151, 1.0439, 1.0864, 1.3652,
                      1.6934, 1.1240, 1.0571, 1.0073, 0.9897, 1.0063, 1.0000, 1.0566, 1.0645, 1.3701,
                      1.7744, 1.1777, 1.0615, 1.0361, 1.0078, 1.0020, 1.0244, 1.0508, 1.0894, 1.4380,
                      1.8892, 1.2188, 1.0723, 1.0410, 1.0049, 1.0103, 1.0142, 1.0493, 1.1025, 1.5107,
                      2.2954, 1.3311, 1.1118, 1.0708, 1.0186, 1.0186, 1.0469, 1.0649, 1.1738, 1.6426,
                      3.2813, 1.4907, 1.2451, 1.0752, 1.0674, 1.0234, 1.0786, 1.1016, 1.3066, 2.0259,
                    },
         		},
         		/* para 3 */
         		{
                   	0.500000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.0571, 1.5801, 1.3872, 1.1582, 1.1074, 1.1167, 1.1367, 1.2324, 1.4136, 2.3062,
                      2.6206, 1.4556, 1.2192, 1.1182, 1.0635, 1.0615, 1.0884, 1.1260, 1.2690, 1.8110,
                      2.0903, 1.3584, 1.1519, 1.0879, 1.0371, 1.0405, 1.0581, 1.1182, 1.2051, 1.6563,
                      1.9482, 1.2681, 1.1362, 1.0615, 1.0132, 1.0088, 1.0405, 1.0825, 1.1670, 1.5308,
                      1.8433, 1.2446, 1.1138, 1.0435, 1.0068, 1.0010, 1.0215, 1.0874, 1.1548, 1.4819,
                      1.8638, 1.2437, 1.1211, 1.0493, 0.9990, 0.9985, 1.0229, 1.0874, 1.1455, 1.4814,
                      1.9146, 1.2754, 1.1294, 1.0708, 1.0107, 1.0195, 1.0371, 1.0947, 1.1606, 1.5342,
                      2.1118, 1.3252, 1.1602, 1.0835, 1.0317, 1.0313, 1.0488, 1.1099, 1.1895, 1.6143,
                      2.4585, 1.4434, 1.1992, 1.1162, 1.0552, 1.0405, 1.0854, 1.1196, 1.2583, 1.7998,
                      3.5869, 1.6157, 1.3730, 1.1514, 1.1216, 1.0869, 1.1519, 1.1924, 1.4204, 2.1289,
                      3.8154, 1.4814, 1.2793, 1.1030, 1.0693, 1.0791, 1.1001, 1.1245, 1.3809, 2.1230,
                      2.4321, 1.3438, 1.1606, 1.0640, 1.0415, 1.0337, 1.0659, 1.0903, 1.1943, 1.7437,
                      1.9727, 1.2769, 1.0913, 1.0591, 1.0225, 1.0215, 1.0347, 1.0542, 1.1499, 1.5288,
                      1.8325, 1.1831, 1.0942, 1.0400, 1.0078, 1.0010, 1.0332, 1.0688, 1.1089, 1.4819,
                      1.7173, 1.1729, 1.0635, 1.0200, 1.0024, 0.9946, 1.0161, 1.0542, 1.1089, 1.3877,
                      1.7485, 1.1582, 1.0869, 1.0225, 1.0024, 1.0000, 1.0127, 1.0693, 1.0923, 1.4180,
                      1.7871, 1.2041, 1.0723, 1.0493, 1.0029, 1.0078, 1.0205, 1.0615, 1.1055, 1.4424,
                      2.0010, 1.2354, 1.1133, 1.0586, 1.0117, 1.0234, 1.0283, 1.0703, 1.1274, 1.5313,
                      2.3086, 1.3574, 1.1372, 1.0786, 1.0415, 1.0254, 1.0581, 1.0786, 1.1987, 1.6865,
                      3.3818, 1.4888, 1.2949, 1.0991, 1.0664, 1.0708, 1.0835, 1.1465, 1.3037, 2.0596,
                      3.7031, 1.3970, 1.2764, 1.0620, 1.0581, 1.0527, 1.0811, 1.0986, 1.3506, 2.0625,
                      2.3340, 1.3335, 1.1064, 1.0605, 1.0264, 1.0186, 1.0615, 1.0576, 1.1821, 1.6934,
                      1.9346, 1.2363, 1.0703, 1.0425, 1.0127, 1.0063, 1.0273, 1.0449, 1.1152, 1.5127,
                      1.7378, 1.1558, 1.0635, 1.0190, 0.9985, 1.0083, 1.0225, 1.0439, 1.0977, 1.4131,
                      1.6572, 1.1460, 1.0425, 1.0151, 1.0029, 0.9907, 1.0151, 1.0439, 1.0864, 1.3652,
                      1.6934, 1.1240, 1.0571, 1.0073, 0.9897, 1.0063, 1.0000, 1.0566, 1.0645, 1.3701,
                      1.7744, 1.1777, 1.0615, 1.0361, 1.0078, 1.0020, 1.0244, 1.0508, 1.0894, 1.4380,
                      1.8892, 1.2188, 1.0723, 1.0410, 1.0049, 1.0103, 1.0142, 1.0493, 1.1025, 1.5107,
                      2.2954, 1.3311, 1.1118, 1.0708, 1.0186, 1.0186, 1.0469, 1.0649, 1.1738, 1.6426,
                      3.2813, 1.4907, 1.2451, 1.0752, 1.0674, 1.0234, 1.0786, 1.1016, 1.3066, 2.0259,
                    },
         		},
         		/* para 4 */
         		{
                   	0.500000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.0571, 1.5801, 1.3872, 1.1582, 1.1074, 1.1167, 1.1367, 1.2324, 1.4136, 2.3062,
                      2.6206, 1.4556, 1.2192, 1.1182, 1.0635, 1.0615, 1.0884, 1.1260, 1.2690, 1.8110,
                      2.0903, 1.3584, 1.1519, 1.0879, 1.0371, 1.0405, 1.0581, 1.1182, 1.2051, 1.6563,
                      1.9482, 1.2681, 1.1362, 1.0615, 1.0132, 1.0088, 1.0405, 1.0825, 1.1670, 1.5308,
                      1.8433, 1.2446, 1.1138, 1.0435, 1.0068, 1.0010, 1.0215, 1.0874, 1.1548, 1.4819,
                      1.8638, 1.2437, 1.1211, 1.0493, 0.9990, 0.9985, 1.0229, 1.0874, 1.1455, 1.4814,
                      1.9146, 1.2754, 1.1294, 1.0708, 1.0107, 1.0195, 1.0371, 1.0947, 1.1606, 1.5342,
                      2.1118, 1.3252, 1.1602, 1.0835, 1.0317, 1.0313, 1.0488, 1.1099, 1.1895, 1.6143,
                      2.4585, 1.4434, 1.1992, 1.1162, 1.0552, 1.0405, 1.0854, 1.1196, 1.2583, 1.7998,
                      3.5869, 1.6157, 1.3730, 1.1514, 1.1216, 1.0869, 1.1519, 1.1924, 1.4204, 2.1289,
                      3.8154, 1.4814, 1.2793, 1.1030, 1.0693, 1.0791, 1.1001, 1.1245, 1.3809, 2.1230,
                      2.4321, 1.3438, 1.1606, 1.0640, 1.0415, 1.0337, 1.0659, 1.0903, 1.1943, 1.7437,
                      1.9727, 1.2769, 1.0913, 1.0591, 1.0225, 1.0215, 1.0347, 1.0542, 1.1499, 1.5288,
                      1.8325, 1.1831, 1.0942, 1.0400, 1.0078, 1.0010, 1.0332, 1.0688, 1.1089, 1.4819,
                      1.7173, 1.1729, 1.0635, 1.0200, 1.0024, 0.9946, 1.0161, 1.0542, 1.1089, 1.3877,
                      1.7485, 1.1582, 1.0869, 1.0225, 1.0024, 1.0000, 1.0127, 1.0693, 1.0923, 1.4180,
                      1.7871, 1.2041, 1.0723, 1.0493, 1.0029, 1.0078, 1.0205, 1.0615, 1.1055, 1.4424,
                      2.0010, 1.2354, 1.1133, 1.0586, 1.0117, 1.0234, 1.0283, 1.0703, 1.1274, 1.5313,
                      2.3086, 1.3574, 1.1372, 1.0786, 1.0415, 1.0254, 1.0581, 1.0786, 1.1987, 1.6865,
                      3.3818, 1.4888, 1.2949, 1.0991, 1.0664, 1.0708, 1.0835, 1.1465, 1.3037, 2.0596,
                      3.7031, 1.3970, 1.2764, 1.0620, 1.0581, 1.0527, 1.0811, 1.0986, 1.3506, 2.0625,
                      2.3340, 1.3335, 1.1064, 1.0605, 1.0264, 1.0186, 1.0615, 1.0576, 1.1821, 1.6934,
                      1.9346, 1.2363, 1.0703, 1.0425, 1.0127, 1.0063, 1.0273, 1.0449, 1.1152, 1.5127,
                      1.7378, 1.1558, 1.0635, 1.0190, 0.9985, 1.0083, 1.0225, 1.0439, 1.0977, 1.4131,
                      1.6572, 1.1460, 1.0425, 1.0151, 1.0029, 0.9907, 1.0151, 1.0439, 1.0864, 1.3652,
                      1.6934, 1.1240, 1.0571, 1.0073, 0.9897, 1.0063, 1.0000, 1.0566, 1.0645, 1.3701,
                      1.7744, 1.1777, 1.0615, 1.0361, 1.0078, 1.0020, 1.0244, 1.0508, 1.0894, 1.4380,
                      1.8892, 1.2188, 1.0723, 1.0410, 1.0049, 1.0103, 1.0142, 1.0493, 1.1025, 1.5107,
                      2.2954, 1.3311, 1.1118, 1.0708, 1.0186, 1.0186, 1.0469, 1.0649, 1.1738, 1.6426,
                      3.2813, 1.4907, 1.2451, 1.0752, 1.0674, 1.0234, 1.0786, 1.1016, 1.3066, 2.0259,
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
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       1,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /*drc_point_size*/
       257,
       /* aec trigger */
       {
          /*aec trigger 1 */
          {
            0.000,
            500.000,
          },
          /*aec trigger 2 */
          {
            0.000,
            0.000,
          },
          /*aec trigger 3 */
          {
            0.000,
            0.000,
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
                     0,16383,16383,16383,16383,16383,16383,16382,16382,16382,16382,16382,16381,16381,16381,16381,16380,16380,16380,16380,16380,16379,16379,16379,16379,
                  16378,16378,16378,16378,16377,16377,16377,16377,16376,16376,16376,16375,16375,16375,16375,16374,16374,16374,16374,16373,16373,16373,16372,16372,16372,
                  16372,16371,16371,16371,16370,16370,16370,16370,16369,16369,16369,16368,16368,16368,16368,16367,16367,16367,16366,16366,16366,16365,16365,16365,16364,
                  16364,16364,16364,16363,16363,16363,16362,16362,16362,16361,16361,16361,16360,16360,16360,16359,16359,16359,16358,16358,16358,16358,16357,16357,16357,
                  16356,16356,16356,16355,16355,16355,16354,16354,16354,16353,16353,16353,16352,16352,16352,16351,16351,16351,16350,16350,16350,16349,16349,16349,16348,
                  16348,16347,16347,16347,16346,16346,16346,16345,16345,16345,16344,16344,16344,16343,16343,16343,16342,16342,16342,16341,16341,16341,16340,16340,16339,
                  16339,16339,16338,16338,16338,16337,16337,16337,16336,16336,16336,16335,16335,16334,16334,16334,16333,16333,16333,16332,16332,16332,16331,16331,16330,
                  16330,16330,16329,16329,16329,16328,16328,16328,16327,16327,16326,16326,16326,16325,16325,16325,16324,16324,16323,16323,16323,16322,16322,16322,16321,
                  16321,16320,16320,16320,16319,16319,16319,16318,16318,16317,16317,16317,16316,16316,16316,16315,16315,16314,16314,16314,16313,16313,16313,16312,16312,
                  16311,16311,16311,16310,16310,16309,16309,16309,16308,16308,16307,16307,16307,16306,16306,16306,16305,16305,16304,16304,16304,16303,16303,16302,16302,
                  16302,16301,16301,16300,16300,16300,16299,
               },
               /* drc_high_LUT_point */
               {
                     0,16299,16191,16071,15944,15811,15674,15534,15391,15245,15098,14950,14800,14649,14497,14345,14192,14039,13886,13733,13580,13427,13275,13122,12971,
                  12819,12669,12519,12369,12221,12073,11926,11780,11635,11490,11347,11204,11063,10923,10783,10645,10508,10372,10237,10103,9971,9839,9709,9580,9452,
                  9325,9199,9075,8952,8830,8709,8590,8472,8355,8239,8124,8011,7899,7788,7678,7570,7462,7356,7251,7148,7045,6944,6844,6745,6647,
                  6550,6455,6360,6267,6175,6084,5994,5905,5818,5731,5646,5561,5478,5396,5315,5234,5155,5077,5000,4924,4849,4775,4702,4630,4559,
                  4488,4419,4351,4283,4217,4151,4087,4023,3960,3898,3837,3776,3717,3658,3600,3543,3487,3432,3377,3323,3270,3218,3166,3115,3065,
                  3016,2967,2919,2872,2826,2780,2734,2690,2646,2603,2560,2518,2477,2436,2396,2357,2318,2280,2242,2205,2168,2132,2097,2062,2027,
                  1994,1960,1927,1895,1863,1832,1801,1771,1741,1711,1683,1654,1626,1598,1571,1544,1518,1492,1467,1442,1417,1393,1369,1345,1322,
                  1299,1277,1255,1233,1212,1191,1170,1150,1130,1110,1091,1072,1053,1035,1017, 999, 981, 964, 947, 931, 914, 898, 882, 867, 851,
                   836, 822, 807, 793, 779, 765, 751, 738, 725, 712, 699, 686, 674, 662, 650, 639, 627, 616, 605, 594, 583, 573, 562, 552, 542,
                   532, 523, 513, 504, 495, 486, 477, 468, 460, 451, 443, 435, 427, 419, 411, 404, 396, 389, 382, 375, 368, 361, 355, 348, 342,
                   335, 329, 323, 317, 311, 305, 300,
               },
               /* saturation */
               160,
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
                //k1, k2 k3
                //1,4,1,
                //1,5,0.9,
                1,6,1,
           },
       },
       /*int auto gen drc talbe enable*/
       1,
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
        		470,
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
            120.000,
          },
          /*aec trigger 2*/
          {
            190.000,
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
                  0,  65, 131, 194, 250, 295, 344, 394, 442, 488, 528, 571, 614, 655, 695, 728, 762, 794, 827, 857, 883, 908, 934, 957, 983,1006,1031,
               1053,1075,1097,1118,1138,1156,1175,1191,1209,1227,1243,1261,1278,1295,1312,1329,1342,1359,1375,1391,1407,1424,1439,1455,1472,1487,1502,
               1519,1533,1547,1560,1576,1588,1602,1617,1631,1647,1660,1674,1690,1703,1716,1733,1745,1758,1770,1786,1798,1810,1824,1836,1847,1858,1872,
               1882,1893,1905,1916,1926,1938,1949,1960,1971,1982,1994,2005,2018,2028,2039,2052,2063,2074,2083,2096,2106,2117,2128,2135,2147,2155,2167,
               2176,2185,2193,2207,2216,2226,2236,2241,2251,2261,2271,2282,2287,2298,2309,2314,2326,2337,2342,2353,2363,2373,2378,2387,2396,2409,2417,
               2424,2435,2442,2452,2461,2468,2478,2488,2496,2505,2513,2521,2529,2537,2545,2553,2561,2570,2578,2586,2594,2602,2610,2618,2626,2634,2642,
               2650,2658,2666,2674,2682,2690,2698,2702,2706,2714,2722,2730,2738,2746,2750,2754,2762,2770,2778,2786,2794,2798,2802,2810,2818,2826,2831,
               2835,2843,2851,2859,2863,2867,2875,2879,2883,2891,2899,2907,2911,2915,2923,2927,2931,2939,2947,2955,2959,2963,2971,2975,2979,2987,2991,
               2995,3003,3007,3011,3019,3023,3027,3035,3039,3043,3051,3055,3059,3067,3071,3075,3083,3088,3092,3096,3100,3104,3108,3116,3120,3124,3132,
               3136,3140,3148,3152,3156,3160,3164,3168,3172,3180,3184,3188,3192,3196,3200,3204,3212,3216,3220,3224,3228,3232,3236,3244,3248,3252,3256,
               3260,3264,3268,3276,3280,3284,3288,3292,3296,3300,3304,3308,3312,3316,3324,3328,3332,3336,3340,3345,3349,3353,3357,3361,3365,3369,3373,
               3377,3381,3385,3389,3393,3397,3401,3405,3409,3413,3417,3421,3425,3429,3433,3437,3441,3445,3449,3453,3457,3461,3465,3469,3473,3477,3481,
               3485,3489,3493,3497,3501,3505,3509,3513,3515,3517,3521,3525,3529,3533,3537,3541,3545,3549,3553,3557,3561,3563,3565,3569,3573,3577,3581,
               3585,3589,3593,3597,3601,3605,3610,3612,3614,3618,3622,3626,3630,3634,3638,3642,3644,3646,3650,3654,3658,3660,3662,3666,3670,3674,3678,
               3682,3686,3690,3692,3694,3698,3702,3706,3708,3710,3714,3718,3722,3724,3726,3730,3734,3738,3740,3742,3746,3750,3754,3756,3758,3762,3766,
               3770,3772,3774,3778,3782,3786,3788,3790,3794,3798,3802,3804,3806,3810,3814,3818,3820,3822,3826,3830,3834,3836,3838,3842,3846,3850,3852,
               3854,3858,3862,3867,3869,3870,3871,3875,3879,3883,3885,3887,3891,3895,3899,3901,3903,3907,3911,3915,3917,3918,3919,3923,3927,3931,3933,
               3935,3939,3943,3947,3949,3951,3955,3959,3963,3965,3966,3967,3971,3975,3979,3981,3983,3987,3991,3995,3997,3998,3999,4003,4007,4011,4013,
               4015,4019,4023,4027,4029,4030,4031,4035,4039,4043,4045,4047,4051,4055,4059,4061,4063,4067,4071,4075,4077,4078,4079,4083,4087,4091,4095,
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
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.700000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 3 */
          {
              /* awb tigger 1 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.600000, //saturation
                  0.000000, //hue
              },
          },
          /* aec tigger 4 */
          {
              /* awb tigger 1 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 2 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 3 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 4 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 5 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 6 */
              {
                  0.500000, //saturation
                  0.000000, //hue
              },
              /* awb tigger 7 */
              {
                  0.500000, //saturation
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
       10,
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
		  /* aec trigger 8 */
          {
            128.000,
            128.100,
          },
		  /* aec trigger 9 */
          {
            256.000,
            256.100,
          },
		  /* aec trigger 10 */
          {
            1024.000,
            1024.100,
          },
       },
       /*isp_sub_module_lee_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               80,  //sharpen_pos
               90,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 70, 200, //edge_th 0 ~3
               3, 80, 500, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               75,  //sharpen_pos
               85,  //sharpen_fu
               3,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 70, 200, //edge_th 0 ~3
               3, 80, 500, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 70, 200, //edge_th 0 ~3
               3, 80, 500, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               50,  //sharpen_pos
               60,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 10, 60, 200, //edge_th 0 ~3
               3, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               60,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
               0, 15, 40, 200, //edge_th 0 ~3
               50, 200, 400, 1000, //luma_th 0 ~3
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
               0, 15, 40, 200, //edge_th 0 ~3
               50, 200, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               60,  //sharpen_fu
               25,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
               0, 15, 40, 200, //edge_th 0 ~3
               50, 200, 400, 1000, //luma_th 0 ~3
           },
		   /* parameter 8 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               60,  //sharpen_fu
               25,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
               0, 15, 40, 200, //edge_th 0 ~3
               50, 200, 400, 1000, //luma_th 0 ~3
           },
		   /* parameter 9 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               40,  //sharpen_fu
               35,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 15, 40, 200, //edge_th 0 ~3
               50, 200, 600, 1000, //luma_th 0 ~3
           },
		   /* parameter 10 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               20,  //sharpen_pos
               30,  //sharpen_fu
               50,  //noise_th
               0,  //order_en
               35, //limit_max
               35, //limit_min
               10, 35, 50, 200, //edge_th 0 ~3
               200, 300, 400, 1000, //luma_th 0 ~3
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
          /* para 3 */
          {
             1,  //enable
             3,  //zoom_par
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
          /* para 4 */
          {
             1,  //enable
             4,  //zoom_par
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
          /* para 5 */
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
          /* para 8 */
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
                   147,120,103,91,81,73,67,61,56,51,47,43,39,36,33,30,27,25,22,20,18,16,14,12,10,9,7,5,4,2,1,0,
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
                   180,147,126,111,99,90,82,74,68,62,57,53,48,44,40,37,34,31,28,25,22,20,17,15,13,11,8,6,5,3,1,0,
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
                   246,200,172,152,136,123,111,102,93,85,78,72,66,60,55,51,46,42,38,34,30,27,24,20,17,15,12,9,6,4,1,0,
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
                   311,254,218,192,172,155,141,129,118,108,99,91,84,77,70,64,58,53,48,43,39,34,30,26,22,19,15,12,8,5,2,0,
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
                   656,535,460,406,363,328,298,272,249,228,209,192,177,162,148,136,124,112,102,92,82,73,64,55,47,40,32,25,18,11,5,0,
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
                   985,803,690,609,545,492,447,408,373,343,314,289,265,243,223,204,186,169,153,138,123,109,96,83,71,60,48,37,27,17,7,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               300, //th222
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
                   1641,1338,1151,1015,908,820,745,680,623,600,600,600,600,600,600,600,600,580,550,550,550,500,480,450,400,350,320,280,250,28,12,0,
               },
               1, //big_5x5_revised_enable
               31, //cur_pix_factor
               300, //th222
               //noise_profile[8]
               {
                   1,2,3,4,8,8,8,8,
               },
           },
       },
    },
    //isp_sub_module_dithering_tuning_t isp_sub_module_dithering_tuning;
    {
    },
  /* ceva hdr */
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
                0,
                400,
            },
            /*trigger 2*/
            {
                0,
                400,
            },
            /*trigger 3*/
            {
                0,
                400,
            },
            /*trigger 4*/
            {
                0,
                400,
            },
        },
        /* isp_sub_module_ceva_vfe_pra pra[MIDDLE_TRIGGER_COUNT];*/
        {
            //pra0
            {
                240,
                240,
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
                //5,
                1,
                /* int inter_en;*/
                1,
                /*enable low gain clamp*/
                0,
                /*drc_lut_pra_t drc_lut_pra[DRC_LUT_PRA_TALBE_SIZE];*/
                {
                    {121, 1<<13, 1, 4, 1, 0.05, 0.2},
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
        350,
        /* ev0_count */
        350,
        /* ev2_count */
        350,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        100,
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
          {256,  349  },        /* Gain= 1.000000 Exposure Index= 188 */
          {256,  360  },        /* Gain= 1.000000 Exposure Index= 189 */
          {256,  371  },        /* Gain= 1.000000 Exposure Index= 190 */
          {256,  383  },        /* Gain= 1.000000 Exposure Index= 191 */
          {256,  395  },        /* Gain= 1.000000 Exposure Index= 192 */
          {256,  407  },        /* Gain= 1.000000 Exposure Index= 193 */
          {256,  420  },        /* Gain= 1.000000 Exposure Index= 194 */
          {256,  433  },        /* Gain= 1.000000 Exposure Index= 195 */
          {256,  446  },        /* Gain= 1.000000 Exposure Index= 196 */
          {256,  460  },        /* Gain= 1.000000 Exposure Index= 197 */
          {256,  474  },        /* Gain= 1.000000 Exposure Index= 198 */
          {256,  489  },        /* Gain= 1.000000 Exposure Index= 199 */
          {256,  504  },        /* Gain= 1.000000 Exposure Index= 200 */
          {256,  520  },        /* Gain= 1.000000 Exposure Index= 201 */
          {256,  536  },        /* Gain= 1.000000 Exposure Index= 202 */
          {256,  553  },        /* Gain= 1.000000 Exposure Index= 203 */
          {256,  570  },        /* Gain= 1.000000 Exposure Index= 204 */
          {256,  588  },        /* Gain= 1.000000 Exposure Index= 205 */
          {256,  606  },        /* Gain= 1.000000 Exposure Index= 206 */
          {256,  625  },        /* Gain= 1.000000 Exposure Index= 207 */
          {256,  644  },        /* Gain= 1.000000 Exposure Index= 208 */
          {256,  664  },        /* Gain= 1.000000 Exposure Index= 209 */
          {256,  684  },        /* Gain= 1.000000 Exposure Index= 210 */
          {256,  705  },        /* Gain= 1.000000 Exposure Index= 211 */
          {256,  727  },        /* Gain= 1.000000 Exposure Index= 212 */
          {256,  749  },        /* Gain= 1.000000 Exposure Index= 213 */
          {256,  772  },        /* Gain= 1.000000 Exposure Index= 214 */
          {256,  796  },        /* Gain= 1.000000 Exposure Index= 215 */
          {264,  796  },        /* Gain= 1.031250 Exposure Index= 216 */
          {272,  796  },        /* Gain= 1.062500 Exposure Index= 217 */
          {281,  796  },        /* Gain= 1.097656 Exposure Index= 218 */
          {290,  796  },        /* Gain= 1.132813 Exposure Index= 219 */
          {299,  796  },        /* Gain= 1.167969 Exposure Index= 220 */
          {308,  796  },        /* Gain= 1.203125 Exposure Index= 221 */
          {318,  796  },        /* Gain= 1.242188 Exposure Index= 222 */
          {328,  796  },        /* Gain= 1.281250 Exposure Index= 223 */
          {338,  796  },        /* Gain= 1.320313 Exposure Index= 224 */
          {349,  796  },        /* Gain= 1.363281 Exposure Index= 225 */
          {360,  796  },        /* Gain= 1.406250 Exposure Index= 226 */
          {371,  796  },        /* Gain= 1.449219 Exposure Index= 227 */
          {383,  796  },        /* Gain= 1.496094 Exposure Index= 228 */
          {395,  796  },        /* Gain= 1.542969 Exposure Index= 229 */
          {407,  796  },        /* Gain= 1.589844 Exposure Index= 230 */
          {420,  796  },        /* Gain= 1.640625 Exposure Index= 231 */
          {433,  796  },        /* Gain= 1.691406 Exposure Index= 232 */
          {446,  796  },        /* Gain= 1.742188 Exposure Index= 233 */
          {460,  796  },        /* Gain= 1.796875 Exposure Index= 234 */
          {474,  796  },        /* Gain= 1.851563 Exposure Index= 235 */
          {489,  796  },        /* Gain= 1.910156 Exposure Index= 236 */
          {504,  796  },        /* Gain= 1.968750 Exposure Index= 237 */
          {520,  796  },        /* Gain= 2.031250 Exposure Index= 238 */
          {536,  796  },        /* Gain= 2.093750 Exposure Index= 239 */
          {553,  796  },        /* Gain= 2.160156 Exposure Index= 240 */
          {570,  796  },        /* Gain= 2.226563 Exposure Index= 241 */
          {588,  796  },        /* Gain= 2.296875 Exposure Index= 242 */
          {606,  796  },        /* Gain= 2.367188 Exposure Index= 243 */
          {625,  796  },        /* Gain= 2.441406 Exposure Index= 244 */
          {644,  796  },        /* Gain= 2.515625 Exposure Index= 245 */
          {664,  796  },        /* Gain= 2.593750 Exposure Index= 246 */
          {684,  796  },        /* Gain= 2.671875 Exposure Index= 247 */
          {705,  796  },        /* Gain= 2.753906 Exposure Index= 248 */
          {727,  796  },        /* Gain= 2.839844 Exposure Index= 249 */
          {749,  796  },        /* Gain= 2.925781 Exposure Index= 250 */
          {772,  796  },        /* Gain= 3.015625 Exposure Index= 251 */
          {796,  796  },        /* Gain= 3.109375 Exposure Index= 252 */
          {820,  796  },        /* Gain= 3.203125 Exposure Index= 253 */
          {845,  796  },        /* Gain= 3.300781 Exposure Index= 254 */
          {871,  796  },        /* Gain= 3.402344 Exposure Index= 255 */
          {898,  796  },        /* Gain= 3.507813 Exposure Index= 256 */
          {925,  796  },        /* Gain= 3.613281 Exposure Index= 257 */
          {953,  796  },        /* Gain= 3.722656 Exposure Index= 258 */
          {982,  796  },        /* Gain= 3.835938 Exposure Index= 259 */
          {1012,  796  },        /* Gain= 3.953125 Exposure Index= 260 */
          {1043,  796  },        /* Gain= 4.074219 Exposure Index= 261 */
          {1075,  796  },        /* Gain= 4.199219 Exposure Index= 262 */
          {1108,  796  },        /* Gain= 4.328125 Exposure Index= 263 */
          {1142,  796  },        /* Gain= 4.460938 Exposure Index= 264 */
          {1177,  796  },        /* Gain= 4.597656 Exposure Index= 265 */
          {1213,  796  },        /* Gain= 4.738281 Exposure Index= 266 */
          {1250,  796  },        /* Gain= 4.882813 Exposure Index= 267 */
          {1288,  796  },        /* Gain= 5.031250 Exposure Index= 268 */
          {1327,  796  },        /* Gain= 5.183594 Exposure Index= 269 */
          {1367,  796  },        /* Gain= 5.339844 Exposure Index= 270 */
          {1409,  796  },        /* Gain= 5.503906 Exposure Index= 271 */
          {1452,  796  },        /* Gain= 5.671875 Exposure Index= 272 */
          {1496,  796  },        /* Gain= 5.843750 Exposure Index= 273 */
          {1541,  796  },        /* Gain= 6.019531 Exposure Index= 274 */
          {1588,  796  },        /* Gain= 6.203125 Exposure Index= 275 */
          {1636,  796  },        /* Gain= 6.390625 Exposure Index= 276 */
          {1686,  796  },        /* Gain= 6.585938 Exposure Index= 277 */
          {1737,  796  },        /* Gain= 6.785156 Exposure Index= 278 */
          {1790,  796  },        /* Gain= 6.992188 Exposure Index= 279 */
          {1844,  796  },        /* Gain= 7.203125 Exposure Index= 280 */
          {1900,  796  },        /* Gain= 7.421875 Exposure Index= 281 */
          {1957,  796  },        /* Gain= 7.644531 Exposure Index= 282 */
          {2016,  796  },        /* Gain= 7.875000 Exposure Index= 283 */
          {2077,  796  },        /* Gain= 8.113281 Exposure Index= 284 */
          {2140,  796  },        /* Gain= 8.359375 Exposure Index= 285 */
          {2205,  796  },        /* Gain= 8.613281 Exposure Index= 286 */
          {2272,  796  },        /* Gain= 8.875000 Exposure Index= 287 */
          {2341,  796  },        /* Gain= 9.144531 Exposure Index= 288 */
          {2412,  796  },        /* Gain= 9.421875 Exposure Index= 289 */
          {2485,  796  },        /* Gain= 9.707031 Exposure Index= 290 */
          {2560,  796  },        /* Gain= 10.000000 Exposure Index= 291 */
          {2637,  796  },        /* Gain= 10.300781 Exposure Index= 292 */
          {2717,  796  },        /* Gain= 10.613281 Exposure Index= 293 */
          {2799,  796  },        /* Gain= 10.933594 Exposure Index= 294 */
          {2883,  796  },        /* Gain= 11.261719 Exposure Index= 295 */
          {2970,  796  },        /* Gain= 11.601563 Exposure Index= 296 */
          {3060,  796  },        /* Gain= 11.953125 Exposure Index= 297 */
          {3152,  796  },        /* Gain= 12.312500 Exposure Index= 298 */
          {3247,  796  },        /* Gain= 12.683594 Exposure Index= 299 */
          {3345,  796  },        /* Gain= 13.066406 Exposure Index= 300 */
          {3446,  796  },        /* Gain= 13.460938 Exposure Index= 301 */
          {3550,  796  },        /* Gain= 13.867188 Exposure Index= 302 */
          {3657,  796  },        /* Gain= 14.285156 Exposure Index= 303 */
          {3767,  796  },        /* Gain= 14.714844 Exposure Index= 304 */
          {3881,  796  },        /* Gain= 15.160156 Exposure Index= 305 */
          {3998,  796  },        /* Gain= 15.617188 Exposure Index= 306 */
          {4118,  796  },        /* Gain= 16.085938 Exposure Index= 307 */
          {4242,  796  },        /* Gain= 16.570313 Exposure Index= 308 */
          {4370,  796  },        /* Gain= 17.070313 Exposure Index= 309 */
          {4502,  796  },        /* Gain= 17.585938 Exposure Index= 310 */
          {4638,  796  },        /* Gain= 18.117188 Exposure Index= 311 */
          {4778,  796  },        /* Gain= 18.664063 Exposure Index= 312 */
          {4922,  796  },        /* Gain= 19.226563 Exposure Index= 313 */
          {5070,  796  },        /* Gain= 19.804688 Exposure Index= 314 */
          {5223,  796  },        /* Gain= 20.402344 Exposure Index= 315 */
          {5380,  796  },        /* Gain= 21.015625 Exposure Index= 316 */
          {5542,  796  },        /* Gain= 21.648438 Exposure Index= 317 */
          {5709,  796  },        /* Gain= 22.300781 Exposure Index= 318 */
          {5881,  796  },        /* Gain= 22.972656 Exposure Index= 319 */
          {6058,  796  },        /* Gain= 23.664063 Exposure Index= 320 */
          {6240,  796  },        /* Gain= 24.375000 Exposure Index= 321 */
          {6428,  796  },        /* Gain= 25.109375 Exposure Index= 322 */
          {6621,  796  },        /* Gain= 25.863281 Exposure Index= 323 */
          {6820,  796  },        /* Gain= 26.640625 Exposure Index= 324 */
          {7025,  796  },        /* Gain= 27.441406 Exposure Index= 325 */
          {7236,  796  },        /* Gain= 28.265625 Exposure Index= 326 */
          {7454,  796  },        /* Gain= 29.117188 Exposure Index= 327 */
          {7678,  796  },        /* Gain= 29.992188 Exposure Index= 328 */
          {7909,  796  },        /* Gain= 30.894531 Exposure Index= 329 */
          {8147,  796  },        /* Gain= 31.824219 Exposure Index= 330 */
          {8392,  796  },        /* Gain= 32.781250 Exposure Index= 331 */
          {8644,  796  },        /* Gain= 33.765625 Exposure Index= 332 */
          {8904,  796  },        /* Gain= 34.781250 Exposure Index= 333 */
          {9172,  796  },        /* Gain= 35.828125 Exposure Index= 334 */
          {9448,  796  },        /* Gain= 36.906250 Exposure Index= 335 */
          {9732,  796  },        /* Gain= 38.015625 Exposure Index= 336 */
          {10024,  796  },        /* Gain= 39.156250 Exposure Index= 337 */
          {10325,  796  },        /* Gain= 40.332031 Exposure Index= 338 */
          {10635,  796  },        /* Gain= 41.542969 Exposure Index= 339 */
          {10955,  796  },        /* Gain= 42.792969 Exposure Index= 340 */
          {11284,  796  },        /* Gain= 44.078125 Exposure Index= 341 */
          {11623,  796  },        /* Gain= 45.402344 Exposure Index= 342 */
          {11972,  796  },        /* Gain= 46.765625 Exposure Index= 343 */
          {12332,  796  },        /* Gain= 48.171875 Exposure Index= 344 */
          {12702,  796  },        /* Gain= 49.617188 Exposure Index= 345 */
          {13084,  796  },        /* Gain= 51.109375 Exposure Index= 346 */
          {13477,  796  },        /* Gain= 52.644531 Exposure Index= 347 */
          {13882,  796  },        /* Gain= 54.226563 Exposure Index= 348 */
          {14299,  796  },        /* Gain= 55.855469 Exposure Index= 349 */
          {14728,  796  },        /* Gain= 57.531250 Exposure Index= 350 */
          {15170,  796  },        /* Gain= 59.257813 Exposure Index= 351 */
          {15626,  796  },        /* Gain= 61.039063 Exposure Index= 352 */
          {16095,  796  },        /* Gain= 62.871094 Exposure Index= 353 */
          {16578,  796  },        /* Gain= 64.757813 Exposure Index= 354 */
          {17076,  796  },        /* Gain= 66.703125 Exposure Index= 355 */
          {17589,  796  },        /* Gain= 68.707031 Exposure Index= 356 */
          {18117,  796  },        /* Gain= 70.769531 Exposure Index= 357 */
          {18661,  796  },        /* Gain= 72.894531 Exposure Index= 358 */
          {19221,  796  },        /* Gain= 75.082031 Exposure Index= 359 */
          {19798,  796  },        /* Gain= 77.335938 Exposure Index= 360 */
          {20392,  796  },        /* Gain= 79.656250 Exposure Index= 361 */
          {21004,  796  },        /* Gain= 82.046875 Exposure Index= 362 */
          {21635,  796  },        /* Gain= 84.511719 Exposure Index= 363 */
          {22285,  796  },        /* Gain= 87.050781 Exposure Index= 364 */
          {22954,  796  },        /* Gain= 89.664063 Exposure Index= 365 */
          {23643,  796  },        /* Gain= 92.355469 Exposure Index= 366 */
          {24353,  796  },        /* Gain= 95.128906 Exposure Index= 367 */
          {25084,  796  },        /* Gain= 97.984375 Exposure Index= 368 */
        },
        /* enable short exp table */
        1,
        /* exp_table_short */
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
          {265,  67  },        /* Gain= 1.035156 Exposure Index= 136 */
          {273,  67  },        /* Gain= 1.066406 Exposure Index= 137 */
          {282,  67  },        /* Gain= 1.101563 Exposure Index= 138 */
          {291,  67  },        /* Gain= 1.136719 Exposure Index= 139 */
          {300,  67  },        /* Gain= 1.171875 Exposure Index= 140 */
          {309,  67  },        /* Gain= 1.207031 Exposure Index= 141 */
          {319,  67  },        /* Gain= 1.246094 Exposure Index= 142 */
          {329,  67  },        /* Gain= 1.285156 Exposure Index= 143 */
          {339,  67  },        /* Gain= 1.324219 Exposure Index= 144 */
          {350,  67  },        /* Gain= 1.367188 Exposure Index= 145 */
          {361,  67  },        /* Gain= 1.410156 Exposure Index= 146 */
          {372,  67  },        /* Gain= 1.453125 Exposure Index= 147 */
          {384,  67  },        /* Gain= 1.500000 Exposure Index= 148 */
          {396,  67  },        /* Gain= 1.546875 Exposure Index= 149 */
          {408,  67  },        /* Gain= 1.593750 Exposure Index= 150 */
          {421,  67  },        /* Gain= 1.644531 Exposure Index= 151 */
          {434,  67  },        /* Gain= 1.695313 Exposure Index= 152 */
          {448,  67  },        /* Gain= 1.750000 Exposure Index= 153 */
          {462,  67  },        /* Gain= 1.804688 Exposure Index= 154 */
          {476,  67  },        /* Gain= 1.859375 Exposure Index= 155 */
          {491,  67  },        /* Gain= 1.917969 Exposure Index= 156 */
          {506,  67  },        /* Gain= 1.976563 Exposure Index= 157 */
          {522,  67  },        /* Gain= 2.039063 Exposure Index= 158 */
          {538,  67  },        /* Gain= 2.101563 Exposure Index= 159 */
          {555,  67  },        /* Gain= 2.167969 Exposure Index= 160 */
          {572,  67  },        /* Gain= 2.234375 Exposure Index= 161 */
          {590,  67  },        /* Gain= 2.304688 Exposure Index= 162 */
          {608,  67  },        /* Gain= 2.375000 Exposure Index= 163 */
          {627,  67  },        /* Gain= 2.449219 Exposure Index= 164 */
          {646,  67  },        /* Gain= 2.523438 Exposure Index= 165 */
          {666,  67  },        /* Gain= 2.601563 Exposure Index= 166 */
          {686,  67  },        /* Gain= 2.679688 Exposure Index= 167 */
          {707,  67  },        /* Gain= 2.761719 Exposure Index= 168 */
          {729,  67  },        /* Gain= 2.847656 Exposure Index= 169 */
          {751,  67  },        /* Gain= 2.933594 Exposure Index= 170 */
          {774,  67  },        /* Gain= 3.023438 Exposure Index= 171 */
          {798,  67  },        /* Gain= 3.117188 Exposure Index= 172 */
          {822,  67  },        /* Gain= 3.210938 Exposure Index= 173 */
          {847,  67  },        /* Gain= 3.308594 Exposure Index= 174 */
          {873,  67  },        /* Gain= 3.410156 Exposure Index= 175 */
          {900,  67  },        /* Gain= 3.515625 Exposure Index= 176 */
          {927,  67  },        /* Gain= 3.621094 Exposure Index= 177 */
          {955,  67  },        /* Gain= 3.730469 Exposure Index= 178 */
          {984,  67  },        /* Gain= 3.843750 Exposure Index= 179 */
          {1014,  67  },        /* Gain= 3.960938 Exposure Index= 180 */
          {1045,  67  },        /* Gain= 4.082031 Exposure Index= 181 */
          {1077,  67  },        /* Gain= 4.207031 Exposure Index= 182 */
          {1110,  67  },        /* Gain= 4.335938 Exposure Index= 183 */
          {1144,  67  },        /* Gain= 4.468750 Exposure Index= 184 */
          {1179,  67  },        /* Gain= 4.605469 Exposure Index= 185 */
          {1215,  67  },        /* Gain= 4.746094 Exposure Index= 186 */
          {1252,  67  },        /* Gain= 4.890625 Exposure Index= 187 */
          {1290,  67  },        /* Gain= 5.039063 Exposure Index= 188 */
          {1329,  67  },        /* Gain= 5.191406 Exposure Index= 189 */
          {1369,  67  },        /* Gain= 5.347656 Exposure Index= 190 */
          {1411,  67  },        /* Gain= 5.511719 Exposure Index= 191 */
          {1454,  67  },        /* Gain= 5.679688 Exposure Index= 192 */
          {1498,  67  },        /* Gain= 5.851563 Exposure Index= 193 */
          {1543,  67  },        /* Gain= 6.027344 Exposure Index= 194 */
          {1590,  67  },        /* Gain= 6.210938 Exposure Index= 195 */
          {1638,  67  },        /* Gain= 6.398438 Exposure Index= 196 */
          {1688,  67  },        /* Gain= 6.593750 Exposure Index= 197 */
          {1739,  67  },        /* Gain= 6.792969 Exposure Index= 198 */
          {1792,  67  },        /* Gain= 7.000000 Exposure Index= 199 */
          {1846,  67  },        /* Gain= 7.210938 Exposure Index= 200 */
          {1902,  67  },        /* Gain= 7.429688 Exposure Index= 201 */
          {1960,  67  },        /* Gain= 7.656250 Exposure Index= 202 */
          {2019,  67  },        /* Gain= 7.886719 Exposure Index= 203 */
          {2080,  67  },        /* Gain= 8.125000 Exposure Index= 204 */
          {2143,  67  },        /* Gain= 8.371094 Exposure Index= 205 */
          {2208,  67  },        /* Gain= 8.625000 Exposure Index= 206 */
          {2275,  67  },        /* Gain= 8.886719 Exposure Index= 207 */
          {2344,  67  },        /* Gain= 9.156250 Exposure Index= 208 */
          {2415,  67  },        /* Gain= 9.433594 Exposure Index= 209 */
          {2488,  67  },        /* Gain= 9.718750 Exposure Index= 210 */
          {2563,  67  },        /* Gain= 10.011719 Exposure Index= 211 */
          {2640,  67  },        /* Gain= 10.312500 Exposure Index= 212 */
          {2720,  67  },        /* Gain= 10.625000 Exposure Index= 213 */
          {2802,  67  },        /* Gain= 10.945313 Exposure Index= 214 */
          {2887,  67  },        /* Gain= 11.277344 Exposure Index= 215 */
          {2974,  67  },        /* Gain= 11.617188 Exposure Index= 216 */
          {3064,  67  },        /* Gain= 11.968750 Exposure Index= 217 */
          {3156,  67  },        /* Gain= 12.328125 Exposure Index= 218 */
          {3251,  67  },        /* Gain= 12.699219 Exposure Index= 219 */
          {3349,  67  },        /* Gain= 13.082031 Exposure Index= 220 */
          {3450,  67  },        /* Gain= 13.476563 Exposure Index= 221 */
          {3554,  67  },        /* Gain= 13.882813 Exposure Index= 222 */
          {3661,  67  },        /* Gain= 14.300781 Exposure Index= 223 */
          {3771,  67  },        /* Gain= 14.730469 Exposure Index= 224 */
          {3885,  67  },        /* Gain= 15.175781 Exposure Index= 225 */
          {4002,  67  },        /* Gain= 15.632813 Exposure Index= 226 */
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
    1,  /* aec_motion_iso_preview */
    512,/* R_WEIGHT */
    1024,/* G_WEIGHT */
    512,/* B_WEIGHT */
    11, /* WT_Q */
    {
      25, /* fast_conv.speed */
      2,  /* fast_conv.luma_tolerance */
      0,  /* fast_conv.frame_skip */
    },
    1, /* metering_type 0:SPOT_METERING,1:CENTER_WEIGHTED,2: SIMPLE_FRAME_AVERAGE*/
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
            1,
            /* enable_hdr_luma_target */
            1,
            /* short_exp_max_index */
            221,
            /* max_exp_ration */
            64,
            /* enable_ration_table */
            1,
            /* ration_table_size */
            9,
            /* over_exp_per_high */
            255,
            /* over_exp_per_low */
            246,
            /* adjust step */
            1,
            /* ration_interp_en */
            1,
            /* ration_table_t ration_table[HDR_RATION_TABLE_SIZE] */
            {
                /*exp_index  ration0 ration1 ration2 ration3 luma_target max_drc_gain min_drc_gain max_drc_gain1 luma_settle_th*/
                {52,    4.000000,   1.000000,   1.000000,   1.000000,   80,   4.000000,   4.000000,   4.000000,   10},
                {76,    4.000000,   1.000000,   1.000000,   1.000000,   78,   4.000000,   4.000000,   4.000000,   10},
                {86,    4.000000,   1.000000,   1.000000,   1.000000,   75,   4.000000,   4.000000,   4.000000,   8},
                {96,    4.000000,   1.000000,   1.000000,   1.000000,   73,   4.000000,   4.000000,   4.000000,   8},
                {110,    6.000000,   1.000000,   1.000000,   1.000000,   70,   6.000000,   6.000000,   6.000000,   6},
                {121,    6.000000,   1.000000,   1.000000,   1.000000,   55,   6.000000,   6.000000,   6.000000,   6},
                {135,    6.000000,   1.000000,   1.000000,   1.000000,   55,   6.000000,   6.000000,   6.000000,   5},
                {180,    6.000000,   1.000000,   1.000000,   1.000000,   55,   6.000000,   6.000000,   6.000000,   5},
                {220,    12.000000,   1.000000,   1.000000,   1.000000,   50,   96.000000,   12.000000,   12.000000,   5},
            },
       /* int over_exp_bin_th;//max 127 min 0 */
             40,
             /*int short_exp_skip_count;*/
       3,
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
       0,
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
            /* enable drc gain advance adjust */
      1,
      /*aec_hdr_fast_param*/
      {
          3, //short_exp_adjust_skip_count
          /*uint32_t interval_threshold[3]*/
          {
            10,  //short_luma_interval_threshold[0]
            20,  //short_luma_interval_threshold[1]
            30,  //short_luma_interval_threshold[2]
          },
          /*float short_luma_speed_ratio[3]*/
          {
            0.95,  /* short_luma_speed_ratio[0] */
            0.80,  /* short_luma_speed_ratio[1] */
            0.75,  /* short_luma_speed_ratio[2] */
          },
          0.70,  /* short_luma_speed_ratio_others */

          0, //drc_gain_adjust_skip_count, could be zero
          /*uint32_t drc_gain_interval_threshold[3] (>1.0)*/
          {
            1.5,  //drc_gain_interval_threshold[0]
            2.0,  //drc_gain_interval_threshold[1]
            2.5,  //drc_gain_interval_threshold[2]
          },
          /*float drc_gain_adjust_ratio[3] (<1)*/
          {
            0.95,  /* drc_gain_adjust_ratio[0] */
            0.80,  /* drc_gain_adjust_ratio[1] */
            0.75,  /* drc_gain_adjust_ratio[2] */
          },
          0.70,  /* drc_gain_adjust_ratio_others */
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
      0, //aec_algo_type : 0-FAST_SMOOTH, 1-FAST_PLUS
      // AEC_FAST_PLUS_PARAM_t aec_fast_plus_param
      {
        2,  /* aec_fast_plus_param.luma_tolerance */
        1,  /* aec_fast_plus_param.frame_skip */
        2,  /* aec_fast_plus_param.ddr_frame_skip_offset : this should be 2 for most situations*/
        /*uint32_t interval_threshold[3]*/
        {
          10,  /* aec_fast_plus_param.interval_threshold[0] */
          20,  /* aec_fast_plus_param.interval_threshold[1] */
          30,  /* aec_fast_plus_param.interval_threshold[2] */
        },
        /*float speed_ratio[3]*/
        {
          0.95,  /* aec_fast_plus_param.speed_ratio[0] */
          0.80,  /* aec_fast_plus_param.speed_ratio[1] */
          0.75,  /* aec_fast_plus_param.speed_ratio[2] */
        },
        0.70,  /* aec_fast_plus_param.speed_ratio_others */
      },
      0, //aec_hdr_algo_type 0-AEC_HDR_ALGO_TYPE_ORG, 1-AEC_HDR_ALGO_TYPE_FAST
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
       { 1.00, 1.00 },   /* cw */   // use tl84 lsc
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
  { /*Exp Index: 0, Outdoor_Index, Inoutdoor_Midpoint, Indoor_index*/
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
    0.50, /* d50_d65_weighted_samaple_boundary */
    0.20, /* blue_sky_pec */
    0.15, /* blue_sky_pec_buffer */
        8,     /* num_of_reference_point */
        0.0064, /* outline */
        570.00, /* white_stat_y_thd_low */
        921.60, /* white_stat_y_thd_high */
        2,      /* dominant_cluster_threshold */
        1,      /* white_stat_cnt_thd */
        0.9,   /* grey_weight_day */
        0.1,   /* white_weight_day */
        0.75,   /* grey_weight_f */
        0.25,   /* white_weight_f */
        0.75,   /* grey_weight_h */
        0.25,   /* white_weight_h */
        1,      /* all_outlier_heuristic_flag */
        0,      /* special_bayer_en */
        0.20,   /* green_threshold */
    0.20, /* threshold_extreme_b_percent */
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

