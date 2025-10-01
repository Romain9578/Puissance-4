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
// Laisser tomber un pion dans une colonne
int poserPion(char plateau[LIGNES][COLONNES], int col, char pion) {
    for (int l = LIGNES - 1; l >= 0; l--) {
        if (plateau[l][col] == ' ') {
            plateau[l][col] = pion;
            return l;
        }
    }
    return -1;
}
// Vérifier si le plateau est rempli
int plateauPlein(char plateau[LIGNES][COLONNES]) {
    for (int c = 0; c < COLONNES; c++)
        if (plateau[0][c] == ' ') return 0;
    return 1;
}

int dansLimites(int l, int c) {
    return l >= 0 && l < LIGNES && c >= 0 && c < COLONNES;
}

int compterDirection(char plateau[LIGNES][COLONNES], int l, int c, int dl, int dc, char pion) {
    int count = 0;
    while (dansLimites(l, c) && plateau[l][c] == pion) {
        count++;
        l += dl;
        c += dc;
    }
    return count;
}

int estVainqueur(char plateau[LIGNES][COLONNES], int l, int c, char pion) {
    int directions[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    for (int i = 0; i < 4; i++) {
        int dl = directions[i][0], dc = directions[i][1];
        int total = compterDirection(plateau, l, c, dl, dc, pion)
                  + compterDirection(plateau, l, c, -dl, -dc, pion) - 1;
        if (total >= 4) return 1;
    }
    return 0;
}

int main() {
    char plateau[LIGNES][COLONNES];
    initialiserPlateau(plateau);
    char joueurs[2] = {'X', 'O'};
    int tour = 0;
    while (1) {
        afficherPlateau(plateau);
        int joueur = tour % 2;
        printf("Joueur %d (%c), choisir une colonne (1-%d) : ",
               joueur + 1, joueurs[joueur], COLONNES);
        int col;
        if (scanf("%d", &col) != 1) return 0;
        col--;
        if (col < 0 || col >= COLONNES) {
            printf("Colonne invalide.\n");
            continue;
        }
        int l = poserPion(plateau, col, joueurs[joueur]);
        if (l == -1) {
            printf("Colonne pleine.\n");
            continue;
        }
        if (estVainqueur(plateau, l, col, joueurs[joueur])) {
            afficherPlateau(plateau);
            printf("Victoire du joueur %d (%c) !\n", joueur + 1, joueurs[joueur]);
            break;
        }
        if (plateauPlein(plateau)) {
            afficherPlateau(plateau);
            printf("Match nul !\n");
            break;
        }
        tour++;
    }
    return 0;
}
