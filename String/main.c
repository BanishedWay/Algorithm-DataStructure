#include "myFunc.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    char *s = "ababcabcacbab", *t = "abcac";
    printf("%d\n", Index(s, t));
    return 0;
}
