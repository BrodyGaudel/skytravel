#include <stdio.h>
#include <string.h>
#include "reserverVOL.h"
#include <gtk/gtk.h>

int cherchervol(char aller[],char retour[])
{ 
    
    FILE *f;
    VOL v;
    
    f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
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
VOL v;



if(f!=NULL)
{
	 while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{	strcpy(depart1,depart);
		strcpy(destination1,destination);
		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0)
		{
		x=verifier_remplir(compagnie,nc,v.compagnie_aerienne);
		if(x==0)
		{
		strcpy(compagnie[nc],v.compagnie_aerienne);
		
		nc++;
		}
		}
	}
}
fclose(f);
return nc;
}

int tableau_date_disponible(char date[50][50],char depart[],char destination[],char compagnie[])
{
int i,x,nv=0;
char depart1[50];
char destination1[50];
char compagnie1[50];
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
VOL v;

if(f!=NULL)
{
	 while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{	strcpy(depart1,depart);
		strcpy(destination1,destination);
		strcpy(compagnie1,compagnie);		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0 && strcmp(v.compagnie_aerienne,compagnie1)==0)
		{
		x=verifier_remplir(date,nv,v.date_depart);
		if(x==0)
		{
		strcpy(date[nv],v.date_depart);
		nv++;
		}
		}
	}
}
fclose(f);
return nv;
}

int tableau_date_retour_disponible(char date[50][50],char depart[],char destination[],char compagnie[],char date_aller[])
{
int i,x,nv=0;
char depart1[50];
char destination1[50];
char compagnie1[50];
char date_aller1[50];
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
VOL v;

if(f!=NULL)
{
	 while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{	strcpy(depart1,depart);
		strcpy(destination1,destination);
		strcpy(compagnie1,compagnie);
		strcpy(date_aller1,date_aller);		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0 && strcmp(v.compagnie_aerienne,compagnie1)==0 && strcmp(v.date_depart,date_aller1)==0)
		{
		x=verifier_remplir(date,nv,v.date_retour);
		if(x==0)
		{
		strcpy(date[nv],v.date_retour);
		nv++;
		}
		}
	}
}
fclose(f);
return nv;
}

float tarif_vol(char depart[],char destination[],char compagnie[],char date_aller[],char date_retour[],char classe[])
{
char depart1[50];
char destination1[50];
char compagnie1[50];
char date_aller1[50];
char date_retour1[50];
char classe1[50];
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
VOL v;

if(f!=NULL)
{
	 while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{	strcpy(depart1,depart);
		strcpy(destination1,destination);
		strcpy(compagnie1,compagnie);
		strcpy(date_aller1,date_aller);
		strcpy(date_retour1,date_retour);
		strcpy(classe1,classe);		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0 && strcmp(v.compagnie_aerienne,compagnie1)==0 && strcmp(v.date_depart,date_aller1)==0 && strcmp(v.date_retour,date_retour1)==0 && strcmp(v.classe,classe1)==0)
		{
			fclose(f);
			return v.tarif;
		}
	}
}
}

int numero_vol(char depart[],char destination[],char compagnie[],char date_aller[],char date_retour[],char classe[])
{
char depart1[50];
char destination1[50];
char compagnie1[50];
char date_aller1[50];
char date_retour1[50];
char classe1[50];
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
VOL v;

if(f!=NULL)
{
	 while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{	strcpy(depart1,depart);
		strcpy(destination1,destination);
		strcpy(compagnie1,compagnie);
		strcpy(date_aller1,date_aller);
		strcpy(date_retour1,date_retour);
		strcpy(classe1,classe);		
		if(strcmp(v.depart,depart1)==0 && strcmp(v.destination,destination1)==0 && strcmp(v.compagnie_aerienne,compagnie1)==0 && strcmp(v.date_depart,date_aller1)==0 && strcmp(v.date_retour,date_retour1)==0 && strcmp(v.classe,classe1)==0)
		{
			fclose(f);
			return v.num_vol;
		}
	}
}
}

float calcul_prix_vol(float tarif,int nbr_voy)
{
float t;
t=tarif*nbr_voy;
return t;

}

void enregistrer_vol(char num[],char id[],char j[],char m[],char a[],float prix)
{

FILE *f;

f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","a+");//ouvertur du fichier en mode lecture
if(f!=NULL) 
{
fprintf(f,"%s %s %s %s %s %s %f \n", num,id,j,m,a,"vol",prix);
fclose(f);
}
              
}
void modifier_nb_place(int numvol,int nb_place)
{
VOL v;

FILE* f=fopen("/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt","r");
FILE* f1=fopen("/home/malekbouslah/Projects/reservation/src/tempo.txt","a+");

if (f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %s %s %f %d ",&v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,&v.tarif,&v.nbr_max)!=EOF)
	{
		if(numvol==v.num_vol)
		{
		fprintf(f1,"%d %s %s %s %s %s %s %f %d \n",v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,v.tarif,v.nbr_max=v.nbr_max-nb_place);
		}	
		else
		fprintf(f1,"%d %s %s %s %s %s %s %f %d \n",v.num_vol,v.compagnie_aerienne,v.depart,v.destination,v.date_depart,v.date_retour,v.classe,v.tarif,v.nbr_max);
	}
}
fclose(f1);
fclose(f);
rename("/home/malekbouslah/Projects/reservation/src/tempo.txt","/home/malekbouslah/Projects/reservation/src/catalogue_vol.txt");
}
