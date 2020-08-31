/** \addtogroup bsp
 *  @{
 */

/**
 * @file ar_ion.h
 * @author Artosyn
 * @date 9 May 2019
 * @brief artosyn ion api
 */

#ifndef __USR_CORE_AR_ION_H
#define __USR_CORE_AR_ION_H
#ifdef __cplusplus
extern "C"{
#endif

#if defined(WIN32) || defined(X64)
/*This is for DSP VS simulation*/
__inline int ar_ion_init(int head_id)
{
	return 0;
}

__inline unsigned char * ar_ion_malloc_ex(size_t size, int flag)
{
	return (unsigned char*)malloc(size);
}

__inline int ar_ion_cache_flush(unsigned char *va)
{
	return 0;
}

__inline int ar_ion_cache_invalid(unsigned char *va)
{
	return 0;
}

///macro define
#define ar_ion_malloc      malloc
#define ar_ion_calloc      calloc
#define ar_ion_free        free
/**
* @brief The detail define comment
* @param va virtual addr
*
*/

#define ar_ion_virt_to_phy(va)  (va)
#define ar_ion_uninit() do{}while(0)
#else
/**
* @brief  ion init.
* @param  heap_id	ion head id
* @retval 0	fail.
*         -1	ok.
*/
int ar_ion_init(int heap_id);
/**
* @brief ar_ion_uninit
* @param heap_id	ion head id
* @retval 0	fail.
*		  -1	ok.
*/
int ar_ion_uninit(void);
/**
* @brief ar_ion_malloc
* @param size malloc memory size
* @retval NULL      malloc memory fail.
*         ion_addr  malloc memory success.
*/
unsigned char *ar_ion_malloc(size_t size);
/**
* @brief ar_ion_calloc
* @param n    element number
* 		  size element size
* @retval 0   success
*		   <0  fail.
*/
unsigned char *ar_ion_calloc(size_t n, size_t size);
/**
* @brief ar_ion_free
* @param addr free addr
* @retval 0  success
*		   <0 fail
*/

int ar_ion_free(unsigned char *addr);

/**
* @brief  virt to phy.
* @param  va	virt addr
* @return  pa 	return phy addr
*/
unsigned char * ar_ion_virt_to_phy(unsigned char *va);

/**
* @brief ar_ion_malloc_ex
* @param size malloc memory size
         flags 0(non cache), 1(cache)
* @retval NULL      malloc memory fail.
*         ion_addr  malloc memory success.
*/
unsigned char *ar_ion_malloc_ex(size_t size, int flags);

/**
* @brief  virt ar_ion_cache_flush.
* @param  va	virt addr
* @return  < 0 	error
*/
int ar_ion_cache_flush(unsigned char *va);

/**
* @brief  virt ar_ion_cache_invalid.
* @param  va	virt addr
* @return  < 0 	error
*/
int ar_ion_cache_invalid(unsigned char *va);


/**
* @brief  virt ar_ion_cache_invalid.
* @param  va_base	ion virt base addr from ar_ion_malloc
* @param  va_base	ion virt base addr from ar_ion_malloc
* @return  < 0 	error
*/
int ar_ion_cache_invalid_by_range(unsigned char *va_base, unsigned char *inv_va_start, unsigned int size);


/**
* @brief  virt ar_ion_cache_invalid.
* @param  va	virt addr
* @return  < 0 	error
*/
int ar_ion_cache_flush_by_range(unsigned char *va_base, unsigned char *inv_va_start, unsigned int size);


#endif

#ifdef __cplusplus
}
#endif

#endif /* __USR_CORE_AR_ION_H */
/** @}*/
