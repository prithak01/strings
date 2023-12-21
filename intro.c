#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // char *str = "Hello!";
    char *str = malloc(50 * sizeof(char));
    if (str == NULL)
    {
        printf("str is NULL");
    }else{
        printf("str is %s", str);
    }
    strcpy(str, "Hello!");
    printf("%s\n", str);
    str[0] = 'h';
    printf("%s\n", str);
    free(str);
    return 0;
}