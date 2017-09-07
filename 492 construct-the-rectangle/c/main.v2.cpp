vector<int> constructRectangle(int area) {
  vector<int> r(2, (int) sqrt(area));

    if (r[0] * r[1] != area) {
      for (; r[1] >= 1; r[1]--) {
        r[0] = area / r[1];

        if (r[0] * r[1] != area)
          continue;

        break;
      }
    }

    return r;
}
