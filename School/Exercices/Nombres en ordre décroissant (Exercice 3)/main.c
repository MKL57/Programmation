#include <stdio.h>
#include <stdlib.h>

// Fonction pour échanger deux valeurs
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour vérifier si le tableau est en ordre décroissant
int estDecroissant(int tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        if (tab[i] < tab[i + 1]) {
            return 0; // Ce n'est pas décroissant
        }
    }
    return 1;
}

// Fonction récursive pour générer les permutations
void permuter(int tab[], int debut, int fin) {
    if (debut == fin) {
        if (estDecroissant(tab, fin + 1)) {
            for (int i = 0; i <= fin; i++) {
                printf("%d ", tab[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = debut; i <= fin; i++) {
            echanger(&tab[debut], &tab[i]);
            permuter(tab, debut + 1, fin);
            echanger(&tab[debut], &tab[i]); // backtrack
        }
    }
}

int main() {
    int nombres[4];

    // Saisie des 4 nombres
    for (int i = 0; i < 4; i++) {
        printf("Entrez le nombre %d : ", i + 1);
        scanf("%d", &nombres[i]);
    }

    printf("\nPermutations en ordre décroissant :\n");
    permuter(nombres, 0, 3);

    return 0;
}
