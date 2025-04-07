#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicament {
    char nom[20];
    char code[20];
    int fabrication;
    int peremption;
    float prix;
    int vendus;
    int stock;
    struct Medicament* suivant;
} Medicament;
void creeMedicament(Medicament* tableau, int taille){
    Medicament* temp = tableau;
    for (int i = 0; i < taille; i++) {
        printf("Entrez le nom du medicament %d: ", i + 1);
        scanf("%s", temp->nom);
        printf("Entrez le code du medicament %d: ", i + 1);
        scanf("%s", temp->code);
        printf("Entrez l'annee de fabrication du medicament %d: ", i + 1);
        scanf("%d", &temp->fabrication);
        printf("Entrez l'annee de peremption du medicament %d: ", i + 1);
        scanf("%d", &temp->peremption);
        printf("Entrez le prix du medicament %d: ", i + 1);
        scanf("%f", &temp->prix);
        printf("Entrez le nombre de medicaments vendus %d: ", i + 1);
        scanf("%d", &temp->vendus);
        printf("Entrez le stock de medicaments %d: ", i + 1);
        scanf("%d", &temp->stock);

        if (i < taille - 1) {
            temp->suivant = malloc(sizeof(Medicament));
            temp = temp->suivant;
            temp->suivant = NULL;
        }
    }
}

void trisBulle(Medicament* tableau, int taille) {
    Medicament* temp1 = tableau;
    Medicament* temp2 = NULL;
    for (int i = 0; i < taille - 1; i++) {
        temp2 = tableau;
        for (int j = 0; j < taille - i - 1; j++) {
            if (temp2->prix > temp2->suivant->prix) {
                Medicament temp = *temp2;
                *temp2 = *(temp2->suivant);
                *(temp2->suivant) = temp;
            }
            temp2 = temp2->suivant;
        }
    }
}

void afficherTableau(Medicament* tableau, int taille) {
    Medicament* temp = tableau;
    for (int i = 0; i < taille; i++) {
        printf("Nom: %s, Code: %s, Fabrication: %d, Peremption: %d, Prix: %.2f, Vendus: %d, Stock: %d\n",
               temp->nom, temp->code, temp->fabrication, temp->peremption,
               temp->prix, temp->vendus, temp->stock);
        temp = temp->suivant;
    }
}

int main(){
    int taille = 3;
    Medicament* tableau = malloc(taille * sizeof(Medicament));
    if (tableau == NULL) {
        return 1;
    }
    creeMedicament(tableau, taille);
    trisBulle(tableau, taille);
    
    free(tableau);
    return 0;
}
