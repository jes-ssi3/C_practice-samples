#include<stdio.h>

/*
Binary Search Testing
May 23, 2025
*/

int binary_search(int a[], int e, int l, int r);

int binary_search(int a[], int e, int l, int r){
    int mid = l + (r - l) / 2;

    if (a[mid] == e){
        return mid;
    } else if (a[mid] > e){
        binary_search(a, e, l, mid - 1);
    } else if (a[mid] < e){
        binary_search(a, e, mid + 1, r);
    } else {
        return 1;
    }
}

int main(){
    int n[10] = {1,2,3,4,5,7,8,9,10,13};
    int target;

    for(int i = 0; i < 10; i++){
        printf("%d\t", n[i]);
    }

    printf("\nChoose a number: ");
    scanf("%d", &target);

    binary_search (n, target, 0, 10);
    if (binary_search (n, target, 0, 10) == 1){
        printf("Not found.\n");
    }else{
        printf("\nFounded, at index %d", binary_search(n, target, 0, sizeof(n)/sizeof(n[0])));
    }
    

}