#include <stdio.h>
#include <string.h>
#include "reservation.h"
#include <gtk/gtk.h>

enum
{
	NUM,
	DATE,
	TYPE,
	ETAT,
	COLUMNS
};

void afficher_res(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

reservation r;
char ch[30];

store =NULL;

FILE* f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("num_res",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date_reservation",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


	f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s  \n",r.num_res,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,r.etat)!=EOF)
		{strcpy(ch,r.date_reservation.jour);
	         strcat(ch,"/");
		 strcat(ch,r.date_reservation.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,r.date_reservation.annee);
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NUM,r.num_res,DATE,ch,TYPE,r.type,ETAT,r.etat,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	


}
}
