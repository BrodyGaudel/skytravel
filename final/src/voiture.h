#include<gtk/gtk.h>
#include<string.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

typedef struct
{
char marque[100];
char serie[100];
char age[100];
char kilometrage[100];
char prix[100];
char date[100];
}Voiture;
typedef struct 
{
char modmarque[100];
char modserie[100];
char modage[100];
char modkilometrage[100];
char modprix[100];
char moddate[100];
}Voituremod;
		
void ajouter_voiture(Voiture p);
void afficher_voiture(GtkWidget *liste);

void supprimervoiture(char serie1[]);
void modifiervoiture(Voituremod m,char serie1[]);
int test_serie(char serieh[]);
