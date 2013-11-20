/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#include <stdio.h>

#include <assert.h>
#include <cuda.h>
#include <cstdlib>

__global__ void incrementArrayOnDevice(int *a, int N, int *count)
{
    int id = blockIdx.x * blockDim.x + threadIdx.x;

    if( id < N )
    {
        if( a[id] == 3 )
        {
            atomicAdd(count, 1);
        }
    }
}

extern "C"

int run_kernel(int *a_h, int length)

{
    //int *a_h;   // host
    int *a_d;   // device

    int N = length;

    // allocate array on host
    a_h = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; ++i)
        a_h[i] = (i % 3 == 0 ? 3 : 1);

    // allocate arrays on device
    cudaMalloc(&a_d, sizeof(int) * N);

    // copy data from host to device
    cudaMemcpy(a_d, a_h, sizeof(int) * N, cudaMemcpyHostToDevice);

    // do calculation on device
    int blockSize = 512;
    int nBlocks = N / blockSize + (N % blockSize == 0 ? 0 : 1);
    printf("number of blocks: %d\n", nBlocks);

    int count;
    int *devCount;
    cudaMalloc(&devCount, sizeof(int));
    cudaMemset(devCount, 0, sizeof(int));

    incrementArrayOnDevice<<<nBlocks, blockSize>>> (a_d, N, devCount);
    
    cudaMemcpy(&count, devCount, sizeof(int), cudaMemcpyDeviceToHost); // retrieve result from device

    //printf("%d\n", count);

    free(a_h);
    cudaFree(a_d);
    cudaFree(devCount);
    
    return count;
}

