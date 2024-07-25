#include <stdio.h>
#include <string>

// TODO: have a list of words to import from

char* words[] = {"apple", "candy", "lumpy"};

/// Retrieves a word for the day given a storage location 
/// and desired length
void get_word_of_day(char *word_location, size_t word_length) {

    // set word_location to NULL if word of appropriate length is not found
    
    char *word = "apple";
    strcpy(word_location, word);

}

