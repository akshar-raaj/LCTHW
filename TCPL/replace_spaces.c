#include <stdio.h> 
#include <stdlib.h>

main(int argc, char *argv[]){
    //Replace consecutive blanks in a string with a single blank

    if(argc!=2){
        printf("You must provide only 2 arguments\n");
        printf("Example usage: ./replace_spaces \"Dennis    Ritchie\"\n");
        exit(0);
    }

    char *input = argv[1];  //String to be cleaned
    printf("%s\n", input);
    char arr[100];          //Cleaned string
    char *current_char = arr;
    int is_blank = 0;
    int blank_index=-2;

    int i;
    for(i=0; *input!='\0'; i++){
        if(*input==' ' && i==blank_index+1){
            //Do not copy consecutive blank spaces
        }
        else{
            *current_char = *input;
            current_char++;
        }

        if(*input == ' '){
            blank_index = i;
        }
        input++;
    } 

    *current_char = '\0';
    printf("%s\n", arr);
}
