#include "myFunc.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *s = "[[]";
    int x = match(s);
    printf("%d\n", x);
    return 0;
}
