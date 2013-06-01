#include <stdio.h>
#define NUMBER_OF_DIGITS 10

main(){
    //Finds the number of times each digit occurs in the input
    //Finds the number of times whitespaces occurs

    int nwhite, nother;
    int digits[NUMBER_OF_DIGITS];
    int c, i;

    for(i=0; i<NUMBER_OF_DIGITS; ++i){
        digits[i] = 0;
    }

    nwhite=nother=0;

    while((c=getchar()) != EOF){
        if(c>='0' && c<='9'){
            ++digits[c-'0'];
        }
        else if(c=='\n' || c=='\t' || c==' '){
            ++nwhite;
        }
        else{
            ++nother;
        }
    }
    printf("Digits\n");
    for(i=0; i<NUMBER_OF_DIGITS; ++i){
        printf("Digit %d occurs %d times\n", i, digits[i]);
    }
    printf("White spaces: %d\nOther: %d\n", nwhite, nother);
}
