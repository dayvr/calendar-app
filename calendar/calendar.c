#include <stdio.h>
#include <string.h>

char* get_month_name(int month, char *name);
char* get_day_name(int day, char *name);
int get_days_in_month(int month, int year);
int get_leap_year(int year);
void print_calendar(int year);
int get_day_of_week(int month, int year);

int main(int argc, char *argv[]) {
    int day, month, year;
    char mName[20];

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("\n");
    printf("%d\n\n", year);
    print_calendar(year);
    return 0;
}

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

char* get_day_name(int day, char *dName) {
    switch (day) {
        case 1:
            strcpy(dName, "Sunday");
            break;
        case 2:
            strcpy(dName, "Monday");
            break;
        case 3:
            strcpy(dName, "Tuesday");
            break;
        case 4:
            strcpy(dName, "Wednesday");
            break;
        case 5:
            strcpy(dName, "Thursday");
            break;
        case 6:
            strcpy(dName, "Friday");
            break;
        case 7:
            strcpy(dName, "Saturday");
            break;
    }
    return dName;
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
            days = get_leap_year(year);
            break;
    }
    return days;
}

int get_leap_year(int year) {
    int leap;
    if (year % 4 == 0 && year % 100 != 0) {
        leap = 29;
    } else {
        leap = 28;
    }
    return leap;
}

void print_calendar(int year) {
    int month, days;
    char mName[20], dName[20];

    for (month = 1; month <= 12; month++) {
        days = get_days_in_month(month, year);
        get_month_name(month, mName);
        printf("%s\n", mName);
        printf(" M  T  W  T  F  S  S\n");
        
        for (int i = 1; i <= days; i++) {
            printf("%2d ", i);
            if (i % 7 == 0 || i == days) {
                printf("\n");
            }
        }
        printf("\n");
    }
    
}

// Return index of day of week
int get_day_of_week(int month, int year) {
    int day, days;
    days = get_days_in_month(month, year);
    day = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + days) % 7;
    return day;
}
