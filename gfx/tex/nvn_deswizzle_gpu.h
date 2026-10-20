#ifndef NVN_DESWIZZLE_GPU_H
#define NVN_DESWIZZLE_GPU_H

#import <Metal/Metal.h>
#include "nvn_texdesc.h"

#ifdef __cplusplus
extern "C" {
#endif

int nvn_deswz_gpu_init(id<MTLDevice> dev);

int nvn_deswz_gpu_encode(id<MTLComputeCommandEncoder> enc, id<MTLBuffer> src, uint64_t src_off,
                         const nvn_texdesc *d, unsigned level, unsigned layer,
                         id<MTLBuffer> dst, uint64_t dst_off, size_t dst_pitch);

#if !DM_NVN_M3
int nvn_deswz_gpu_encode_m4(id<MTL4ComputeCommandEncoder> enc, id<MTL4ArgumentTable> table,
                            id<MTLBuffer> params, size_t params_off, id<MTLBuffer> src, uint64_t src_off,
                            const nvn_texdesc *d, unsigned level, unsigned layer,
                            id<MTLBuffer> dst, uint64_t dst_off, size_t dst_pitch);
#endif

#ifdef __cplusplus
}
#endif

#endif
