#include<stdio.h>
#include<string.h>

struct menu{
    int itemNo;
    char list[20];
    float unitPrice;
};

int main(){
    int order=0;
    char Name[10];

    struct menu List[5];
    for (int i = 0; i < 5; i++){
        List[i].itemNo = i+1;
    }

    strcpy(List[0].list, "Americano");
    strcpy(List[1].list, "Cappuccino");
    strcpy(List[2].list, "Iced Latte");
    strcpy(List[3].list, "Blueberry Muffin");
    strcpy(List[4].list, "Croissant");
    
    List[0].unitPrice = 120.00;
    List[1].unitPrice = 135.00;
    List[2].unitPrice = 140.00;
    List[3].unitPrice = 95.00;
    List[4].unitPrice = 85.00;
    

    printf("Welcome to CoffeeHouse!\nPlease enter your name: ");
    fgets(Name, 10, stdin);
    Name[strcspn(Name, "\n")] = '\0';

    printf("------ Menu -------\n");
    printf("[1] Americano           (Drink)        - ₱120.00\n");
    printf("[2] Cappuccino          (Drink)        - ₱135.00\n");
    printf("[3] Iced Latte          (Drink)        - ₱140.00\n");
    printf("[4] Blueberry Muffin    (Pastry)       - ₱95.00\n");
    printf("[5] Croissant           (Pastry)       - ₱85.00\n\n");

    printf("How many items would you like to order? ");
    scanf("%d", &order);
    while(getchar() != '\n');

    float total[order], subtotal=0, fTotal=0, tax=0;
    int itemNo[order];
    int qty[order];

    for (int i = 0; i < order; i++){
        printf("Enter item number: ");
        scanf("%d", &itemNo[i]); while (getchar()!='\n');
        printf("Enter quantity: ");
        scanf("%d", &qty[i]); while (getchar()!='\n');
        
        itemNo[i] = List[itemNo[i]-1].itemNo;
        total[i] = List[itemNo[i]-1].unitPrice * (float)qty[i];
        subtotal += total[i];
    }

    if (subtotal > 500){
        subtotal = subtotal - (subtotal*0.05);
    }
    
    tax = subtotal * 0.12;
    fTotal = subtotal + tax;   

    printf("------ Receipt -------\n");
    printf("Customer: %s\n\n", Name);

    printf("%-20s %5s %12s %12s\n", "Item", "Qty", "Unit Price", "Total");
    for (int i = 0; i < order; i ++){
        printf("%-20s %5d %12.2f %12.2f\n", List[itemNo[i] - 1].list, qty[i], List[itemNo[i] - 1].unitPrice, total[i]);
    }

    printf("\n\nSubtotal:                           ₱%.2f\n", subtotal);
    printf("Tax (12%%):                           ₱%.2f\n", tax);
    printf("---------------------------------------------------\n");
    printf("TOTAL:                                 ₱%.2f\n\n", fTotal);

    printf("Thank you for dining at CoffeeHouse!\n");
    
    return 0;
}