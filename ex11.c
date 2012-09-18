#include <stdio.h>

int main(int argc, char *argv[])
{
   int i = 1;

   while(i<argc)
   {
       printf("arg %d is %s\n", i, argv[i]);
       i++;
   }

   char *states[] = {
       "AP", "UP", "MP"};

   i = 0;
   while(i<3)
   {
       printf("state %d is %s\n", i, states[i]);
       i++;
   }

   return 0;
}
