#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void die(char *message)
{
    printf(message);
    exit(1);
}
int main(int argc, char *argv[])
{
    if (argc<2)
    {
        die("Usage: ./file_io <file_name>\n");
    }

    char *filename = argv[1];
    FILE *fp;
    fp = fopen(filename, "w");
    assert(fp!=NULL);

    fprintf(fp, "Testing\n");

    int closed = fclose(fp);
    if(closed != 0)
    {
        die("File could not be closed properly");
    }

    return 0;
}
