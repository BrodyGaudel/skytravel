#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>


enum
{
IDFACTURE,
IDCLIENT,
JOUR,
MOIS,
ANNEE,
NOM,
PRENOM,
SERVICE,
PRIX,
COLUMNS
};


//FONCTION AJOUTER

void ajouterbrody(char idclient[30],char idfacture[30],int jour,int mois,int annee,char nom[30],char prenom[30],char service[30],char prix[30])
{
FILE *f;
f=fopen("/home/malekbouslah/Desktop/final/src/facture.txt","a+");
strcpy(service,"vol");
if(f !=NULL)
{
fprintf(f,"%s %s %d %d %d %s %s %s %s\n",idfacture,idclient,jour,mois,annee,nom,prenom,service,prix);
}
fclose(f);
}

//FONCTION AFFICHER


void afficherbrody(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char idfacture[30];
char idclient[30];
int jour;
int mois;
int annee;
char nom[20];
char prenom[20];
char service[50];
char prix[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("idfacture",renderer,"text",IDFACTURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("idclient",renderer,"text",IDCLIENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("service",renderer,"text",SERVICE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("/home/malekbouslah/Desktop/final/src/facture.txt","r");
	if(f==NULL)
	{
		return;
	}
	else{
		f=fopen("/home/malekbouslah/Desktop/final/src/facture.txt","a+");
		while(fscanf(f,"%s %s %d %d %d %s %s %s %s\n",idfacture,idclient,&jour,&mois,&annee,nom,prenom,service,prix)!=EOF)
		{
			gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,IDFACTURE,idfacture,IDCLIENT,idclient,JOUR,jour,MOIS,mois,ANNEE,annee,NOM,nom,PRENOM,prenom,SERVICE,service,PRIX,prix,-1);
		}
		fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}			
//FONCTION SUPPRIMER	
	
void supprimerbrody(char idfacture[])
{
FILE *f;
FILE *f1;
facture b;
//char idfacture[30];
f=fopen("/home/malekbouslah/Desktop/final/src/facture.txt","r");
f1=fopen("/home/malekbouslah/Desktop/final/src/document.txt","a+");
while(fscanf(f,"%s %s %d %d %d %s %s %s %s\n",b.idfacture,b.idclient,&b.jour,&b.mois,&b.annee,b.nom,b.prenom,b.service,b.prix)!=EOF);
{
if (strcmp(b.idfacture,idfacture)!=0)
fprintf(f1,"%s %s %d %d %d %s %s %s %s\n",b.idfacture,b.idclient,b.jour,b.mois,b.annee,b.nom,b.prenom,b.service,b.prix);
}
fclose(f);
fclose(f1);
remove("/home/malekbouslah/Desktop/final/src/facture.txt");
rename("/home/malekbouslah/Desktop/final/src/document.txt","/home/malekbouslah/Desktop/final/src/facture.txt");
}

//FONCTION MODIFIER

void modifierbrody(facture b)
{
char idfacture[30];
char idclient[30];
int jour;
int mois;
int annee;
char nom[20];
char prenom[20];
char service[50];
char prix[30];

FILE *f;
FILE *f1;
f=fopen("/home/malekbouslah/Desktop/final/src/facture.txt","r");
f1=fopen("/home/malekbouslah/Desktop/final/src/modfact.txt","a+");
while(fscanf(f,"%s %s %d %d %d %s %s %s %s",idfacture,idclient,&jour,&mois,&annee,nom,prenom,service,prix)!=EOF)
{if(strcmp(b.idfacture,idfacture)==0)
fprintf(f1,"%s %s %d %d %d %s %s %s %s\n",b.idfacture,b.idclient,b.jour,b.mois,b.annee,b.nom,b.prenom,b.service,b.prix);
else
fprintf(f1,"%s %s %d %d %d %s %s %s %s\n",idfacture,idclient,jour,mois,annee,nom,prenom,service,prix);

}
fclose(f);
fclose(f1);
remove("/home/malekbouslah/Desktop/final/src/facture.txt");
rename("/home/malekbouslah/Desktop/final/src/modfact.txt","/home/malekbouslah/Desktop/final/src/facture.txt");
}
