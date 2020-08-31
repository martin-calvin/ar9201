
/*---------------header of imx291 tuing-------------------------*/

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
    /*isp_sub_module_blc_tuning_t isp_sub_module_blc_tuning*/
    {
        /*enable:*/
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
               887,
               892,
               888,
               892,
               271,
               271,
               271,
               271,
           },
           /*parameter 3 */
           {
               910,
               905,
               904,
               906,
               272,
               271,
               271,
               271,
           },
           /*parameter 4 */
           {
               1459,
               1454,
               1455,
               1450,
               282,
               281,
               281,
               281,
           },
           /*parameter 5 */
           {
               2307,
               2322,
               2303,
               2325,
               298,
               299,
               298,
               299,
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
            1,
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
    /* isp_sub_module_rnr_tuning_t isp_sub_module_rnr_tuning*/
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
                        {10,30,26},
                        //g channel
                        {10,30,26},
                        //b channel
                        {10,30,26},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {10,30,18},
                        //g channel
                        {10,30,18},
                        //b channel
                        {10,30,18},
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
            /* para 2 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {20,60,55},
                        //g channel
                        {20,60,55},
                        //b channel
                        {20,60,55},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {20,60,39},
                        //g channel
                        {20,60,39},
                        //b channel
                        {20,60,39},
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
                3,//denoise_layer
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
                        {40,120,80},
                        //g channel
                        {40,120,80},
                        //b channel
                        {40,120,80},
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
            /* para 4 */
            {
                3,//denoise_layer
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
                        {70,210,143},
                        //g channel
                        {70,210,143},
                        //b channel
                        {70,210,143},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {70,210,143},
                        //g channel
                        {70,210,143},
                        //b channel
                        {70,210,143},
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
                        {90,270,184},
                        //g channel
                        {90,270,184},
                        //b channel
                        {90,270,184},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {90,270,184},
                        //g channel
                        {90,270,184},
                        //b channel
                        {90,270,184},
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
                        {115,345,330},
                        //g channel
                        {115,345,330},
                        //b channel
                        {115,345,330},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {115,345,236},
                        //g channel
                        {115,345,236},
                        //b channel
                        {115,345,236},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {115,345,236},
                        //g channel
                        {115,345,236},
                        //b channel
                        {115,345,236},
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
                        {130,390,374},
                        //g channel
                        {130,390,374},
                        //b channel
                        {130,390,374},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {130,390,267},
                        //g channel
                        {130,390,267},
                        //b channel
                        {130,390,267},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {130,390,267},
                        //g channel
                        {130,390,267},
                        //b channel
                        {130,390,267},
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
                        {150,450,432},
                        //g channel
                        {150,450,432},
                        //b channel
                        {150,450,432},
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
                        {200,600,577},
                        //g channel
                        {200,600,577},
                        //b channel
                        {200,600,577},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {200,600,412},
                        //g channel
                        {200,600,412},
                        //b channel
                        {200,600,412},
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
                        {250,750,722},
                        //g channel
                        {250,750,722},
                        //b channel
                        {250,750,722},
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
            /* para 11 */
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
                        {300,900,619},
                        //g channel
                        {300,900,619},
                        //b channel
                        {300,900,619},
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
            /* para 12 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {350,1050,1012},
                        //g channel
                        {350,1050,1012},
                        //b channel
                        {350,1050,1012},
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
                        {350,1050,723},
                        //g channel
                        {350,1050,723},
                        //b channel
                        {350,1050,723},
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
                        {400,1200,1157},
                        //g channel
                        {400,1200,1157},
                        //b channel
                        {400,1200,1157},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {400,1200,826},
                        //g channel
                        {400,1200,826},
                        //b channel
                        {400,1200,826},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {400,1200,826},
                        //g channel
                        {400,1200,826},
                        //b channel
                        {400,1200,826},
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
        5,//awb count
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
       			2500,
       			2800,
       		},
       		/*awb trigger 2*/ //tl84
       		{
       			3500,
       			4200,
       		},
       		/*awb trigger 3*/
       		{
       			4500,
       			5500,
       		},
       		/*awb trigger 4*/
       		{
       			6200,
       			7200,
       		},
       		/*awb trigger 5*/
       		{
       			7500,
       			8000,
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
              /* a */
              {
                  //1
                   	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.3789, 1.1675, 1.4180, 1.1040, 1.0884, 1.0630, 1.0635, 1.1021, 1.2124, 2.0317,
                      2.1030, 1.2930, 1.1572, 1.0850, 1.0659, 1.0571, 1.0737, 1.1255, 1.1958, 1.6089,
                      1.9092, 1.2046, 1.1577, 1.0571, 1.0200, 1.0156, 1.0210, 1.0249, 1.1294, 1.3027,
                      1.5029, 1.2114, 1.0894, 1.0464, 1.0210, 1.0068, 1.0220, 1.0503, 1.0869, 1.4175,
                      1.5347, 1.1899, 1.0869, 1.0430, 1.0122, 1.0083, 1.0127, 1.0674, 1.0664, 1.3691,
                      1.5547, 1.1533, 1.0903, 1.0283, 0.9883, 0.9907, 0.9961, 1.0410, 1.0581, 1.3062,
                      1.5942, 1.1919, 1.0972, 1.0518, 1.0063, 1.0034, 1.0313, 1.0605, 1.0840, 1.3506,
                      1.6831, 1.1909, 1.1064, 1.0474, 1.0107, 1.0010, 1.0254, 1.0513, 1.0884, 1.3613,
                      1.8330, 1.2451, 1.1235, 1.0757, 1.0366, 1.0278, 1.0474, 1.0610, 1.1279, 1.4863,
                      2.1772, 1.3564, 1.1475, 1.1055, 1.0723, 1.0576, 1.0967, 1.0962, 1.2285, 1.6812,
                      4.1450, 1.0708, 1.3433, 1.0454, 1.0410, 1.0283, 1.0039, 1.0581, 1.1182, 1.9541,
                      1.9741, 1.2197, 1.0977, 1.0537, 1.0356, 1.0342, 1.0449, 1.0732, 1.1353, 1.5283,
                      1.8101, 1.1309, 1.1084, 1.0332, 1.0078, 0.9985, 1.0059, 0.9922, 1.0674, 1.2407,
                      1.4312, 1.1299, 1.0464, 1.0259, 1.0093, 1.0044, 1.0137, 1.0181, 1.0322, 1.3403,
                      1.4243, 1.1201, 1.0439, 1.0308, 1.0005, 1.0088, 1.0039, 1.0391, 1.0195, 1.3135,
                      1.4814, 1.0776, 1.0518, 1.0020, 0.9932, 0.9844, 0.9961, 1.0186, 0.9995, 1.2515,
                      1.5068, 1.1177, 1.0630, 1.0332, 1.0073, 1.0073, 1.0210, 1.0361, 1.0337, 1.2817,
                      1.5693, 1.1147, 1.0581, 1.0239, 1.0015, 0.9985, 1.0024, 1.0234, 1.0200, 1.3193,
                      1.7593, 1.1689, 1.0737, 1.0474, 1.0278, 1.0127, 1.0342, 1.0298, 1.0674, 1.4111,
                      2.0117, 1.2925, 1.0835, 1.0688, 1.0459, 1.0425, 1.0645, 1.0469, 1.1641, 1.6333,
                      3.7095, 1.0996, 1.2368, 1.0205, 1.0024, 1.0278, 0.9839, 1.0322, 1.0942, 1.9038,
                      1.9141, 1.1807, 1.0601, 1.0371, 1.0337, 1.0176, 1.0278, 1.0454, 1.1084, 1.4902,
                      1.7173, 1.0947, 1.0796, 1.0137, 0.9971, 0.9912, 1.0054, 0.9658, 1.0488, 1.1987,
                      1.3662, 1.1143, 1.0059, 1.0327, 1.0005, 1.0068, 1.0063, 1.0054, 1.0059, 1.3179,
                      1.4082, 1.0737, 1.0474, 1.0078, 1.0117, 1.0088, 1.0005, 1.0190, 0.9985, 1.2480,
                      1.4321, 1.0532, 1.0288, 1.0112, 0.9927, 0.9946, 0.9961, 1.0063, 0.9907, 1.2148,
                      1.4966, 1.1006, 1.0547, 1.0317, 1.0088, 1.0142, 1.0112, 1.0239, 1.0142, 1.2236,
                      1.5361, 1.0801, 1.0425, 1.0142, 0.9980, 0.9971, 1.0034, 1.0078, 1.0054, 1.2798,
                      1.7002, 1.1548, 1.0557, 1.0356, 1.0313, 1.0044, 1.0225, 1.0098, 1.0474, 1.3604,
                      2.0078, 1.2603, 1.0737, 1.0513, 1.0356, 1.0298, 1.0703, 1.0405, 1.1504, 1.6362, },
              },
              /* tl84 */
              {
                      //1
                     	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                     	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                      {
                        4.1177, 1.0200, 1.3145, 1.0361, 1.0273, 1.0288, 1.0176, 1.0674, 1.1880, 1.9839,
                        1.8242, 1.1538, 1.0396, 1.0200, 1.0107, 1.0181, 1.0361, 1.0806, 1.1426, 1.5615,
                        1.7285, 1.0952, 1.0908, 1.0278, 1.0098, 1.0059, 1.0137, 1.0063, 1.1113, 1.2886,
                        1.3691, 1.0923, 1.0371, 1.0142, 1.0034, 1.0000, 1.0156, 1.0352, 1.0669, 1.3940,
                        1.3882, 1.0835, 1.0444, 1.0171, 1.0029, 1.0063, 1.0083, 1.0391, 1.0503, 1.3247,
                        1.4541, 1.0698, 1.0562, 1.0146, 0.9941, 1.0005, 1.0088, 1.0352, 1.0469, 1.3154,
                        1.4683, 1.0869, 1.0610, 1.0234, 1.0000, 1.0073, 1.0156, 1.0493, 1.0508, 1.3257,
                        1.5483, 1.1030, 1.0605, 1.0337, 1.0049, 1.0044, 1.0278, 1.0322, 1.0723, 1.3618,
                        1.7065, 1.1621, 1.0747, 1.0493, 1.0298, 1.0249, 1.0259, 1.0591, 1.0918, 1.4839,
                        1.9590, 1.2676, 1.0728, 1.0806, 1.0376, 1.0454, 1.0728, 1.0679, 1.2002, 1.6558,
                        3.9126, 0.9922, 1.2827, 0.9980, 0.9990, 1.0073, 0.9824, 1.0444, 1.1367, 1.9082,
                        1.7847, 1.1152, 1.0190, 1.0049, 0.9946, 1.0034, 1.0186, 1.0576, 1.1084, 1.5464,
                        1.6704, 1.0762, 1.0645, 1.0151, 1.0049, 1.0010, 1.0073, 1.0015, 1.0962, 1.2559,
                        1.3262, 1.0737, 1.0063, 1.0107, 0.9922, 0.9922, 1.0103, 1.0117, 1.0396, 1.3706,
                        1.3472, 1.0542, 1.0176, 1.0044, 0.9937, 1.0034, 0.9966, 1.0386, 1.0234, 1.3071,
                        1.3984, 1.0464, 1.0317, 1.0054, 0.9902, 0.9976, 1.0029, 1.0254, 1.0234, 1.2837,
                        1.4204, 1.0527, 1.0317, 1.0083, 0.9922, 1.0000, 1.0068, 1.0327, 1.0347, 1.2930,
                        1.4946, 1.0776, 1.0366, 1.0171, 0.9980, 1.0005, 1.0132, 1.0264, 1.0464, 1.3350,
                        1.6426, 1.1216, 1.0488, 1.0332, 1.0220, 1.0161, 1.0249, 1.0366, 1.0786, 1.4404,
                        1.9014, 1.2368, 1.0415, 1.0488, 1.0303, 1.0234, 1.0547, 1.0488, 1.1729, 1.6533,
                        3.5703, 0.9697, 1.1934, 0.9746, 0.9712, 0.9771, 0.9536, 0.9995, 1.0933, 1.8184,
                        1.7134, 1.0806, 0.9814, 0.9849, 0.9927, 0.9839, 1.0044, 1.0293, 1.0874, 1.4570,
                        1.5840, 1.0283, 1.0396, 0.9946, 0.9956, 0.9868, 0.9995, 0.9692, 1.0596, 1.2251,
                        1.2598, 1.0522, 0.9678, 1.0015, 0.9951, 0.9829, 0.9937, 1.0142, 1.0034, 1.3223,
                        1.2930, 1.0146, 1.0000, 0.9888, 0.9937, 1.0049, 0.9990, 1.0171, 0.9961, 1.2949,
                        1.3579, 0.9995, 1.0127, 1.0015, 0.9893, 1.0068, 1.0015, 1.0186, 1.0068, 1.2432,
                        1.3447, 1.0283, 1.0020, 1.0010, 0.9878, 1.0059, 1.0015, 1.0181, 1.0049, 1.2578,
                        1.4683, 1.0332, 1.0195, 1.0107, 1.0020, 1.0034, 1.0146, 1.0117, 1.0259, 1.3047,
                        1.5986, 1.0918, 1.0112, 1.0195, 1.0073, 1.0024, 1.0229, 1.0068, 1.0625, 1.3691,
                        1.8970, 1.2026, 1.0273, 1.0439, 1.0215, 1.0313, 1.0254, 1.0508, 1.1177, 1.6348,
                      },
           		},
           		/* D50 */
           		{
                    //1
                     	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                     	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                      {
                        4.0952, 1.1001, 1.3145, 1.0571, 1.0430, 1.0010, 1.0371, 1.0596, 1.1460, 1.9468,
                        1.8774, 1.1831, 1.0522, 1.0313, 1.0156, 1.0225, 1.0342, 1.0640, 1.1333, 1.5078,
                        1.7769, 1.1294, 1.1064, 1.0313, 1.0142, 0.9985, 1.0098, 0.9980, 1.0908, 1.2593,
                        1.3936, 1.1294, 1.0444, 1.0269, 1.0068, 1.0015, 1.0146, 1.0264, 1.0503, 1.3721,
                        1.4111, 1.1191, 1.0410, 1.0176, 1.0034, 1.0000, 1.0034, 1.0278, 1.0332, 1.2969,
                        1.4771, 1.0942, 1.0664, 1.0249, 0.9961, 0.9971, 1.0073, 1.0313, 1.0337, 1.2930,
                        1.4990, 1.1089, 1.0571, 1.0244, 0.9946, 1.0039, 1.0195, 1.0264, 1.0474, 1.2734,
                        1.5791, 1.1309, 1.0713, 1.0400, 1.0044, 0.9985, 1.0210, 1.0356, 1.0498, 1.3491,
                        1.7505, 1.1665, 1.0820, 1.0430, 1.0337, 1.0161, 1.0366, 1.0313, 1.0889, 1.4204,
                        2.0322, 1.2930, 1.0874, 1.0742, 1.0249, 1.0381, 1.0557, 1.0781, 1.1714, 1.6729,
                        3.8853, 1.0391, 1.2690, 1.0205, 1.0107, 1.0054, 1.0029, 1.0215, 1.1235, 1.8501,
                        1.8433, 1.1450, 1.0435, 1.0171, 1.0107, 1.0112, 1.0176, 1.0620, 1.1016, 1.5020,
                        1.7056, 1.0967, 1.0718, 1.0254, 1.0000, 0.9985, 1.0132, 0.9814, 1.0796, 1.2256,
                        1.3550, 1.1001, 1.0239, 1.0190, 1.0063, 0.9990, 1.0088, 1.0146, 1.0303, 1.3242,
                        1.3848, 1.0786, 1.0244, 1.0146, 0.9941, 1.0010, 0.9985, 1.0249, 1.0112, 1.2979,
                        1.4390, 1.0620, 1.0425, 1.0137, 0.9951, 1.0029, 1.0073, 1.0239, 1.0151, 1.2559,
                        1.4629, 1.0801, 1.0498, 1.0195, 0.9995, 1.0024, 1.0142, 1.0229, 1.0278, 1.2539,
                        1.5249, 1.0923, 1.0444, 1.0234, 1.0005, 1.0073, 1.0103, 1.0229, 1.0303, 1.3169,
                        1.6968, 1.1470, 1.0601, 1.0410, 1.0308, 1.0127, 1.0347, 1.0313, 1.0718, 1.4077,
                        1.9736, 1.2480, 1.0747, 1.0391, 1.0327, 1.0371, 1.0425, 1.0400, 1.1533, 1.6240,
                        3.5591, 1.0322, 1.2188, 0.9883, 0.9863, 0.9873, 0.9434, 1.0078, 1.0728, 1.8179,
                        1.7832, 1.1064, 1.0024, 0.9985, 0.9814, 0.9995, 1.0049, 1.0190, 1.0825, 1.4253,
                        1.6304, 1.0669, 1.0498, 1.0093, 0.9995, 0.9985, 0.9883, 0.9756, 1.0454, 1.1929,
                        1.3018, 1.0796, 0.9941, 1.0156, 0.9893, 0.9927, 1.0015, 0.9922, 1.0005, 1.2827,
                        1.3481, 1.0356, 1.0063, 0.9995, 0.9941, 1.0063, 0.9966, 1.0137, 0.9932, 1.2603,
                        1.3936, 1.0293, 1.0249, 1.0044, 0.9966, 1.0044, 0.9985, 1.0093, 0.9902, 1.2056,
                        1.4072, 1.0576, 1.0200, 1.0210, 0.9912, 1.0103, 1.0024, 1.0112, 1.0073, 1.2163,
                        1.4912, 1.0542, 1.0234, 1.0068, 1.0024, 1.0005, 1.0044, 1.0078, 1.0063, 1.2651,
                        1.6470, 1.1235, 1.0396, 1.0381, 1.0161, 1.0078, 1.0249, 1.0044, 1.0552, 1.3564,
                        1.9585, 1.1958, 1.0396, 1.0264, 1.0293, 1.0195, 1.0288, 1.0376, 1.1172, 1.5864,
                      },
           		},
           		/* D65 */
           		{
                      //1
                     	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                     	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                      {
                        4.2407, 1.1104, 1.3750, 1.0693, 1.0688, 1.0425, 1.0469, 1.0693, 1.1992, 1.9521,
                        1.9233, 1.2148, 1.0732, 1.0483, 1.0264, 1.0234, 1.0420, 1.0854, 1.1563, 1.5420,
                        1.8511, 1.1558, 1.1377, 1.0479, 1.0234, 1.0107, 1.0264, 1.0156, 1.1260, 1.2964,
                        1.4453, 1.1523, 1.0571, 1.0278, 1.0146, 0.9946, 1.0166, 1.0361, 1.0776, 1.3755,
                        1.4761, 1.1401, 1.0649, 1.0337, 1.0024, 0.9966, 1.0044, 1.0444, 1.0508, 1.3389,
                        1.5112, 1.1162, 1.0786, 1.0244, 0.9956, 1.0029, 1.0093, 1.0469, 1.0581, 1.3154,
                        1.5371, 1.1450, 1.0757, 1.0347, 1.0005, 0.9912, 1.0205, 1.0327, 1.0708, 1.2876,
                        1.6450, 1.1523, 1.0942, 1.0356, 1.0151, 1.0015, 1.0366, 1.0386, 1.1030, 1.3516,
                        1.7661, 1.2129, 1.0996, 1.0625, 1.0366, 1.0186, 1.0444, 1.0527, 1.1133, 1.4595,
                        2.1362, 1.3042, 1.1328, 1.0732, 1.0576, 1.0381, 1.0947, 1.0640, 1.2227, 1.6465,
                        3.8921, 1.0532, 1.2793, 1.0151, 1.0186, 1.0142, 0.9790, 1.0483, 1.1069, 1.8936,
                        1.8271, 1.1401, 1.0322, 1.0107, 1.0020, 0.9961, 1.0200, 1.0400, 1.1113, 1.4746,
                        1.7290, 1.1011, 1.0791, 1.0283, 1.0044, 1.0049, 1.0073, 0.9961, 1.0713, 1.2368,
                        1.3354, 1.0947, 1.0151, 1.0063, 1.0010, 0.9839, 1.0063, 1.0049, 1.0298, 1.3271,
                        1.4028, 1.0723, 1.0244, 1.0142, 0.9907, 1.0059, 0.9941, 1.0273, 1.0112, 1.2915,
                        1.4136, 1.0674, 1.0352, 1.0093, 0.9961, 0.9927, 1.0083, 1.0220, 1.0142, 1.2603,
                        1.4536, 1.0781, 1.0327, 1.0181, 0.9888, 1.0020, 1.0049, 1.0195, 1.0239, 1.2510,
                        1.5347, 1.0928, 1.0469, 1.0225, 1.0049, 1.0024, 1.0122, 1.0322, 1.0317, 1.3154,
                        1.6899, 1.1431, 1.0513, 1.0425, 1.0146, 1.0132, 1.0249, 1.0205, 1.0649, 1.3931,
                        1.9453, 1.2412, 1.0591, 1.0313, 1.0317, 1.0225, 1.0459, 1.0420, 1.1602, 1.6021,
                        3.5894, 1.0400, 1.2090, 1.0015, 0.9946, 0.9648, 0.9790, 0.9780, 1.0938, 1.7681,
                        1.7788, 1.1064, 1.0098, 0.9829, 1.0029, 0.9961, 1.0029, 1.0273, 1.0908, 1.4004,
                        1.6450, 1.0708, 1.0513, 1.0205, 0.9932, 0.9907, 1.0029, 0.9600, 1.0532, 1.1880,
                        1.2954, 1.0728, 0.9951, 1.0059, 1.0010, 0.9907, 0.9946, 1.0049, 1.0024, 1.2866,
                        1.3472, 1.0435, 1.0078, 1.0024, 0.9927, 1.0063, 0.9897, 1.0127, 0.9858, 1.2563,
                        1.3892, 1.0288, 1.0234, 1.0122, 0.9907, 1.0049, 0.9976, 1.0093, 0.9990, 1.2158,
                        1.4004, 1.0513, 1.0122, 1.0083, 0.9893, 1.0029, 0.9980, 1.0146, 0.9946, 1.2163,
                        1.4873, 1.0649, 1.0249, 1.0200, 1.0034, 1.0059, 1.0073, 1.0083, 1.0122, 1.2705,
                        1.6519, 1.1069, 1.0347, 1.0313, 1.0122, 1.0093, 1.0210, 1.0117, 1.0493, 1.3647,
                        1.8989, 1.2109, 1.0254, 1.0210, 1.0205, 1.0142, 1.0356, 1.0273, 1.1167, 1.5786,
                      },
           		},
           		/* D75 */
           		{
                    //1
                     	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                     	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                      {
                        4.1865, 1.0645, 1.3467, 1.0649, 1.0322, 1.0439, 1.0366, 1.0952, 1.1953, 2.0259,
                        1.8706, 1.1914, 1.0674, 1.0405, 1.0229, 1.0254, 1.0479, 1.0928, 1.1846, 1.5708,
                        1.8105, 1.1372, 1.1206, 1.0479, 1.0186, 1.0142, 1.0293, 1.0327, 1.1426, 1.3276,
                        1.3970, 1.1392, 1.0532, 1.0298, 1.0059, 1.0020, 1.0171, 1.0405, 1.0981, 1.4121,
                        1.4536, 1.1265, 1.0605, 1.0298, 0.9990, 1.0015, 1.0132, 1.0581, 1.0811, 1.3716,
                        1.4888, 1.0996, 1.0796, 1.0171, 0.9985, 0.9990, 1.0132, 1.0454, 1.0825, 1.3350,
                        1.5039, 1.1221, 1.0703, 1.0352, 0.9902, 1.0054, 1.0229, 1.0591, 1.0791, 1.3652,
                        1.5942, 1.1436, 1.0801, 1.0454, 1.0098, 1.0034, 1.0391, 1.0469, 1.1196, 1.3716,
                        1.7627, 1.1860, 1.1089, 1.0605, 1.0298, 1.0308, 1.0371, 1.0708, 1.1250, 1.5127,
                        2.0562, 1.2866, 1.1099, 1.0947, 1.0444, 1.0571, 1.0986, 1.0864, 1.2549, 1.6919,
                        3.8584, 1.0059, 1.2529, 1.0034, 0.9858, 1.0010, 0.9844, 1.0479, 1.1191, 1.9507,
                        1.7607, 1.1206, 1.0181, 1.0073, 0.9990, 1.0049, 1.0215, 1.0586, 1.1284, 1.5352,
                        1.6841, 1.0796, 1.0674, 1.0161, 1.0039, 1.0000, 1.0117, 1.0063, 1.0854, 1.2651,
                        1.3091, 1.0718, 1.0049, 1.0078, 0.9932, 0.9976, 1.0063, 1.0176, 1.0479, 1.3555,
                        1.3643, 1.0581, 1.0215, 1.0083, 0.9966, 1.0078, 1.0044, 1.0396, 1.0327, 1.3145,
                        1.4126, 1.0410, 1.0400, 1.0083, 0.9980, 1.0029, 1.0044, 1.0386, 1.0249, 1.2808,
                        1.4253, 1.0581, 1.0313, 1.0122, 0.9922, 1.0039, 1.0132, 1.0303, 1.0400, 1.2920,
                        1.5073, 1.0811, 1.0425, 1.0239, 1.0024, 1.0073, 1.0176, 1.0400, 1.0562, 1.3525,
                        1.6587, 1.1265, 1.0459, 1.0337, 1.0259, 1.0098, 1.0322, 1.0337, 1.0806, 1.4438,
                        1.8936, 1.2397, 1.0527, 1.0503, 1.0293, 1.0386, 1.0601, 1.0547, 1.1816, 1.6748,
                        3.5396, 0.9746, 1.1919, 0.9702, 0.9639, 0.9604, 0.9644, 0.9912, 1.0928, 1.7993,
                        1.6948, 1.0762, 0.9814, 0.9795, 0.9839, 0.9937, 1.0059, 1.0356, 1.0952, 1.4600,
                        1.5952, 1.0454, 1.0376, 1.0063, 0.9922, 0.9922, 0.9980, 0.9736, 1.0684, 1.2051,
                        1.2593, 1.0405, 0.9736, 0.9927, 0.9824, 0.9873, 0.9893, 1.0044, 1.0039, 1.3169,
                        1.2988, 1.0215, 0.9980, 0.9980, 0.9946, 1.0073, 0.9966, 1.0225, 1.0039, 1.2764,
                        1.3516, 1.0073, 1.0078, 0.9932, 0.9888, 1.0010, 0.9995, 1.0151, 1.0093, 1.2466,
                        1.3784, 1.0244, 1.0122, 1.0029, 0.9907, 0.9995, 1.0020, 1.0151, 1.0063, 1.2476,
                        1.4370, 1.0469, 1.0137, 1.0073, 1.0054, 1.0015, 1.0244, 1.0107, 1.0361, 1.3027,
                        1.6133, 1.0864, 1.0166, 1.0234, 1.0088, 0.9971, 1.0181, 1.0137, 1.0518, 1.4067,
                        1.8169, 1.1953, 1.0220, 1.0181, 1.0225, 1.0200, 1.0522, 1.0190, 1.1563, 1.5977,
                      },
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
    /*isp_sub_module_gic_pra isp_sub_module_gic_tuning;*/
    {

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
        		360,
        	},
        	/*trigger 1*/
        	{
				480,
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
                     1.8296, -0.8228, -0.0068,
                     -0.4532, 1.2936, 0.1596,
                     0.3094, -2.4026, 3.0932,
                },
                /* ccm tl84 matrix */
                {
                     1.6250, -0.4258, -0.1992,
                     -0.3945, 1.5078, -0.1133,
                     0.3906, -1.4961, 2.1094,
                },
                /* ccm d50 matrix */
                {
                     1.6680, -0.5234, -0.1445,
                     -0.2828, 1.4727, -0.1859,
                     0.2305, -1.0391, 1.8164,
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
                     1.6680, -0.5235, -0.1445,
                     -0.3828, 1.4727, -0.0859,
                     0.2304, -1.0391, 1.8167,
                },
                /* ccm tl84 matrix */
                {
                     1.6250, -0.4258, -0.1992,
                     -0.3945, 1.5078, -0.1133,
                     0.3906, -1.4961, 2.1094,
                },
                /* ccm d50 matrix */
                {
                     1.6680, -0.5234, -0.1445,
                     -0.2828, 1.4727, -0.1859,
                     0.2305, -1.0391, 1.8164,
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
            0.000,
            100.000,
          },
          /*aec trigger 2*/
          {
            170,
            280,
          },
          /*aec trigger 3*/
          {
            310,
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
            140.000,
          },
          /*aec trigger 2*/
          {
            180.000,
            300.000,
          },
          /*aec trigger 3*/
          {
            380.000,
            550.000,
          },
       },
       513,//gamma lut count
       /*isp_sub_module_gamma_lut_pra pra[MIN_TRIGGER_COUNT]; MIN_TRIGGER_COUNT=3*/
       {
          /* outdoor */
          {
                  0,  39,  79, 118, 159, 202, 241, 280, 318, 356, 393, 428, 462, 494, 527, 557, 592, 624, 659, 690, 718, 747, 772, 794, 820, 842, 867,
                889, 911, 933, 956, 978, 998,1019,1037,1057,1077,1095,1114,1134,1154,1173,1193,1209,1228,1244,1264,1280,1299,1315,1334,1350,1366,1384,
               1400,1415,1433,1449,1466,1481,1497,1514,1529,1547,1562,1578,1596,1610,1625,1643,1658,1672,1686,1703,1717,1731,1747,1760,1773,1786,1802,
               1814,1826,1840,1853,1865,1879,1891,1904,1916,1929,1944,1955,1967,1979,1993,2004,2015,2027,2039,2049,2062,2073,2085,2096,2112,2120,2136,
               2144,2160,2168,2184,2192,2208,2216,2224,2240,2248,2256,2272,2280,2288,2304,2313,2321,2329,2337,2353,2361,2369,2377,2385,2401,2409,2417,
               2425,2433,2441,2449,2465,2473,2481,2489,2497,2505,2513,2521,2529,2537,2545,2553,2561,2570,2578,2586,2594,2602,2610,2618,2626,2634,2642,
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
               4015,4019,4023,4027,4029,4030,4031,4035,4039,4043,4045,4047,4051,4055,4059,4061,4063,4067,4071,4075,4077,4078,4079,4083,4087,4095,4095,
          },
          /* indoor */
          {
                  0,  39,  79, 118, 159, 202, 241, 280, 318, 356, 393, 428, 462, 494, 527, 557, 592, 624, 659, 690, 718, 747, 772, 794, 820, 842, 867,
                889, 911, 933, 956, 978, 998,1019,1037,1057,1077,1095,1114,1134,1154,1173,1193,1209,1228,1244,1264,1280,1299,1315,1334,1350,1366,1384,
               1400,1415,1433,1449,1466,1481,1497,1514,1529,1547,1562,1578,1596,1610,1625,1643,1658,1672,1686,1703,1717,1731,1747,1760,1773,1786,1802,
               1814,1826,1840,1853,1865,1879,1891,1904,1916,1929,1944,1955,1967,1979,1993,2004,2015,2027,2039,2049,2062,2073,2085,2096,2112,2120,2136,
               2144,2160,2168,2184,2192,2208,2216,2224,2240,2248,2256,2272,2280,2288,2304,2313,2321,2329,2337,2353,2361,2369,2377,2385,2401,2409,2417,
               2425,2433,2441,2449,2465,2473,2481,2489,2497,2505,2513,2521,2529,2537,2545,2553,2561,2570,2578,2586,2594,2602,2610,2618,2626,2634,2642,
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
               4015,4019,4023,4027,4029,4030,4031,4035,4039,4043,4045,4047,4051,4055,4059,4061,4063,4067,4071,4075,4077,4078,4079,4083,4087,4095,4095,
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
    /*isp_sub_module_3d_lut_tuning_t isp_sub_module_3d_lut_tuning;*/
    {
		0, //enable
		1, //interpolation enable
		1, //ae count
		1, //awb count
		1, //trigger mode : 0 gain trigger 1 lux trigger
		/* aec trigger */
        {
			//trigger 0
			{
            0.000,
            350.000,
			},
			//trigger 1
			{
            0.000,
            0.000,
			},
			 //trigger 2
			{
            0.000,
            0.000,
			},
			 //trigger 3
			{
            0.000,
            0.000,
			},
			 //trigger 4
			{
            0.000,
            0.000,
			},
        },
		/* awb trigger */
		{
			//trigger 0
			{
            0.000,
            8000.000,
			},
			//trigger 1
			{
            0.000,
            0.000,
			},
			//trigger 2
			{
            0.000,
            0.000,
			},
			//trigger 3
			{
            0.000,
            0.000,
			},
			//trigger 4
			{
            0.000,
            0.000,
			},
			//trigger 5
			{
            0.000,
            0.000,
			},
			//trigger 6
			{
            0.000,
            0.000,
			},
		},
		/*isp_sub_module_3d_lut_pra pra[MIDDLE_TRIGGER_COUNT=5][MIDDLE_TRIGGER_COUNT=7];*/
		{
			//aec trigger 0
            {
				//para 0
				{
					//lut3d_table0
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
                        3072, 2218,  511,
                         511, 3072,  511,
                        2560, 3072,  511,
                           0, 3584,  512,
                        2048, 3584,  511,
                        4095, 3106,  512,
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
                        3584, 2798, 1536,
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
					//lut3d_table1
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
                        2560, 1706,    0,
                           0, 2560,    0,
                        2048, 2560,    0,
                        4095, 2560,    0,
                        1536, 3072,    0,
                        3584, 2594,    0,
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
                        3072, 2286, 1023,
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
					//lut3d_table2
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
                        4095, 3242, 1536,
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
					//lut3d_table3
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
                         511, 3072,    0,
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
                        4095, 3311, 2048,
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
				//para 1
				{
				},
				//para 2
				{
				},
				//para 3
				{
				},
				//para 4
				{
				},
				//para 5
				{
				},
				//para 6
				{
				},
			},
			//aec trigger 1
            {
			},
			//aec trigger 2
            {
			},
			//aec trigger 3
            {
			},
			//aec trigger 4
            {
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
       2,
       /*count_awb*/
       1,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            0.000,
            350.000,
          },
          /* aec trigger 2 */
          {
            440.000,
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
            8000.000,
          },
          /* awb trigger 2 */
          {
            0.000,
            0.000,
          },
          /* awb trigger 3 */
          {
            0.000,
            0.000,
          },
          /* awb trigger 4 */
          {
            0.000,
            0.000,
          },
          /* awb trigger 5 */
          {
            0.000,
            0.000,
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
                  0.850000, //saturation
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
          /* aec tigger 3 */
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
          /* aec tigger 4 */
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
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               90,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               68,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               55,  //sharpen_pos
               55,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               45,  //sharpen_pos
               60,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
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
               60,  //sharpen_fu
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
               40,  //sharpen_pos
               60,  //sharpen_fu
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
       8,
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
            1.500,
          },
          /*aec trigger 2 */
          {
            3.800,
            4.200,
          },
          /*aec trigger 3 */
          {
            7.000,
            8.000,
          },
          /*aec trigger 4 */
          {
            15.000,
            16.000,
          },
          /*aec trigger 5 */
          {
            30.000,
            31.000,
          },
          /*aec trigger 6 */
          {
            60.000,
            61.000,
          },
          /*aec trigger 7 */
          {
            100.000,
            101.000,
          },
          /*aec trigger 8 */
          {
            500.000,
            501.000,
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
       },
    },
   /* isp_sub_module_3d_2d_nr_tuning_t isp_sub_module_3d_2d_nr_tuning */
    {
       1, //enable
       1, //interpolation enable
       9, //ae count
       0, //trigger mode : 0 gain trigger 1 lux trigger
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            1.500,
          },
          /* aec trigger 2 */
          {
            3.800,
            4.200,
          },
          /* aec trigger 3 */
          {
            7.800,
            8.200,
          },
          /* aec trigger 4 */
          {
            12.000,
            12.100,
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
            100.000,
            101.000,
          },
          /* aec trigger 9 */
          {
            256.000,
            256.100,
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
           /* parameter 7 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   32,26,23,20,18,16,14,13,12,11,10,9,8,8,7,6,6,5,5,4,4,3,3,2,2,2,1,1,0,0,0,0,
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
           /* parameter 8 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
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
		   /* parameter 9 */
           {
               //weight_cur_lut[32]
               {
                   3,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
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
	   1,
	   /*int count_ae;*/
	   1,
	   /*int trigger_mode;*/
	   0,
	   /* aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT];*/
	   {
			   /*trigger 0*/
			   {
				   1,
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
					240,
					240,
					3,
					60,
					100,
					45,
			   },
				//pra1
			   {
					64,
					64,
					3,
					256,
					100,
					26,
			   },
				//pra2
			   {
					64,
					64,
					3,
					256,
					100,
					26,
			   },
				//pra3
			   {
					64,
					64,
					3,
					256,
					100,
					26,
			   },
				 //pra4
			   {
					64,
					64,
					3,
					256,
					100,
					26,
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
	/*ae exp_table_para*/
	{
        /* count */
        506,
        /* ev0_count */
        506,
        /* ev2_count */
        506,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        4096,
        /* max_isp_gain */
        1023.99,
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
          {256,  820  },        /* Gain= 1.000000 Exposure Index= 216 */
          {256,  845  },        /* Gain= 1.000000 Exposure Index= 217 */
          {256,  871  },        /* Gain= 1.000000 Exposure Index= 218 */
          {256,  898  },        /* Gain= 1.000000 Exposure Index= 219 */
          {256,  925  },        /* Gain= 1.000000 Exposure Index= 220 */
          {256,  953  },        /* Gain= 1.000000 Exposure Index= 221 */
          {256,  982  },        /* Gain= 1.000000 Exposure Index= 222 */
          {256,  1012  },        /* Gain= 1.000000 Exposure Index= 223 */
          {256,  1043  },        /* Gain= 1.000000 Exposure Index= 224 */
          {256,  1075  },        /* Gain= 1.000000 Exposure Index= 225 */
          {256,  1108  },        /* Gain= 1.000000 Exposure Index= 226 */
          {260,  1125  },        /* Gain= 1.015625 Exposure Index= 227 */
          {268,  1125  },        /* Gain= 1.046875 Exposure Index= 228 */
          {277,  1125  },        /* Gain= 1.082031 Exposure Index= 229 */
          {286,  1125  },        /* Gain= 1.117188 Exposure Index= 230 */
          {295,  1125  },        /* Gain= 1.152344 Exposure Index= 231 */
          {304,  1125  },        /* Gain= 1.187500 Exposure Index= 232 */
          {314,  1125  },        /* Gain= 1.226563 Exposure Index= 233 */
          {324,  1125  },        /* Gain= 1.265625 Exposure Index= 234 */
          {334,  1125  },        /* Gain= 1.304688 Exposure Index= 235 */
          {345,  1125  },        /* Gain= 1.347656 Exposure Index= 236 */
          {356,  1125  },        /* Gain= 1.390625 Exposure Index= 237 */
          {367,  1125  },        /* Gain= 1.433594 Exposure Index= 238 */
          {379,  1125  },        /* Gain= 1.480469 Exposure Index= 239 */
          {391,  1125  },        /* Gain= 1.527344 Exposure Index= 240 */
          {403,  1125  },        /* Gain= 1.574219 Exposure Index= 241 */
          {416,  1125  },        /* Gain= 1.625000 Exposure Index= 242 */
          {429,  1125  },        /* Gain= 1.675781 Exposure Index= 243 */
          {442,  1125  },        /* Gain= 1.726563 Exposure Index= 244 */
          {456,  1125  },        /* Gain= 1.781250 Exposure Index= 245 */
          {470,  1125  },        /* Gain= 1.835938 Exposure Index= 246 */
          {485,  1125  },        /* Gain= 1.894531 Exposure Index= 247 */
          {500,  1125  },        /* Gain= 1.953125 Exposure Index= 248 */
          {515,  1125  },        /* Gain= 2.011719 Exposure Index= 249 */
          {531,  1125  },        /* Gain= 2.074219 Exposure Index= 250 */
          {547,  1125  },        /* Gain= 2.136719 Exposure Index= 251 */
          {564,  1125  },        /* Gain= 2.203125 Exposure Index= 252 */
          {581,  1125  },        /* Gain= 2.269531 Exposure Index= 253 */
          {599,  1125  },        /* Gain= 2.339844 Exposure Index= 254 */
          {617,  1125  },        /* Gain= 2.410156 Exposure Index= 255 */
          {636,  1125  },        /* Gain= 2.484375 Exposure Index= 256 */
          {656,  1125  },        /* Gain= 2.562500 Exposure Index= 257 */
          {676,  1125  },        /* Gain= 2.640625 Exposure Index= 258 */
          {697,  1125  },        /* Gain= 2.722656 Exposure Index= 259 */
          {718,  1125  },        /* Gain= 2.804688 Exposure Index= 260 */
          {740,  1125  },        /* Gain= 2.890625 Exposure Index= 261 */
          {763,  1125  },        /* Gain= 2.980469 Exposure Index= 262 */
          {786,  1125  },        /* Gain= 3.070313 Exposure Index= 263 */
          {810,  1125  },        /* Gain= 3.164063 Exposure Index= 264 */
          {835,  1125  },        /* Gain= 3.261719 Exposure Index= 265 */
          {861,  1125  },        /* Gain= 3.363281 Exposure Index= 266 */
          {887,  1125  },        /* Gain= 3.464844 Exposure Index= 267 */
          {914,  1125  },        /* Gain= 3.570313 Exposure Index= 268 */
          {942,  1125  },        /* Gain= 3.679688 Exposure Index= 269 */
          {971,  1125  },        /* Gain= 3.792969 Exposure Index= 270 */
          {1001,  1125  },        /* Gain= 3.910156 Exposure Index= 271 */
          {1032,  1125  },        /* Gain= 4.031250 Exposure Index= 272 */
          {1063,  1125  },        /* Gain= 4.152344 Exposure Index= 273 */
          {1095,  1125  },        /* Gain= 4.277344 Exposure Index= 274 */
          {1128,  1125  },        /* Gain= 4.406250 Exposure Index= 275 */
          {1162,  1125  },        /* Gain= 4.539063 Exposure Index= 276 */
          {1197,  1125  },        /* Gain= 4.675781 Exposure Index= 277 */
          {1233,  1125  },        /* Gain= 4.816406 Exposure Index= 278 */
          {1270,  1125  },        /* Gain= 4.960938 Exposure Index= 279 */
          {1309,  1125  },        /* Gain= 5.113281 Exposure Index= 280 */
          {1349,  1125  },        /* Gain= 5.269531 Exposure Index= 281 */
          {1390,  1125  },        /* Gain= 5.429688 Exposure Index= 282 */
          {1432,  1125  },        /* Gain= 5.593750 Exposure Index= 283 */
          {1475,  1125  },        /* Gain= 5.761719 Exposure Index= 284 */
          {1520,  1125  },        /* Gain= 5.937500 Exposure Index= 285 */
          {1566,  1125  },        /* Gain= 6.117188 Exposure Index= 286 */
          {1613,  1125  },        /* Gain= 6.300781 Exposure Index= 287 */
          {1662,  1125  },        /* Gain= 6.492188 Exposure Index= 288 */
          {1712,  1125  },        /* Gain= 6.687500 Exposure Index= 289 */
          {1764,  1125  },        /* Gain= 6.890625 Exposure Index= 290 */
          {1817,  1125  },        /* Gain= 7.097656 Exposure Index= 291 */
          {1872,  1125  },        /* Gain= 7.312500 Exposure Index= 292 */
          {1929,  1125  },        /* Gain= 7.535156 Exposure Index= 293 */
          {1987,  1125  },        /* Gain= 7.761719 Exposure Index= 294 */
          {2047,  1125  },        /* Gain= 7.996094 Exposure Index= 295 */
          {2109,  1125  },        /* Gain= 8.238281 Exposure Index= 296 */
          {2173,  1125  },        /* Gain= 8.488281 Exposure Index= 297 */
          {2239,  1125  },        /* Gain= 8.746094 Exposure Index= 298 */
          {2307,  1125  },        /* Gain= 9.011719 Exposure Index= 299 */
          {2377,  1125  },        /* Gain= 9.285156 Exposure Index= 300 */
          {2449,  1125  },        /* Gain= 9.566406 Exposure Index= 301 */
          {2523,  1125  },        /* Gain= 9.855469 Exposure Index= 302 */
          {2599,  1125  },        /* Gain= 10.152344 Exposure Index= 303 */
          {2677,  1125  },        /* Gain= 10.457031 Exposure Index= 304 */
          {2758,  1125  },        /* Gain= 10.773438 Exposure Index= 305 */
          {2841,  1125  },        /* Gain= 11.097656 Exposure Index= 306 */
          {2927,  1125  },        /* Gain= 11.433594 Exposure Index= 307 */
          {3015,  1125  },        /* Gain= 11.777344 Exposure Index= 308 */
          {3106,  1125  },        /* Gain= 12.132813 Exposure Index= 309 */
          {3200,  1125  },        /* Gain= 12.500000 Exposure Index= 310 */
          {3296,  1125  },        /* Gain= 12.875000 Exposure Index= 311 */
          {3395,  1125  },        /* Gain= 13.261719 Exposure Index= 312 */
          {3497,  1125  },        /* Gain= 13.660156 Exposure Index= 313 */
          {3602,  1125  },        /* Gain= 14.070313 Exposure Index= 314 */
          {3711,  1125  },        /* Gain= 14.496094 Exposure Index= 315 */
          {3823,  1125  },        /* Gain= 14.933594 Exposure Index= 316 */
          {3938,  1125  },        /* Gain= 15.382813 Exposure Index= 317 */
          {4057,  1125  },        /* Gain= 15.847656 Exposure Index= 318 */
          {4179,  1125  },        /* Gain= 16.324219 Exposure Index= 319 */
          {4305,  1125  },        /* Gain= 16.816406 Exposure Index= 320 */
          {4435,  1125  },        /* Gain= 17.324219 Exposure Index= 321 */
          {4569,  1125  },        /* Gain= 17.847656 Exposure Index= 322 */
          {4707,  1125  },        /* Gain= 18.386719 Exposure Index= 323 */
          {4849,  1125  },        /* Gain= 18.941406 Exposure Index= 324 */
          {4995,  1125  },        /* Gain= 19.511719 Exposure Index= 325 */
          {5145,  1125  },        /* Gain= 20.097656 Exposure Index= 326 */
          {5300,  1125  },        /* Gain= 20.703125 Exposure Index= 327 */
          {5459,  1125  },        /* Gain= 21.324219 Exposure Index= 328 */
          {5623,  1125  },        /* Gain= 21.964844 Exposure Index= 329 */
          {5792,  1125  },        /* Gain= 22.625000 Exposure Index= 330 */
          {5966,  1125  },        /* Gain= 23.304688 Exposure Index= 331 */
          {6145,  1125  },        /* Gain= 24.003906 Exposure Index= 332 */
          {6330,  1125  },        /* Gain= 24.726563 Exposure Index= 333 */
          {6520,  1125  },        /* Gain= 25.468750 Exposure Index= 334 */
          {6716,  1125  },        /* Gain= 26.234375 Exposure Index= 335 */
          {6918,  1125  },        /* Gain= 27.023438 Exposure Index= 336 */
          {7126,  1125  },        /* Gain= 27.835938 Exposure Index= 337 */
          {7340,  1125  },        /* Gain= 28.671875 Exposure Index= 338 */
          {7561,  1125  },        /* Gain= 29.535156 Exposure Index= 339 */
          {7788,  1125  },        /* Gain= 30.421875 Exposure Index= 340 */
          {8022,  1125  },        /* Gain= 31.335938 Exposure Index= 341 */
          {8263,  1125  },        /* Gain= 32.277344 Exposure Index= 342 */
          {8511,  1125  },        /* Gain= 33.246094 Exposure Index= 343 */
          {8767,  1125  },        /* Gain= 34.246094 Exposure Index= 344 */
          {9031,  1125  },        /* Gain= 35.277344 Exposure Index= 345 */
          {9302,  1125  },        /* Gain= 36.335938 Exposure Index= 346 */
          {9582,  1125  },        /* Gain= 37.429688 Exposure Index= 347 */
          {9870,  1125  },        /* Gain= 38.554688 Exposure Index= 348 */
          {10167,  1125  },        /* Gain= 39.714844 Exposure Index= 349 */
          {10473,  1125  },        /* Gain= 40.910156 Exposure Index= 350 */
          {10788,  1125  },        /* Gain= 42.140625 Exposure Index= 351 */
          {11112,  1125  },        /* Gain= 43.406250 Exposure Index= 352 */
          {11446,  1125  },        /* Gain= 44.710938 Exposure Index= 353 */
          {11790,  1125  },        /* Gain= 46.054688 Exposure Index= 354 */
          {12144,  1125  },        /* Gain= 47.437500 Exposure Index= 355 */
          {12509,  1125  },        /* Gain= 48.863281 Exposure Index= 356 */
          {12885,  1125  },        /* Gain= 50.332031 Exposure Index= 357 */
          {13272,  1125  },        /* Gain= 51.843750 Exposure Index= 358 */
          {13671,  1125  },        /* Gain= 53.402344 Exposure Index= 359 */
          {14082,  1125  },        /* Gain= 55.007813 Exposure Index= 360 */
          {14505,  1125  },        /* Gain= 56.660156 Exposure Index= 361 */
          {14941,  1125  },        /* Gain= 58.363281 Exposure Index= 362 */
          {15390,  1125  },        /* Gain= 60.117188 Exposure Index= 363 */
          {15852,  1125  },        /* Gain= 61.921875 Exposure Index= 364 */
          {16328,  1125  },        /* Gain= 63.781250 Exposure Index= 365 */
          {16818,  1125  },        /* Gain= 65.695313 Exposure Index= 366 */
          {17323,  1125  },        /* Gain= 67.667969 Exposure Index= 367 */
          {17843,  1125  },        /* Gain= 69.699219 Exposure Index= 368 */
          {18379,  1125  },        /* Gain= 71.792969 Exposure Index= 369 */
          {18931,  1125  },        /* Gain= 73.949219 Exposure Index= 370 */
          {19499,  1125  },        /* Gain= 76.167969 Exposure Index= 371 */
          {20084,  1125  },        /* Gain= 78.453125 Exposure Index= 372 */
          {20687,  1125  },        /* Gain= 80.808594 Exposure Index= 373 */
          {21308,  1125  },        /* Gain= 83.234375 Exposure Index= 374 */
          {21948,  1125  },        /* Gain= 85.734375 Exposure Index= 375 */
          {22607,  1125  },        /* Gain= 88.308594 Exposure Index= 376 */
          {23286,  1125  },        /* Gain= 90.960938 Exposure Index= 377 */
          {23985,  1125  },        /* Gain= 93.691406 Exposure Index= 378 */
          {24705,  1125  },        /* Gain= 96.503906 Exposure Index= 379 */
          {25447,  1125  },        /* Gain= 99.402344 Exposure Index= 380 */
          {26211,  1125  },        /* Gain= 102.386719 Exposure Index= 381 */
          {26998,  1125  },        /* Gain= 105.460938 Exposure Index= 382 */
          {27808,  1125  },        /* Gain= 108.625000 Exposure Index= 383 */
          {28643,  1125  },        /* Gain= 111.886719 Exposure Index= 384 */
          {29503,  1125  },        /* Gain= 115.246094 Exposure Index= 385 */
          {30389,  1125  },        /* Gain= 118.707031 Exposure Index= 386 */
          {31301,  1125  },        /* Gain= 122.269531 Exposure Index= 387 */
          {32241,  1125  },        /* Gain= 125.941406 Exposure Index= 388 */
          {33209,  1125  },        /* Gain= 129.722656 Exposure Index= 389 */
          {34206,  1125  },        /* Gain= 133.617188 Exposure Index= 390 */
          {35233,  1125  },        /* Gain= 137.628906 Exposure Index= 391 */
          {36290,  1125  },        /* Gain= 141.757813 Exposure Index= 392 */
          {37379,  1125  },        /* Gain= 146.011719 Exposure Index= 393 */
          {38501,  1125  },        /* Gain= 150.394531 Exposure Index= 394 */
          {39657,  1125  },        /* Gain= 154.910156 Exposure Index= 395 */
          {40847,  1125  },        /* Gain= 159.558594 Exposure Index= 396 */
          {42073,  1125  },        /* Gain= 164.347656 Exposure Index= 397 */
          {43336,  1125  },        /* Gain= 169.281250 Exposure Index= 398 */
          {44637,  1125  },        /* Gain= 174.363281 Exposure Index= 399 */
          {45977,  1125  },        /* Gain= 179.597656 Exposure Index= 400 */
          {47357,  1125  },        /* Gain= 184.988281 Exposure Index= 401 */
          {48778,  1125  },        /* Gain= 190.539063 Exposure Index= 402 */
          {50242,  1125  },        /* Gain= 196.257813 Exposure Index= 403 */
          {51750,  1125  },        /* Gain= 202.148438 Exposure Index= 404 */
          {53303,  1125  },        /* Gain= 208.214844 Exposure Index= 405 */
          {54903,  1125  },        /* Gain= 214.464844 Exposure Index= 406 */
          {56551,  1125  },        /* Gain= 220.902344 Exposure Index= 407 */
          {58248,  1125  },        /* Gain= 227.531250 Exposure Index= 408 */
          {59996,  1125  },        /* Gain= 234.359375 Exposure Index= 409 */
          {61796,  1125  },        /* Gain= 241.390625 Exposure Index= 410 */
          {63650,  1125  },        /* Gain= 248.632813 Exposure Index= 411 */
          {65560,  1125  },        /* Gain= 256.093750 Exposure Index= 412 */
          {67527,  1125  },        /* Gain= 263.777344 Exposure Index= 413 */
          {69553,  1125  },        /* Gain= 271.691406 Exposure Index= 414 */
          {71640,  1125  },        /* Gain= 279.843750 Exposure Index= 415 */
          {73790,  1125  },        /* Gain= 288.242188 Exposure Index= 416 */
          {76004,  1125  },        /* Gain= 296.890625 Exposure Index= 417 */
          {78285,  1125  },        /* Gain= 305.800781 Exposure Index= 418 */
          {80634,  1125  },        /* Gain= 314.976563 Exposure Index= 419 */
          {83054,  1125  },        /* Gain= 324.429688 Exposure Index= 420 */
          {85546,  1125  },        /* Gain= 334.164063 Exposure Index= 421 */
          {88113,  1125  },        /* Gain= 344.191406 Exposure Index= 422 */
          {90757,  1125  },        /* Gain= 354.519531 Exposure Index= 423 */
          {93480,  1125  },        /* Gain= 365.156250 Exposure Index= 424 */
          {96285,  1125  },        /* Gain= 376.113281 Exposure Index= 425 */
          {99174,  1125  },        /* Gain= 387.398438 Exposure Index= 426 */
          {102150,  1125  },        /* Gain= 399.023438 Exposure Index= 427 */
          {105215,  1125  },        /* Gain= 410.996094 Exposure Index= 428 */
          {108372,  1125  },        /* Gain= 423.328125 Exposure Index= 429 */
          {111624,  1125  },        /* Gain= 436.031250 Exposure Index= 430 */
          {114973,  1125  },        /* Gain= 449.113281 Exposure Index= 431 */
          {118423,  1125  },        /* Gain= 462.589844 Exposure Index= 432 */
          {121976,  1125  },        /* Gain= 476.468750 Exposure Index= 433 */
          {125636,  1125  },        /* Gain= 490.765625 Exposure Index= 434 */
          {129406,  1125  },        /* Gain= 505.492188 Exposure Index= 435 */
          {133289,  1125  },        /* Gain= 520.660156 Exposure Index= 436 */
          {137288,  1125  },        /* Gain= 536.281250 Exposure Index= 437 */
          {141407,  1125  },        /* Gain= 552.371094 Exposure Index= 438 */
          {145650,  1125  },        /* Gain= 568.945313 Exposure Index= 439 */
          {150020,  1125  },        /* Gain= 586.015625 Exposure Index= 440 */
          {154521,  1125  },        /* Gain= 603.597656 Exposure Index= 441 */
          {159157,  1125  },        /* Gain= 621.707031 Exposure Index= 442 */
          {163932,  1125  },        /* Gain= 640.359375 Exposure Index= 443 */
          {168850,  1125  },        /* Gain= 659.570313 Exposure Index= 444 */
          {173916,  1125  },        /* Gain= 679.359375 Exposure Index= 445 */
          {179134,  1125  },        /* Gain= 699.742188 Exposure Index= 446 */
          {184509,  1125  },        /* Gain= 720.738281 Exposure Index= 447 */
          {190045,  1125  },        /* Gain= 742.363281 Exposure Index= 448 */
          {195747,  1125  },        /* Gain= 764.636719 Exposure Index= 449 */
          {201620,  1125  },        /* Gain= 787.578125 Exposure Index= 450 */
          {207669,  1125  },        /* Gain= 811.207031 Exposure Index= 451 */
          {213900,  1125  },        /* Gain= 835.546875 Exposure Index= 452 */
          {220317,  1125  },        /* Gain= 860.613281 Exposure Index= 453 */
          {226927,  1125  },        /* Gain= 886.433594 Exposure Index= 454 */
          {233735,  1125  },        /* Gain= 913.027344 Exposure Index= 455 */
          {240748,  1125  },        /* Gain= 940.421875 Exposure Index= 456 */
          {247971,  1125  },        /* Gain= 968.636719 Exposure Index= 457 */
          {255411,  1125  },        /* Gain= 997.699219 Exposure Index= 458 */
          {263074,  1125  },        /* Gain= 1027.632813 Exposure Index= 459 */
          {270967,  1125  },        /* Gain= 1058.464844 Exposure Index= 460 */
          {279097,  1125  },        /* Gain= 1090.222656 Exposure Index= 461 */
          {287470,  1125  },        /* Gain= 1122.929688 Exposure Index= 462 */
          {296095,  1125  },        /* Gain= 1156.621094 Exposure Index= 463 */
          {304978,  1125  },        /* Gain= 1191.320313 Exposure Index= 464 */
          {314128,  1125  },        /* Gain= 1227.062500 Exposure Index= 465 */
          {323552,  1125  },        /* Gain= 1263.875000 Exposure Index= 466 */
          {333259,  1125  },        /* Gain= 1301.792969 Exposure Index= 467 */
          {343257,  1125  },        /* Gain= 1340.847656 Exposure Index= 468 */
          {353555,  1125  },        /* Gain= 1381.074219 Exposure Index= 469 */
          {364162,  1125  },        /* Gain= 1422.507813 Exposure Index= 470 */
          {375087,  1125  },        /* Gain= 1465.183594 Exposure Index= 471 */
          {386340,  1125  },        /* Gain= 1509.140625 Exposure Index= 472 */
          {397931,  1125  },        /* Gain= 1554.417969 Exposure Index= 473 */
          {409869,  1125  },        /* Gain= 1601.050781 Exposure Index= 474 */
          {422166,  1125  },        /* Gain= 1649.085938 Exposure Index= 475 */
          {434831,  1125  },        /* Gain= 1698.558594 Exposure Index= 476 */
          {447876,  1125  },        /* Gain= 1749.515625 Exposure Index= 477 */
          {461313,  1125  },        /* Gain= 1802.003906 Exposure Index= 478 */
          {475153,  1125  },        /* Gain= 1856.066406 Exposure Index= 479 */
          {489408,  1125  },        /* Gain= 1911.750000 Exposure Index= 480 */
          {504091,  1125  },        /* Gain= 1969.105469 Exposure Index= 481 */
          {519214,  1125  },        /* Gain= 2028.179688 Exposure Index= 482 */
          {534791,  1125  },        /* Gain= 2089.027344 Exposure Index= 483 */
          {550835,  1125  },        /* Gain= 2151.699219 Exposure Index= 484 */
          {567361,  1125  },        /* Gain= 2216.253906 Exposure Index= 485 */
          {584382,  1125  },        /* Gain= 2282.742188 Exposure Index= 486 */
          {601914,  1125  },        /* Gain= 2351.226563 Exposure Index= 487 */
          {619972,  1125  },        /* Gain= 2421.765625 Exposure Index= 488 */
          {638572,  1125  },        /* Gain= 2494.421875 Exposure Index= 489 */
          {657730,  1125  },        /* Gain= 2569.257813 Exposure Index= 490 */
          {677462,  1125  },        /* Gain= 2646.335938 Exposure Index= 491 */
          {697786,  1125  },        /* Gain= 2725.726563 Exposure Index= 492 */
          {718720,  1125  },        /* Gain= 2807.500000 Exposure Index= 493 */
          {740282,  1125  },        /* Gain= 2891.726563 Exposure Index= 494 */
          {762491,  1125  },        /* Gain= 2978.480469 Exposure Index= 495 */
          {785366,  1125  },        /* Gain= 3067.835938 Exposure Index= 496 */
          {808927,  1125  },        /* Gain= 3159.871094 Exposure Index= 497 */
          {833195,  1125  },        /* Gain= 3254.667969 Exposure Index= 498 */
          {858191,  1125  },        /* Gain= 3352.308594 Exposure Index= 499 */
          {883937,  1125  },        /* Gain= 3452.878906 Exposure Index= 500 */
          {910456,  1125  },        /* Gain= 3556.468750 Exposure Index= 501 */
          {937770,  1125  },        /* Gain= 3663.164063 Exposure Index= 502 */
          {965904,  1125  },        /* Gain= 3773.062500 Exposure Index= 503 */
          {994882,  1125  },        /* Gain= 3886.257813 Exposure Index= 504 */
          {1024729, 1125  },        /* Gain= 4002.847656 Exposure Index= 505 */
		},
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            39,  /* outdoor_luma_target_compensated */
            35,  /* default_luma_target_compensated */
            18,/* low_light.luma_target */
            100,  /* outdoor_index */
            220,  /* indoor_index */
            330,/* low_light.start_idx */
            350,/* low_light.end_idx */
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
		1, /* metering_type 0:SPOT_METERING,1:CENTER_WEIGHTED,2: SIMPLE_FRAME_AVERAGE*/
		0, /*full_sweep_en ,set to 1 to fullsweep exp table*/
		77.894, /* exposure_index_adj_step ,NEED 1 / log10(1.03) */
		1, /* 0: no antibanding; 1: 50Hz antibanding; 2: 60Hz antibanding */
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
            0.15,    //float hist_sat_pct;                               0.1-0.2
            0.15,    //float hist_dark_pct;                             0.1-0.3
            150,      //float hist_sat_low_ref;
            200,     //float hist_sat_high_ref;
            3,       //float hist_dark_low_ref;
            20,      //float hist_dark_high_ref;

        },
        {
            1,  /*1: OverExp enable; 0: OverExp disable */
		    220,/* high_luma_region_threshold : OverExp Threshold*/
            /* the ratio table in OverExp condition */
            1.0, //outdoor
            0.9, //indoor
            0.8, //low light
            /*the luma offset to be reduced in OverExp condition */
            8,  //outdoor
            6,  //indoor
            6,  //low light
            /*Max Count Table of OverExp */
            30,  //outdoor
            25,  //indoor
            15,  //low light
            /*Min Count Table of OverExp */
            15,   //outdoor
            10,   //indoor
            5,   //low light
        },
        /*sensor hdr tuning pra */
        {
		 	 /*int enable;*/
			 1,
             /*int enable_hdr_luma_tartget;*/
			 1,
			 /*int short_exp_max_index;*/
			 115,
             /*float max_exp_ration;*/
			 256,
			 /*int enble_ration_table;*/
			 1,
			 /*int ration_talbe_size;*/
			 5,
			 /*int over_exp_per_high;*/
			 4,
             /*int over_exp_per_low;*/
			 1,
			 /*float short_k;*/
			 2,
			 /*ration_interp_en*/
			 0,
			 /*ration_table_t ration_table[HDR_RATION_TALBE_SIZE];*/
		 	 {
		 	         /*exp_index  ration0 ration1 ration2 ration3 luma_target*/
		 	     	{0,             64,    1,      1,	   1, 	     20},
					{10,            32,    1,      1,	   1,        20},
					{52,            16,    1,      1,	   1,	     20},
					{80,              8,   1,      1,	   1,        20},
					{115,            4,    1,      1,	   1,	     20},
		 	 },
		},
		/*night_detect_t night sensce deteted*/
		{
		     /*int enable*/
			 1,
			 /* int lux_index_low;*/
			 220,
			 /*int lux_index_hight;*/
			 250,
		},
        /*motion_detect_t*/
		{
		     /*int enable;*/
			 1,
			 /* int abs_th;*/
			 10,
		},
      /*  face ae */
      {

      },
      /*  extreme color */
      {

      },
      /*  bright dark */
      {

      },
      0, //aec_algo_type : 0-FAST_SMOOTH, 1-FAST_PLUS
      // AEC_FAST_PLUS_PARAM_t aec_fast_plus_param
      {
        2,  /* aec_fast_plus_param.luma_tolerance */
        2,  /* aec_fast_plus_param.frame_skip */
        2,  /* aec_fast_plus_param.ddr_frame_skip_offset : this should be 2 for most situations*/
        /*uint32_t interval_threshold[3]*/
        {
          5,  /* aec_fast_plus_param.interval_threshold[0] */
          10,  /* aec_fast_plus_param.interval_threshold[1] */
          15,  /* aec_fast_plus_param.interval_threshold[2] */
        },
        /*float speed_ratio[3]*/
        {
          0.95,  /* aec_fast_plus_param.speed_ratio[0] */
          0.80,  /* aec_fast_plus_param.speed_ratio[1] */
          0.75,  /* aec_fast_plus_param.speed_ratio[2] */
        },
        0.70,  /* aec_fast_plus_param.speed_ratio_others */
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
            332,
        },
	},
    /* awb_point */
    {
    	{ 0.5548, 0.6724 },    /* d75 */
        { 0.5906, 0.6413 },    /* d65 */
        { 0.6383, 0.5382 },    /* d50 */
        { 0.6383, 0.5382 },    /* noon */
        { 0.6427, 0.4062 },    /* cw */
        { 0.7172, 0.4580 },    /* tl84 */
        { 1.0190, 0.3248 },    /* a */
        { 1.0190, 0.3248 },    /* h */
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
    	7889, /* d75 */
    	6628, /* d65 */
    	5184, /* d50 */
    	5184, /* noon */
    	3930, /* cw */
    	4180, /* tl84 */
    	2710, /* a */
    	2710, /* h */
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
        { 0, 0, 0, 0 },   /*   d75    */
        { 2, 4, 2, 1 },   /*   d65    */
        { 6, 5, 4, 2 },   /*   d50    */
        { 6, 5, 4, 2 },   /*   noon   */
        { 1, 1, 1, 1 },   /*   cw     */
        { 1, 1, 1, 1 },   /*   tl84   */
        { 0, 1, 1, 1 },   /*   a      */
        { 0, 0, 1, 1 },   /*   h      */
        { 0, 0, 0, 0 },   /*   custom1*/
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
           0x00000100, /* Gray_m1 */
           0x00010100, /* Gray_m2 */
           0x00000100, /* Gray_m3 */
           0x00010100, /* Gray_m4 */
           0x00000258, /* Gray_c1 */
           0x00010320, /* Gray_c2 */
           0x00010258, /* Gray_c3 */
           0x00000404, /* Gray_c4 */
           0x000000a2, /* Green_BGmax */
           0x00000038, /* Green_BGmin */
           0x00000073, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000192, /* Green_Rmul */
           0x00000126, /* Green_Bmul */
           0x000000cc,	/* extreme B, B/G */	//	D50 0.8
           0x00000500,	/* extreme B, R/G */
           0x00000133,	/* extreme R, R/G */	//	TL84
           0x00000191,	/* extreme R, B/G */
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
           0x00000005,	/* Y min  0.05*1024	*/
           0x00000100, /* Gray_m1 */
           0x00010100, /* Gray_m2 */
           0x00000100, /* Gray_m3 */
           0x00010100, /* Gray_m4 */
           0x00000258, /* Gray_c1 */
           0x00010320, /* Gray_c2 */
           0x00010258, /* Gray_c3 */
           0x00000404, /* Gray_c4 */
           0x000000a2, /* Green_BGmax */
           0x00000038, /* Green_BGmin */
           0x00000073, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000192, /* Green_Rmul */
           0x00000126, /* Green_Bmul */
           0x000002ae,	/* extreme B, B/G */	//	D50 0.68
           0x00000500,	/* extreme B, R/G */
           0x00000297,	/* extreme R, R/G */	//	TL84
           0x00000291,	/* extreme R, B/G */
    	},
    	{
    	},
  },
},
/*af_tuning_t  af_tuning*/
{

},
