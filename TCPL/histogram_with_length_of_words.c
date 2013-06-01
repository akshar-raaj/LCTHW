#include <stdio.h>

main(){
    //Create a histogram with length of words
    
    int c;
    int length=0;
    int i;

    while((c=getchar()) != EOF){
        if(c == ' ' || c == '\n'){
            for(i=0; i<length; i++){
                printf("*");
            }
            printf("\n");
            length = 0;
        }
        else{
            length++;
        }
    }
}
