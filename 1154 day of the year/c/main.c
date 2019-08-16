

int dayOfYear(char * date){
    int month =  (date[5] - '0') * 10 + (date[6] - '0');
    int day_of_month = 10 * (date[8] - '0') + (date[9] - '0');

    int is_leap_year = 0;
    if (month > 2) {
        int year =
            (date[0] - '0') * 1000 + (date[1] - '0') * 100 +
            (date[2] - '0') * 10 + (date[3] - '0');
        is_leap_year = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }

    int days = day_of_month;
    for (int i = 1; i < month; i++) {
        days += i == 2 ?
                (is_leap_year ? 29 : 28) :
                ((i <= 7 && i % 2 == 1) || (i >= 8 && i % 2 == 0)) ? 31 : 30;
    }
    return days;
}

