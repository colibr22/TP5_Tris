#include <stdio.h>
#include <string.h>

typedef struct{
    char nom[50];
    char prenom[50];
    char matricule[20];
    float moyenne;
}Etudiant;

void echanger(Etudiant *a, Etudiant *b) {
    Etudiant temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Etudiant tab[], int debut, int fin) {
    float pivot = tab[fin].moyenne;
    int i = debut - 1;

    for (int j = debut; j < fin; j++) {
        if (tab[j].moyenne >= pivot) {
            i++;
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[fin]);
    return i + 1;
}

void quicksort_moyenne(Etudiant tab[], int debut, int fin) {
    if (debut < fin) {
        int pivot_index = partition(tab, debut, fin);
        quicksort_moyenne(tab, debut, pivot_index - 1);
        quicksort_moyenne(tab, pivot_index + 1, fin);
    }
}

void afficher_etudiants(Etudiant tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nom: %s, Prenom: %s, Matricule: %s, Moyenne: %.2f\n",
               tab[i].nom, tab[i].prenom, tab[i].matricule, tab[i].moyenne);
    }
}

int main() {
    int n ;
    printf("Entrez le nombre d'etudiants : ");
    scanf("%d", &n);

    Etudiant tab[3] = {
        {"Doe", "John", "MAT001", 14.5},
        {"Smith", "Anna", "MAT002", 17.3},
        {"Brown", "Charlie", "MAT003", 12.0},
    };

    quicksort_moyenne(tab, 0, n-1);
    printf("Tri par ordre de moyenne :\n");
    afficher_etudiants(tab, n);

    return 0;
}
