#include <stdio.h>

void clear_input_buffer(void);

int main()
{

    printf("What is the first letter of your name? ");
    char letter;
    scanf("%c", &letter);

    clear_input_buffer(); // Function to remove \n and EOF

    printf("What is your name? ");
    char name[50];
    scanf("%s", name);

    printf("first letter of your name is %c\n", letter);
    printf("Your name is %s\n", name);

    if (letter != name[0])
    {
        printf("Your name and it's first letter don't match\n");
    }
    else
    {
        printf("Your name and it's first letter match\n");
    }

    return 0;
}

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
