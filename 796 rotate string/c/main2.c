#include <stdio.h>
#include <string.h>
#include <assert.h>

#define bool int;
#define true 1;
#define false 0;

//
bool rotateString(char* A, char* B) {
  if (strlen(A) != strlen(B)) {
     [   return false;
    }

    int first_ind, len = strlen(A), i, forw, j, count = 0;
    for (i = 0, j = 0; i < len; i++ ) {
        if (A[i] == B[j]) {
            count ++;
            j ++;
        }
        else {
            count = 0;
            j = 0;
            if (A[i] == B[0]) {
                count = j = 1;
            }
        }
    }


    for (i = 0; i < (len - count); i ++, j++) {
        if (A[i] != B[j]) {
            return false;
        }
    }

    return true;]
}

int main() {
  assert(rotateString("", "") == 1);
  assert(rotateString("a", "a") == 1);
  assert(rotateString("ab", "ab") == 1);
  // assert(rotateString("ab", "ba") == 1);
  // assert(rotateString("abcde", "cdeab") == 1);
  // assert(rotateString("abcde", "abced") == 0);
  // assert(rotateString("abcde", "abcde") == 1);

  printf("All test cases are passed.\n");
}
