#include <stdio.h>
#include <string.h>

#define LEAP_YEAR(Y) (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))

char* get_month_name(int month, char *mName) {
    switch (month) {
        case 1:
            strcpy(mName, "January");
            break;
        case 2:
            strcpy(mName, "February");
            break;
        case 3:
            strcpy(mName, "March");
            break;
        case 4:
            strcpy(mName, "April");
            break;
        case 5:
            strcpy(mName, "May");
            break;
        case 6:
            strcpy(mName, "June");
            break;
        case 7:
            strcpy(mName, "July");
            break;
        case 8:
            strcpy(mName, "August");
            break;
        case 9:
            strcpy(mName, "September");
            break;
        case 10:
            strcpy(mName, "October");
            break;
        case 11:
            strcpy(mName, "November");
            break;
        case 12:
            strcpy(mName, "December");
            break;
        default:
            printf("Invalid month\n");
            break;
    }
    return mName;
}

int get_days_in_month(int month, int year) {
    int days;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = LEAP_YEAR(year) ? 29 : 28;
            break;
    }
    return days;
}

// Returns the day of the week of the first day of the given month and year
int get_day_of_week(int month, int year) {
    int day, days;
    days = get_days_in_month(month, year);
    day = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + days) % 7;
    return day;
}

// Function that prints months names and days of the week
void print_month(int month, int year) {
    int i, j, k, days, day;
    char mName[10];
    days = get_days_in_month(month, year);
    day = get_day_of_week(month, year);
    printf("\n%s %d\n", get_month_name(month, mName), year);
    printf(" S  M  T  W  T  F  S\n");
    for (i = 0; i < day; i++) {
        printf("   ");
    }
    for (j = 1; j <= days; j++) {
        printf("%2d ", j);
        if ((j + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void print_calendar(int year) {
    int month, day, days, start;
    char mName[20];

    start = get_day_of_week(1, year);
    for (month = 1; month <= 12; month++) {
        print_month(month, year);
    }
}

int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    print_calendar(year);
    return 0;
}
