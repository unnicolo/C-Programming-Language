/*
** Exercise 5-8 - The C Programming Language
** Created 27.07.17
*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
    int year, yearday, month, day;

    // In a non-leap year the 60th day is March 1st.
    year = 1987;
    yearday = 60;
    month_day(year, yearday, &month, &day);
    printf("The day number %3d of the year %4d is %d.%d\n",
           yearday, year, day, month);
    printf("It should be March 1st: 1.3\n");

    // In a leap year (1988 is a leap year) the 60th day is Feb 29.
    year = 1988;
    month_day(year, yearday, &month, &day);
    printf("The day number %3d of the year %4d is %d.%d\n",
          yearday, year, day, month);
    printf("It should be Feb 29th: 29.2\n");

    // Vice versa entering March 1st in a leap your should give 60th day
    // and 61st day in a leap year.
    year = 1987;
    month = 3;
    day = 1;
    yearday = day_of_year(year, month, day);
    printf("The yearday of %d.%d.%4d is %3d\n", day, month, year, yearday);
    printf("It should be the 60th day.\n");

    year = 1988;
    yearday = day_of_year(year, month, day);
    printf("The yearday of %d.%d.%4d is %3d\n", day, month, year, yearday);
    printf("It should be the 61st day.\n");

    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_of_year: set day of year from month and day
// We check for the following errors:
//   Year provided is invalid (year is negative)
//   Month provided is invalid (not in 1...12)
//   Day provided is invalid (not in 1...365)
// In the case an error is detected, we return -1 as the special error value.
int day_of_year(int year, int month, int day) {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 365) {
        return -1;
    }
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++) {
        //day += daytab[leap][i];
        day += *(*(daytab + leap) + i);
    }
    return day;
}

// month_day: set month, day from day of year
// We check for the following errors:
//   the provided year is invalid (year is negative)
//   provided day is an invalid number (not in 1...365)
// In case a error is detected, we set the values pmonth and pday point to
// to -1 as a special error value.
void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year < 0 || yearday < 1 || yearday > 365) {
        *pmonth = -1;
        *pday = -1;
    }

    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
        yearday -= *(*(daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yearday;
}
