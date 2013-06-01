#include <stdio.h>

main(){
    int c;
    int word_ends = 0;

    while((c=getchar()) != EOF){
        if(c==' '){
            word_ends = 1;
        }
        else{
            putchar(c);
        }
        if(word_ends){
            printf("\n");
            word_ends = 0;
        }
    }
}
