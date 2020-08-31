
/*---------------header of gc2385 tuing-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x00000001,
/*tuning_ctl_t tuning_ctl  */
{
  //float aec_trigger_tolerence;
  5,
  //float aec_trigger_tolerence_gain
 0.9,
  //float awb_trigger_tolerence; /
  100,
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
       1,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       {
          /*region 1 */
          {
            1.000,
            224.000, //120
          },
          /*region 2 */
          {
            64.000,
            112.000,
          },

          /*region 3 */
          {
            128.000,
            224.000,
          },
          /*region 4 */
          {
            1001.000,
            1183.000,
          },
       },
       {
           /*parameter 1 */
           {
               1040,
               1040,
               1040,
               1040,
               274,
               274,
               274,
               274,
           },
           /*parameter 2 */
           {
               1074,
               1111,
               1060,
               1118,
               274,
               275,
               274,
               275,
           },
           /*parameter 3 */
           {
               1291,
               1421,
               1268,
               1397,
               278,
               281,
               278,
               280,
           },
           /*parameter 5 */
           {
               891,
               805,
               956,
               950,
               271,
               270,
               272,
               272,
           },
       },
    },

    /*isp_sub_module_hdr_mix_tuning_t isp_sub_module_hdr_mix_tuning;*/
    {

    },
    /* isp_sub_module_compander_tuning_t isp_sub_module_compander_tuning*/
    {
    },
    /* isp_sub_module_dpc_tuning_t isp_sub_module_dpc_tuning*/
    {
      0, //enable
      /*interpolation enable*/
      0,
      5, //ae count
      0, //sram mode 0 otf mode, 1 static lut table mode
      0, //trigger mode : 0 gain trigger 1 lux trigger
      {
          0, //pra0 enable
	  0, //pra1 enable
          0, //pra2 enable
	  0, //pra3 enable
          0, //pra4 enable
      },
      /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==5 */
      {
          /*aec trigger 0*/
          {
            1.000000,
            3.000000,
          },
          /*aec trigger 1*/
          {
            3.0000000,
            6.000000,
          },
          /*aec trigger 2*/
          {
            6.0000000,
            9.000000,
          },
          /*aec trigger 3*/
          {
            9.0000000,
            12.000000,
          },
          /*aec trigger 4*/
          {
            12.0000000,
            32.000000,
          },
      },
      /*isp_sub_module_dpc_pra pra[MIDDLE_TRIGGER_COUNT]*/
      {
          /*pra 0*/
          {
            0x0000004c,0x00000000, 0x0000003c,0x000000c8, 0x00000320, 0x0000003c, 0x000000c8, 0x00000320, 0x0000003c, 0x00000190,
            0x00000320,0x0000003c, 0x00000190,0x00000320, 0x00000033, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200,
            0x00000000,0x00000020, 0x00000060,0x000000a0, 0x000000e0,
          },
          /*pra 1*/
          {
            0x0000004c,0x00000000, 0x0000003c,0x000000c8, 0x00000320, 0x0000003c, 0x000000c8, 0x00000320, 0x0000003c, 0x00000190,
            0x00000320,0x0000003c, 0x00000190,0x00000320, 0x00000033, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200,
            0x00000000,0x00000020, 0x00000060,0x000000a0, 0x000000e0,
          },
          /*pra 2*/
          {
            0x0000004c,0x00000000, 0x0000003c,0x000000c8, 0x00000320, 0x0000003c, 0x000000c8, 0x00000320, 0x0000003c, 0x00000190,
            0x00000320,0x0000003c, 0x00000190,0x00000320, 0x00000033, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200,
            0x00000000,0x00000020, 0x00000060,0x000000a0, 0x000000e0,
          },
          /*pra 3*/
          {
            0x0000004c,0x00000000, 0x0000003c,0x000000c8, 0x00000320, 0x0000003c, 0x000000c8, 0x00000320, 0x0000003c, 0x00000190,
            0x00000320,0x0000003c, 0x00000190,0x00000320, 0x00000033, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200,
            0x00000000,0x00000020, 0x00000060,0x000000a0, 0x000000e0,
          },
          /*pra 4*/
          {
            0x0000004c,0x00000000, 0x0000003c,0x000000c8, 0x00000320, 0x0000003c, 0x000000c8, 0x00000320, 0x0000003c, 0x00000190,
            0x00000320,0x0000003c, 0x00000190,0x00000320, 0x00000033, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200,
            0x00000000,0x00000020, 0x00000060,0x000000a0, 0x000000e0,
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
    /* isp_sub_module_rnr_tuning_t isp_sub_module_rnr_tuning*/
    /* isp_sub_module_rnr_tuning_t isp_sub_module_rnr_tuning */
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       11,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       /*aec_trigger_t aec_trigger[MIDDLE_TRIGGER_COUNT] MIDDLE_TRIGGER_COUNT==5 */
       {
          /*aec trigger 1 */
          {
            1.000,
            1.500,
          },
          /*aec trigger 2 */
          {
            2.000,
            3.500,
          },
          /*aec trigger 3 */
          {
            4.000,
            6.000,
          },
          /*aec trigger 4 */
          {
            7.000,
            10.000,
          },
          /*aec trigger 5 */
          {
            14.000,
            17.000,
          },
          /*aec trigger 6 */
          {
            31.000,
            36.000,
          },
          /*aec trigger 7 */
          {
            60.000,
            70.000,
          },
          /*aec trigger 8 */
          {
            128.000,
            137.000,
          },
          /*aec trigger 9 */
          {
            220.000,
            240.000,
          },
          /*aec trigger 10 */
          {
            517.000,
            533.000,
          },
          /*aec trigger 11 */
          {
            855.000,
            1000.000,
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
                        {30,90,84},
                        //g channel
                        {30,90,84},
                        //b channel
                        {30,90,84},
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
                        {25,75,49},
                        //g channel
                        {25,75,49},
                        //b channel
                        {25,75,49},
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
                        {50,150,142},
                        //g channel
                        {50,150,142},
                        //b channel
                        {50,150,142},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {50,150,101},
                        //g channel
                        {50,150,101},
                        //b channel
                        {50,150,101},
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
                1,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {65,195,185},
                        //g channel
                        {65,195,185},
                        //b channel
                        {65,195,185},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {65,195,132},
                        //g channel
                        {65,195,132},
                        //b channel
                        {65,195,132},
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
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {65,195,185},
                        //g channel
                        {65,195,185},
                        //b channel
                        {65,195,185},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {65,195,132},
                        //g channel
                        {65,195,132},
                        //b channel
                        {65,195,132},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {50,150,101},
                        //g channel
                        {50,150,101},
                        //b channel
                        {50,150,101},
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
                        {86,258,176},
                        //g channel
                        {86,258,176},
                        //b channel
                        {86,258,176},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {65,195,132},
                        //g channel
                        {65,195,132},
                        //b channel
                        {65,195,132},
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
            /* para 8 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {260,780,751},
                        //g channel
                        {260,780,751},
                        //b channel
                        {260,780,751},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {220,660,453},
                        //g channel
                        {220,660,453},
                        //b channel
                        {220,660,453},
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
                        {220,660,453},
                        //g channel
                        {220,660,453},
                        //b channel
                        {220,660,453},
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
                        {280,840,809},
                        //g channel
                        {280,840,809},
                        //b channel
                        {280,840,809},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {220,660,453},
                        //g channel
                        {220,660,453},
                        //b channel
                        {220,660,453},
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
                        {240,720,495},
                        //g channel
                        {240,720,495},
                        //b channel
                        {240,720,495},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {220,660,453},
                        //g channel
                        {220,660,453},
                        //b channel
                        {220,660,453},
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
        6,//awb count
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
     			3200,
     		},
			/*awb trigger 2*/
     		{
     			3500,
     			3960,
     		},
     		/*awb trigger 2*/
     		{
     			4000,
     			4200,
     		},
     		/*awb trigger 3*/
     		{
     			4500,
     			5500,
     		},
     		/*awb trigger 4*/
     		{
     			6000,
     			7000,
     		},
     		/*awb trigger 5*/
     		{
     			7200,
     			8000,
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
                      5.1826, 3.3667, 2.6675, 2.4897, 2.4219, 2.3647, 2.4810, 2.5815, 3.0903, 4.4941,
                      4.3237, 2.7964, 2.5850, 2.2891, 2.0723, 2.0142, 2.1914, 2.4253, 2.7114, 3.6533,
                      3.3232, 2.6782, 2.2832, 1.8911, 1.5107, 1.4736, 1.6650, 2.0903, 2.5215, 2.9839,
                      3.2598, 2.4717, 2.1870, 1.5034, 1.2388, 1.1943, 1.3550, 1.8096, 2.4312, 2.9097,
                      2.8843, 2.5098, 1.8945, 1.3276, 1.0449, 0.9990, 1.1553, 1.5024, 2.2021, 2.7212,
                      2.9087, 2.4302, 1.8462, 1.2500, 0.9937, 0.9409, 1.1406, 1.4180, 2.2241, 2.7012,
                      2.9707, 2.4951, 1.9258, 1.3291, 1.0542, 1.0049, 1.1392, 1.5459, 2.2109, 2.7407,
                      3.3555, 2.5845, 2.1572, 1.5410, 1.2095, 1.1660, 1.3081, 1.7573, 2.4033, 2.7847,
                      3.5249, 2.6528, 2.2764, 1.8223, 1.4746, 1.4063, 1.5933, 2.0435, 2.4526, 3.1128,
                      5.0244, 3.1318, 2.6919, 2.3550, 2.0366, 1.9419, 2.2461, 2.4434, 2.7334, 3.7051,
                      4.3369, 2.6450, 2.2305, 1.9922, 2.0801, 1.9663, 2.0806, 2.0420, 2.5225, 3.4438,
                      3.3125, 2.2515, 2.0493, 1.9590, 1.7988, 1.7700, 1.8525, 1.9941, 2.1333, 2.9048,
                      2.6733, 2.0347, 1.9487, 1.6240, 1.4365, 1.3745, 1.5225, 1.7378, 2.0161, 2.2588,
                      2.5044, 1.9858, 1.7739, 1.4121, 1.1865, 1.1611, 1.2974, 1.5449, 1.9614, 2.2021,
                      2.2998, 1.9673, 1.6494, 1.2285, 1.0283, 1.0176, 1.1089, 1.3350, 1.7192, 2.0820,
                      2.2295, 1.9536, 1.5674, 1.1987, 0.9937, 0.9609, 1.1069, 1.2437, 1.7993, 2.0591,
                      2.2939, 1.9800, 1.6250, 1.2139, 1.0229, 1.0010, 1.0757, 1.3237, 1.7070, 2.0815,
                      2.5947, 2.0747, 1.7778, 1.4272, 1.1489, 1.1191, 1.2275, 1.5229, 1.9058, 2.1348,
                      2.8145, 2.0684, 1.8740, 1.5586, 1.3628, 1.2886, 1.4043, 1.6489, 1.9067, 2.4116,
                      3.7524, 2.6401, 2.1484, 1.9956, 1.7622, 1.7656, 1.9111, 2.1152, 2.1904, 2.9282,
                      4.3228, 2.3867, 2.0293, 1.8438, 1.7627, 1.7197, 1.8140, 1.8628, 2.2856, 3.3940,
                      3.1821, 2.1436, 1.9414, 1.8423, 1.6504, 1.5708, 1.6382, 1.7627, 1.9092, 2.6040,
                      2.5005, 1.9146, 1.7788, 1.5566, 1.3521, 1.2983, 1.3853, 1.6167, 1.8042, 2.1890,
                      2.3828, 1.8374, 1.7310, 1.3848, 1.1489, 1.1123, 1.2715, 1.4521, 1.8486, 2.1216,
                      2.0781, 1.8535, 1.5586, 1.2319, 1.0151, 1.0093, 1.0845, 1.2568, 1.5708, 1.8560,
                      2.1460, 1.7637, 1.5000, 1.1724, 1.0088, 0.9507, 1.1514, 1.2090, 1.7026, 1.9609,
                      2.0781, 1.7778, 1.5161, 1.1675, 0.9922, 0.9829, 1.0522, 1.2803, 1.6338, 1.9229,
                      2.3799, 1.8086, 1.6030, 1.2881, 1.0708, 1.0508, 1.1948, 1.4844, 1.8262, 1.9575,
                      2.5146, 1.8232, 1.6465, 1.4214, 1.2412, 1.1865, 1.3213, 1.5625, 1.7671, 2.3018,
                      3.1191, 2.2241, 1.8198, 1.6860, 1.5381, 1.6460, 1.7988, 1.9595, 2.0815, 2.6025,
                    },
         		},
         		/* para 2 */
         		{
                   	0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.6670, 2.5459, 2.2759, 1.9297, 1.9707, 2.0039, 1.9346, 2.0313, 2.5239, 3.3716,
                      3.3574, 2.3213, 2.0098, 1.9302, 1.6948, 1.7041, 1.8159, 1.9595, 2.2061, 2.8525,
                      2.6411, 2.0859, 1.8906, 1.5947, 1.3853, 1.3340, 1.5073, 1.7354, 2.0430, 2.4131,
                      2.5625, 1.9956, 1.7964, 1.3643, 1.1377, 1.1533, 1.2109, 1.5596, 1.9668, 2.2412,
                      2.2686, 2.0063, 1.6265, 1.2261, 1.0332, 0.9888, 1.1353, 1.3330, 1.8804, 2.0996,
                      2.2676, 1.9634, 1.5942, 1.1777, 0.9976, 0.9238, 1.0742, 1.3076, 1.8086, 2.1831,
                      2.4185, 1.9771, 1.6602, 1.2231, 1.0439, 0.9985, 1.0908, 1.3765, 1.8096, 2.1250,
                      2.5308, 2.0938, 1.7900, 1.3745, 1.1675, 1.0830, 1.2373, 1.4941, 1.9561, 2.2397,
                      2.9678, 2.0898, 1.8940, 1.5718, 1.3174, 1.2705, 1.3853, 1.6963, 1.9834, 2.5215,
                      3.6387, 2.5342, 2.1191, 1.8755, 1.7661, 1.6167, 1.7969, 1.9463, 2.1592, 2.8701,
                      4.3984, 2.4194, 2.1089, 1.9302, 1.8853, 1.8823, 1.9404, 1.9224, 2.3188, 3.1875,
                      3.0352, 2.1299, 1.9131, 1.8311, 1.6953, 1.6406, 1.7539, 1.8608, 1.9775, 2.6602,
                      2.5298, 1.8750, 1.8110, 1.5562, 1.3350, 1.3418, 1.4199, 1.6958, 1.8271, 2.2354,
                      2.2573, 1.8916, 1.6934, 1.3350, 1.1660, 1.1348, 1.2080, 1.4614, 1.7759, 2.0352,
                      2.1636, 1.8379, 1.5464, 1.1860, 1.0044, 1.0264, 1.0718, 1.3188, 1.6782, 1.9893,
                      2.1426, 1.8433, 1.5410, 1.1665, 0.9976, 0.9517, 1.0269, 1.2373, 1.6187, 1.9238,
                      2.1567, 1.8389, 1.5400, 1.1777, 1.0171, 1.0020, 1.0830, 1.2612, 1.6421, 1.9849,
                      2.4067, 1.9443, 1.7178, 1.3569, 1.1377, 1.0947, 1.1846, 1.4175, 1.8066, 1.9614,
                      2.6401, 1.9492, 1.7759, 1.5054, 1.2935, 1.2505, 1.3389, 1.5303, 1.8179, 2.2891,
                      3.5981, 2.4883, 2.1074, 1.8872, 1.7427, 1.6089, 1.8130, 1.9155, 2.1250, 2.7271,
                      4.3638, 2.2808, 2.0742, 1.7305, 1.7266, 1.6831, 1.6313, 1.7197, 2.0566, 3.0273,
                      2.7598, 2.0894, 1.7788, 1.7480, 1.6138, 1.5098, 1.6123, 1.7383, 1.8320, 2.4248,
                      2.5713, 1.8267, 1.7725, 1.5322, 1.3022, 1.2842, 1.2974, 1.5557, 1.6812, 2.0923,
                      2.1973, 1.7944, 1.6440, 1.3242, 1.1768, 1.0933, 1.2256, 1.3564, 1.6753, 1.8794,
                      1.9517, 1.8042, 1.4893, 1.1948, 1.0713, 1.0176, 1.0757, 1.2188, 1.5723, 1.7334,
                      1.9702, 1.7158, 1.4341, 1.1499, 0.9819, 0.9551, 1.0254, 1.1963, 1.5112, 1.8232,
                      1.9077, 1.6855, 1.4331, 1.1206, 1.0103, 0.9717, 1.0762, 1.1792, 1.5845, 1.7178,
                      2.1367, 1.7827, 1.5156, 1.2534, 1.0791, 1.0386, 1.1455, 1.3633, 1.7129, 1.8164,
                      2.3550, 1.7070, 1.5864, 1.3320, 1.1812, 1.1641, 1.2739, 1.4390, 1.7280, 2.1738,
                      3.1338, 2.2402, 1.8623, 1.7192, 1.5645, 1.4580, 1.6548, 1.7607, 1.9497, 2.3638,
                    },
         		},
    			/* para 3 */
         		{
                   	0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.6006, 2.7778, 2.2007, 2.0635, 1.9429, 1.9199, 1.9951, 2.0508, 2.5874, 3.6084,
                      3.2500, 2.3159, 2.0410, 1.8784, 1.7427, 1.7578, 1.7646, 2.0405, 2.1392, 2.9849,
                      2.8955, 2.0571, 1.9375, 1.5913, 1.4189, 1.3364, 1.5024, 1.7798, 2.0308, 2.4897,
                      2.5317, 2.0142, 1.7705, 1.3960, 1.1323, 1.1704, 1.2280, 1.5757, 1.9243, 2.3022,
                      2.3188, 2.0073, 1.6382, 1.2212, 1.0542, 0.9980, 1.1226, 1.3677, 1.8354, 2.0591,
                      2.2036, 1.9648, 1.5688, 1.2021, 0.9722, 0.9521, 1.0576, 1.3164, 1.7466, 2.1563,
                      2.3799, 2.0103, 1.6626, 1.2241, 1.0366, 1.0161, 1.0977, 1.4014, 1.7827, 2.1401,
                      2.6294, 2.0596, 1.7798, 1.3965, 1.1631, 1.0889, 1.2178, 1.5044, 1.9438, 2.1650,
                      2.7915, 2.1357, 1.8818, 1.5459, 1.3550, 1.2900, 1.4038, 1.6689, 1.9424, 2.5356,
                      3.8721, 2.5073, 2.1533, 1.9175, 1.7114, 1.6382, 1.7681, 2.0171, 2.1978, 2.8994,
                      4.3789, 2.4419, 2.1211, 1.9307, 1.9028, 1.8936, 1.9561, 1.9473, 2.3179, 3.4307,
                      3.0845, 2.1802, 1.9136, 1.8174, 1.6943, 1.6636, 1.7305, 1.8843, 1.9966, 2.6489,
                      2.5117, 1.9180, 1.8535, 1.5649, 1.3521, 1.3408, 1.4536, 1.6938, 1.9194, 2.2329,
                      2.3574, 1.9209, 1.6982, 1.3442, 1.1528, 1.1074, 1.2183, 1.5029, 1.7773, 2.1113,
                      2.1626, 1.8906, 1.5942, 1.2236, 1.0195, 1.0273, 1.0991, 1.3027, 1.7563, 1.9438,
                      2.1304, 1.9004, 1.5420, 1.2002, 1.0083, 0.9312, 1.0659, 1.2583, 1.6587, 2.0039,
                      2.1772, 1.8818, 1.5601, 1.2192, 1.0010, 1.0205, 1.0698, 1.3193, 1.6812, 2.0059,
                      2.4653, 2.0020, 1.7559, 1.3877, 1.1538, 1.1128, 1.2036, 1.4590, 1.7910, 2.0396,
                      2.6528, 1.9907, 1.7720, 1.5361, 1.3047, 1.2617, 1.3491, 1.6157, 1.8364, 2.3936,
                      3.8247, 2.5034, 2.1133, 2.0029, 1.7026, 1.6992, 1.7822, 1.9995, 2.0811, 2.7397,
                      4.6694, 2.3105, 2.0161, 1.7388, 1.6987, 1.6187, 1.6621, 1.6973, 2.1143, 3.1265,
                      2.7495, 2.0864, 1.8228, 1.7568, 1.6206, 1.5181, 1.6050, 1.6992, 1.8120, 2.3804,
                      2.5420, 1.7935, 1.7734, 1.5190, 1.3193, 1.2832, 1.3252, 1.5581, 1.6997, 2.0386,
                      2.1577, 1.7876, 1.7061, 1.3018, 1.1855, 1.0918, 1.1870, 1.3599, 1.6602, 1.8452,
                      2.0366, 1.7178, 1.5210, 1.2129, 1.0190, 1.0303, 1.0542, 1.2422, 1.5542, 1.7017,
                      1.8364, 1.6870, 1.4429, 1.1025, 1.0176, 0.9502, 1.0269, 1.1929, 1.5054, 1.8052,
                      1.9541, 1.6909, 1.4399, 1.1484, 0.9873, 0.9893, 1.0415, 1.1934, 1.5796, 1.6538,
                      2.0981, 1.7168, 1.5215, 1.2319, 1.0737, 1.0610, 1.1313, 1.3765, 1.6885, 1.8247,
                      2.3027, 1.7627, 1.5923, 1.3706, 1.1943, 1.1816, 1.2461, 1.4443, 1.7163, 2.1421,
                      3.2388, 2.1475, 1.8911, 1.7402, 1.5503, 1.5420, 1.6152, 1.8120, 1.9170, 2.3457,
                    },
         		},
         		/* para 4 */
         		{
                   	0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      5.2671, 3.0522, 2.5073, 2.2969, 2.2026, 2.1855, 2.2583, 2.2798, 2.8555, 3.7749,
                      3.8262, 2.6470, 2.3135, 2.1597, 1.9175, 1.8584, 2.0107, 2.2339, 2.4663, 3.4497,
                      3.1660, 2.3447, 2.1323, 1.7617, 1.4922, 1.4302, 1.6050, 1.9648, 2.2505, 2.7876,
                      2.9258, 2.3198, 1.9731, 1.5000, 1.1865, 1.1582, 1.3140, 1.6904, 2.1797, 2.5835,
                      2.5977, 2.2554, 1.8130, 1.3008, 1.0542, 1.0293, 1.1416, 1.4956, 2.0112, 2.4932,
                      2.6621, 2.1904, 1.7388, 1.2358, 0.9941, 0.9312, 1.0825, 1.3862, 1.9727, 2.4346,
                      2.6069, 2.2734, 1.8203, 1.2695, 1.0513, 1.0190, 1.1162, 1.4609, 2.0122, 2.3613,
                      2.9536, 2.3364, 2.0005, 1.4961, 1.1909, 1.1411, 1.2725, 1.7085, 2.1865, 2.5903,
                      3.2651, 2.3691, 2.0962, 1.6763, 1.4458, 1.3428, 1.5083, 1.8286, 2.2026, 2.7549,
                      4.0142, 2.8809, 2.3550, 2.1699, 1.8589, 1.8384, 1.9980, 2.2725, 2.5103, 3.3223,
                      4.5630, 2.4365, 2.1621, 1.9414, 1.9360, 1.8662, 1.9463, 2.0098, 2.2739, 3.5645,
                      3.0591, 2.2246, 1.9727, 1.8652, 1.7583, 1.7031, 1.7803, 1.9253, 2.0845, 2.6851,
                      2.5825, 1.8984, 1.8560, 1.5596, 1.3623, 1.3306, 1.4409, 1.6948, 1.8711, 2.2979,
                      2.3726, 1.9805, 1.7407, 1.3975, 1.1860, 1.1582, 1.2485, 1.5161, 1.8457, 2.1348,
                      2.2759, 1.8794, 1.6436, 1.2256, 1.0493, 1.0181, 1.1221, 1.3408, 1.7422, 2.0332,
                      2.1431, 1.9365, 1.5303, 1.2007, 0.9819, 0.9453, 1.0469, 1.2485, 1.6758, 1.9878,
                      2.2681, 1.9302, 1.6255, 1.2319, 1.0391, 1.0229, 1.1045, 1.3389, 1.7222, 2.0801,
                      2.5024, 2.0342, 1.7671, 1.3931, 1.1514, 1.1128, 1.1968, 1.4761, 1.8389, 2.0591,
                      2.7070, 2.0293, 1.7944, 1.5552, 1.3154, 1.2544, 1.3623, 1.6128, 1.8257, 2.3735,
                      3.6548, 2.5767, 2.1763, 1.9590, 1.7354, 1.7002, 1.8198, 1.9917, 2.1475, 2.8354,
                      4.3647, 2.5928, 2.0571, 1.9897, 1.8877, 1.7969, 1.9116, 1.8535, 2.2817, 3.2007,
                      3.1533, 2.2002, 2.0425, 1.8877, 1.7490, 1.6499, 1.7056, 1.7988, 1.9648, 2.5044,
                      2.4961, 1.9785, 1.8569, 1.6104, 1.3804, 1.3369, 1.3960, 1.6323, 1.7847, 2.2520,
                      2.3179, 1.9585, 1.7651, 1.4170, 1.2163, 1.1348, 1.2344, 1.4375, 1.7603, 1.9365,
                      2.2227, 1.8936, 1.6313, 1.2485, 1.0781, 1.0166, 1.0820, 1.2949, 1.6323, 1.8926,
                      2.0708, 1.8218, 1.4805, 1.1831, 0.9912, 0.9146, 1.0249, 1.2075, 1.5811, 1.8535,
                      2.1733, 1.7974, 1.5444, 1.1650, 1.0020, 0.9683, 1.0610, 1.2656, 1.6304, 1.8628,
                      2.3779, 1.8477, 1.6250, 1.3042, 1.1064, 1.0547, 1.1616, 1.4175, 1.7847, 1.9004,
                      2.4429, 1.8286, 1.6235, 1.3823, 1.2202, 1.1548, 1.2798, 1.5181, 1.7334, 2.2827,
                      3.3682, 2.3105, 1.9971, 1.7622, 1.5889, 1.5884, 1.7339, 1.8252, 2.0859, 2.3516,
                    },
         		},
         		/* para 5 */
         		{
                   	0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.8398, 3.0840, 2.4717, 2.2749, 2.2554, 2.2349, 2.2056, 2.4063, 2.7578, 4.1772,
                      3.7891, 2.6089, 2.3247, 2.1353, 1.9292, 1.8242, 2.0088, 2.2051, 2.4097, 3.2021,
                      3.1084, 2.3677, 2.1406, 1.7339, 1.4575, 1.4561, 1.5503, 1.9590, 2.2827, 2.6953,
                      2.7954, 2.2886, 1.9595, 1.4707, 1.2241, 1.1689, 1.3384, 1.6709, 2.1606, 2.5698,
                      2.7222, 2.2646, 1.7915, 1.2979, 1.0498, 1.0103, 1.1318, 1.4595, 1.9971, 2.3877,
                      2.5840, 2.2632, 1.6968, 1.2764, 0.9839, 0.9409, 1.1162, 1.3979, 1.9473, 2.4780,
                      2.6929, 2.2388, 1.8135, 1.2837, 1.0742, 1.0127, 1.1206, 1.4517, 1.9893, 2.3765,
                      2.8604, 2.3828, 1.9507, 1.4917, 1.1875, 1.1416, 1.2891, 1.6230, 2.1865, 2.4102,
                      3.3252, 2.3159, 2.1074, 1.6646, 1.4346, 1.3496, 1.5093, 1.8667, 2.2080, 2.8325,
                      4.0552, 2.8887, 2.3887, 2.1836, 1.7866, 1.8198, 1.9570, 2.1973, 2.5562, 3.0093,
                      4.2983, 2.4258, 2.1597, 1.8984, 1.9448, 1.8350, 1.9341, 1.8984, 2.3726, 3.2202,
                      3.0620, 2.2158, 1.9063, 1.8633, 1.6797, 1.6543, 1.7466, 1.8794, 2.0166, 2.7393,
                      2.6738, 1.9321, 1.8877, 1.5693, 1.3828, 1.3462, 1.4409, 1.6904, 1.9092, 2.2148,
                      2.3174, 1.9717, 1.7246, 1.3779, 1.1826, 1.1216, 1.2505, 1.4878, 1.8276, 2.1123,
                      2.2183, 1.9771, 1.5601, 1.2383, 1.0234, 1.0112, 1.0825, 1.3496, 1.7002, 2.0176,
                      2.1431, 1.9321, 1.5508, 1.2051, 0.9756, 0.9482, 1.0479, 1.2749, 1.6982, 1.9985,
                      2.2485, 1.9531, 1.5991, 1.2241, 1.0117, 1.0200, 1.0659, 1.3247, 1.6733, 2.0239,
                      2.5244, 2.0229, 1.8003, 1.3960, 1.1641, 1.1060, 1.1938, 1.5127, 1.8154, 2.0898,
                      2.7651, 2.0166, 1.8071, 1.5142, 1.3071, 1.2813, 1.3438, 1.5967, 1.8335, 2.3462,
                      3.5527, 2.6328, 2.1421, 1.9995, 1.7139, 1.6851, 1.7642, 2.0400, 2.1001, 2.8999,
                      4.6719, 2.3604, 2.2236, 1.8765, 1.9326, 1.8423, 1.8340, 1.8389, 2.1563, 3.2129,
                      3.1353, 2.2559, 1.9863, 1.9785, 1.7104, 1.6567, 1.7241, 1.8267, 1.9741, 2.5015,
                      2.6592, 1.9473, 2.0181, 1.5942, 1.4263, 1.3599, 1.3809, 1.6270, 1.8262, 2.1328,
                      2.3950, 1.9961, 1.7979, 1.4102, 1.2085, 1.1196, 1.2246, 1.4375, 1.7207, 2.0332,
                      2.2515, 1.9297, 1.6367, 1.2349, 1.0498, 0.9946, 1.0566, 1.2729, 1.6304, 1.9106,
                      2.0322, 1.9243, 1.4941, 1.1880, 0.9946, 0.9316, 1.0205, 1.2290, 1.5825, 1.8638,
                      2.1563, 1.8086, 1.5229, 1.1592, 0.9849, 0.9526, 1.0391, 1.2461, 1.6304, 1.8843,
                      2.2534, 1.8975, 1.5864, 1.2769, 1.0752, 1.0308, 1.1230, 1.4282, 1.7056, 1.9761,
                      2.4307, 1.8672, 1.6631, 1.3970, 1.2007, 1.1621, 1.2866, 1.4531, 1.8110, 2.1475,
                      3.1724, 2.3467, 1.9463, 1.7388, 1.6216, 1.5508, 1.6548, 1.9634, 1.9307, 2.5391,
                    },
         		},
         		/* para 6 */
         		{
                   	0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
                   	1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
                    {
                      4.8101, 2.8667, 2.4185, 2.1270, 2.1987, 2.0503, 2.2524, 2.1694, 2.7827, 3.9258,
                      3.5142, 2.4727, 2.2173, 2.0415, 1.8530, 1.7949, 1.9238, 2.1338, 2.3081, 3.1064,
                      3.0137, 2.2925, 2.0684, 1.7012, 1.4634, 1.3916, 1.5308, 1.9146, 2.1738, 2.7368,
                      2.7500, 2.1958, 1.8994, 1.4336, 1.2095, 1.1636, 1.3057, 1.5957, 2.0874, 2.3848,
                      2.4722, 2.1733, 1.7368, 1.2773, 1.0547, 1.0024, 1.1191, 1.4321, 1.9136, 2.3716,
                      2.5107, 2.1548, 1.6499, 1.2407, 1.0093, 0.9102, 1.1094, 1.3354, 1.9131, 2.2778,
                      2.4980, 2.1543, 1.7427, 1.2725, 1.0430, 1.0181, 1.1157, 1.4263, 1.9131, 2.3164,
                      2.8989, 2.2437, 1.9087, 1.4536, 1.1772, 1.1309, 1.2593, 1.5635, 2.1294, 2.2539,
                      3.0732, 2.2808, 2.0078, 1.6299, 1.4082, 1.3105, 1.4839, 1.7856, 2.1182, 2.7646,
                      4.1816, 2.6348, 2.3789, 2.0288, 1.7813, 1.7207, 1.8975, 2.1348, 2.3770, 2.9814,
                      4.2319, 2.4761, 2.0469, 1.9282, 1.8955, 1.8413, 1.9497, 1.9209, 2.3496, 3.3369,
                      3.0503, 2.1597, 1.9038, 1.8408, 1.6807, 1.6689, 1.7124, 1.9077, 1.9824, 2.6978,
                      2.5083, 1.9355, 1.8472, 1.5796, 1.3843, 1.3374, 1.4272, 1.6997, 1.8730, 2.2920,
                      2.3286, 1.9287, 1.7051, 1.3633, 1.1860, 1.1162, 1.2637, 1.4888, 1.8237, 2.1099,
                      2.1680, 1.9150, 1.6006, 1.2295, 1.0151, 1.0229, 1.0693, 1.3462, 1.7109, 1.9902,
                      2.1929, 1.9180, 1.5591, 1.1953, 1.0049, 0.9370, 1.0435, 1.2944, 1.6763, 2.0718,
                      2.2495, 1.9141, 1.6177, 1.2119, 1.0122, 1.0078, 1.0723, 1.2920, 1.6860, 1.9751,
                      2.4863, 2.0059, 1.7456, 1.3975, 1.1343, 1.0923, 1.2031, 1.4922, 1.8267, 2.0952,
                      2.7651, 2.0117, 1.8335, 1.5288, 1.3413, 1.2432, 1.3667, 1.5781, 1.8545, 2.3228,
                      3.6450, 2.4868, 2.0684, 1.9355, 1.6450, 1.6499, 1.7817, 1.9668, 2.0610, 2.7910,
                      4.5991, 2.4058, 2.1514, 1.9414, 1.8223, 1.8438, 1.8359, 1.8403, 2.2686, 2.9878,
                      2.9946, 2.2744, 2.0337, 1.9849, 1.7827, 1.6895, 1.7290, 1.8184, 1.9355, 2.5923,
                      2.5518, 1.9990, 1.9297, 1.6577, 1.4248, 1.3604, 1.4160, 1.6738, 1.8164, 2.1621,
                      2.3354, 1.9873, 1.7896, 1.4463, 1.2178, 1.1577, 1.2163, 1.4404, 1.7349, 1.9507,
                      2.1738, 1.9116, 1.6528, 1.2622, 1.0591, 1.0000, 1.0757, 1.2632, 1.6519, 1.8779,
                      2.0640, 1.8853, 1.5151, 1.2021, 0.9976, 0.9385, 1.0303, 1.2559, 1.5889, 1.9546,
                      2.1265, 1.8071, 1.5200, 1.1646, 0.9751, 0.9497, 1.0278, 1.2344, 1.6079, 1.8481,
                      2.3726, 1.8281, 1.6558, 1.2729, 1.0806, 1.0264, 1.1558, 1.3926, 1.7739, 1.8979,
                      2.5400, 1.8535, 1.6392, 1.4160, 1.2153, 1.1870, 1.2505, 1.5176, 1.7280, 2.2124,
                      3.1733, 2.2769, 1.8940, 1.7461, 1.5630, 1.5342, 1.7056, 1.8452, 1.9863, 2.4102,
                    },
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
      1, //enable
      1, /*interpolation enable*/
      2, //ae count
      4, /* awb count */
      0, //trigger mode : 0 gain trigger 1 lux trigger

      /* aec trigger */
      {
            /*trigger 0*/
        	{
        		1,
        		13.5,
        	},
            /*trigger 1*/
        	{
				800,
				1000,
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
      {    //trigger 0 H
        	/*trigger 0*/
        	{
        		2500,
        		3200,
        	},
        	/*trigger 1*/
        	{
        		3800,
        		4200,
        	},
        	/*trigger 2*/
        	{
        		4500,
        		5500,
        	},
        	/*trigger 3*/
        	{
        		6000,
        		7000,
        	},
        	/*trigger 4*/
        	{
				7200,
				8000,
        	},
        	/*trigger 5*/
        	{
        	},
        	/*trigger 6*/
        	{
        	},
       },
       /*isp_sub_module_ccm1_pra pra[5][7] */
       {
            //ae region 0
            {
				/* ccm a matrix */
                {
                     1.6774, -0.3716, -0.3058,
                     -0.3426, 1.0000, 0.3426,
                     -0.0834, -2.2700, 3.3534,
                },
                /* ccm tl84 matrix */
                {
                     1.9358, -0.7110, -0.2248,
                     -0.3662, 1.4872, -0.1210,
                     0.0502, -1.3406, 2.2904,
                },
                /* ccm d50 matrix */
                {
                     1.8010, -0.6080, -0.1930,
                     -0.3344, 1.6286, -0.2942,
                     0.0226, -1.0722, 2.0496,
                },
                /* ccm d65 matrix */
                {
                     2.0216, -0.8084, -0.2132,
                     -0.1810, 1.4638, -0.2828,
                     0.0908, -1.2068, 2.1160,
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
            //ae region 1
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
            //ae region 2
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
            //ae region 3
            {
                /* ccm a matrix 0409 */
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
                //awb region 4
                {
                },
                //awb region 5
                {
                },
                //awb region 6
                {
                },
            },
            //ae region 4
            {
                //awb region 0
                {
                },
                //awb region 1
                {
                },
                //awb region 2
                {
                },
                //awb region 3
                {
                },
                //awb region 4
                {
                },
                //awb region 5
                {
                },
                //awb region 6
                {
                },
            },

       },

    },
    /*isp_sub_module_ccm1_tuning_t isp_sub_module_ccm2_tuning;*/
    {
      0, //enable
    },
    /*isp_sub_module_gtm1_lut_tuning_t isp_sub_module_gtm1_lut_tuning;*/
    {
    },
    /*isp_sub_module_gamma_lut_tuning_t isp_sub_module_gamma_lut_tuning;*/
    {
       /*enable*/
       1,
       /*interpolation enable*/
       1,
       /*count_ae*/
       1,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==3 */
       {
          /*aec trigger 1*/
          {
            1.000,
            1000.000, //50
          },
          /*aec trigger 2*/
          {
            51.000,
            100.000,
          },
          /*aec trigger 3*/
          {
            100.000,
            400.000,
          },
       },
       513,//gamma lut count
       /*isp_sub_module_gamma_lut_pra pra[MIN_TRIGGER_COUNT]; MIN_TRIGGER_COUNT=3*/
       {
          /* outdoor */
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
          /* normal */
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
          /* indoor */
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
    /*isp_sub_module_cm_tuning_t isp_sub_module_cm_tuning;*/
    {
      0, //enable
      1, /*interpolation enable*/
      1, //ae count
      4, /* awb count */
      1, //trigger mode : 0 gain trigger 1 lux trigger
      /* aec trigger */
      {
        //trigger 0
      	{
      		0,
      		324,
      	},
        //trigger 1
      	{
      	},
      	 //trigger 2
      	{
      	},
      	 //trigger 3
      	{
      	},
      	 //trigger 4
      	{
      	},
      },
      /* awb trigger */
      {
        //trigger 0
      	{
      		2500,
      		3200,
      	},
      	//trigger 1
      	{
            3800,
      		4500,
      	},
      	//trigger 2
      	{
            4500,
      		5500,
      	},
      	//trigger 3
      	{
            6000,
      		7000,
      	},
      	//trigger 4
      	{
			7200,
			8000,
      	},
      	//trigger 5
      	{
      	},
      	//trigger 6
      	{
      	},
      },
        /*isp_sub_module_cm_pra pra[MIDDLE_TRIGGER_COUNT=5][MIDDLE_TRIGGER_COUNT=7];*/
      {
            //aetrigger 0
            {
                //awb trigger 0
                {
                    1.0,
                    0.000000,
                },
                //awb trigger 1
                {
                    1.0,
                    0.000000,
                },
                //awb trigger 2
                {
                    1.0,
                    0.000000,
                },
                //awb trigger 3
                {
                    1.0,
                    0.000000,
                },
                //awb trigger 4
                {
                },
                //awb trigger 5
                {
                },
                //awb trigger 6
                {
                },
            },
            //aetrigger 1
            {
                //awb trigger 0
                {
                },
                //awb trigger 1
                {
                },
                //awb trigger 2
                {
                },
                //awb trigger 3
                {
                },
                //awb trigger 4
                {
                },
                //awb trigger 5
                {
                },
                //awb trigger 6
                {
                },
            },
            //aetrigger 2
            {
                //awb trigger 0
                {
                },
                //awb trigger 1
                {
                },
                //awb trigger 2
                {
                },
                //awb trigger 3
                {
                },
                //awb trigger 4
                {
                },
                //awb trigger 5
                {
                },
                //awb trigger 6
                {
                },
            },
            //aetrigger 3
            {
                //awb trigger 0
                {
                },
                //awb trigger 1
                {
                },
                //awb trigger 2
                {
                },
                //awb trigger 3
                {
                },
                //awb trigger 4
                {
                },
                //awb trigger 5
                {
                },
                //awb trigger 6
                {
                },
            },
            //aetrigger 4
            {
                //awb trigger 0
                {
                },
                //awb trigger 1
                {
                },
                //awb trigger 2
                {
                },
                //awb trigger 3
                {
                },
                //awb trigger 4
                {
                },
                //awb trigger 5
                {
                },
                //awb trigger 6
                {
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
       11,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       0,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            1.500,
          },
          /* aec trigger 2 */
          {
            2.000,
            3.000,
          },
          /* aec trigger 3 */
          {
            4.000,
            6.000,
          },
          /* aec trigger 4 */
          {
            7.000,
            10.000,
          },
          /* aec trigger 5 */
          {
            14.000,
            17.000,
          },
          /* aec trigger 6 */
          {
            31.000,
            36.000,
          },
          /* aec trigger 7 */
          {
            60.000,
            70.000,
          },
          /* aec trigger 8 */
          {
            128.000,
            137.000,
          },
          /* aec trigger 9 */
          {
            220.000,
            260.000,
          },
          /* aec trigger 10 */
          {
            517.000,
            533.000,
          },
          /* aec trigger 11 */
          {
            855.000,
            1000.000,
          },
       },
       /*isp_sub_module_lee_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               96,  //sharpen_pos
               96,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               180, //limit_max
               180, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               90,  //sharpen_pos
               90,  //sharpen_fu
               6,  //noise_th
               0,  //order_en
               180, //limit_max
               180, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               86,  //sharpen_pos
               86,  //sharpen_fu
               6,  //noise_th
               0,  //order_en
               180, //limit_max
               180, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               76,  //sharpen_pos
               80,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               76,  //sharpen_pos
               67,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               70,  //sharpen_pos
               60,  //sharpen_fu
               8,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   112,114,112,//gaussian(1,1:3)
                   114,115,114,//gaussian(2,1:3)
                   112,114,112,//gaussian(3,1:3)
               },
               48,  //sharpen_pos
               65,  //sharpen_fu
               9,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 8 */
           {
               {
                   113,114,113,//gaussian(1,1:3)
                   114,114,114,//gaussian(2,1:3)
                   113,114,113,//gaussian(3,1:3)
               },
               48,  //sharpen_pos
               50,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 9 */
           {
               {
                   113,114,113,//gaussian(1,1:3)
                   114,114,114,//gaussian(2,1:3)
                   113,114,113,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               45,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 10 */
           {
               {
                   113,114,113,//gaussian(1,1:3)
                   114,114,114,//gaussian(2,1:3)
                   113,114,113,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               45,  //sharpen_fu
               12,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 11 */
           {
               {
                   113,114,113,//gaussian(1,1:3)
                   114,114,114,//gaussian(2,1:3)
                   113,114,113,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               40,  //sharpen_fu
               13,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 300, 600, //edge_th 0 ~3
               8, 100, 600, 1000, //luma_th 0 ~3
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
       11,
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
            2.000,
            3.500,
          },
          /*aec trigger 3 */
          {
            4.000,
            6.000,
          },
          /*aec trigger 4 */
          {
            7.000,
            10.000,
          },
          /*aec trigger 5 */
          {
            14.000,
            17.000,
          },
          /*aec trigger 6 */
          {
            31.000,
            36.000,
          },
          /*aec trigger 7 */
          {
            60.000,
            70.000,
          },
          /*aec trigger 8 */
          {
            128.000,
            137.000,
          },
          /*aec trigger 9 */
          {
            220.000,
            260.000,
          },
          /*aec trigger 10 */
          {
            517.000,
            533.000,
          },
          /*aec trigger 11 */
          {
            855.000,
            1000.000,
          },
       },
       /* isp_sub_module_cnf_pra pra[MIDDLE_TRIGGER_COUNT] */
       {
          /* para 1 */
          {
             1,  //enable
             2,  //zoom_par
             1,  //dn_level
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
             1,  //dn_level
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
             1,  //dn_level
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
             2,  //zoom_par
             1,  //dn_level
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
          /* para 8 */
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
          /* para 9 */
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
          /* para 10 */
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
          /* para 11 */
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
       },
    },

	    /* isp_sub_module_3d_2d_nr_tuning_t isp_sub_module_3d_2d_nr_tuning */
    {
       1, //enable
       1, //interpolation enable
       11, //ae count
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
            2.000,
            3.500,
          },
          /* aec trigger 3 */
          {
            4.000,
            6.000,
          },
          /* aec trigger 4 */
          {
            7.000,
            10.000,
          },
          /* aec trigger 5 */
          {
            14.000,
            17.000,
          },
          /* aec trigger 6 */
          {
            31.000,
            36.000,
          },
          /* aec trigger 7 */
          {
            60.000,
            70.000,
          },
          /* aec trigger 8 */
          {
            128.000,
            137.000,
          },
          /* aec trigger 9 */
          {
            220.000,
            260.000,
          },
          /* aec trigger 10 */
          {
            517.000,
            533.000,
          },
          /* aec trigger 11 */
          {
            855.000,
            1000.000,
          },
       },
       /*isp_sub_module_3d_2d_nr_pra pra[MIDDLE_TRIGGER_COUNT=5]*/
       {
           /* parameter 1 */
           {
               //weight_cur_lut[32]
               {
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
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
                   49,40,34,30,27,24,22,20,18,17,15,14,13,12,11,10,9,8,7,6,6,5,4,4,3,3,2,1,1,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   49,40,34,30,27,24,22,20,18,17,15,14,13,12,11,10,9,8,7,6,6,5,4,4,3,3,2,1,1,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   32,26,23,20,18,16,14,13,12,11,10,9,8,8,7,6,6,5,5,4,4,3,3,2,2,2,1,1,0,0,0,0,
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
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
               },
               //weight_pre_lut[32]
               {
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
               },
               //weight_big_block_lut[32]
               {
                   32,26,23,20,18,16,14,13,12,11,10,9,8,8,7,6,6,5,5,4,4,3,3,2,2,2,1,1,0,0,0,0,
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
                   82,66,57,50,45,41,37,34,31,28,26,24,22,20,18,17,15,14,12,11,10,9,8,6,5,5,4,3,2,1,0,0,
               },
               //weight_pre_lut[32]
               {
                   82,66,57,50,45,41,37,34,31,28,26,24,22,20,18,17,15,14,12,11,10,9,8,6,5,5,4,3,2,1,0,0,
               },
               //weight_big_block_lut[32]
               {
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
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
                   164,133,115,101,90,82,74,68,62,57,52,48,44,40,37,34,31,28,25,23,20,18,16,13,11,10,8,6,4,2,1,0,
               },
               //weight_pre_lut[32]
               {
                   164,133,115,101,90,82,74,68,62,57,52,48,44,40,37,34,31,28,25,23,20,18,16,13,11,10,8,6,4,2,1,0,
               },
               //weight_big_block_lut[32]
               {
                   164,133,115,101,90,82,74,68,62,57,52,48,44,40,37,34,31,28,25,23,20,18,16,13,11,10,8,6,4,2,1,0,
               },
               0, //big_5x5_revised_enable
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
                   223,182,156,138,123,111,101,92,84,77,71,65,60,55,50,46,42,38,34,31,28,24,21,19,16,13,11,8,6,3,1,0,
               },
               //weight_pre_lut[32]
               {
                   311,254,218,192,172,155,141,129,118,108,99,91,84,77,70,64,58,53,48,43,39,34,30,26,22,19,15,12,8,5,2,0,
               },
               //weight_big_block_lut[32]
               {
                   262,214,184,162,145,131,119,108,99,91,83,77,70,65,59,54,49,45,40,36,32,29,25,22,19,16,13,10,7,4,2,0,
               },
               0, //big_5x5_revised_enable
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
           /* parameter 11 */
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
                   820,669,575,507,454,410,372,340,311,285,262,241,221,203,186,170,155,141,127,115,102,91,80,69,59,50,40,31,22,14,6,0,
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
    /* ae torlerence */
    2,
    /* ae exp_table_para */
    {
        /* count */
        417,
        /* ev0_count */
        417,
        /* ev2_count */
        417,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        256,
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
          {257,  1286  },        /* Gain= 1.003906 Exposure Index= 231 */
          {265,  1286  },        /* Gain= 1.035156 Exposure Index= 232 */
          {273,  1286  },        /* Gain= 1.066406 Exposure Index= 233 */
          {282,  1286  },        /* Gain= 1.101563 Exposure Index= 234 */
          {291,  1286  },        /* Gain= 1.136719 Exposure Index= 235 */
          {300,  1286  },        /* Gain= 1.171875 Exposure Index= 236 */
          {309,  1286  },        /* Gain= 1.207031 Exposure Index= 237 */
          {319,  1286  },        /* Gain= 1.246094 Exposure Index= 238 */
          {329,  1286  },        /* Gain= 1.285156 Exposure Index= 239 */
          {339,  1286  },        /* Gain= 1.324219 Exposure Index= 240 */
          {350,  1286  },        /* Gain= 1.367188 Exposure Index= 241 */
          {361,  1286  },        /* Gain= 1.410156 Exposure Index= 242 */
          {372,  1286  },        /* Gain= 1.453125 Exposure Index= 243 */
          {384,  1286  },        /* Gain= 1.500000 Exposure Index= 244 */
          {396,  1286  },        /* Gain= 1.546875 Exposure Index= 245 */
          {408,  1286  },        /* Gain= 1.593750 Exposure Index= 246 */
          {421,  1286  },        /* Gain= 1.644531 Exposure Index= 247 */
          {434,  1286  },        /* Gain= 1.695313 Exposure Index= 248 */
          {448,  1286  },        /* Gain= 1.750000 Exposure Index= 249 */
          {462,  1286  },        /* Gain= 1.804688 Exposure Index= 250 */
          {476,  1286  },        /* Gain= 1.859375 Exposure Index= 251 */
          {491,  1286  },        /* Gain= 1.917969 Exposure Index= 252 */
          {506,  1286  },        /* Gain= 1.976563 Exposure Index= 253 */
          {522,  1286  },        /* Gain= 2.039063 Exposure Index= 254 */
          {538,  1286  },        /* Gain= 2.101563 Exposure Index= 255 */
          {555,  1286  },        /* Gain= 2.167969 Exposure Index= 256 */
          {572,  1286  },        /* Gain= 2.234375 Exposure Index= 257 */
          {590,  1286  },        /* Gain= 2.304688 Exposure Index= 258 */
          {608,  1286  },        /* Gain= 2.375000 Exposure Index= 259 */
          {627,  1286  },        /* Gain= 2.449219 Exposure Index= 260 */
          {646,  1286  },        /* Gain= 2.523438 Exposure Index= 261 */
          {666,  1286  },        /* Gain= 2.601563 Exposure Index= 262 */
          {686,  1286  },        /* Gain= 2.679688 Exposure Index= 263 */
          {707,  1286  },        /* Gain= 2.761719 Exposure Index= 264 */
          {729,  1286  },        /* Gain= 2.847656 Exposure Index= 265 */
          {751,  1286  },        /* Gain= 2.933594 Exposure Index= 266 */
          {774,  1286  },        /* Gain= 3.023438 Exposure Index= 267 */
          {798,  1286  },        /* Gain= 3.117188 Exposure Index= 268 */
          {822,  1286  },        /* Gain= 3.210938 Exposure Index= 269 */
          {847,  1286  },        /* Gain= 3.308594 Exposure Index= 270 */
          {873,  1286  },        /* Gain= 3.410156 Exposure Index= 271 */
          {900,  1286  },        /* Gain= 3.515625 Exposure Index= 272 */
          {927,  1286  },        /* Gain= 3.621094 Exposure Index= 273 */
          {955,  1286  },        /* Gain= 3.730469 Exposure Index= 274 */
          {984,  1286  },        /* Gain= 3.843750 Exposure Index= 275 */
          {1014,  1286  },        /* Gain= 3.960938 Exposure Index= 276 */
          {1045,  1286  },        /* Gain= 4.082031 Exposure Index= 277 */
          {1077,  1286  },        /* Gain= 4.207031 Exposure Index= 278 */
          {1110,  1286  },        /* Gain= 4.335938 Exposure Index= 279 */
          {1144,  1286  },        /* Gain= 4.468750 Exposure Index= 280 */
          {1179,  1286  },        /* Gain= 4.605469 Exposure Index= 281 */
          {1215,  1286  },        /* Gain= 4.746094 Exposure Index= 282 */
          {1252,  1286  },        /* Gain= 4.890625 Exposure Index= 283 */
          {1290,  1286  },        /* Gain= 5.039063 Exposure Index= 284 */
          {1329,  1286  },        /* Gain= 5.191406 Exposure Index= 285 */
          {1369,  1286  },        /* Gain= 5.347656 Exposure Index= 286 */
          {1411,  1286  },        /* Gain= 5.511719 Exposure Index= 287 */
          {1454,  1286  },        /* Gain= 5.679688 Exposure Index= 288 */
          {1498,  1286  },        /* Gain= 5.851563 Exposure Index= 289 */
          {1543,  1286  },        /* Gain= 6.027344 Exposure Index= 290 */
          {1590,  1286  },        /* Gain= 6.210938 Exposure Index= 291 */
          {1638,  1286  },        /* Gain= 6.398438 Exposure Index= 292 */
          {1688,  1286  },        /* Gain= 6.593750 Exposure Index= 293 */
          {1739,  1286  },        /* Gain= 6.792969 Exposure Index= 294 */
          {1792,  1286  },        /* Gain= 7.000000 Exposure Index= 295 */
          {1846,  1286  },        /* Gain= 7.210938 Exposure Index= 296 */
          {1902,  1286  },        /* Gain= 7.429688 Exposure Index= 297 */
          {1960,  1286  },        /* Gain= 7.656250 Exposure Index= 298 */
          {2019,  1286  },        /* Gain= 7.886719 Exposure Index= 299 */
          {2080,  1286  },        /* Gain= 8.125000 Exposure Index= 300 */
          {2143,  1286  },        /* Gain= 8.371094 Exposure Index= 301 */
          {2208,  1286  },        /* Gain= 8.625000 Exposure Index= 302 */
          {2275,  1286  },        /* Gain= 8.886719 Exposure Index= 303 */
          {2344,  1286  },        /* Gain= 9.156250 Exposure Index= 304 */
          {2415,  1286  },        /* Gain= 9.433594 Exposure Index= 305 */
          {2488,  1286  },        /* Gain= 9.718750 Exposure Index= 306 */
          {2563,  1286  },        /* Gain= 10.011719 Exposure Index= 307 */
          {2640,  1286  },        /* Gain= 10.312500 Exposure Index= 308 */
          {2720,  1286  },        /* Gain= 10.625000 Exposure Index= 309 */
          {2802,  1286  },        /* Gain= 10.945313 Exposure Index= 310 */
          {2887,  1286  },        /* Gain= 11.277344 Exposure Index= 311 */
          {2974,  1286  },        /* Gain= 11.617188 Exposure Index= 312 */
          {3064,  1286  },        /* Gain= 11.968750 Exposure Index= 313 */
          {3156,  1286  },        /* Gain= 12.328125 Exposure Index= 314 */
          {3251,  1286  },        /* Gain= 12.699219 Exposure Index= 315 */
          {3349,  1286  },        /* Gain= 13.082031 Exposure Index= 316 */
          {3450,  1286  },        /* Gain= 13.476563 Exposure Index= 317 */
          {3554,  1286  },        /* Gain= 13.882813 Exposure Index= 318 */
          {3661,  1286  },        /* Gain= 14.300781 Exposure Index= 319 */
          {3771,  1286  },        /* Gain= 14.730469 Exposure Index= 320 */
          {3885,  1286  },        /* Gain= 15.175781 Exposure Index= 321 */
          {4002,  1286  },        /* Gain= 15.632813 Exposure Index= 322 */
          {4123,  1286  },        /* Gain= 16.105469 Exposure Index= 323 */
          {4247,  1286  },        /* Gain= 16.589844 Exposure Index= 324 */
          {4375,  1286  },        /* Gain= 17.089844 Exposure Index= 325 */
          {4507,  1286  },        /* Gain= 17.605469 Exposure Index= 326 */
          {4643,  1286  },        /* Gain= 18.136719 Exposure Index= 327 */
          {4783,  1286  },        /* Gain= 18.683594 Exposure Index= 328 */
          {4927,  1286  },        /* Gain= 19.246094 Exposure Index= 329 */
          {5075,  1286  },        /* Gain= 19.824219 Exposure Index= 330 */
          {5228,  1286  },        /* Gain= 20.421875 Exposure Index= 331 */
          {5385,  1286  },        /* Gain= 21.035156 Exposure Index= 332 */
          {5547,  1286  },        /* Gain= 21.667969 Exposure Index= 333 */
          {5714,  1286  },        /* Gain= 22.320313 Exposure Index= 334 */
          {5886,  1286  },        /* Gain= 22.992188 Exposure Index= 335 */
          {6063,  1286  },        /* Gain= 23.683594 Exposure Index= 336 */
          {6245,  1286  },        /* Gain= 24.394531 Exposure Index= 337 */
          {6433,  1286  },        /* Gain= 25.128906 Exposure Index= 338 */
          {6626,  1286  },        /* Gain= 25.882813 Exposure Index= 339 */
          {6825,  1286  },        /* Gain= 26.660156 Exposure Index= 340 */
          {7030,  1286  },        /* Gain= 27.460938 Exposure Index= 341 */
          {7241,  1286  },        /* Gain= 28.285156 Exposure Index= 342 */
          {7459,  1286  },        /* Gain= 29.136719 Exposure Index= 343 */
          {7683,  1286  },        /* Gain= 30.011719 Exposure Index= 344 */
          {7914,  1286  },        /* Gain= 30.914063 Exposure Index= 345 */
          {8152,  1286  },        /* Gain= 31.843750 Exposure Index= 346 */
          {8397,  1286  },        /* Gain= 32.800781 Exposure Index= 347 */
          {8649,  1286  },        /* Gain= 33.785156 Exposure Index= 348 */
          {8909,  1286  },        /* Gain= 34.800781 Exposure Index= 349 */
          {9177,  1286  },        /* Gain= 35.847656 Exposure Index= 350 */
          {9453,  1286  },        /* Gain= 36.925781 Exposure Index= 351 */
          {9737,  1286  },        /* Gain= 38.035156 Exposure Index= 352 */
          {10030,  1286  },        /* Gain= 39.179688 Exposure Index= 353 */
          {10331,  1286  },        /* Gain= 40.355469 Exposure Index= 354 */
          {10641,  1286  },        /* Gain= 41.566406 Exposure Index= 355 */
          {10961,  1286  },        /* Gain= 42.816406 Exposure Index= 356 */
          {11290,  1286  },        /* Gain= 44.101563 Exposure Index= 357 */
          {11629,  1286  },        /* Gain= 45.425781 Exposure Index= 358 */
          {11978,  1286  },        /* Gain= 46.789063 Exposure Index= 359 */
          {12338,  1286  },        /* Gain= 48.195313 Exposure Index= 360 */
          {12709,  1286  },        /* Gain= 49.644531 Exposure Index= 361 */
          {13091,  1286  },        /* Gain= 51.136719 Exposure Index= 362 */
          {13484,  1286  },        /* Gain= 52.671875 Exposure Index= 363 */
          {13889,  1286  },        /* Gain= 54.253906 Exposure Index= 364 */
          {14306,  1286  },        /* Gain= 55.882813 Exposure Index= 365 */
          {14736,  1286  },        /* Gain= 57.562500 Exposure Index= 366 */
          {15179,  1286  },        /* Gain= 59.292969 Exposure Index= 367 */
          {15635,  1286  },        /* Gain= 61.074219 Exposure Index= 368 */
          {16105,  1286  },        /* Gain= 62.910156 Exposure Index= 369 */
          {16589,  1286  },        /* Gain= 64.800781 Exposure Index= 370 */
          {17087,  1286  },        /* Gain= 66.746094 Exposure Index= 371 */
          {17600,  1286  },        /* Gain= 68.750000 Exposure Index= 372 */
          {18128,  1286  },        /* Gain= 70.812500 Exposure Index= 373 */
          {18672,  1286  },        /* Gain= 72.937500 Exposure Index= 374 */
          {19233,  1286  },        /* Gain= 75.128906 Exposure Index= 375 */
          {19810,  1286  },        /* Gain= 77.382813 Exposure Index= 376 */
          {20405,  1286  },        /* Gain= 79.707031 Exposure Index= 377 */
          {21018,  1286  },        /* Gain= 82.101563 Exposure Index= 378 */
          {21649,  1286  },        /* Gain= 84.566406 Exposure Index= 379 */
          {22299,  1286  },        /* Gain= 87.105469 Exposure Index= 380 */
          {22968,  1286  },        /* Gain= 89.718750 Exposure Index= 381 */
          {23658,  1286  },        /* Gain= 92.414063 Exposure Index= 382 */
          {24368,  1286  },        /* Gain= 95.187500 Exposure Index= 383 */
          {25100,  1286  },        /* Gain= 98.046875 Exposure Index= 384 */
          {25853,  1286  },        /* Gain= 100.988281 Exposure Index= 385 */
          {26629,  1286  },        /* Gain= 104.019531 Exposure Index= 386 */
          {27428,  1286  },        /* Gain= 107.140625 Exposure Index= 387 */
          {28251,  1286  },        /* Gain= 110.355469 Exposure Index= 388 */
          {29099,  1286  },        /* Gain= 113.667969 Exposure Index= 389 */
          {29972,  1286  },        /* Gain= 117.078125 Exposure Index= 390 */
          {30872,  1286  },        /* Gain= 120.593750 Exposure Index= 391 */
          {31799,  1286  },        /* Gain= 124.214844 Exposure Index= 392 */
          {32753,  1286  },        /* Gain= 127.941406 Exposure Index= 393 */
          {33736,  1286  },        /* Gain= 131.781250 Exposure Index= 394 */
          {34749,  1286  },        /* Gain= 135.738281 Exposure Index= 395 */
          {35792,  1286  },        /* Gain= 139.812500 Exposure Index= 396 */
          {36866,  1286  },        /* Gain= 144.007813 Exposure Index= 397 */
          {37972,  1286  },        /* Gain= 148.328125 Exposure Index= 398 */
          {39112,  1286  },        /* Gain= 152.781250 Exposure Index= 399 */
          {40286,  1286  },        /* Gain= 157.367188 Exposure Index= 400 */
          {41495,  1286  },        /* Gain= 162.089844 Exposure Index= 401 */
          {42740,  1286  },        /* Gain= 166.953125 Exposure Index= 402 */
          {44023,  1286  },        /* Gain= 171.964844 Exposure Index= 403 */
          {45344,  1286  },        /* Gain= 177.125000 Exposure Index= 404 */
          {46705,  1286  },        /* Gain= 182.441406 Exposure Index= 405 */
          {48107,  1286  },        /* Gain= 187.917969 Exposure Index= 406 */
          {49551,  1286  },        /* Gain= 193.558594 Exposure Index= 407 */
          {51038,  1286  },        /* Gain= 199.367188 Exposure Index= 408 */
          {52570,  1286  },        /* Gain= 205.351563 Exposure Index= 409 */
          {54148,  1286  },        /* Gain= 211.515625 Exposure Index= 410 */
          {55773,  1286  },        /* Gain= 217.863281 Exposure Index= 411 */
          {57447,  1286  },        /* Gain= 224.402344 Exposure Index= 412 */
          {59171,  1286  },        /* Gain= 231.136719 Exposure Index= 413 */
          {60947,  1286  },        /* Gain= 238.074219 Exposure Index= 414 */
          {62776,  1286  },        /* Gain= 245.218750 Exposure Index= 415 */
          {64660,  1286  },        /* Gain= 252.578125 Exposure Index= 416 */
        },
    },
    /* ae_tuning_para para */
    {
        1,  /* aec_stats_type,0:BAYER_AEC,1:HYBRID_AEC */
        1,  /* force_exp_forced */
        0.100000,  /* force_exp_value */
        1,  /* preview_isp_enable */
        {
            37,  /* outdoor_luma_target_compensated */
            31,  /* default_luma_target_compensated */
            10,/* low_light.luma_target */
            210,  /* outdoor_index */
            290,  /* indoor_index */
            320,/* low_light.start_idx */
            340,/* low_light.end_idx */
        },
        5,  /* snow_scene_detect.extreme_luma_target_offset */
        5,  /* backlight_scene_detect.backlight_max_la_luma_target_offset */
        1,  /* ace_motion_iso_preview */
        512,  /* R_WEIGHT */
        1024,  /* G_WEIGHT */
        512,  /* B_WEIGHT */
        11,  /* WT_Q */
        {
            25,/* fast_conv.speed */
            2,/* fast_conv.luma_tolerance */
            0,/* fast_conv.frame_skip */
        },
        1,  /* metering_type 0:SPOT_METERING,1:CENTER_WEIGHTED,2:SIMPLE_FRAME_AVERAGE */
        0,  /* full_sweep_en */
        77.894000,  /* exposure_index_adj_step,NEED 1/log10(1.03) */
        1,  /* 0:no antibanding;1:50hz ;2:60hz */
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
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
              1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
        },/* 36x16 bias table for luma metering:0-100 */
        {
            0,  /* hist_target_adjust_enable */
            1.200000,  /* outdoor_max_target_adjust_ratio */
            0.800000,  /* outdoor_min_target_adjust_ratio */
            1.200000,  /* indoor_max_target_adjust_ratio */
            0.800000,  /* indoor_min_target_adjust_ratio */
            1.200000,  /* lowlight_max_target_adjust_ratio */
            0.800000,  /* lowlight_min_target_adjust_ratio */
            0.500000,  /* target_filter_factor */
            0.150000,  /* hist_sat_pct */
            0.150000,  /* hist_dark_pct */
            150.000000,  /* hist_sat_low_ref */
            200.000000,  /* hist_sat_high_ref */
            3.000000,  /* hist_dark_low_ref */
            20.000000,  /* hist_dark_high_ref */
        },
        {
            0,  /* over_exp_enable */
            240,  /* high_luma_region_threshold */
            1.000000,  /* outdoor_over_exp_adjust_ratio */
            0.900000,  /* indoor_over_exp_adjust_ratio */
            0.800000,  /* lowlight_over_exp_adjust_ratio */
            15.000000,  /* outdoor_over_exp_adjust_offset */
            5.000000,  /* indoor_over_exp_adjust_offset */
            5.000000,  /* lowlight_over_exp_adjust_offset */
            30,  /* outdoor_over_exp_max_count */
            50,  /* indoor_over_exp_max_count */
            60,  /* lowlight_over_exp_max_count */
            5,  /* outdoor_over_exp_min_count */
            5,  /* indoor_over_exp_min_count */
            5,  /* lowlight_over_exp_min_count */
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
            424,
        },
        {
            0,
            424
        },
        {
            0,
            424,
        },
	},
    /* awb_point */
    {
    	{ 0.7904, 0.9104 },    /* d75 */
        { 0.8385, 0.8283 },    /* d65 */
        { 0.9215, 0.7307 },    /* d50 */
        { 0.9215, 0.7307 },    /* noon */
        { 0.8386, 0.5367 },    /* cw */
        { 0.9556, 0.5471 },    /* tl84 */
        { 1.2691, 0.5335 },    /* a */
        { 1.4152, 0.5144 },    /* h */
        {  },    /* custom1 */
        {  },    /* custom2 */
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
    	7500, /* d75 */
    	6500, /* d65 */
    	5001, /* d50 */
    	5001, /* noon */
    	4048, /* cw */
    	3936, /* tl84 */
    	2864, /* a */
    	2306, /* h */
    	6250,  /* custom1 */
    	3500, /* custom_a */
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
    	9,     /* custom_a */
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
		{ 0, 2,10, 1},	/* d75 */
		{ 2, 8,10, 6},	/* d65 */
		{10,10,10, 6},  /* d50 */
		{10,10, 5, 5},	/* noon */
		{ 0, 0, 1, 1},	/* cw */
		{ 0, 0, 1, 1},	/* tl84 */
		{ 0, 0, 1, 1},	/* a */
		{ 0, 0, 1, 1},	/* h */
		{ 0, 0,10,10},	/* custom_daylight */
		{ 0, 0, 1, 1},	/* custom_a */
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
    	60,     /* outdoor_midpoint */
    	120,    /* outdoor_index */
    	135,    /* inoutdoor_midpoint */
    	150,    /* indoor_index */
    	10,     /* exposure_adjustment */
        0.75,   /* awb_tuning_params */
		0.50,	/* d50_d65_weighted_samaple_boundary */
		0.20,	/* blue_sky_pec */
		0.15,	/* blue_sky_pec_buffer */
        9,     /* num_of_reference_point */
        0.0100, /* outline */
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
		0.20,	/* threshold_extreme_b_percent */
        0.0064, /* compact_to_grey_dis */
    	0.45,   /* cluster_high_pec */
    	0.25,   /* cluster_mid_pec */
    	0.15,   /* cluster_low_pec */
        10,     /* BitsSum */
        3,      /* FrameNum */
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
           0x00000034,	/* Y min  0.05*1024	*/
           0x00000010,
           0x00010100,
           0x00000100,
           0x000100c8,
           0x00000014,
           0x00010320,
           0x00010258,
           0x00000028,
           0x000000c7, /* Green_BGmax */
           0x00000068, /* Green_BGmin */
           0x000000bc, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000105, /* Green_Rmul */
           0x00000114, /* Green_Bmul */
           0x00000126,	/* extreme B, B/G */	//	D50 0.68
           0x00000500,	/* extreme B, R/G */
           0x000001a6,	/* extreme R, R/G */	//	TL84
           0x00001980,	/* extreme R, B/G */
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
