

bool lemonadeChange(int* bills, int billsSize){
    int five = 0;
    int ten = 0;
    for (int i = 0; i < billsSize; i++) {
        switch (bills[i]) {
            case 5: {
                five++;
                break;
            }
            case 10: {
                if (--five < 0) {
                    return false;
                }
                ten++;
                break;
            }
            default: {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}
