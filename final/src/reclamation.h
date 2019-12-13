#include<gtk/gtk.h>
#include<string.h>
typedef struct
{
char id[30];
char type[30];
char date[30];
char rec[30];

}reclamation;

void ajouter_reclamation(reclamation c);
void afficher_reclamation(GtkWidget *liste);
void supprimer_reclamation(char id[]);
void ajouter_repense(char id[],char rep[]);
void afficher_repense(GtkWidget *liste);
void timeanis();

