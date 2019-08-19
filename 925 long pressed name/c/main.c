

bool isLongPressedName(char * name, char * typed){
    int i = 0, i2 = 1;
    int j = 0, j2 = 1;
    while (name[i]) {
        if (name[i] != typed[j]) {
          return false;
        }

        while (name[i2]) {
            if (name[i2] != name[i]) {
                break;
            }
            i2++;
        }

        while (typed[j2]) {
            if (typed[j2] != typed[j]) {
                break;
            }
            j2++;
        }
        if (i2 - i > j2 - j) {
            return false;
        }

        i = i2++;
        j = j2++;
    }

    return name[i] == '\0' && typed[j] == '\0';
}

