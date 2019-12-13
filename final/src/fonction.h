
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>


typedef struct facture{ 
char idfacture[30];
char idclient[30];
int jour;
int mois;
int annee;
char nom[20];
char prenom[20];
char service[50];
char prix[30];
}facture;

void ajouterbrody(char idclient[30],char idfacture[30],int jour,int mois,int annee,char nom[30],char prenom[30],char service[30],char prix[30]);
void supprimerbrody(char idfacture[]);
void modifierbrody(facture b);
void afficherbrody(GtkWidget *liste);
