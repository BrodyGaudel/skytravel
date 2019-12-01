#include <stdio.h>
#include <string.h>
#include "reserverVOL.h"
#include <gtk/gtk.h>

int cherchervol(char aller[],char retour[])
{ 
    
    FILE *f;
    vol v;
    
    f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %s %d %d %d ",&v.num_vol,v.date_aller,v.date_arriver,v.depart,v.destination,v.compagnie,v.classe,&v.nbr_voy_ad,&v.nbr_voy_enf,&v.nbr_voy_bb)!=EOF)
        {
            
            if (strcmp(aller,v.depart)==0)
            {
		if(strcmp(retour,v.destination)==0)
		{
			fclose(f);
			return(1);		
		}
                
            }
        }
	fclose(f);
	return(0);
    }
}

int verifier_remplir(char tab[50][50],int n, char test[])
{
int i,x=0;
for(i=0;i<n;i++)
{
if(strcmp(tab[i],test)==0)
{
x=1;
break;
}
}
return x;
}

int tableau_compagnie_disponible(char compagnie[50][50],char depart[],char destination[])
{
int i,x,nc=0;
char depart1[50];
char destination1[50];

FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
vol v;



if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %s %s %d %d %d \n",&v.num_vol,v.date_aller,v.date_arriver,v.depart,v.destination,v.compagnie,v.classe,&v.nbr_voy_ad,&v.nbr_voy_enf,&v.nbr_voy_bb)!=EOF)
	{	strcpy(depart1,v.depart);
		strcpy(destination1,v.destination);
		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0)
		{
		x=verifier_remplir(compagnie,nc,v.compagnie);
		if(x==0)
		{
		strcpy(compagnie[nc],v.compagnie);
		
		nc++;
		}
		}
	}
}
fclose(f);
return nc;
}
/*
int tableau_date_disponible(char date[50][50],char compagnie[])
{
int i,nv=0;
char compagnie1[50];
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
vol v;

if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %s %s %d %d %d \n",&v.num_vol,v.date_aller,v.date_arriver,v.depart,v.destination,v.compagnie,v.classe,&v.nbr_voy_ad,&v.nbr_voy_enf,&v.nbr_voy_bb)!=EOF)
	{	strcpy(compagnie1,v.compagnie);
		
		
		if(strcmp(v.compagnie,compagnie1)==0 )
		{
		if(!=v)
		{
		strcpy(date[nv],v.date);
		nv++;
		}
		}
	}
}*/

/*
int calcul_prix(int tarif,int nbr_voy)
{
int t;
t=tarif*nbr_voy;
return t;

}

void enregistrer_vol(vol v)
{
 int num;
FILE*f1,f2;
f2=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r")
if
f1=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","a+");//ouvertur du fichier en mode lecture
if(f!=NULL) 
{
fprintf(f,"%s %s %s %s %s %d \n", num,date.jour,date.mois,date.annee,"vol",prix);
fclose(f);
}
              
}*/
