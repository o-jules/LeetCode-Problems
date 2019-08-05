
#include <stdio.h>
#include <stdbool.h>

// the readable version
bool validMountainArray(int* A, int ASize){
    if (ASize < 3 || A[1] <= A[0]) {
      return false;
    }

    int i = 0, j = ASize - 1;
    while(A[i + 1] > A[i]){
        i++;
        if (i == j) {
          return false;
        }
    }

    while(A[i + 1] < A[i]) {
        i++;
        if (i == j) {
          return true;
        }
    }
    return i == j;
}

int main(int argc, char **argv) {
  int list[] = {1,3,2};

  bool is = validMountainArray(list, 3);
  if (is) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  return 0;
}
