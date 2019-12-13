#ifndef AjouterVol_h
#define AjouterVol_h

#include <stdio.h>
#include <gtk/gtk.h>


typedef struct
{
	int jour;
	int mois;
	int annee;
}DATE;

typedef struct
{
	int num_vol;
	char compagnie_aerienne[30];
	char depart[30];
	char destination[30];
	DATE date_depart;
	DATE date_retour;
	char classe[30];
	float tarif;
	int nbr_max;
}VOL;

void AGajouter_vol(VOL vol);
void ajoutcataloguemalek();
void AGafficher_vol(GtkWidget *liste);
void AGrecherche_vol();
void AGmodifier_vol(VOL vol);
void AGsupprimer_vol(int num_volS);
int AGtest_num_vol(int num_volT);
int AGtest_tarif(char c[]);

#endif
