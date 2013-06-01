#include <stdio.h> 
#include <stdlib.h>

main(int argc, char *argv[]){
    //Replace consecutive blanks in a string with a single blank

    int c;
    int is_blank = 0;
    
    while((c=getchar()) != EOF){
        if(is_blank && c==' '){
        }
        else{
            is_blank = 0;
            putchar(c);
        }
        if(c==' '){
            is_blank = 1;
        }
    }
}
