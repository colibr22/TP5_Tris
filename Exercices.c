#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicament {
    char nom[50];
    char code[20];
    int fabrication;
    int peremption;
    float prix;
    int vendus;
    int stock;
} Medicament;

void saisirMedicament(Medicament *med) {
    printf("Nom : ");
    scanf("%s", med->nom);

    printf("Code medicament : ");
    scanf("%s", med->code);

    printf("Date de fabrication (aaaammjj) : ");
    scanf("%d", &med->fabrication);

    printf("Date de peremption (aaaammjj) : ");
    scanf("%d", &med->peremption);

    printf("Prix unitaire ($) : ");
    scanf("%f", &med->prix);

    printf("Nombre d'unites vendues : ");
    scanf("%d", &med->vendus);

    printf("Nombre restant en stock : ");
    scanf("%d", &med->stock);
}

void trierParDatePeremption(Medicament tab[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tab[j].peremption, tab[j + 1].peremption > 0) {
                Medicament temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}



void afficherMedicament(Medicament med) {
    printf("%s (Expire le %d )\n", med.nom, med.peremption);
}

int main() {
    int n;
    printf("Combien de medicaments voulez-vous saisir ? : ");
    scanf("%d", &n);
    Medicament tab[n];
    int i;
    
    printf("=== Saisie des medicaments ===\n");
    for (i = 0; i < n; i++) {
        printf("\nMedicament #%d\n", i + 1);
        saisirMedicament(&tab[i]);
    }

    trierParDatePeremption(tab, n);

    printf("\n=== Medicaments tries par date de peremption ===\n");
    for (i = 0; i < n; i++) {
        afficherMedicament(tab[i]);
    }

    return 0;
}
