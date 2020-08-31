#ifndef __LIB_REMOTE_SPI_H__
#define __LIB_REMOTE_SPI_H__


#define 	TR		(0)
#define 	TO		(1)
#define 	RO		(2)
#define 	EE		(3)

#define 	SPI_MAX_BUF_LEN 16
// Serial Clock Polarity
typedef enum
{
	HAL_SPI_POLARITY_LOW = 0,		// Inactive state of serial clock is low
	HAL_SPI_POLARITY_HIGH,			// Inactive state of serial clock is high
} remote_spi_polarity_enum;

// Serial Clock Phase
typedef enum
{
	HAL_SPI_PHASE_1EDGE = 0,	// data are captured on the first edge of the serial clock
	HAL_SPI_PHASE_2EDGE 		// data are captured on the second edge of the serial clock
} remote_spi_phase_enum;

// spi chennal
typedef enum
{
	SPI_0 = 0,
	SPI_1,
	SPI_2,
	SPI_3,
	SPI_4,
	SPI_5
} remote_spi_component_enum;

// spi init info
typedef struct
{
	uint16_t			   u16_halSpiBaudr;
	int 	 e_halSpiPolarity;
	int 		e_halSpiPhase;
} remote_stru_spi_init;

typedef struct
{
	int e_spi_component;
	remote_stru_spi_init  pst_spi_init_info;
	unsigned int tmod;
	unsigned int txlen;
	unsigned int rxlen;
	unsigned char txbuf[SPI_MAX_BUF_LEN];
	unsigned char rxbuf[SPI_MAX_BUF_LEN];
}spi_rpc_xfer_t;


typedef struct
{
	pthread_mutex_t m_mutex_lock;

} remote_stru_spi_dev_data;


unsigned int remote_spi_open(const char *name);

int remote_spi_close(unsigned int fd);

int remote_spi_master_xfer(unsigned int fd, spi_rpc_xfer_t* spi_rpc_xfer);

#endif

