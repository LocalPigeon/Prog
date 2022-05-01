#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
    printf("Hello World!\n");

    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

    print_out("May", 2);
    print_out("Cayde", 6);
    return 0;
}