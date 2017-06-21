/*
 * =====================================================================================
 *
 *       Filename:  union.h
 *
 *    Description:  Header to union opreation code
 *
 *        Version:  1.0
 *        Created:  06/14/17 19:47:27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  @vpcsilva
 *
 * =====================================================================================
 */
#ifndef UNION_H
#define UNION_H

#include <vector>
#include <string>
#include <iomanip> // std::setprecision()
#include <iostream>
#include "../base/relation.h"
#include "../wtime.h"
#include <algorithm>

using namespace std;

#define msg(format, ...) do { fprintf(stderr, format, ##__VA_ARGS__); } while (0)
#define err(format, ...) do { fprintf(stderr, format, ##__VA_ARGS__); exit(1); } while (0)

// IF CUDA
// Copyright (c) 2005 Wei-keng Liao
// Copyright (c) 2011 Serban Giuroiu
#ifdef __CUDACC__
#include <thrust/device_vector.h>

inline void checkCuda(cudaError_t e) {
    if (e != cudaSuccess) {
        // cudaGetErrorString() isn't always very helpful. Look up the error
        // number in the cudaError enum in driver_types.h in the CUDA includes
        // directory for a better explanation.
        err("CUDA Error %d: %s\n", e, cudaGetErrorString(e));
    }
}
inline void checkLastCudaError() {
    checkCuda(cudaGetLastError());
}

#endif
// END IF CUDA

Relation unionOp(Relation, Relation);

#endif