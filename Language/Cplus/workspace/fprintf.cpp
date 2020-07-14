#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    char *s = "abcdefg";
    s += 2;
    FILE *test = fopen("test.txt","w");
    fprintf(stderr, "%d\n", s);
    fprintf(stderr, "%c\n", *s);
    fprintf(stderr, "%s\n", s);
    printf("***\n");
    char str[] = "ab\012\\n";
    printf("%d", strlen(str));
    return 0;
}