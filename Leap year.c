/*Write a C program that determines whether
a given year is a leap year, 
considering the century rule (a year is a leap year if it is divisible by 4, 
but not divisible by 100, unless it is also divisible by 400).
*/

#include<stdio.h>
int main()
{
    int year, result;

    printf("Enter a year to check if it's a leap year: ");
    result = scanf("%d",&year);

    if (result!=1){
        printf("Please enter a valid year.");
    } else if (year<0) {
        printf("Enter a non-negative year.");
    } else if (year%400==0){
        printf("It is a leap year.\n");
    } else if (year%100==0){
        printf("It is not a leap year.\n");
    } else if (year%4==0){
        printf("It is a leap year.\n");
    } else {
        printf("It is not a leap year.\n");}
    return 0;
}