#include <stdio.h>
#include <malloc.h>
#include "stepik.h"

void main(){
   int n; int *arr; int ch; int i;
   printf("Enter number of elements\n");
   scanf("%d", &n);
   arr = (int*) malloc(n*sizeof(int));
   for (i=0; i<n; i++){
      printf("%d: ", i);
      scanf("%d", &arr[i]);
   }
   printf("Enter option\n");
   scanf("%d", &ch);
   menu(ch, arr, n);
   free(arr);
}
