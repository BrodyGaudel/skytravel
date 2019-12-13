#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <gdk/gdkkeysyms.h>
#include <unistd.h>
#include <time.h>


enum
{	ID,
	TYPE ,
	DATE,
	REC,
	COLUMNS
};

void ajouter_reclamation(reclamation c)
{

 FILE *f;
 f=fopen("/home/malekbouslah/Desktop/final/src/utilisateur.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s \n",c.id,c.type,c.date,c.rec);
 fclose(f);
 }

}

void afficher_reclamation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char type[30];
char date[30];
char rec[30];

store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/malekbouslah/Desktop/final/src/utilisateur.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Desktop/final/src/utilisateur.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",id,type,date,rec)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,id,TYPE,type,DATE,date,REC,rec,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}
void supprimer_reclamation(char id[])

{
reclamation c;
FILE *f;
FILE *f1;
f=fopen("/home/malekbouslah/Desktop/final/src/utilisateur.txt","r");
f1=fopen("/home/malekbouslah/Desktop/final/src/utilisateur1.txt","w");
if((f!=NULL) && (f1!=NULL))
{while(fscanf(f,"%s %s %s %s \n",c.id,c.type,c.date,c.rec)!=EOF)
{
if(strcmp(id,c.id)!=0)
fprintf(f1,"%s %s %s %s \n",c.id,c.type,c.date,c.rec);
}
}
fclose(f);
fclose(f1);
remove("/home/malekbouslah/Desktop/final/src/utilistateur.txt");
rename("/home/malekbouslah/Desktop/final/src/utilisateur1.txt","/home/malekbouslah/Desktop/final/src/utilisateur.txt"); 
}
void ajouter_repense(char id[],char rep[])
{

 FILE *f;
 f=fopen("/home/malekbouslah/Desktop/final/src/repense.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s \n",id,rep);
 
 }
fclose(f);
}
enum
{	ID1,
	REP1,
	COLUMNS1
};



void afficher_repense(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
reclamation c;
char id[100];
char rep[100];
store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REP1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	

	
	store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/malekbouslah/Desktop/final/src/repense.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Desktop/final/src/repense.txt","a+");
		while(fscanf(f,"%s %s \n",id,rep)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID1,id,REP1,rep,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}
void date_sys() 
{
guint j,m,a;
int jf,mf,af;
int test=0;
FILE *f;
m=m+1;
f=fopen("/home/malekbouslah/Desktop/final/src/datesys.txt","a+");
while((fscanf(f,"%d %d %d \n",&jf,&mf,&af)!=EOF)&&(test==0))
{
if((j==jf)&&(m==mf)&&(a==af))
{
test=1;
}
else 
{
test=0;
}
}
if(test==0) 
{
fprintf(f,"%d %d %d \n",j,m,a);
}
fclose(f);
}

void timeanis()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
FILE *f;
f=fopen("/home/malekbouslah/Desktop/final/src/datesys.txt","a+");
fprintf(f,"%d;%d;%d\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
fclose(f);
}
