
bool canThreePartsEqualSum(int* A, int ASize) {
    if (ASize >= 3) {
        int sum = 0;
        for (int i = 0; i < ASize; i++) {
            sum += A[i];
        }

        if (sum % 3 == 0) {
            sum /= 3;
            int s = sum, i = 0, j = 0;
            while (i < ASize) {
                s -= A[i++];
                if (s == 0) {
                    if (j++ == 2) {
                        return true;
                    }
                    s = sum;
                }
            }
        }
    }

    return false;
}
