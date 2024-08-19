#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    char *cwd;

    // Get the current working directory
    cwd = getcwd(NULL, 0);
    free(cwd);
}