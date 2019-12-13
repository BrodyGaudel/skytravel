#ifndef AjouterVol_h
#define AjouterVol_h

#include <stdio.h>
#include <gtk/gtk.h>

typedef struct
{
	int num_vol;
	char compagnie_aerienne[30];
	char depart[30];
	char destination[30];
	char date_depart[30];
	char date_retour[30];
	char classe[30];
	float tarif;
	int nbr_max;
}VOL;

void ajouter_vol(VOL vol);
void afficher_vol(GtkWidget *liste);
void recherche_vol();
void modifier_vol(VOL vol,int Num_vol);
void supprimer_vol(int num_volS);

#endif
