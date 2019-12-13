#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "vol.h"
enum
{
	NUM_VOL,
	COMPAGNIE_AERIENNE,
	DEPART,
	DESTINATION,
	DATE_DEPART,
	DATE_RETOUR,
	CLASSE,
	TARIF,
	NBR_MAX,
	COLUMNS
};

void AGajouter_vol(VOL vol)
{
	FILE* f;
	f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt", "a+");
	if (f!=NULL)
	{
		fprintf(f, " %d %s %s %s %d %d %d %d %d %d %s %f %d		 \n",vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,vol.date_depart.jour,vol.date_depart.mois,vol.date_depart.annee,vol.date_retour.jour,vol.date_retour.mois,vol.date_retour.annee,vol.classe,vol.tarif,vol.nbr_max);
		fclose(f);
	}
	else
	{
		return;
	}
}

void ajoutcataloguemalek()
{
	char depart[30];
	char destination[30];
	char compagnie_aerienne[30];
	char date_depart_jour[30];
	char date_depart_mois[30];
	char date_depart_annee[30];
	char date_retour_jour[30];
	char date_retour_mois[30];
	char date_retour_annee[30];
	char num_vol[30];
	char tarif[30];
	char nbr_max[30];
	char classe[30];

FILE *f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt", "r");

FILE *f1=fopen("/home/macbookair/Projects/try/src/catalogue_vola.txt", "a+");

if (f!=NULL)
{
	while (fscanf(f, " %s %s %s %s %s %s %s %s %s %s %s %s %s 	 \n",num_vol,compagnie_aerienne,depart,destination,date_depart_jour,date_depart_mois,date_depart_annee,date_retour_jour,date_retour_mois,date_retour_annee,classe,tarif,nbr_max)!=EOF);
	{
		strcat(date_depart_jour,"/");
		strcat(date_depart_jour,date_depart_mois);
		strcat(date_depart_jour,"/");
		strcat(date_depart_jour,date_depart_annee);
		strcat(date_retour_jour,"/");
		strcat(date_retour_jour,date_retour_mois);
		strcat(date_retour_jour,"/");
		strcat(date_retour_jour,date_retour_annee);

		fprintf(f1, " %s %s %s %s %s %s %s %s %s 	 \n",num_vol,compagnie_aerienne,depart,destination,date_depart_jour,date_retour_jour,classe,tarif,nbr_max);
	}

fclose(f1);
fclose(f);
}
}


void AGafficher_vol(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char depart[30];
	char destination[30];
	char compagnie_aerienne[30];
	char date_depart_jour[30];
	char date_depart_mois[30];
	char date_depart_annee[30];
	char date_retour_jour[30];
	char date_retour_mois[30];
	char date_retour_annee[30];
	char num_vol[30];
	char tarif[30];
	char nbr_max[30];
	char classe[30];
	/*char ch[30];
	char ch1[30];
	char ch2[30];
	char ch3[30];
	char ch4[30];
	char ch5[30];*/

	store=NULL;
	FILE* f;
	store=gtk_tree_view_get_model(liste);	

	
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Numero de Vol",renderer,"text",NUM_VOL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Compagnie Aerienne",renderer,"text",COMPAGNIE_AERIENNE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Destination",renderer,"text",DESTINATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de Depart",renderer,"text",DATE_DEPART,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de Retour",renderer,"text",DATE_RETOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Classe",renderer,"text",CLASSE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tarif",renderer,"text",TARIF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nombre maximale de voyageurs",renderer,"text",NBR_MAX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

							store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt", "r");

if (f==NULL)
{
	return;
}
else
{ 
	f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt", "a+");
	while (fscanf(f, " %s %s %s %s %s %s %s %s %s %s %s %s %s 	 \n",num_vol,compagnie_aerienne,depart,destination,date_depart_jour,date_depart_mois,date_depart_annee,date_retour_jour,date_retour_mois,date_retour_annee,classe,tarif,nbr_max)!=EOF)
	{
		strcat(date_depart_jour,"/");
		strcat(date_depart_jour,date_depart_mois);
		strcat(date_depart_jour,"/");
		strcat(date_depart_jour,date_depart_annee);
		strcat(date_retour_jour,"/");
		strcat(date_retour_jour,date_retour_mois);
		strcat(date_retour_jour,"/");
		strcat(date_retour_jour,date_retour_annee);

		gtk_list_store_append(store,&iter);
						gtk_list_store_set(store,&iter,NUM_VOL,num_vol,COMPAGNIE_AERIENNE,compagnie_aerienne,DEPART,depart,DESTINATION,destination,DATE_DEPART,date_depart_jour,DATE_RETOUR,date_retour_jour,CLASSE,classe,TARIF,tarif,NBR_MAX,nbr_max, -1);
}	
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void AGmodifier_vol(VOL vol)
{

	int num_volM;
	char compagnie_aerienneM[30];
	char departM[30];
	char destinationM[30];
	int date_depart_jourM;
	int date_depart_moisM;
	int date_depart_anneeM;
	int date_retour_jourM;
	int date_retour_moisM;
	int date_retour_anneeM;
	char classeM[30];
	float tarifM;
	int nbr_maxM;


FILE *f1;
FILE *f2;
f1=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt","r");
f2=fopen("/home/macbookair/Projects/try/src/Modifier.txt","a+"); 

		while (fscanf(f1, "  %d %s %s %s %d %d %d %d %d %d %s %f %d	 \n",&num_volM,compagnie_aerienneM,departM,destinationM,&date_depart_jourM,&date_depart_moisM,&date_depart_anneeM,&date_retour_jourM,&date_retour_moisM,&date_retour_anneeM,classeM,&tarifM,&nbr_maxM)!=EOF)
		{ 
			if(vol.num_vol==num_volM)
			{
				fprintf(f2, "  %d %s %s %s %d %d %d %d %d %d %s %f %d		 \n",vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,vol.date_depart.jour,vol.date_depart.mois,vol.date_depart.annee,vol.date_retour.jour,vol.date_retour.mois,vol.date_retour.annee,vol.classe,vol.tarif,vol.nbr_max);
					}
			else 
			{
				fprintf(f2, " %d %s %s %s %d %d %d %d %d %d %s %f %d	 \n",num_volM,compagnie_aerienneM,departM,destinationM,date_depart_jourM,date_depart_moisM,date_depart_anneeM,date_retour_jourM,date_retour_moisM,date_retour_anneeM,classeM,tarifM,nbr_maxM);
			}
		}
fclose(f1);
fclose(f2);

remove("/home/macbookair/Projects/try/src/catalogue_vol.txt") ;
rename ("/home/macbookair/Projects/try/src/Modifier.txt" , "/home/macbookair/Projects/try/src/catalogue_vol.txt") ;
}

void AGsupprimer_vol(int num_volS)
{

VOL v ;

FILE *f1;
FILE *f2;

f1=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt","r");
f2=fopen("/home/macbookair/Projects/try/src/supp.txt","a+");

while (fscanf(f1, "  %d %s %s %s %d %d %d %d %d %d %s %f %d	 \n",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,&v.date_depart.jour,&v.date_depart.mois,&v.date_depart.annee,&v.date_retour.jour,&v.date_retour.mois,&v.date_retour.annee,v.classe,&v.tarif,&v.nbr_max)!=EOF)
 {
	if (v.num_vol!=num_volS)
	{
		fprintf(f2, " %d %s %s %s %d %d %d %d %d %d %s %f %d	 \n",v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart.jour,v.date_depart.mois,v.date_depart.annee,v.date_retour.jour,v.date_retour.mois,v.date_retour.annee,v.classe,v.tarif,v.nbr_max);
	}
}
fclose(f1);
fclose(f2);

remove("/home/macbookair/Projects/try/src/catalogue_vol.txt");
rename ("/home/macbookair/Projects/try/src/supp.txt" , "/home/macbookair/Projects/try/src/catalogue_vol.txt") ;
}

int AGtest_num_vol(int num_volT) 
{
 
FILE *f;

VOL v;

int test = 0 ;
 
f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt","r");

if(f!=NULL) 
{ 
	while (fscanf(f, "  %d %s %s %s %d %d %d %d %d %d %s %f %d	 \n",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,&v.date_depart.jour,&v.date_depart.mois,&v.date_depart.annee,&v.date_retour.jour,&v.date_retour.mois,&v.date_retour.annee,v.classe,&v.tarif,&v.nbr_max)!=EOF)
{
	if(v.num_vol==num_volT )
	test=1 ;
 } 
fclose(f);
return test ; 
}
}

int AGtest_tarif(char c[])
{
  int r=0,i;
  for(i=0;i<strlen(c);i++)
    {
      if(!isdigit(c[i]))
        {
          r=1; 
        }
    
    }
    
    return r;

}

