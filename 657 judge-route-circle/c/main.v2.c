
// 'U' - 'A' = 20
// 'D' - 'A' = 3
// 'L' - 'A' = 11
// 'R' - 'A' = 17
// ascii
// A 65
//
// U 85
// D 68
// L 76
// R 82



bool judgeCircle(char* moves) {
  int array[26] = {0};
  while(*moves) {
    array[*(moves++) - 'A']++;
  }

  return (array[20] == array[3]) &&
        (array[11] == array[17]);
}

/**
  // 也可以想办法减小数组的大小
  // 以 moves / 10 % 2 替代 moves - 'A' 作 index

  bool judgeCircle(char* moves) {
    int a[6] = {0};
    while(*moves) {
      a[*moves/4]++;
      moves++;
    }
    return (a[3] == a[1]) && (a[2] == a[0]);
  }
**/
