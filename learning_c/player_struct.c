#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[25];
    int age;
    char club[50];
    int old_numbers[20];
} Player;


int main()
{

    // /* Implement a struct with an array variable

    Player player11;

    strcpy(player11.name, "Adewale Gbewọle");
    player11.age = 66;
    strcpy(player11.club, "Liverpool");
    player11.old_numbers[0] = 45;

    printf("Player 11 is named %s\n", player11.name);
    printf("Player 11 plays for %s!!!\n", player11.club);
    printf("Player 11 is %d years old\n", player11.age);
    printf("Player 11 previously held position %d\n", player11.old_numbers[0]);

    return 0;
}
