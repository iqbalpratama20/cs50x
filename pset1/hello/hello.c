#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Takes an input (name) and then say hello along with the name
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);

}
