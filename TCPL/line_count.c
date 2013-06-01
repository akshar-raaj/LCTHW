#include <stdlib.h>
#include <stdio.h>

main(){
    int lc = 0;
    int c;

    while((c=getchar()) != EOF){
        if(c == '\n'){
            ++lc;
        }
    }

    printf("%d\n", lc);
}
