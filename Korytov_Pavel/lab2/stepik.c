#include <stdio.h>

void menu(int ch, int arr[], int n){        
    switch (ch) {
        case 0: get_max(arr, n); break;
        case 1: get_min(arr, n); break;
        case 2: get_sum(arr, n); break;
        case 3: get_count_first_el(arr, n); break;
        default: printf("Data incorrect"); //Problems with russian encoding while copying from stepik to linux
    }
}

int mod(int a, int b){
    int r=a;
    while (r>=b){
        r=r-b;   
    }
    return r;
}

int get_max(int arr[], int n){
    int i; int m=arr[0];
    for (i=1; i<n; i++){
        if (arr[i]>m) 
            m=arr[i];
    }
    printf("%d\n", m);
}

int get_min(int arr[], int n){
    int m=arr[0]; int i;
    for (i=1; i<n; i++){
        if (arr[i]<m)
            m=arr[i];
    }
    printf("%d\n", m);
}

int get_sum(int arr[], int n){
    int m=0; int i;
    for (i=0; i<n; i++){
        if (mod(arr[i], 2) == 0) {
             m=m+arr[i];
        }
    }
    printf("%d\n", m);
}

int get_count_first_el(int arr[], int n){
    int k=arr[0]; int m=0; int i;
    for (i=1; i<n; i++){
        if (k == arr[i]){
            m++;   
        }
    }
    printf("%d\n", m);
}
