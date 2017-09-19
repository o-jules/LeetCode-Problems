
#define is0x(i)     (i < 128)
#define is10x(i)    (i >= 128 && i < 192)
#define is110x(i)   (i >= 192 && i < 224)
#define is1110x(i)  (i >= 224 && i < 240)
#define is11110x(i) (i >= 240)
#define bool int
#define true 1
#define false 0

bool validUtf8(int* data, int dataSize) {
  int t = 0, acc = 0;
  for (int i = 0; i < dataSize; i++) {
    if (data[i] < 0) return false;

    if (data[i] >= 128 && data[i] < 192) {
      acc++;
      continue;
    }

    if (t != acc) return false;

    // this is important!
    if (data[i] >= 248)  return false;

    if (data[i] < 128) {
      t = 0;
    } else if (data[i] >= 240) {
      t = 3;
    } else if(data[i] >= 224) {
      t = 2;
    } else if(data[i] >= 192) {
      t = 1;
    }
    acc = 0;
  }

  return t == acc;
}

int main(void) {
  // test:
  // [248,130,130,130] -> false
}
