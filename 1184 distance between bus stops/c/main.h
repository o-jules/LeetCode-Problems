int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    if (start == destination) {
        return 0;
    }
    if (distanceSize == 1) {
        return distance[0];
    }

    int cw = 0, ccw = 0; // clockwise, counterclockwise
    int f = start < destination ? start : destination;
    int e = start > destination ? start : destination;

    for (int i = f; i < e; i++) {
        cw += distance[i];
    }

    for (int i = e; i < distanceSize; i++) {
        ccw += distance[i];
    }
    for (int i = 0; i < f; i++) {
        ccw += distance[i];
    }

    return cw < ccw ? cw : ccw;
}
