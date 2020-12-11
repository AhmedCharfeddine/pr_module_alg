#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(); //provides text based interface for the menu. Returns user choice.
void play_game(); //simulates the game being played
void options(); //provides a text based interface for the game options

void main() {
    int state;
    do
    {
        state = menu();
        switch (state) {
            case 1: play_game(); break;
            case 2: options(); break;
        }
    }
    while (state != 0);    
}

int menu() {
    int input;
    printf("tapez:\n1 pour jouer\n2 pour accéder au options\n0 pour sortir\n");
    scanf(" %d", &input);
    return input;
}

void play_game() {
    char word[] = "example", c;
    const int LENGTH = strlen(word);
    char output[LENGTH];
    int state, i, lives = 8;
    
    //initialising output
    output[0] = word[0];
    output[LENGTH - 1] = word[LENGTH - 1];
    for (i = 1; i < LENGTH - 1; i++) output[i] = '-';
    
    //simulating game
    printf("départ du jeu..\n%s\n", output);
    do
    {
        //getting input
        do
        {
        printf("devinez un caractère: ");
        scanf(" %c", &c);
        }
        while (!('a' <= c) || !(c <= 'z')); //avoiding invalid inputs (non alphabetical and non lowercase)
        
        //verifying input
        if (strchr(word, c) != NULL) {
            for (i = 1; i < LENGTH - 1; i++) {
                if (word[i] == c) {
                    output[i] = word[i];
                }
            }
            printf("%s\n", output);
        }
        else {
            lives--;
            printf("entrée fausse\nil vous reste %d tentatives\n", lives);
        }
        
        //needs more optimisation: if user inputs a character already entered
        
        
    }
    while ((strchr(output, '-') != NULL) && (lives != 0));
    
    if (strchr(output, '-') == NULL) {
        printf("félicitations, vous avez gagné! le mot est: %s\n", word);
    }
    else
        printf("défaite! le mot est: %s\n", word);
        
}

void options() {
    int state;
    do
    {
        printf("tapez:\n1 pour voir la liste des mots WIP\n2 pour ajouter un mot WIP\n3 pour supprimer un mot WIP\n0 pour retourner\n");
        scanf(" %d", &state);
        switch (state) {
            /*
            case 1: print_list(); break;
            case 2: append_list(); break;
            case 3: delete_word(); break;
            */
            }
    }
    while (state != 0);
}


