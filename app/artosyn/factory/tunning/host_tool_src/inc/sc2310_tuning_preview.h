/*---------------header of sc2310 tuing-------------------------*/

/* version of the tuning header uint32_t header_version*/
0x20190910,
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
       3,
       /*tigger_mode : 0 gain ,1 lux */
       0,
       {
          /*region 1 */
          {
            1.000,
            120.000, //120
          },
          /*region 2 */
          {
            150.000,
            480.000,
          },
         
          /*region 4 */
          {
            600.000,
            1000.000,
          },
          /*region 5 */
          {
            1001.000,
            1183.000,
          },
       },
       {
           /*parameter 1 */
           {         
               1028,
               1028,
               1027,
               1028,
               274,
               274,
               274,
               274,  
           },        
           /*parameter 2 */
           {                
               1009,
               989,
               1010,
               1013,
               273,
               273,
               273,
               273,         
           },               
           /*parameter 4 */
           {         
               934,
               829,
               939,
               953,
               272,
               270,
               272,
               272, 
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
	  		0,
			0,
			0,
			0,
			0,
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
            8.000,
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
                        {28,84,78},
                        //g channel
                        {28,84,78},
                        //b channel
                        {28,84,78},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {28,84,56},
                        //g channel
                        {28,84,56},
                        //b channel
                        {28,84,56},
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
                        {38,114,107},
                        //g channel
                        {38,114,107},
                        //b channel
                        {38,114,107},
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
            /* para 5 */
            {
                3,//denoise_layer
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
                        {60,180,122},
                        //g channel
                        {60,180,122},
                        //b channel
                        {60,180,122},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {55,165,112},
                        //g channel
                        {55,165,112},
                        //b channel
                        {55,165,112},
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
                        {100,300,287},
                        //g channel
                        {100,300,287},
                        //b channel
                        {100,300,287},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {100,300,205},
                        //g channel
                        {100,300,205},
                        //b channel
                        {100,300,205},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {92,276,188},
                        //g channel
                        {92,276,188},
                        //b channel
                        {92,276,188},
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
                        {120,360,345},
                        //g channel
                        {120,360,345},
                        //b channel
                        {120,360,345},
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
            /* para 8 */
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
                        {108,324,221},
                        //g channel
                        {108,324,221},
                        //b channel
                        {108,324,221},
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
                        {146,438,300},
                        //g channel
                        {146,438,300},
                        //b channel
                        {146,438,300},
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
                        {170,510,490},
                        //g channel
                        {170,510,490},
                        //b channel
                        {170,510,490},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {170,510,350},
                        //g channel
                        {170,510,350},
                        //b channel
                        {170,510,350},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {162,486,333},
                        //g channel
                        {162,486,333},
                        //b channel
                        {162,486,333},
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
     			2500,
     			3200,
     		},
			/*awb trigger 2*/
     		{
     			3300,
     			3600,
     		},
     		/*awb trigger 2*/
     		{
     			3800,
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
					  3.7856, 1.2715, 1.4185, 1.1089, 1.1152, 1.0869, 1.1133, 1.1763, 1.5298, 2.8398, 
					  2.0957, 1.3320, 1.2310, 1.1309, 1.0952, 1.0869, 1.1284, 1.2529, 1.3389, 2.6050, 
					  1.6401, 1.2358, 1.1270, 1.0659, 1.0366, 1.0342, 1.0718, 1.0889, 1.2651, 1.7905, 
					  1.4839, 1.2388, 1.0884, 1.0493, 1.0327, 1.0225, 1.0591, 1.1113, 1.2031, 1.7871, 
					  1.5649, 1.2100, 1.1074, 1.0522, 1.0225, 1.0220, 1.0552, 1.1167, 1.1890, 1.7402, 
					  1.5459, 1.1738, 1.0757, 1.0288, 0.9868, 0.9834, 1.0342, 1.0698, 1.1782, 1.6597, 
					  1.6313, 1.2324, 1.1216, 1.0688, 1.0361, 1.0342, 1.0601, 1.1206, 1.2114, 1.7988, 
					  1.7119, 1.2256, 1.1021, 1.0596, 1.0283, 1.0200, 1.0581, 1.1040, 1.2412, 1.8735, 
					  2.1133, 1.2988, 1.1733, 1.1021, 1.0557, 1.0537, 1.0840, 1.1660, 1.3286, 2.2915, 
					  3.0142, 1.4448, 1.3179, 1.1362, 1.1372, 1.0933, 1.1460, 1.1870, 1.5942, 2.6743, 
					  3.5376, 1.1865, 1.3110, 1.0610, 1.0527, 1.0552, 1.0654, 1.0654, 1.5029, 2.4312, 
					  2.0283, 1.2490, 1.1841, 1.0962, 1.0752, 1.0708, 1.0977, 1.1982, 1.2559, 2.5405, 
					  1.5171, 1.1606, 1.0645, 1.0391, 1.0083, 1.0171, 1.0435, 1.0327, 1.2026, 1.6650, 
					  1.3926, 1.1606, 1.0439, 1.0259, 1.0259, 1.0195, 1.0454, 1.0679, 1.1362, 1.6914, 
					  1.4492, 1.1416, 1.0605, 1.0444, 1.0161, 1.0220, 1.0400, 1.0625, 1.1323, 1.6128, 
					  1.4131, 1.1182, 1.0186, 1.0063, 0.9868, 0.9727, 1.0220, 1.0376, 1.0986, 1.5713, 
					  1.5503, 1.1445, 1.0752, 1.0518, 1.0215, 1.0332, 1.0356, 1.0713, 1.1436, 1.6689, 
					  1.6250, 1.1460, 1.0449, 1.0254, 1.0078, 0.9976, 1.0293, 1.0537, 1.1650, 1.7891, 
					  2.0693, 1.1997, 1.1196, 1.0527, 1.0317, 1.0278, 1.0479, 1.1030, 1.2510, 2.1411, 
					  3.1035, 1.3330, 1.2339, 1.0830, 1.0586, 1.0474, 1.0776, 1.1001, 1.5020, 2.5327, 
					  3.4863, 1.2061, 1.3047, 1.0640, 1.0840, 1.0537, 1.0483, 1.1226, 1.4424, 2.5132, 
					  2.0703, 1.2354, 1.1899, 1.0898, 1.0737, 1.0747, 1.1060, 1.2002, 1.2598, 2.5825, 
					  1.5059, 1.1641, 1.0459, 1.0430, 1.0142, 1.0239, 1.0439, 1.0396, 1.1807, 1.6929, 
					  1.4146, 1.1704, 1.0381, 1.0435, 1.0273, 1.0366, 1.0493, 1.0835, 1.1250, 1.7368, 
					  1.4658, 1.1211, 1.0708, 1.0430, 1.0200, 1.0259, 1.0547, 1.0659, 1.1260, 1.6431, 
					  1.4507, 1.1147, 1.0254, 1.0132, 1.0000, 0.9858, 1.0396, 1.0317, 1.1182, 1.5737, 
					  1.5386, 1.1333, 1.0771, 1.0435, 1.0249, 1.0381, 1.0371, 1.0840, 1.1226, 1.7520, 
					  1.6597, 1.1484, 1.0576, 1.0420, 1.0264, 1.0093, 1.0508, 1.0728, 1.1719, 1.8618, 
					  2.0410, 1.2031, 1.1182, 1.0537, 1.0332, 1.0264, 1.0503, 1.1235, 1.2476, 2.1084, 
					  3.1924, 1.3203, 1.3062, 1.0972, 1.0762, 1.1084, 1.1113, 1.0908, 1.5967, 2.3086, 
					},
				},
				/* para 2 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.2241, 1.5015, 1.2373, 1.1157, 1.1387, 1.1162, 1.1470, 1.8574, 1.0742, 7.2822, 
					  2.1636, 1.2813, 1.1318, 1.0840, 1.0498, 1.0493, 1.0918, 1.2207, 1.3047, 2.8877, 
					  1.7139, 1.1729, 1.0791, 1.0303, 1.0283, 1.0288, 1.0610, 1.0869, 1.2554, 2.1821, 
					  1.6392, 1.1841, 1.1006, 1.0615, 1.0552, 1.0474, 1.0840, 1.1025, 1.2524, 1.8877, 
					  1.5308, 1.0923, 1.0420, 0.9985, 0.9858, 0.9780, 1.0166, 1.0488, 1.1523, 1.7261, 
					  1.6284, 1.1445, 1.1006, 1.0527, 1.0181, 1.0234, 1.0566, 1.1045, 1.1938, 1.8511, 
					  1.5894, 1.1289, 1.0654, 1.0229, 1.0142, 1.0176, 1.0454, 1.0889, 1.1885, 1.9155, 
					  1.6963, 1.1431, 1.0786, 1.0342, 1.0244, 1.0190, 1.0610, 1.0864, 1.2446, 2.0288, 
					  1.5493, 1.3525, 1.0581, 1.1074, 1.0615, 1.0791, 1.1089, 1.1758, 1.3979, 2.5547, 
					  1.4985, 1.4365, 1.1284, 1.0483, 1.0806, 1.0483, 1.0933, 1.4038, 1.3799, 4.5449, 
					  3.1841, 1.4517, 1.2197, 1.0854, 1.1201, 1.1001, 1.1255, 1.7134, 1.1602, 6.6724, 
					  2.0928, 1.2651, 1.1099, 1.0684, 1.0503, 1.0454, 1.0806, 1.1841, 1.2983, 2.7715, 
					  1.7036, 1.1533, 1.0679, 1.0293, 1.0181, 1.0308, 1.0562, 1.0820, 1.2456, 2.1265, 
					  1.5645, 1.1509, 1.0747, 1.0381, 1.0430, 1.0454, 1.0659, 1.0913, 1.2153, 1.8242, 
					  1.4961, 1.0796, 1.0332, 0.9985, 0.9839, 0.9844, 1.0146, 1.0444, 1.1353, 1.7134, 
					  1.5391, 1.1235, 1.0688, 1.0327, 1.0059, 1.0288, 1.0483, 1.1011, 1.1714, 1.8145, 
					  1.5439, 1.1069, 1.0454, 1.0239, 1.0068, 1.0132, 1.0405, 1.0679, 1.1616, 1.8516, 
					  1.6675, 1.1294, 1.0488, 1.0293, 1.0059, 1.0210, 1.0566, 1.0649, 1.2344, 1.9995, 
					  1.4663, 1.3125, 1.0322, 1.0791, 1.0645, 1.0586, 1.0991, 1.1475, 1.3687, 2.4360, 
					  1.4766, 1.4204, 1.0703, 1.0620, 1.0249, 1.0376, 1.0566, 1.3379, 1.3408, 4.4609, 
					  3.1650, 1.4600, 1.1978, 1.1035, 1.1138, 1.1279, 1.1240, 1.6230, 1.2520, 6.4053, 
					  2.0625, 1.2183, 1.1045, 1.0381, 1.0381, 1.0313, 1.0557, 1.1670, 1.2505, 2.8003, 
					  1.6577, 1.1450, 1.0498, 1.0342, 1.0186, 1.0415, 1.0522, 1.0864, 1.2129, 2.1099, 
					  1.5571, 1.1362, 1.0649, 1.0317, 1.0537, 1.0420, 1.0718, 1.0903, 1.1963, 1.8594, 
					  1.4766, 1.0474, 1.0151, 0.9839, 0.9780, 0.9751, 1.0054, 1.0298, 1.1025, 1.6816, 
					  1.5298, 1.1294, 1.0674, 1.0513, 1.0229, 1.0264, 1.0728, 1.0898, 1.1812, 1.8086, 
					  1.5449, 1.0659, 1.0322, 0.9897, 0.9883, 1.0073, 1.0239, 1.0449, 1.1196, 1.8438, 
					  1.6499, 1.1064, 1.0654, 1.0244, 1.0278, 1.0181, 1.0645, 1.0815, 1.2197, 2.0425, 
					  1.4678, 1.3198, 1.0259, 1.0884, 1.0449, 1.0679, 1.0898, 1.1484, 1.3491, 2.3818, 
					  1.4619, 1.3159, 1.1353, 1.0039, 1.0454, 1.0415, 1.0547, 1.2676, 1.4258, 3.9604, 
					},
				},
				
				/* para 2 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.5620, 1.2607, 1.3359, 1.1006, 1.0703, 1.0669, 1.0713, 1.1201, 1.4722, 2.4375, 
					  1.9253, 1.2578, 1.1416, 1.0830, 1.0464, 1.0483, 1.0684, 1.1421, 1.2466, 2.3481, 
					  1.5947, 1.2080, 1.0742, 1.0586, 1.0273, 1.0205, 1.0562, 1.0542, 1.1909, 1.7646, 
					  1.5000, 1.1548, 1.0674, 1.0342, 1.0107, 1.0195, 1.0288, 1.0571, 1.1255, 1.6768, 
					  1.5454, 1.1377, 1.0693, 1.0352, 1.0059, 0.9932, 1.0317, 1.0420, 1.1079, 1.5854, 
					  1.5181, 1.1270, 1.0649, 1.0273, 0.9932, 0.9951, 1.0239, 1.0444, 1.1162, 1.5918, 
					  1.5693, 1.1392, 1.0659, 1.0313, 1.0059, 0.9990, 1.0171, 1.0439, 1.1172, 1.6401, 
					  1.6978, 1.1646, 1.0835, 1.0415, 1.0264, 1.0083, 1.0396, 1.0581, 1.1733, 1.7813, 
					  2.0332, 1.2480, 1.1191, 1.0796, 1.0273, 1.0298, 1.0444, 1.1050, 1.2539, 2.1748, 
					  2.9233, 1.3428, 1.2427, 1.0742, 1.0791, 1.0444, 1.0527, 1.0850, 1.4810, 2.3062, 
					  3.5752, 1.1948, 1.3350, 1.0640, 1.0479, 1.0449, 1.0669, 1.0615, 1.4722, 2.1514, 
					  1.8970, 1.2427, 1.1265, 1.0693, 1.0483, 1.0439, 1.0581, 1.1475, 1.2129, 2.3726, 
					  1.5527, 1.1782, 1.0581, 1.0425, 1.0142, 1.0161, 1.0493, 1.0400, 1.1714, 1.7319, 
					  1.4487, 1.1455, 1.0469, 1.0254, 1.0181, 1.0137, 1.0298, 1.0493, 1.1021, 1.6367, 
					  1.4937, 1.1094, 1.0542, 1.0181, 1.0039, 0.9985, 1.0239, 1.0400, 1.0869, 1.5752, 
					  1.4722, 1.1133, 1.0474, 1.0171, 0.9971, 1.0015, 1.0239, 1.0376, 1.0957, 1.5439, 
					  1.5327, 1.1152, 1.0483, 1.0278, 1.0020, 1.0005, 1.0117, 1.0342, 1.0957, 1.6025, 
					  1.6792, 1.1353, 1.0640, 1.0205, 1.0229, 1.0039, 1.0337, 1.0479, 1.1572, 1.7451, 
					  2.0757, 1.2036, 1.1108, 1.0596, 1.0205, 1.0225, 1.0381, 1.0825, 1.2285, 2.1143, 
					  3.0986, 1.2891, 1.2080, 1.0425, 1.0371, 1.0371, 1.0273, 1.0654, 1.4429, 2.3350, 
					  3.4458, 1.1899, 1.3379, 1.0503, 1.0786, 1.0693, 1.0566, 1.0537, 1.4741, 2.0913, 
					  1.8608, 1.2197, 1.0986, 1.0552, 1.0269, 1.0229, 1.0532, 1.1177, 1.1919, 2.3579, 
					  1.5190, 1.1587, 1.0503, 1.0327, 1.0249, 1.0244, 1.0430, 1.0293, 1.1553, 1.7183, 
					  1.4336, 1.1304, 1.0298, 1.0337, 1.0122, 1.0210, 1.0303, 1.0347, 1.0933, 1.6357, 
					  1.4644, 1.0884, 1.0444, 1.0088, 1.0049, 0.9951, 1.0308, 1.0283, 1.0806, 1.5625, 
					  1.4858, 1.1099, 1.0410, 1.0278, 0.9971, 1.0020, 1.0176, 1.0220, 1.0806, 1.5288, 
					  1.5225, 1.0967, 1.0415, 1.0200, 1.0063, 0.9917, 1.0137, 1.0249, 1.0850, 1.5864, 
					  1.6733, 1.1265, 1.0596, 1.0259, 1.0205, 1.0034, 1.0283, 1.0425, 1.1323, 1.7500, 
					  2.0513, 1.2007, 1.1011, 1.0649, 1.0161, 1.0244, 1.0210, 1.0884, 1.2139, 2.0220, 
					  3.1040, 1.2505, 1.2632, 1.0186, 1.0527, 1.0454, 1.0342, 1.0254, 1.4731, 2.1196, 
					},
				},
				/* para 3 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.4224, 1.2358, 1.2764, 1.0811, 1.0684, 1.0874, 1.0586, 1.1782, 1.4570, 2.8896, 
					  1.9912, 1.2119, 1.1675, 1.0806, 1.0435, 1.0508, 1.0723, 1.1748, 1.2617, 2.4927, 
					  1.5571, 1.1694, 1.0913, 1.0400, 1.0249, 1.0273, 1.0562, 1.0591, 1.2236, 1.7373, 
					  1.3979, 1.1567, 1.0513, 1.0308, 1.0054, 1.0200, 1.0317, 1.0854, 1.1377, 1.7393, 
					  1.4219, 1.1304, 1.0435, 1.0215, 1.0000, 1.0039, 1.0308, 1.0518, 1.1436, 1.6284, 
					  1.4814, 1.1162, 1.0557, 1.0176, 0.9922, 0.9878, 1.0317, 1.0649, 1.1333, 1.6636, 
					  1.5190, 1.1304, 1.0537, 1.0317, 1.0054, 1.0083, 1.0264, 1.0601, 1.1465, 1.7002, 
					  1.6040, 1.1641, 1.0664, 1.0396, 1.0239, 1.0059, 1.0527, 1.0747, 1.2031, 1.8315, 
					  2.0820, 1.2227, 1.1226, 1.0737, 1.0327, 1.0405, 1.0562, 1.1265, 1.2822, 2.2544, 
					  2.8403, 1.3335, 1.2236, 1.0674, 1.0728, 1.0630, 1.0713, 1.1255, 1.5088, 2.5112, 
					  3.2778, 1.2197, 1.2319, 1.0552, 1.0508, 1.0630, 1.0732, 1.0981, 1.4766, 2.5654, 
					  1.9434, 1.1860, 1.1377, 1.0552, 1.0469, 1.0347, 1.0703, 1.1650, 1.2207, 2.5059, 
					  1.5005, 1.1475, 1.0669, 1.0337, 1.0161, 1.0264, 1.0498, 1.0347, 1.2036, 1.6821, 
					  1.3369, 1.1348, 1.0249, 1.0215, 1.0166, 1.0166, 1.0361, 1.0581, 1.1201, 1.6748, 
					  1.3784, 1.1094, 1.0298, 1.0156, 1.0005, 1.0010, 1.0264, 1.0439, 1.1064, 1.5986, 
					  1.3931, 1.1040, 1.0249, 1.0156, 0.9976, 1.0005, 1.0288, 1.0449, 1.1133, 1.5674, 
					  1.4863, 1.1084, 1.0415, 1.0264, 1.0059, 1.0078, 1.0234, 1.0410, 1.1226, 1.6313, 
					  1.5762, 1.1284, 1.0420, 1.0220, 1.0215, 1.0112, 1.0410, 1.0586, 1.1709, 1.7769, 
					  2.1025, 1.1826, 1.1108, 1.0586, 1.0210, 1.0303, 1.0459, 1.0903, 1.2593, 2.1426, 
					  3.0220, 1.2803, 1.1992, 1.0449, 1.0425, 1.0571, 1.0483, 1.0977, 1.4487, 2.5024, 
					  3.2905, 1.1860, 1.2305, 1.0317, 1.0405, 1.0654, 1.0269, 1.0835, 1.4463, 2.4751, 
					  1.9092, 1.1499, 1.1265, 1.0386, 1.0342, 1.0254, 1.0669, 1.1421, 1.2036, 2.4570, 
					  1.4956, 1.1323, 1.0430, 1.0317, 1.0068, 1.0225, 1.0342, 1.0200, 1.1753, 1.6924, 
					  1.3286, 1.1060, 1.0259, 1.0039, 1.0220, 1.0132, 1.0342, 1.0508, 1.1045, 1.6768, 
					  1.3633, 1.0859, 1.0161, 1.0137, 1.0044, 1.0044, 1.0376, 1.0381, 1.0859, 1.5928, 
					  1.4102, 1.0713, 1.0361, 1.0107, 0.9966, 1.0015, 1.0283, 1.0249, 1.1016, 1.5400, 
					  1.4521, 1.0908, 1.0273, 1.0151, 1.0083, 1.0015, 1.0269, 1.0464, 1.0942, 1.6558, 
					  1.5479, 1.1157, 1.0366, 1.0264, 1.0137, 1.0156, 1.0327, 1.0552, 1.1519, 1.7910, 
					  2.0566, 1.1768, 1.1064, 1.0474, 1.0273, 1.0146, 1.0459, 1.0967, 1.2383, 2.1069, 
					  2.9771, 1.2744, 1.1895, 1.0542, 1.0322, 1.0645, 1.0439, 1.0430, 1.5024, 2.2769, 
					},
				},
				/* para 4 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.2935, 1.2832, 1.2705, 1.0947, 1.0938, 1.0781, 1.1201, 1.2188, 1.5142, 3.1924, 
					  1.9536, 1.2368, 1.1787, 1.0869, 1.0537, 1.0630, 1.0947, 1.2271, 1.3013, 2.5669, 
					  1.5420, 1.2017, 1.1094, 1.0498, 1.0308, 1.0298, 1.0786, 1.0747, 1.2764, 1.7822, 
					  1.3755, 1.1909, 1.0508, 1.0371, 1.0161, 1.0205, 1.0527, 1.1079, 1.1885, 1.7769, 
					  1.4531, 1.1533, 1.0625, 1.0166, 1.0015, 1.0029, 1.0376, 1.0898, 1.1738, 1.7173, 
					  1.4995, 1.1484, 1.0640, 1.0332, 0.9927, 0.9985, 1.0483, 1.0840, 1.1792, 1.6875, 
					  1.5239, 1.1558, 1.0723, 1.0220, 1.0151, 1.0098, 1.0430, 1.0894, 1.1938, 1.7354, 
					  1.6445, 1.1982, 1.0786, 1.0605, 1.0205, 1.0239, 1.0601, 1.0962, 1.2446, 1.8647, 
					  2.0889, 1.2378, 1.1606, 1.0776, 1.0537, 1.0488, 1.0845, 1.1772, 1.3257, 2.3149, 
					  2.9546, 1.3569, 1.2617, 1.1016, 1.0854, 1.0884, 1.1060, 1.1367, 1.5640, 2.5869, 
					  3.1919, 1.1943, 1.2031, 1.0459, 1.0518, 1.0576, 1.0664, 1.1167, 1.4731, 2.7817, 
					  1.8960, 1.1768, 1.1250, 1.0537, 1.0366, 1.0303, 1.0684, 1.1704, 1.2168, 2.5347, 
					  1.4731, 1.1304, 1.0610, 1.0313, 1.0137, 1.0200, 1.0474, 1.0337, 1.2109, 1.6997, 
					  1.2949, 1.1265, 1.0132, 1.0142, 1.0156, 1.0068, 1.0405, 1.0596, 1.1230, 1.6816, 
					  1.3491, 1.0884, 1.0254, 1.0073, 0.9976, 1.0098, 1.0225, 1.0557, 1.1016, 1.6187, 
					  1.3862, 1.0952, 1.0239, 1.0063, 1.0000, 0.9912, 1.0303, 1.0527, 1.1138, 1.5918, 
					  1.4585, 1.0957, 1.0298, 1.0229, 1.0054, 1.0107, 1.0239, 1.0542, 1.1133, 1.6392, 
					  1.5518, 1.1250, 1.0361, 1.0166, 1.0122, 1.0054, 1.0391, 1.0601, 1.1768, 1.8193, 
					  2.0903, 1.1689, 1.1074, 1.0508, 1.0317, 1.0273, 1.0518, 1.0977, 1.2637, 2.1450, 
					  3.0449, 1.2632, 1.1958, 1.0430, 1.0234, 1.0444, 1.0425, 1.1182, 1.4351, 2.6479, 
					  3.0825, 1.1646, 1.1831, 1.0176, 1.0410, 1.0454, 1.0356, 1.1108, 1.4399, 2.7637, 
					  1.8965, 1.1426, 1.1143, 1.0396, 1.0254, 1.0298, 1.0591, 1.1396, 1.2070, 2.4614, 
					  1.4321, 1.1123, 1.0410, 1.0259, 1.0059, 1.0186, 1.0396, 1.0176, 1.1846, 1.6670, 
					  1.2827, 1.1079, 1.0020, 1.0122, 1.0088, 1.0195, 1.0386, 1.0518, 1.1118, 1.6704, 
					  1.3286, 1.0737, 1.0024, 1.0063, 1.0005, 1.0029, 1.0327, 1.0332, 1.0923, 1.5752, 
					  1.3809, 1.0811, 1.0215, 1.0156, 0.9990, 1.0049, 1.0239, 1.0391, 1.0874, 1.5767, 
					  1.4165, 1.0854, 1.0103, 1.0176, 1.0029, 1.0029, 1.0283, 1.0410, 1.1084, 1.6426, 
					  1.5376, 1.1113, 1.0288, 1.0229, 1.0176, 1.0093, 1.0317, 1.0532, 1.1475, 1.7979, 
					  2.0278, 1.1738, 1.0957, 1.0522, 1.0249, 1.0195, 1.0415, 1.0894, 1.2529, 2.0806, 
					  2.9941, 1.2222, 1.2153, 1.0381, 1.0381, 1.0586, 1.0420, 1.0781, 1.4531, 2.4468, 
					},
				},
				/* para 5 */
				{
					0.800000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
					  3.4546, 1.2393, 1.3135, 1.0879, 1.0918, 1.0874, 1.1035, 1.1953, 1.5313, 2.9038, 
					  2.0225, 1.2686, 1.1855, 1.0947, 1.0537, 1.0547, 1.0859, 1.2100, 1.2832, 2.5361, 
					  1.5767, 1.2002, 1.1060, 1.0576, 1.0269, 1.0425, 1.0698, 1.0845, 1.2705, 1.7739, 
					  1.3931, 1.1904, 1.0576, 1.0244, 1.0088, 1.0049, 1.0391, 1.0903, 1.1694, 1.7495, 
					  1.4937, 1.1582, 1.0630, 1.0293, 1.0000, 1.0034, 1.0347, 1.0864, 1.1577, 1.7236, 
					  1.5029, 1.1563, 1.0630, 1.0327, 0.9854, 0.9951, 1.0410, 1.0698, 1.1782, 1.6460, 
					  1.5435, 1.1621, 1.0669, 1.0239, 1.0088, 1.0044, 1.0210, 1.0845, 1.1665, 1.7432, 
					  1.6855, 1.2002, 1.0942, 1.0615, 1.0234, 1.0210, 1.0601, 1.0913, 1.2437, 1.8789, 
					  2.0571, 1.2642, 1.1362, 1.0811, 1.0469, 1.0371, 1.0703, 1.1533, 1.3052, 2.2544, 
					  2.9468, 1.3721, 1.2817, 1.1108, 1.0869, 1.0815, 1.0923, 1.1270, 1.5835, 2.4727, 
					  3.2905, 1.1948, 1.2368, 1.0405, 1.0547, 1.0576, 1.0601, 1.0981, 1.4683, 2.5371, 
					  1.9399, 1.1865, 1.1382, 1.0566, 1.0371, 1.0352, 1.0630, 1.1592, 1.2202, 2.4888, 
					  1.4907, 1.1494, 1.0640, 1.0386, 1.0190, 1.0254, 1.0508, 1.0420, 1.1958, 1.7002, 
					  1.3257, 1.1279, 1.0171, 1.0132, 1.0044, 1.0078, 1.0313, 1.0459, 1.1230, 1.6445, 
					  1.3872, 1.0996, 1.0361, 1.0171, 1.0049, 1.0088, 1.0293, 1.0493, 1.1040, 1.5962, 
					  1.4155, 1.1011, 1.0264, 1.0146, 0.9854, 0.9976, 1.0225, 1.0454, 1.1074, 1.5815, 
					  1.4644, 1.1011, 1.0337, 1.0146, 1.0107, 0.9961, 1.0264, 1.0410, 1.1157, 1.6240, 
					  1.6060, 1.1338, 1.0420, 1.0264, 1.0151, 1.0059, 1.0376, 1.0552, 1.1724, 1.7769, 
					  2.0728, 1.1782, 1.1055, 1.0464, 1.0229, 1.0181, 1.0454, 1.1001, 1.2471, 2.1602, 
					  3.0166, 1.2734, 1.1948, 1.0327, 1.0352, 1.0229, 1.0454, 1.0640, 1.4517, 2.4404, 
					  3.2148, 1.1685, 1.2314, 1.0342, 1.0337, 1.0601, 1.0386, 1.0874, 1.4419, 2.5498, 
					  1.9175, 1.1460, 1.1187, 1.0400, 1.0264, 1.0361, 1.0454, 1.1460, 1.1831, 2.4556, 
					  1.4609, 1.1309, 1.0420, 1.0308, 1.0132, 1.0186, 1.0444, 1.0181, 1.1797, 1.6733, 
					  1.3159, 1.1074, 1.0049, 1.0186, 1.0088, 1.0171, 1.0347, 1.0396, 1.1006, 1.6719, 
					  1.3618, 1.0840, 1.0146, 1.0151, 1.0059, 1.0068, 1.0303, 1.0415, 1.0796, 1.5825, 
					  1.3882, 1.0806, 1.0210, 1.0181, 1.0015, 0.9980, 1.0322, 1.0205, 1.0947, 1.5513, 
					  1.4443, 1.0835, 1.0171, 1.0151, 0.9966, 1.0039, 1.0176, 1.0278, 1.0923, 1.6040, 
					  1.5830, 1.1089, 1.0474, 1.0254, 1.0225, 1.0186, 1.0352, 1.0669, 1.1392, 1.8296, 
					  2.0010, 1.1719, 1.0879, 1.0366, 1.0103, 1.0166, 1.0288, 1.0713, 1.2354, 2.0303, 
					  3.0264, 1.2388, 1.2222, 1.0474, 1.0459, 1.0493, 1.0454, 1.0444, 1.4629, 2.3745, 
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
      1, //enable
      1, /*interpolation enable*/
      1, //ae count
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
      1, //enable
      1, /*interpolation enable*/
      2, //ae count
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
			380,
			424,
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
                    0.85,
                    0.000000,
                },
                //awb trigger 1
                {
                    0.85,
                    0.000000,
                },
                //awb trigger 2
                {
                    0.85,
                    0.000000,
                },
                //awb trigger 3
                {
                    0.85,
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
            3.500,
          },
          /* aec trigger 3 */
          {
            4.000,
            6.000,
          },
          /* aec trigger 4 */
          {
            8.000,
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
                   44,124,44,//gaussian(1,1:3)
                   124,345,124,//gaussian(2,1:3)
                   44,124,44,//gaussian(3,1:3)
               },
               80,  //sharpen_pos
               80,  //sharpen_fu
               3,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   44,124,44,//gaussian(1,1:3)
                   124,345,124,//gaussian(2,1:3)
                   44,124,44,//gaussian(3,1:3)
               },
               78,  //sharpen_pos
               80,  //sharpen_fu
               5,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               55,  //sharpen_pos
               60,  //sharpen_fu
               6,  //noise_th
               0,  //order_en
               120, //limit_max
               120, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               48,  //sharpen_pos
               56,  //sharpen_fu
               10,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               42,  //sharpen_pos
               46,  //sharpen_fu
               12,  //noise_th
               0,  //order_en
               80, //limit_max
               80, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 6 */
           {
               {
                   68,127,68,//gaussian(1,1:3)
                   127,236,127,//gaussian(2,1:3)
                   68,127,68,//gaussian(3,1:3)
               },
               35,  //sharpen_pos
               38,  //sharpen_fu
               12,  //noise_th
               0,  //order_en
               70, //limit_max
               70, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 7 */
           {
               {
                   87,124,87,//gaussian(1,1:3)
                   124,175,124,//gaussian(2,1:3)
                   87,124,87,//gaussian(3,1:3)
               },
               35,  //sharpen_pos
               38,  //sharpen_fu
               14,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 8 */
           {
               {
                   97,121,97,//gaussian(1,1:3)
                   121,151,121,//gaussian(2,1:3)
                   97,121,97,//gaussian(3,1:3)
               },
               38,  //sharpen_pos
               40,  //sharpen_fu
               13,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 9 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               38,  //sharpen_pos
               40,  //sharpen_fu
               14,  //noise_th
               0,  //order_en
               60, //limit_max
               60, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 10 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               45,  //sharpen_fu
               15,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 1, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 11 */
           {
               {
                   104,118,104,//gaussian(1,1:3)
                   118,133,118,//gaussian(2,1:3)
                   104,118,104,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               40,  //sharpen_fu
               15,  //noise_th
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
            8.000,
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
          /* para 2 */
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
          /* para 3 */
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
            8.000,
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
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
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
           /* parameter 5 */
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
           /* parameter 6 */
           {
               //weight_cur_lut[32]
               {
                   16,13,11,10,9,8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,
               },
               //weight_pre_lut[32]
               {
                   32,26,23,20,18,16,14,13,12,11,10,9,8,8,7,6,6,5,5,4,4,3,3,2,2,2,1,1,0,0,0,0,
               },
               //weight_big_block_lut[32]
               {
                   328,267,230,203,181,164,149,136,124,114,104,96,88,81,74,68,62,56,51,46,41,36,32,27,23,20,16,12,9,5,2,0,
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
                   49,40,34,30,27,24,22,20,18,17,15,14,13,12,11,10,9,8,7,6,6,5,4,4,3,3,2,1,1,0,0,0,
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
                   65,53,46,40,36,32,29,27,24,22,21,19,17,16,14,13,12,11,10,9,8,7,6,5,4,4,3,2,1,1,0,0,
               },
               //weight_big_block_lut[32]
               {
                   446,364,313,276,247,223,202,185,169,155,142,131,120,110,101,92,84,76,69,62,56,49,43,38,32,27,22,17,12,7,3,0,
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
        424,
        /* ev0_count */
        424,
        /* ev2_count */
        424,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        1000,
        /* max_isp_gain */
        1,
        /* exp_table */
        {
          {256,  3  },        /* Gain= 1.000000 Exposure Index= 0 */
          {264,  3  },        /* Gain= 1.031250 Exposure Index= 1 */
          {272,  3  },        /* Gain= 1.062500 Exposure Index= 2 */
          {281,  3  },        /* Gain= 1.097656 Exposure Index= 3 */
          {290,  3  },        /* Gain= 1.132813 Exposure Index= 4 */
          {299,  3  },        /* Gain= 1.167969 Exposure Index= 5 */
          {308,  3  },        /* Gain= 1.203125 Exposure Index= 6 */
          {318,  3  },        /* Gain= 1.242188 Exposure Index= 7 */
          {328,  3  },        /* Gain= 1.281250 Exposure Index= 8 */
          {338,  3  },        /* Gain= 1.320313 Exposure Index= 9 */
          {262,  4  },        /* Gain= 1.023438 Exposure Index= 10 */
          {270,  4  },        /* Gain= 1.054688 Exposure Index= 11 */
          {279,  4  },        /* Gain= 1.089844 Exposure Index= 12 */
          {288,  4  },        /* Gain= 1.125000 Exposure Index= 13 */
          {297,  4  },        /* Gain= 1.160156 Exposure Index= 14 */
          {306,  4  },        /* Gain= 1.195313 Exposure Index= 15 */
          {316,  4  },        /* Gain= 1.234375 Exposure Index= 16 */
          {261,  5  },        /* Gain= 1.019531 Exposure Index= 17 */
          {269,  5  },        /* Gain= 1.050781 Exposure Index= 18 */
          {278,  5  },        /* Gain= 1.085938 Exposure Index= 19 */
          {287,  5  },        /* Gain= 1.121094 Exposure Index= 20 */
          {296,  5  },        /* Gain= 1.156250 Exposure Index= 21 */
          {305,  5  },        /* Gain= 1.191406 Exposure Index= 22 */
          {262,  6  },        /* Gain= 1.023438 Exposure Index= 23 */
          {270,  6  },        /* Gain= 1.054688 Exposure Index= 24 */
          {279,  6  },        /* Gain= 1.089844 Exposure Index= 25 */
          {288,  6  },        /* Gain= 1.125000 Exposure Index= 26 */
          {297,  6  },        /* Gain= 1.160156 Exposure Index= 27 */
          {263,  7  },        /* Gain= 1.027344 Exposure Index= 28 */
          {271,  7  },        /* Gain= 1.058594 Exposure Index= 29 */
          {280,  7  },        /* Gain= 1.093750 Exposure Index= 30 */
          {289,  7  },        /* Gain= 1.128906 Exposure Index= 31 */
          {261,  8  },        /* Gain= 1.019531 Exposure Index= 32 */
          {269,  8  },        /* Gain= 1.050781 Exposure Index= 33 */
          {278,  8  },        /* Gain= 1.085938 Exposure Index= 34 */
          {287,  8  },        /* Gain= 1.121094 Exposure Index= 35 */
          {263,  9  },        /* Gain= 1.027344 Exposure Index= 36 */
          {271,  9  },        /* Gain= 1.058594 Exposure Index= 37 */
          {280,  9  },        /* Gain= 1.093750 Exposure Index= 38 */
          {260,  10  },        /* Gain= 1.015625 Exposure Index= 39 */
          {268,  10  },        /* Gain= 1.046875 Exposure Index= 40 */
          {277,  10  },        /* Gain= 1.082031 Exposure Index= 41 */
          {260,  11  },        /* Gain= 1.015625 Exposure Index= 42 */
          {268,  11  },        /* Gain= 1.046875 Exposure Index= 43 */
          {277,  11  },        /* Gain= 1.082031 Exposure Index= 44 */
          {262,  12  },        /* Gain= 1.023438 Exposure Index= 45 */
          {270,  12  },        /* Gain= 1.054688 Exposure Index= 46 */
          {257,  13  },        /* Gain= 1.003906 Exposure Index= 47 */
          {265,  13  },        /* Gain= 1.035156 Exposure Index= 48 */
          {273,  13  },        /* Gain= 1.066406 Exposure Index= 49 */
          {262,  14  },        /* Gain= 1.023438 Exposure Index= 50 */
          {270,  14  },        /* Gain= 1.054688 Exposure Index= 51 */
          {260,  15  },        /* Gain= 1.015625 Exposure Index= 52 */
          {268,  15  },        /* Gain= 1.046875 Exposure Index= 53 */
          {259,  16  },        /* Gain= 1.011719 Exposure Index= 54 */
          {267,  16  },        /* Gain= 1.042969 Exposure Index= 55 */
          {259,  17  },        /* Gain= 1.011719 Exposure Index= 56 */
          {267,  17  },        /* Gain= 1.042969 Exposure Index= 57 */
          {260,  18  },        /* Gain= 1.015625 Exposure Index= 58 */
          {268,  18  },        /* Gain= 1.046875 Exposure Index= 59 */
          {262,  19  },        /* Gain= 1.023438 Exposure Index= 60 */
          {257,  20  },        /* Gain= 1.003906 Exposure Index= 61 */
          {265,  20  },        /* Gain= 1.035156 Exposure Index= 62 */
          {260,  21  },        /* Gain= 1.015625 Exposure Index= 63 */
          {268,  21  },        /* Gain= 1.046875 Exposure Index= 64 */
          {264,  22  },        /* Gain= 1.031250 Exposure Index= 65 */
          {261,  23  },        /* Gain= 1.019531 Exposure Index= 66 */
          {258,  24  },        /* Gain= 1.007813 Exposure Index= 67 */
          {266,  24  },        /* Gain= 1.039063 Exposure Index= 68 */
          {264,  25  },        /* Gain= 1.031250 Exposure Index= 69 */
          {262,  26  },        /* Gain= 1.023438 Exposure Index= 70 */
          {260,  27  },        /* Gain= 1.015625 Exposure Index= 71 */
          {259,  28  },        /* Gain= 1.011719 Exposure Index= 72 */
          {258,  29  },        /* Gain= 1.007813 Exposure Index= 73 */
          {257,  30  },        /* Gain= 1.003906 Exposure Index= 74 */
          {257,  31  },        /* Gain= 1.003906 Exposure Index= 75 */
          {257,  32  },        /* Gain= 1.003906 Exposure Index= 76 */
          {257,  33  },        /* Gain= 1.003906 Exposure Index= 77 */
          {257,  34  },        /* Gain= 1.003906 Exposure Index= 78 */
          {258,  35  },        /* Gain= 1.007813 Exposure Index= 79 */
          {259,  36  },        /* Gain= 1.011719 Exposure Index= 80 */
          {260,  37  },        /* Gain= 1.015625 Exposure Index= 81 */
          {261,  38  },        /* Gain= 1.019531 Exposure Index= 82 */
          {262,  39  },        /* Gain= 1.023438 Exposure Index= 83 */
          {257,  41  },        /* Gain= 1.003906 Exposure Index= 84 */
          {259,  42  },        /* Gain= 1.011719 Exposure Index= 85 */
          {261,  43  },        /* Gain= 1.019531 Exposure Index= 86 */
          {257,  45  },        /* Gain= 1.003906 Exposure Index= 87 */
          {259,  46  },        /* Gain= 1.011719 Exposure Index= 88 */
          {256,  48  },        /* Gain= 1.000000 Exposure Index= 89 */
          {259,  49  },        /* Gain= 1.011719 Exposure Index= 90 */
          {257,  51  },        /* Gain= 1.003906 Exposure Index= 91 */
          {260,  52  },        /* Gain= 1.015625 Exposure Index= 92 */
          {258,  54  },        /* Gain= 1.007813 Exposure Index= 93 */
          {257,  56  },        /* Gain= 1.003906 Exposure Index= 94 */
          {256,  58  },        /* Gain= 1.000000 Exposure Index= 95 */
          {260,  59  },        /* Gain= 1.015625 Exposure Index= 96 */
          {260,  61  },        /* Gain= 1.015625 Exposure Index= 97 */
          {260,  63  },        /* Gain= 1.015625 Exposure Index= 98 */
          {256,  66  },        /* Gain= 1.000000 Exposure Index= 99 */
          {256,  68  },        /* Gain= 1.000000 Exposure Index= 100 */
          {257,  70  },        /* Gain= 1.003906 Exposure Index= 101 */
          {258,  72  },        /* Gain= 1.007813 Exposure Index= 102 */
          {259,  74  },        /* Gain= 1.011719 Exposure Index= 103 */
          {257,  77  },        /* Gain= 1.003906 Exposure Index= 104 */
          {259,  79  },        /* Gain= 1.011719 Exposure Index= 105 */
          {258,  82  },        /* Gain= 1.007813 Exposure Index= 106 */
          {257,  85  },        /* Gain= 1.003906 Exposure Index= 107 */
          {256,  88  },        /* Gain= 1.000000 Exposure Index= 108 */
          {258,  90  },        /* Gain= 1.007813 Exposure Index= 109 */
          {258,  93  },        /* Gain= 1.007813 Exposure Index= 110 */
          {258,  96  },        /* Gain= 1.007813 Exposure Index= 111 */
          {258,  99  },        /* Gain= 1.007813 Exposure Index= 112 */
          {258,  102  },        /* Gain= 1.007813 Exposure Index= 113 */
          {256,  106  },        /* Gain= 1.000000 Exposure Index= 114 */
          {257,  109  },        /* Gain= 1.003906 Exposure Index= 115 */
          {258,  112  },        /* Gain= 1.007813 Exposure Index= 116 */
          {257,  116  },        /* Gain= 1.003906 Exposure Index= 117 */
          {256,  120  },        /* Gain= 1.000000 Exposure Index= 118 */
          {258,  123  },        /* Gain= 1.007813 Exposure Index= 119 */
          {258,  127  },        /* Gain= 1.007813 Exposure Index= 120 */
          {256,  132  },        /* Gain= 1.000000 Exposure Index= 121 */
          {256,  136  },        /* Gain= 1.000000 Exposure Index= 122 */
          {257,  140  },        /* Gain= 1.003906 Exposure Index= 123 */
          {256,  145  },        /* Gain= 1.000000 Exposure Index= 124 */
          {257,  149  },        /* Gain= 1.003906 Exposure Index= 125 */
          {257,  154  },        /* Gain= 1.003906 Exposure Index= 126 */
          {257,  159  },        /* Gain= 1.003906 Exposure Index= 127 */
          {257,  164  },        /* Gain= 1.003906 Exposure Index= 128 */
          {257,  169  },        /* Gain= 1.003906 Exposure Index= 129 */
          {256,  175  },        /* Gain= 1.000000 Exposure Index= 130 */
          {257,  180  },        /* Gain= 1.003906 Exposure Index= 131 */
          {257,  186  },        /* Gain= 1.003906 Exposure Index= 132 */
          {257,  192  },        /* Gain= 1.003906 Exposure Index= 133 */
          {257,  198  },        /* Gain= 1.003906 Exposure Index= 134 */
          {257,  204  },        /* Gain= 1.003906 Exposure Index= 135 */
          {256,  211  },        /* Gain= 1.000000 Exposure Index= 136 */
          {257,  217  },        /* Gain= 1.003906 Exposure Index= 137 */
          {257,  224  },        /* Gain= 1.003906 Exposure Index= 138 */
          {257,  231  },        /* Gain= 1.003906 Exposure Index= 139 */
          {257,  238  },        /* Gain= 1.003906 Exposure Index= 140 */
          {257,  246  },        /* Gain= 1.003906 Exposure Index= 141 */
          {257,  254  },        /* Gain= 1.003906 Exposure Index= 142 */
          {256,  263  },        /* Gain= 1.000000 Exposure Index= 143 */
          {256,  271  },        /* Gain= 1.000000 Exposure Index= 144 */
          {256,  280  },        /* Gain= 1.000000 Exposure Index= 145 */
          {256,  289  },        /* Gain= 1.000000 Exposure Index= 146 */
          {256,  298  },        /* Gain= 1.000000 Exposure Index= 147 */
          {256,  307  },        /* Gain= 1.000000 Exposure Index= 148 */
          {256,  317  },        /* Gain= 1.000000 Exposure Index= 149 */
          {256,  327  },        /* Gain= 1.000000 Exposure Index= 150 */
          {256,  337  },        /* Gain= 1.000000 Exposure Index= 151 */
          {256,  348  },        /* Gain= 1.000000 Exposure Index= 152 */
          {256,  359  },        /* Gain= 1.000000 Exposure Index= 153 */
          {256,  370  },        /* Gain= 1.000000 Exposure Index= 154 */
          {256,  382  },        /* Gain= 1.000000 Exposure Index= 155 */
          {256,  394  },        /* Gain= 1.000000 Exposure Index= 156 */
          {256,  406  },        /* Gain= 1.000000 Exposure Index= 157 */
          {256,  419  },        /* Gain= 1.000000 Exposure Index= 158 */
          {256,  432  },        /* Gain= 1.000000 Exposure Index= 159 */
          {256,  445  },        /* Gain= 1.000000 Exposure Index= 160 */
          {256,  459  },        /* Gain= 1.000000 Exposure Index= 161 */
          {256,  473  },        /* Gain= 1.000000 Exposure Index= 162 */
          {256,  488  },        /* Gain= 1.000000 Exposure Index= 163 */
          {256,  503  },        /* Gain= 1.000000 Exposure Index= 164 */
          {256,  519  },        /* Gain= 1.000000 Exposure Index= 165 */
          {256,  535  },        /* Gain= 1.000000 Exposure Index= 166 */
          {256,  552  },        /* Gain= 1.000000 Exposure Index= 167 */
          {256,  569  },        /* Gain= 1.000000 Exposure Index= 168 */
          {256,  587  },        /* Gain= 1.000000 Exposure Index= 169 */
          {256,  605  },        /* Gain= 1.000000 Exposure Index= 170 */
          {256,  624  },        /* Gain= 1.000000 Exposure Index= 171 */
          {256,  643  },        /* Gain= 1.000000 Exposure Index= 172 */
          {256,  663  },        /* Gain= 1.000000 Exposure Index= 173 */
          {256,  683  },        /* Gain= 1.000000 Exposure Index= 174 */
          {256,  704  },        /* Gain= 1.000000 Exposure Index= 175 */
          {256,  726  },        /* Gain= 1.000000 Exposure Index= 176 */
          {256,  748  },        /* Gain= 1.000000 Exposure Index= 177 */
          {256,  771  },        /* Gain= 1.000000 Exposure Index= 178 */
          {256,  795  },        /* Gain= 1.000000 Exposure Index= 179 */
          {256,  819  },        /* Gain= 1.000000 Exposure Index= 180 */
          {256,  844  },        /* Gain= 1.000000 Exposure Index= 181 */
          {256,  870  },        /* Gain= 1.000000 Exposure Index= 182 */
          {256,  897  },        /* Gain= 1.000000 Exposure Index= 183 */
          {256,  924  },        /* Gain= 1.000000 Exposure Index= 184 */
          {256,  952  },        /* Gain= 1.000000 Exposure Index= 185 */
          {256,  981  },        /* Gain= 1.000000 Exposure Index= 186 */
          {256,  1011  },        /* Gain= 1.000000 Exposure Index= 187 */
          {256,  1042  },        /* Gain= 1.000000 Exposure Index= 188 */
          {256,  1074  },        /* Gain= 1.000000 Exposure Index= 189 */
          {256,  1107  },        /* Gain= 1.000000 Exposure Index= 190 */
          {256,  1141  },        /* Gain= 1.000000 Exposure Index= 191 */
          {256,  1176  },        /* Gain= 1.000000 Exposure Index= 192 */
          {259,  1200  },        /* Gain= 1.011719 Exposure Index= 193 */
          {267,  1200  },        /* Gain= 1.042969 Exposure Index= 194 */
          {276,  1200  },        /* Gain= 1.078125 Exposure Index= 195 */
          {285,  1200  },        /* Gain= 1.113281 Exposure Index= 196 */
          {294,  1200  },        /* Gain= 1.148438 Exposure Index= 197 */
          {303,  1200  },        /* Gain= 1.183594 Exposure Index= 198 */
          {313,  1200  },        /* Gain= 1.222656 Exposure Index= 199 */
          {323,  1200  },        /* Gain= 1.261719 Exposure Index= 200 */
          {333,  1200  },        /* Gain= 1.300781 Exposure Index= 201 */
          {343,  1200  },        /* Gain= 1.339844 Exposure Index= 202 */
          {354,  1200  },        /* Gain= 1.382813 Exposure Index= 203 */
          {365,  1200  },        /* Gain= 1.425781 Exposure Index= 204 */
          {376,  1200  },        /* Gain= 1.468750 Exposure Index= 205 */
          {388,  1200  },        /* Gain= 1.515625 Exposure Index= 206 */
          {400,  1200  },        /* Gain= 1.562500 Exposure Index= 207 */
          {412,  1200  },        /* Gain= 1.609375 Exposure Index= 208 */
          {425,  1200  },        /* Gain= 1.660156 Exposure Index= 209 */
          {438,  1200  },        /* Gain= 1.710938 Exposure Index= 210 */
          {452,  1200  },        /* Gain= 1.765625 Exposure Index= 211 */
          {466,  1200  },        /* Gain= 1.820313 Exposure Index= 212 */
          {480,  1200  },        /* Gain= 1.875000 Exposure Index= 213 */
          {495,  1200  },        /* Gain= 1.933594 Exposure Index= 214 */
          {510,  1200  },        /* Gain= 1.992188 Exposure Index= 215 */
          {526,  1200  },        /* Gain= 2.054688 Exposure Index= 216 */
          {542,  1200  },        /* Gain= 2.117188 Exposure Index= 217 */
          {559,  1200  },        /* Gain= 2.183594 Exposure Index= 218 */
          {576,  1200  },        /* Gain= 2.250000 Exposure Index= 219 */
          {594,  1200  },        /* Gain= 2.320313 Exposure Index= 220 */
          {612,  1200  },        /* Gain= 2.390625 Exposure Index= 221 */
          {631,  1200  },        /* Gain= 2.464844 Exposure Index= 222 */
          {650,  1200  },        /* Gain= 2.539063 Exposure Index= 223 */
          {670,  1200  },        /* Gain= 2.617188 Exposure Index= 224 */
          {691,  1200  },        /* Gain= 2.699219 Exposure Index= 225 */
          {712,  1200  },        /* Gain= 2.781250 Exposure Index= 226 */
          {734,  1200  },        /* Gain= 2.867188 Exposure Index= 227 */
          {757,  1200  },        /* Gain= 2.957031 Exposure Index= 228 */
          {780,  1200  },        /* Gain= 3.046875 Exposure Index= 229 */
          {804,  1200  },        /* Gain= 3.140625 Exposure Index= 230 */
          {829,  1200  },        /* Gain= 3.238281 Exposure Index= 231 */
          {854,  1200  },        /* Gain= 3.335938 Exposure Index= 232 */
          {880,  1200  },        /* Gain= 3.437500 Exposure Index= 233 */
          {907,  1200  },        /* Gain= 3.542969 Exposure Index= 234 */
          {935,  1200  },        /* Gain= 3.652344 Exposure Index= 235 */
          {964,  1200  },        /* Gain= 3.765625 Exposure Index= 236 */
          {993,  1200  },        /* Gain= 3.878906 Exposure Index= 237 */
          {1023,  1200  },        /* Gain= 3.996094 Exposure Index= 238 */
          {1054,  1200  },        /* Gain= 4.117188 Exposure Index= 239 */
          {1086,  1200  },        /* Gain= 4.242188 Exposure Index= 240 */
          {1119,  1200  },        /* Gain= 4.371094 Exposure Index= 241 */
          {1153,  1200  },        /* Gain= 4.503906 Exposure Index= 242 */
          {1188,  1200  },        /* Gain= 4.640625 Exposure Index= 243 */
          {1224,  1200  },        /* Gain= 4.781250 Exposure Index= 244 */
          {1261,  1200  },        /* Gain= 4.925781 Exposure Index= 245 */
          {1299,  1200  },        /* Gain= 5.074219 Exposure Index= 246 */
          {1338,  1200  },        /* Gain= 5.226563 Exposure Index= 247 */
          {1379,  1200  },        /* Gain= 5.386719 Exposure Index= 248 */
          {1421,  1200  },        /* Gain= 5.550781 Exposure Index= 249 */
          {1464,  1200  },        /* Gain= 5.718750 Exposure Index= 250 */
          {1508,  1200  },        /* Gain= 5.890625 Exposure Index= 251 */
          {1554,  1200  },        /* Gain= 6.070313 Exposure Index= 252 */
          {1601,  1200  },        /* Gain= 6.253906 Exposure Index= 253 */
          {1650,  1200  },        /* Gain= 6.445313 Exposure Index= 254 */
          {1700,  1200  },        /* Gain= 6.640625 Exposure Index= 255 */
          {1751,  1200  },        /* Gain= 6.839844 Exposure Index= 256 */
          {1804,  1200  },        /* Gain= 7.046875 Exposure Index= 257 */
          {1859,  1200  },        /* Gain= 7.261719 Exposure Index= 258 */
          {1915,  1200  },        /* Gain= 7.480469 Exposure Index= 259 */
          {1973,  1200  },        /* Gain= 7.707031 Exposure Index= 260 */
          {2033,  1200  },        /* Gain= 7.941406 Exposure Index= 261 */
          {2094,  1200  },        /* Gain= 8.179688 Exposure Index= 262 */
          {2157,  1200  },        /* Gain= 8.425781 Exposure Index= 263 */
          {2222,  1200  },        /* Gain= 8.679688 Exposure Index= 264 */
          {2289,  1200  },        /* Gain= 8.941406 Exposure Index= 265 */
          {2358,  1200  },        /* Gain= 9.210938 Exposure Index= 266 */
          {2429,  1200  },        /* Gain= 9.488281 Exposure Index= 267 */
          {2502,  1200  },        /* Gain= 9.773438 Exposure Index= 268 */
          {2578,  1200  },        /* Gain= 10.070313 Exposure Index= 269 */
          {2656,  1200  },        /* Gain= 10.375000 Exposure Index= 270 */
          {2736,  1200  },        /* Gain= 10.687500 Exposure Index= 271 */
          {2819,  1200  },        /* Gain= 11.011719 Exposure Index= 272 */
          {2904,  1200  },        /* Gain= 11.343750 Exposure Index= 273 */
          {2992,  1200  },        /* Gain= 11.687500 Exposure Index= 274 */
          {3082,  1200  },        /* Gain= 12.039063 Exposure Index= 275 */
          {3175,  1200  },        /* Gain= 12.402344 Exposure Index= 276 */
          {3271,  1200  },        /* Gain= 12.777344 Exposure Index= 277 */
          {3370,  1200  },        /* Gain= 13.164063 Exposure Index= 278 */
          {3472,  1200  },        /* Gain= 13.562500 Exposure Index= 279 */
          {3577,  1200  },        /* Gain= 13.972656 Exposure Index= 280 */
          {3685,  1200  },        /* Gain= 14.394531 Exposure Index= 281 */
          {3796,  1200  },        /* Gain= 14.828125 Exposure Index= 282 */
          {3910,  1200  },        /* Gain= 15.273438 Exposure Index= 283 */
          {4028,  1200  },        /* Gain= 15.734375 Exposure Index= 284 */
          {4149,  1200  },        /* Gain= 16.207031 Exposure Index= 285 */
          {4274,  1200  },        /* Gain= 16.695313 Exposure Index= 286 */
          {4403,  1200  },        /* Gain= 17.199219 Exposure Index= 287 */
          {4536,  1200  },        /* Gain= 17.718750 Exposure Index= 288 */
          {4673,  1200  },        /* Gain= 18.253906 Exposure Index= 289 */
          {4814,  1200  },        /* Gain= 18.804688 Exposure Index= 290 */
          {4959,  1200  },        /* Gain= 19.371094 Exposure Index= 291 */
          {5108,  1200  },        /* Gain= 19.953125 Exposure Index= 292 */
          {5262,  1200  },        /* Gain= 20.554688 Exposure Index= 293 */
          {5420,  1200  },        /* Gain= 21.171875 Exposure Index= 294 */
          {5583,  1200  },        /* Gain= 21.808594 Exposure Index= 295 */
          {5751,  1200  },        /* Gain= 22.464844 Exposure Index= 296 */
          {5924,  1200  },        /* Gain= 23.140625 Exposure Index= 297 */
          {6102,  1200  },        /* Gain= 23.835938 Exposure Index= 298 */
          {6286,  1200  },        /* Gain= 24.554688 Exposure Index= 299 */
          {6475,  1200  },        /* Gain= 25.292969 Exposure Index= 300 */
          {6670,  1200  },        /* Gain= 26.054688 Exposure Index= 301 */
          {6871,  1200  },        /* Gain= 26.839844 Exposure Index= 302 */
          {7078,  1200  },        /* Gain= 27.648438 Exposure Index= 303 */
          {7291,  1200  },        /* Gain= 28.480469 Exposure Index= 304 */
          {7510,  1200  },        /* Gain= 29.335938 Exposure Index= 305 */
          {7736,  1200  },        /* Gain= 30.218750 Exposure Index= 306 */
          {7969,  1200  },        /* Gain= 31.128906 Exposure Index= 307 */
          {8209,  1200  },        /* Gain= 32.066406 Exposure Index= 308 */
          {8456,  1200  },        /* Gain= 33.031250 Exposure Index= 309 */
          {8710,  1200  },        /* Gain= 34.023438 Exposure Index= 310 */
          {8972,  1200  },        /* Gain= 35.046875 Exposure Index= 311 */
          {9242,  1200  },        /* Gain= 36.101563 Exposure Index= 312 */
          {9520,  1200  },        /* Gain= 37.187500 Exposure Index= 313 */
          {9806,  1200  },        /* Gain= 38.304688 Exposure Index= 314 */
          {10101,  1200  },        /* Gain= 39.457031 Exposure Index= 315 */
          {10405,  1200  },        /* Gain= 40.644531 Exposure Index= 316 */
          {10718,  1200  },        /* Gain= 41.867188 Exposure Index= 317 */
          {11040,  1200  },        /* Gain= 43.125000 Exposure Index= 318 */
          {11372,  1200  },        /* Gain= 44.421875 Exposure Index= 319 */
          {11714,  1200  },        /* Gain= 45.757813 Exposure Index= 320 */
          {12066,  1200  },        /* Gain= 47.132813 Exposure Index= 321 */
          {12428,  1200  },        /* Gain= 48.546875 Exposure Index= 322 */
          {12801,  1200  },        /* Gain= 50.003906 Exposure Index= 323 */
          {13186,  1200  },        /* Gain= 51.507813 Exposure Index= 324 */
          {13582,  1200  },        /* Gain= 53.054688 Exposure Index= 325 */
          {13990,  1200  },        /* Gain= 54.648438 Exposure Index= 326 */
          {14410,  1200  },        /* Gain= 56.289063 Exposure Index= 327 */
          {14843,  1200  },        /* Gain= 57.980469 Exposure Index= 328 */
          {15289,  1200  },        /* Gain= 59.722656 Exposure Index= 329 */
          {15748,  1200  },        /* Gain= 61.515625 Exposure Index= 330 */
          {16221,  1200  },        /* Gain= 63.363281 Exposure Index= 331 */
          {16708,  1200  },        /* Gain= 65.265625 Exposure Index= 332 */
          {17210,  1200  },        /* Gain= 67.226563 Exposure Index= 333 */
          {17727,  1200  },        /* Gain= 69.246094 Exposure Index= 334 */
          {18259,  1200  },        /* Gain= 71.324219 Exposure Index= 335 */
          {18807,  1200  },        /* Gain= 73.464844 Exposure Index= 336 */
          {19372,  1200  },        /* Gain= 75.671875 Exposure Index= 337 */
          {19954,  1200  },        /* Gain= 77.945313 Exposure Index= 338 */
          {20553,  1200  },        /* Gain= 80.285156 Exposure Index= 339 */
          {21170,  1200  },        /* Gain= 82.695313 Exposure Index= 340 */
          {21806,  1200  },        /* Gain= 85.179688 Exposure Index= 341 */
          {22461,  1200  },        /* Gain= 87.738281 Exposure Index= 342 */
          {23135,  1200  },        /* Gain= 90.371094 Exposure Index= 343 */
          {23830,  1200  },        /* Gain= 93.085938 Exposure Index= 344 */
          {24545,  1200  },        /* Gain= 95.878906 Exposure Index= 345 */
          {25282,  1200  },        /* Gain= 98.757813 Exposure Index= 346 */
          {26041,  1200  },        /* Gain= 101.722656 Exposure Index= 347 */
          {26823,  1200  },        /* Gain= 104.777344 Exposure Index= 348 */
          {27628,  1200  },        /* Gain= 107.921875 Exposure Index= 349 */
          {28457,  1200  },        /* Gain= 111.160156 Exposure Index= 350 */
          {29311,  1200  },        /* Gain= 114.496094 Exposure Index= 351 */
          {30191,  1200  },        /* Gain= 117.933594 Exposure Index= 352 */
          {31097,  1200  },        /* Gain= 121.472656 Exposure Index= 353 */
          {32030,  1200  },        /* Gain= 125.117188 Exposure Index= 354 */
          {32991,  1200  },        /* Gain= 128.871094 Exposure Index= 355 */
          {33981,  1200  },        /* Gain= 132.738281 Exposure Index= 356 */
          {35001,  1200  },        /* Gain= 136.722656 Exposure Index= 357 */
          {36052,  1200  },        /* Gain= 140.828125 Exposure Index= 358 */
          {37134,  1200  },        /* Gain= 145.054688 Exposure Index= 359 */
          {38249,  1200  },        /* Gain= 149.410156 Exposure Index= 360 */
          {39397,  1200  },        /* Gain= 153.894531 Exposure Index= 361 */
          {40579,  1200  },        /* Gain= 158.511719 Exposure Index= 362 */
          {41797,  1200  },        /* Gain= 163.269531 Exposure Index= 363 */
          {43051,  1200  },        /* Gain= 168.167969 Exposure Index= 364 */
          {44343,  1200  },        /* Gain= 173.214844 Exposure Index= 365 */
          {45674,  1200  },        /* Gain= 178.414063 Exposure Index= 366 */
          {47045,  1200  },        /* Gain= 183.769531 Exposure Index= 367 */
          {48457,  1200  },        /* Gain= 189.285156 Exposure Index= 368 */
          {49911,  1200  },        /* Gain= 194.964844 Exposure Index= 369 */
          {51409,  1200  },        /* Gain= 200.816406 Exposure Index= 370 */
          {52952,  1200  },        /* Gain= 206.843750 Exposure Index= 371 */
          {54541,  1200  },        /* Gain= 213.050781 Exposure Index= 372 */
          {56178,  1200  },        /* Gain= 219.445313 Exposure Index= 373 */
          {57864,  1200  },        /* Gain= 226.031250 Exposure Index= 374 */
          {59600,  1200  },        /* Gain= 232.812500 Exposure Index= 375 */
          {61388,  1200  },        /* Gain= 239.796875 Exposure Index= 376 */
          {63230,  1200  },        /* Gain= 246.992188 Exposure Index= 377 */
          {65127,  1200  },        /* Gain= 254.402344 Exposure Index= 378 */
          {67081,  1200  },        /* Gain= 262.035156 Exposure Index= 379 */
          {69094,  1200  },        /* Gain= 269.898438 Exposure Index= 380 */
          {71167,  1200  },        /* Gain= 277.996094 Exposure Index= 381 */
          {73303,  1200  },        /* Gain= 286.339844 Exposure Index= 382 */
          {75503,  1200  },        /* Gain= 294.933594 Exposure Index= 383 */
          {77769,  1200  },        /* Gain= 303.785156 Exposure Index= 384 */
          {80103,  1200  },        /* Gain= 312.902344 Exposure Index= 385 */
          {82507,  1200  },        /* Gain= 322.292969 Exposure Index= 386 */
          {84983,  1200  },        /* Gain= 331.964844 Exposure Index= 387 */
          {87533,  1200  },        /* Gain= 341.925781 Exposure Index= 388 */
          {90159,  1200  },        /* Gain= 352.183594 Exposure Index= 389 */
          {92864,  1200  },        /* Gain= 362.750000 Exposure Index= 390 */
          {95650,  1200  },        /* Gain= 373.632813 Exposure Index= 391 */
          {98520,  1200  },        /* Gain= 384.843750 Exposure Index= 392 */
          {101476,  1200  },        /* Gain= 396.390625 Exposure Index= 393 */
          {104521,  1200  },        /* Gain= 408.285156 Exposure Index= 394 */
          {107657,  1200  },        /* Gain= 420.535156 Exposure Index= 395 */
          {110887,  1200  },        /* Gain= 433.152344 Exposure Index= 396 */
          {114214,  1200  },        /* Gain= 446.148438 Exposure Index= 397 */
          {117641,  1200  },        /* Gain= 459.535156 Exposure Index= 398 */
          {121171,  1200  },        /* Gain= 473.324219 Exposure Index= 399 */
          {124807,  1200  },        /* Gain= 487.527344 Exposure Index= 400 */
          {128552,  1200  },        /* Gain= 502.156250 Exposure Index= 401 */
          {132409,  1200  },        /* Gain= 517.222656 Exposure Index= 402 */
          {136382,  1200  },        /* Gain= 532.742188 Exposure Index= 403 */
          {140474,  1200  },        /* Gain= 548.726563 Exposure Index= 404 */
          {144689,  1200  },        /* Gain= 565.191406 Exposure Index= 405 */
          {149030,  1200  },        /* Gain= 582.148438 Exposure Index= 406 */
          {153501,  1200  },        /* Gain= 599.613281 Exposure Index= 407 */
          {158107,  1200  },        /* Gain= 617.605469 Exposure Index= 408 */
          {162851,  1200  },        /* Gain= 636.136719 Exposure Index= 409 */
          {167737,  1200  },        /* Gain= 655.222656 Exposure Index= 410 */
          {172770,  1200  },        /* Gain= 674.882813 Exposure Index= 411 */
          {177954,  1200  },        /* Gain= 695.132813 Exposure Index= 412 */
          {183293,  1200  },        /* Gain= 715.988281 Exposure Index= 413 */
          {188792,  1200  },        /* Gain= 737.468750 Exposure Index= 414 */
          {194456,  1200  },        /* Gain= 759.593750 Exposure Index= 415 */
          {200290,  1200  },        /* Gain= 782.382813 Exposure Index= 416 */
          {206299,  1200  },        /* Gain= 805.855469 Exposure Index= 417 */
          {212488,  1200  },        /* Gain= 830.031250 Exposure Index= 418 */
          {218863,  1200  },        /* Gain= 854.933594 Exposure Index= 419 */
          {225429,  1200  },        /* Gain= 880.582031 Exposure Index= 420 */
          {232192,  1200  },        /* Gain= 907.000000 Exposure Index= 421 */
          {239158,  1200  },        /* Gain= 934.210938 Exposure Index= 422 */
          {246333,  1200  },        /* Gain= 962.238281 Exposure Index= 423 */
          {253723,  1200  },        /* Gain= 991.105469 Exposure Index= 424 */
          {261335,  1200  },        /* Gain= 1020.839844 Exposure Index= 425 */
          {269176,  1200  },        /* Gain= 1051.468750 Exposure Index= 426 */
          {277252,  1200  },        /* Gain= 1083.015625 Exposure Index= 427 */
          {285570,  1200  },        /* Gain= 1115.507813 Exposure Index= 428 */
          {294138,  1200  },        /* Gain= 1148.976563 Exposure Index= 429 */
          {302963,  1200  },        /* Gain= 1183.449219 Exposure Index= 430 */
        },
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
		    32,  /* outdoor_luma_target_compensated */ //36
		    24,  /* default_luma_target_compensated */ //36
			15,  /* lowlight_luma_target */   //24
		    120, /* outdoor_index */
		    140, /* indoor_index */  //150
			230, /* lowlight_start_idx */   //230
			//300, /* lowlight_end_idx */
			378, /* lowlight_end_idx */ //391
		},
		5,  /* snow_scene_detect.extreme_luma_target_offset */
		5,  /* backlit_scene_detect.backlight_max_la_luma_target_offset */
		1,	/* aec_motion_iso_preview */
		512,/* R_WEIGHT */
		1024,/* G_WEIGHT */
		512,/* B_WEIGHT */
		11, /* WT_Q */
		{
			30, /* fast_conv.speed */
			2,  /* fast_conv.luma_tolerance */
			0,  /* fast_conv.frame_skip */
		},
		1, /* metering_type 0:SPOT_METERING,1:CENTER_WEIGHTED,2: ADVANCE_FRAME_AVERAGE*/
		0, /*full_sweep_en ,set to 1 to fullsweep exp table*/
		77.894, /* exposure_index_adj_step ,NEED 1 / log10(1.03) */
		1, /* 0: no antibanding; 1: 50Hz antibanding; 2: 60Hz antibanding */
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
            1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1,
            1, 5,10,10,10,10,10,10,10,10,10,10,10,10, 5, 1,
            1, 5,10,15,15,15,15,15,15,15,15,15,15,10, 5, 1,
            1, 5,10,15,25,25,25,25,25,25,25,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,35,35,35,35,35,35,25,15,10, 5, 1,
            1, 5,10,15,25,25,25,25,25,25,25,25,15,10, 5, 1,
            1, 5,10,15,15,15,15,15,15,15,15,15,15,10, 5, 1,
            1, 5,10,10,10,10,10,10,10,10,10,10,10,10, 5, 1,
            1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1,
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
		},*/ /*36x16 bias table for luma metering: 0-100 */
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
            1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1,
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
		}, /*36x16 bias table for luma metering: 0-100 */
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
            0,  /*1: OverExp enable; 0: OverExp disable */
		    240,/* high_luma_region_threshold : OverExp Threshold*/
            /* the ratio table in OverExp condition */
            1.0, //outdoor
            0.9, //indoor
            0.8, //low light
            /*the luma offset to be reduced in OverExp condition */
            15,  //outdoor
             5,  //indoor
             5,  //low light
            /*Max Count Table of OverExp */
            30,  //outdoor
            50,  //indoor
            60,  //low light
            /*Min Count Table of OverExp */
            5,   //outdoor  
            5,   //indoor
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
	10,
	/* count_ae */
	2,
	/* trigger_mode  : 0 gain trigger 1 lux trigger */
	0,
	/* aec_trigger */
    {
		{
            0,
            160,
        },
        {
            161,
            1000,
        },
        {
            0,
            424,
        },
	},	
    /* awb_point */
    {
    	{ 0.4713, 0.7365 },    /* d75 */
        { 0.5057, 0.6967 },    /* d65 */
        { 0.6039, 0.6038 },    /* d50 */
        { 0.6039, 0.6038 },    /* noon */
        { 0.6178, 0.4927 },    /* cw */
        { 0.6961, 0.5379 },    /* tl84 */
        { 0.9420, 0.4055 },    /* a */
        { 1.1122, 0.3873 },    /* h */
        { 0.4917, 0.6152 },    /* custom1 */
        { 0.8224, 0.4288 },    /* custom2 */
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
           0x00000034,	/* Y min  0.05*1024	*/
           0x00000010,
           0x00010100,	
           0x00000100,
           0x000100c8,
           0x00000014,
           0x00010320,
           0x00010258,
           0x00000028, 
           0x000000a6, /* Green_BGmax */
           0x00000048, /* Green_BGmin */
           0x0000009a, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000105, /* Green_Rmul */
           0x00000114, /* Green_Bmul */
           0x000000cc,	/* extreme B, B/G */	//	D50 0.68
           0x00000500,	/* extreme B, R/G */
           0x0000014c,	/* extreme R, R/G */	//	TL84
           0x00001980,	/* extreme R, B/G */
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
           0x00000034,	/* Y min  0.05*1024	*/
           0x00000010,
           0x00010100,	
           0x00000100,
           0x000100c8,
           0x00000014,
           0x00010320,
           0x00010258,
           0x00000028, 
           0x000000a6, /* Green_BGmax */
           0x00000048, /* Green_BGmin */
           0x0000009a, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000105, /* Green_Rmul */
           0x00000114, /* Green_Bmul */
           0x000000cc,	/* extreme B, B/G */	//	D50 0.68
           0x00000500,	/* extreme B, R/G */
           0x0000014c,	/* extreme R, R/G */	//	TL84
           0x00001980,	/* extreme R, B/G */
    	},
    	{
    	},
  },
},
/*af_tuning_t  af_tuning*/
{
},
