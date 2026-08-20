/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Shim for the NVTX include used by the profiling ranges. ROCm has no NVTX;
// roctx is the equivalent range API and rocprof reports its ranges the same
// way. The header moved from roctracer to the rocprofiler SDK, so take whichever
// the installation provides; both declare roctxRangePushA and roctxRangePop.
// Only on the HIP include path, so the NVIDIA build never sees this file.

#ifndef CVCUDA_HIP_NVTX3_NVTOOLSEXT_H
#define CVCUDA_HIP_NVTX3_NVTOOLSEXT_H

#if __has_include(<rocprofiler-sdk-roctx/roctx.h>)
#    include <rocprofiler-sdk-roctx/roctx.h>
#else
#    include <roctracer/roctx.h>
#endif

#define nvtxRangePushA roctxRangePushA
#define nvtxRangePop   roctxRangePop

#endif // CVCUDA_HIP_NVTX3_NVTOOLSEXT_H
