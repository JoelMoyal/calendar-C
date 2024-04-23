#include <stdio.h>  // Including the standard input/output library
#include <stdlib.h> // Including the standard library functions

// Function to calculate the first weekday of a given year
int get_1st_weekday(int year)
{
    // Formula to calculate the weekday (0-6)
    int d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}

int main()
{

    // Declaring variables for year, month, day, daysInMonth, weekDay, and startingDay
    int year, month, day, daysInMonth, weekDay = 0, startingDay;

    // Prompting the user to enter a year
    printf("\nEnter Year:");
    scanf("%d", &year);

    // Defining an array of month names
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Defining an array of days in each month
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Checking if the year is a leap year and adjusting the number of days in February accordingly
    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0)
        monthDay[1] = 29;

    // Calculating the starting weekday of the year
    startingDay = get_1st_weekday(year);

    // Looping through each month
    for (month = 0; month < 12; month++)
    {
        // Setting the number of days in the current month
        daysInMonth = monthDay[month];

        // Printing the month name and a separator
        printf("\n\n--------------%s------------------\n", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        // Printing empty spaces for the days before the first day of the month
        for (weekDay = 0; weekDay < startingDay; weekDay++)
            printf("     ");

        // Looping through each day in the month
        for (day = 1; day <= daysInMonth; day++)
        {
            // Printing the day number
            printf("%5d", day);

            // Incrementing the weekday and checking if it's greater than 6
            if (++weekDay > 6)
            {
                // If it is, print a newline and reset the weekday to 0
                printf("\n");
                weekDay = 0;
            }
            // Updating the starting weekday for the next month
            startingDay = weekDay;
        }
    }
}