#include<stdio.h>
#include<string.h>

int main(){
    int i,j,p=0;
    char ch[110];
    gets(ch);
    j=strlen(ch);
    for(i=0;i<j;i++){
        if(ch[i]==ch[i+1]&&ch[i+1]==ch[i+2]&&ch[i+2]==ch[i+3]&&ch[i+3]==ch[i+4]&&ch[i+4]==ch[i+5]&&ch[i+5]==ch[i+6]){
            printf("YES");
            p=0;
            break;

        }
        else{

            p=1;

        }
        if(ch[i+6]=='\0'){
            break;
        }
    }
    if(p==1){
        printf("NO");
    }
}
