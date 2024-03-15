#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20

char* selectRandomWord();
int checkGuess(char guess, char* word, char* guessArray);

int main() {
    srand(time(NULL));

    char* word = selectRandomWord();
    int wordLength = strlen(word);

    char guessArray[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; ++i) {
        guessArray[i] = '_';
    }
    guessArray[wordLength] = '\0';

    int tries = 0;
    int correctGuesses = 0;
    char guess;
    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES && correctGuesses < wordLength) {
        printf("\nWord: %s\n", guessArray);
        printf("Tries left: %d\n", MAX_TRIES - tries);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (checkGuess(guess, word, guessArray)) {
            correctGuesses++;
        } else {
            tries++;
        }
    }

    if (tries == MAX_TRIES) {
        printf("\nSorry, you've run out of tries. The word was: %s\n", word);
    } else {
        printf("\nCongratulations! You've guessed the word: %s\n", word);
    }

    free(word);
    return 0;
}

char* selectRandomWord() {
    char* words[] = {"apple", "banana", "orange", "grape", "strawberry", "watermelon"};
    int numWords = sizeof(words) / sizeof(words[0]);
    return strdup(words[rand() % numWords]);
}

int checkGuess(char guess, char* word, char* guessArray) {
    int found = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] == guess) {
            guessArray[i] = guess;
            found = 1;
        }
    }
    return found;
}
