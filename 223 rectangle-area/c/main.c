#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a): (b))
#define MAX(a, b) ((a) > (b) ? (a): (b))
#define DIFF(a, b) (((a) <= 0 && (b) > 0) ? -1 : ((a) - (b)))

int computeArea(
  int A, int B, int C, int D,
  int E, int F, int G, int H
) {
  int r = MIN(C, G), l = MAX(A, E);
  int t = MIN(D, H), b = MAX(B, F);
  int w = DIFF(r, l);
  int h = DIFF(t, b);

  return (C-A)*(D-B) - ((w>0 && h>0)? (w*h): 0) + (G - E) * (H - F);
}

void test(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
  printf("area is = %d\n", computeArea(x1, y1, x2, y2, X1, Y1, X2, Y2));
}

int main(void) {
  test(-3,0, 3,4, 0,-1, 9,2);    // 45
  test(-2,-2, 2,2, -2,-2, 2,2);  // 16
  test(0,0, 0,0, -1,-1, 1,1);    // 4
  test(-2,-2, 2,2, 3,3, 4,4);    //17
  test(-2,-2, 2,2, -3,-3, 3,-1); // 24
  test(-2,-2, 2,2, -1,4, 1,6);   // 20
  test(-1500000001,0, -1500000000,1, 1500000000,0, 1500000001, 1); // 2
}
