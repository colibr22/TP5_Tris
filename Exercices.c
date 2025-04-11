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

int rechercheDichotomique(Medicament tab[], int n, char nomRecherche[]) {
    int debut = 0;
    int fin = n - 1;
    int mil;
    int trouve = 0;

    while (!trouve && debut <= fin) {
        mil = (debut + fin) / 2;
        int cmp = strcmp(nomRecherche, tab[mil].nom);

        if (cmp == 0) {
            trouve = 1;
            return mil;
        } else if (cmp > 0) {
            debut = mil + 1;
        } else {
            fin = mil - 1;
        }
    }

    return -1;
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

    char nomRecherche[50];
    printf("Entrez le nom du médicament à rechercher : ");
    scanf("%s", nomRecherche);

    int pos = rechercheDichotomique(tab, n, nomRecherche);

    if (pos != -1) {
        printf("Le medicament \"%s\" est trouve au rang %d.\n", nomRecherche, pos);
    } else {
        printf("Le medicament \"%s\" n'est pas dans le tableau.\n", nomRecherche);
    }

    return 0;
}
