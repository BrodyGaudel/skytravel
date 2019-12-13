#include <gtk/gtk.h>

typedef struct
{
int numh;
char nom[20];
char lieu[20];
char chambre_vide[30];
char jour[6];
char mois[6];
char annee[6];
char rank[30];
char prix[10];

}hotel;

void ajouter_hotel(hotel p);
void afficher_hotel(GtkWidget *liste);
void supprimer(int numh1);
void modifier_hotel(hotel p);
int test_num(int num);
int test_nombre(char c[]);
