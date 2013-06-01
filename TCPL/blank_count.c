#include <stdio.h>

main(){
    int bc = 0;
    int c;

    while((c=getchar()) != EOF){
        if(c==' '){
            ++bc;
        }
    }

    printf("%d\n", bc);
}
