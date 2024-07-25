#include <stdio.h>

#include "word_of_day.h"

#define WORD_LENGTH 5
char wordle_word[WORD_LENGTH+1];
int word_length = WORD_LENGTH;

char user_input[] = "_____";

int main() {

    get_word_of_day(wordle_word, word_length);

    if (wordle_word == NULL) {
        printf("The word for the day did not initialize properly, please try again later!");
        return 0;
    }

    printf("This word to guess has %d characters\n", WORD_LENGTH);
    printf("The current guess is %s\n", user_input);

    printf("%s\n", wordle_word);

    return 0;
}