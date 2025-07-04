#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Book{
    char title[50];
    char author[30];
    char isbn[15];
    float price;
    int quantity;
};

void inFile(struct Book book[]){
    FILE *a = fopen("book.dat", "wb");

    if (a == NULL){
        printf("Error...\n");
    }
    
    
    strcpy(book[0].title, "The Hobbit");
    strcpy(book[1].title, "A Brief History of Time");
    strcpy(book[2].title, "Clean Code");
    strcpy(book[3].title, "The Catcher in the Rye");
    strcpy(book[4].title, "To Kill a Mockingbird");
    strcpy(book[5].title, "1984");
    strcpy(book[6].title, "The Great Gatsby");
    strcpy(book[7].title, "Atomic Habits");
    strcpy(book[8].title, "The Alchemist");
    strcpy(book[9].title, "Deep Work");

    strcpy(book[0].author, "J.R.R Tolkien");
    strcpy(book[1].author, "Stephen Hawking");
    strcpy(book[2].author, "Robert C. Martin");
    strcpy(book[3].author, "J.D. Salinger");
    strcpy(book[4].author, "Harper Lee");
    strcpy(book[5].author, "George Orwell");
    strcpy(book[6].author, "F. Scott Fitzgerald");
    strcpy(book[7].author, "James Clear");
    strcpy(book[8].author, "Paulo Coelho");
    strcpy(book[9].author, "Cal Newport");

    strcpy(book[0].isbn, "9780547928227");
    strcpy(book[1].isbn, "9780553380163");
    strcpy(book[2].isbn, "9780132350884");
    strcpy(book[3].isbn, "9780316769488");
    strcpy(book[4].isbn, "9780060935467");
    strcpy(book[5].isbn, "9780451524935");
    strcpy(book[6].isbn, "9780743273565");
    strcpy(book[7].isbn, "9780735211292");
    strcpy(book[8].isbn, "9780061122415");
    strcpy(book[9].isbn, "9781455586691");

    float prices[10] = {499,550, 650, 420, 480, 390, 360, 730, 410, 620};

    int quantity[10] = {10, 7, 5, 4, 8, 6, 9, 12, 10, 3};

    for (int i = 0; i < 10; i++){
        book[i].price = prices[i];
        book[i].quantity = quantity[i];
        fwrite(&book[i], sizeof(struct Book), 1, a);

    }

    fclose(a);
}

void displayAll(struct Book book[]){
    FILE *a = fopen("book.dat", "rb");

    if (a == NULL){
        printf("Error...\n");
    }


    for (int i = 0; i < 10; i++){
        fread(&book[i], sizeof(struct Book), 1, a);
    }

    

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9-1; j++){
            if(strcmp(book[j].title, book[j+1].title) > 0){
                struct Book temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    

    printf("--------------------------------------------------\n");
    printf("%-30s %20s %20s %5s\n", "Title", "Author", "Price", "Qty");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 10; i++){
        printf("%-30s %20s %20.2f %5d\n", book[i].title, book[i].author, book[i].price, book[i].quantity);
    }

    fclose(a);
}

int search(struct Book book[]){

    FILE *a = fopen("book.dat", "rb");

    for (int i = 0; i < 10; i++){
        fread(&book[i], sizeof(struct Book), 1, a);
    }

    

    char isbnSearch[15];
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9-1; j++){
            if(strcmp(book[j].isbn, book[j+1].isbn) > 0){
                struct Book temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    printf("Search ISBN: ");
    fgets(isbnSearch, 15, stdin);

    int n = 10;
    int low = 0, high = n - 1;

    while (low <= high){
        int mid = (low + high) / 2;
        int compare = strcmp(book[mid].isbn, isbnSearch);

        if (compare == 0){
            return mid;
        } else if (compare < 0){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    fclose(a);

    return -1;
}

void purchase (struct Book book[]){

    FILE *a = fopen("book.dat", "rb");

    for (int i = 0; i < 10; i++){
        fread(&book[i], sizeof(struct Book), 1, a);
    }

    
    char isbn[15];
    int flag = 0, qty;

    printf("Enter ISBN: ");
    fgets(isbn, 15, stdin);
    
    int n = 10, purchase;
    int low = 0, high = n - 1;

    while (low <= high){
        int mid = (low + high) / 2;
        int compare = strcmp(book[mid].isbn, isbn);

        if (compare == 0){
            flag = 1;
            printf("Available.\n");
            purchase = mid;
            break;
        } else if (compare < 0){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (flag == 1){
        float subtotal=0, discount=0, tax=0, fTotal=0;
        printf("Enter quantity: ");
        scanf("%d", &qty);
        while(getchar() != '\n');

        subtotal = book[purchase].price * qty;
        book[purchase].quantity -= qty;

        printf("\n\nSubtotal: Php%.2f\n", subtotal);
        discount = subtotal*.10;
        subtotal -= discount;
        tax = subtotal*.12;
        fTotal = subtotal + tax;
        printf("Discount (10%%): -Php%.2f\n", discount);
        printf("Tax (12%%): Php%.2f\n", tax);
        printf("TOTAL: Php%.2f\n", fTotal);

        printf("\nPurchase successful!\n");
        

    } else {
        printf("Not available.\n");
    }

    fclose(a);
    
}
int main(){
    int choice = 0;
    struct Book b[10];
    inFile(b);

    while (1){
    printf("Welcome to BookNook!\nPlease choose:\n");
    printf("[1] View All Books\n[2] Search Book by ISBN\n[3] Purchase Book\n[4] Exit\nEnter choice: ");
    scanf("%d", &choice); while (getchar() != '\n');

    switch (choice){
        case 1:{ displayAll(b); break;}

        case 2: {
        int a = search(b);
        if(a == -1){ printf("Not found.\n"); }
        else {printf("Founded.\n");}
        break;
        }
        case 3:{
        purchase(b);
        break;
        }
        case 4:{ printf("Exiting..."); return 0;}

        default:{ printf("Incorrect input. Please try again.\n");}
    }
}

    return 0;

}