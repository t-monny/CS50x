// Hello, user! program 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}

// Don't forget to put "" in the right place when using placeholders, close them before , variable.