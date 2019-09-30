#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int largestPerimeter(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmpfunc);

    for (int i = 0; i <= ASize - 3; i++) {
        if (A[i] < A[i+1] + A[i+2]) {
            return A[i] + A[i+1] + A[i+2];
        }
    }

    return 0;
}

