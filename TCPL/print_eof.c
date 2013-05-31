#include <stdio.h>

main(){
    int c;
    while((c=getchar()) != EOF){
    }
    printf("Got EOF. Printing it");
    putchar(c);
    printf("\n");
}
