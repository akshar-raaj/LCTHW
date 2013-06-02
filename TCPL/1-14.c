#include <stdio.h>
#define NUMBER_OF_CHARS 128

main(){
    //Prints histogram of frequencies of different characters
    
    int frequencies[NUMBER_OF_CHARS] = {0};
    int c;
    int i, j;

    while((c=getchar()) != EOF){
        ++frequencies[c];
    }

    for(i=0; i<NUMBER_OF_CHARS; ++i){
        printf("Character %c occurs %d times\n", i, frequencies[i]);
    }

    for(i=0; i<NUMBER_OF_CHARS; ++i){
        if(frequencies[i]>0){
            printf("%c  ", i);
            for(j=0; j<frequencies[i]; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}
