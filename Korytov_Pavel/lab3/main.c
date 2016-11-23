#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isq(char* str){
    int i; int q=0;
    for (i=0; i<strlen(str); i++){
        if ((str[i] == '?') || (str[i] == '!'))
            q=1;
    }
    return q;
}

char* MakeStringGreatAgain(char* str){
    int i; int k;
    while ((str[0] == '\n') || (str[0] == '\t') || (str[0] == ' ')){
        for (i=0; i<strlen(str)-1; i++){
            str[i]=str[i+1];
        }
        str[strlen(str)-1] = '\0';
    }
    return str;
}

int main()
{
    int str_cnt=0; int i=0; int new_str_cnt=0; int k=0; int str_len = 10; int temp_len=10;
    char *str = (char*)malloc(str_len*sizeof(char));
    char *temp;
    char ch;
    while ((ch=getchar())!='!'){
        str[i++]=ch;
        if ((i+3)>str_len){
            str_len=str_len+100;
            str = (char*)realloc(str, str_len*sizeof(char));
        }
    }
    str[i++]='!';
    str[i]='\0';
    i=0;
    while (i<strlen(str)){
        temp = (char*)malloc(temp_len*sizeof(char));
        while ((str[i]!=';') && (str[i]!='.') && (str[i]!='?') && (str[i]!='!')){
            temp[k++]=str[i];
            i++;
            if ((k+3)>temp_len){
                temp = (char*)realloc(temp, temp_len*sizeof(char));
                temp_len = temp_len + 100;
            }
        }
        temp[k++]=str[i];
        temp[k]='\0'; k=0; temp_len = 10;
        if (isq(temp) == 0){
            printf("%s\n", MakeStringGreatAgain(temp));
            new_str_cnt++;
        }
        i++; str_cnt++; free(temp);
    }
    printf("Sentence number before %d and sentence number after %d\n", str_cnt-1, new_str_cnt);
    return 0;
}
