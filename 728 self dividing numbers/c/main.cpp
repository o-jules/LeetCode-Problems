class Solution {
public:
    bool isSelfDivided(int num) {
        int j = num, k = num % 10;
        while (j > 0) {
            if (k == 0 || num % k != 0) {
                return false;
            }
            j = (j - k) / 10;
            k = j % 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> list;
        for (int i = left; i <= right; i++) {
            if (this->isSelfDivided(i)) {
                list.push_back(i);
            }
        }
        return list;
    }
};
