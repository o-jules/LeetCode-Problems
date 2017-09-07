#include <cmath>

vector<int> constructRectangle(int area) {
  int w = (int) sqrt(area), h;
  vector<int> rect(2, w);

  if (w * w != area) {
    for (; w >= 1; w--) {
      h = area / w;
      if (w * h != area)
        continue;

      rect[0] = h;
      rect[1] = w;
      break;
    }
  }

  return rect;
}
