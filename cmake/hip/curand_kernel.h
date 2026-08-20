/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Jeff Daily <jeff.daily@amd.com>
 */

#pragma once
#include "CvCudaHipCompat.h"
#include <cstdio> // rocRAND's mtgp32 header calls printf without including it
#include <hiprand/hiprand_kernel.h>

#define curandState    hiprandState
#define curandState_t  hiprandState_t
#define curand_init    hiprand_init
#define curand_normal  hiprand_normal
#define curand_normal2 hiprand_normal2

// curand keeps one spare Box-Muller normal in the generator state and flags it
// with boxmuller_flag == EXTRA_FLAG_NORMAL. rocRAND caches the same spare value
// but marks an empty slot with a NaN sentinel, which its own helper queries.
#if defined(__cplusplus)
__host__ __device__ inline bool cvcuda_hipHasCachedNormal(const hiprandState &state)
{
    return rocrand_device::detail::engine_boxmuller_helper<rocrand_state_xorwow>::has_float(&state);
}
#endif
