#include <stdio.h>
#include <string.h>
#include "voiture.h"
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


void ajouter_voiture(Voiture p)
{

 FILE *f;
 f=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s \n",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date);
 fclose(f);
 }

}
void afficher_voiture(GtkWidget *liste)
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
void supprimervoiture(char serie1[])
{
Voiture p;

	FILE *f;
	FILE *tmp;
int r;
int n;

f=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","r");
tmp=fopen("/home/malekbouslah/Desktop/final/src/tmp.txt","w");
if(f!=NULL){
    if(tmp!=NULL){
while (fscanf(f,"%s %s %s %s %s %s",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date)!=EOF){
            if  (strcmp(serie1,p.serie)!=0){
 fprintf(tmp,"%s %s %s %s %s %s \n",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date,n);
		r=1;
            }
		}
    }
    fclose(tmp);
}
fclose(f);
if (r){
remove("/home/malekbouslah/Desktop/final/src/voiture.txt");
rename("/home/malekbouslah/Desktop/final/src/tmp.txt","/home/malekbouslah/Desktop/final/src/voiture.txt");
}
}

void modifiervoiture(Voituremod m,char serie1[]){

Voiture p ;



    FILE *f_mod;
    FILE *f_mod1;
f_mod=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","r");
f_mod1=fopen("/home/malekbouslah/Desktop/final/src/mod.txt","w");
if(f_mod!=NULL){
    if(f_mod1!=NULL){
while (fscanf(f_mod,"%s %s %s %s %s %s",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date)!=EOF){
            if  (strcmp(serie1,p.serie)!=0){
       fprintf(f_mod1,"%s %s %s %s %s %s \n",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date);
            }
            else {
       fprintf(f_mod1,"%s %s %s %s %s %s \n",m.modmarque,m.modserie,m.modage,m.modkilometrage,m.modprix,m.moddate);
            }
        }
    }
}
fclose(f_mod1);
fclose(f_mod);
remove("/home/malekbouslah/Desktop/final/src/voiture.txt");
rename("/home/malekbouslah/Desktop/final/src/mod.txt","/home/malekbouslah/Desktop/final/src/voiture.txt");
}



int test_serie(char serieh[]) 
{ 
FILE *f;
Voiture p;
int test = 0 ; 
f=fopen("/home/malekbouslah/Desktop/final/src/voiture.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s\n",p.marque,p.serie,p.age,p.kilometrage,p.prix,p.date)!=EOF) 
{ if(strcmp(p.serie,serieh)==0)
test=1 ;
 } 
fclose(f);
return test ; 
}
}
 /*
int test_nombre(char c[])
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

}*/ 



