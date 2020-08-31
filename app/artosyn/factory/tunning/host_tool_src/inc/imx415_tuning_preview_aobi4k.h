
/*---------------header of imx415 tuning-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x20200819,
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
       /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==3 */
       {
          /*region 1 */
          {
            1.000,
            48.000,
          },
          /*region 2 */
          {
            64.000,
            64.100,
          },
          /*region 3 */
          {
            128.000,
            128.100,
          },
          /*region 4 */
          {
            256.000,
            256.100,
          },
          /*region 5 */
          {
            2048.000,
            2048.100,
          },
       },
       /*isp_sub_module_blc_para pra[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT=3*/
       {
           /*parameter 1 */
           {
               800,
               800,
               800,
               800,
               270,
               270,
               270,
               270,
           },
           /*parameter 2 */
           {
               870,
               870,
               870,
               870,
               270,
               270,
               270,
               270,
           },
           /*parameter 3 */
           {
               1000,
               1000,
               1000,
               1000,
               271,
               271,
               271,
               271,
           },
           /*parameter 4 */
           {
               1300,
               1300,
               1300,
               1300,
               270,
               270,
               270,
               270,
           },
           /*parameter 3 */
           {
               1767,
               1626,
               1748,
               1643,
               287,
               285,
               287,
               285,
           },
           /*parameter 4 1536xgain*/
           /*{
               2227,
               2100,
               2257,
               2062,
               297,
               294,
               297,
               293,
           },*/
           /*parameter 5 2048xgain*/
           /*{
               3540,
               3361,
               3546,
               3341,
               303,
               300,
               304,
               299,
           },*/
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
            1,
            1,
            1,
            1,
            1,
       },
       {
          /*aec trigger 1 */
          {
            1.000,
            16.000,
          },
          /*aec trigger 2 */
          {
            32.000,
            32.100,
          },
          /*aec trigger 3 */
          {
            64.000,
            64.100,
          },
          /*aec trigger 4 */
          {
            128.000,
            512.100,
          },
          /*aec trigger 5 */
          {
            512.000,
            2048.000,
          },
       },
       /*aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT] MIDDLE_TRIGGER_COUNT==5 */
       {
           /*parameter 1 */
           {
               0x00000019,0x00000000,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x000000c8,0x00000320,0x0000003c,0x00000190,
               0x00000320,0x0000003c,0x00000190,0x00000320,0x00000033,0x00000020,0x00000040,0x00000080,0x00000100,0x00000200,
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
            16.000,
            16.100,
          },
          /*aec trigger 6 */
          {
            32.000,
            32.100,
          },
          /*aec trigger 7 */
          {
            64.000,
            64.100,
          },
          /*aec trigger 8 */
          {
            128.000,
            128.100,
          },
          /*aec trigger 9 */
          {
            256.000,
            256.100,
          },
          /*aec trigger 10 */
          {
            512.000,
            512.100,
          },
          /*aec trigger 11 */
          {
            1024.000,
            1024.100,
          },
          /*aec trigger 12 */
          {
            1560.000,
            1560.100,
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
                2,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {13,39,35},
                        //g channel
                        {13,39,35},
                        //b channel
                        {13,39,35},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {9,27,16},
                        //g channel
                        {9,27,16},
                        //b channel
                        {9,27,16},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {0,0,-2},
                        //g channel
                        {0,0,-2},
                        //b channel
                        {0,0,-2},
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
                2,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {30,90,84},
                        //g channel
                        {30,90,84},
                        //b channel
                        {30,90,84},
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
                2,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {46,138,130},
                        //g channel
                        {46,138,130},
                        //b channel
                        {46,138,130},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {32,96,64},
                        //g channel
                        {32,96,64},
                        //b channel
                        {32,96,64},
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
                        {52,156,148},
                        //g channel
                        {52,156,148},
                        //b channel
                        {52,156,148},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {38,114,76},
                        //g channel
                        {38,114,76},
                        //b channel
                        {38,114,76},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {16,48,31},
                        //g channel
                        {16,48,31},
                        //b channel
                        {16,48,31},
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
                        {93,279,267},
                        //g channel
                        {93,279,267},
                        //b channel
                        {93,279,267},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {78,234,159},
                        //g channel
                        {78,234,159},
                        //b channel
                        {78,234,159},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {48,144,97},
                        //g channel
                        {48,144,97},
                        //b channel
                        {48,144,97},
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
                        {218,654,629},
                        //g channel
                        {218,654,629},
                        //b channel
                        {218,654,629},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {159,477,327},
                        //g channel
                        {159,477,327},
                        //b channel
                        {159,477,327},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {132,396,271},
                        //g channel
                        {132,396,271},
                        //b channel
                        {132,396,271},
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
                        {352,1056,1018},
                        //g channel
                        {352,1056,1018},
                        //b channel
                        {352,1056,1018},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {252,756,520},
                        //g channel
                        {252,756,520},
                        //b channel
                        {252,756,520},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {238,714,491},
                        //g channel
                        {238,714,491},
                        //b channel
                        {238,714,491},
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
                        {380,1140,1099},
                        //g channel
                        {380,1140,1099},
                        //b channel
                        {380,1140,1099},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {312,936,644},
                        //g channel
                        {312,936,644},
                        //b channel
                        {312,936,644},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {337,1011,696},
                        //g channel
                        {337,1011,696},
                        //b channel
                        {337,1011,696},
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
                        {890,2670,2578},
                        //g channel
                        {890,2670,2578},
                        //b channel
                        {890,2670,2578},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {890,2670,1841},
                        //g channel
                        {890,2670,1841},
                        //b channel
                        {890,2670,1841},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {890,2670,1841},
                        //g channel
                        {890,2670,1841},
                        //b channel
                        {890,2670,1841},
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
                        {1365,4095,3955},
                        //g channel
                        {1365,4095,3955},
                        //b channel
                        {1365,4095,3955},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
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
                        {1365,4095,3955},
                        //g channel
                        {1365,4095,3955},
                        //b channel
                        {1365,4095,3955},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
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
                        {1365,4095,3955},
                        //g channel
                        {1365,4095,3955},
                        //b channel
                        {1365,4095,3955},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
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
                        {1365,4095,3955},
                        //g channel
                        {1365,4095,3955},
                        //b channel
                        {1365,4095,3955},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {1365,4095,2825},
                        //g channel
                        {1365,4095,2825},
                        //b channel
                        {1365,4095,2825},
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
        4,//awb count
		1,//trigger_mode : 0 gain trigger 1 lux trigger
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
     			3400,
     		},
     		/*awb trigger 2*/
     		{
     			3800,
     			4600,
     		},
     		/*awb trigger 3*/
     		{
     			4700,
     			5800,
     		},
     		/*awb trigger 4*/
     		{
     			6200,
     			7900,
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
               	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  1.5776, 1.3765, 1.2603, 1.1699, 1.1113, 1.1230, 1.1641, 1.2275, 1.3584, 1.4746,
                  1.4780, 1.3535, 1.2129, 1.1191, 1.0801, 1.0679, 1.1182, 1.1929, 1.3027, 1.4399,
                  1.4819, 1.3027, 1.1685, 1.0742, 1.1040, 1.0317, 1.0693, 1.1226, 1.2759, 1.3857,
                  1.4282, 1.2813, 1.1548, 1.0596, 1.0791, 0.9961, 1.0493, 1.1055, 1.2295, 1.3735,
                  1.4316, 1.2544, 1.1265, 1.0591, 0.9819, 0.9971, 1.0259, 1.0952, 1.2163, 1.3633,
                  1.4258, 1.2515, 1.1484, 1.0498, 1.0093, 1.0015, 1.0239, 1.0942, 1.2290, 1.3462,
                  1.4033, 1.2725, 1.1548, 1.0640, 1.0054, 1.0034, 1.0322, 1.1060, 1.2217, 1.3770,
                  1.4561, 1.3164, 1.1899, 1.1001, 1.0317, 1.0220, 1.0601, 1.1250, 1.2607, 1.3804,
                  1.4722, 1.3408, 1.2300, 1.1187, 1.0571, 1.0562, 1.0767, 1.1660, 1.2705, 1.4048,
                  1.5313, 1.3535, 1.2769, 1.1333, 1.1152, 1.0869, 1.1572, 1.2056, 1.3359, 1.4824,
                  1.4663, 1.3682, 1.2241, 1.2056, 1.1094, 1.1318, 1.1646, 1.2241, 1.3364, 1.4546,
                  1.4346, 1.3037, 1.1919, 1.1128, 1.0605, 1.0742, 1.1001, 1.1846, 1.2686, 1.4077,
                  1.3975, 1.2739, 1.1499, 1.0786, 1.1230, 1.0337, 1.0786, 1.1396, 1.2466, 1.3589,
                  1.3984, 1.2485, 1.1445, 1.0635, 1.0840, 0.9985, 1.0508, 1.1172, 1.2095, 1.3628,
                  1.3613, 1.2310, 1.1216, 1.0532, 0.9858, 1.0010, 1.0225, 1.1064, 1.1914, 1.3345,
                  1.3760, 1.2295, 1.1450, 1.0488, 1.0127, 1.0015, 1.0332, 1.0938, 1.2158, 1.3120,
                  1.3818, 1.2529, 1.1543, 1.0654, 1.0107, 1.0156, 1.0327, 1.1133, 1.2109, 1.3296,
                  1.3823, 1.2803, 1.1812, 1.0776, 1.0352, 1.0234, 1.0674, 1.1162, 1.2324, 1.3335,
                  1.4521, 1.3120, 1.2231, 1.1226, 1.0659, 1.0566, 1.0854, 1.1675, 1.2554, 1.3599,
                  1.4507, 1.3203, 1.2622, 1.1372, 1.0884, 1.1006, 1.1465, 1.1665, 1.3232, 1.3594,
                  1.4600, 1.3267, 1.1826, 1.1670, 1.1128, 1.1025, 1.1338, 1.1904, 1.2700, 1.3638,
                  1.3594, 1.2612, 1.1675, 1.1055, 1.0479, 1.0576, 1.0918, 1.1685, 1.2271, 1.3569,
                  1.3188, 1.2334, 1.1221, 1.0547, 1.1299, 1.0273, 1.0732, 1.1064, 1.2319, 1.2886,
                  1.3271, 1.2075, 1.1265, 1.0615, 1.0762, 0.9912, 1.0410, 1.1089, 1.1753, 1.3042,
                  1.3115, 1.2129, 1.0996, 1.0708, 0.9780, 1.0049, 1.0303, 1.0781, 1.2051, 1.2842,
                  1.2949, 1.2002, 1.1309, 1.0337, 1.0132, 0.9922, 1.0269, 1.1040, 1.1802, 1.2881,
                  1.3335, 1.2344, 1.1494, 1.0635, 1.0107, 1.0176, 1.0308, 1.0977, 1.1953, 1.2524,
                  1.3296, 1.2671, 1.1577, 1.0884, 1.0273, 1.0156, 1.0654, 1.1167, 1.2256, 1.3096,
                  1.3848, 1.2676, 1.2163, 1.0991, 1.0615, 1.0630, 1.0679, 1.1616, 1.2056, 1.2900,
                  1.3965, 1.3110, 1.2124, 1.1270, 1.0781, 1.0610, 1.1387, 1.1538, 1.3066, 1.3047,
                },
     		},
     		/* para 2 */
     		{
               	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  1.4272, 1.3184, 1.2217, 1.1709, 1.0986, 1.1265, 1.1445, 1.2388, 1.3135, 1.4868,
                  1.3857, 1.2710, 1.1777, 1.0918, 1.0615, 1.0596, 1.1094, 1.1621, 1.2861, 1.3730,
                  1.3589, 1.2651, 1.1353, 1.0713, 1.1079, 1.0308, 1.0723, 1.1382, 1.2490, 1.3853,
                  1.3643, 1.2202, 1.1318, 1.0488, 1.0747, 0.9985, 1.0498, 1.1133, 1.2139, 1.3462,
                  1.3325, 1.2207, 1.1094, 1.0557, 0.9937, 0.9995, 1.0366, 1.0962, 1.2070, 1.3418,
                  1.3350, 1.2227, 1.1216, 1.0479, 1.0049, 1.0122, 1.0283, 1.1006, 1.2129, 1.3408,
                  1.3408, 1.2290, 1.1450, 1.0571, 1.0156, 1.0137, 1.0405, 1.1108, 1.2114, 1.3340,
                  1.3735, 1.2827, 1.1665, 1.0947, 1.0288, 1.0356, 1.0664, 1.1265, 1.2451, 1.3428,
                  1.3965, 1.2939, 1.2002, 1.1128, 1.0571, 1.0659, 1.0908, 1.1636, 1.2646, 1.3887,
                  1.4131, 1.3159, 1.2373, 1.1230, 1.0981, 1.0791, 1.1475, 1.1904, 1.3159, 1.4072,
                  1.3911, 1.2949, 1.2124, 1.1636, 1.1084, 1.1138, 1.1465, 1.2051, 1.3013, 1.3862,
                  1.3535, 1.2734, 1.1616, 1.1040, 1.0542, 1.0605, 1.1045, 1.1646, 1.2695, 1.3857,
                  1.3257, 1.2363, 1.1353, 1.0605, 1.1260, 1.0205, 1.0781, 1.1294, 1.2354, 1.3379,
                  1.3320, 1.2183, 1.1289, 1.0542, 1.0752, 0.9976, 1.0459, 1.1123, 1.2026, 1.3423,
                  1.3330, 1.2090, 1.1104, 1.0552, 0.9858, 0.9956, 1.0356, 1.0986, 1.1982, 1.3179,
                  1.3291, 1.2017, 1.1367, 1.0405, 1.0117, 1.0020, 1.0337, 1.1001, 1.2119, 1.3242,
                  1.3271, 1.2358, 1.1382, 1.0591, 1.0039, 1.0171, 1.0337, 1.1099, 1.2051, 1.3252,
                  1.3638, 1.2617, 1.1719, 1.0815, 1.0322, 1.0278, 1.0635, 1.1211, 1.2402, 1.3291,
                  1.3628, 1.2998, 1.1958, 1.1143, 1.0713, 1.0581, 1.0972, 1.1606, 1.2490, 1.3677,
                  1.4165, 1.3022, 1.2412, 1.1382, 1.0820, 1.1094, 1.1304, 1.1816, 1.3105, 1.3413,
                  1.3794, 1.2686, 1.1685, 1.1763, 1.0776, 1.1128, 1.1289, 1.1660, 1.2798, 1.3604,
                  1.2329, 1.2271, 1.1211, 1.0723, 1.0464, 1.0425, 1.0942, 1.1323, 1.2402, 1.3057,
                  1.3042, 1.2080, 1.1138, 1.0571, 1.1284, 1.0181, 1.0718, 1.1162, 1.2061, 1.2974,
                  1.2573, 1.1821, 1.1079, 1.0405, 1.0859, 0.9824, 1.0459, 1.0933, 1.1821, 1.2939,
                  1.2729, 1.1763, 1.0942, 1.0493, 0.9731, 0.9980, 1.0303, 1.0879, 1.1802, 1.2847,
                  1.2642, 1.1831, 1.1196, 1.0322, 1.0054, 1.0088, 1.0195, 1.1025, 1.1689, 1.2778,
                  1.2861, 1.1953, 1.1392, 1.0503, 1.0010, 1.0132, 1.0298, 1.0967, 1.1963, 1.2842,
                  1.3301, 1.2461, 1.1523, 1.0811, 1.0229, 1.0313, 1.0581, 1.1187, 1.2026, 1.2974,
                  1.2876, 1.2710, 1.1802, 1.0996, 1.0493, 1.0522, 1.0762, 1.1523, 1.2085, 1.3115,
                  1.4141, 1.2720, 1.2271, 1.1294, 1.0981, 1.1035, 1.1274, 1.1646, 1.2886, 1.3032,
                },
     		},
     		/* para 3 */
     		{
               	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  1.4526, 1.3569, 1.2412, 1.1763, 1.1182, 1.1426, 1.1753, 1.2627, 1.3496, 1.5278,
                  1.4263, 1.3037, 1.1890, 1.1128, 1.0718, 1.0728, 1.1187, 1.1851, 1.3135, 1.4019,
                  1.3804, 1.2681, 1.1523, 1.0630, 1.1172, 1.0400, 1.0796, 1.1470, 1.2671, 1.4028,
                  1.3774, 1.2490, 1.1304, 1.0698, 1.0786, 1.0098, 1.0591, 1.1221, 1.2373, 1.3672,
                  1.3618, 1.2285, 1.1055, 1.0498, 0.9912, 0.9966, 1.0327, 1.0947, 1.2197, 1.3516,
                  1.3442, 1.2056, 1.1309, 1.0405, 1.0117, 1.0117, 1.0244, 1.1123, 1.2285, 1.3433,
                  1.3691, 1.2368, 1.1367, 1.0601, 1.0054, 1.0093, 1.0405, 1.1230, 1.2202, 1.3853,
                  1.3647, 1.2656, 1.1646, 1.0757, 1.0283, 1.0244, 1.0552, 1.1279, 1.2578, 1.3540,
                  1.3911, 1.2778, 1.1899, 1.0898, 1.0537, 1.0371, 1.0835, 1.1689, 1.2539, 1.4238,
                  1.4165, 1.3188, 1.2119, 1.1074, 1.0898, 1.0806, 1.1465, 1.1851, 1.3530, 1.4067,
                  1.3745, 1.3540, 1.1953, 1.1890, 1.1045, 1.1440, 1.1523, 1.2466, 1.3198, 1.4707,
                  1.3950, 1.2783, 1.1938, 1.1025, 1.0728, 1.0762, 1.1201, 1.1802, 1.2861, 1.3828,
                  1.3516, 1.2593, 1.1328, 1.0747, 1.1235, 1.0376, 1.0771, 1.1538, 1.2476, 1.3789,
                  1.3550, 1.2256, 1.1353, 1.0596, 1.0830, 0.9980, 1.0620, 1.1191, 1.2168, 1.3442,
                  1.3198, 1.2119, 1.1133, 1.0483, 0.9858, 1.0068, 1.0283, 1.1035, 1.2090, 1.3174,
                  1.3491, 1.1997, 1.1284, 1.0405, 1.0059, 1.0063, 1.0308, 1.1089, 1.2104, 1.3125,
                  1.3096, 1.2227, 1.1353, 1.0498, 1.0000, 1.0166, 1.0288, 1.1074, 1.2148, 1.3169,
                  1.3604, 1.2563, 1.1567, 1.0762, 1.0273, 1.0200, 1.0581, 1.1274, 1.2275, 1.3374,
                  1.3706, 1.2778, 1.1826, 1.1006, 1.0474, 1.0527, 1.0781, 1.1577, 1.2510, 1.3511,
                  1.3901, 1.2856, 1.2148, 1.1265, 1.0850, 1.0859, 1.1348, 1.1724, 1.3081, 1.3618,
                  1.3779, 1.3008, 1.1987, 1.1396, 1.1133, 1.0903, 1.1372, 1.2056, 1.2783, 1.4019,
                  1.3218, 1.2485, 1.1592, 1.0938, 1.0542, 1.0645, 1.1025, 1.1743, 1.2451, 1.3701,
                  1.3032, 1.2388, 1.1157, 1.0547, 1.1392, 1.0122, 1.0864, 1.1143, 1.2334, 1.3188,
                  1.3301, 1.1909, 1.1294, 1.0420, 1.0913, 0.9824, 1.0410, 1.1196, 1.1787, 1.3193,
                  1.2988, 1.1821, 1.0981, 1.0371, 0.9731, 0.9912, 1.0327, 1.0830, 1.2002, 1.2974,
                  1.3110, 1.1875, 1.1157, 1.0293, 1.0034, 0.9888, 1.0215, 1.0972, 1.1777, 1.2935,
                  1.3193, 1.1978, 1.1372, 1.0317, 1.0005, 0.9980, 1.0308, 1.0869, 1.2041, 1.2778,
                  1.3276, 1.2402, 1.1416, 1.0664, 1.0210, 1.0181, 1.0449, 1.1167, 1.2041, 1.2959,
                  1.3535, 1.2388, 1.1792, 1.0825, 1.0313, 1.0337, 1.0781, 1.1313, 1.2207, 1.3369,
                  1.3721, 1.2539, 1.2026, 1.1104, 1.0732, 1.0898, 1.1133, 1.1689, 1.2676, 1.3374,
                },
     		},
     		/* para 4 */
     		{
               	0.700000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  1.4692, 1.3418, 1.2095, 1.1738, 1.1245, 1.1484, 1.1641, 1.2607, 1.3687, 1.5874,
                  1.4023, 1.3003, 1.1797, 1.0991, 1.0615, 1.0742, 1.1235, 1.1938, 1.3193, 1.4478,
                  1.3975, 1.2573, 1.1353, 1.0762, 1.1094, 1.0469, 1.0923, 1.1592, 1.2900, 1.4609,
                  1.3604, 1.2178, 1.1318, 1.0400, 1.0732, 1.0083, 1.0527, 1.1274, 1.2417, 1.4038,
                  1.3320, 1.2202, 1.0977, 1.0493, 0.9912, 1.0015, 1.0493, 1.1094, 1.2495, 1.3965,
                  1.3501, 1.2002, 1.1152, 1.0366, 0.9995, 1.0127, 1.0391, 1.1182, 1.2334, 1.3706,
                  1.3521, 1.2231, 1.1343, 1.0439, 1.0103, 1.0176, 1.0425, 1.1274, 1.2495, 1.3931,
                  1.3662, 1.2529, 1.1519, 1.0815, 1.0215, 1.0337, 1.0698, 1.1426, 1.2764, 1.3848,
                  1.3662, 1.2983, 1.1782, 1.0957, 1.0527, 1.0527, 1.0889, 1.1768, 1.2871, 1.4312,
                  1.3857, 1.2769, 1.2109, 1.1201, 1.0835, 1.0972, 1.1592, 1.2021, 1.3701, 1.4551,
                  1.4370, 1.3052, 1.2080, 1.1641, 1.1060, 1.1216, 1.1729, 1.2554, 1.3467, 1.5156,
                  1.3643, 1.2729, 1.1655, 1.0986, 1.0679, 1.0801, 1.1274, 1.1914, 1.3027, 1.4160,
                  1.3633, 1.2397, 1.1313, 1.0674, 1.1191, 1.0376, 1.0894, 1.1616, 1.2734, 1.4092,
                  1.3306, 1.2109, 1.1201, 1.0483, 1.0762, 1.0005, 1.0620, 1.1265, 1.2388, 1.3726,
                  1.3296, 1.1963, 1.1050, 1.0425, 0.9932, 0.9966, 1.0459, 1.1187, 1.2305, 1.3589,
                  1.2905, 1.2002, 1.1143, 1.0313, 1.0024, 1.0112, 1.0420, 1.1177, 1.2202, 1.3472,
                  1.3203, 1.2051, 1.1289, 1.0396, 1.0088, 1.0093, 1.0474, 1.1157, 1.2354, 1.3530,
                  1.3296, 1.2603, 1.1465, 1.0815, 1.0244, 1.0303, 1.0654, 1.1436, 1.2456, 1.3716,
                  1.3506, 1.2676, 1.1875, 1.0889, 1.0581, 1.0537, 1.0957, 1.1602, 1.2769, 1.3716,
                  1.3740, 1.2783, 1.2075, 1.1289, 1.0732, 1.0977, 1.1357, 1.2012, 1.3096, 1.4375,
                  1.4141, 1.2925, 1.1987, 1.1592, 1.1113, 1.1143, 1.1421, 1.2280, 1.2983, 1.4912,
                  1.3135, 1.2544, 1.1445, 1.0825, 1.0601, 1.0713, 1.1206, 1.1782, 1.2803, 1.3774,
                  1.3076, 1.2163, 1.1206, 1.0513, 1.1357, 1.0308, 1.0815, 1.1387, 1.2539, 1.3564,
                  1.3213, 1.1919, 1.1187, 1.0410, 1.0913, 0.9946, 1.0630, 1.1270, 1.2100, 1.3496,
                  1.2813, 1.1777, 1.0923, 1.0405, 0.9766, 1.0039, 1.0356, 1.1084, 1.2212, 1.3237,
                  1.2651, 1.1821, 1.0991, 1.0317, 0.9995, 1.0093, 1.0532, 1.1074, 1.2124, 1.3315,
                  1.3071, 1.1899, 1.1426, 1.0366, 1.0063, 1.0234, 1.0264, 1.1216, 1.2056, 1.3311,
                  1.2949, 1.2378, 1.1304, 1.0688, 1.0156, 1.0264, 1.0728, 1.1240, 1.2466, 1.3389,
                  1.3628, 1.2495, 1.1899, 1.0933, 1.0503, 1.0576, 1.0830, 1.1650, 1.2485, 1.3682,
                  1.3501, 1.2480, 1.2065, 1.0947, 1.0688, 1.0928, 1.1201, 1.1797, 1.2983, 1.3813,
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
       5,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       {
          /*region 1 */
          {
            1.000,
            4.000,
          },
          /*region 2 */
          {
            4.100,
            16.000,
          },
          /*region 3 */
          {
            16.100,
            64.000,
          },
          /*region 4 */
          {
            64.100,
            512.000,
          },
          /*region 5 */
          {
            512.100,
            1024.000,
          },
       },
       {
           /*parameter 1 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               232, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               270, //k_thres
               113, //limit_base_green
               113, //limit_base_red
               3938, //limit_end_green
               4500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 2 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               232, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               270, //k_thres
               113, //limit_base_green
               113, //limit_base_red
               3938, //limit_end_green
               4500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 3 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               232, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               270, //k_thres
               113, //limit_base_green
               113, //limit_base_red
               3938, //limit_end_green
               4500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 4 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               232, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               270, //k_thres
               113, //limit_base_green
               113, //limit_base_red
               3938, //limit_end_green
               4500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 5 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               232, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               270, //k_thres
               113, //limit_base_green
               113, //limit_base_red
               3938, //limit_end_green
               4500, //limit_end_red
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
        1,//ae count
        4,//awb count
        1,//trigger_mode : 0 gain trigger 1 lux trigger
      /* aec trigger */
      {
        	/*trigger 0*/
        	{
        		0,
        		511,
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
      /* awb trigger */
      {
        	/*trigger 0*/
        	{
        		2500,
        		3400,
        	},
        	/*trigger 1*/
        	{
        		4000,
        		4500,
        	},
        	/*trigger 2*/
        	{
        		4800,
        		5600,
        	},
        	/*trigger 3*/
        	{
        		5800,
        		6700,
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
					2.4452,	-1.2932,-0.1520,
					-0.8132,2.0754,	-0.2622,
					-0.2876,-0.5863,1.8740,
                },
                /* ccm tl84 matrix */
                {
					2.1441,	-1.2084,0.0644,
					-0.7426,2.0979,	-0.3553,
					-0.0140,-1.0227,2.0368,
                },
                /* ccm d50 matrix */
                {
                     1.8688, -1.0480, 0.1792,
					-0.4812,1.7359,	-0.2547,
                     0.1518, -0.8789, 1.7270,
                },
                /* ccm d65 matrix */
                {
					1.9637,	-0.9612,-0.0025,
                    -0.3979, 1.6253, -0.2274,
					0.0572,	-0.8057,1.7485,
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
                },
                /* ccm tl84 matrix */
                {
                },
                /* ccm d50 matrix */
                {
                },
                /* ccm d65 matrix */
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
        	/*ae region 2*/
        	{
                /* ccm a matrix */
                {
                },
                /* ccm tl84 matrix */
                {
                },
                /* ccm d50 matrix */
                {
                },
                /* ccm d65 matrix */
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
            200.000,
          },
          /*aec trigger 2*/
          {
            220.000,
            345.000,
          },
          /*aec trigger 3*/
          {
            360.000,
            450.000,
          },
       },
       513,//gamma lut count
       /*isp_sub_module_gamma_lut_pra pra[MIN_TRIGGER_COUNT]; MIN_TRIGGER_COUNT=3*/
       {
          /* outdoor */
          {
                  0,  60, 121, 181, 243, 306, 369, 433, 495, 558, 619, 668, 709, 741, 774, 805, 838, 870, 903, 934, 962, 991,1017,1040,1066,1086,1110,
               1133,1153,1177,1197,1219,1239,1261,1279,1300,1320,1339,1359,1379,1400,1420,1440,1456,1476,1492,1512,1528,1548,1564,1584,1600,1615,1634,
               1650,1666,1684,1700,1717,1733,1748,1765,1779,1792,1806,1822,1834,1846,1860,1873,1884,1899,1910,1924,1936,1945,1955,1964,1975,1983,1993,
               2003,2012,2021,2032,2040,2048,2056,2066,2074,2083,2092,2100,2111,2119,2128,2137,2146,2155,2161,2171,2178,2186,2194,2199,2208,2213,2222,
               2228,2234,2240,2249,2256,2262,2269,2272,2279,2285,2292,2299,2303,2310,2318,2321,2329,2336,2340,2346,2353,2360,2363,2369,2375,2383,2389,
               2394,2401,2405,2412,2418,2423,2429,2435,2441,2447,2455,2459,2466,2470,2477,2484,2488,2495,2499,2506,2513,2517,2523,2527,2534,2541,2544,
               2551,2554,2561,2567,2570,2577,2583,2588,2591,2597,2602,2609,2614,2619,2625,2629,2635,2640,2644,2650,2656,2661,2665,2670,2676,2681,2687,
               2691,2696,2701,2705,2711,2716,2720,2727,2732,2738,2740,2746,2751,2757,2760,2766,2773,2776,2782,2785,2791,2797,2800,2805,2808,2814,2820,
               2823,2828,2831,2836,2842,2844,2850,2852,2858,2862,2866,2871,2876,2879,2884,2888,2891,2897,2900,2904,2910,2914,2919,2921,2926,2931,2936,
               2938,2943,2949,2951,2956,2959,2964,2969,2972,2977,2979,2984,2989,2992,2997,2999,3004,3009,3011,3016,3018,3023,3027,3031,3036,3040,3044,
               3048,3052,3055,3060,3063,3067,3073,3077,3081,3083,3088,3092,3097,3099,3104,3109,3112,3117,3119,3124,3129,3131,3136,3139,3143,3148,3150,
               3155,3157,3162,3167,3169,3174,3176,3180,3184,3188,3191,3195,3198,3202,3206,3208,3212,3215,3219,3224,3227,3231,3233,3236,3240,3244,3246,
               3251,3255,3257,3262,3264,3268,3272,3274,3279,3281,3285,3289,3292,3296,3298,3302,3307,3309,3313,3315,3319,3324,3326,3330,3332,3336,3341,
               3343,3347,3349,3353,3357,3359,3364,3366,3370,3374,3376,3380,3383,3387,3391,3393,3397,3400,3404,3406,3409,3413,3417,3420,3423,3427,3430,
               3433,3436,3439,3443,3446,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
               3528,3530,3534,3538,3542,3544,3547,3551,3556,3559,3562,3567,3569,3573,3577,3580,3583,3587,3591,3594,3598,3602,3606,3610,3613,3617,3621,
               3624,3628,3631,3635,3640,3644,3648,3650,3654,3658,3662,3665,3669,3674,3676,3681,3683,3688,3693,3696,3701,3703,3708,3713,3716,3721,3723,
               3729,3734,3736,3742,3744,3750,3755,3758,3763,3766,3772,3777,3780,3786,3789,3795,3800,3803,3809,3812,3818,3824,3827,3833,3836,3842,3848,
               3851,3857,3863,3868,3871,3876,3880,3887,3892,3896,3902,3906,3911,3916,3920,3925,3930,3935,3939,3951,3962,3977,3998,4024,4047,4071,4095,
          },
          /* indoor */
          {
                  0,  44,  89, 133, 177, 221, 263, 305, 345, 385, 424, 468, 513, 556, 600, 638, 678, 717, 758, 795, 829, 862, 896, 927, 962, 992,1025,
               1055,1084,1114,1142,1171,1195,1223,1246,1269,1296,1318,1340,1360,1382,1405,1424,1447,1468,1486,1505,1522,1543,1560,1578,1598,1615,1632,
               1652,1669,1684,1700,1719,1733,1748,1765,1779,1792,1806,1822,1834,1846,1860,1873,1884,1899,1910,1924,1936,1944,1953,1961,1970,1978,1986,
               1995,2003,2010,2020,2028,2036,2043,2053,2060,2068,2078,2085,2093,2100,2110,2117,2125,2133,2141,2148,2157,2165,2173,2180,2187,2194,2202,
               2209,2215,2222,2230,2235,2243,2249,2255,2265,2272,2279,2283,2290,2298,2306,2310,2319,2327,2331,2340,2344,2352,2360,2365,2373,2377,2385,
               2393,2397,2405,2409,2417,2424,2428,2436,2440,2447,2455,2459,2466,2470,2477,2484,2488,2495,2499,2506,2513,2517,2523,2527,2534,2541,2544,
               2551,2554,2561,2567,2570,2577,2583,2588,2591,2597,2602,2609,2614,2619,2625,2629,2635,2640,2644,2650,2656,2661,2665,2670,2676,2681,2687,
               2691,2696,2701,2705,2711,2716,2720,2727,2732,2738,2740,2746,2751,2757,2760,2766,2773,2776,2782,2785,2791,2797,2800,2805,2808,2814,2820,
               2823,2828,2831,2836,2842,2844,2850,2852,2858,2862,2866,2871,2876,2879,2884,2888,2891,2897,2900,2904,2910,2914,2919,2921,2926,2931,2936,
               2938,2943,2949,2951,2956,2959,2964,2969,2972,2977,2979,2984,2989,2992,2997,2999,3004,3009,3011,3016,3018,3023,3027,3031,3036,3040,3044,
               3048,3052,3055,3060,3063,3067,3073,3077,3081,3083,3088,3092,3097,3099,3104,3109,3112,3117,3119,3124,3129,3131,3136,3139,3143,3148,3150,
               3155,3157,3162,3167,3169,3174,3176,3180,3184,3188,3191,3195,3198,3202,3206,3208,3212,3215,3219,3224,3227,3231,3233,3236,3240,3244,3246,
               3251,3255,3257,3262,3264,3268,3272,3274,3279,3281,3285,3289,3292,3296,3298,3302,3307,3309,3313,3315,3319,3324,3326,3330,3332,3336,3341,
               3343,3347,3349,3353,3357,3359,3364,3366,3370,3374,3376,3380,3383,3387,3391,3393,3397,3400,3404,3406,3409,3413,3417,3420,3423,3427,3430,
               3433,3436,3439,3443,3446,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
               3528,3530,3534,3538,3542,3544,3547,3551,3556,3559,3562,3567,3569,3573,3577,3580,3583,3587,3591,3594,3598,3602,3606,3610,3613,3617,3621,
               3624,3628,3631,3635,3640,3644,3648,3650,3654,3658,3662,3665,3669,3674,3676,3681,3683,3688,3693,3696,3701,3703,3708,3713,3716,3721,3723,
               3729,3734,3736,3742,3744,3750,3755,3758,3763,3766,3772,3777,3780,3786,3789,3795,3800,3803,3809,3812,3818,3824,3827,3833,3836,3842,3848,
               3851,3857,3863,3868,3871,3876,3880,3887,3892,3896,3902,3906,3911,3916,3920,3925,3930,3935,3939,3951,3962,3977,3998,4024,4047,4071,4095,
          },
          /* lowlight */
          {
                 20,  85, 152, 216, 276, 329, 393, 457, 519, 574, 620, 665, 710, 754, 793, 824, 854, 883, 913, 940, 966, 991,1018,1041,1069,1092,1118,
               1142,1165,1187,1210,1232,1250,1272,1290,1308,1329,1346,1363,1378,1395,1412,1427,1445,1461,1477,1497,1514,1534,1550,1570,1586,1602,1620,
               1637,1652,1671,1687,1704,1720,1732,1744,1756,1769,1780,1792,1805,1816,1827,1840,1851,1862,1872,1885,1895,1904,1916,1926,1935,1944,1956,
               1965,1973,1983,1992,2001,2011,2020,2029,2038,2046,2054,2062,2071,2078,2087,2096,2103,2112,2118,2128,2135,2143,2151,2157,2166,2172,2182,
               2188,2195,2202,2212,2219,2227,2234,2238,2246,2254,2262,2270,2275,2283,2292,2296,2305,2314,2318,2327,2335,2342,2346,2354,2361,2371,2377,
               2383,2392,2397,2405,2412,2418,2425,2433,2440,2447,2455,2459,2466,2470,2477,2484,2488,2495,2499,2506,2513,2517,2523,2527,2534,2541,2544,
               2551,2554,2561,2567,2570,2577,2583,2588,2591,2597,2602,2609,2614,2619,2625,2629,2635,2640,2644,2650,2656,2661,2665,2670,2676,2681,2687,
               2691,2696,2701,2705,2711,2716,2720,2727,2732,2738,2740,2746,2751,2757,2760,2766,2773,2776,2782,2785,2791,2797,2800,2805,2808,2814,2820,
               2823,2828,2831,2836,2842,2844,2850,2852,2858,2862,2866,2871,2876,2879,2884,2888,2891,2897,2900,2904,2910,2914,2919,2921,2926,2931,2936,
               2938,2943,2949,2951,2956,2959,2964,2969,2972,2977,2979,2984,2989,2992,2997,2999,3004,3009,3011,3016,3018,3023,3027,3031,3036,3040,3044,
               3048,3052,3055,3060,3063,3067,3073,3077,3081,3083,3088,3092,3097,3099,3104,3109,3112,3117,3119,3124,3129,3131,3136,3139,3143,3148,3150,
               3155,3157,3162,3167,3169,3174,3176,3180,3184,3188,3191,3195,3198,3202,3206,3208,3212,3215,3219,3224,3227,3231,3233,3236,3240,3244,3246,
               3251,3255,3257,3262,3264,3268,3272,3274,3279,3281,3285,3289,3292,3296,3298,3302,3307,3309,3313,3315,3319,3324,3326,3330,3332,3336,3341,
               3343,3347,3349,3353,3357,3359,3364,3366,3370,3374,3376,3380,3383,3387,3391,3393,3397,3400,3404,3406,3409,3413,3417,3420,3423,3427,3430,
               3433,3436,3439,3443,3446,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
               3528,3530,3534,3538,3542,3544,3547,3551,3556,3559,3562,3567,3569,3573,3577,3580,3583,3587,3591,3594,3598,3602,3606,3610,3613,3617,3621,
               3624,3628,3631,3635,3640,3644,3648,3650,3654,3658,3662,3665,3669,3674,3676,3681,3683,3688,3693,3696,3701,3703,3708,3713,3716,3721,3723,
               3729,3734,3736,3742,3744,3750,3755,3758,3763,3766,3772,3777,3780,3786,3789,3795,3800,3803,3809,3812,3818,3824,3827,3833,3836,3842,3848,
               3851,3857,3863,3868,3871,3876,3880,3887,3892,3896,3902,3906,3911,3916,3920,3925,3930,3935,3939,3951,3962,3977,3998,4024,4047,4071,4095,
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
       3,
       /*count_awb*/
       4,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            0.000,
            170.000,
          },
          /* aec trigger 2 */
          {
            200.000,
            370.000,
          },
          /* aec trigger 3 */
          {
            411.000,
            511.000,
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
            2000.000,
            3300.000,
          },
          /* awb trigger 2 */
          {
            3700.000,
            4300.000,
          },
          /* awb trigger 3 */
          {
            4700.000,
            5300.000,
          },
          /* awb trigger 4 */
          {
            5500.000,
            7500.000,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                  /* lut3d table 1 */
                  {
                           0,    0,    0,
                        2048,    0,    0,
                        4095,    0,    0,
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
                        1536,  512,    0,
                        3584,  512,    0,
                        1024, 1024,    0,
                        3072, 1024,    0,
                         512, 1536,    0,
                        2560, 1536,    0,
                           0, 2048,    0,
                        2048, 2048,    0,
                        4095, 2048,    0,
                        1536, 2560,    0,
                        3584, 2560,    0,
                        1024, 3072,    0,
                        3072, 3072,    0,
                         512, 3584,    0,
                        2560, 3584,    0,
                           0, 4095,    0,
                        2048, 4095,    0,
                        4095, 4095,    0,
                        1536,    0,  512,
                        3584,    0,  512,
                        1024,  512,  512,
                        3072,  512,  512,
                         512, 1024,  512,
                        2560, 1024,  512,
                           0, 1536,  512,
                        2048, 1536,  512,
                        4095, 1536,  512,
                        1536, 2048,  512,
                        3584, 2048,  512,
                        1024, 2560,  512,
                        3072, 2560,  512,
                         512, 3072,  512,
                        2560, 3072,  512,
                           0, 3584,  512,
                        2048, 3584,  512,
                        4095, 3584,  512,
                        1536, 4095,  512,
                        3584, 4095,  512,
                        1024,    0, 1024,
                        3072,    0, 1024,
                         512,  512, 1024,
                        2560,  512, 1024,
                           0, 1024, 1024,
                        2048, 1024, 1024,
                        4095, 1024, 1024,
                        1536, 1536, 1024,
                        3584, 1536, 1024,
                        1024, 2048, 1024,
                        3072, 2048, 1024,
                         512, 2560, 1024,
                        2560, 2560, 1024,
                           0, 3072, 1024,
                        2048, 3072, 1024,
                        4095, 3072, 1024,
                        1536, 3584, 1024,
                        3584, 3584, 1024,
                        1024, 4095, 1024,
                        3072, 4095, 1024,
                         512,    0, 1536,
                        2560,    0, 1536,
                           0,  512, 1536,
                        2048,  512, 1536,
                        4095,  512, 1536,
                        1536, 1024, 1536,
                        3584, 1024, 1536,
                        1024, 1536, 1536,
                        3072, 1536, 1536,
                         512, 2048, 1536,
                        2560, 2048, 1536,
                           0, 2560, 1536,
                        2048, 2560, 1536,
                        4095, 2560, 1536,
                        1536, 3072, 1536,
                        3584, 3072, 1536,
                        1024, 3584, 1536,
                        3072, 3584, 1536,
                         512, 4095, 1536,
                        2560, 4095, 1536,
                           0,    0, 2048,
                        2048,    0, 2048,
                        4095,    0, 2048,
                        1536,  512, 2048,
                        3584,  512, 2048,
                        1024, 1024, 2048,
                        3072, 1024, 2048,
                         512, 1536, 2048,
                        2560, 1536, 2048,
                           0, 2048, 2048,
                        2048, 2048, 2048,
                        4095, 2048, 2048,
                        1536, 2560, 2048,
                        3584, 2560, 2048,
                        1024, 3072, 2048,
                        3072, 3072, 2048,
                         512, 3584, 2048,
                        2560, 3584, 2048,
                           0, 4095, 2048,
                        2048, 4095, 2048,
                        4095, 4095, 2048,
                        1536,    0, 2560,
                        3584,    0, 2560,
                        1024,  512, 2560,
                        3072,  512, 2560,
                         512, 1024, 2560,
                        2560, 1024, 2560,
                           0, 1536, 2560,
                        2048, 1536, 2560,
                        4095, 1536, 2560,
                        1536, 2048, 2560,
                        3584, 2048, 2560,
                        1024, 2560, 2560,
                        3072, 2560, 2560,
                         512, 3072, 2560,
                        2560, 3072, 2560,
                           0, 3584, 2560,
                        2048, 3584, 2560,
                        4095, 3584, 2560,
                        1536, 4095, 2560,
                        3584, 4095, 2560,
                        1024,    0, 3072,
                        3072,    0, 3072,
                         512,  512, 3072,
                        2560,  512, 3072,
                           0, 1024, 3072,
                        2048, 1024, 3072,
                        4095, 1024, 3072,
                        1536, 1536, 3072,
                        3584, 1536, 3072,
                        1024, 2048, 3072,
                        3072, 2048, 3072,
                         512, 2560, 3072,
                        2560, 2560, 3072,
                           0, 3072, 3072,
                        2048, 3072, 3072,
                        4095, 3072, 3072,
                        1536, 3584, 3072,
                        3584, 3584, 3072,
                        1024, 4095, 3072,
                        3072, 4095, 3072,
                         512,    0, 3584,
                        2560,    0, 3584,
                           0,  512, 3584,
                        2048,  512, 3584,
                        4095,  512, 3584,
                        1536, 1024, 3584,
                        3584, 1024, 3584,
                        1024, 1536, 3584,
                        3072, 1536, 3584,
                         512, 2048, 3584,
                        2560, 2048, 3584,
                           0, 2560, 3584,
                        2048, 2560, 3584,
                        4095, 2560, 3584,
                        1536, 3072, 3584,
                        3584, 3072, 3584,
                        1024, 3584, 3584,
                        3072, 3584, 3584,
                         512, 4095, 3584,
                        2560, 4095, 3584,
                           0,    0, 4095,
                        2048,    0, 4095,
                        4095,    0, 4095,
                        1536,  512, 4095,
                        3584,  512, 4095,
                        1024, 1024, 4095,
                        3072, 1024, 4095,
                         512, 1536, 4095,
                        2560, 1536, 4095,
                           0, 2048, 4095,
                        2048, 2048, 4095,
                        4095, 2048, 4095,
                        1536, 2560, 4095,
                        3584, 2560, 4095,
                        1024, 3072, 4095,
                        3072, 3072, 4095,
                         512, 3584, 4095,
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
                        1024, 3584,    0,
                        3072, 3584,    0,
                         512, 4095,    0,
                        2560, 4095,    0,
                           0,    0,  512,
                        2048,    0,  512,
                        4095,    0,  512,
                        1536,  512,  512,
                        3584,  512,  512,
                        1024, 1024,  512,
                        3072, 1024,  512,
                         512, 1536,  512,
                        2560, 1536,  512,
                           0, 2048,  512,
                        2048, 2048,  512,
                        4095, 2048,  512,
                        1536, 2560,  512,
                        3584, 2560,  512,
                        1024, 3072,  512,
                        3072, 3072,  512,
                         512, 3584,  512,
                        2560, 3584,  512,
                           0, 4095,  512,
                        2048, 4095,  512,
                        4095, 4095,  512,
                        1536,    0, 1024,
                        3584,    0, 1024,
                        1024,  512, 1024,
                        3072,  512, 1024,
                         512, 1024, 1024,
                        2560, 1024, 1024,
                           0, 1536, 1024,
                        2048, 1536, 1024,
                        4095, 1536, 1024,
                        1536, 2048, 1024,
                        3584, 2048, 1024,
                        1024, 2560, 1024,
                        3072, 2560, 1024,
                         512, 3072, 1024,
                        2560, 3072, 1024,
                           0, 3584, 1024,
                        2048, 3584, 1024,
                        4095, 3584, 1024,
                        1536, 4095, 1024,
                        3584, 4095, 1024,
                        1024,    0, 1536,
                        3072,    0, 1536,
                         512,  512, 1536,
                        2560,  512, 1536,
                           0, 1024, 1536,
                        2048, 1024, 1536,
                        4095, 1024, 1536,
                        1536, 1536, 1536,
                        3584, 1536, 1536,
                        1024, 2048, 1536,
                        3072, 2048, 1536,
                         512, 2560, 1536,
                        2560, 2560, 1536,
                           0, 3072, 1536,
                        2048, 3072, 1536,
                        4095, 3072, 1536,
                        1536, 3584, 1536,
                        3584, 3584, 1536,
                        1024, 4095, 1536,
                        3072, 4095, 1536,
                         512,    0, 2048,
                        2560,    0, 2048,
                           0,  512, 2048,
                        2048,  512, 2048,
                        4095,  512, 2048,
                        1536, 1024, 2048,
                        3584, 1024, 2048,
                        1024, 1536, 2048,
                        3072, 1536, 2048,
                         512, 2048, 2048,
                        2560, 2048, 2048,
                           0, 2560, 2048,
                        2048, 2560, 2048,
                        4095, 2560, 2048,
                        1536, 3072, 2048,
                        3584, 3072, 2048,
                        1024, 3584, 2048,
                        3072, 3584, 2048,
                         512, 4095, 2048,
                        2560, 4095, 2048,
                           0,    0, 2560,
                        2048,    0, 2560,
                        4095,    0, 2560,
                        1536,  512, 2560,
                        3584,  512, 2560,
                        1024, 1024, 2560,
                        3072, 1024, 2560,
                         512, 1536, 2560,
                        2560, 1536, 2560,
                           0, 2048, 2560,
                        2048, 2048, 2560,
                        4095, 2048, 2560,
                        1536, 2560, 2560,
                        3584, 2560, 2560,
                        1024, 3072, 2560,
                        3072, 3072, 2560,
                         512, 3584, 2560,
                        2560, 3584, 2560,
                           0, 4095, 2560,
                        2048, 4095, 2560,
                        4095, 4095, 2560,
                        1536,    0, 3072,
                        3584,    0, 3072,
                        1024,  512, 3072,
                        3072,  512, 3072,
                         512, 1024, 3072,
                        2560, 1024, 3072,
                           0, 1536, 3072,
                        2048, 1536, 3072,
                        4095, 1536, 3072,
                        1536, 2048, 3072,
                        3584, 2048, 3072,
                        1024, 2560, 3072,
                        3072, 2560, 3072,
                         512, 3072, 3072,
                        2560, 3072, 3072,
                           0, 3584, 3072,
                        2048, 3584, 3072,
                        4095, 3584, 3072,
                        1536, 4095, 3072,
                        3584, 4095, 3072,
                        1024,    0, 3584,
                        3072,    0, 3584,
                         512,  512, 3584,
                        2560,  512, 3584,
                           0, 1024, 3584,
                        2048, 1024, 3584,
                        4095, 1024, 3584,
                        1536, 1536, 3584,
                        3584, 1536, 3584,
                        1024, 2048, 3584,
                        3072, 2048, 3584,
                         512, 2560, 3584,
                        2560, 2560, 3584,
                           0, 3072, 3584,
                        2048, 3072, 3584,
                        4095, 3072, 3584,
                        1536, 3584, 3584,
                        3584, 3584, 3584,
                        1024, 4095, 3584,
                        3072, 4095, 3584,
                         512,    0, 4095,
                        2560,    0, 4095,
                           0,  512, 4095,
                        2048,  512, 4095,
                        4095,  512, 4095,
                        1536, 1024, 4095,
                        3584, 1024, 4095,
                        1024, 1536, 4095,
                        3072, 1536, 4095,
                         512, 2048, 4095,
                        2560, 2048, 4095,
                           0, 2560, 4095,
                        2048, 2560, 4095,
                        4095, 2560, 4095,
                        1536, 3072, 4095,
                        3584, 3072, 4095,
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
                        2560,  512,    0,
                           0, 1024,    0,
                        2048, 1024,    0,
                        4095, 1024,    0,
                        1536, 1536,    0,
                        3584, 1536,    0,
                        1024, 2048,    0,
                        3072, 2048,    0,
                         512, 2560,    0,
                        2560, 2560,    0,
                           0, 3072,    0,
                        2048, 3072,    0,
                        4095, 3072,    0,
                        1536, 3584,    0,
                        3584, 3584,    0,
                        1024, 4095,    0,
                        3072, 4095,    0,
                         512,    0,  512,
                        2560,    0,  512,
                           0,  512,  512,
                        2048,  512,  512,
                        4095,  512,  512,
                        1536, 1024,  512,
                        3584, 1024,  512,
                        1024, 1536,  512,
                        3072, 1536,  512,
                         512, 2048,  512,
                        2560, 2048,  512,
                           0, 2560,  512,
                        2048, 2560,  512,
                        4095, 2560,  512,
                        1536, 3072,  512,
                        3584, 3072,  512,
                        1024, 3584,  512,
                        3072, 3584,  512,
                         512, 4095,  512,
                        2560, 4095,  512,
                           0,    0, 1024,
                        2048,    0, 1024,
                        4095,    0, 1024,
                        1536,  512, 1024,
                        3584,  512, 1024,
                        1024, 1024, 1024,
                        3072, 1024, 1024,
                         512, 1536, 1024,
                        2560, 1536, 1024,
                           0, 2048, 1024,
                        2048, 2048, 1024,
                        4095, 2048, 1024,
                        1536, 2560, 1024,
                        3584, 2560, 1024,
                        1024, 3072, 1024,
                        3072, 3072, 1024,
                         512, 3584, 1024,
                        2560, 3584, 1024,
                           0, 4095, 1024,
                        2048, 4095, 1024,
                        4095, 4095, 1024,
                        1536,    0, 1536,
                        3584,    0, 1536,
                        1024,  512, 1536,
                        3072,  512, 1536,
                         512, 1024, 1536,
                        2560, 1024, 1536,
                           0, 1536, 1536,
                        2048, 1536, 1536,
                        4095, 1536, 1536,
                        1536, 2048, 1536,
                        3584, 2048, 1536,
                        1024, 2560, 1536,
                        3072, 2560, 1536,
                         512, 3072, 1536,
                        2560, 3072, 1536,
                           0, 3584, 1536,
                        2048, 3584, 1536,
                        4095, 3584, 1536,
                        1536, 4095, 1536,
                        3584, 4095, 1536,
                        1024,    0, 2048,
                        3072,    0, 2048,
                         512,  512, 2048,
                        2560,  512, 2048,
                           0, 1024, 2048,
                        2048, 1024, 2048,
                        4095, 1024, 2048,
                        1536, 1536, 2048,
                        3584, 1536, 2048,
                        1024, 2048, 2048,
                        3072, 2048, 2048,
                         512, 2560, 2048,
                        2560, 2560, 2048,
                           0, 3072, 2048,
                        2048, 3072, 2048,
                        4095, 3072, 2048,
                        1536, 3584, 2048,
                        3584, 3584, 2048,
                        1024, 4095, 2048,
                        3072, 4095, 2048,
                         512,    0, 2560,
                        2560,    0, 2560,
                           0,  512, 2560,
                        2048,  512, 2560,
                        4095,  512, 2560,
                        1536, 1024, 2560,
                        3584, 1024, 2560,
                        1024, 1536, 2560,
                        3072, 1536, 2560,
                         512, 2048, 2560,
                        2560, 2048, 2560,
                           0, 2560, 2560,
                        2048, 2560, 2560,
                        4095, 2560, 2560,
                        1536, 3072, 2560,
                        3584, 3072, 2560,
                        1024, 3584, 2560,
                        3072, 3584, 2560,
                         512, 4095, 2560,
                        2560, 4095, 2560,
                           0,    0, 3072,
                        2048,    0, 3072,
                        4095,    0, 3072,
                        1536,  512, 3072,
                        3584,  512, 3072,
                        1024, 1024, 3072,
                        3072, 1024, 3072,
                         512, 1536, 3072,
                        2560, 1536, 3072,
                           0, 2048, 3072,
                        2048, 2048, 3072,
                        4095, 2048, 3072,
                        1536, 2560, 3072,
                        3584, 2560, 3072,
                        1024, 3072, 3072,
                        3072, 3072, 3072,
                         512, 3584, 3072,
                        2560, 3584, 3072,
                           0, 4095, 3072,
                        2048, 4095, 3072,
                        4095, 4095, 3072,
                        1536,    0, 3584,
                        3584,    0, 3584,
                        1024,  512, 3584,
                        3072,  512, 3584,
                         512, 1024, 3584,
                        2560, 1024, 3584,
                           0, 1536, 3584,
                        2048, 1536, 3584,
                        4095, 1536, 3584,
                        1536, 2048, 3584,
                        3584, 2048, 3584,
                        1024, 2560, 3584,
                        3072, 2560, 3584,
                         512, 3072, 3584,
                        2560, 3072, 3584,
                           0, 3584, 3584,
                        2048, 3584, 3584,
                        4095, 3584, 3584,
                        1536, 4095, 3584,
                        3584, 4095, 3584,
                        1024,    0, 4095,
                        3072,    0, 4095,
                         512,  512, 4095,
                        2560,  512, 4095,
                           0, 1024, 4095,
                        2048, 1024, 4095,
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
                        3072,  512,    0,
                         512, 1024,    0,
                        2560, 1024,    0,
                           0, 1536,    0,
                        2048, 1536,    0,
                        4095, 1536,    0,
                        1536, 2048,    0,
                        3584, 2048,    0,
                        1024, 2560,    0,
                        3072, 2560,    0,
                         512, 3072,    0,
                        2560, 3072,    0,
                           0, 3584,    0,
                        2048, 3584,    0,
                        4095, 3584,    0,
                        1536, 4095,    0,
                        3584, 4095,    0,
                        1024,    0,  512,
                        3072,    0,  512,
                         512,  512,  512,
                        2560,  512,  512,
                           0, 1024,  512,
                        2048, 1024,  512,
                        4095, 1024,  512,
                        1536, 1536,  512,
                        3584, 1536,  512,
                        1024, 2048,  512,
                        3072, 2048,  512,
                         512, 2560,  512,
                        2560, 2560,  512,
                           0, 3072,  512,
                        2048, 3072,  512,
                        4095, 3072,  512,
                        1536, 3584,  512,
                        3584, 3584,  512,
                        1024, 4095,  512,
                        3072, 4095,  512,
                         512,    0, 1024,
                        2560,    0, 1024,
                           0,  512, 1024,
                        2048,  512, 1024,
                        4095,  512, 1024,
                        1536, 1024, 1024,
                        3584, 1024, 1024,
                        1024, 1536, 1024,
                        3072, 1536, 1024,
                         512, 2048, 1024,
                        2560, 2048, 1024,
                           0, 2560, 1024,
                        2048, 2560, 1024,
                        4095, 2560, 1024,
                        1536, 3072, 1024,
                        3584, 3072, 1024,
                        1024, 3584, 1024,
                        3072, 3584, 1024,
                         512, 4095, 1024,
                        2560, 4095, 1024,
                           0,    0, 1536,
                        2048,    0, 1536,
                        4095,    0, 1536,
                        1536,  512, 1536,
                        3584,  512, 1536,
                        1024, 1024, 1536,
                        3072, 1024, 1536,
                         512, 1536, 1536,
                        2560, 1536, 1536,
                           0, 2048, 1536,
                        2048, 2048, 1536,
                        4095, 2048, 1536,
                        1536, 2560, 1536,
                        3584, 2560, 1536,
                        1024, 3072, 1536,
                        3072, 3072, 1536,
                         512, 3584, 1536,
                        2560, 3584, 1536,
                           0, 4095, 1536,
                        2048, 4095, 1536,
                        4095, 4095, 1536,
                        1536,    0, 2048,
                        3584,    0, 2048,
                        1024,  512, 2048,
                        3072,  512, 2048,
                         512, 1024, 2048,
                        2560, 1024, 2048,
                           0, 1536, 2048,
                        2048, 1536, 2048,
                        4095, 1536, 2048,
                        1536, 2048, 2048,
                        3584, 2048, 2048,
                        1024, 2560, 2048,
                        3072, 2560, 2048,
                         512, 3072, 2048,
                        2560, 3072, 2048,
                           0, 3584, 2048,
                        2048, 3584, 2048,
                        4095, 3584, 2048,
                        1536, 4095, 2048,
                        3584, 4095, 2048,
                        1024,    0, 2560,
                        3072,    0, 2560,
                         512,  512, 2560,
                        2560,  512, 2560,
                           0, 1024, 2560,
                        2048, 1024, 2560,
                        4095, 1024, 2560,
                        1536, 1536, 2560,
                        3584, 1536, 2560,
                        1024, 2048, 2560,
                        3072, 2048, 2560,
                         512, 2560, 2560,
                        2560, 2560, 2560,
                           0, 3072, 2560,
                        2048, 3072, 2560,
                        4095, 3072, 2560,
                        1536, 3584, 2560,
                        3584, 3584, 2560,
                        1024, 4095, 2560,
                        3072, 4095, 2560,
                         512,    0, 3072,
                        2560,    0, 3072,
                           0,  512, 3072,
                        2048,  512, 3072,
                        4095,  512, 3072,
                        1536, 1024, 3072,
                        3584, 1024, 3072,
                        1024, 1536, 3072,
                        3072, 1536, 3072,
                         512, 2048, 3072,
                        2560, 2048, 3072,
                           0, 2560, 3072,
                        2048, 2560, 3072,
                        4095, 2560, 3072,
                        1536, 3072, 3072,
                        3584, 3072, 3072,
                        1024, 3584, 3072,
                        3072, 3584, 3072,
                         512, 4095, 3072,
                        2560, 4095, 3072,
                           0,    0, 3584,
                        2048,    0, 3584,
                        4095,    0, 3584,
                        1536,  512, 3584,
                        3584,  512, 3584,
                        1024, 1024, 3584,
                        3072, 1024, 3584,
                         512, 1536, 3584,
                        2560, 1536, 3584,
                           0, 2048, 3584,
                        2048, 2048, 3584,
                        4095, 2048, 3584,
                        1536, 2560, 3584,
                        3584, 2560, 3584,
                        1024, 3072, 3584,
                        3072, 3072, 3584,
                         512, 3584, 3584,
                        2560, 3584, 3584,
                           0, 4095, 3584,
                        2048, 4095, 3584,
                        4095, 4095, 3584,
                        1536,    0, 4095,
                        3584,    0, 4095,
                        1024,  512, 4095,
                        3072,  512, 4095,
                         512, 1024, 4095,
                        2560, 1024, 4095,
                           0, 1536, 4095,
                        2048, 1536, 4095,
                        4095, 1536, 4095,
                        1536, 2048, 4095,
                        3584, 2048, 4095,
                        1024, 2560, 4095,
                        3072, 2560, 4095,
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
       5,
       /*count_awb*/
       1,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       1,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            375.000,
          },
          /* aec trigger 2 */
          {
            390.000,
            420.000,
          },
          /* aec trigger 3 */
          {
            440.000,
            450.000,
          },
          /* aec trigger 4 */
          {
            451.000,
            490.000,
          },
          /* aec trigger 5 */
          {
            500.000,
            511.000,
          },
       },
       /* awb trigger */
       {
          /* awb trigger 1 */
          {
            0.000,
            7500.000,
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
                  0.900000, //saturation
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
                  0.650000, //saturation
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
                  0.500000, //saturation
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
                  0.350000, //saturation
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
       9,
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
            2048.000,
          },
       },
       /*isp_sub_module_lee_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               80,  //sharpen_pos
               80,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               3, 5, 500, 600, //edge_th 0 ~3
               8, 20, 700, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               75,  //sharpen_pos
               75,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               3, 5, 500, 600, //edge_th 0 ~3
               8, 20, 800, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               70,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               3, 5, 500, 600, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               60,  //sharpen_fu
               13,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               3, 5, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               50,  //sharpen_pos
               50,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               3, 5, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               40,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               3, 5, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               0,  //sharpen_pos
               0,  //sharpen_fu
               10,  //noise_th
               100,  //order_en
               100, //limit_max
               100, //limit_min
               5, 6, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 8 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               0,  //sharpen_pos
               0,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               10, 60, 90, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 9 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               0,  //sharpen_pos
               0,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               30, 70, 110, 200, //edge_th 0 ~3
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
            2048.000,
          },
       },
       /* isp_sub_module_cnf_pra pra[MIDDLE_TRIGGER_COUNT] */
       {
          /* para 1 */
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
          /* para 2 */
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
          /* para 3 */
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
          /* para 4 */
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
          /* para 5 */
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
          /* para 6 */
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
             12,  //zoom_par
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
            4.000,
          },
          /* aec trigger 2 */
          {
            8.000,
            32.000,
          },
          /* aec trigger 3 */
          {
            48.000,
            128.000,
          },
          /* aec trigger 4 */
          {
            256.000,
            256.100,
          },
          /* aec trigger 5 */
          {
            512.000,
            512.100,
          },
          /* aec trigger 6 */
          {
            768.000,
            768.100,
          },
          /* aec trigger 7 */
          {
            1024.000,
            1024.100,
          },
          /* aec trigger 8 */
          {
            1536.000,
            1536.100,
          },
          /* aec trigger 9 */
          {
            2048.000,
            2048.000,
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
                   426,348,299,263,236,213,193,177,162,148,136,125,115,105,96,88,80,73,66,59,53,47,41,36,31,26,21,16,11,7,3,0,
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
                   985,803,690,609,545,492,447,408,373,343,314,289,265,243,223,204,186,169,153,138,123,109,96,83,71,60,48,37,27,17,7,0,
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
                   1313,1070,921,812,726,656,596,544,498,457,419,385,354,325,297,272,248,225,204,184,164,146,128,111,95,80,65,50,36,23,10,0,
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
                   1641,1338,1151,1015,908,820,745,680,623,571,524,482,442,406,372,340,310,282,255,230,205,182,160,139,119,99,81,63,45,28,12,0,
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
                   1970,1606,1381,1218,1090,984,895,816,747,686,629,578,531,487,446,408,372,338,306,276,247,219,192,167,143,119,97,75,54,34,15,0,
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
                   1970,1606,1381,1218,1090,984,895,816,747,686,629,578,531,487,446,408,372,338,306,276,247,219,192,167,143,119,97,75,54,34,15,0,
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
/* 	//isp_sub_module_scaler_tuning_t
	{
		{
			1,
			{
				{
				3840,
				2160,
				2,
				2,
				},
			},
		},

	},
	//isp_sub_module_scaler_tuning_t */
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
        412,
        /* ev0_count */
        412,
        /* ev2_count */
        412,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        128,
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
          {256,  1142  },        /* Gain= 1.000000 Exposure Index= 227 */
          {256,  1177  },        /* Gain= 1.000000 Exposure Index= 228 */
          {256,  1213  },        /* Gain= 1.000000 Exposure Index= 229 */
          {256,  1250  },        /* Gain= 1.000000 Exposure Index= 230 */
          {256,  1288  },        /* Gain= 1.000000 Exposure Index= 231 */
          {256,  1327  },        /* Gain= 1.000000 Exposure Index= 232 */
          {256,  1367  },        /* Gain= 1.000000 Exposure Index= 233 */
          {256,  1409  },        /* Gain= 1.000000 Exposure Index= 234 */
          {256,  1452  },        /* Gain= 1.000000 Exposure Index= 235 */
          {256,  1496  },        /* Gain= 1.000000 Exposure Index= 236 */
          {256,  1541  },        /* Gain= 1.000000 Exposure Index= 237 */
          {256,  1588  },        /* Gain= 1.000000 Exposure Index= 238 */
          {256,  1636  },        /* Gain= 1.000000 Exposure Index= 239 */
          {256,  1686  },        /* Gain= 1.000000 Exposure Index= 240 */
          {256,  1737  },        /* Gain= 1.000000 Exposure Index= 241 */
          {256,  1790  },        /* Gain= 1.000000 Exposure Index= 242 */
          {256,  1844  },        /* Gain= 1.000000 Exposure Index= 243 */
          {256,  1900  },        /* Gain= 1.000000 Exposure Index= 244 */
          {256,  1957  },        /* Gain= 1.000000 Exposure Index= 245 */
          {256,  2016  },        /* Gain= 1.000000 Exposure Index= 246 */
          {256,  2077  },        /* Gain= 1.000000 Exposure Index= 247 */
          {256,  2140  },        /* Gain= 1.000000 Exposure Index= 248 */
          {256,  2205  },        /* Gain= 1.000000 Exposure Index= 249 */
          {259,  2250  },        /* Gain= 1.011719 Exposure Index= 250 */
          {267,  2250  },        /* Gain= 1.042969 Exposure Index= 251 */
          {276,  2250  },        /* Gain= 1.078125 Exposure Index= 252 */
          {285,  2250  },        /* Gain= 1.113281 Exposure Index= 253 */
          {294,  2250  },        /* Gain= 1.148438 Exposure Index= 254 */
          {303,  2250  },        /* Gain= 1.183594 Exposure Index= 255 */
          {313,  2250  },        /* Gain= 1.222656 Exposure Index= 256 */
          {323,  2250  },        /* Gain= 1.261719 Exposure Index= 257 */
          {333,  2250  },        /* Gain= 1.300781 Exposure Index= 258 */
          {343,  2250  },        /* Gain= 1.339844 Exposure Index= 259 */
          {354,  2250  },        /* Gain= 1.382813 Exposure Index= 260 */
          {365,  2250  },        /* Gain= 1.425781 Exposure Index= 261 */
          {376,  2250  },        /* Gain= 1.468750 Exposure Index= 262 */
          {388,  2250  },        /* Gain= 1.515625 Exposure Index= 263 */
          {400,  2250  },        /* Gain= 1.562500 Exposure Index= 264 */
          {412,  2250  },        /* Gain= 1.609375 Exposure Index= 265 */
          {425,  2250  },        /* Gain= 1.660156 Exposure Index= 266 */
          {438,  2250  },        /* Gain= 1.710938 Exposure Index= 267 */
          {452,  2250  },        /* Gain= 1.765625 Exposure Index= 268 */
          {466,  2250  },        /* Gain= 1.820313 Exposure Index= 269 */
          {480,  2250  },        /* Gain= 1.875000 Exposure Index= 270 */
          {495,  2250  },        /* Gain= 1.933594 Exposure Index= 271 */
          {510,  2250  },        /* Gain= 1.992188 Exposure Index= 272 */
          {526,  2250  },        /* Gain= 2.054688 Exposure Index= 273 */
          {542,  2250  },        /* Gain= 2.117188 Exposure Index= 274 */
          {559,  2250  },        /* Gain= 2.183594 Exposure Index= 275 */
          {576,  2250  },        /* Gain= 2.250000 Exposure Index= 276 */
          {594,  2250  },        /* Gain= 2.320313 Exposure Index= 277 */
          {612,  2250  },        /* Gain= 2.390625 Exposure Index= 278 */
          {631,  2250  },        /* Gain= 2.464844 Exposure Index= 279 */
          {650,  2250  },        /* Gain= 2.539063 Exposure Index= 280 */
          {670,  2250  },        /* Gain= 2.617188 Exposure Index= 281 */
          {691,  2250  },        /* Gain= 2.699219 Exposure Index= 282 */
          {712,  2250  },        /* Gain= 2.781250 Exposure Index= 283 */
          {734,  2250  },        /* Gain= 2.867188 Exposure Index= 284 */
          {757,  2250  },        /* Gain= 2.957031 Exposure Index= 285 */
          {780,  2250  },        /* Gain= 3.046875 Exposure Index= 286 */
          {804,  2250  },        /* Gain= 3.140625 Exposure Index= 287 */
          {829,  2250  },        /* Gain= 3.238281 Exposure Index= 288 */
          {854,  2250  },        /* Gain= 3.335938 Exposure Index= 289 */
          {880,  2250  },        /* Gain= 3.437500 Exposure Index= 290 */
          {907,  2250  },        /* Gain= 3.542969 Exposure Index= 291 */
          {935,  2250  },        /* Gain= 3.652344 Exposure Index= 292 */
          {964,  2250  },        /* Gain= 3.765625 Exposure Index= 293 */
          {993,  2250  },        /* Gain= 3.878906 Exposure Index= 294 */
          {1023,  2250  },        /* Gain= 3.996094 Exposure Index= 295 */
          {1054,  2250  },        /* Gain= 4.117188 Exposure Index= 296 */
          {1086,  2250  },        /* Gain= 4.242188 Exposure Index= 297 */
          {1119,  2250  },        /* Gain= 4.371094 Exposure Index= 298 */
          {1153,  2250  },        /* Gain= 4.503906 Exposure Index= 299 */
          {1188,  2250  },        /* Gain= 4.640625 Exposure Index= 300 */
          {1224,  2250  },        /* Gain= 4.781250 Exposure Index= 301 */
          {1261,  2250  },        /* Gain= 4.925781 Exposure Index= 302 */
          {1299,  2250  },        /* Gain= 5.074219 Exposure Index= 303 */
          {1338,  2250  },        /* Gain= 5.226563 Exposure Index= 304 */
          {1379,  2250  },        /* Gain= 5.386719 Exposure Index= 305 */
          {1421,  2250  },        /* Gain= 5.550781 Exposure Index= 306 */
          {1464,  2250  },        /* Gain= 5.718750 Exposure Index= 307 */
          {1508,  2250  },        /* Gain= 5.890625 Exposure Index= 308 */
          {1554,  2250  },        /* Gain= 6.070313 Exposure Index= 309 */
          {1601,  2250  },        /* Gain= 6.253906 Exposure Index= 310 */
          {1650,  2250  },        /* Gain= 6.445313 Exposure Index= 311 */
          {1700,  2250  },        /* Gain= 6.640625 Exposure Index= 312 */
          {1751,  2250  },        /* Gain= 6.839844 Exposure Index= 313 */
          {1804,  2250  },        /* Gain= 7.046875 Exposure Index= 314 */
          {1859,  2250  },        /* Gain= 7.261719 Exposure Index= 315 */
          {1915,  2250  },        /* Gain= 7.480469 Exposure Index= 316 */
          {1973,  2250  },        /* Gain= 7.707031 Exposure Index= 317 */
          {2033,  2250  },        /* Gain= 7.941406 Exposure Index= 318 */
          {2094,  2250  },        /* Gain= 8.179688 Exposure Index= 319 */
          {2157,  2250  },        /* Gain= 8.425781 Exposure Index= 320 */
          {2222,  2250  },        /* Gain= 8.679688 Exposure Index= 321 */
          {2289,  2250  },        /* Gain= 8.941406 Exposure Index= 322 */
          {2358,  2250  },        /* Gain= 9.210938 Exposure Index= 323 */
          {2429,  2250  },        /* Gain= 9.488281 Exposure Index= 324 */
          {2502,  2250  },        /* Gain= 9.773438 Exposure Index= 325 */
          {2578,  2250  },        /* Gain= 10.070313 Exposure Index= 326 */
          {2656,  2250  },        /* Gain= 10.375000 Exposure Index= 327 */
          {2736,  2250  },        /* Gain= 10.687500 Exposure Index= 328 */
          {2819,  2250  },        /* Gain= 11.011719 Exposure Index= 329 */
          {2904,  2250  },        /* Gain= 11.343750 Exposure Index= 330 */
          {2992,  2250  },        /* Gain= 11.687500 Exposure Index= 331 */
          {3082,  2250  },        /* Gain= 12.039063 Exposure Index= 332 */
          {3175,  2250  },        /* Gain= 12.402344 Exposure Index= 333 */
          {3271,  2250  },        /* Gain= 12.777344 Exposure Index= 334 */
          {3370,  2250  },        /* Gain= 13.164063 Exposure Index= 335 */
          {3472,  2250  },        /* Gain= 13.562500 Exposure Index= 336 */
          {3577,  2250  },        /* Gain= 13.972656 Exposure Index= 337 */
          {3685,  2250  },        /* Gain= 14.394531 Exposure Index= 338 */
          {3796,  2250  },        /* Gain= 14.828125 Exposure Index= 339 */
          {3910,  2250  },        /* Gain= 15.273438 Exposure Index= 340 */
          {4028,  2250  },        /* Gain= 15.734375 Exposure Index= 341 */
          {4149,  2250  },        /* Gain= 16.207031 Exposure Index= 342 */
          {4274,  2250  },        /* Gain= 16.695313 Exposure Index= 343 */
          {4403,  2250  },        /* Gain= 17.199219 Exposure Index= 344 */
          {4536,  2250  },        /* Gain= 17.718750 Exposure Index= 345 */
          {4673,  2250  },        /* Gain= 18.253906 Exposure Index= 346 */
          {4814,  2250  },        /* Gain= 18.804688 Exposure Index= 347 */
          {4959,  2250  },        /* Gain= 19.371094 Exposure Index= 348 */
          {5108,  2250  },        /* Gain= 19.953125 Exposure Index= 349 */
          {5262,  2250  },        /* Gain= 20.554688 Exposure Index= 350 */
          {5420,  2250  },        /* Gain= 21.171875 Exposure Index= 351 */
          {5583,  2250  },        /* Gain= 21.808594 Exposure Index= 352 */
          {5751,  2250  },        /* Gain= 22.464844 Exposure Index= 353 */
          {5924,  2250  },        /* Gain= 23.140625 Exposure Index= 354 */
          {6102,  2250  },        /* Gain= 23.835938 Exposure Index= 355 */
          {6286,  2250  },        /* Gain= 24.554688 Exposure Index= 356 */
          {6475,  2250  },        /* Gain= 25.292969 Exposure Index= 357 */
          {6670,  2250  },        /* Gain= 26.054688 Exposure Index= 358 */
          {6871,  2250  },        /* Gain= 26.839844 Exposure Index= 359 */
          {7078,  2250  },        /* Gain= 27.648438 Exposure Index= 360 */
          {7291,  2250  },        /* Gain= 28.480469 Exposure Index= 361 */
          {7510,  2250  },        /* Gain= 29.335938 Exposure Index= 362 */
          {7736,  2250  },        /* Gain= 30.218750 Exposure Index= 363 */
          {7969,  2250  },        /* Gain= 31.128906 Exposure Index= 364 */
          {8209,  2250  },        /* Gain= 32.066406 Exposure Index= 365 */
          {8456,  2250  },        /* Gain= 33.031250 Exposure Index= 366 */
          {8710,  2250  },        /* Gain= 34.023438 Exposure Index= 367 */
          {8972,  2250  },        /* Gain= 35.046875 Exposure Index= 368 */
          {9242,  2250  },        /* Gain= 36.101563 Exposure Index= 369 */
          {9520,  2250  },        /* Gain= 37.187500 Exposure Index= 370 */
          {9806,  2250  },        /* Gain= 38.304688 Exposure Index= 371 */
          {10101,  2250  },        /* Gain= 39.457031 Exposure Index= 372 */
          {10405,  2250  },        /* Gain= 40.644531 Exposure Index= 373 */
          {10718,  2250  },        /* Gain= 41.867188 Exposure Index= 374 */
          {11040,  2250  },        /* Gain= 43.125000 Exposure Index= 375 */
          {11372,  2250  },        /* Gain= 44.421875 Exposure Index= 376 */
          {11714,  2250  },        /* Gain= 45.757813 Exposure Index= 377 */
          {12066,  2250  },        /* Gain= 47.132813 Exposure Index= 378 */
          {12428,  2250  },        /* Gain= 48.546875 Exposure Index= 379 */
          {12801,  2250  },        /* Gain= 50.003906 Exposure Index= 380 */
          {13186,  2250  },        /* Gain= 51.507813 Exposure Index= 381 */
          {13582,  2250  },        /* Gain= 53.054688 Exposure Index= 382 */
          {13990,  2250  },        /* Gain= 54.648438 Exposure Index= 383 */
          {14410,  2250  },        /* Gain= 56.289063 Exposure Index= 384 */
          {14843,  2250  },        /* Gain= 57.980469 Exposure Index= 385 */
          {15289,  2250  },        /* Gain= 59.722656 Exposure Index= 386 */
          {15748,  2250  },        /* Gain= 61.515625 Exposure Index= 387 */
          {16221,  2250  },        /* Gain= 63.363281 Exposure Index= 388 */
          {16708,  2250  },        /* Gain= 65.265625 Exposure Index= 389 */
          {17210,  2250  },        /* Gain= 67.226563 Exposure Index= 390 */
          {17727,  2250  },        /* Gain= 69.246094 Exposure Index= 391 */
          {18259,  2250  },        /* Gain= 71.324219 Exposure Index= 392 */
          {18807,  2250  },        /* Gain= 73.464844 Exposure Index= 393 */
          {19372,  2250  },        /* Gain= 75.671875 Exposure Index= 394 */
          {19954,  2250  },        /* Gain= 77.945313 Exposure Index= 395 */
          {20553,  2250  },        /* Gain= 80.285156 Exposure Index= 396 */
          {21170,  2250  },        /* Gain= 82.695313 Exposure Index= 397 */
          {21806,  2250  },        /* Gain= 85.179688 Exposure Index= 398 */
          {22461,  2250  },        /* Gain= 87.738281 Exposure Index= 399 */
          {23135,  2250  },        /* Gain= 90.371094 Exposure Index= 400 */
          {23830,  2250  },        /* Gain= 93.085938 Exposure Index= 401 */
          {24545,  2250  },        /* Gain= 95.878906 Exposure Index= 402 */
          {25282,  2250  },        /* Gain= 98.757813 Exposure Index= 403 */
          {26041,  2250  },        /* Gain= 101.722656 Exposure Index= 404 */
          {26823,  2250  },        /* Gain= 104.777344 Exposure Index= 405 */
          {27628,  2250  },        /* Gain= 107.921875 Exposure Index= 406 */
          {28457,  2250  },        /* Gain= 111.160156 Exposure Index= 407 */
          {29311,  2250  },        /* Gain= 114.496094 Exposure Index= 408 */
          {30191,  2250  },        /* Gain= 117.933594 Exposure Index= 409 */
          {31097,  2250  },        /* Gain= 121.472656 Exposure Index= 410 */
          {32030,  2250  },        /* Gain= 125.117188 Exposure Index= 411 */
        },
    },	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            50,  /* outdoor_luma_target_compensated */
            38,  /* default_luma_target_compensated */
            12,/* low_light.luma_target */
            170,  /* outdoor_index */
            220,  /* indoor_index */
            340,/* low_light.start_idx */
            410,/* low_light.end_idx */
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
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
              1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,
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
        /* sensor hdr tuning para */
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
			 245,
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
                         120,
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
                           4,  /* low th */
                           8,  /* high th*/
                           50,/* skip frame num */
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
            0,//bright_dark_en
            4,//bright_dark_count
            0,//bright_en
            0,//dark_en
			 1,//inter_enable
            /* bright_dark_pra [MIDDLE_TRIGGER_COUNT] */
            {
                /* para 1 */
                {
                    0.000000,//lux_index
                    20.000000,//dark_th_low
                    40.000000,//dark_th_high
                    230.000000,//bright_th_low
                    240.000000,//bright_th_high
                    4.000000,//dark_th_low_w
                    2.000000,//dark_th_high_w
                    0.750000,//bright_th_low_w
                    0.500000,//bright_th_high_w
                },
                /* para 2 */
                {
                    180.000000,//lux_index
                    15.000000,//dark_th_low
                    30.000000,//dark_th_high
                    230.000000,//bright_th_low
                    240.000000,//bright_th_high
                    5.000000,//dark_th_low_w
                    3.000000,//dark_th_high_w
                    0.700000,//bright_th_low_w
                    0.400000,//bright_th_high_w
                },
                /* para 3 */
                {
                    280.000000,//lux_index
                    15.000000,//dark_th_low
                    30.000000,//dark_th_high
                    230.000000,//bright_th_low
                    240.000000,//bright_th_high
                    4.000000,//dark_th_low_w
                    2.000000,//dark_th_high_w
                    1.000000,//bright_th_low_w
                    0.500000,//bright_th_high_w
                },
                /* para 4 */
                {
                    400.000000,//lux_index
                    15.000000,//dark_th_low
                    30.000000,//dark_th_high
                    230.000000,//bright_th_low
                    240.000000,//bright_th_high
                    1.000000,//dark_th_low_w
                    1.000000,//dark_th_high_w
                    1.000000,//bright_th_low_w
                    1.000000,//bright_th_high_w
                },
            },
	    },
        1,//aec algo type,0:fast smooth  1:fast plus
        /* aec fast plus param */
        {
            2,//luma tolerance
            1,//frame skip
            2,//ddr frame skip offset
            {5,10,15},//interval threshold
            {0.900000,0.700000,0.600000},//speed ratio
            0.500000,//speed ratio others
        },
        0,//aec hdr algo type,0:org  1:fast
	},
},
/*awb_tuning_t awb_tuning*/
{
    /* awb version */
    0x00000001,
    /* enable */
    1,
    /* interpolation enable */
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
            511,
        },
        {
            0,
            511,
        },
        {
            0,
            511,
        },
	},
    /* awb_point */
    {
        { 0.4534, 0.6215 },    /* d75 */
        { 0.4917, 0.5597 },    /* d65 */
        { 0.5642, 0.4915 },    /* d50 */
        { 0.5642, 0.4915 },    /* noon */
        { 0.5512, 0.3499 },    /* cw */
        { 0.6529, 0.3635 },    /* tl84 */
        { 0.8316, 0.3014 },    /* a */
        { 0.9838, 0.2659 },    /* h */
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
    	 { 1.00, 0.90 },   /* h */
    	 { 1.00, 1.00 },   /* custom_daylight */
         { 1.00, 1.00 },   /* custom_a */
    },
      /* awb cct */
    {
        7442,  /* d75 */
        6575,  /* d65 */
        5045,  /* d50 */
        5100,  /* noon */
        4250,  /* cw */
        4000,  /* tl84 */
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
        /* awb_light_weight_table 1 */
        {
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        },
        /* awb_light_weight_table 2 */
        {
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        },
        /* awb_light_weight_table 3 */
        {
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        },
        /* awb_light_weight_table 4 */
        {
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        },
    },
    /* awb_light_weight_table2 */
    {   /* Exp Index:0,Outdoor_index,Inoutdoor_midpoint,Indoor_index */
        { 1, 2, 2, 1 },   /*   d75    */
        { 2, 8, 2, 1 },   /*   d65    */
        { 5,10,10, 8 },   /*   d50    */
        { 5,10,10, 8 },   /*   noon   */
        { 1, 0, 1, 1 },   /*   cw     */
        { 2, 0, 2, 2 },   /*   tl84   */
        { 1, 0, 0, 0 },   /*   a      */
        { 0, 0, 0, 0 },   /*   h      */
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
        100,      /* dominant_cluster_threshold */
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
        0.008, /* compact_to_grey_dis */
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
           0x00000100, /* Gray_m1 */
           0x00010100, /* Gray_m2 */
           0x00000100, /* Gray_m3 */
           0x00010100, /* Gray_m4 */
           0x00000258, /* Gray_c1 */
           0x000102a4, /* Gray_c2 */
           0x00010258, /* Gray_c3 */
           0x00000404, /* Gray_c4 */
           0x000000a6, /* Green_BGmax */
           0x00000019, /* Green_BGmin */
           0x00000080, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x000001c2, /* Green_Rmul */
           0x000000f5, /* Green_Bmul */
           0x00001680, /* ExtremeB_BG_TH */
           0x00001480, /* ExtremeB_RG_TH */
           0x000012f0, /* ExtremeR_RG_TH */
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
