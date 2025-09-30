#include <stdio.h>
#include <stdlib.h>

#define LIGNES 6
#define COLONNES 7

// Initialisation du plateau avec des cases vides
void initialiserPlateau(char plateau[LIGNES][COLONNES]) {
    for (int l = 0; l < LIGNES; l++)
        for (int c = 0; c < COLONNES; c++)
            plateau[l][c] = ' ';
}

// Affichage du plateau 
void afficherPlateau(char plateau[LIGNES][COLONNES]) {
    printf("\n  ");
    for (int c = 0; c < COLONNES; c++) printf("%d ", c + 1);
    printf("\n");
    for (int l = 0; l < LIGNES; l++) {
        printf("| ");
        for (int c = 0; c < COLONNES; c++)
            printf("%c ", plateau[l][c]);
        printf("|\n");
    }
    printf("  ");
    for (int c = 0; c < COLONNES * 2 - 1; c++) printf("-");
    printf("\n");
}

int main() {
    char plateau[LIGNES][COLONNES];
    initialiserPlateau(plateau);
    afficherPlateau(plateau);
    return 0;
}