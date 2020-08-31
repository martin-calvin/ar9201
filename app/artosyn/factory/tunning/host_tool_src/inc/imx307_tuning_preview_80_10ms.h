
/*---------------header of imx307 tuing-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x20191203,
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
                        {40,120,113},
                        //g channel
                        {40,120,113},
                        //b channel
                        {40,120,113},
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
                        {75,225,214},
                        //g channel
                        {75,225,214},
                        //b channel
                        {75,225,214},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {55,165,112},
                        //g channel
                        {55,165,112},
                        //b channel
                        {55,165,112},
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
                1,//denoise_layer
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
            /* para 7 */
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
            /* para 8 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {280,840,809},
                        //g channel
                        {280,840,809},
                        //b channel
                        {280,840,809},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {250,750,515},
                        //g channel
                        {250,750,515},
                        //b channel
                        {250,750,515},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {250,750,515},
                        //g channel
                        {250,750,515},
                        //b channel
                        {250,750,515},
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
                        {420,1260,1215},
                        //g channel
                        {420,1260,1215},
                        //b channel
                        {420,1260,1215},
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
                        {320,960,660},
                        //g channel
                        {320,960,660},
                        //b channel
                        {320,960,660},
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
                        {550,1650,1592},
                        //g channel
                        {550,1650,1592},
                        //b channel
                        {550,1650,1592},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {480,1440,992},
                        //g channel
                        {480,1440,992},
                        //b channel
                        {480,1440,992},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {420,1260,868},
                        //g channel
                        {420,1260,868},
                        //b channel
                        {420,1260,868},
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
                        {700,2100,2027},
                        //g channel
                        {700,2100,2027},
                        //b channel
                        {700,2100,2027},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {650,1950,1344},
                        //g channel
                        {650,1950,1344},
                        //b channel
                        {650,1950,1344},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {600,1800,1240},
                        //g channel
                        {600,1800,1240},
                        //b channel
                        {600,1800,1240},
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
        3,//awb count
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
     			6400,
     			6600,
     		},
     		/*awb trigger 4*/
     		{
     			0,
     			0,
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
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  2.6870, 1.9229, 1.5493, 1.4023, 1.3306, 1.2988, 1.4131, 1.5913, 1.9717, 2.9014, 
					  2.3823, 1.6929, 1.4390, 1.2754, 1.2017, 1.2021, 1.2861, 1.4399, 1.7549, 2.4839, 
					  2.1733, 1.5933, 1.3579, 1.2056, 1.1250, 1.1284, 1.2075, 1.3906, 1.5996, 2.3296, 
					  2.0205, 1.5220, 1.3140, 1.1455, 1.0596, 1.0635, 1.1606, 1.3164, 1.5703, 2.1416, 
					  1.9614, 1.4814, 1.2896, 1.1167, 0.9990, 1.0137, 1.1260, 1.3018, 1.4941, 2.0898, 
					  1.9238, 1.4902, 1.2729, 1.1167, 0.9917, 1.0083, 1.1201, 1.2793, 1.5264, 2.0342, 
					  1.9766, 1.5117, 1.3042, 1.1313, 1.0527, 1.0371, 1.1455, 1.2983, 1.5166, 2.0649, 
					  2.1030, 1.5547, 1.3433, 1.1880, 1.0898, 1.1191, 1.1772, 1.3428, 1.5918, 2.1357, 
					  2.2598, 1.6606, 1.4023, 1.2471, 1.1807, 1.1606, 1.2588, 1.4136, 1.6538, 2.4570, 
					  2.5420, 1.8008, 1.4980, 1.3486, 1.2461, 1.2817, 1.3335, 1.5093, 1.8481, 2.5381, 
					  2.5464, 1.8252, 1.4995, 1.3901, 1.2866, 1.3101, 1.3716, 1.5308, 1.9111, 2.6685, 
					  2.2275, 1.6553, 1.3901, 1.2637, 1.1929, 1.1943, 1.2832, 1.4302, 1.7051, 2.3765, 
					  2.0742, 1.5488, 1.3350, 1.1968, 1.1221, 1.1265, 1.2012, 1.3657, 1.5781, 2.2056, 
					  1.9292, 1.4800, 1.2920, 1.1382, 1.0518, 1.0693, 1.1636, 1.3066, 1.5430, 2.0688, 
					  1.8652, 1.4678, 1.2583, 1.1196, 0.9976, 1.0151, 1.1182, 1.3066, 1.4663, 2.0293, 
					  1.8623, 1.4458, 1.2651, 1.1074, 0.9985, 1.0093, 1.1338, 1.2734, 1.5063, 1.9780, 
					  1.8931, 1.4731, 1.2769, 1.1318, 1.0474, 1.0469, 1.1357, 1.3057, 1.4775, 2.0225, 
					  2.0278, 1.5127, 1.3267, 1.1758, 1.1001, 1.1104, 1.1885, 1.3345, 1.5645, 2.0625, 
					  2.1440, 1.6138, 1.3784, 1.2378, 1.1724, 1.1665, 1.2422, 1.4097, 1.6128, 2.3613, 
					  2.4473, 1.7271, 1.4731, 1.3252, 1.2603, 1.2529, 1.3394, 1.4912, 1.7666, 2.4800, 
					  2.3823, 1.7686, 1.4824, 1.3501, 1.2964, 1.2974, 1.3965, 1.5303, 1.8955, 2.6030, 
					  2.1338, 1.6284, 1.3525, 1.2622, 1.1626, 1.2075, 1.2583, 1.4253, 1.6758, 2.3271, 
					  1.9863, 1.5352, 1.3096, 1.1670, 1.1279, 1.1201, 1.1958, 1.3677, 1.5488, 2.1836, 
					  1.9360, 1.4663, 1.2896, 1.1484, 1.0371, 1.0645, 1.1558, 1.3237, 1.5171, 2.0776, 
					  1.7695, 1.4580, 1.2314, 1.1177, 0.9961, 1.0205, 1.1201, 1.2798, 1.4712, 1.9678, 
					  1.8086, 1.4429, 1.2515, 1.1064, 1.0068, 1.0156, 1.1313, 1.2920, 1.4961, 1.9463, 
					  1.8960, 1.4609, 1.2705, 1.1313, 1.0405, 1.0562, 1.1426, 1.3071, 1.4722, 2.0005, 
					  1.9409, 1.5073, 1.3203, 1.1816, 1.1064, 1.1187, 1.1846, 1.3257, 1.5674, 2.0366, 
					  2.1377, 1.5894, 1.3677, 1.2402, 1.1748, 1.1753, 1.2607, 1.4087, 1.5981, 2.3062, 
					  2.3271, 1.7471, 1.4526, 1.3223, 1.2568, 1.2612, 1.3364, 1.4585, 1.7852, 2.3989, 
					},
				},
				/* para 2 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  2.5850, 1.8701, 1.5337, 1.3745, 1.3101, 1.2813, 1.3931, 1.5508, 1.9717, 2.7979, 
					  2.3052, 1.6953, 1.4165, 1.2710, 1.1987, 1.2100, 1.2783, 1.4478, 1.7295, 2.5039, 
					  2.0972, 1.5972, 1.3564, 1.2007, 1.1255, 1.1196, 1.2036, 1.3511, 1.6035, 2.2607, 
					  2.0127, 1.5249, 1.2993, 1.1494, 1.0571, 1.0708, 1.1553, 1.3311, 1.5503, 2.2075, 
					  1.8984, 1.4897, 1.2827, 1.1133, 1.0034, 1.0156, 1.1279, 1.2896, 1.4819, 2.0776, 
					  1.8774, 1.5083, 1.2598, 1.1191, 0.9946, 1.0015, 1.1172, 1.2739, 1.5166, 2.0283, 
					  1.9429, 1.4922, 1.3105, 1.1245, 1.0439, 1.0518, 1.1343, 1.3027, 1.5073, 2.0635, 
					  1.9839, 1.5688, 1.3271, 1.1807, 1.1001, 1.0996, 1.1904, 1.3291, 1.6099, 2.0723, 
					  2.2349, 1.6182, 1.4194, 1.2344, 1.1523, 1.1621, 1.2417, 1.4194, 1.6519, 2.3774, 
					  2.4150, 1.7725, 1.4805, 1.3481, 1.2808, 1.2720, 1.3955, 1.4980, 1.8481, 2.5039, 
					  2.5415, 1.8149, 1.4912, 1.4033, 1.2656, 1.2910, 1.3789, 1.5132, 1.9136, 2.6855, 
					  2.2109, 1.6343, 1.3906, 1.2539, 1.1953, 1.1948, 1.2773, 1.4272, 1.7026, 2.3726, 
					  2.0625, 1.5498, 1.3325, 1.2002, 1.1108, 1.1299, 1.1982, 1.3652, 1.5771, 2.2148, 
					  1.9385, 1.4702, 1.2905, 1.1353, 1.0488, 1.0649, 1.1592, 1.3208, 1.5269, 2.1108, 
					  1.8433, 1.4609, 1.2617, 1.1143, 1.0049, 1.0220, 1.1196, 1.2974, 1.4727, 2.0083, 
					  1.8516, 1.4575, 1.2603, 1.1113, 0.9893, 1.0112, 1.1255, 1.2871, 1.4937, 1.9951, 
					  1.8848, 1.4663, 1.2822, 1.1255, 1.0513, 1.0527, 1.1396, 1.3037, 1.4854, 2.0278, 
					  1.9995, 1.5083, 1.3281, 1.1685, 1.1016, 1.1108, 1.1836, 1.3267, 1.5640, 2.0205, 
					  2.1475, 1.6089, 1.3730, 1.2402, 1.1572, 1.1719, 1.2437, 1.4209, 1.6138, 2.3604, 
					  2.3491, 1.7183, 1.4712, 1.3042, 1.2568, 1.2715, 1.3394, 1.4785, 1.7798, 2.3975, 
					  2.4766, 1.7686, 1.5117, 1.3784, 1.3105, 1.2852, 1.3706, 1.5186, 1.8535, 2.6226, 
					  2.0879, 1.6069, 1.3574, 1.2334, 1.1704, 1.1929, 1.2588, 1.4170, 1.6719, 2.2925, 
					  2.0171, 1.5249, 1.3281, 1.1807, 1.1294, 1.1133, 1.1953, 1.3550, 1.5386, 2.1802, 
					  1.8633, 1.4629, 1.2715, 1.1372, 1.0381, 1.0645, 1.1499, 1.2998, 1.5210, 2.0317, 
					  1.8135, 1.4268, 1.2661, 1.1055, 1.0078, 1.0132, 1.1152, 1.3037, 1.4434, 2.0078, 
					  1.7637, 1.4424, 1.2407, 1.0962, 0.9985, 1.0078, 1.1284, 1.2642, 1.4927, 1.9248, 
					  1.9058, 1.4365, 1.2734, 1.1387, 1.0342, 1.0601, 1.1353, 1.2979, 1.4834, 1.9507, 
					  1.9380, 1.5000, 1.3066, 1.1597, 1.1035, 1.0986, 1.1807, 1.3125, 1.5410, 2.0186, 
					  2.0967, 1.5767, 1.3647, 1.2451, 1.1611, 1.1865, 1.2510, 1.3843, 1.6216, 2.2788, 
					  2.2754, 1.7036, 1.4116, 1.3037, 1.2388, 1.2363, 1.3252, 1.4292, 1.7632, 2.2583, 
					},
				},
				/* para 3 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  2.6758, 1.8975, 1.5498, 1.4053, 1.3096, 1.3130, 1.3984, 1.5620, 1.9478, 2.7881, 
					  2.3257, 1.6855, 1.4160, 1.2661, 1.2021, 1.1958, 1.2788, 1.4336, 1.7300, 2.4033, 
					  2.1616, 1.5781, 1.3560, 1.2134, 1.1191, 1.1338, 1.2065, 1.3804, 1.5928, 2.2715, 
					  2.0122, 1.5107, 1.3003, 1.1426, 1.0591, 1.0596, 1.1631, 1.3145, 1.5396, 2.1191, 
					  1.9185, 1.4844, 1.2695, 1.1279, 0.9897, 1.0210, 1.1162, 1.2891, 1.4956, 2.0088, 
					  1.9229, 1.4712, 1.2690, 1.1157, 0.9946, 1.0073, 1.1299, 1.2817, 1.4961, 2.0190, 
					  1.9355, 1.5059, 1.2852, 1.1406, 1.0454, 1.0430, 1.1499, 1.2876, 1.5210, 2.0103, 
					  2.1260, 1.5215, 1.3540, 1.1812, 1.0972, 1.1152, 1.1821, 1.3374, 1.5718, 2.0894, 
					  2.1841, 1.6426, 1.3838, 1.2412, 1.1709, 1.1670, 1.2520, 1.4116, 1.6328, 2.3853, 
					  2.5024, 1.7554, 1.5156, 1.3340, 1.2744, 1.2695, 1.3535, 1.4829, 1.8262, 2.4897, 
					  2.5313, 1.8140, 1.4902, 1.3711, 1.2900, 1.2837, 1.3643, 1.5259, 1.8916, 2.6396, 
					  2.2134, 1.6245, 1.3799, 1.2524, 1.1938, 1.1855, 1.2822, 1.4189, 1.6914, 2.3350, 
					  2.0586, 1.5483, 1.3257, 1.1943, 1.1167, 1.1279, 1.1968, 1.3623, 1.5659, 2.1958, 
					  1.9199, 1.4717, 1.2822, 1.1357, 1.0625, 1.0576, 1.1611, 1.3096, 1.5215, 2.0332, 
					  1.8477, 1.4580, 1.2485, 1.1226, 0.9927, 1.0171, 1.1260, 1.2949, 1.4712, 1.9932, 
					  1.8696, 1.4438, 1.2583, 1.1074, 0.9971, 1.0044, 1.1279, 1.2715, 1.4873, 1.9443, 
					  1.8945, 1.4688, 1.2715, 1.1323, 1.0513, 1.0474, 1.1421, 1.3066, 1.4775, 1.9775, 
					  1.9985, 1.5156, 1.3223, 1.1763, 1.0986, 1.1113, 1.1841, 1.3242, 1.5498, 2.0273, 
					  2.1689, 1.5942, 1.3691, 1.2373, 1.1631, 1.1699, 1.2451, 1.4053, 1.6011, 2.3008, 
					  2.3789, 1.7349, 1.4600, 1.3174, 1.2603, 1.2441, 1.3203, 1.4731, 1.7515, 2.3579, 
					  2.4038, 1.7432, 1.4824, 1.3262, 1.2798, 1.2549, 1.3896, 1.4600, 1.8960, 2.4683, 
					  2.1060, 1.5747, 1.3716, 1.2334, 1.1836, 1.1978, 1.2627, 1.4209, 1.6421, 2.2656, 
					  1.9648, 1.5269, 1.3135, 1.1816, 1.1113, 1.1162, 1.1929, 1.3403, 1.5601, 2.0913, 
					  1.9072, 1.4526, 1.2788, 1.1382, 1.0464, 1.0654, 1.1606, 1.3115, 1.5098, 2.0029, 
					  1.7559, 1.4365, 1.2500, 1.1113, 0.9971, 1.0195, 1.1152, 1.2910, 1.4521, 1.9541, 
					  1.8003, 1.4463, 1.2471, 1.1152, 1.0010, 1.0103, 1.1357, 1.2739, 1.4893, 1.8843, 
					  1.8535, 1.4375, 1.2739, 1.1226, 1.0400, 1.0596, 1.1387, 1.2925, 1.4678, 1.9209, 
					  1.9600, 1.4873, 1.3218, 1.1772, 1.1040, 1.1216, 1.1787, 1.3247, 1.5322, 1.9697, 
					  2.0601, 1.5708, 1.3652, 1.2324, 1.1680, 1.1782, 1.2480, 1.3901, 1.5889, 2.2217, 
					  2.3315, 1.6582, 1.4590, 1.2793, 1.2549, 1.2529, 1.3232, 1.4526, 1.7510, 2.2520, 
					},
				},
				/* para 4 */
				{
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
    /*isp_sub_module_drc_pra isp_sub_module_drc_tuning;*/
    {
       0, //enable
       1, /*interpolation enable*/
       1, //ae count
       1, //trigger mode : 0 gain trigger 1 lux trigger
       257,//drc_point_size
       /* aec trigger */
       {
             /*trigger 0*/
             {
                 0,
                 340,
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
       /* isp_sub_module_drc_pra pra[MIN_TRIGGER_COUNT] */
       {
            /*para 0*/
            {
                //drc_low_LUT_point
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
                    6132,6132,6132,6132,6132,6132,6131
                },
                //drc_high_LUT_point
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
                       0,   0,   0,   0,   0,   0,   0,//drc_high_LUT_point
                },
                //saturation
                100,
                //fl1
                {
                    3,17,29,17, 3,
                    7,29,46,29, 7,
                    3,17,29,17, 3,
                },
                //fl2
                {
                    12,18,21,18,12,
                    14,21,24,21,14,
                    12,18,21,18,12,
                },
                //fl3
                {
                    14,18,19,18,14,
                    16,19,20,19,16,
                    14,18,19,18,14,
                },
            },
            /*para 1*/
            {
                //drc_low_LUT_point
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
                    6132,6132,6132,6132,6132,6132,6131
                },
                //drc_high_LUT_point
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
                       0,   0,   0,   0,   0,   0,   0,//drc_high_LUT_point
                },
                //saturation
                100,
                //fl1
                {
                    3,17,29,17, 3,
                    7,29,46,29, 7,
                    3,17,29,17, 3,
                },
                //fl2
                {
                    12,18,21,18,12,
                    14,21,24,21,14,
                    12,18,21,18,12,
                },
                //fl3
                {
                    14,18,19,18,14,
                    16,19,20,19,16,
                    14,18,19,18,14,
                },
            },
            /*para 2*/
            {
                //drc_low_LUT_point
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
                    6132,6132,6132,6132,6132,6132,6131
                },
                //drc_high_LUT_point
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
                       0,   0,   0,   0,   0,   0,   0,//drc_high_LUT_point
                },
                //saturation
                100,
                //fl1
                {
                    3,17,29,17, 3,
                    7,29,46,29, 7,
                    3,17,29,17, 3,
                },
                //fl2
                {
                    12,18,21,18,12,
                    14,21,24,21,14,
                    12,18,21,18,12,
                },
                //fl3
                {
                    14,18,19,18,14,
                    16,19,20,19,16,
                    14,18,19,18,14,
                },
            },
            /*para 3*/
            {
                //drc_low_LUT_point
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
                    6132,6132,6132,6132,6132,6132,6131
                },
                //drc_high_LUT_point
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
                       0,   0,   0,   0,   0,   0,   0,//drc_high_LUT_point
                },
                //saturation
                100,
                //fl1
                {
                    3,17,29,17, 3,
                    7,29,46,29, 7,
                    3,17,29,17, 3,
                },
                //fl2
                {
                    12,18,21,18,12,
                    14,21,24,21,14,
                    12,18,21,18,12,
                },
                //fl3
                {
                    14,18,19,18,14,
                    16,19,20,19,16,
                    14,18,19,18,14,
                },
            },
            /*para 4*/
            {
                //drc_low_LUT_point
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
                    6132,6132,6132,6132,6132,6132,6131
                },
                //drc_high_LUT_point
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
                       0,   0,   0,   0,   0,   0,   0,//drc_high_LUT_point
                },
                //saturation
                100,
                //fl1
                {
                    3,17,29,17, 3,
                    7,29,46,29, 7,
                    3,17,29,17, 3,
                },
                //fl2
                {
                    12,18,21,18,12,
                    14,21,24,21,14,
                    12,18,21,18,12,
                },
                //fl3
                {
                    14,18,19,18,14,
                    16,19,20,19,16,
                    14,18,19,18,14,
                },
            },
       },
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
        3,//awb count
        1,//trigger_mode : 0 gain trigger 1 lux trigger
      /* aec trigger */
      {
        	/*trigger 0*/
        	{
        		0,
        		460,
        	},
        	/*trigger 1*/
        	{
				495,
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
        		6500,
        		6600,
        	},
        	/*trigger 3*/
        	{
        		6950,
        		7050,
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
                     1.8296, -0.8228, -0.0068,
                     -0.4532, 1.2936, 0.1596,
                     0.3094, -2.0026, 2.6932,
                },
                /* ccm tl84 matrix */
                {
                     1.8250, -0.7258, -0.0992,
                     -0.3755, 1.5473, -0.1718,
                     0.0345, -0.9417, 1.9072,
                },
                /* ccm d50 matrix */
                {
                     1.7664, -0.7932, 0.0268,
                     -0.3577, 1.4874, -0.1297,
                     0.0329, -1.0534, 2.0205,
                },
                /* ccm d65 matrix */
                {
                     1.6680, -0.5234, -0.1445,
                     -0.2828, 1.4727, -0.1859,
                     0.2305, -1.0391, 1.8164,
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
                /* ccm a matrix */
                {
                     1.5765, -0.4980, -0.0782,
                     -0.4232, 1.5227, -0.0995,
                     -0.0556, -0.7619, 1.8175,
                },
                /* ccm tl84 matrix */
                {
                     1.7156, -0.8977, 0.1821,
                     -0.3052, 1.4735, -0.1684,
                     0.2093, -1.2373, 2.0280,
                },
                /* ccm d50 matrix */
                {
                     1.6352, -0.7070, 0.0717,
                     -0.2542, 1.4422, -0.1880,
                     0.2611, -1.5451, 2.2840,
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
          /* lowlight */
          {
                  0,  35,  71, 107, 143, 179, 215, 251, 287, 323, 346, 380, 411, 442, 471, 498, 525, 551, 577, 601, 625, 648, 670, 692, 714, 735, 755,
                775, 795, 814, 833, 852, 870, 888, 906, 923, 940, 957, 974, 990,1007,1022,1038,1054,1069,1084,1099,1114,1129,1143,1157,1171,1185,1199,
               1213,1227,1240,1253,1266,1279,1292,1305,1318,1330,1343,1355,1368,1380,1392,1404,1416,1427,1439,1451,1462,1474,1485,1496,1508,1519,1530,
               1541,1551,1562,1573,1584,1594,1605,1615,1626,1636,1646,1657,1667,1677,1687,1697,1707,1717,1727,1736,1746,1756,1765,1775,1784,1794,1803,
               1813,1822,1831,1840,1850,1859,1868,1877,1886,1895,1904,1913,1921,1930,1939,1948,1956,1965,1974,1982,1991,1999,2008,2016,2024,2033,2041,
               2049,2058,2066,2074,2082,2090,2098,2106,2114,2122,2130,2138,2146,2154,2162,2170,2178,2185,2193,2201,2208,2216,2224,2231,2239,2246,2254,
               2262,2269,2276,2284,2291,2299,2306,2313,2321,2328,2335,2342,2350,2357,2364,2371,2378,2385,2392,2399,2406,2413,2420,2427,2434,2441,2448,
               2455,2462,2469,2476,2482,2489,2496,2503,2510,2516,2523,2530,2536,2543,2550,2556,2563,2569,2576,2582,2589,2595,2602,2608,2615,2621,2628,
               2634,2641,2647,2653,2660,2666,2672,2679,2685,2691,2697,2704,2710,2716,2722,2728,2735,2741,2747,2753,2759,2765,2771,2777,2783,2789,2795,
               2801,2807,2813,2819,2825,2831,2837,2843,2849,2855,2861,2867,2872,2878,2884,2890,2896,2901,2907,2913,2919,2924,2930,2936,2942,2947,2953,
               2959,2964,2970,2976,2981,2987,2992,2998,3004,3009,3015,3020,3026,3031,3037,3042,3048,3053,3059,3064,3070,3075,3081,3086,3091,3097,3102,
               3108,3113,3118,3124,3129,3134,3140,3145,3150,3156,3161,3166,3171,3177,3182,3187,3192,3198,3203,3208,3213,3218,3224,3229,3234,3239,3244,
               3249,3255,3260,3265,3270,3275,3280,3285,3290,3295,3300,3305,3310,3315,3320,3325,3330,3335,3340,3345,3350,3355,3360,3365,3370,3375,3380,
               3385,3390,3395,3400,3404,3409,3414,3419,3424,3429,3434,3438,3443,3448,3453,3458,3462,3467,3472,3477,3482,3486,3491,3496,3501,3505,3510,
               3515,3519,3524,3529,3533,3538,3543,3548,3552,3557,3562,3566,3571,3575,3580,3585,3589,3594,3598,3603,3608,3612,3617,3621,3626,3631,3635,
               3640,3644,3649,3653,3658,3662,3667,3671,3676,3680,3685,3689,3694,3698,3703,3707,3711,3716,3720,3725,3729,3734,3738,3742,3747,3751,3756,
               3760,3764,3769,3773,3778,3782,3786,3791,3795,3799,3804,3808,3812,3817,3821,3825,3829,3834,3838,3842,3847,3851,3855,3859,3864,3868,3872,
               3876,3881,3885,3889,3893,3898,3902,3906,3910,3914,3919,3923,3927,3931,3935,3939,3944,3948,3952,3956,3960,3964,3969,3973,3977,3981,3985,
               3989,3993,3997,4001,4006,4010,4014,4018,4022,4026,4030,4034,4038,4042,4046,4050,4054,4058,4062,4066,4070,4074,4078,4082,4087,4091,4095,
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
            430.000,
            440.000,
          },
          /* aec trigger 3 */
          {
            450.000,
            460.000,
          },
          /* aec trigger 4 */
          {
            480.000,
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
            512.000,
            512.100,
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
               100, //limit_max
               100, //limit_min
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
               68,  //sharpen_pos
               85,  //sharpen_fu
               3,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
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
               65,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
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
               55,  //sharpen_pos
               65,  //sharpen_fu
               8,  //noise_th
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
               50,  //sharpen_pos
               60,  //sharpen_fu
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
               45,  //sharpen_pos
               50,  //sharpen_fu
               20,  //noise_th
               0,  //order_en
               80, //limit_max
               80, //limit_min
               0, 1, 80, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               35,  //sharpen_pos
               40,  //sharpen_fu
               25,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 8 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               40,  //sharpen_fu
               35,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 9 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               35,  //sharpen_fu
               35,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 10 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               10,  //sharpen_pos
               10,  //sharpen_fu
               40,  //noise_th
               0,  //order_en
               30, //limit_max
               30, //limit_min
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
        410,
        /* ev0_count */
        410,
        /* ev2_count */
        410,
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
          {2090,  642  },        /* Gain= 8.164063 Exposure Index= 277 */
          {2153,  642  },        /* Gain= 8.410156 Exposure Index= 278 */
          {2218,  642  },        /* Gain= 8.664063 Exposure Index= 279 */
          {2285,  642  },        /* Gain= 8.925781 Exposure Index= 280 */
          {2354,  642  },        /* Gain= 9.195313 Exposure Index= 281 */
          {2425,  642  },        /* Gain= 9.472656 Exposure Index= 282 */
          {2498,  642  },        /* Gain= 9.757813 Exposure Index= 283 */
          {2573,  642  },        /* Gain= 10.050781 Exposure Index= 284 */
          {2651,  642  },        /* Gain= 10.355469 Exposure Index= 285 */
          {2731,  642  },        /* Gain= 10.667969 Exposure Index= 286 */
          {2813,  642  },        /* Gain= 10.988281 Exposure Index= 287 */
          {2898,  642  },        /* Gain= 11.320313 Exposure Index= 288 */
          {2985,  642  },        /* Gain= 11.660156 Exposure Index= 289 */
          {3075,  642  },        /* Gain= 12.011719 Exposure Index= 290 */
          {3168,  642  },        /* Gain= 12.375000 Exposure Index= 291 */
          {3264,  642  },        /* Gain= 12.750000 Exposure Index= 292 */
          {3362,  642  },        /* Gain= 13.132813 Exposure Index= 293 */
          {3463,  642  },        /* Gain= 13.527344 Exposure Index= 294 */
          {3567,  642  },        /* Gain= 13.933594 Exposure Index= 295 */
          {3675,  642  },        /* Gain= 14.355469 Exposure Index= 296 */
          {3786,  642  },        /* Gain= 14.789063 Exposure Index= 297 */
          {3900,  642  },        /* Gain= 15.234375 Exposure Index= 298 */
          {4017,  642  },        /* Gain= 15.691406 Exposure Index= 299 */
          {4138,  642  },        /* Gain= 16.164063 Exposure Index= 300 */
          {4263,  642  },        /* Gain= 16.652344 Exposure Index= 301 */
          {4391,  642  },        /* Gain= 17.152344 Exposure Index= 302 */
          {4523,  642  },        /* Gain= 17.667969 Exposure Index= 303 */
          {4659,  642  },        /* Gain= 18.199219 Exposure Index= 304 */
          {4799,  642  },        /* Gain= 18.746094 Exposure Index= 305 */
          {4943,  642  },        /* Gain= 19.308594 Exposure Index= 306 */
          {5092,  642  },        /* Gain= 19.890625 Exposure Index= 307 */
          {5245,  642  },        /* Gain= 20.488281 Exposure Index= 308 */
          {5403,  642  },        /* Gain= 21.105469 Exposure Index= 309 */
          {5566,  642  },        /* Gain= 21.742188 Exposure Index= 310 */
          {5733,  642  },        /* Gain= 22.394531 Exposure Index= 311 */
          {5905,  642  },        /* Gain= 23.066406 Exposure Index= 312 */
          {6083,  642  },        /* Gain= 23.761719 Exposure Index= 313 */
          {6144,  655  },        /* Gain= 24.000000 Exposure Index= 314 */
          {6144,  675  },        /* Gain= 24.000000 Exposure Index= 315 */
          {6144,  696  },        /* Gain= 24.000000 Exposure Index= 316 */
          {6144,  717  },        /* Gain= 24.000000 Exposure Index= 317 */
          {6144,  739  },        /* Gain= 24.000000 Exposure Index= 318 */
          {6144,  762  },        /* Gain= 24.000000 Exposure Index= 319 */
          {6144,  785  },        /* Gain= 24.000000 Exposure Index= 320 */
          {6144,  809  },        /* Gain= 24.000000 Exposure Index= 321 */
          {6144,  834  },        /* Gain= 24.000000 Exposure Index= 322 */
          {6144,  860  },        /* Gain= 24.000000 Exposure Index= 323 */
          {6144,  886  },        /* Gain= 24.000000 Exposure Index= 324 */
          {6144,  913  },        /* Gain= 24.000000 Exposure Index= 325 */
          {6144,  941  },        /* Gain= 24.000000 Exposure Index= 326 */
          {6144,  970  },        /* Gain= 24.000000 Exposure Index= 327 */
          {6144,  1000  },        /* Gain= 24.000000 Exposure Index= 328 */
          {6248,  1013  },        /* Gain= 24.406250 Exposure Index= 329 */
          {6436,  1013  },        /* Gain= 25.140625 Exposure Index= 330 */
          {6630,  1013  },        /* Gain= 25.898438 Exposure Index= 331 */
          {6829,  1013  },        /* Gain= 26.675781 Exposure Index= 332 */
          {7034,  1013  },        /* Gain= 27.476563 Exposure Index= 333 */
          {7246,  1013  },        /* Gain= 28.304688 Exposure Index= 334 */
          {7464,  1013  },        /* Gain= 29.156250 Exposure Index= 335 */
          {7688,  1013  },        /* Gain= 30.031250 Exposure Index= 336 */
          {7919,  1013  },        /* Gain= 30.933594 Exposure Index= 337 */
          {8157,  1013  },        /* Gain= 31.863281 Exposure Index= 338 */
          {8402,  1013  },        /* Gain= 32.820313 Exposure Index= 339 */
          {8655,  1013  },        /* Gain= 33.808594 Exposure Index= 340 */
          {8915,  1013  },        /* Gain= 34.824219 Exposure Index= 341 */
          {9183,  1013  },        /* Gain= 35.871094 Exposure Index= 342 */
          {9459,  1013  },        /* Gain= 36.949219 Exposure Index= 343 */
          {9743,  1013  },        /* Gain= 38.058594 Exposure Index= 344 */
          {10036,  1013  },        /* Gain= 39.203125 Exposure Index= 345 */
          {10338,  1013  },        /* Gain= 40.382813 Exposure Index= 346 */
          {10649,  1013  },        /* Gain= 41.597656 Exposure Index= 347 */
          {10969,  1013  },        /* Gain= 42.847656 Exposure Index= 348 */
          {11299,  1013  },        /* Gain= 44.136719 Exposure Index= 349 */
          {11638,  1013  },        /* Gain= 45.460938 Exposure Index= 350 */
          {11988,  1013  },        /* Gain= 46.828125 Exposure Index= 351 */
          {12348,  1013  },        /* Gain= 48.234375 Exposure Index= 352 */
          {12719,  1013  },        /* Gain= 49.683594 Exposure Index= 353 */
          {13101,  1013  },        /* Gain= 51.175781 Exposure Index= 354 */
          {13495,  1013  },        /* Gain= 52.714844 Exposure Index= 355 */
          {13900,  1013  },        /* Gain= 54.296875 Exposure Index= 356 */
          {14317,  1013  },        /* Gain= 55.925781 Exposure Index= 357 */
          {14747,  1013  },        /* Gain= 57.605469 Exposure Index= 358 */
          {15190,  1013  },        /* Gain= 59.335938 Exposure Index= 359 */
          {15646,  1013  },        /* Gain= 61.117188 Exposure Index= 360 */
          {16116,  1013  },        /* Gain= 62.953125 Exposure Index= 361 */
          {16600,  1013  },        /* Gain= 64.843750 Exposure Index= 362 */
          {17098,  1013  },        /* Gain= 66.789063 Exposure Index= 363 */
          {17611,  1013  },        /* Gain= 68.792969 Exposure Index= 364 */
          {18140,  1013  },        /* Gain= 70.859375 Exposure Index= 365 */
          {18685,  1013  },        /* Gain= 72.988281 Exposure Index= 366 */
          {19246,  1013  },        /* Gain= 75.179688 Exposure Index= 367 */
          {19824,  1013  },        /* Gain= 77.437500 Exposure Index= 368 */
          {20419,  1013  },        /* Gain= 79.761719 Exposure Index= 369 */
          {21032,  1013  },        /* Gain= 82.156250 Exposure Index= 370 */
          {21663,  1013  },        /* Gain= 84.621094 Exposure Index= 371 */
          {22313,  1013  },        /* Gain= 87.160156 Exposure Index= 372 */
          {22983,  1013  },        /* Gain= 89.777344 Exposure Index= 373 */
          {23673,  1013  },        /* Gain= 92.472656 Exposure Index= 374 */
          {24384,  1013  },        /* Gain= 95.250000 Exposure Index= 375 */
          {25116,  1013  },        /* Gain= 98.109375 Exposure Index= 376 */
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
        },
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            54,  /* outdoor_luma_target_compensated */
            51,  /* default_luma_target_compensated */
            31,/* low_light.luma_target */
		    80, /* outdoor_index */
		    190, /* indoor_index */
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
		    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
            1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
            1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
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
            0,  /*1: OverExp enable; 0: OverExp disable */
		    245,/* high_luma_region_threshold : OverExp Threshold*/
            /* the ratio table in OverExp condition */
            1.0, //outdoor
            1.0, //indoor
            0.9, //low light
            /*the luma offset to be reduced in OverExp condition */
            15,  //outdoor
            12,  //indoor
            10,  //low light
            /*Max Count Table of OverExp */
            260,  //outdoor
            230,  //indoor
            144,  //low light
            /*Min Count Table of OverExp */
            120,   //outdoor
            100,   //indoor
            60,   //low light
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
                0,  /* enable */
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
			 1,  /* enable */
             70,  /* face luma target */
             0.75,  /* face weight*/
             20,  /* face skip count */
			 0.3, /* filter weight */
			 1, /* en face bright dark region */
			 230, /* bright high th */
			 200, /* bright low th */
			 100, /* dark high th */
			 30, /* dark low th */
			 2,  /* bright high th w */
			 2,  /* bright low th w */
			 2, /* dark high th w */
			 2,  /* dark low th w */
			 1,  /* en face luma cut */
			 200,  /* face luma high */
			 20,  /* face luma low */
			 0, /* enable w dec */
			 1,
			 0.8,
			 0.9,
			 0.95,
			 1,
			 0.01,
			 0.1,
			 0.5,
			 2,
			 1,//face stats
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
					 8,//dark th low
					 20,//dark th high
					 230,//bright th low
					 245,//bright th high
					 4,//dark th low weight
					 2,//dark th high weight
					 0.5,//bright low weight
					 0.3,//bright hight weight
				 },
				 /* para 2 */
				 {
					 140,//lux index
					 5,//dark th low
					 15,//dark th high
					 225,//bright th low
					 235,//bright th high
					 4,//dark th low weight
					 2,//dark th high weight
					 0.4,//bright low weight
					 0.3,//bright hight weight
				 },
				 /* para 3 */
				 {
					 230,//lux index
					 5,//dark th low
					 15,//dark th high
					 225,//bright th low
					 235,//bright th high
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
	9,
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
        { 0.4177, 0.6899 },    /* d75 */
        { 0.4500, 0.6461 },    /* d65 */
        { 0.5187, 0.5496 },    /* d50 */
        { 0.5187, 0.5496 },    /* noon */
        { 0.5067, 0.4083 },    /* cw */
        { 0.5865, 0.4461 },    /* tl84 */
        { 0.8205, 0.3554 },    /* a */
        { 1.0130, 0.3116 },    /* h */
        { 0.4129, 0.6245},    /* custom1 */
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
    	6500,  /* custom1 */
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
    	8,     /* custom_daylight */
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
        9,     /* num_of_reference_point */
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
           0x00000098, /* Green_BGmax */
           0x0000003c, /* Green_BGmin */
           0x00000080, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x0000014d, /* Green_Rmul */
           0x000000ed, /* Green_Bmul */
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
           0x000000b7, /* Green_BGmax */
           0x00000038, /* Green_BGmin */
           0x00000082, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000165, /* Green_Rmul */
           0x000000d7, /* Green_Bmul */
           0x000000c0,	/* extreme B, B/G */	//	D50 0.68
           0x00001480,	/* extreme B, R/G */
           0x00000119,	/* extreme R, R/G */	//	TL84
           0x00001980,	/* extreme R, B/G */
           2, //zoom
    	},
    	{
    	},
  },
},
/*af_tuning_t  af_tuning*/
{

},
