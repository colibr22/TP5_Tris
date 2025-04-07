#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[50];
    char code[50];
    int fabrication;
    int peremption;
    int prix;
    struct Medicament* suivant;
}Medicament;

void creeMedicament(Medicament* tableau, int taille) {
    Medicament* new = malloc(sizeof(Medicament));
	if (new == NULL) {
		return;
	}
	printf("Entrez le code du medicament: ");
	scanfs("%s", new->code, 50);
	printf("Entrez le nom du medicament: ");
	scanfs("%s", new->nom, 50);
    printf("Entrez la date de fabrication: ");
	scanfs("%s", new->fabrication);
	printf("Entrez la date de peremption: ");
	scanfs("%d", new->peremption);
	printf("Entrez un prix unitaire (en dollars $): ");
	scanfs("%s", new->prix);
	new->suivant = tableau->suivant;
	tableau->suivant = new;
}

void trisBulle(Medicament* tableau){

}

void afficherTableau(Medicament tableau, int taille) {
    
}

int main(){
    Medicament* tabmedoc = malloc(sizeof(Medicament));
    tabmedoc ->suivant = NULL;
    int taille = 5;
    creeMedicament(tabmedoc);
}
