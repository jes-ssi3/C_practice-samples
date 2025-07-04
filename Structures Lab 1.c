#include<stdio.h>
#include<string.h>

/*
Structures Activity
May 13, 2025
*/

int main(){
    //struct and variable declarations
    struct sales{
        char computer_ID[10];
        int time_In, time_Out;
    };
    
    struct sales rental;

    int time, mins, hours;
    float amount;
    char again[4];
    int flag = 1;

    do{
    
    printf("ABC Computer Center Daily Monitoring Report\n\n");
    
    printf("Computer_ID: ");

    //input computer ID, depends on the center's naming system
    scanf("%s", rental.computer_ID);
    
    //input time in and time out in military format
    printf("Time-IN(in military format): ");
    scanf("%d", &rental.time_In);
    printf("Time-OUT(in military format): ");
    scanf("%d", &rental.time_Out);
    
    //time in and time out validation
    if((rental.time_In<0||rental.time_Out<0) //if negative time input
        ||(rental.time_In>2400||rental.time_Out>2400) //if more than military hour format
        ||(rental.time_In>rental.time_Out) //if rental time in is more than rental time out
        ||(rental.time_In % 100 > 59|| rental.time_Out % 100 >59)) //if minutes is more than 59
        {
        printf("Invalid time.\n"); //error message
    } else {
        time = rental.time_Out - rental.time_In;
        hours = time/100;
        mins = time%100;
        amount = hours*12 + mins*0.20; //computer rental is 12.00 per hr and 0.20 for remaining minutes
        
        //when minutes exceed, add to hours
        if (mins > 59){
            hours += mins/60;
            mins%=60;
        }

        if (hours == 1){
        printf("Number of hours and minutes spent: %d hour and %d minutes\n", hours, mins);
        } else {
        printf("Number of hours and minutes spent: %d hours and %d minutes\n", hours, mins);
        }
        printf("Amount to be paid: %.2f\n", amount);
    }
    
    
    // Ask to try again
    flag = 0;  // Reset flag
    do {
        printf("Do you want to try again? (yes/no): ");
        scanf("%s", again);
        if (strcasecmp(again, "yes") == 0) {
            flag = 1;
        } else if (strcasecmp(again, "no") == 0) {
            flag = 0;
        } else {
            printf("Please enter yes or no.\n");
        }
    } while (strcasecmp(again, "yes") != 0 && strcasecmp(again, "no") != 0);

    } while (flag == 1);

    return 0;
}