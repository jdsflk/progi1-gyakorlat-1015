typedef struct {
    int year;
    int month;
    int day;
} date;

int isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

// Returns the index of the day in the year, e. g. jan. 1. -> 1, feb. 2. -> 33
int indexOfDay(date date1) {
    int monthLengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index = date1.day;
    if (isLeapYear(date1.year)) {
        monthLengths[1]++;
    }
    for (int i = 0; i < date1.month - 1; i++) {
        index += monthLengths[i];
    }
    return index;
}

// year1 < year2
int numberOfLeapYearsBetween(int year1, int year2) {
    int fours, hundreds, fourHundreds;
    fours = ((year2 - 1) - (year1 - 1) % 4 - (year1 + 3 - (year1 + 3) % 4)) / 4 + 1;
    /* When I wrote this line only God and I understood it. Now only God understands it.
     * Seriously, I don't know how we came up with the formula, he just wrote it on the board out of the blue.
     * */
    if (fours < 1) {
        return 0;
    }
    /*
     * Weird maths goes here
     * */
    return fours - hundreds + fourHundreds;
}

// date1 < date2
int howManyDaysSince(date date1, date date2) {
    int dayDif = indexOfDay(date2) - indexOfDay(date1);
    return dayDif + 365 * (date2.year - date1.year) + numberOfLeapYearsBetween(date1.year, date2.year);
}