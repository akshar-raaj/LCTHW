#include <stdio.h>

main(){
    //Print EOF. Wanted to see how EOF is represented.
    int c;

    while((c=getchar()) != EOF){
    }

    printf("Got EOF. Printing it");
    putchar(c);
    printf("\n");
}
