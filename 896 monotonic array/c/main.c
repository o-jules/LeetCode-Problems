
#include <stdbool.h>

bool isMonotonic(int* A, int ASize){
    if (ASize <= 1) {
        return true;
    }
    int order = 0; // 0 equal, 1 decrease, 2 increase
    for (int i = 1; i < ASize; i++) {
        if (order == 0 && A[i] != A[i - 1]) {
            order = A[i - 1] > A[i] ? 1 : 2;
        } else if (order == 1 && A[i - 1] < A[i]) {
            return false;
        } else if (order == 2 && A[i - 1] > A[i]) {
            return false;
        }
    }

    return true;
}
