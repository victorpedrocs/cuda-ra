/*
 * =====================================================================================
 *
 *       Filename:  select.h
 *
 *    Description:  Cabeçalho para o código de implementação do operador select
 *
 *        Version:  1.0
 *        Created:  06/04/16 00:08:59
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#ifndef SELECT_H
#define SELECT_H

#include <vector>
#include <string>
#include <iomanip> // std::setprecision()
#include <iostream>
#include "../base/relation.h"
#include "../wtime.h"

using namespace std;

// Copyright (c) 2005 Wei-keng Liao
// Copyright (c) 2011 Serban Giuroiu
#define msg(format, ...) do { fprintf(stderr, format, ##__VA_ARGS__); } while (0)
#define err(format, ...) do { fprintf(stderr, format, ##__VA_ARGS__); exit(1); } while (0)

struct Operator {
	int column;
	string op;
	float value;
};

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

Relation select(Relation, Operator);


#endif
