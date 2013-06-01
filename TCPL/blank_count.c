#include <stdio.h>

main(){
    //Counts occurences of spaces
    int bc = 0;
    int c;

    while((c=getchar()) != EOF){
        if(c==' '){
            ++bc;
        }
    }

    printf("%d\n", bc);
}
