#ifndef __MY_AXI_DMA_H__
#define __MY_AXI_DMA_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */



/*使用dsm进行mem->mem数据copy 
* @dst_pa 目标mem的物理地址
* @src_pa 源mem的物理地址
* @size copy的数据长度
* return =0时成功，非0失败
*/
int my_dma_memcpy(void *dst_va, void *dst_pa, void *src_va, void *src_pa, int size);


















#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif