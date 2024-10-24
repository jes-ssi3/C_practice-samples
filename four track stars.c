#include<stdio.h>

void display_menu ()
{
    printf("\nFour Track Stars: Penn Relay\n");
    printf("1. Runner 1\n");
    printf("2. Runner 2\n");
    printf("3. Runner 3\n");
    printf("4. Runner 4\n");
}

int user_choice()
{
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    int choice;

    while (2){
        display_menu();
        choice = user_choice();

        switch (choice){
            case 1:
            {
                float minutes, seconds, scs, fps, mps;

                printf("Enter minutes of runner 1: ");
                scanf("%f", &minutes);
                printf("Enter remaining seconds of runner 1: ");
                scanf("%f", &seconds);

                scs=(minutes*60)+seconds;
                fps=5280/scs;
                mps=fps/3.282;

                printf("Runner 1 fps is %.2f and mps is %.2f", fps, mps);          

            }
            break;
            case 2:
            {
                float minutes, seconds, scs, fps, mps;

                printf("Enter minutes of runner 2: ");
                scanf("%f", &minutes);
                printf("Enter remaining seconds of runner 2: ");
                scanf("%f", &seconds);

                scs=(minutes*60)+seconds;
                fps=5280/scs;
                mps=fps/3.282;

                printf("Runner 2 fps is %.2f and mps is %.2f", fps, mps); 
            }
            break;
            case 3:
            {
                float minutes, seconds, scs, fps, mps;

                printf("Enter minutes of runner 3: ");
                scanf("%f", &minutes);
                printf("Enter remaining seconds of runner 3: ");
                scanf("%f", &seconds);

                scs=(minutes*60)+seconds;
                fps=5280/scs;
                mps=fps/3.282;

                printf("Runner 3 fps is %.2f and mps is %.2f", fps, mps); 
            }
            break;
            case 4:
            {
                float minutes, seconds, scs, fps, mps;

                printf("Enter minutes of runner 4: ");
                scanf("%f", &minutes);
                printf("Enter remaining seconds of runner 4: ");
                scanf("%f", &seconds);

                scs=(minutes*60)+seconds;
                fps=5280/scs;
                mps=fps/3.282;

                printf("Runner 4 fps is %.2f and mps is %.2f", fps, mps); 
            }
            break;
        }
    }
    return 0;
}