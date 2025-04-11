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
    struct Medicament *suivant;
} Medicament;

/*
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
}*/
Medicament* creerMedicament(char* nom, char* code) {
    Medicament* m = (Medicament*)malloc(sizeof(Medicament));
    strcpy(m->nom, nom);
    strcpy(m->code, code);
    m->suivant = NULL;
    return m;
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

void trierParDatePeremption(Medicament tab[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tab[j].peremption, tab[j + 1].peremption) {
                Medicament temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void trierParPrix(Medicament tab[], int n) {
    int i, j;
    Medicament temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tab[j].prix < tab[j + 1].prix) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void trierListeParCode(Medicament* head) {
    int permute;
    Medicament* p;
    Medicament* dernier = NULL;

    if (head == NULL) return;

    do {
        permute = 0;
        p = head;

        while (p->suivant != dernier) {
            if (strcmp(p->code, p->suivant->code) > 0) {
                // Échange des données des deux nœuds
                Medicament temp = *p;
                *p = *(p->suivant);
                *(p->suivant) = temp;

                // On remet les pointeurs .suivant à leur place (échangés aussi !)
                Medicament* tmpNext = p->suivant->suivant;
                p->suivant->suivant = p;
                p->suivant = tmpNext;

                permute = 1;
            }
            p = p->suivant;
        }
        dernier = p;
    } while (permute);
}

void afficherMedicamentPrix(Medicament med) {
    printf("%s (Prix: %.2f)\n", med.nom, med.prix);
}

void afficherMedicamentPeremption(Medicament med) {
    printf("%s (Expire le %d )\n", med.nom, med.peremption);
}

void afficherListe(Medicament* head) {
    Medicament* p = head;
    printf("\n--- Liste triée ---\n");
    while (p != NULL) {
        printf("Code: %s | Nom: %s\n", p->code, p->nom);
        p = p->suivant;
    }
}

int main() {
    int n = 5;
    //printf("Combien de medicaments voulez-vous saisir ? : ");
    //scanf("%d", &n);
    int i;
    Medicament tab[5] = {
        { "paracetamol", "MED001", 20220101, 20250101, 3.50, 100, 50 },
        { "ibuprofene", "MED002", 20220303, 20250303, 2.50, 200, 150 },
        { "antibiotique", "MED004", 20220101, 20252121, 4.00, 80, 60 },
        { "vitamine C", "MED005", 20230505, 20260505, 1.80, 300, 250 },
        { "aspirine", "MED006", 20221212, 20261212, 2.00, 150, 100 },
        
    };

    Medicament* m1 = creerMedicament("doliprane", "MED003");
    Medicament* m2 = creerMedicament("ampicilline", "MED004");
    Medicament* m3 = creerMedicament("benzylpenicilline", "MED005");

    m1->suivant = m2;
    m2->suivant = m3;
    
    /*
    printf("=== Saisie des medicaments ===\n");
    for (i = 0; i < n; i++) {
        printf("\nMedicament #%d\n", i + 1);
        saisirMedicament(&tab[i]);
    }*/
    trierParDatePeremption(tab, n);

    printf("\n=== Medicaments tries par date de peremption ===\n");
    for (i = 0; i < n; i++) {
        afficherMedicamentPeremption(tab[i]);
    }

    char nomRecherche[50];
    printf("\nEntrez le nom du medicament a rechercher : ");
    scanf("%s \n", nomRecherche);

    int pos = rechercheDichotomique(tab, n, nomRecherche);

    if (pos != -1) {
        printf("Le medicament \"%s\" est trouve au rang %d.\n", nomRecherche, pos);
    } else {
        printf("Le medicament \"%s\" n'est pas dans le tableau.\n", nomRecherche);
    }

    printf("\n=== Medicaments tries par prix ===\n");
    trierParPrix(tab, n);
    afficherMedicamentPrix(tab[0]);

    int totalVendus = 0;
    int totalStock = 0;

    for (int i = 0; i < n; i++) {
        totalVendus += tab[i].vendus;
        totalStock += tab[i].stock;
    }

    float taux = 0.0;
    if ((totalVendus + totalStock) > 0) {
        taux = (float)totalVendus / (totalVendus + totalStock) * 100;
    }

    printf("\nTaux de medicaments vendus : %.2f %%\n", taux);

    printf("--- Liste avant tri ---\n");
    afficherListe(m1);
    printf("\n--- Liste apres tri ---\n");
    trierListeParCode(m1);
    afficherListe(m1);

    return 0;
}
