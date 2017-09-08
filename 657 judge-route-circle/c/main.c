// ascii
// A 65
// U 85
// D 68
// L 76
// R 82

/*
switch(*moves) {
  case 'U': y++; break;
  case 'D': y--; break;
  case 'L': x--; break;
  case 'R': x++; break;
}
*/

bool judgeCircle(char* moves) {
  int x = 0, y = 0;
  int i = strlen(moves);
  char m;
  while(i >= 0) {
    m = moves[i];
    if (m == 85) {
      y++;
    } else if (m == 68) {
      y--;
    } else if (m == 76) {
      x--;
    } else if (m == 82) {
      x++;
    }

    i--;
  }
  return (x == 0 && y == 0);
}
