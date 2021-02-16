#include <stdio.h>
#include <time.h>
#include <ctype.h>

// Total months
const int numMonths = 12;

// Month names
const char *month[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

// Day names
const char *day[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};

// Function declaration
int isValidMonth(char monthName[]);

int isValidYear(int year);

int isLeapYear(int year);

int maxMonthDays(int m, int y);

void printCalendar(int monthNum, int year);

int main() {
    // Variable declaration
    int m, y;
    // Get month and year
    printf("Enter MM/YYYY\n");
    scanf("%d/%d", &m, &y);

    // Check if month is valid and get month number
    if ((m > 0) && (m <= 12)) {
        // Check if year is valid
        if ((999 <= y) && (y <= 10000)) {
            // Print calendar
            printCalendar(m, y);
        } else {
            // Print invalid year
            printf("\nInvalid year \'%d\'", y);
        }
    } else {
        // Print invalid month
        printf("\nInvalid month number \'%s\'", m);
    }
    return 0;
}

// This method returns the number of days in the given month for the given year.
int maxMonthDays(int m, int y) {
// If month is February
    if (m == 2) {
        // If year is a leap year
        if (((y % 400) == 0) || (((y % 4) == 0) && ((y % 100) != 0))) {
            return 29;
        } else {
            return 28;
        }
    } else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) ||
               (m == 8) || (m == 10) || (m == 12)) {
        return 31;
    } else {
        return 30;
    }
}

// This method prints the calendar for the given month and year
void printCalendar(int monthNum, int year) {
// Variable declaration
    struct tm tm = {.tm_year = year - 1900, .tm_mon = monthNum - 1,
            .tm_mday = 1, .tm_isdst = -1};
    time_t t;
    int i;

// Initialize t
    t = mktime(&tm);

// Print day names
    for (i = 0; i < 7; i++) {
        printf("%-4s", day[i]);
    }

// Print new line
    printf("\n");

// Get number of days for the given monthNum
    int numDays = maxMonthDays(monthNum, year);

// Get the day of the first day of the given month
    int dayOfWeek = tm.tm_wday;

// Print space to display the first day of the month
    for (i = 0; i < dayOfWeek; i++) {
        printf("%-4s", "");
    }

// Print dates
    for (i = 1; i <= numDays; i++) {
// Check if dayOfWeek is a new week
        if ((dayOfWeek % 7) == 0) {
// Print new line
            printf("\n");
        }

// Print day
        printf("%-4d", i);

// Increment dayOfWeek by 1
        dayOfWeek = dayOfWeek + 1;
    }
}