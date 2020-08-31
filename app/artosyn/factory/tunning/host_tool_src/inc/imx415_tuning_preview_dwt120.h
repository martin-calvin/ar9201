
/*---------------header of imx415 tuning-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x20200106,
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
                        {0,0,0},
                        //g channel
                        {0,0,0},
                        //b channel
                        {0,0,0},
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
                        {35,105,98},
                        //g channel
                        {35,105,98},
                        //b channel
                        {35,105,98},
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
                        {53,159,151},
                        //g channel
                        {53,159,151},
                        //b channel
                        {53,159,151},
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
                        {35,105,70},
                        //g channel
                        {35,105,70},
                        //b channel
                        {35,105,70},
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
                        {90,270,258},
                        //g channel
                        {90,270,258},
                        //b channel
                        {90,270,258},
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
                        {58,174,118},
                        //g channel
                        {58,174,118},
                        //b channel
                        {58,174,118},
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
                        {144,432,414},
                        //g channel
                        {144,432,414},
                        //b channel
                        {144,432,414},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {118,354,242},
                        //g channel
                        {118,354,242},
                        //b channel
                        {118,354,242},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {84,252,172},
                        //g channel
                        {84,252,172},
                        //b channel
                        {84,252,172},
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
                        {230,690,664},
                        //g channel
                        {230,690,664},
                        //b channel
                        {230,690,664},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {202,606,416},
                        //g channel
                        {202,606,416},
                        //b channel
                        {202,606,416},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {202,606,416},
                        //g channel
                        {202,606,416},
                        //b channel
                        {202,606,416},
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
                        {452,1356,1308},
                        //g channel
                        {452,1356,1308},
                        //b channel
                        {452,1356,1308},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {452,1356,934},
                        //g channel
                        {452,1356,934},
                        //b channel
                        {452,1356,934},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {438,1314,905},
                        //g channel
                        {438,1314,905},
                        //b channel
                        {438,1314,905},
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
                        {615,1845,1780},
                        //g channel
                        {615,1845,1780},
                        //b channel
                        {615,1845,1780},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {601,1803,1243},
                        //g channel
                        {601,1803,1243},
                        //b channel
                        {601,1803,1243},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {629,1887,1301},
                        //g channel
                        {629,1887,1301},
                        //b channel
                        {629,1887,1301},
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
               	0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  2.6274, 1.8315, 1.4688, 1.2529, 1.2495, 1.2070, 1.3008, 1.4561, 1.9165, 2.7012,
                  2.3774, 1.6509, 1.3320, 1.2119, 1.1226, 1.1338, 1.2222, 1.3506, 1.7021, 2.4321,
                  2.1543, 1.5537, 1.2842, 1.1328, 1.0859, 1.0757, 1.1694, 1.2876, 1.6040, 2.1953,
                  2.0776, 1.4639, 1.2305, 1.0811, 1.0127, 1.0200, 1.1030, 1.2515, 1.4980, 2.1504,
                  2.0103, 1.4526, 1.2124, 1.0698, 1.0049, 0.9971, 1.0776, 1.2168, 1.4575, 2.0112,
                  2.0200, 1.4565, 1.2075, 1.0703, 0.9971, 0.9883, 1.0903, 1.2271, 1.4688, 2.0645,
                  2.0645, 1.4751, 1.2539, 1.0918, 1.0293, 1.0166, 1.1118, 1.2510, 1.4917, 2.1201,
                  2.1855, 1.5776, 1.2769, 1.1616, 1.0879, 1.0898, 1.1484, 1.2930, 1.5947, 2.1953,
                  2.3643, 1.6782, 1.3618, 1.2266, 1.1328, 1.1475, 1.1992, 1.3701, 1.7417, 2.4458,
                  2.7178, 1.8584, 1.4863, 1.2866, 1.2373, 1.2407, 1.2476, 1.4800, 1.8975, 2.6904,
                  2.5786, 1.7783, 1.4355, 1.2148, 1.2393, 1.1797, 1.2529, 1.4209, 1.8057, 2.6416,
                  2.2837, 1.6362, 1.3071, 1.2031, 1.1079, 1.1333, 1.1992, 1.3120, 1.6567, 2.3311,
                  2.1387, 1.4980, 1.2720, 1.1118, 1.0767, 1.0557, 1.1421, 1.2397, 1.5273, 2.1543,
                  2.0200, 1.4541, 1.2158, 1.0884, 1.0151, 1.0254, 1.0908, 1.2344, 1.4360, 2.0518,
                  1.9302, 1.4365, 1.1943, 1.0659, 0.9961, 0.9868, 1.0791, 1.1846, 1.4106, 2.0137,
                  1.9810, 1.4375, 1.2002, 1.0713, 1.0020, 0.9897, 1.0718, 1.1953, 1.4116, 1.9653,
                  2.0151, 1.4644, 1.2388, 1.0928, 1.0249, 1.0229, 1.1021, 1.2290, 1.4321, 2.0718,
                  2.0991, 1.5508, 1.2490, 1.1519, 1.0815, 1.0840, 1.1230, 1.2593, 1.5449, 2.1191,
                  2.3389, 1.6621, 1.3369, 1.2163, 1.1353, 1.1401, 1.1846, 1.3286, 1.6802, 2.3589,
                  2.6680, 1.8164, 1.4741, 1.2739, 1.2119, 1.2456, 1.1943, 1.4751, 1.8091, 2.6597,
                  2.2944, 1.6938, 1.4131, 1.1978, 1.2397, 1.1655, 1.2300, 1.3945, 1.7246, 2.5396,
                  2.2100, 1.5732, 1.3101, 1.2046, 1.1084, 1.1304, 1.1904, 1.2651, 1.6138, 2.1392,
                  2.0146, 1.4434, 1.2539, 1.1152, 1.0786, 1.0674, 1.1401, 1.2368, 1.4854, 2.0889,
                  1.8994, 1.4282, 1.2207, 1.0933, 1.0254, 1.0200, 1.0864, 1.2124, 1.3931, 1.9561,
                  1.9194, 1.3599, 1.2163, 1.0625, 0.9897, 0.9878, 1.0713, 1.1724, 1.3711, 1.8872,
                  1.8428, 1.4282, 1.1743, 1.0679, 1.0063, 0.9849, 1.0786, 1.1963, 1.3696, 1.9165,
                  1.9746, 1.3862, 1.2505, 1.0889, 1.0317, 1.0166, 1.1006, 1.2075, 1.3818, 1.9268,
                  1.9458, 1.5049, 1.2109, 1.1538, 1.0771, 1.0864, 1.0996, 1.2520, 1.4492, 2.0483,
                  2.1929, 1.5796, 1.3208, 1.1973, 1.1353, 1.1250, 1.1821, 1.2764, 1.6274, 2.1694,
                  2.4272, 1.7432, 1.3765, 1.3008, 1.1973, 1.2056, 1.1743, 1.4175, 1.6797, 2.5132,
                },
     		},
     		/* para 2 */
     		{
               	0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  2.5132, 1.7998, 1.4150, 1.2388, 1.2144, 1.2021, 1.2593, 1.4526, 1.8164, 2.5796,
                  2.3140, 1.6191, 1.3296, 1.2002, 1.1123, 1.1323, 1.2031, 1.3057, 1.6631, 2.2686,
                  2.0728, 1.5444, 1.2500, 1.1362, 1.0747, 1.0645, 1.1445, 1.2744, 1.5264, 2.1450,
                  2.0166, 1.4282, 1.2222, 1.0859, 1.0015, 1.0229, 1.0786, 1.2354, 1.4336, 2.0337,
                  1.9268, 1.4395, 1.1919, 1.0645, 0.9937, 0.9917, 1.0703, 1.1895, 1.4136, 1.9390,
                  1.9214, 1.4312, 1.1821, 1.0728, 0.9888, 0.9893, 1.0762, 1.1924, 1.4160, 1.9385,
                  2.0098, 1.4521, 1.2524, 1.0874, 1.0200, 1.0112, 1.0908, 1.2227, 1.4390, 2.0122,
                  2.0747, 1.5273, 1.2402, 1.1416, 1.0684, 1.0659, 1.1382, 1.2544, 1.5107, 2.1362,
                  2.2817, 1.6309, 1.3496, 1.2080, 1.1235, 1.1377, 1.1670, 1.3359, 1.6729, 2.2739,
                  2.5718, 1.7720, 1.4668, 1.2515, 1.2188, 1.2046, 1.2344, 1.4399, 1.7578, 2.6328,
                  2.5596, 1.7959, 1.4434, 1.2300, 1.2227, 1.1860, 1.2705, 1.3945, 1.8247, 2.5645,
                  2.2729, 1.6367, 1.3110, 1.2002, 1.1226, 1.1221, 1.1895, 1.2822, 1.6260, 2.2759,
                  2.1147, 1.5225, 1.2627, 1.1265, 1.0747, 1.0615, 1.1460, 1.2314, 1.5215, 2.0571,
                  2.0273, 1.4404, 1.2300, 1.0884, 1.0176, 1.0278, 1.0923, 1.2173, 1.4185, 2.0264,
                  1.9717, 1.4360, 1.2051, 1.0747, 1.0098, 0.9849, 1.0752, 1.1699, 1.3926, 1.9160,
                  1.9600, 1.4326, 1.2065, 1.0742, 0.9961, 0.9922, 1.0767, 1.1714, 1.4043, 1.9346,
                  2.0020, 1.4424, 1.2300, 1.0923, 1.0273, 1.0181, 1.0903, 1.2183, 1.3999, 2.0000,
                  2.0879, 1.5635, 1.2549, 1.1543, 1.0874, 1.0820, 1.1255, 1.2310, 1.5205, 2.0796,
                  2.3184, 1.6270, 1.3311, 1.2104, 1.1128, 1.1387, 1.1587, 1.3218, 1.6362, 2.2876,
                  2.5430, 1.8589, 1.4375, 1.2827, 1.2227, 1.2124, 1.2026, 1.3896, 1.8071, 2.5161,
                  2.4541, 1.7212, 1.4082, 1.1948, 1.2080, 1.2012, 1.2085, 1.3916, 1.7739, 2.3501,
                  2.2666, 1.6099, 1.3369, 1.2012, 1.1367, 1.1396, 1.2124, 1.2739, 1.6021, 2.2197,
                  2.0244, 1.4873, 1.2368, 1.1411, 1.0781, 1.0894, 1.1372, 1.2378, 1.4712, 2.0020,
                  1.9644, 1.4214, 1.2524, 1.0898, 1.0347, 1.0405, 1.1089, 1.1982, 1.4146, 1.9316,
                  1.8979, 1.4287, 1.2021, 1.1025, 1.0156, 1.0044, 1.0859, 1.1763, 1.3496, 1.8442,
                  1.8525, 1.4067, 1.1831, 1.0659, 0.9956, 0.9873, 1.0879, 1.1812, 1.3672, 1.8677,
                  1.9756, 1.4194, 1.2544, 1.0986, 1.0454, 1.0322, 1.1025, 1.1865, 1.3750, 1.8813,
                  1.9395, 1.5068, 1.2070, 1.1548, 1.0698, 1.0898, 1.1274, 1.2271, 1.4746, 1.9839,
                  2.2871, 1.5674, 1.3325, 1.1992, 1.1260, 1.1294, 1.1543, 1.2563, 1.5825, 2.1318,
                  2.2842, 1.7847, 1.3574, 1.2715, 1.2095, 1.2178, 1.2134, 1.3853, 1.7397, 2.4131,
                },
     		},
     		/* para 3 */
     		{
               	0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  2.6045, 1.8311, 1.4771, 1.2681, 1.2500, 1.2124, 1.2954, 1.4395, 1.8525, 2.5874,
                  2.3667, 1.6729, 1.3506, 1.2178, 1.1270, 1.1299, 1.2183, 1.3115, 1.6890, 2.3208,
                  2.1660, 1.5615, 1.2925, 1.1494, 1.0879, 1.0811, 1.1660, 1.2754, 1.5659, 2.1396,
                  2.0684, 1.4736, 1.2456, 1.0991, 1.0146, 1.0337, 1.0957, 1.2305, 1.4736, 2.0137,
                  2.0381, 1.4722, 1.2231, 1.0850, 1.0132, 0.9951, 1.0869, 1.1997, 1.4341, 1.9795,
                  2.0161, 1.4575, 1.2227, 1.0757, 1.0034, 0.9966, 1.0713, 1.2104, 1.4390, 1.9570,
                  2.0620, 1.4814, 1.2559, 1.0957, 1.0337, 1.0195, 1.1069, 1.2363, 1.4600, 2.0190,
                  2.1445, 1.5708, 1.2769, 1.1606, 1.0767, 1.0820, 1.1406, 1.2622, 1.5566, 2.1157,
                  2.3394, 1.6592, 1.3633, 1.2100, 1.1479, 1.1445, 1.1909, 1.3350, 1.7012, 2.3301,
                  2.7002, 1.8428, 1.4849, 1.2813, 1.2124, 1.2173, 1.2520, 1.4414, 1.8467, 2.5845,
                  2.5537, 1.8232, 1.4277, 1.2529, 1.2192, 1.1836, 1.2549, 1.4028, 1.7842, 2.5654,
                  2.3013, 1.6606, 1.3164, 1.2056, 1.1196, 1.1240, 1.1982, 1.2827, 1.6353, 2.2671,
                  2.1558, 1.5259, 1.2739, 1.1401, 1.0732, 1.0698, 1.1377, 1.2432, 1.4995, 2.1035,
                  2.0332, 1.4722, 1.2305, 1.1040, 1.0186, 1.0288, 1.0938, 1.2134, 1.4277, 1.9946,
                  1.9922, 1.4517, 1.2061, 1.0791, 1.0029, 0.9927, 1.0732, 1.1768, 1.3872, 1.9448,
                  1.9849, 1.4448, 1.2134, 1.0767, 1.0083, 0.9917, 1.0669, 1.1934, 1.3843, 1.9341,
                  2.0239, 1.4702, 1.2324, 1.0991, 1.0225, 1.0186, 1.0908, 1.2139, 1.4023, 1.9858,
                  2.1187, 1.5522, 1.2559, 1.1528, 1.0801, 1.0762, 1.1187, 1.2256, 1.5054, 2.0723,
                  2.3042, 1.6504, 1.3315, 1.2061, 1.1304, 1.1328, 1.1763, 1.3066, 1.6440, 2.2686,
                  2.6284, 1.8267, 1.4473, 1.2681, 1.2158, 1.2007, 1.2061, 1.3872, 1.7910, 2.5200,
                  2.3896, 1.8164, 1.3945, 1.2500, 1.2251, 1.1738, 1.2485, 1.3892, 1.7588, 2.4346,
                  2.2686, 1.6108, 1.3262, 1.1948, 1.1187, 1.1152, 1.1919, 1.2476, 1.5952, 2.1606,
                  2.0972, 1.5010, 1.2656, 1.1470, 1.0825, 1.0718, 1.1523, 1.2310, 1.4692, 2.0347,
                  1.9873, 1.4331, 1.2354, 1.0830, 1.0171, 1.0259, 1.0874, 1.2036, 1.3926, 1.9082,
                  1.9385, 1.4272, 1.2173, 1.0859, 1.0093, 0.9883, 1.0859, 1.1646, 1.3569, 1.8696,
                  1.9727, 1.4185, 1.2051, 1.0767, 1.0010, 0.9941, 1.0703, 1.1802, 1.3604, 1.8569,
                  1.9663, 1.4253, 1.2368, 1.0898, 1.0244, 1.0205, 1.0923, 1.1958, 1.3667, 1.9155,
                  2.0049, 1.5200, 1.2275, 1.1523, 1.0732, 1.0835, 1.1138, 1.2168, 1.4639, 2.0044,
                  2.2476, 1.5898, 1.3223, 1.1963, 1.1270, 1.1309, 1.1743, 1.2637, 1.6108, 2.1431,
                  2.4253, 1.7700, 1.3940, 1.2515, 1.2012, 1.1846, 1.1982, 1.3359, 1.7417, 2.4448,
                },
     		},
     		/* para 4 */
     		{
               	0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
               	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                {
                  2.6367, 1.8843, 1.4780, 1.3032, 1.2744, 1.2607, 1.2964, 1.5020, 1.8530, 2.6855,
                  2.3154, 1.6509, 1.3418, 1.2163, 1.1279, 1.1431, 1.2109, 1.3296, 1.6963, 2.3247,
                  2.0967, 1.5352, 1.2720, 1.1367, 1.0806, 1.0654, 1.1475, 1.2715, 1.5327, 2.1362,
                  2.0615, 1.5132, 1.2588, 1.1240, 1.0483, 1.0596, 1.1084, 1.2754, 1.4800, 2.0928,
                  1.9443, 1.4229, 1.2056, 1.0654, 0.9805, 0.9717, 1.0688, 1.1807, 1.4131, 1.9580,
                  1.9927, 1.4712, 1.2314, 1.0854, 1.0254, 0.9995, 1.0977, 1.2241, 1.4482, 2.0107,
                  2.0454, 1.4805, 1.2646, 1.1113, 1.0288, 1.0283, 1.0972, 1.2510, 1.4434, 2.0640,
                  2.0864, 1.5420, 1.2471, 1.1465, 1.0610, 1.0601, 1.1362, 1.2441, 1.5220, 2.1255,
                  2.3784, 1.6636, 1.3857, 1.2373, 1.1572, 1.1606, 1.2046, 1.3809, 1.7192, 2.3823,
                  2.5591, 1.8179, 1.4434, 1.2373, 1.2090, 1.1904, 1.1816, 1.4541, 1.7427, 2.5889,
                  2.6538, 1.8540, 1.4697, 1.2910, 1.2510, 1.2319, 1.2720, 1.4536, 1.8472, 2.6177,
                  2.3184, 1.6797, 1.3203, 1.2158, 1.1260, 1.1333, 1.2017, 1.2930, 1.6353, 2.2681,
                  2.1201, 1.5088, 1.2627, 1.1294, 1.0669, 1.0605, 1.1328, 1.2344, 1.5005, 2.1128,
                  2.1074, 1.5122, 1.2637, 1.1289, 1.0479, 1.0527, 1.1094, 1.2480, 1.4580, 2.0361,
                  1.9272, 1.4355, 1.1880, 1.0620, 0.9888, 0.9736, 1.0571, 1.1655, 1.3662, 1.9380,
                  2.0430, 1.4653, 1.2363, 1.0986, 1.0220, 1.0054, 1.0894, 1.2056, 1.4058, 1.9780,
                  2.0005, 1.4795, 1.2314, 1.1040, 1.0322, 1.0215, 1.0996, 1.2207, 1.4199, 2.0156,
                  2.1299, 1.5308, 1.2539, 1.1367, 1.0737, 1.0713, 1.1069, 1.2231, 1.4937, 2.0728,
                  2.3120, 1.7007, 1.3486, 1.2319, 1.1523, 1.1528, 1.1968, 1.3359, 1.6904, 2.3208,
                  2.6528, 1.7695, 1.4619, 1.2271, 1.1943, 1.2007, 1.1621, 1.3950, 1.7432, 2.5308,
                  2.5991, 1.8359, 1.4609, 1.2803, 1.2285, 1.2593, 1.2642, 1.4790, 1.7910, 2.5977,
                  2.2290, 1.6455, 1.3071, 1.2036, 1.1353, 1.1157, 1.1792, 1.2744, 1.5859, 2.2114,
                  2.1064, 1.4609, 1.2729, 1.1313, 1.0615, 1.0835, 1.1357, 1.2236, 1.4590, 2.0254,
                  2.0620, 1.4858, 1.2676, 1.1167, 1.0513, 1.0483, 1.1099, 1.2549, 1.4297, 2.0015,
                  1.8989, 1.4097, 1.1914, 1.0771, 0.9780, 0.9780, 1.0620, 1.1338, 1.3384, 1.8311,
                  1.9980, 1.4419, 1.2437, 1.0918, 1.0225, 1.0146, 1.0967, 1.2061, 1.3887, 1.9111,
                  1.9565, 1.4414, 1.2397, 1.1060, 1.0283, 1.0195, 1.1143, 1.1943, 1.4019, 1.9287,
                  2.0220, 1.5078, 1.2295, 1.1343, 1.0635, 1.0786, 1.0967, 1.2192, 1.4326, 1.9912,
                  2.2485, 1.6533, 1.3408, 1.2446, 1.1533, 1.1553, 1.2051, 1.3101, 1.6582, 2.2808,
                  2.4810, 1.7090, 1.4116, 1.2056, 1.1777, 1.1807, 1.1519, 1.3569, 1.6875, 2.3955,
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
               72, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               150, //k_thres
               63, //limit_base_green
               63, //limit_base_red
               2188, //limit_end_green
               2500, //limit_end_red
               256, //weight_filterG
               2048, //k_diff_base
           },
           /*parameter 2 */
           {
               1, //enable
               256, //alphfa1
               128, //alphfa_red
               112, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               180, //k_thres
               75, //limit_base_green
               75, //limit_base_red
               2625, //limit_end_green
               3000, //limit_end_red
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
               192, //k_filter_power
               9830, //b_value
               10, //ge_thres
               164, //g_slope
               60, //max_thres
               240, //k_thres
               100, //limit_base_green
               100, //limit_base_red
               3500, //limit_end_green
               4000, //limit_end_red
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
        		6200,
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
					2.0688,	-1.0480,-0.0208,
					-0.4812,1.7359,	-0.2547,
					-0.0482,-0.8789,1.9270,
                },
                /* ccm d65 matrix */
                {
					1.9637,	-0.9612,-0.0025,
					-0.3979,1.7253,	-0.3274,
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
            160.000,
          },
          /*aec trigger 2*/
          {
            170.000,
            360.000,
          },
          /*aec trigger 3*/
          {
            370.000,
            500.000,
          },
       },
       513,//gamma lut count
       /*isp_sub_module_gamma_lut_pra pra[MIN_TRIGGER_COUNT]; MIN_TRIGGER_COUNT=3*/
       {
          /* outdoor */
          {
                  0,  75, 153, 226, 291, 344, 402, 460, 516, 565, 604, 646, 688, 729, 769, 802, 838, 872, 907, 940, 970,1000,1027,1051,1079,1100,1125,
               1148,1169,1194,1214,1237,1257,1278,1295,1315,1335,1353,1373,1392,1411,1430,1448,1462,1479,1493,1509,1522,1538,1551,1566,1577,1589,1602,
               1614,1625,1639,1650,1663,1674,1686,1701,1713,1724,1735,1749,1760,1770,1782,1793,1803,1815,1825,1836,1847,1858,1869,1879,1892,1902,1913,
               1925,1935,1945,1957,1967,1977,1986,1998,2007,2016,2028,2036,2045,2053,2064,2072,2080,2089,2098,2106,2115,2123,2132,2140,2147,2153,2161,
               2168,2174,2181,2188,2193,2201,2207,2213,2222,2229,2236,2240,2247,2254,2262,2266,2275,2283,2287,2295,2299,2307,2316,2320,2328,2332,2340,
               2348,2352,2359,2363,2371,2379,2383,2391,2395,2402,2410,2414,2421,2425,2433,2440,2444,2451,2455,2463,2470,2474,2481,2485,2492,2499,2503,
               2510,2513,2520,2527,2531,2537,2544,2550,2553,2559,2564,2572,2577,2582,2589,2593,2599,2605,2610,2616,2622,2627,2632,2637,2643,2648,2654,
               2658,2663,2669,2673,2679,2683,2688,2695,2700,2706,2708,2714,2720,2726,2729,2735,2741,2744,2751,2754,2760,2766,2769,2775,2778,2784,2790,
               2793,2799,2802,2808,2814,2817,2823,2825,2831,2835,2839,2844,2848,2852,2856,2860,2863,2868,2872,2875,2881,2885,2889,2891,2896,2900,2905,
               2907,2912,2917,2920,2925,2928,2933,2938,2941,2946,2949,2954,2960,2962,2968,2971,2976,2982,2985,2991,2993,2999,3003,3007,3011,3016,3019,
               3023,3027,3030,3035,3038,3042,3047,3051,3055,3057,3061,3066,3070,3073,3077,3082,3085,3089,3092,3097,3102,3104,3109,3112,3117,3122,3125,
               3130,3132,3138,3143,3146,3151,3154,3159,3163,3167,3171,3176,3179,3183,3187,3190,3195,3198,3202,3208,3211,3215,3218,3222,3226,3231,3233,
               3238,3243,3245,3250,3253,3257,3262,3265,3269,3272,3276,3281,3283,3288,3290,3295,3300,3302,3307,3309,3314,3318,3320,3325,3327,3332,3336,
               3339,3343,3345,3350,3354,3356,3361,3363,3367,3372,3374,3378,3381,3385,3389,3391,3395,3399,3403,3405,3408,3412,3416,3420,3423,3427,3429,
               3433,3436,3439,3443,3447,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
               3528,3530,3534,3538,3542,3544,3547,3551,3556,3559,3562,3567,3569,3573,3577,3580,3583,3587,3591,3594,3598,3602,3606,3610,3613,3617,3621,
               3624,3628,3631,3635,3640,3644,3648,3650,3654,3658,3662,3665,3669,3674,3676,3681,3683,3688,3693,3696,3701,3703,3708,3713,3716,3721,3723,
               3729,3734,3736,3742,3744,3750,3755,3758,3763,3766,3772,3777,3780,3786,3789,3795,3800,3803,3809,3812,3818,3824,3827,3833,3836,3842,3848,
               3851,3857,3863,3868,3871,3876,3880,3887,3892,3896,3902,3906,3911,3916,3920,3925,3930,3935,3939,3951,3962,3977,3998,4024,4047,4071,4095,
          },
          /* indoor */
          {
                  0,  75, 153, 226, 291, 344, 402, 460, 516, 565, 604, 646, 688, 729, 769, 802, 838, 872, 907, 940, 970,1000,1027,1051,1079,1100,1125,
               1148,1169,1194,1214,1237,1257,1278,1295,1315,1335,1353,1373,1392,1411,1430,1448,1462,1479,1493,1509,1522,1538,1551,1566,1577,1589,1602,
               1614,1625,1639,1650,1663,1674,1686,1701,1713,1724,1735,1749,1760,1770,1782,1793,1803,1815,1825,1836,1847,1858,1869,1879,1892,1902,1913,
               1925,1935,1945,1957,1967,1977,1986,1998,2007,2016,2028,2036,2045,2053,2064,2072,2080,2089,2098,2106,2115,2123,2132,2140,2147,2153,2161,
               2168,2174,2181,2188,2193,2201,2207,2213,2222,2229,2236,2240,2247,2254,2262,2266,2275,2283,2287,2295,2299,2307,2316,2320,2328,2332,2340,
               2348,2352,2359,2363,2371,2379,2383,2391,2395,2402,2410,2414,2421,2425,2433,2440,2444,2451,2455,2463,2470,2474,2481,2485,2492,2499,2503,
               2510,2513,2520,2527,2531,2537,2544,2550,2553,2559,2564,2572,2577,2582,2589,2593,2599,2605,2610,2616,2622,2627,2632,2637,2643,2648,2654,
               2658,2663,2669,2673,2679,2683,2688,2695,2700,2706,2708,2714,2720,2726,2729,2735,2741,2744,2751,2754,2760,2766,2769,2775,2778,2784,2790,
               2793,2799,2802,2808,2814,2817,2823,2825,2831,2835,2839,2844,2848,2852,2856,2860,2863,2868,2872,2875,2881,2885,2889,2891,2896,2900,2905,
               2907,2912,2917,2920,2925,2928,2933,2938,2941,2946,2949,2954,2960,2962,2968,2971,2976,2982,2985,2991,2993,2999,3003,3007,3011,3016,3019,
               3023,3027,3030,3035,3038,3042,3047,3051,3055,3057,3061,3066,3070,3073,3077,3082,3085,3089,3092,3097,3102,3104,3109,3112,3117,3122,3125,
               3130,3132,3138,3143,3146,3151,3154,3159,3163,3167,3171,3176,3179,3183,3187,3190,3195,3198,3202,3208,3211,3215,3218,3222,3226,3231,3233,
               3238,3243,3245,3250,3253,3257,3262,3265,3269,3272,3276,3281,3283,3288,3290,3295,3300,3302,3307,3309,3314,3318,3320,3325,3327,3332,3336,
               3339,3343,3345,3350,3354,3356,3361,3363,3367,3372,3374,3378,3381,3385,3389,3391,3395,3399,3403,3405,3408,3412,3416,3420,3423,3427,3429,
               3433,3436,3439,3443,3447,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
               3528,3530,3534,3538,3542,3544,3547,3551,3556,3559,3562,3567,3569,3573,3577,3580,3583,3587,3591,3594,3598,3602,3606,3610,3613,3617,3621,
               3624,3628,3631,3635,3640,3644,3648,3650,3654,3658,3662,3665,3669,3674,3676,3681,3683,3688,3693,3696,3701,3703,3708,3713,3716,3721,3723,
               3729,3734,3736,3742,3744,3750,3755,3758,3763,3766,3772,3777,3780,3786,3789,3795,3800,3803,3809,3812,3818,3824,3827,3833,3836,3842,3848,
               3851,3857,3863,3868,3871,3876,3880,3887,3892,3896,3902,3906,3911,3916,3920,3925,3930,3935,3939,3951,3962,3977,3998,4024,4047,4071,4095,
          },
          /* lowlight */
          {
                  0,  75, 153, 226, 291, 344, 402, 460, 516, 565, 604, 646, 688, 729, 769, 802, 838, 872, 907, 940, 970,1000,1027,1051,1079,1100,1125,
               1148,1169,1194,1214,1237,1257,1278,1295,1315,1335,1353,1373,1392,1411,1430,1448,1462,1479,1493,1509,1522,1538,1551,1566,1577,1589,1602,
               1614,1625,1639,1650,1663,1674,1686,1701,1713,1724,1735,1749,1760,1770,1782,1793,1803,1815,1825,1836,1847,1858,1869,1879,1892,1902,1913,
               1925,1935,1945,1957,1967,1977,1986,1998,2007,2016,2028,2036,2045,2053,2064,2072,2080,2089,2098,2106,2115,2123,2132,2140,2147,2153,2161,
               2168,2174,2181,2188,2193,2201,2207,2213,2222,2229,2236,2240,2247,2254,2262,2266,2275,2283,2287,2295,2299,2307,2316,2320,2328,2332,2340,
               2348,2352,2359,2363,2371,2379,2383,2391,2395,2402,2410,2414,2421,2425,2433,2440,2444,2451,2455,2463,2470,2474,2481,2485,2492,2499,2503,
               2510,2513,2520,2527,2531,2537,2544,2550,2553,2559,2564,2572,2577,2582,2589,2593,2599,2605,2610,2616,2622,2627,2632,2637,2643,2648,2654,
               2658,2663,2669,2673,2679,2683,2688,2695,2700,2706,2708,2714,2720,2726,2729,2735,2741,2744,2751,2754,2760,2766,2769,2775,2778,2784,2790,
               2793,2799,2802,2808,2814,2817,2823,2825,2831,2835,2839,2844,2848,2852,2856,2860,2863,2868,2872,2875,2881,2885,2889,2891,2896,2900,2905,
               2907,2912,2917,2920,2925,2928,2933,2938,2941,2946,2949,2954,2960,2962,2968,2971,2976,2982,2985,2991,2993,2999,3003,3007,3011,3016,3019,
               3023,3027,3030,3035,3038,3042,3047,3051,3055,3057,3061,3066,3070,3073,3077,3082,3085,3089,3092,3097,3102,3104,3109,3112,3117,3122,3125,
               3130,3132,3138,3143,3146,3151,3154,3159,3163,3167,3171,3176,3179,3183,3187,3190,3195,3198,3202,3208,3211,3215,3218,3222,3226,3231,3233,
               3238,3243,3245,3250,3253,3257,3262,3265,3269,3272,3276,3281,3283,3288,3290,3295,3300,3302,3307,3309,3314,3318,3320,3325,3327,3332,3336,
               3339,3343,3345,3350,3354,3356,3361,3363,3367,3372,3374,3378,3381,3385,3389,3391,3395,3399,3403,3405,3408,3412,3416,3420,3423,3427,3429,
               3433,3436,3439,3443,3447,3450,3453,3457,3459,3464,3466,3470,3475,3477,3481,3483,3488,3492,3494,3499,3501,3505,3510,3512,3516,3519,3523,
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
                  1.200000, //saturation
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
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               70,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               65,  //sharpen_pos
               65,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               65,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               60,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               60,  //sharpen_pos
               60,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               55,  //sharpen_pos
               55,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               55,  //sharpen_pos
               55,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               5, 6, 200, 300, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 8 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               30,  //sharpen_fu
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
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               30,  //sharpen_fu
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
            8.000,
          },
          /* aec trigger 2 */
          {
            16.000,
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
        418,
        /* ev0_count */
        418,
        /* ev2_count */
        418,
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
          {260,  674  },        /* Gain= 1.015625 Exposure Index= 210 */
          {268,  674  },        /* Gain= 1.046875 Exposure Index= 211 */
          {277,  674  },        /* Gain= 1.082031 Exposure Index= 212 */
          {286,  674  },        /* Gain= 1.117188 Exposure Index= 213 */
          {295,  674  },        /* Gain= 1.152344 Exposure Index= 214 */
          {304,  674  },        /* Gain= 1.187500 Exposure Index= 215 */
          {314,  674  },        /* Gain= 1.226563 Exposure Index= 216 */
          {324,  674  },        /* Gain= 1.265625 Exposure Index= 217 */
          {334,  674  },        /* Gain= 1.304688 Exposure Index= 218 */
          {345,  674  },        /* Gain= 1.347656 Exposure Index= 219 */
          {356,  674  },        /* Gain= 1.390625 Exposure Index= 220 */
          {367,  674  },        /* Gain= 1.433594 Exposure Index= 221 */
          {379,  674  },        /* Gain= 1.480469 Exposure Index= 222 */
          {391,  674  },        /* Gain= 1.527344 Exposure Index= 223 */
          {403,  674  },        /* Gain= 1.574219 Exposure Index= 224 */
          {416,  674  },        /* Gain= 1.625000 Exposure Index= 225 */
          {429,  674  },        /* Gain= 1.675781 Exposure Index= 226 */
          {442,  674  },        /* Gain= 1.726563 Exposure Index= 227 */
          {456,  674  },        /* Gain= 1.781250 Exposure Index= 228 */
          {470,  674  },        /* Gain= 1.835938 Exposure Index= 229 */
          {485,  674  },        /* Gain= 1.894531 Exposure Index= 230 */
          {500,  674  },        /* Gain= 1.953125 Exposure Index= 231 */
          {515,  674  },        /* Gain= 2.011719 Exposure Index= 232 */
          {531,  674  },        /* Gain= 2.074219 Exposure Index= 233 */
          {547,  674  },        /* Gain= 2.136719 Exposure Index= 234 */
          {564,  674  },        /* Gain= 2.203125 Exposure Index= 235 */
          {581,  674  },        /* Gain= 2.269531 Exposure Index= 236 */
          {599,  674  },        /* Gain= 2.339844 Exposure Index= 237 */
          {617,  674  },        /* Gain= 2.410156 Exposure Index= 238 */
          {636,  674  },        /* Gain= 2.484375 Exposure Index= 239 */
          {656,  674  },        /* Gain= 2.562500 Exposure Index= 240 */
          {676,  674  },        /* Gain= 2.640625 Exposure Index= 241 */
          {697,  674  },        /* Gain= 2.722656 Exposure Index= 242 */
          {718,  674  },        /* Gain= 2.804688 Exposure Index= 243 */
          {740,  674  },        /* Gain= 2.890625 Exposure Index= 244 */
          {763,  674  },        /* Gain= 2.980469 Exposure Index= 245 */
          {786,  674  },        /* Gain= 3.070313 Exposure Index= 246 */
          {810,  674  },        /* Gain= 3.164063 Exposure Index= 247 */
          {835,  674  },        /* Gain= 3.261719 Exposure Index= 248 */
          {861,  674  },        /* Gain= 3.363281 Exposure Index= 249 */
          {887,  674  },        /* Gain= 3.464844 Exposure Index= 250 */
          {914,  674  },        /* Gain= 3.570313 Exposure Index= 251 */
          {942,  674  },        /* Gain= 3.679688 Exposure Index= 252 */
          {971,  674  },        /* Gain= 3.792969 Exposure Index= 253 */
          {1001,  674  },        /* Gain= 3.910156 Exposure Index= 254 */
          {1032,  674  },        /* Gain= 4.031250 Exposure Index= 255 */
          {1063,  674  },        /* Gain= 4.152344 Exposure Index= 256 */
          {1095,  674  },        /* Gain= 4.277344 Exposure Index= 257 */
          {1128,  674  },        /* Gain= 4.406250 Exposure Index= 258 */
          {1162,  674  },        /* Gain= 4.539063 Exposure Index= 259 */
          {1197,  674  },        /* Gain= 4.675781 Exposure Index= 260 */
          {1233,  674  },        /* Gain= 4.816406 Exposure Index= 261 */
          {1270,  674  },        /* Gain= 4.960938 Exposure Index= 262 */
          {1309,  674  },        /* Gain= 5.113281 Exposure Index= 263 */
          {1349,  674  },        /* Gain= 5.269531 Exposure Index= 264 */
          {1390,  674  },        /* Gain= 5.429688 Exposure Index= 265 */
          {1432,  674  },        /* Gain= 5.593750 Exposure Index= 266 */
          {1475,  674  },        /* Gain= 5.761719 Exposure Index= 267 */
          {1520,  674  },        /* Gain= 5.937500 Exposure Index= 268 */
          {1566,  674  },        /* Gain= 6.117188 Exposure Index= 269 */
          {1613,  674  },        /* Gain= 6.300781 Exposure Index= 270 */
          {1662,  674  },        /* Gain= 6.492188 Exposure Index= 271 */
          {1712,  674  },        /* Gain= 6.687500 Exposure Index= 272 */
          {1764,  674  },        /* Gain= 6.890625 Exposure Index= 273 */
          {1817,  674  },        /* Gain= 7.097656 Exposure Index= 274 */
          {1872,  674  },        /* Gain= 7.312500 Exposure Index= 275 */
          {1929,  674  },        /* Gain= 7.535156 Exposure Index= 276 */
          {1987,  674  },        /* Gain= 7.761719 Exposure Index= 277 */
          {2047,  674  },        /* Gain= 7.996094 Exposure Index= 278 */
          {2048,  694  },        /* Gain= 8.000000 Exposure Index= 279 */
          {2048,  715  },        /* Gain= 8.000000 Exposure Index= 280 */
          {2048,  737  },        /* Gain= 8.000000 Exposure Index= 281 */
          {2048,  760  },        /* Gain= 8.000000 Exposure Index= 282 */
          {2048,  783  },        /* Gain= 8.000000 Exposure Index= 283 */
          {2048,  807  },        /* Gain= 8.000000 Exposure Index= 284 */
          {2048,  832  },        /* Gain= 8.000000 Exposure Index= 285 */
          {2048,  857  },        /* Gain= 8.000000 Exposure Index= 286 */
          {2048,  883  },        /* Gain= 8.000000 Exposure Index= 287 */
          {2048,  910  },        /* Gain= 8.000000 Exposure Index= 288 */
          {2048,  938  },        /* Gain= 8.000000 Exposure Index= 289 */
          {2048,  967  },        /* Gain= 8.000000 Exposure Index= 290 */
          {2048,  997  },        /* Gain= 8.000000 Exposure Index= 291 */
          {2048,  1027  },        /* Gain= 8.000000 Exposure Index= 292 */
          {2048,  1058  },        /* Gain= 8.000000 Exposure Index= 293 */
          {2048,  1090  },        /* Gain= 8.000000 Exposure Index= 294 */
          {2048,  1123  },        /* Gain= 8.000000 Exposure Index= 295 */
          {2048,  1157  },        /* Gain= 8.000000 Exposure Index= 296 */
          {2048,  1192  },        /* Gain= 8.000000 Exposure Index= 297 */
          {2048,  1228  },        /* Gain= 8.000000 Exposure Index= 298 */
          {2048,  1265  },        /* Gain= 8.000000 Exposure Index= 299 */
          {2048,  1303  },        /* Gain= 8.000000 Exposure Index= 300 */
          {2048,  1343  },        /* Gain= 8.000000 Exposure Index= 301 */
          {2048,  1384  },        /* Gain= 8.000000 Exposure Index= 302 */
          {2048,  1426  },        /* Gain= 8.000000 Exposure Index= 303 */
          {2048,  1469  },        /* Gain= 8.000000 Exposure Index= 304 */
          {2048,  1514  },        /* Gain= 8.000000 Exposure Index= 305 */
          {2048,  1560  },        /* Gain= 8.000000 Exposure Index= 306 */
          {2048,  1607  },        /* Gain= 8.000000 Exposure Index= 307 */
          {2048,  1656  },        /* Gain= 8.000000 Exposure Index= 308 */
          {2048,  1706  },        /* Gain= 8.000000 Exposure Index= 309 */
          {2048,  1758  },        /* Gain= 8.000000 Exposure Index= 310 */
          {2048,  1811  },        /* Gain= 8.000000 Exposure Index= 311 */
          {2048,  1866  },        /* Gain= 8.000000 Exposure Index= 312 */
          {2048,  1922  },        /* Gain= 8.000000 Exposure Index= 313 */
          {2048,  1980  },        /* Gain= 8.000000 Exposure Index= 314 */
          {2048,  2040  },        /* Gain= 8.000000 Exposure Index= 315 */
          {2048,  2102  },        /* Gain= 8.000000 Exposure Index= 316 */
          {2048,  2166  },        /* Gain= 8.000000 Exposure Index= 317 */
          {2048,  2231  },        /* Gain= 8.000000 Exposure Index= 318 */
          {2048,  2298  },        /* Gain= 8.000000 Exposure Index= 319 */
          {2048,  2367  },        /* Gain= 8.000000 Exposure Index= 320 */
          {2048,  2439  },        /* Gain= 8.000000 Exposure Index= 321 */
          {2048,  2513  },        /* Gain= 8.000000 Exposure Index= 322 */
          {2048,  2589  },        /* Gain= 8.000000 Exposure Index= 323 */
          {2048,  2667  },        /* Gain= 8.000000 Exposure Index= 324 */
          {2086,  2698  },        /* Gain= 8.148438 Exposure Index= 325 */
          {2149,  2698  },        /* Gain= 8.394531 Exposure Index= 326 */
          {2214,  2698  },        /* Gain= 8.648438 Exposure Index= 327 */
          {2281,  2698  },        /* Gain= 8.910156 Exposure Index= 328 */
          {2350,  2698  },        /* Gain= 9.179688 Exposure Index= 329 */
          {2421,  2698  },        /* Gain= 9.457031 Exposure Index= 330 */
          {2494,  2698  },        /* Gain= 9.742188 Exposure Index= 331 */
          {2569,  2698  },        /* Gain= 10.035156 Exposure Index= 332 */
          {2647,  2698  },        /* Gain= 10.339844 Exposure Index= 333 */
          {2727,  2698  },        /* Gain= 10.652344 Exposure Index= 334 */
          {2809,  2698  },        /* Gain= 10.972656 Exposure Index= 335 */
          {2894,  2698  },        /* Gain= 11.304688 Exposure Index= 336 */
          {2981,  2698  },        /* Gain= 11.644531 Exposure Index= 337 */
          {3071,  2698  },        /* Gain= 11.996094 Exposure Index= 338 */
          {3164,  2698  },        /* Gain= 12.359375 Exposure Index= 339 */
          {3259,  2698  },        /* Gain= 12.730469 Exposure Index= 340 */
          {3357,  2698  },        /* Gain= 13.113281 Exposure Index= 341 */
          {3458,  2698  },        /* Gain= 13.507813 Exposure Index= 342 */
          {3562,  2698  },        /* Gain= 13.914063 Exposure Index= 343 */
          {3669,  2698  },        /* Gain= 14.332031 Exposure Index= 344 */
          {3780,  2698  },        /* Gain= 14.765625 Exposure Index= 345 */
          {3894,  2698  },        /* Gain= 15.210938 Exposure Index= 346 */
          {4011,  2698  },        /* Gain= 15.667969 Exposure Index= 347 */
          {4132,  2698  },        /* Gain= 16.140625 Exposure Index= 348 */
          {4256,  2698  },        /* Gain= 16.625000 Exposure Index= 349 */
          {4384,  2698  },        /* Gain= 17.125000 Exposure Index= 350 */
          {4516,  2698  },        /* Gain= 17.640625 Exposure Index= 351 */
          {4652,  2698  },        /* Gain= 18.171875 Exposure Index= 352 */
          {4792,  2698  },        /* Gain= 18.718750 Exposure Index= 353 */
          {4936,  2698  },        /* Gain= 19.281250 Exposure Index= 354 */
          {5085,  2698  },        /* Gain= 19.863281 Exposure Index= 355 */
          {5238,  2698  },        /* Gain= 20.460938 Exposure Index= 356 */
          {5396,  2698  },        /* Gain= 21.078125 Exposure Index= 357 */
          {5558,  2698  },        /* Gain= 21.710938 Exposure Index= 358 */
          {5725,  2698  },        /* Gain= 22.363281 Exposure Index= 359 */
          {5897,  2698  },        /* Gain= 23.035156 Exposure Index= 360 */
          {6074,  2698  },        /* Gain= 23.726563 Exposure Index= 361 */
          {6257,  2698  },        /* Gain= 24.441406 Exposure Index= 362 */
          {6445,  2698  },        /* Gain= 25.175781 Exposure Index= 363 */
          {6639,  2698  },        /* Gain= 25.933594 Exposure Index= 364 */
          {6839,  2698  },        /* Gain= 26.714844 Exposure Index= 365 */
          {7045,  2698  },        /* Gain= 27.519531 Exposure Index= 366 */
          {7257,  2698  },        /* Gain= 28.347656 Exposure Index= 367 */
          {7475,  2698  },        /* Gain= 29.199219 Exposure Index= 368 */
          {7700,  2698  },        /* Gain= 30.078125 Exposure Index= 369 */
          {7931,  2698  },        /* Gain= 30.980469 Exposure Index= 370 */
          {8169,  2698  },        /* Gain= 31.910156 Exposure Index= 371 */
          {8415,  2698  },        /* Gain= 32.871094 Exposure Index= 372 */
          {8668,  2698  },        /* Gain= 33.859375 Exposure Index= 373 */
          {8929,  2698  },        /* Gain= 34.878906 Exposure Index= 374 */
          {9197,  2698  },        /* Gain= 35.925781 Exposure Index= 375 */
          {9473,  2698  },        /* Gain= 37.003906 Exposure Index= 376 */
          {9758,  2698  },        /* Gain= 38.117188 Exposure Index= 377 */
          {10051,  2698  },        /* Gain= 39.261719 Exposure Index= 378 */
          {10353,  2698  },        /* Gain= 40.441406 Exposure Index= 379 */
          {10664,  2698  },        /* Gain= 41.656250 Exposure Index= 380 */
          {10984,  2698  },        /* Gain= 42.906250 Exposure Index= 381 */
          {11314,  2698  },        /* Gain= 44.195313 Exposure Index= 382 */
          {11654,  2698  },        /* Gain= 45.523438 Exposure Index= 383 */
          {12004,  2698  },        /* Gain= 46.890625 Exposure Index= 384 */
          {12365,  2698  },        /* Gain= 48.300781 Exposure Index= 385 */
          {12736,  2698  },        /* Gain= 49.750000 Exposure Index= 386 */
          {13119,  2698  },        /* Gain= 51.246094 Exposure Index= 387 */
          {13513,  2698  },        /* Gain= 52.785156 Exposure Index= 388 */
          {13919,  2698  },        /* Gain= 54.371094 Exposure Index= 389 */
          {14337,  2698  },        /* Gain= 56.003906 Exposure Index= 390 */
          {14768,  2698  },        /* Gain= 57.687500 Exposure Index= 391 */
          {15212,  2698  },        /* Gain= 59.421875 Exposure Index= 392 */
          {15669,  2698  },        /* Gain= 61.207031 Exposure Index= 393 */
          {16140,  2698  },        /* Gain= 63.046875 Exposure Index= 394 */
          {16625,  2698  },        /* Gain= 64.941406 Exposure Index= 395 */
          {17124,  2698  },        /* Gain= 66.890625 Exposure Index= 396 */
          {17638,  2698  },        /* Gain= 68.898438 Exposure Index= 397 */
          {18168,  2698  },        /* Gain= 70.968750 Exposure Index= 398 */
          {18714,  2698  },        /* Gain= 73.101563 Exposure Index= 399 */
          {19276,  2698  },        /* Gain= 75.296875 Exposure Index= 400 */
          {19855,  2698  },        /* Gain= 77.558594 Exposure Index= 401 */
          {20451,  2698  },        /* Gain= 79.886719 Exposure Index= 402 */
          {21065,  2698  },        /* Gain= 82.285156 Exposure Index= 403 */
          {21697,  2698  },        /* Gain= 84.753906 Exposure Index= 404 */
          {22348,  2698  },        /* Gain= 87.296875 Exposure Index= 405 */
          {23019,  2698  },        /* Gain= 89.917969 Exposure Index= 406 */
          {23710,  2698  },        /* Gain= 92.617188 Exposure Index= 407 */
          {24422,  2698  },        /* Gain= 95.398438 Exposure Index= 408 */
          {25155,  2698  },        /* Gain= 98.261719 Exposure Index= 409 */
          {25910,  2698  },        /* Gain= 101.210938 Exposure Index= 410 */
          {26688,  2698  },        /* Gain= 104.250000 Exposure Index= 411 */
          {27489,  2698  },        /* Gain= 107.378906 Exposure Index= 412 */
          {28314,  2698  },        /* Gain= 110.601563 Exposure Index= 413 */
          {29164,  2698  },        /* Gain= 113.921875 Exposure Index= 414 */
          {30039,  2698  },        /* Gain= 117.339844 Exposure Index= 415 */
          {30941,  2698  },        /* Gain= 120.863281 Exposure Index= 416 */
          {31870,  2698  },        /* Gain= 124.492188 Exposure Index= 417 */
        },
    },	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            35,  /* outdoor_luma_target_compensated 35*/
            30,  /* default_luma_target_compensated 30*/
            14,/* low_light.luma_target 14*/
            160,  /* outdoor_index */
            190,  /* indoor_index */
            380,/* low_light.start_idx */
            400,/* low_light.end_idx */
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
        { 0.3937, 0.5626 },    /* d75 */
        { 0.4225, 0.5246 },    /* d65 */
        { 0.4853, 0.4554 },    /* d50 */
        { 0.4853, 0.4554 },    /* noon */
        { 0.4881, 0.3417 },    /* cw */
        { 0.5942, 0.3595 },    /* tl84 */
        { 0.7261, 0.2649 },    /* a */
        { 0.8691, 0.2139 },    /* h */
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
        {10,10,10, 2 },   /*   d50    */
        {10,10,10, 2 },   /*   noon   */
        { 0, 0, 1, 1 },   /*   cw     */
        { 0, 0, 1, 1 },   /*   tl84   */
        { 0, 0, 1, 1 },   /*   a      */
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
