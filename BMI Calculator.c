/*BMI= height/weight^2
 BMI < 18.5: Underweight
18.5 ≤ BMI < 24.9: Normal weight
25 ≤ BMI < 29.9: Overweight
BMI ≥ 30: Obesity
*/

#include<stdio.h>

int main (){
    float weight=0, height=0, bmi=0, r1, r2;

    printf("Enter your weight (in kg): ");
    r1 = scanf("%f", &weight);
    printf("Enter your height (in meters): ");
    r2 = scanf("%f", &height);

    bmi=weight/(height*height);

    if (r1!=1&&r2!=1){
        printf("\nInvalid input. Please enter valid numerical values for both weight and height.");
    } else if (weight<=0||height<=0){
        printf("\nInvalid input. Please enter a positive numerical weight and height.");
    } else if (bmi>=30) {
        printf("Your BMI is %.2f. You are in the Obesity category.", bmi);
    } else if (bmi<30 && bmi>=25) {
        printf("Your BMI is %.2f. You are in the Overweight category.", bmi);
    } else if (bmi<25&& bmi>=18.5) {
        printf("Your BMI is %.2f. You are in the Normal weight category.", bmi);
    } else {
        printf("Your BMI is %.2f. You are in the Underweight catergory.", bmi);
    }
    return 0;
}