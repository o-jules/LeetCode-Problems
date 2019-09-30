

int maxDistToClosest(int* seats, int seatsSize){
    int md = 1;
    int has_left = 0;

    int d = 0;
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 0) {
            d++;
        } else {
            if (d > 0) {
                d = has_left == 0 ? d : (d + d % 2) / 2;
                if (d > md) md = d;
            }
            d = 0;
            has_left = 1;
        }
    }
    if (d > md) {
        md = d;
    }

    return md;
}
