#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void ajouter_vol(VOL vol)
{
	FILE* f;
	f=fopen("ListeVol.txt", "a+");
	if (f!=NULL)
	{
		fprintf(f, " %d %s %s %s %s %s %s %f %d		 \n",vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,vol.date_depart,vol.date_retour,vol.classe,vol.tarif,vol.nbr_max);
		fclose(f);
	}
	else
	{
		return;
	}
}

void afficher_vol(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	int num_vol;
	char compagnie_aerienne[30];
	char depart[30];
	char destination[30];
	char date_depart[30];
	char date_retour[30];
	char classe[30];
	float tarif;	
	int nbr_max;
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

		store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_INT);

f=fopen("/home/macbookair/Desktop/try1/src/ListeVol.txt", "a+");
while (fscanf(f, " %d %s %s %s %s %s %s %f %d" ,&num_vol,compagnie_aerienne,depart,destination,date_depart,date_retour,classe,&tarif,&nbr_max)!=EOF)
{
	gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NUM_VOL,num_vol,COMPAGNIE_AERIENNE,compagnie_aerienne,DEPART,depart,DESTINATION,destination,DATE_DEPART,date_depart,DATE_RETOUR,date_retour,CLASSE,classe,TARIF,tarif,NBR_MAX,nbr_max, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
else
{
	return;
}
}

void modifier_vol(VOL vol,int Num_volM)
{
	int num_volM;
	char compagnie_aerienneM[30];
	char departM[30];
	char destinationM[30];
	char date_departM[30];
	char date_retourM[30];
	char classeM[30];
	float tarifM;
	int nbr_maxM;

FILE *f1;
FILE *f2;
f1=fopen("/home/macbookair/Desktop/try1/src/ListeVol.txt","r");
f2=fopen("/home/macbookair/Desktop/try1/src/ListeVolM.txt","a+"); 

		while (fscanf(f1, " %d %s %s %s %s %s %s %f %d" ,&num_volM,compagnie_aerienneM,departM,destinationM,date_departM,date_retourM,classeM,&tarifM,&nbr_maxM)!=EOF)
		{ 
			if(num_volM==Num_volM)
			{
				fprintf(f2, " %d %s %s %s %s %s %s %f %d		 \n",vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,vol.date_depart,vol.date_retour,vol.classe,vol.tarif,vol.nbr_max);
			}
			else 
			{
				fprintf(f2, " %d %s %s %s %s %s %s %f %d		 \n",num_volM,compagnie_aerienneM,departM,destinationM,date_departM,date_retourM,classeM,tarifM,nbr_maxM);

			}
		}
fclose(f1);
fclose(f2);

remove("/home/macbookair/Desktop/try1/src/ListeVol.txt") ;
rename ("/home/macbookair/Desktop/try1/src/ListeVolM.txt" , "/home/macbookair/Desktop/try1/src/ListeVol.txt") ;
}

void supprimer_vol(int num_volS)
{
VOL v ;
FILE *f;
FILE *f1;
f=fopen("/home/macbookair/Desktop/try1/src/ListeVol.txt","r");
f1=fopen("/home/macbookair/Desktop/try1/src/ListeVolM.txt","a+");
while (fscanf(f, " %d %s %s %s %s %s %s %f %d" ,&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
{ 
	if (num_volS!=v.num_vol)
	fprintf(f1, " %d %s %s %s %s %s %s %f %d		 \n",v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,v.tarif,v.nbr_max);
}


fclose(f);
fclose(f1);

remove("/home/macbookair/Desktop/try1/src/ListeVol.txt");
rename ("/home/macbookair/Desktop/try1/src/ListeVolM.txt" , "/home/macbookair/Desktop/try1/src/ListeVol.txt") ;
}


