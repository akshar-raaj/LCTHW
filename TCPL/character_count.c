#include <stdio.h>

main(){
    //Counts number of characters
    int nc = 0;

    while(getchar()!=EOF){
        ++nc;
    }
    printf("%d\n", nc);
}
