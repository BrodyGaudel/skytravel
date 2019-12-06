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



int cherchervol(char aller[],char retour[]);
int verifier_remplir(char tab[50][50],int n, char test[]);
int tableau_compagnie_disponible(char compagnie[50][50],char depart[],char destination[]);
int tableau_date_disponible(char date[50][50],char depart[],char destination[],char compagnie[]);
int tableau_date_retour_disponible(char date[50][50],char depart[],char destination[],char compagnie[],char date_aller[]);
float tarif_vol(char depart[],char destination[],char compagnie[],char date_aller[],char date_retour[],char classe[]);
float calcul_prix_vol(float tarif,int nbr_voy);
void enregistrer_vol(char num[],char j[],char m[],char a[],float prix);
