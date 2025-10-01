#include <stdio.h>
#include <stdlib.h>

#define LIGNES 6
#define COLONNES 7


void initialiserPlateau(char plateau[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++)
        for (int j = 0; j < COLONNES; j++)
            plateau[i][j] = ' ';
}

void afficherPlateau(char plateau[LIGNES][COLONNES]) {
    printf("\n  ");
    for (int j = 0; j < COLONNES; j++) printf("%d ", j + 1);
    printf("\n");
    for (int i = 0; i < LIGNES; i++) {
        printf("| ");
        for (int j = 0; j < COLONNES; j++)
            printf("%c ", plateau[i][j]);
        printf("|\n");
    }
    printf("  ");
    for (int j = 0; j < COLONNES * 2 - 1; j++) printf("-");
    printf("\n");
}


int deposerPion(char plateau[LIGNES][COLONNES], int col, char pion) {
    for (int i = LIGNES - 1; i >= 0; i--) {
        if (plateau[i][col] == ' ') {
            plateau[i][col] = pion;
            return i;
        }
    }
    return -1; // colonne pleine
}


int estDansPlateau(int l, int c) {
    return (l >= 0 && l < LIGNES && c >= 0 && c < COLONNES);
}

int compterDirection(char plateau[LIGNES][COLONNES], int l, int c, int dL, int dC, char pion) {
    int compteur = 0;
    while (estDansPlateau(l, c) && plateau[l][c] == pion) {
        compteur++;
        l += dL;
        c += dC;
    }
    return compteur;
}

int estGagnant(char plateau[LIGNES][COLONNES], int l, int c, char pion) {
    int directions[4][2] = {
        {0, 1},   // horizontal →
        {1, 0},   // vertical ↓
        {1, 1},   // diagonale ↘
        {-1, -1}  // ❌ BUG: devrait être {1, -1} pour la diagonale ↗ ("/")
    };

    for (int i = 0; i < 4; i++) {
        int dL = directions[i][0];
        int dC = directions[i][1];
        int total = compterDirection(plateau, l, c, dL, dC, pion)
                  + compterDirection(plateau, l, c, -dL, -dC, pion) - 1;
        if (total >= 4) return 1;
    }
    return 0;
}

int main() {
    char P[LIGNES][COLONNES];
    initialiserPlateau(P);

   
    deposerPion(P, 3, 'X');

  
    deposerPion(P, 2, 'O');
    deposerPion(P, 2, 'X');

    
    deposerPion(P, 1, 'O');
    deposerPion(P, 1, 'O');
    deposerPion(P, 1, 'X');

    
    deposerPion(P, 0, 'O');
    deposerPion(P, 0, 'O');
    deposerPion(P, 0, 'O');
    int l = deposerPion(P, 0, 'X'); 

    afficherPlateau(P);

    if (estGagnant(P, l, 0, 'X')) {
        printf("Victoire de X (devrait être détectée).\n");
    } else {
       
        printf("BUG: la diagonale \"/\" n'est PAS détectée (volontaire).\n");
    }

    return 0;
}
