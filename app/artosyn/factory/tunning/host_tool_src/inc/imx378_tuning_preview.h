
/*---------------header of imx378 tuing-------------------------*/

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
       /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==3 */
       {
          /*aec trigger 0*/
          {
            1.000,
            4.000,
          },
          /*aec trigger 1*/
          {
            4.000,
            32.000,
          },
          /*aec trigger 2*/
          {
            32.000,
            64.000,
          },
          /*aec trigger 3*/
          {
            64.000,
            128.000,
          },
          /*aec trigger 4*/
          {
            128.000,
            351.000,
          },
       },
       /*isp_sub_module_blc_para pra[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT=3*/
       {
           /*pra 0*/
           {
               1027,
               1027,
               1027,
               1028,
               274,
               274,
               274,
               274,
           },
           /*pra 1*/
           {
               1023,/*R*/
               1023,/*B*/
               1023,/*GR*/
               1023,/*GB*/
               274,/*gain_R =ceil((2^14)./( (2^14)-blc_R)*(2^8)) */
               274,/*gain_B*/
               274,/*gain_GR*/
               274,/*gain_GB*/
           },
           /*pra 2*/
           {
               1023,/*R*/
               1022,/*B*/
               1027,/*GR*/
               1029,/*GB*/
               274,/*gain_R =ceil((2^14)./( (2^14)-blc_R)*(2^8)) */
               274,/*gain_B*/
               274,/*gain_GR*/
               274,/*gain_GB*/
           },
           /*pra 3*/
           {
               1013,
               1011,
               1022,
               1028,
               273,
               273,
               274,
               274,
           },
           /*pra 4*/
           {
               1060,
               1057,
               1079,
               1089,
               274,
               274,
               275,
               275,
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
      5, //ae count
      0, //sram mode 0 otf mode, 1 static lut table mode
      0, //trigger mode : 0 gain trigger 1 lux trigger
      {
          1, //pra0 enable
	  1, //pra1 enable
          1, //pra2 enable
	  1, //pra3 enable
          1, //pra4 enable
      },
      /*aec_trigger_t aec_trigger[MIN_TRIGGER_COUNT] MIN_TRIGGER_COUNT==5 */
      {
          /*aec trigger 0*/
          {
            1.000,
            16.000,
          },
          /*aec trigger 1*/
          {
            16.000,
            32.000,
          },
          /*aec trigger 2*/
          {
            32.000,
            64.000,
          },
          /*aec trigger 3*/
          {
            64.000,
            128.000,
          },
          /*aec trigger 4*/
          {
            128.000,
            351.000,
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
            24.000,
            24.100,
          },
          /*aec trigger 8 */
          {
            32.000,
            32.100,
          },
          /*aec trigger 9 */
          {
            48.000,
            48.100,
          },
          /*aec trigger 10 */
          {
            64.000,
            64.100,
          },
          /*aec trigger 11 */
          {
            128.000,
            128.100,
          },
          /*aec trigger 12 */
          {
            256.000,
            256.100,
          },
          /*aec trigger 13 */
          {
            512.000,
            512.100,
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
                        {23,69,64},
                        //g channel
                        {23,69,64},
                        //b channel
                        {23,69,64},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {23,69,45},
                        //g channel
                        {23,69,45},
                        //b channel
                        {23,69,45},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {23,69,45},
                        //g channel
                        {23,69,45},
                        //b channel
                        {23,69,45},
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
                        {38,114,76},
                        //g channel
                        {38,114,76},
                        //b channel
                        {38,114,76},
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
            /* para 4 */
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
            /* para 5 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {67,201,191},
                        //g channel
                        {67,201,191},
                        //b channel
                        {67,201,191},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {67,201,136},
                        //g channel
                        {67,201,136},
                        //b channel
                        {67,201,136},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {67,201,136},
                        //g channel
                        {67,201,136},
                        //b channel
                        {67,201,136},
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
                        {76,228,217},
                        //g channel
                        {76,228,217},
                        //b channel
                        {76,228,217},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {76,228,155},
                        //g channel
                        {76,228,155},
                        //b channel
                        {76,228,155},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {76,228,155},
                        //g channel
                        {76,228,155},
                        //b channel
                        {76,228,155},
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
            /* para 8 */
            {
                3,//denoise_layer
                0,//profile_enable
                /*isp_sub_module_rnr_lay lay[RNR_LAYER_COUNT_MAX][RNR_CHANNEL_COUMT]*/
                {
                    /*layer 1*/
                    {
                        //r channel
                        {129,387,371},
                        //g channel
                        {129,387,371},
                        //b channel
                        {129,387,371},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {129,387,265},
                        //g channel
                        {129,387,265},
                        //b channel
                        {129,387,265},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {129,387,265},
                        //g channel
                        {129,387,265},
                        //b channel
                        {129,387,265},
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
                        {199,597,574},
                        //g channel
                        {199,597,574},
                        //b channel
                        {199,597,574},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {199,597,410},
                        //g channel
                        {199,597,410},
                        //b channel
                        {199,597,410},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {199,597,410},
                        //g channel
                        {199,597,410},
                        //b channel
                        {199,597,410},
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
                        {241,723,696},
                        //g channel
                        {241,723,696},
                        //b channel
                        {241,723,696},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {241,723,497},
                        //g channel
                        {241,723,497},
                        //b channel
                        {241,723,497},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {241,723,497},
                        //g channel
                        {241,723,497},
                        //b channel
                        {241,723,497},
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
                        {339,1017,980},
                        //g channel
                        {339,1017,980},
                        //b channel
                        {339,1017,980},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {339,1017,700},
                        //g channel
                        {339,1017,700},
                        //b channel
                        {339,1017,700},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {339,1017,700},
                        //g channel
                        {339,1017,700},
                        //b channel
                        {339,1017,700},
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
                        {519,1557,1502},
                        //g channel
                        {519,1557,1502},
                        //b channel
                        {519,1557,1502},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {544,1632,1124},
                        //g channel
                        {544,1632,1124},
                        //b channel
                        {544,1632,1124},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {519,1557,1073},
                        //g channel
                        {519,1557,1073},
                        //b channel
                        {519,1557,1073},
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
                        {809,2427,2343},
                        //g channel
                        {809,2427,2343},
                        //b channel
                        {809,2427,2343},
                    },
                    /*layer 2*/
                    {
                        //r channel
                        {846,2538,1750},
                        //g channel
                        {846,2538,1750},
                        //b channel
                        {846,2538,1750},
                    },
                    /*layer 3*/
                    {
                        //r channel
                        {809,2427,1673},
                        //g channel
                        {809,2427,1673},
                        //b channel
                        {809,2427,1673},
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
     			2500,
     			3500,
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
						4.71303,2.29691,1.77019,1.40966,1.27916,1.24696,1.34357,1.55434,1.97921,3.23396,
						3.50311,1.99372,1.52112,1.25183,1.13855,1.12495,1.18867,1.37015,1.74948,2.59645,
						3.01714,1.81919,1.41062,1.17244,1.08074,1.07688,1.11642,1.28117,1.59692,2.31592,
						2.71795,1.70512,1.32435,1.11096,1.02998,0.99488,1.06764,1.20069,1.50730,2.14163,
						2.57795,1.65006,1.27637,1.08980,0.98972,0.99266,1.03542,1.18021,1.45518,2.06485,
						2.60669,1.63820,1.27761,1.09333,0.99810,1.00331,1.03255,1.17719,1.45121,2.07332,
						2.69542,1.69033,1.31022,1.11308,1.01794,0.98588,1.06105,1.20622,1.48046,2.13406,
						2.97976,1.78613,1.38772,1.15947,1.06888,1.05319,1.10066,1.25314,1.56542,2.26922,
						3.34558,1.96175,1.47762,1.23202,1.12368,1.11075,1.17259,1.36096,1.68701,2.55054,
						4.31490,2.25581,1.68451,1.36613,1.24168,1.18355,1.29538,1.48690,1.91223,2.95513,
						4.48229,2.23687,1.75008,1.38663,1.27084,1.23723,1.32541,1.52644,1.96365,3.13859,
						3.40258,1.96511,1.49938,1.24623,1.13302,1.12419,1.18155,1.38123,1.70903,2.61614,
						2.94884,1.78877,1.39730,1.16059,1.07861,1.06576,1.11212,1.27256,1.58511,2.29574,
						2.64794,1.68395,1.31274,1.10404,1.03150,0.99141,1.07200,1.20122,1.48905,2.12827,
						2.55068,1.63092,1.26948,1.09212,0.99161,0.98700,1.04105,1.18013,1.44574,2.06239,
						2.51124,1.62828,1.26530,1.09004,0.99870,1.00363,1.02807,1.17523,1.44625,2.02850,
						2.65055,1.66986,1.30250,1.10526,1.02017,0.98310,1.06651,1.19767,1.47566,2.11011,
						2.83260,1.77316,1.36314,1.15595,1.06497,1.06144,1.09469,1.25434,1.55165,2.23843,
						3.28493,1.92738,1.47697,1.21696,1.12261,1.10478,1.17275,1.35537,1.68715,2.51688,
						4.07562,2.22687,1.63821,1.35451,1.22873,1.20238,1.29460,1.46755,1.91280,2.86554,
						4.39925,2.26571,1.71102,1.38964,1.25780,1.26498,1.33905,1.53391,1.97143,3.15473,
						3.41476,1.96574,1.51615,1.25373,1.14388,1.12134,1.19578,1.38672,1.72070,2.60053,
						2.93895,1.79104,1.39544,1.15825,1.07781,1.07164,1.11720,1.26919,1.59320,2.30558,
						2.66658,1.68299,1.31848,1.10477,1.03017,0.99855,1.07604,1.20843,1.49609,2.11862,
						2.57789,1.62621,1.27927,1.09579,0.99070,0.98735,1.04130,1.18152,1.45257,2.06577,
						2.51547,1.62972,1.26582,1.08902,0.99687,0.99526,1.03287,1.17701,1.45162,2.05736,
						2.66244,1.66271,1.30912,1.11737,1.01900,0.98743,1.06893,1.18859,1.49194,2.10388,
						2.83189,1.79653,1.36240,1.16123,1.07526,1.06393,1.09990,1.26415,1.55877,2.27105,
						3.27144,1.93874,1.47259,1.24324,1.12032,1.11791,1.16985,1.35194,1.69954,2.50980,
						4.06660,2.21447,1.67877,1.35139,1.25219,1.21438,1.31028,1.52435,1.88603,3.06201
					},
				},
				/* para 2 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
						4.71303,2.29691,1.77019,1.40966,1.27916,1.24696,1.34357,1.55434,1.97921,3.23396,
						3.50311,1.99372,1.52112,1.25183,1.13855,1.12495,1.18867,1.37015,1.74948,2.59645,
						3.01714,1.81919,1.41062,1.17244,1.08074,1.07688,1.11642,1.28117,1.59692,2.31592,
						2.71795,1.70512,1.32435,1.11096,1.02998,0.99488,1.06764,1.20069,1.50730,2.14163,
						2.57795,1.65006,1.27637,1.08980,0.98972,0.99266,1.03542,1.18021,1.45518,2.06485,
						2.60669,1.63820,1.27761,1.09333,0.99810,1.00331,1.03255,1.17719,1.45121,2.07332,
						2.69542,1.69033,1.31022,1.11308,1.01794,0.98588,1.06105,1.20622,1.48046,2.13406,
						2.97976,1.78613,1.38772,1.15947,1.06888,1.05319,1.10066,1.25314,1.56542,2.26922,
						3.34558,1.96175,1.47762,1.23202,1.12368,1.11075,1.17259,1.36096,1.68701,2.55054,
						4.31490,2.25581,1.68451,1.36613,1.24168,1.18355,1.29538,1.48690,1.91223,2.95513,
						4.48229,2.23687,1.75008,1.38663,1.27084,1.23723,1.32541,1.52644,1.96365,3.13859,
						3.40258,1.96511,1.49938,1.24623,1.13302,1.12419,1.18155,1.38123,1.70903,2.61614,
						2.94884,1.78877,1.39730,1.16059,1.07861,1.06576,1.11212,1.27256,1.58511,2.29574,
						2.64794,1.68395,1.31274,1.10404,1.03150,0.99141,1.07200,1.20122,1.48905,2.12827,
						2.55068,1.63092,1.26948,1.09212,0.99161,0.98700,1.04105,1.18013,1.44574,2.06239,
						2.51124,1.62828,1.26530,1.09004,0.99870,1.00363,1.02807,1.17523,1.44625,2.02850,
						2.65055,1.66986,1.30250,1.10526,1.02017,0.98310,1.06651,1.19767,1.47566,2.11011,
						2.83260,1.77316,1.36314,1.15595,1.06497,1.06144,1.09469,1.25434,1.55165,2.23843,
						3.28493,1.92738,1.47697,1.21696,1.12261,1.10478,1.17275,1.35537,1.68715,2.51688,
						4.07562,2.22687,1.63821,1.35451,1.22873,1.20238,1.29460,1.46755,1.91280,2.86554,
						4.39925,2.26571,1.71102,1.38964,1.25780,1.26498,1.33905,1.53391,1.97143,3.15473,
						3.41476,1.96574,1.51615,1.25373,1.14388,1.12134,1.19578,1.38672,1.72070,2.60053,
						2.93895,1.79104,1.39544,1.15825,1.07781,1.07164,1.11720,1.26919,1.59320,2.30558,
						2.66658,1.68299,1.31848,1.10477,1.03017,0.99855,1.07604,1.20843,1.49609,2.11862,
						2.57789,1.62621,1.27927,1.09579,0.99070,0.98735,1.04130,1.18152,1.45257,2.06577,
						2.51547,1.62972,1.26582,1.08902,0.99687,0.99526,1.03287,1.17701,1.45162,2.05736,
						2.66244,1.66271,1.30912,1.11737,1.01900,0.98743,1.06893,1.18859,1.49194,2.10388,
						2.83189,1.79653,1.36240,1.16123,1.07526,1.06393,1.09990,1.26415,1.55877,2.27105,
						3.27144,1.93874,1.47259,1.24324,1.12032,1.11791,1.16985,1.35194,1.69954,2.50980,
						4.06660,2.21447,1.67877,1.35139,1.25219,1.21438,1.31028,1.52435,1.88603,3.06201
					},
				},
				/* para 3 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
						4.71303,2.29691,1.77019,1.40966,1.27916,1.24696,1.34357,1.55434,1.97921,3.23396,
						3.50311,1.99372,1.52112,1.25183,1.13855,1.12495,1.18867,1.37015,1.74948,2.59645,
						3.01714,1.81919,1.41062,1.17244,1.08074,1.07688,1.11642,1.28117,1.59692,2.31592,
						2.71795,1.70512,1.32435,1.11096,1.02998,0.99488,1.06764,1.20069,1.50730,2.14163,
						2.57795,1.65006,1.27637,1.08980,0.98972,0.99266,1.03542,1.18021,1.45518,2.06485,
						2.60669,1.63820,1.27761,1.09333,0.99810,1.00331,1.03255,1.17719,1.45121,2.07332,
						2.69542,1.69033,1.31022,1.11308,1.01794,0.98588,1.06105,1.20622,1.48046,2.13406,
						2.97976,1.78613,1.38772,1.15947,1.06888,1.05319,1.10066,1.25314,1.56542,2.26922,
						3.34558,1.96175,1.47762,1.23202,1.12368,1.11075,1.17259,1.36096,1.68701,2.55054,
						4.31490,2.25581,1.68451,1.36613,1.24168,1.18355,1.29538,1.48690,1.91223,2.95513,
						4.48229,2.23687,1.75008,1.38663,1.27084,1.23723,1.32541,1.52644,1.96365,3.13859,
						3.40258,1.96511,1.49938,1.24623,1.13302,1.12419,1.18155,1.38123,1.70903,2.61614,
						2.94884,1.78877,1.39730,1.16059,1.07861,1.06576,1.11212,1.27256,1.58511,2.29574,
						2.64794,1.68395,1.31274,1.10404,1.03150,0.99141,1.07200,1.20122,1.48905,2.12827,
						2.55068,1.63092,1.26948,1.09212,0.99161,0.98700,1.04105,1.18013,1.44574,2.06239,
						2.51124,1.62828,1.26530,1.09004,0.99870,1.00363,1.02807,1.17523,1.44625,2.02850,
						2.65055,1.66986,1.30250,1.10526,1.02017,0.98310,1.06651,1.19767,1.47566,2.11011,
						2.83260,1.77316,1.36314,1.15595,1.06497,1.06144,1.09469,1.25434,1.55165,2.23843,
						3.28493,1.92738,1.47697,1.21696,1.12261,1.10478,1.17275,1.35537,1.68715,2.51688,
						4.07562,2.22687,1.63821,1.35451,1.22873,1.20238,1.29460,1.46755,1.91280,2.86554,
						4.39925,2.26571,1.71102,1.38964,1.25780,1.26498,1.33905,1.53391,1.97143,3.15473,
						3.41476,1.96574,1.51615,1.25373,1.14388,1.12134,1.19578,1.38672,1.72070,2.60053,
						2.93895,1.79104,1.39544,1.15825,1.07781,1.07164,1.11720,1.26919,1.59320,2.30558,
						2.66658,1.68299,1.31848,1.10477,1.03017,0.99855,1.07604,1.20843,1.49609,2.11862,
						2.57789,1.62621,1.27927,1.09579,0.99070,0.98735,1.04130,1.18152,1.45257,2.06577,
						2.51547,1.62972,1.26582,1.08902,0.99687,0.99526,1.03287,1.17701,1.45162,2.05736,
						2.66244,1.66271,1.30912,1.11737,1.01900,0.98743,1.06893,1.18859,1.49194,2.10388,
						2.83189,1.79653,1.36240,1.16123,1.07526,1.06393,1.09990,1.26415,1.55877,2.27105,
						3.27144,1.93874,1.47259,1.24324,1.12032,1.11791,1.16985,1.35194,1.69954,2.50980,
						4.06660,2.21447,1.67877,1.35139,1.25219,1.21438,1.31028,1.52435,1.88603,3.06201
					},
				},
				/* para 4 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
						4.71303,2.29691,1.77019,1.40966,1.27916,1.24696,1.34357,1.55434,1.97921,3.23396,
						3.50311,1.99372,1.52112,1.25183,1.13855,1.12495,1.18867,1.37015,1.74948,2.59645,
						3.01714,1.81919,1.41062,1.17244,1.08074,1.07688,1.11642,1.28117,1.59692,2.31592,
						2.71795,1.70512,1.32435,1.11096,1.02998,0.99488,1.06764,1.20069,1.50730,2.14163,
						2.57795,1.65006,1.27637,1.08980,0.98972,0.99266,1.03542,1.18021,1.45518,2.06485,
						2.60669,1.63820,1.27761,1.09333,0.99810,1.00331,1.03255,1.17719,1.45121,2.07332,
						2.69542,1.69033,1.31022,1.11308,1.01794,0.98588,1.06105,1.20622,1.48046,2.13406,
						2.97976,1.78613,1.38772,1.15947,1.06888,1.05319,1.10066,1.25314,1.56542,2.26922,
						3.34558,1.96175,1.47762,1.23202,1.12368,1.11075,1.17259,1.36096,1.68701,2.55054,
						4.31490,2.25581,1.68451,1.36613,1.24168,1.18355,1.29538,1.48690,1.91223,2.95513,
						4.48229,2.23687,1.75008,1.38663,1.27084,1.23723,1.32541,1.52644,1.96365,3.13859,
						3.40258,1.96511,1.49938,1.24623,1.13302,1.12419,1.18155,1.38123,1.70903,2.61614,
						2.94884,1.78877,1.39730,1.16059,1.07861,1.06576,1.11212,1.27256,1.58511,2.29574,
						2.64794,1.68395,1.31274,1.10404,1.03150,0.99141,1.07200,1.20122,1.48905,2.12827,
						2.55068,1.63092,1.26948,1.09212,0.99161,0.98700,1.04105,1.18013,1.44574,2.06239,
						2.51124,1.62828,1.26530,1.09004,0.99870,1.00363,1.02807,1.17523,1.44625,2.02850,
						2.65055,1.66986,1.30250,1.10526,1.02017,0.98310,1.06651,1.19767,1.47566,2.11011,
						2.83260,1.77316,1.36314,1.15595,1.06497,1.06144,1.09469,1.25434,1.55165,2.23843,
						3.28493,1.92738,1.47697,1.21696,1.12261,1.10478,1.17275,1.35537,1.68715,2.51688,
						4.07562,2.22687,1.63821,1.35451,1.22873,1.20238,1.29460,1.46755,1.91280,2.86554,
						4.39925,2.26571,1.71102,1.38964,1.25780,1.26498,1.33905,1.53391,1.97143,3.15473,
						3.41476,1.96574,1.51615,1.25373,1.14388,1.12134,1.19578,1.38672,1.72070,2.60053,
						2.93895,1.79104,1.39544,1.15825,1.07781,1.07164,1.11720,1.26919,1.59320,2.30558,
						2.66658,1.68299,1.31848,1.10477,1.03017,0.99855,1.07604,1.20843,1.49609,2.11862,
						2.57789,1.62621,1.27927,1.09579,0.99070,0.98735,1.04130,1.18152,1.45257,2.06577,
						2.51547,1.62972,1.26582,1.08902,0.99687,0.99526,1.03287,1.17701,1.45162,2.05736,
						2.66244,1.66271,1.30912,1.11737,1.01900,0.98743,1.06893,1.18859,1.49194,2.10388,
						2.83189,1.79653,1.36240,1.16123,1.07526,1.06393,1.09990,1.26415,1.55877,2.27105,
						3.27144,1.93874,1.47259,1.24324,1.12032,1.11791,1.16985,1.35194,1.69954,2.50980,
						4.06660,2.21447,1.67877,1.35139,1.25219,1.21438,1.31028,1.52435,1.88603,3.06201
					},
				},
				/* para 5 */
				{
					0.900000,//stength,register: [07:00]lsc_snr1_man_factor = floor(strength * 2^7) ,address:0x64804C40
					1,  //lsc_man_mode: [16]lsc_snr1_man_mode = lsc_man_mode,address:0x64804C40
					{
						4.71303,2.29691,1.77019,1.40966,1.27916,1.24696,1.34357,1.55434,1.97921,3.23396,
						3.50311,1.99372,1.52112,1.25183,1.13855,1.12495,1.18867,1.37015,1.74948,2.59645,
						3.01714,1.81919,1.41062,1.17244,1.08074,1.07688,1.11642,1.28117,1.59692,2.31592,
						2.71795,1.70512,1.32435,1.11096,1.02998,0.99488,1.06764,1.20069,1.50730,2.14163,
						2.57795,1.65006,1.27637,1.08980,0.98972,0.99266,1.03542,1.18021,1.45518,2.06485,
						2.60669,1.63820,1.27761,1.09333,0.99810,1.00331,1.03255,1.17719,1.45121,2.07332,
						2.69542,1.69033,1.31022,1.11308,1.01794,0.98588,1.06105,1.20622,1.48046,2.13406,
						2.97976,1.78613,1.38772,1.15947,1.06888,1.05319,1.10066,1.25314,1.56542,2.26922,
						3.34558,1.96175,1.47762,1.23202,1.12368,1.11075,1.17259,1.36096,1.68701,2.55054,
						4.31490,2.25581,1.68451,1.36613,1.24168,1.18355,1.29538,1.48690,1.91223,2.95513,
						4.48229,2.23687,1.75008,1.38663,1.27084,1.23723,1.32541,1.52644,1.96365,3.13859,
						3.40258,1.96511,1.49938,1.24623,1.13302,1.12419,1.18155,1.38123,1.70903,2.61614,
						2.94884,1.78877,1.39730,1.16059,1.07861,1.06576,1.11212,1.27256,1.58511,2.29574,
						2.64794,1.68395,1.31274,1.10404,1.03150,0.99141,1.07200,1.20122,1.48905,2.12827,
						2.55068,1.63092,1.26948,1.09212,0.99161,0.98700,1.04105,1.18013,1.44574,2.06239,
						2.51124,1.62828,1.26530,1.09004,0.99870,1.00363,1.02807,1.17523,1.44625,2.02850,
						2.65055,1.66986,1.30250,1.10526,1.02017,0.98310,1.06651,1.19767,1.47566,2.11011,
						2.83260,1.77316,1.36314,1.15595,1.06497,1.06144,1.09469,1.25434,1.55165,2.23843,
						3.28493,1.92738,1.47697,1.21696,1.12261,1.10478,1.17275,1.35537,1.68715,2.51688,
						4.07562,2.22687,1.63821,1.35451,1.22873,1.20238,1.29460,1.46755,1.91280,2.86554,
						4.39925,2.26571,1.71102,1.38964,1.25780,1.26498,1.33905,1.53391,1.97143,3.15473,
						3.41476,1.96574,1.51615,1.25373,1.14388,1.12134,1.19578,1.38672,1.72070,2.60053,
						2.93895,1.79104,1.39544,1.15825,1.07781,1.07164,1.11720,1.26919,1.59320,2.30558,
						2.66658,1.68299,1.31848,1.10477,1.03017,0.99855,1.07604,1.20843,1.49609,2.11862,
						2.57789,1.62621,1.27927,1.09579,0.99070,0.98735,1.04130,1.18152,1.45257,2.06577,
						2.51547,1.62972,1.26582,1.08902,0.99687,0.99526,1.03287,1.17701,1.45162,2.05736,
						2.66244,1.66271,1.30912,1.11737,1.01900,0.98743,1.06893,1.18859,1.49194,2.10388,
						2.83189,1.79653,1.36240,1.16123,1.07526,1.06393,1.09990,1.26415,1.55877,2.27105,
						3.27144,1.93874,1.47259,1.24324,1.12032,1.11791,1.16985,1.35194,1.69954,2.50980,
						4.06660,2.21447,1.67877,1.35139,1.25219,1.21438,1.31028,1.52435,1.88603,3.06201
					},
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
        1,//ae count
        4,//awb count
        1,//trigger_mode : 0 gain trigger 1 lux trigger
      /* aec trigger */
      {
        	/*trigger 0*/
        	{
        		0,
        		405,
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
        		2800,
        		3600,
        	},
        	/*trigger 1*/
        	{
        		3800,
        		4500,
        	},
        	/*trigger 2*/
        	{
        		4800,
        		6200,
        	},
        	/*trigger 3*/
        	{
        		6500,
        		7000,
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
                     0.8090, 0.2976, -0.1066,
                     -0.4549, 1.6545, -0.1996,
                     -0.2226, -0.4882, 1.7108,
                },
                /* ccm tl84 matrix */
                {
                     1.5414, -0.3964, -0.1450,
                     -0.4211, 1.6473, -0.2262,
                     -0.0396, -0.6837, 1.7232,
                },
                /* ccm d50 matrix */
                {
                     1.5321, -0.3093, -0.2228,
                     -0.3029, 1.5856, -0.2827,
                     -0.0026, -1.0527, 2.0553,
                },
                /* ccm d65 matrix */
                {
                     1.8041, -0.8115, 0.0073,
                     -0.3216, 1.6561, -0.3345,
                     -0.0027, -0.8324, 1.8351,
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
            260.000,
            340.000,
          },
          /*aec trigger 3*/
          {
            360.000,
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
          /* indoor */
          {
                  0,  51, 103, 153, 202, 247, 288, 326, 360, 393, 426, 454, 482, 511, 541, 571, 599, 626, 654, 680, 705, 732, 757, 780, 807, 829, 854,
                878, 900, 926, 947, 971, 989,1008,1023,1042,1060,1076,1094,1112,1130,1149,1167,1182,1201,1217,1233,1248,1266,1281,1297,1314,1329,1343,
               1361,1376,1390,1404,1421,1434,1446,1458,1468,1481,1492,1503,1516,1526,1537,1550,1561,1572,1583,1596,1607,1617,1628,1638,1649,1659,1669,
               1680,1690,1699,1711,1721,1730,1740,1752,1761,1771,1783,1792,1802,1811,1823,1833,1842,1853,1863,1872,1883,1892,1902,1912,1922,1929,1940,
               1947,1955,1962,1974,1983,1991,2000,2004,2013,2022,2031,2040,2045,2055,2064,2069,2079,2089,2094,2103,2112,2121,2125,2134,2141,2153,2160,
               2167,2176,2183,2191,2199,2206,2214,2223,2231,2238,2245,2253,2260,2267,2274,2282,2289,2296,2303,2311,2318,2325,2332,2339,2346,2353,2360,
               2367,2374,2381,2388,2395,2401,2408,2415,2422,2429,2435,2442,2449,2456,2462,2469,2476,2482,2489,2495,2502,2508,2515,2521,2528,2534,2541,
               2547,2554,2560,2566,2573,2579,2585,2592,2598,2604,2611,2617,2623,2629,2635,2642,2648,2654,2660,2666,2672,2678,2684,2690,2696,2703,2709,
               2715,2720,2726,2732,2738,2744,2750,2756,2762,2768,2774,2779,2785,2791,2797,2803,2808,2814,2820,2826,2831,2837,2843,2849,2854,2860,2865,
               2871,2877,2882,2888,2894,2899,2905,2910,2916,2921,2927,2932,2938,2943,2949,2954,2960,2965,2971,2976,2981,2987,2992,2997,3003,3008,3014,
               3019,3024,3030,3035,3040,3045,3051,3056,3061,3066,3072,3077,3082,3087,3092,3098,3103,3108,3113,3118,3123,3129,3134,3139,3144,3149,3154,
               3159,3164,3169,3174,3179,3184,3189,3194,3199,3204,3209,3214,3219,3224,3229,3234,3239,3244,3249,3254,3259,3264,3268,3273,3278,3283,3288,
               3293,3298,3302,3307,3312,3317,3322,3326,3331,3336,3341,3346,3350,3355,3360,3364,3369,3374,3379,3383,3388,3393,3397,3402,3407,3411,3416,
               3421,3425,3430,3435,3439,3444,3448,3453,3458,3462,3467,3471,3476,3480,3485,3490,3494,3499,3503,3508,3512,3517,3521,3526,3530,3535,3539,
               3544,3548,3552,3557,3561,3566,3570,3575,3579,3584,3588,3592,3597,3601,3605,3610,3614,3619,3623,3627,3632,3636,3640,3645,3649,3653,3658,
               3662,3666,3671,3675,3679,3683,3688,3692,3696,3700,3705,3709,3713,3717,3722,3726,3730,3734,3739,3743,3747,3751,3755,3760,3764,3768,3772,
               3776,3780,3785,3789,3793,3797,3801,3805,3809,3814,3818,3822,3826,3830,3834,3838,3842,3846,3850,3854,3859,3863,3867,3871,3875,3879,3883,
               3887,3891,3895,3899,3903,3907,3911,3915,3919,3923,3927,3931,3935,3939,3943,3947,3951,3955,3959,3963,3967,3971,3975,3978,3982,3986,3990,
               3994,3998,4002,4006,4010,4014,4018,4021,4025,4029,4033,4037,4041,4045,4049,4052,4056,4060,4064,4068,4072,4075,4079,4083,4087,4091,4095,
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
       5,
       /*trigger mode : 0 gain trigger 1 lux trigger*/
       0,
       /* aec trigger */
       {
          /* aec trigger 1 */
          {
            1.000,
            4.000,
          },
          /* aec trigger 2 */
          {
            4.100,
            8.000,
          },
          /* aec trigger 3 */
          {
            8.100,
            12.000,
          },
          /* aec trigger 4 */
          {
            12.100,
            16.000,
          },
          /* aec trigger 5 */
          {
            16.100,
            24.000,
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
               40,  //sharpen_pos
               50,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 20, 40, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 2 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               50,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               110, //limit_max
               100, //limit_min
               0, 25, 50, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 3 */
           {
               {
                   58,127,58,//gaussian(1,1:3)
                   127,279,127,//gaussian(2,1:3)
                   58,127,58,//gaussian(3,1:3)
               },
               40,  //sharpen_pos
               50,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 30, 60, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 4 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               40,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 40, 70, 200, //edge_th 0 ~3
               8, 100, 400, 1000, //luma_th 0 ~3
           },
           /* parameter 5 */
           {
               {
                   76,126,76,//gaussian(1,1:3)
                   126,209,126,//gaussian(2,1:3)
                   76,126,76,//gaussian(3,1:3)
               },
               30,  //sharpen_pos
               40,  //sharpen_fu
               2,  //noise_th
               0,  //order_en
               100, //limit_max
               100, //limit_min
               0, 50, 80, 200, //edge_th 0 ~3
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
        457,
        /* ev0_count */
        457,
        /* ev2_count */
        457,
        /* fix_fps_index */
        30,
        /* enable_isp_digital_gain */
        0,
        /* max_sensor_gain */
        351,
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
          {256,  2272  },        /* Gain= 1.000000 Exposure Index= 250 */
          {256,  2341  },        /* Gain= 1.000000 Exposure Index= 251 */
          {256,  2412  },        /* Gain= 1.000000 Exposure Index= 252 */
          {256,  2485  },        /* Gain= 1.000000 Exposure Index= 253 */
          {256,  2560  },        /* Gain= 1.000000 Exposure Index= 254 */
          {256,  2637  },        /* Gain= 1.000000 Exposure Index= 255 */
          {256,  2717  },        /* Gain= 1.000000 Exposure Index= 256 */
          {256,  2799  },        /* Gain= 1.000000 Exposure Index= 257 */
          {256,  2883  },        /* Gain= 1.000000 Exposure Index= 258 */
          {256,  2970  },        /* Gain= 1.000000 Exposure Index= 259 */
          {256,  3060  },        /* Gain= 1.000000 Exposure Index= 260 */
          {259,  3125  },        /* Gain= 1.011719 Exposure Index= 261 */
          {267,  3125  },        /* Gain= 1.042969 Exposure Index= 262 */
          {276,  3125  },        /* Gain= 1.078125 Exposure Index= 263 */
          {285,  3125  },        /* Gain= 1.113281 Exposure Index= 264 */
          {294,  3125  },        /* Gain= 1.148438 Exposure Index= 265 */
          {303,  3125  },        /* Gain= 1.183594 Exposure Index= 266 */
          {313,  3125  },        /* Gain= 1.222656 Exposure Index= 267 */
          {323,  3125  },        /* Gain= 1.261719 Exposure Index= 268 */
          {333,  3125  },        /* Gain= 1.300781 Exposure Index= 269 */
          {343,  3125  },        /* Gain= 1.339844 Exposure Index= 270 */
          {354,  3125  },        /* Gain= 1.382813 Exposure Index= 271 */
          {365,  3125  },        /* Gain= 1.425781 Exposure Index= 272 */
          {376,  3125  },        /* Gain= 1.468750 Exposure Index= 273 */
          {388,  3125  },        /* Gain= 1.515625 Exposure Index= 274 */
          {400,  3125  },        /* Gain= 1.562500 Exposure Index= 275 */
          {412,  3125  },        /* Gain= 1.609375 Exposure Index= 276 */
          {425,  3125  },        /* Gain= 1.660156 Exposure Index= 277 */
          {438,  3125  },        /* Gain= 1.710938 Exposure Index= 278 */
          {452,  3125  },        /* Gain= 1.765625 Exposure Index= 279 */
          {466,  3125  },        /* Gain= 1.820313 Exposure Index= 280 */
          {480,  3125  },        /* Gain= 1.875000 Exposure Index= 281 */
          {495,  3125  },        /* Gain= 1.933594 Exposure Index= 282 */
          {510,  3125  },        /* Gain= 1.992188 Exposure Index= 283 */
          {526,  3125  },        /* Gain= 2.054688 Exposure Index= 284 */
          {542,  3125  },        /* Gain= 2.117188 Exposure Index= 285 */
          {559,  3125  },        /* Gain= 2.183594 Exposure Index= 286 */
          {576,  3125  },        /* Gain= 2.250000 Exposure Index= 287 */
          {594,  3125  },        /* Gain= 2.320313 Exposure Index= 288 */
          {612,  3125  },        /* Gain= 2.390625 Exposure Index= 289 */
          {631,  3125  },        /* Gain= 2.464844 Exposure Index= 290 */
          {650,  3125  },        /* Gain= 2.539063 Exposure Index= 291 */
          {670,  3125  },        /* Gain= 2.617188 Exposure Index= 292 */
          {691,  3125  },        /* Gain= 2.699219 Exposure Index= 293 */
          {712,  3125  },        /* Gain= 2.781250 Exposure Index= 294 */
          {734,  3125  },        /* Gain= 2.867188 Exposure Index= 295 */
          {757,  3125  },        /* Gain= 2.957031 Exposure Index= 296 */
          {780,  3125  },        /* Gain= 3.046875 Exposure Index= 297 */
          {804,  3125  },        /* Gain= 3.140625 Exposure Index= 298 */
          {829,  3125  },        /* Gain= 3.238281 Exposure Index= 299 */
          {854,  3125  },        /* Gain= 3.335938 Exposure Index= 300 */
          {880,  3125  },        /* Gain= 3.437500 Exposure Index= 301 */
          {907,  3125  },        /* Gain= 3.542969 Exposure Index= 302 */
          {935,  3125  },        /* Gain= 3.652344 Exposure Index= 303 */
          {964,  3125  },        /* Gain= 3.765625 Exposure Index= 304 */
          {993,  3125  },        /* Gain= 3.878906 Exposure Index= 305 */
          {1023,  3125  },        /* Gain= 3.996094 Exposure Index= 306 */
          {1054,  3125  },        /* Gain= 4.117188 Exposure Index= 307 */
          {1086,  3125  },        /* Gain= 4.242188 Exposure Index= 308 */
          {1119,  3125  },        /* Gain= 4.371094 Exposure Index= 309 */
          {1153,  3125  },        /* Gain= 4.503906 Exposure Index= 310 */
          {1188,  3125  },        /* Gain= 4.640625 Exposure Index= 311 */
          {1224,  3125  },        /* Gain= 4.781250 Exposure Index= 312 */
          {1261,  3125  },        /* Gain= 4.925781 Exposure Index= 313 */
          {1299,  3125  },        /* Gain= 5.074219 Exposure Index= 314 */
          {1338,  3125  },        /* Gain= 5.226563 Exposure Index= 315 */
          {1379,  3125  },        /* Gain= 5.386719 Exposure Index= 316 */
          {1421,  3125  },        /* Gain= 5.550781 Exposure Index= 317 */
          {1464,  3125  },        /* Gain= 5.718750 Exposure Index= 318 */
          {1508,  3125  },        /* Gain= 5.890625 Exposure Index= 319 */
          {1554,  3125  },        /* Gain= 6.070313 Exposure Index= 320 */
          {1601,  3125  },        /* Gain= 6.253906 Exposure Index= 321 */
          {1650,  3125  },        /* Gain= 6.445313 Exposure Index= 322 */
          {1700,  3125  },        /* Gain= 6.640625 Exposure Index= 323 */
          {1751,  3125  },        /* Gain= 6.839844 Exposure Index= 324 */
          {1804,  3125  },        /* Gain= 7.046875 Exposure Index= 325 */
          {1859,  3125  },        /* Gain= 7.261719 Exposure Index= 326 */
          {1915,  3125  },        /* Gain= 7.480469 Exposure Index= 327 */
          {1973,  3125  },        /* Gain= 7.707031 Exposure Index= 328 */
          {2033,  3125  },        /* Gain= 7.941406 Exposure Index= 329 */
          {2094,  3125  },        /* Gain= 8.179688 Exposure Index= 330 */
          {2157,  3125  },        /* Gain= 8.425781 Exposure Index= 331 */
          {2222,  3125  },        /* Gain= 8.679688 Exposure Index= 332 */
          {2289,  3125  },        /* Gain= 8.941406 Exposure Index= 333 */
          {2358,  3125  },        /* Gain= 9.210938 Exposure Index= 334 */
          {2429,  3125  },        /* Gain= 9.488281 Exposure Index= 335 */
          {2502,  3125  },        /* Gain= 9.773438 Exposure Index= 336 */
          {2578,  3125  },        /* Gain= 10.070313 Exposure Index= 337 */
          {2656,  3125  },        /* Gain= 10.375000 Exposure Index= 338 */
          {2736,  3125  },        /* Gain= 10.687500 Exposure Index= 339 */
          {2819,  3125  },        /* Gain= 11.011719 Exposure Index= 340 */
          {2904,  3125  },        /* Gain= 11.343750 Exposure Index= 341 */
          {2992,  3125  },        /* Gain= 11.687500 Exposure Index= 342 */
          {3082,  3125  },        /* Gain= 12.039063 Exposure Index= 343 */
          {3175,  3125  },        /* Gain= 12.402344 Exposure Index= 344 */
          {3271,  3125  },        /* Gain= 12.777344 Exposure Index= 345 */
          {3370,  3125  },        /* Gain= 13.164063 Exposure Index= 346 */
          {3472,  3125  },        /* Gain= 13.562500 Exposure Index= 347 */
          {3577,  3125  },        /* Gain= 13.972656 Exposure Index= 348 */
          {3685,  3125  },        /* Gain= 14.394531 Exposure Index= 349 */
          {3796,  3125  },        /* Gain= 14.828125 Exposure Index= 350 */
          {3910,  3125  },        /* Gain= 15.273438 Exposure Index= 351 */
          {4028,  3125  },        /* Gain= 15.734375 Exposure Index= 352 */
          {4149,  3125  },        /* Gain= 16.207031 Exposure Index= 353 */
          {4274,  3125  },        /* Gain= 16.695313 Exposure Index= 354 */
          {4403,  3125  },        /* Gain= 17.199219 Exposure Index= 355 */
          {4536,  3125  },        /* Gain= 17.718750 Exposure Index= 356 */
          {4673,  3125  },        /* Gain= 18.253906 Exposure Index= 357 */
          {4814,  3125  },        /* Gain= 18.804688 Exposure Index= 358 */
          {4959,  3125  },        /* Gain= 19.371094 Exposure Index= 359 */
          {5108,  3125  },        /* Gain= 19.953125 Exposure Index= 360 */
          {5262,  3125  },        /* Gain= 20.554688 Exposure Index= 361 */
          {5420,  3125  },        /* Gain= 21.171875 Exposure Index= 362 */
          {5583,  3125  },        /* Gain= 21.808594 Exposure Index= 363 */
          {5751,  3125  },        /* Gain= 22.464844 Exposure Index= 364 */
          {5924,  3125  },        /* Gain= 23.140625 Exposure Index= 365 */
          {6102,  3125  },        /* Gain= 23.835938 Exposure Index= 366 */
          {6286,  3125  },        /* Gain= 24.554688 Exposure Index= 367 */
          {6475,  3125  },        /* Gain= 25.292969 Exposure Index= 368 */
          {6670,  3125  },        /* Gain= 26.054688 Exposure Index= 369 */
          {6871,  3125  },        /* Gain= 26.839844 Exposure Index= 370 */
          {7078,  3125  },        /* Gain= 27.648438 Exposure Index= 371 */
          {7291,  3125  },        /* Gain= 28.480469 Exposure Index= 372 */
          {7510,  3125  },        /* Gain= 29.335938 Exposure Index= 373 */
          {7736,  3125  },        /* Gain= 30.218750 Exposure Index= 374 */
          {7969,  3125  },        /* Gain= 31.128906 Exposure Index= 375 */
          {8209,  3125  },        /* Gain= 32.066406 Exposure Index= 376 */
          {8456,  3125  },        /* Gain= 33.031250 Exposure Index= 377 */
          {8710,  3125  },        /* Gain= 34.023438 Exposure Index= 378 */
          {8972,  3125  },        /* Gain= 35.046875 Exposure Index= 379 */
          {9242,  3125  },        /* Gain= 36.101563 Exposure Index= 380 */
          {9520,  3125  },        /* Gain= 37.187500 Exposure Index= 381 */
          {9806,  3125  },        /* Gain= 38.304688 Exposure Index= 382 */
          {10101,  3125  },        /* Gain= 39.457031 Exposure Index= 383 */
          {10405,  3125  },        /* Gain= 40.644531 Exposure Index= 384 */
          {10718,  3125  },        /* Gain= 41.867188 Exposure Index= 385 */
          {11040,  3125  },        /* Gain= 43.125000 Exposure Index= 386 */
          {11372,  3125  },        /* Gain= 44.421875 Exposure Index= 387 */
          {11714,  3125  },        /* Gain= 45.757813 Exposure Index= 388 */
          {12066,  3125  },        /* Gain= 47.132813 Exposure Index= 389 */
          {12428,  3125  },        /* Gain= 48.546875 Exposure Index= 390 */
          {12801,  3125  },        /* Gain= 50.003906 Exposure Index= 391 */
          {13186,  3125  },        /* Gain= 51.507813 Exposure Index= 392 */
          {13582,  3125  },        /* Gain= 53.054688 Exposure Index= 393 */
          {13990,  3125  },        /* Gain= 54.648438 Exposure Index= 394 */
          {14410,  3125  },        /* Gain= 56.289063 Exposure Index= 395 */
          {14843,  3125  },        /* Gain= 57.980469 Exposure Index= 396 */
          {15289,  3125  },        /* Gain= 59.722656 Exposure Index= 397 */
          {15748,  3125  },        /* Gain= 61.515625 Exposure Index= 398 */
          {16221,  3125  },        /* Gain= 63.363281 Exposure Index= 399 */
          {16708,  3125  },        /* Gain= 65.265625 Exposure Index= 400 */
          {17210,  3125  },        /* Gain= 67.226563 Exposure Index= 401 */
          {17727,  3125  },        /* Gain= 69.246094 Exposure Index= 402 */
          {18259,  3125  },        /* Gain= 71.324219 Exposure Index= 403 */
          {18807,  3125  },        /* Gain= 73.464844 Exposure Index= 404 */
          {19372,  3125  },        /* Gain= 75.671875 Exposure Index= 405 */
          {19954,  3125  },        /* Gain= 77.945313 Exposure Index= 406 */
          {20553,  3125  },        /* Gain= 80.285156 Exposure Index= 407 */
          {21170,  3125  },        /* Gain= 82.695313 Exposure Index= 408 */
          {21806,  3125  },        /* Gain= 85.179688 Exposure Index= 409 */
          {22461,  3125  },        /* Gain= 87.738281 Exposure Index= 410 */
          {23135,  3125  },        /* Gain= 90.371094 Exposure Index= 411 */
          {23830,  3125  },        /* Gain= 93.085938 Exposure Index= 412 */
          {24545,  3125  },        /* Gain= 95.878906 Exposure Index= 413 */
          {25282,  3125  },        /* Gain= 98.757813 Exposure Index= 414 */
          {26041,  3125  },        /* Gain= 101.722656 Exposure Index= 415 */
          {26823,  3125  },        /* Gain= 104.777344 Exposure Index= 416 */
          {27628,  3125  },        /* Gain= 107.921875 Exposure Index= 417 */
          {28457,  3125  },        /* Gain= 111.160156 Exposure Index= 418 */
          {29311,  3125  },        /* Gain= 114.496094 Exposure Index= 419 */
          {30191,  3125  },        /* Gain= 117.933594 Exposure Index= 420 */
          {31097,  3125  },        /* Gain= 121.472656 Exposure Index= 421 */
          {32030,  3125  },        /* Gain= 125.117188 Exposure Index= 422 */
          {32991,  3125  },        /* Gain= 128.871094 Exposure Index= 423 */
          {33981,  3125  },        /* Gain= 132.738281 Exposure Index= 424 */
          {35001,  3125  },        /* Gain= 136.722656 Exposure Index= 425 */
          {36052,  3125  },        /* Gain= 140.828125 Exposure Index= 426 */
          {37134,  3125  },        /* Gain= 145.054688 Exposure Index= 427 */
          {38249,  3125  },        /* Gain= 149.410156 Exposure Index= 428 */
          {39397,  3125  },        /* Gain= 153.894531 Exposure Index= 429 */
          {40579,  3125  },        /* Gain= 158.511719 Exposure Index= 430 */
          {41797,  3125  },        /* Gain= 163.269531 Exposure Index= 431 */
          {43051,  3125  },        /* Gain= 168.167969 Exposure Index= 432 */
          {44343,  3125  },        /* Gain= 173.214844 Exposure Index= 433 */
          {45674,  3125  },        /* Gain= 178.414063 Exposure Index= 434 */
          {47045,  3125  },        /* Gain= 183.769531 Exposure Index= 435 */
          {48457,  3125  },        /* Gain= 189.285156 Exposure Index= 436 */
          {49911,  3125  },        /* Gain= 194.964844 Exposure Index= 437 */
          {51409,  3125  },        /* Gain= 200.816406 Exposure Index= 438 */
          {52952,  3125  },        /* Gain= 206.843750 Exposure Index= 439 */
          {54541,  3125  },        /* Gain= 213.050781 Exposure Index= 440 */
          {56178,  3125  },        /* Gain= 219.445313 Exposure Index= 441 */
          {57864,  3125  },        /* Gain= 226.031250 Exposure Index= 442 */
          {59600,  3125  },        /* Gain= 232.812500 Exposure Index= 443 */
          {61388,  3125  },        /* Gain= 239.796875 Exposure Index= 444 */
          {63230,  3125  },        /* Gain= 246.992188 Exposure Index= 445 */
          {65127,  3125  },        /* Gain= 254.402344 Exposure Index= 446 */
          {67081,  3125  },        /* Gain= 262.035156 Exposure Index= 447 */
          {69094,  3125  },        /* Gain= 269.898438 Exposure Index= 448 */
          {71167,  3125  },        /* Gain= 277.996094 Exposure Index= 449 */
          {73303,  3125  },        /* Gain= 286.339844 Exposure Index= 450 */
          {75503,  3125  },        /* Gain= 294.933594 Exposure Index= 451 */
          {77769,  3125  },        /* Gain= 303.785156 Exposure Index= 452 */
          {80103,  3125  },        /* Gain= 312.902344 Exposure Index= 453 */
          {82507,  3125  },        /* Gain= 322.292969 Exposure Index= 454 */
          {84983,  3125  },        /* Gain= 331.964844 Exposure Index= 455 */
          {87533,  3125  },        /* Gain= 341.925781 Exposure Index= 456 */
        },
    },
	/*ae_tuning_par par*/
	{
		1,  /* aec_stats_type; 0:BAYER_AEC; 1:HYBRID_AEC */
		0,  /* force_exp_forced */
		0.1,/* force_exp_value */
		1,  /* preview_iso_enable */
		{
            51,  /* outdoor_luma_target_compensated */
            48,  /* default_luma_target_compensated */
            31,/* low_light.luma_target */
            210,  /* outdoor_index */
            290,  /* indoor_index */
            360,/* low_light.start_idx */
            450,/* low_light.end_idx */
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
        1,  /* 0:no antibanding;1:50hz ;2:60hz */
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
        },/* 36x16 bias table for luma metering:0-100 */
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
    10,
	/* count_ae */
	1,
	/* trigger_mode */
	1,
	/* aec_trigger */
    {
		{
            0,
            456,
        },
        {
            0,
            456,
        },
        {
            0,
            456,
        },
	},
    /* awb_point */
    {
        { 0.3664, 0.7162 },    /* d75 */
        { 0.3921, 0.6727 },    /* d65 */
        { 0.4582, 0.5718 },    /* d50 */
        { 0.4587, 0.5713 },    /* noon */
        { 0.4634, 0.4159 },    /* cw */
        { 0.5306, 0.4425 },    /* tl84 */
        { 0.7320, 0.3519 },    /* a */
        { 0.9107, 0.2812 },    /* h */
        { 0.0000, 0.0000 },    /* custom1 */
        { 0.6282, 0.3996 },    /* custom2 */
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
    	3400, /* custom_2 */
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
        8,  /* custom1 */
        9,  /* custom2 */
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
	/* light_weight_table2 */
	{	/*Exp Index: 0, Outdoor_Index, Inoutdoor_Midpoint, Indoor_index*/
        { 0, 2, 1, 0 },   /*   d75    */
        { 2, 8, 2, 1 },   /*   d65    */
        {10,10, 10, 4 },   /*   d50    */
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
        10,   /* num_of_reference_point */
        0.0067, /* outline */
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
        0.20,   /* threshold_extreme_b_percent */
        0.1000,   /* compact_to_grey_dis */
        0.45,   /* cluster_high_pec */
        0.25,   /* cluster_mid_pec */
        0.15,   /* cluster_low_pec */
        10,   /* BitsSum */
        3,   /* FrameNum */
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
           0x000003e8, /* Ymax */
           0x0000001e, /* Ymin */
           0x00000100, /* Gray_m1 */
           0x00010100, /* Gray_m2 */
           0x00000100, /* Gray_m3 */
           0x00010100, /* Gray_m4 */
           0x00000258, /* Gray_c1 */
           0x000102a4, /* Gray_c2 */
           0x00010258, /* Gray_c3 */
           0x00000404, /* Gray_c4 */
           0x0000009f, /* Green_BGmax */
           0x0000003b, /* Green_BGmin */
           0x00000074, /* Green_RGmax */
           0x00000000, /* Green_RGmin */
           0x00000166, /* Green_Rmul */
           0x000000ea, /* Green_Bmul */
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
