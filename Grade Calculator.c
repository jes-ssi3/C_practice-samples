#include<stdio.h>

int main (){
    float grade;

    printf("Enter the student's score (0-100): ");
    scanf("%f", &grade);

    if (grade<0||grade>100){
        printf("Invalid input. Please enter from 0-100");
    } else if (grade>=90) {
        printf("The grade is: A");
    } else if (grade>=80) {
        printf("The grade is: B");
    } else if (grade>=70) {
        printf("The grade is: C");
    } else if (grade>=60) {
        printf("The grade is: D");
    } else if (grade>60){ 
        printf("The grade is: F"); 
    } else {
        printf("Please enter a valid number.");
    }
return 0;
}