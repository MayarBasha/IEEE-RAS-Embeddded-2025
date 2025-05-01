#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
}date1,date2;

// Function to compare two dates using pointers
int compareDates(struct Date *d1, struct Date *d2) {
    return (d1->day == d2->day && d1->month == d2->month && d1->year == d2->year);
}

int main() {


    // Pointers to the structures
    struct Date *ptr1 = &date1;
    struct Date *ptr2 = &date2;


    printf("Enter first date (d m y): ");
    scanf("%d %d %d", &ptr1->day, &ptr1->month, &ptr1->year);

    printf("Enter second date (d m y): ");
    scanf("%d %d %d", &ptr2->day, &ptr2->month, &ptr2->year);

    // Compare the dates
    if (compareDates(ptr1, ptr2)) {
        printf("Dates are equal.\n");
    } else {
        printf("Dates are not equal.\n");
    }

    return 0;
}

