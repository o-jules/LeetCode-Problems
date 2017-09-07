#include <cmath>

vector<int> constructRectangle(int area) {
  int w, h;
  int gap = -1;
  vector<int> rect(2, 0);
  int half = (int) sqrt(area);

  for (w = 1; w <= half; w++) {
    h = area / w;
    if (w * h - area == 0 && w <= h) {
      if (h - w == 0) {
        return {h, w};
      } else {
        if (h - w > gap) {
          rect[0] = h;
          rect[1] = w;
        }
      }
    }
  }

  return rect;
}
