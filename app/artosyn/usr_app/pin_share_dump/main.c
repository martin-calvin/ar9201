#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

#define FILE_NAME_SIZE          4096
#define TOTAL_PAD_NUM          (140)
#define TOTAL_FUNC_NUM          (140)
#define TOTAL_MUX_NUM           49
#define PAD_CONFIG_BASE_ADDR    0x60633000
#define PAD_CONFIG_OFFSET_ADDR    0x04
#define BIT_GET_REGION(r, start, n) \
	((r & (((1 << n) -1) << start)) >> start)

struct pin_mux_cfg {
	char* pin;
	short pad;
	short func;
	short pad_sel;
	short start;
	short bits;
	short value;
};

static int pin_mux_base[2] = {0x60633110, 0x60633114};

static struct pin_mux_cfg pin_tbl[] = {
	/* SPI Master2 DI */
	{
		.pin = "SPI Master2 DI",
		.pad = 18,
		.func = 0,
		.pad_sel = 0,
		.start = 8,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "SPI Master2 DI",
		.pad = 52,
		.func = 3,
		.pad_sel = 0,
		.start = 8,
		.bits = 2,
		.value = 1,
	},

	/* SPI Master3 DI */
	{
		.pin = "SPI Master3 DI",
		.pad = 22,
		.func = 2,
		.pad_sel = 0,
		.start = 10,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "SPI Master3 DI",
		.pad = 121,
		.func = 3,
		.pad_sel = 0,
		.start = 10,
		.bits = 2,
		.value = 1,
	},

	/* I2C3 SDA*/
	{
		.pin = "I2C3 SDA",
		.pad = 36,
		.func = 0,
		.pad_sel = 0,
		.start = 12,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2C3 SDA",
		.pad = 84,
		.func = 2,
		.pad_sel = 0,
		.start = 12,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "I2C3 SDA",
		.pad = 136,
		.func = 3,
		.pad_sel = 0,
		.start = 12,
		.bits = 2,
		.value = 2,
	},

	/* I2C3 SCLK*/
	{
		.pin = "I2C3 SCLK",
		.pad = 37,
		.func = 0,
		.pad_sel = 0,
		.start = 14,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2C3 SCLK",
		.pad = 85,
		.func = 2,
		.pad_sel = 0,
		.start = 14,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "I2C3 SCLK",
		.pad = 135,
		.func = 3,
		.pad_sel = 0,
		.start = 14,
		.bits = 2,
		.value = 2,
	},

	/* I2C4 SDA*/
	{
		.pin = "I2C4 SDA",
		.pad = 8,
		.func = 3,
		.pad_sel = 0,
		.start = 16,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2C4 SDA",
		.pad = 38,
		.func = 3,
		.pad_sel = 0,
		.start = 16,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "I2C4 SDA",
		.pad = 90,
		.func = 2,
		.pad_sel = 0,
		.start = 16,
		.bits = 2,
		.value = 2,
	},

	{
		.pin = "I2C4 SDA",
		.pad = 139,
		.func = 2,
		.pad_sel = 0,
		.start = 16,
		.bits = 2,
		.value = 3,
	},

	/* I2C4 SCLK*/
	{
		.pin = "I2C4 SCLK",
		.pad = 9,
		.func = 3,
		.pad_sel = 0,
		.start = 18,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2C4 SCLK",
		.pad = 39,
		.func = 3,
		.pad_sel = 0,
		.start = 18,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "I2C4 SCLK",
		.pad = 91,
		.func = 2,
		.pad_sel = 0,
		.start = 18,
		.bits = 2,
		.value = 2,
	},

	{
		.pin = "I2C4 SCLK",
		.pad = 138,
		.func = 2,
		.pad_sel = 0,
		.start = 18,
		.bits = 2,
		.value = 3,
	},

	/* UART1 SIN*/
	{
		.pin = "UART1 SIN",
		.pad = 42,
		.func = 3,
		.pad_sel = 0,
		.start = 0,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "UART1 SIN",
		.pad = 8,
		.func = 1,
		.pad_sel = 0,
		.start = 0,
		.bits = 2,
		.value = 0,
	},

	/* UART5 SIN*/
	{
		.pin = "UART5 SIN",
		.pad = 5,
		.func = 1,
		.pad_sel = 0,
		.start = 2,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "UART5 SIN",
		.pad = 52,
		.func = 2,
		.pad_sel = 0,
		.start = 2,
		.bits = 2,
		.value = 1,
	},

	{
		.pin = "UART5 SIN",
		.pad = 135,
		.func = 2,
		.pad_sel = 0,
		.start = 2,
		.bits = 2,
		.value = 2,
	},

	/* UART7 SIN*/
	{
		.pin = "UART7 SIN",
		.pad = 56,
		.func = 2,
		.pad_sel = 0,
		.start = 4,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "UART7 SIN",
		.pad = 86,
		.func = 2,
		.pad_sel = 0,
		.start = 4,
		.bits = 2,
		.value = 1,
	},

	/* UART8 SIN*/
	{
		.pin = "UART8 SIN",
		.pad = 58,
		.func = 2,
		.pad_sel = 0,
		.start = 6,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "UART8 XIN",
		.pad = 88,
		.func = 2,
		.pad_sel = 0,
		.start = 6,
		.bits = 2,
		.value = 1,
	},

	/* CAN0 RXD*/
	{
		.pin = "CAN0 RXD",
		.pad = 22,
		.func = 3,
		.pad_sel = 0,
		.start = 20,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "CAN0 RXD",
		.pad = 42,
		.func = 2,
		.pad_sel = 0,
		.start = 20,
		.bits = 2,
		.value = 1,
	},

	/* CAN1 RXD*/
	{
		.pin = "CAN1 RXD",
		.pad = 24,
		.func = 3,
		.pad_sel = 0,
		.start = 22,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "CAN1 RXD",
		.pad = 44,
		.func = 2,
		.pad_sel = 0,
		.start = 22,
		.bits = 2,
		.value = 1,
	},

	/* CAN2 RXD*/
	{
		.pin = "CAN2 RXD",
		.pad = 14,
		.func = 2,
		.pad_sel = 0,
		.start = 24,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "CAN2 RXD",
		.pad = 46,
		.func = 2,
		.pad_sel = 0,
		.start = 24,
		.bits = 2,
		.value = 1,
	},

	/* CAN3 RXD*/
	{
		.pin = "CAN3 RXD",
		.pad = 16,
		.func = 2,
		.pad_sel = 0,
		.start = 26,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "CAN3 RXD",
		.pad = 48,
		.func = 2,
		.pad_sel = 0,
		.start = 26,
		.bits = 2,
		.value = 1,
	},

	/* BB SPI DI A */
	{
		.pin = "BB SPI DI A",
		.pad = 8,
		.func = 4,
		.pad_sel = 0,
		.start = 28,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "BB SPI DI A",
		.pad = 122,
		.func = 2,
		.pad_sel = 0,
		.start = 28,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV0 DO */
	{
		.pin = "I2S MST/SLV0 DO",
		.pad = 62,
		.func = 0,
		.pad_sel = 1,
		.start = 4,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV0 DO",
		.pad = 132,
		.func = 3,
		.pad_sel = 1,
		.start = 4,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV1 DO */
	{
		.pin = "I2S MST/SLV1 DO",
		.pad = 66,
		.func = 0,
		.pad_sel = 1,
		.start = 6,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV1 DO",
		.pad = 131,
		.func = 3,
		.pad_sel = 1,
		.start = 6,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV2 DO */
	{
		.pin = "I2S MST/SLV2 DO",
		.pad = 70,
		.func = 0,
		.pad_sel = 1,
		.start = 8,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV2 DO",
		.pad = 130,
		.func = 3,
		.pad_sel = 1,
		.start = 8,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV3 WS */
	{
		.pin = "I2S MST/SLV3 WS",
		.pad = 72,
		.func = 0,
		.pad_sel = 1,
		.start = 0,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV3 WS",
		.pad = 134,
		.func = 3,
		.pad_sel = 1,
		.start = 0,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV3 DO */
	{
		.pin = "I2S MST/SLV0 DO",
		.pad = 74,
		.func = 0,
		.pad_sel = 1,
		.start = 10,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV0 DO",
		.pad = 129,
		.func = 3,
		.pad_sel = 1,
		.start = 10,
		.bits = 2,
		.value = 1,
	},

	/* I2S MST/SLV3 CLK */
	{
		.pin = "I2S MST/SLV0 CLK",
		.pad = 75,
		.func = 0,
		.pad_sel = 1,
		.start = 2,
		.bits = 2,
		.value = 0,
	},

	{
		.pin = "I2S MST/SLV0 CLK",
		.pad = 133,
		.func = 3,
		.pad_sel = 1,
		.start = 2,
		.bits = 2,
		.value = 1,
	},
};

static char* pad_tbl[TOTAL_PAD_NUM][TOTAL_FUNC_NUM] =
	{{"RSTN","","","","","",""},
	{"TEST_MODE_EN","","","","","",""},
	{"JTAG_TRSTN","WTD_0","","","GPIO_A0_0","ATE_TEST_IN_16",""},
	{"GPIO_A0_1","PCIE_PERST_DET","","","","ATE_TEST_IN_17",""},
	{"GPIO_A0_2","HDMI_HP","","","","ATE_TEST_IN_18",""},
	{"GPIO_A0_3","UART_SIN5","SPI_M2_CS1N","","","ATE_TEST_IN_19",""},
	{"GPIO_A0_4","UART_SOUT5","SPI_M2_CS2N","","BB_SPI_DOMOSI_A","ATE_TEST_IN_20",""},
	{"GPIO_A0_5","WTD_1","","","BB_SPI_ENB_A","ATE_TEST_IN_21",""},
	{"GPIO_A0_6","UART_SIN1","SPI_M2_CS3N","I2C_SDA4","BB_SPI_DIMISO_A","ATE_TEST_IN_22",""},
	{"GPIO_A0_7","UART_SOUT1","SPI_M2_CS4N","I2C_SCLK4","BB_SPI_CLK_A","ATE_TEST_IN_23",""},
	{"SPI_M0_DI","GPIO_C0_0","","","","",""},
	{"SPI_M0_DO","GPIO_C0_1","","","","",""},
	{"SPI_M0_SCLK","GPIO_C0_2","","","","",""},
	{"SPI_M0_CSN","GPIO_C0_3","","","","",""},
	{"SPI_M1_DI","GPIO_C0_4","CAN_RXD2","","","",""},
	{"SPI_M1_DO","GPIO_C0_5","CAN_TXD2","","","",""},
	{"SPI_M1_SCLK","GPIO_C0_6","CAN_RXD3","TEST_JTAG_RTCK","","",""},
	{"SPI_M1_CSN","GPIO_C0_7","CAN_TXD3","TEST_JTAG_TRSTN","","",""},
	{"SPI_M2_DI","GPIO_D0_0","BB_ANT_SW_SEL","TEST_JTAG_TDI","","",""},
	{"SPI_M2_DO","GPIO_D0_1","BB_ANT_SW_SEL_N","TEST_JTAG_TDO","","",""},
	{"SPI_M2_SCLK","GPIO_D0_2","BS_SEL","TEST_JTAG_TCK","","",""},
	{"SPI_M2_CS0N","GPIO_D0_3","BS_SEL_N","TEST_JTAG_TMS","","",""},
	{"SPI_DBG_DI","GPIO_A1_0","SPI_M3_DI","CAN_RXD0","SPI_S0_DI","",""},
	{"SPI_DBG_DO","GPIO_A1_1","SPI_M3_DO","CAN_TXD0","SPI_S0_DO","",""},
	{"SPI_DBG_CLK","GPIO_A1_2","SPI_M3_SCLK","CAN_RXD1","SPI_S0_SCK","",""},
	{"SPI_DBG_CSN","GPIO_A1_3","SPI_M3_CS0N","CAN_TXD1","SPI_S0_CSN","",""},
	{"BB_DEBUG_MOSI","GPIO_A1_4","SPI_M3_CS1N","CAN_STBY0","SPI_S1_DI","",""},
	{"BB_DEBUG_MISO","GPIO_A1_5","SPI_M3_CS2N","CAN_STBY1","SPI_S1_DO","",""},
	{"BB_DEBUG_SCK","GPIO_A1_6","SPI_M3_CS3N","CAN_STBY2","SPI_S1_SCK","",""},
	{"BB_DEBUG_CSN","GPIO_A1_7","SPI_M3_CS4N","CAN_STBY3","SPI_S1_CSN","",""},
	{"I2C_SDA0","GPIO_B1_0","","","","",""},
	{"I2C_SCLK0","GPIO_B1_1","","","","",""},
	{"I2C_SDA1","GPIO_B1_2","","","","",""},
	{"I2C_SCLK1","GPIO_B1_3","","","","",""},
	{"I2C_SDA2","GPIO_B1_4","","","","",""},
	{"I2C_SCLK2","GPIO_B1_5","","","","",""},
	{"I2C_SDA3","GPIO_B1_6","BB_SPI_ENB_B","","","",""},
	{"I2C_SCLK3","GPIO_B1_7","BB_SPI_CLK_B","","","",""},
	{"JTAG_TMS","GPIO_D0_4","BB_SPI_DIMISO_B","I2C_SDA4","","",""},
	{"JTAG_TCK","GPIO_D0_5","BB_SPI_DOMOSI_B","I2C_SCLK4","","",""},
	{"SEC_UART_SIN","GPIO_C1_0","UART_SIN0","","","",""},
	{"SEC_UART_SOUT","GPIO_C1_1","UART_SOUT0","","","",""},
	{"TROOT_RXD","GPIO_C1_2","CAN_RXD0","UART_SIN1","","",""},
	{"TROOT_TXD","GPIO_C1_3","CAN_TXD0","UART_SOUT1","","",""},
	{"UART_SIN2","GPIO_C1_4","CAN_RXD1","ATE_TEST_IN_24","","",""},
	{"UART_SOUT2","GPIO_C1_5","CAN_TXD1","ATE_TEST_IN_25","","",""},
	{"UART_SIN3","GPIO_C1_6","CAN_RXD2","ATE_TEST_IN_26","","",""},
	{"UART_SOUT3","GPIO_C1_7","CAN_TXD2","CEVA_UART_TX","","",""},
	{"JTAG_TDI","GPIO_D0_6","CAN_RXD3","BB_PA_ON_2G","UART_SIN4","UART_CTS_N1",""},
	{"JTAG_TDO","GPIO_D0_7","CAN_TXD3","BB_PA_ON_5G","UART_SOUT4","UART_RTS_N1",""},
	{"PWM0","GPIO_D1_0","","","","",""},
	{"PWM1","GPIO_D1_1","","","TRACE_DATA_7","",""},
	{"PWM2","GPIO_D1_2","UART_SIN5","SPI_M2_DI","TRACE_DATA_6","",""},
	{"PWM3","GPIO_D1_3","UART_SOUT5","SPI_M2_DO","TRACE_DATA_5","",""},
	{"PWM4","GPIO_D1_4","UART_SIN6","SPI_M2_SCLK","TRACE_DATA_4","BB_PA_ON_2G_1",""},
	{"PWM5","GPIO_D1_5","UART_SOUT6","SPI_M2_CS0N","TRACE_DATA_3","BB_PA_ON_5G_1",""},
	{"PWM6","GPIO_D1_6","UART_SIN7","SPI_M2_CS1N","TRACE_DATA_2","CAN_TCLK0",""},
	{"PWM7","GPIO_D1_7","UART_SOUT7","SPI_M2_CS2N","TRACE_DATA_1","CAN_TCLK1",""},
	{"PWM8","GPIO_A2_0","UART_SIN8","SPI_M2_CS3N","TRACE_DATA_0","CAN_TCLK2",""},
	{"PWM9","GPIO_A2_1","UART_SOUT8","SPI_M2_CS4N","TRACE_CLK","CAN_TCLK3",""},
	{"I2S_WS_0","GPIO_B2_0","","","","",""},
	{"I2S_SDI_0","GPIO_B2_1","","","","",""},
	{"I2S_SDO_0","GPIO_B2_2","","","","",""},
	{"I2S_CLK_0","GPIO_B2_3","","","","",""},
	{"I2S_WS_1","GPIO_B2_4","","","","",""},
	{"I2S_SDI_1","GPIO_B2_5","","","","",""},
	{"I2S_SDO_1","GPIO_B2_6","","","","",""},
	{"I2S_CLK_1","GPIO_B2_7","","","","",""},
	{"I2S_WS_2","GPIO_C2_0","","MON_OUT_24","BB_RXTX_A","ATE_TEST_IN_8",""},
	{"I2S_SDI_2","GPIO_C2_1","","MON_OUT_25","BB_ENABLE_A","ATE_TEST_IN_9",""},
	{"I2S_SDO_2","GPIO_C2_2","","MON_OUT_26","BB_RXHP_A","ATE_TEST_IN_10",""},
	{"I2S_CLK_2","GPIO_C2_3","","MON_OUT_27","BB_RX_LNA_VBIAS_2G","ATE_TEST_IN_11",""},
	{"I2S_WS_3","GPIO_C2_4","DVP_EXT_OUT_0","MON_OUT_28","BB_RXTX_B","ATE_TEST_IN_12",""},
	{"I2S_SDI_3","GPIO_C2_5","DVP_EXT_OUT_1","MON_OUT_29","BB_ENABLE_B","ATE_TEST_IN_13",""},
	{"I2S_SDO_3","GPIO_C2_6","DVP_EXT_OUT_2","MON_OUT_30","BB_RXHP_B","ATE_TEST_IN_14",""},
	{"I2S_CLK_3","GPIO_C2_7","DVP_EXT_OUT_3","MON_OUT_31","BB_RX_LNA_VBIAS_5G","ATE_TEST_IN_15",""},
	{"QSPI_SCK","SD_CCLK_OUT","GPIO_D2_0","","","",""},
	{"QSPI_CS_N","SD_CCMD","GPIO_D2_1","","","",""},
	{"GPIO_D2_2","SD_CARD_DETECT_N","","","","",""},
	{"GPIO_D2_3","SD_CARD_WPRT","","","","",""},
	{"QSPI_DATA_0","SD_CDATA_0","GPIO_D2_4","","","",""},
	{"QSPI_DATA_1","SD_CDATA_1","GPIO_D2_5","","","",""},
	{"QSPI_DATA_2","SD_CDATA_2","GPIO_D2_6","","","",""},
	{"QSPI_DATA_3","SD_CDATA_3","GPIO_D2_7","","","",""},
	{"PCLK1","GPIO_A2_2","I2C_SDA3","TYPEC_DIG_OUT_0","MON_OUT_0","ATE_TEST_OUT_0","DVP_EXT_OUT_4"},
	{"PDE1","GPIO_A2_3","I2C_SCLK3","TYPEC_DIG_OUT_1","MON_OUT_1","ATE_TEST_OUT_1","DVP_EXT_OUT_5"},
	{"PVSYNC1","GPIO_A2_4","UART_SIN7","TYPEC_DIG_OUT_2","MON_OUT_2","ATE_TEST_OUT_2","DVP_EXT_OUT_6"},
	{"PHSYNC1","GPIO_A2_5","UART_SOUT7","TYPEC_DIG_OUT_3","MON_OUT_3","ATE_TEST_OUT_3","DVP_EXT_OUT_7"},
	{"PDATA1_0","GPIO_A3_0","UART_SIN8","TYPEC_DIG_OUT_4","MON_OUT_4","ATE_TEST_OUT_4",""},
	{"PDATA1_1","GPIO_A3_1","UART_SOUT8","TYPEC_DIG_OUT_5","MON_OUT_5","ATE_TEST_OUT_5",""},
	{"PDATA1_2","GPIO_A3_2","I2C_SDA4","TYPEC_DIG_IN_6","MON_OUT_6","ATE_TEST_OUT_6",""},
	{"PDATA1_3","GPIO_A3_3","I2C_SCLK4","TYPEC_DIG_IN_7","MON_OUT_7","ATE_TEST_OUT_7",""},
	{"PDATA1_4","GPIO_A3_4","SPI_M3_CS1N","TYPEC_DIG_IN_8","MON_OUT_8","ATE_TEST_OUT_8",""},
	{"PDATA1_5","GPIO_A3_5","SPI_M3_CS2N","TYPEC_DIG_IN_9","MON_OUT_9","ATE_TEST_OUT_9",""},
	{"PDATA1_6","GPIO_A3_6","SPI_M3_CS3N","TYPEC_DIG_OUT_10","MON_OUT_10","ATE_TEST_OUT_10",""},
	{"PDATA1_7","GPIO_A3_7","SPI_M3_CS4N","TYPEC_DIG_OUT_11","MON_OUT_11","ATE_TEST_OUT_11",""},
	{"PCLK0","GPIO_A2_6","","","MON_OUT_12","ATE_TEST_OUT_12",""},
	{"PDE0","GPIO_A2_7","","","MON_OUT_13","ATE_TEST_OUT_13",""},
	{"PVSYNC0","GPIO_B0_0","","","MON_OUT_14","ATE_TEST_OUT_14",""},
	{"PHSYNC0","GPIO_B0_1","","","MON_OUT_15","ATE_TEST_OUT_15",""},
	{"MON_OUT_16","GPIO_B3_0","","","PDATA0_0","ATE_TEST_IN_0",""},
	{"MON_OUT_17","GPIO_B3_1","","","PDATA0_1","ATE_TEST_IN_1",""},
	{"MON_OUT_18","GPIO_B3_2","","","PDATA0_2","ATE_TEST_IN_2",""},
	{"MON_OUT_19","GPIO_B3_3","","","PDATA0_3","ATE_TEST_IN_3",""},
	{"MON_OUT_20","GPIO_B3_4","","","PDATA0_4","ATE_TEST_IN_4",""},
	{"MON_OUT_21","GPIO_B3_5","","","PDATA0_5","ATE_TEST_IN_5",""},
	{"MON_OUT_22","GPIO_B3_6","","","PDATA0_6","ATE_TEST_IN_6",""},
	{"MON_OUT_23","GPIO_B3_7","","","PDATA0_7","ATE_TEST_IN_7",""},
	{"EMMC_CCLK_OUT","GPIO_B0_2","","","","",""},
	{"EMMC_CCMD","GPIO_B0_3","","","","",""},
	{"EMMC_PWR","GPIO_B0_4","","","","",""},
	{"EMMC_D0","GPIO_C3_0","","","","",""},
	{"EMMC_D1","GPIO_C3_1","","","","",""},
	{"EMMC_D2","GPIO_C3_2","","","","",""},
	{"EMMC_D3","GPIO_C3_3","","","","",""},
	{"EMMC_D4","GPIO_C3_4","","","","",""},
	{"EMMC_D5","GPIO_C3_5","","","","",""},
	{"EMMC_D6","GPIO_C3_6","","","","",""},
	{"EMMC_D7","GPIO_C3_7","","","","",""},
	{"USB_OC","GPIO_B0_5","","","","",""},
	{"USB_PWR_CTRL","GPIO_B0_6","","","","",""},
	{"GBE_TXC","GPIO_D3_0","BB_SPI_ENB_A","SPI_M3_DI","","",""},
	{"GBE_TXEN","GPIO_D3_1","BB_SPI_DIMISO_A","SPI_M3_DO","","",""},
	{"GBE_TXD0","GPIO_D3_2","BB_SPI_DOMOSI_A","SPI_M3_SCLK","","",""},
	{"GBE_TXD1","GPIO_D3_3","BB_SPI_CLK_A","SPI_M3_CS0N","","",""},
	{"GBE_TXD2","GPIO_D3_4","BB_RXTX_A","SPI_M3_CS1N","","",""},
	{"GBE_TXD3","GPIO_D3_5","BB_ENABLE_A","SPI_M3_CS2N","","",""},
	{"GBE_RXC","GPIO_D3_6","BB_RXHP_A","SPI_M3_CS3N","","",""},
	{"GBE_RXEN","GPIO_D3_7","BB_RX_LNA_VBIAS_2G","SPI_M3_CS4N","","",""},
	{"GBE_RXD0","GPIO_B4_0","BB_RX_LNA_VBIAS_5G","I2S_SDO_3","","",""},
	{"GBE_RXD1","GPIO_B4_1","BB_PA_ON_2G","I2S_SDO_2","","",""},
	{"GBE_RXD2","GPIO_B4_2","BB_PA_ON_5G","I2S_SDO_1","","",""},
	{"GBE_RXD3","GPIO_B4_3","BB_ANT_SW_SEL","I2S_SDO_0","","",""},
	{"GBE_MDC","GPIO_B4_4","BB_ANT_SW_SEL_N","I2S_CLK_3","","",""},
	{"GBE_MDIO","GPIO_B4_5","BS_SEL","I2S_WS_3","","",""},
	{"GBE_INT","GPIO_A4_0","UART_SIN5","I2C_SCLK3","","",""},
	{"GBE_CLK","GPIO_A4_1","UART_SOUT5","I2C_SDA3","","",""},
	{"GBE_RST","GPIO_B0_7","BS_SEL_N","","","",""},
	{"HDMI_SCL","GPIO_A4_2","I2C_SCLK4","","","",""},
	{"HDMI_SDA","GPIO_A4_3","I2C_SDA4","","","",""},
	{"HDMI_CEC","GPIO_A4_4","","","","",""}};




static unsigned int read_reg(unsigned int reg_addr)
{
	unsigned int fd_mem, reg_read_data;
	unsigned char *reg_read_addr, *map_address;

	fd_mem=open("/dev/mem", O_RDWR | O_SYNC);
	if(fd_mem < 0){
		printf("open /dev/mem fail line:%d\n", __LINE__);
		return;
	}
	map_address =  mmap(NULL, FILE_NAME_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_mem, reg_addr&(~(FILE_NAME_SIZE - 1)));
	reg_read_addr = map_address+(reg_addr & (FILE_NAME_SIZE - 1));
	reg_read_data = *(unsigned int *)reg_read_addr;
	munmap(map_address, FILE_NAME_SIZE);
	close(fd_mem);
	return reg_read_data;
}

static int find_pra_index_by_name(char *name,int argc, char *argv[])
{
	int i=0;
	for(i=0;i<argc;i++)
	{
		 if(!strcmp(name,argv[i]))
		 {
			 return i;
		 }
	}
	return 0;
}

static inline int get_region(int addr, int start, int bits)
{
	return BIT_GET_REGION(reg_read(addr), start, bits);
}


static void pin_mux_dump(void)
{
	int i;
	printf("*---------------pin_mux_dump---------------*\n");
	for(i = 0;i < TOTAL_MUX_NUM;i++)
	{
		if(pin_tbl[i].value == \
		BIT_GET_REGION(read_reg(pin_mux_base[pin_tbl[i].pad_sel]), pin_tbl[i].start,pin_tbl[i].bits ))
		{
			printf("%s : pad %d\n", pin_tbl[i].pin, pin_tbl[i].pad);
		}
	}
	printf("*-------------pin_mux_dump_end-------------*\n");
}

static void pin_share_dump(void)
{
	int pad;
	int reg_addr;
	int reg_start;
	int reg_bits;
	int func;
	printf("*--------------pin_share_dump--------------*\n");
	for(pad = 0;pad < TOTAL_PAD_NUM; pad++)
	{
		reg_addr = PAD_CONFIG_BASE_ADDR + pad / 3 * PAD_CONFIG_OFFSET_ADDR;
		reg_start = pad % 3 * 10;
		reg_bits = 3;
		func = BIT_GET_REGION(read_reg(reg_addr), reg_start, reg_bits);
		if(!strcmp(pad_tbl[pad][func], ""))
		{
			printf("pad %d : no func %d!\n", pad, func);
			continue;
		}
		printf("pad %d : %s\n", pad, pad_tbl[pad][func]);
		//if(!((pad + 1) % 10))
		//{
		//	printf("\n");
		//}
	}
	printf("*-------------pin_share_dump_end-------------*\n");
}



static void pin_share_dump_help(const char *argv0)
{
	printf("*--------------------------------------------------*\n");
	printf(" pin share dump usage: %s\n", argv0);
	printf(" pin share dump : pin_share_dump -ps\n");
	printf(" pin mux dump   : pin_share_dump -pm\n");
	printf("*--------------------------------------------------*\n");
}

int main (int argc, char *argv[])
{
	int gpio_num;
	int index;


	index = find_pra_index_by_name("-ps",argc,argv);
	if(index>0)
	{
		pin_share_dump();
		return 0;
	}
	index = find_pra_index_by_name("-pm",argc,argv);
	if(index>0)
	{
		pin_mux_dump();
		return 0;
	}
	else
	{
		printf("command wrong!\n");
		pin_share_dump_help(argv[0]);
	}

	return 0;
}




