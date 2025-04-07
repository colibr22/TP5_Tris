#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[50];
    char code[50];
    int fabrication;
    int peremption;
    float prix;
    int vendus;
    int stock;
    struct Medicament* suivant;
}Medicament;

void creeMedicament(Medicament* tableau) {
    Medicament* nouveau = malloc(sizeof(Medicament));
    if (nouveau == NULL) {
        return;
    }
    
    printf("Entrez le nom du medicament : ");
    scanf("%s", nouveau->nom);
    printf("Entrez le code du medicament : ");
    scanf("%s", nouveau->code);
    printf("Entrez l'annee de fabrication : ");
    scanf("%d", &nouveau->fabrication);
    printf("Entrez l'annee de peremption : ");
    scanf("%d", &nouveau->peremption);
    printf("Entrez le prix : ");
    scanf("%f", &nouveau->prix);
    printf("Entrez le nombre de medicaments vendus : ");
    scanf("%d", &nouveau->vendus);
    printf("Entrez le stock disponible : ");
    scanf("%d", &nouveau->stock);
    nouveau->suivant = tableau->suivant;
    tableau->suivant = nouveau;
}

void trisBulle(Medicament* tableau){

}


int main(){
    Medicament* tableau = malloc(sizeof(Medicament));
    tableau->suivant = NULL;
    creeMedicament(tableau);
    free(tableau);
    return 0;
}
