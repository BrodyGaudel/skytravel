#include <gtk/gtk.h>
/*
typedef struct
{
char jour[6];
char mois[6];
char annee[6];
}Date;
*/

typedef struct
{
int num_vol;//char num_vol[30]
char date_aller[50];//date_depart[30]
char date_arriver[50];//date_retour[30]
char depart[20];//30
char destination[20];//30
char compagnie[20];//char compagnie_aerienne[30]
char classe[20];//30
int nbr_voy_ad;//nbr_max
int nbr_voy_enf;
int nbr_voy_bb;
//float tarif
}vol;



int cherchervol(char aller[],char retour[]);
int verifier_remplir(char tab[50][50],int n, char test[]);
int tableau_compagnie_disponible(char compagnie[50][50],char depart[],char destination[]);
void enregistrer_vol(vol v);
