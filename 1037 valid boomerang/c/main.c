

bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    pointsColSize = 2;

    for (int i = 0; i < 3; i++) {
        int j = i == 2 ? 0 : i + 1;
        int *p1 = points[i];
        int *p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1]) {
            return false;
        }
    }

    int *p1 = points[0], *p2 = points[1], *p3 = points[2];
    if ((p1[0] - p2[0]) * (p2[1] - p3[1]) == (p1[1] - p2[1]) * (p2[0] - p3[0])) {
        return false;
    }

    return true;
}
