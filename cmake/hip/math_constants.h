/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

// Shim for the CUDA math constants header, which ROCm has no equivalent of.
// Only the constants the kernels use are defined. Only on the HIP include path,
// so the NVIDIA build never sees this file.

#pragma once
#include "CvCudaHipCompat.h"

#ifndef CUDART_INF_F
#    define CUDART_INF_F __builtin_inff()
#endif
