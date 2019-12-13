#include <gtk/gtk.h>


typedef struct
{
char jour[6];
char mois[6];
char annee[6];
}date;

typedef struct 
{
char num_res[20];
char identifiant[30];
date date_reservation;
char type[30];
float devis;
}reservation;

void afficher_res(GtkWidget *liste,char ide[]);
void suppres(char num_res[]);
//int chercher_id(char id[]);
