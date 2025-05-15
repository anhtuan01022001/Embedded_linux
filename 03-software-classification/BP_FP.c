#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char data[64] = "";
    fflush(stdin);
    fgets(data, sizeof(data), stdin);
    printf("%s", data);
    return 0;
}