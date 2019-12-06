#include <stdio.h>
#include <string.h>
#include "reservation.h"
#include <gtk/gtk.h>

enum
{
	NUM,
	DATE,
	TYPE,
	DEVIS,
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
	column=gtk_tree_view_column_new_with_attributes("devis",renderer,"text",DEVIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_FLOAT);


	f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %f  \n",r.num_res,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
		{strcpy(ch,r.date_reservation.jour);
	         strcat(ch,"/");
		 strcat(ch,r.date_reservation.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,r.date_reservation.annee);
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NUM,r.num_res,DATE,ch,TYPE,r.type,DEVIS,r.devis,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	


}
}

//supp reservation
void suppres(char num_res[])
{
FILE *f;
FILE *f2;
reservation r;

f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");

if(f==NULL)
	{
		return;
	}
while (fscanf(f,"%s %s %s %s %s %f  \n",r.num_res,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
        {
         if (strcmp(num_res,r.num_res))
        {
	f2=fopen("/home/malekbouslah/Projects/reservation/src/testres.txt", "a");
		if (f2==NULL)
		{
		return;
		}

	fprintf(f2,"%s %s %s %s %s %f  \n",r.num_res,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,r.devis);

	 fclose(f2);
	}
	}

	fclose(f);
remove("/home/malekbouslah/Projects/reservation/src/reservation.txt");
rename("/home/malekbouslah/Projects/reservation/src/testres.txt","/home/malekbouslah/Projects/reservation/src/reservation.txt");

FILE *f1;
FILE *f3;
char num[50],depart[50],destination[50],compagnie[50],date_aller[50],date_retour[50],classe[50];
int nb_voy;
float prix;
f1=fopen("/home/malekbouslah/Projects/reservation/src/volreserver.txt","r");

if(f==NULL)
	{
		return;
	}
while (fscanf(f1,"%s %s %s %s %s %s %s %d %f\n",num,depart,destination,compagnie,date_aller,date_retour,classe,&nb_voy,&prix)!=EOF)
        {
         if (strcmp(num_res,num))
        {
	f3=fopen("/home/malekbouslah/Projects/reservation/src/testvol.txt", "a");
		if (f3==NULL)
		{
		return;
		}

	fprintf(f3,"%s %s %s %s %s %s %s %d %f\n",num,depart,destination,compagnie,date_aller,date_retour,classe,nb_voy,prix );

	 fclose(f3);
	}
	}

	fclose(f1);
remove("/home/malekbouslah/Projects/reservation/src/volreserver.txt");
rename("/home/malekbouslah/Projects/reservation/src/testvol.txt","/home/malekbouslah/Projects/reservation/src/volreserver.txt");

}
