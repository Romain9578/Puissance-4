#include <stdio.h>
#include <stdlib.h>

#define LIGNES 6
#define COLONNES 7

void initialiserPlateau(char plateau[LIGNES][COLONNES]) {
    for (int l = 0; l < LIGNES; l++)
        for (int c = 0; c < COLONNES; c++)
            plateau[l][c] = ' ';
}

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

// Laisser tomber un pion dans une colonne
int poserPion(char plateau[LIGNES][COLONNES], int col, char pion) {
    for (int l = LIGNES - 1; l >= 0; l--) {
        if (plateau[l][col] == ' ') {
            plateau[l][col] = pion;
            return l;
        }
    }
    return -1; // colonne pleine
}

// Vérifier si le plateau est rempli
int plateauPlein(char plateau[LIGNES][COLONNES]) {
    for (int c = 0; c < COLONNES; c++)
        if (plateau[0][c] == ' ') return 0;
    return 1;
}

int main() {
    char plateau[LIGNES][COLONNES];
    initialiserPlateau(plateau);
    afficherPlateau(plateau);
    poserPion(plateau, 3, 'X'); // Exemple : placer un pion colonne 4
    afficherPlateau(plateau);
    return 0;
}
