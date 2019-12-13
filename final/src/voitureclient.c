#include <stdio.h>
#include <string.h>
#include "voitureclient.h"
#include <gtk/gtk.h>


enum
{
	MARQUE,
	SERIE,
	AGE,
	KILOMETRAGE,
	PRIX,
	DATE,
	COLUMNS
};




void afficher_voitureclient(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char marque[30];
char serie[30];
char age[30];
char kilometrage[30];
char prix[30];
char date[30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("serie",renderer,"text",SERIE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("kilometrage",renderer,"text",KILOMETRAGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",marque,serie,age,kilometrage,prix,date)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,MARQUE,marque,SERIE,serie,AGE,age,KILOMETRAGE,kilometrage,PRIX,prix,DATE,date,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}

