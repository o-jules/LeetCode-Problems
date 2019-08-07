

bool isOneBitCharacter(int* bits, int bitsSize){
    if (bits[bitsSize - 1] == 1) {
        return false;
    }

    int i = 0;
    while (i < bitsSize) {
        if (bits[i] == 0) {
            i++;
            if (i == bitsSize) {
                return true;
            }
        } else {
            i++;
            i++;
        }
    }
    return false;
}
