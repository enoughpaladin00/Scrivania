#include <stdio.h>
#include <stdlib.h>

//Definisco una struttura dati per rappresentare una data
typedef struct Date{
    int day;
    int month;
    int year;
} Date;

//Function that fill the data structure Date
int stringToDate(Date* date, char** buffer);

//Function that calculates the middle date
void computeMidDate(Date* date1, Date* date2, Date* result);

//Function that tells if the year is a leap year
int isLeapYear(int year){
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int howManyLeap(int year){
    int count = 0;
    for(int i = 0; i <= year; i++){
        if((i%4 == 0 && i%100 != 0)|| i%400 == 0)
            count++;
    }
    return count;
}

//Function that tells how many days there are in that month of that year
int daysInMonth(int year, int month){
    static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 && isLeapYear(year)? 29 : days[month-1];
}

//Function that counts days since 1st Jan 0 a.C.
int absoluteDate(Date* date){
    int year = date->year, month = date->month;
    //Calculating the days
    int days = date->day;           //DAYS

    for(int i = 1; i < month; i++) //MONTH
        days += daysInMonth(year, i);
    
    int leapYear = howManyLeap(year);
    days += (leapYear * 366) + (year - leapYear) * 365;
    
    //printf("%d/%d/%d %d %d\n", date->day, month, year, days, leapYear);
    return days;
}

//Function that transforms an absolute day in a date
void absIntoDate(Date* date, int abs){
    int year = 0;
    while(abs >= 366){
        if(isLeapYear(year))
            abs-=366;
        else
            abs-=365;
        year++;
    }
    int month = 1;
    while(abs > daysInMonth(year, month)){
        abs -= daysInMonth(year, month);
        month++;
    }

    date->year = year;
    date->month = month;
    date->day = abs;
    return;
}

int main(int argc, char** argv){
    //Allocating spaces for data structures
    Date* date1 = (Date*)malloc(sizeof(Date));
    Date* date2 = (Date*)malloc(sizeof(Date));
    Date* result = (Date*)malloc(sizeof(Date));
    char* buffer = (char*)malloc(sizeof(char) * 11);

    //Filling the dates
    scanf("%s", buffer);
    fflush(stdin);
    if(stringToDate(date1, &buffer)){
        return 1;
    }
    
    scanf("%s", buffer);
    fflush(stdin);
    if(stringToDate(date2, &buffer)){
        return 1;
    }

    //Freeing the space dynamically allocated
    free(buffer);

    //Computing the middle data
    computeMidDate(date1, date2, result);

    //Printing the result
    printf("RISULTATO:\n%d/%d/%d\n", result->day, result->month, result->year);
    free(date1);
    free(date2);
    free(result);
    return 0;
}

int stringToDate(Date* date, char** buffer){
    char* temp = *buffer;

    //Parsing the date
    temp[2] = '\n';
    temp[5] = '\n';
    temp[10] = '\n';
    date->day = atoi(temp);
    date->month = atoi(temp + 3);
    date->year = atoi(temp + 6);

    //Checking date semantic
    if(date->day > 31 || date->day < 1 || date->month < 1 || date->month > 12)
        return 1;
    if(date->month == 2 && date->day > 29)
        return 1;
    if((date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) && date->day > 30)
        return 1;
    
    return 0;
}

void computeMidDate(Date* date1, Date* date2, Date* result){
    
    int abs1 = absoluteDate(date1);
    int abs2 = absoluteDate(date2);
    int abs3 = (abs1 + abs2)/2;
    printf("%d %d %d\n", abs1, abs2, abs3);
    absIntoDate(result, abs3);
    
}
