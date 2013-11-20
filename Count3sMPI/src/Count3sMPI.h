#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "mpi.h"

#pragma once

    //size: 12 //3s: 4
    int a[] = {23, 3, 3, 5, 2, 3, 2, 1, 2, 1, 3, 3};
    int size = 12;

    int numProcs = 3;

    int rank;
    int lengthProc;
    int localCount;
    int globalCount;
    int RootProcess = 0;
    MPI_Status status;
    int tag = 1;
