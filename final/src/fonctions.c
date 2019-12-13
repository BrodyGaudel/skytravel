#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>


enum
{
	NUMH,
	NOM,
	LIEU,
	CHAMBRE_VIDE,
	DATE_EXPIRSSION,
	RANK,
	PRIX,
	COLUMNS
};

void ajouter_hotel(hotel p)
{

 FILE *f;
 f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%d %s %s %s %s %s %s %s %s \n",p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix);
 fclose(f);
 }

}

void afficher_hotel(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
hotel p;
char numh[10];
char ch[20];
char ch1[10];
char date_expirssion[20];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("numh",renderer,"text",NUMH,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("lieu",renderer,"text",LIEU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("chambre_vide",renderer,"text",CHAMBRE_VIDE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	 renderer=gtk_cell_renderer_text_new();	
	  column=gtk_tree_view_column_new_with_attributes("date_expirssion",renderer,"text",DATE_EXPIRSSION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
 
	
	renderer=gtk_cell_renderer_text_new();	
	column=gtk_tree_view_column_new_with_attributes("rank",renderer,"text",RANK,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix)!=EOF)
		{
		strcpy(ch,p.jour);
	         strcat(ch,"/");
		 strcat(ch,p.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,p.annee);
		strcpy(ch1,p.prix);
		 strcat(ch1,"dt");
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NUMH,numh,NOM,p.nom,LIEU,p.lieu,CHAMBRE_VIDE,p.chambre_vide,DATE_EXPIRSSION,ch,RANK,p.rank,PRIX,ch1,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}
void supprimer(int numh1)
{
FILE *f;
FILE *f1;
hotel p;
f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r");
f1=fopen("/home/malekbouslah/Desktop/final/src/doc.txt","a+");
while (fscanf(f,"%d  %s %s %s %s %s %s %s %s \n",&p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix)!=EOF)
{
	if (p.numh!=numh1)	
	fprintf(f1,"%d  %s %s %s %s %s %s %s %s \n",p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix);
}
fclose(f);
fclose(f1);
remove("/home/malekbouslah/Desktop/final/src/hotel.txt");
rename("/home/malekbouslah/Desktop/final/src/doc.txt","/home/malekbouslah/Desktop/final/src/hotel.txt");
}
void modifier_hotel(hotel p)
{	int numh1;	
	char nom1[20];
	char lieu1[20];
	char chambre_vide1[12]; 
	char jour1[6];
	char  mois1[6];
	char  annee1[6];
	char rank1[30];
	char prix1[20];
	

FILE *f;
FILE *f1;
int test=-1;
f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r");
f1=fopen("/home/malekbouslah/Desktop/final/src/modif.txt","a+");
while (fscanf(f,"%d %s %s %s  %s %s %s %s %s",&numh1,nom1,lieu1,chambre_vide1,jour1,mois1,annee1,rank1,prix1)!=EOF)
{if (p.numh==numh1)
	fprintf(f1,"%d %s %s %s %s %s %s %s %s\n",p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix);
else
	fprintf(f1,"%d %s %s %s %s %s %s %s %s\n",numh1,nom1,lieu1,chambre_vide1,jour1,mois1,annee1,rank1,prix1);
}
fclose(f);
fclose(f1);
remove("/home/malekbouslah/Desktop/final/src/hotel.txt");
rename("/home/malekbouslah/Desktop/final/src/modif.txt","/home/malekbouslah/Desktop/final/src/hotel.txt");
}

int test_num(int numh) 
{ 
FILE *f;
hotel p;
int test = 0 ; 
f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%d %s %s %s %s %s %s %s %s \n",&p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix)!=EOF) 
{ if(p.numh==numh )
test=1 ;
 } 
fclose(f);
return test ; 
}
}

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

}



int veriflogin( char nom[], char pwd[])
{ 
 int a;
 FILE* f;
 char ch[30],ch1[30];
 f=fopen("/home/malekbouslah/Desktop/final/src/users.txt","r");
 if(f!=NULL)
	{
 	 while((fscanf(f,"%s %s %d", ch, ch1,&a)!=EOF))
	 	 if((strcmp(nom,ch)==0)&&(strcmp(pwd,ch1)==0)&&(nom[0]!='-'))return(a);
	 fclose(f);
	}
 else return(0); 	
}
