#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int odd_sent(char* arr);

char* deleite_plz(char* arr);

int main(){
   char* a=(char*)malloc(500*sizeof(char)); 
   char* c=(char*)malloc(500*sizeof(char));
   char b;
    int i=0, j=0, n=0, m=0;
    while((b=getchar())!='!'){
        a[i++]=b;
      }
    a[i++]='!';
    a[i]='\0';
    i=0;
    while(i<strlen(a)){  
        while((a[i]!='.') && (a[i]!='?') && (a[i]!=';') && (a[i]!='!')){
            c[j++]=a[i];
            i++;
        }
        c[j++]=a[i];
        c[j]='\0';
        j=0;
        if(odd_sent(c)==0){
            printf("%s\n", deleite_plz(c));
            m++;
        }
        n++;
        i++;   
      }
    printf("Количество предложений до %d и количество предложений после %d\0", n-1, m);
    return 0;
}

char* deleite_plz(char* arr){
    int i, j, k;
    while((arr[0]=='\t') || (arr[0]==' ') || (arr[0]=='\n')){
        for(i=0;i<strlen(arr)-1;i++){
            arr[i]=arr[i+1];
        }
        arr[strlen(arr)-1]='\0';
    }
    return arr;
}
  
int odd_sent(char* arr){
    int i, j=0;
    for(i=0;i<strlen(arr);i++){
        if(arr[i]=='?' || arr[i]=='!'){
            j++;
        }
    }
    return j;
}
