#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<gtk/gtkclist.h>
#include<gdk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reservation.h"
#include "reserverVOL.h"
#include "client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "voiture.h"
#include "reclamation.h"
#include "vol.h"
#include "fonction.h"

//***********************partie malek********************************************************************

void
on_button1malek_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *affichage;
GtkWidget *treeview1;
GtkWidget *input;
GtkWidget *output;
char id[50];

affichage=lookup_widget(objet_graphique,"affichage");
input=lookup_widget(objet_graphique,"label67malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));


reservations=lookup_widget(objet_graphique,"reservations");
gtk_widget_hide(reservations);

affichage=create_affichage();

gtk_widget_show(affichage);
output=lookup_widget(affichage,"label68malek");
gtk_label_set_text(GTK_LABEL(output),id);

treeview1=lookup_widget(affichage,"treeview1malek");
afficher_res(treeview1,id);

}


void
on_button11malek_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *affichage;
GtkWidget *treeview1;

GtkWidget *input;
GtkWidget *input1;
GtkWidget *output;
char id[50];
char num[20];
reservations=lookup_widget(objet_graphique,"reservations");
affichage=lookup_widget(objet_graphique,"affichage");
input1=lookup_widget(objet_graphique,"label68malek");

strcpy(id,gtk_label_get_text(GTK_LABEL(input1)));

input=lookup_widget(objet_graphique,"entry8malek");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
suppres(num);


gtk_widget_destroy(affichage);
affichage=lookup_widget(objet_graphique,"affichage");
affichage=create_affichage();

gtk_widget_show(affichage);

output=lookup_widget(affichage,"label68malek");
gtk_label_set_text(GTK_LABEL(output),id);
treeview1=lookup_widget(affichage,"treeview1malek");
afficher_res(treeview1,id);
}



void
on_button2malek_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *vol;
GtkWidget *combobox10;
GtkWidget *input;
GtkWidget *output;
GtkWidget *output1;
char id[50];
char pres[50];

reservations=lookup_widget(objet_graphique,"reservations");
input=lookup_widget(objet_graphique,"label67malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));

combobox10=lookup_widget(objet_graphique,"combobox10malek");
strcpy(pres,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)));
output1=lookup_widget(objet_graphique,"label3malek");

if(strcmp(pres,"\0")==0)
{
gtk_label_set_text(GTK_LABEL(output1),"veuillez choisir une prestation");
}
if (strcmp(pres,"vol")==0)
{

gtk_widget_destroy(reservations);
vol=lookup_widget(objet_graphique,"vol");
vol=create_vol();

gtk_widget_show(vol);
output=lookup_widget(vol,"label70malek");
gtk_label_set_text(GTK_LABEL(output),id);
}
}


void
on_button5malek_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage;
 GtkWidget *reservations,*input,*output;

char id[50];

 affichage=lookup_widget(objet_graphique,"affichage");
 input=lookup_widget(objet_graphique,"label68malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));	
 reservations=create_reservations();

 gtk_widget_show(reservations);
 gtk_widget_destroy(affichage);
 output=lookup_widget(reservations,"label67malek");
gtk_label_set_text(GTK_LABEL(output),id);

}


void
on_button8malek_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int test,i,j,n,m;
char aller[100];
char retour[100];
char compagnie[50][50];
char comp[100];
char date[50][50];
GtkWidget *vol;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *combobox7;
GtkWidget *combobox9;
GtkWidget *output3;



input1=lookup_widget(objet_graphique,"entry5malek");
input2=lookup_widget(objet_graphique,"entry7malek");
output3=lookup_widget(objet_graphique,"label28malek");
combobox7=lookup_widget(objet_graphique,"combobox7malek");
combobox9=lookup_widget(objet_graphique,"combobox9malek");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));

test=cherchervol(aller,retour);
if(test==0)
{
gtk_label_set_text(GTK_LABEL(output3),"ville de départ ou d'arriver indisponnible pour le moment, voir catalogue!! ");
}
if(test==1)
{
gtk_label_set_text(GTK_LABEL(output3)," remplissez le formulaire de réservation ");
n=tableau_compagnie_disponible(compagnie,aller,retour);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox7),_(compagnie[i]));
}

}
}


void
on_validermalek_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int test,j,m;
char aller[100];
char retour[100];

char comp[100];
char date_aller[50][50];
GtkWidget *vol;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *combobox7;
GtkWidget *combobox9;




input1=lookup_widget(objet_graphique,"entry5malek");
input2=lookup_widget(objet_graphique,"entry7malek");

combobox7=lookup_widget(objet_graphique,"combobox7malek");
combobox9=lookup_widget(objet_graphique,"combobox9malek");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));

test=cherchervol(aller,retour);

if(test==1)
{

strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
m=tableau_date_disponible(date_aller,aller,retour,comp);
for(j=0;j<m;j++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox9),_(date_aller[j]));
}
}
}


void
on_valider_datemalek_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int test,j,m;
char aller[100];
char retour[100];
char comp[100];
char da[100];
char date_retour[50][50];
GtkWidget *vol;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *combobox7;
GtkWidget *combobox9;
GtkWidget *combobox11;



input1=lookup_widget(objet_graphique,"entry5malek");
input2=lookup_widget(objet_graphique,"entry7malek");
combobox7=lookup_widget(objet_graphique,"combobox7malek");
combobox9=lookup_widget(objet_graphique,"combobox9malek");
combobox11=lookup_widget(objet_graphique,"combobox11malek");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));

test=cherchervol(aller,retour);

if(test==1)
{

strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
strcpy(da,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)));
m=tableau_date_retour_disponible(date_retour,aller,retour,comp,da);
for(j=0;j<m;j++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox11),_(date_retour[j]));
}
}
}


void
on_retour_volmalek_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
 GtkWidget *reservations,*input,*output;

char id[50];

 vol=lookup_widget(objet_graphique,"vol");
input=lookup_widget(objet_graphique,"label70malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));


 reservations=create_reservations();
 
 gtk_widget_show(reservations);
  gtk_widget_destroy(vol);
 output=lookup_widget(reservations,"label67malek");
gtk_label_set_text(GTK_LABEL(output),id);

 
}


void
on_devis_volmalek_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
GtkWidget *devisvol;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *spinbuttonadulte;
GtkWidget *spinbuttonenfant;
GtkWidget *spinbuttonbebe;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *combobox7;
GtkWidget *combobox9;
GtkWidget *combobox11;
GtkWidget *chec1,*chec2,*chec3;

float tarif,total;
int a,e,b;
int nbr_voy;
char aller[100];
char retour[100];
char comp[100];
char da[100];
char dr[100];
char prix[50];
char ch[100];
char classe[50];


input1=lookup_widget(objet_graphique,"entry5malek");
input2=lookup_widget(objet_graphique,"entry7malek");
output2=lookup_widget(objet_graphique,"label65malek");

combobox7=lookup_widget(objet_graphique,"combobox7malek");
combobox9=lookup_widget(objet_graphique,"combobox9malek");
combobox11=lookup_widget(objet_graphique,"combobox11malek");

spinbuttonadulte=lookup_widget(objet_graphique,"spinbuttonadultemalek");
spinbuttonenfant=lookup_widget(objet_graphique,"spinbuttonenfantmalek");
spinbuttonbebe=lookup_widget(objet_graphique,"spinbuttonbebemalek");

chec1=lookup_widget(objet_graphique,"economiquemalek");
chec2=lookup_widget(objet_graphique,"businessmalek");
chec3=lookup_widget(objet_graphique,"firstmalek");


strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
strcpy(da,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)));
strcpy(dr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonadulte));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonenfant));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonbebe));

gboolean etat1,etat2,etat3;
etat1=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec1));
etat2=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec2));
etat3=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec3));

if(!etat1 && !etat2 && !etat3)
{
gtk_label_set_text(GTK_LABEL(output2),"choisissez la classe svp!!");
} 
else
{
if (etat1)
	strcpy(classe,"economique");
if (etat2)
	strcpy(classe,"business");
if (etat3)
	strcpy(classe,"first");


tarif=tarif_vol(aller,retour,comp,da,dr,classe);
nbr_voy=a+e+b;
total=calcul_prix_vol(tarif,nbr_voy);
sprintf(prix,"%f",total);

strcat(ch,prix);
output1=lookup_widget(objet_graphique,"label62malek");
gtk_label_set_text(GTK_LABEL(output1),ch);
}
}



void
on_reessayervolmalek_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
GtkWidget *input;
GtkWidget *output;
char id[50];

input=lookup_widget(objet_graphique,"label70malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));
vol=lookup_widget(objet_graphique,"vol");
gtk_widget_hide(vol);

vol=create_vol();
gtk_widget_show(vol);
output=lookup_widget(vol,"label70malek");
gtk_label_set_text(GTK_LABEL(output),id);

}


void
on_enregistrementvolmalek_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
GtkWidget *input;
GtkWidget *output2;

vol=lookup_widget(objet_graphique,"vol");
input=lookup_widget(objet_graphique,"label62malek");
output2=lookup_widget(objet_graphique,"label70malek");

char prix[50];
float total;
char id[50];

reservation r;
FILE *f=fopen("/home/malekbouslah/Desktop/final/src/reservation.txt","r");
int num=1;
char num_vol[50];char j[50];char m[50];char ann[50];

strcpy(prix,gtk_label_get_text(GTK_LABEL(input)));
total=atof(prix);
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %f  \n",r.num_res,r.identifiant,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
{
num=atof(r.num_res)+1;
sprintf(num_vol,"%d",num);
}
}
  int day, mois, an;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);

  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
sprintf(j,"%d",day);
sprintf(m,"%d",mois);
sprintf(ann,"%d",an);
strcpy(id,gtk_label_get_text(GTK_LABEL(output2)));

//enregistrer_vol(num_vol,id,j,m,ann,total);



GtkWidget *spinbuttonadulte;
GtkWidget *spinbuttonenfant;
GtkWidget *spinbuttonbebe;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *combobox7;
GtkWidget *combobox9;
GtkWidget *combobox11;
GtkWidget *chec1,*chec2,*chec3;
GtkWidget *output;

float tarif;
int a,e,b;
int nbr_voy;
char aller[100];
char retour[100];
char comp[100];
char da[100];
char dr[100];
char classe[50];
int numvol;



input1=lookup_widget(objet_graphique,"entry5malek");
input2=lookup_widget(objet_graphique,"entry7malek");
output=lookup_widget(objet_graphique,"label65malek");

chec1=lookup_widget(objet_graphique,"economiquemalek");
chec2=lookup_widget(objet_graphique,"businessmalek");
chec3=lookup_widget(objet_graphique,"firstmalek");


combobox7=lookup_widget(objet_graphique,"combobox7malek");
combobox9=lookup_widget(objet_graphique,"combobox9malek");
combobox11=lookup_widget(objet_graphique,"combobox11malek");

spinbuttonadulte=lookup_widget(objet_graphique,"spinbuttonadultemalek");
spinbuttonenfant=lookup_widget(objet_graphique,"spinbuttonenfantmalek");
spinbuttonbebe=lookup_widget(objet_graphique,"spinbuttonbebemalek");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
strcpy(da,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)));
strcpy(dr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonadulte));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonenfant));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonbebe));
gboolean etat1,etat2,etat3;
etat1=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec1));
etat2=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec2));
etat3=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec3));


if (etat1)
	strcpy(classe,"economique");
if (etat2)
	strcpy(classe,"business");
if (etat3)
	strcpy(classe,"first");





nbr_voy=a+e+b;
if(nbr_voy>cherchernombrevoy(aller,retour,comp,da,dr,classe))
	gtk_label_set_text(GTK_LABEL(output),"nombre de place indisponnible!!");
else
{	gtk_label_set_text(GTK_LABEL(output),"vol enregistré avec succès!!");

enregistrer_vol(num_vol,id,j,m,ann,total);
FILE *f1;
f1=fopen("/home/malekbouslah/Desktop/final/src/volreserver.txt", "a+");
		if (f1==NULL)
		{
		return;
		}

	fprintf(f1,"%s %s %s %s %s %s %s %s %d %f\n",num_vol,id,aller,retour,comp,da,dr,classe,nbr_voy,total );

	 fclose(f1);

numvol=numero_vol(aller,retour,comp,da,dr,classe);
modifier_nb_place(numvol,nbr_voy);
}
}



void
on_modifiervolmalek_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage;
GtkWidget *modificationvol;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;

char id[50];
char num[20];
char num_vol[50];char iden[50];char aller[50];char retour[50];char comp[50];char da[50];char dr[50];char classe[50];int nbr_voy;float total;


affichage=lookup_widget(objet_graphique,"affichage");
input1=lookup_widget(objet_graphique,"label68malek");

strcpy(id,gtk_label_get_text(GTK_LABEL(input1)));

input=lookup_widget(objet_graphique,"entry8malek");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
gtk_widget_hide(affichage);
modificationvol=create_modificationvol();
gtk_widget_show(modificationvol);
output=lookup_widget(modificationvol,"label73malek");
gtk_label_set_text(GTK_LABEL(output),id);
output1=lookup_widget(modificationvol,"entry9malek");
gtk_entry_set_text(GTK_ENTRY(output1),num);

output2=lookup_widget(modificationvol,"entry10malek");
output3=lookup_widget(modificationvol,"entry11malek");
output4=lookup_widget(modificationvol,"entry12malek");
output5=lookup_widget(modificationvol,"entry13malek");
output6=lookup_widget(modificationvol,"entry14malek");

FILE *f1=fopen("/home/malekbouslah/Desktop/final/src/volreserver.txt","r");
if (f1!=NULL)
{
	while(fscanf(f1,"%s %s %s %s %s %s %s %s %d %f\n",num_vol,iden,aller,retour,comp,da,dr,classe,&nbr_voy,&total )!=EOF)	
	{
	if(strcmp(num,num_vol)==0)
		{
		gtk_entry_set_text(GTK_ENTRY(output2),aller);
		gtk_entry_set_text(GTK_ENTRY(output3),retour);
		gtk_entry_set_text(GTK_ENTRY(output4),comp);
		gtk_entry_set_text(GTK_ENTRY(output5),da);
		gtk_entry_set_text(GTK_ENTRY(output6),dr);
		}	
	}	

	 
}
fclose(f1);
}


void
on_retourmodifmalek_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *modificationvol;
 GtkWidget *affichage;
 GtkWidget *treeview1;

 GtkWidget *input;
 GtkWidget *output;
 char id[50];

 
 modificationvol=lookup_widget(objet_graphique,"modificationvol");
 input=lookup_widget(objet_graphique,"label73malek");
 strcpy(id,gtk_label_get_text(GTK_LABEL(input)));
 
 gtk_widget_destroy(modificationvol);
 affichage=create_affichage();

 gtk_widget_show(affichage);
 output=lookup_widget(affichage,"label68malek");
 gtk_label_set_text(GTK_LABEL(output),id);
 treeview1=lookup_widget(affichage,"treeview1malek");
 afficher_res(treeview1,id);

 
}


void
on_enregistrermodifmalek_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget modificationvol;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *output1;
GtkWidget *output2;

GtkWidget *chec1,*chec2,*chec3;
GtkWidget *spinbutton1adulte;
GtkWidget *spinbutton2enfant;
GtkWidget *spinbutton3bebe;

float tarif,total;
int a,e,b;
int nbr_voy;
char num[50];
char aller[100];
char retour[100];
char comp[100];
char da[100];
char dr[100];
char prix[50];
//char ch[100];
char classe[50];
char id[50];
int numvol;


input1=lookup_widget(objet_graphique,"entry9malek");
input2=lookup_widget(objet_graphique,"entry10malek");
input3=lookup_widget(objet_graphique,"entry11malek");
input4=lookup_widget(objet_graphique,"entry12malek");
input5=lookup_widget(objet_graphique,"entry13malek");
input6=lookup_widget(objet_graphique,"entry14malek");
output1=lookup_widget(objet_graphique,"label85malek");
output2=lookup_widget(objet_graphique,"label84malek");

chec1=lookup_widget(objet_graphique,"checkbuttoneconomiquemalek");
chec2=lookup_widget(objet_graphique,"checkbuttonbusinessmalek");
chec3=lookup_widget(objet_graphique,"checkbuttonfirstmalek");

spinbutton1adulte=lookup_widget(objet_graphique,"spinbutton1adultemalek");
spinbutton2enfant=lookup_widget(objet_graphique,"spinbutton2enfantmalek");
spinbutton3bebe=lookup_widget(objet_graphique,"spinbutton3bebemalek");

strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(da,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(dr,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(objet_graphique,"label73malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input7)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1adulte));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2enfant));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3bebe));

gboolean etat1,etat2,etat3;
etat1=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec1));
etat2=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec2));
etat3=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec3));

if (etat1)
	strcpy(classe,"economique");
if (etat2)
	strcpy(classe,"business");
if (etat3)
	strcpy(classe,"first");
/*
suppres(num);
reservation r;
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");
//int nume=1;
int numvol;
char num_vol[50];
char j[50];char m[50];char ann[50];*/

strcpy(prix,gtk_label_get_text(GTK_LABEL(output2)));
total=atof(prix);
/*if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %f  \n",r.num_res,r.identifiant,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
{
//nume=atof(r.num_res)+1;
//sprintf(num_vol,"%d",nume);
strcpy(num_vol,num);
}
}
  int day, mois, an;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);

  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
sprintf(j,"%d",day);
sprintf(m,"%d",mois);
sprintf(ann,"%d",an);

enregistrer_vol(num,id,j,m,ann,total);*/

nbr_voy=a+e+b;
/*
FILE *f1;
f1=fopen("/home/malekbouslah/Projects/reservation/src/volreserver.txt", "a+");
		if (f1==NULL)
		{
		return;
		}

	fprintf(f1,"%s %s %s %s %s %s %s %s %d %f\n",num,id,aller,retour,comp,da,dr,classe,nbr_voy,total );

	 fclose(f1);*/
modifierclasseprix(num,classe,nbr_voy,total);
gtk_label_set_text(GTK_LABEL(output1),"modification enregistré avec succès!!");
numvol=numero_vol(aller,retour,comp,da,dr,classe);
modifier_nb_place(numvol,nbr_voy);

}


void
on_devismodifmalek_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget modificationvol;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *output1;

GtkWidget *chec1,*chec2,*chec3;
GtkWidget *spinbutton1adulte;
GtkWidget *spinbutton2enfant;
GtkWidget *spinbutton3bebe;

float tarif,total;
int a,e,b;
int nbr_voy;
char num[50];
char aller[100];
char retour[100];
char comp[100];
char da[100];
char dr[100];
char prix[50];
char ch[100];
char classe[50];


input1=lookup_widget(objet_graphique,"entry9malek");
input2=lookup_widget(objet_graphique,"entry10malek");
input3=lookup_widget(objet_graphique,"entry11malek");
input4=lookup_widget(objet_graphique,"entry12malek");
input5=lookup_widget(objet_graphique,"entry13malek");
input6=lookup_widget(objet_graphique,"entry14malek");

chec1=lookup_widget(objet_graphique,"checkbuttoneconomiquemalek");
chec2=lookup_widget(objet_graphique,"checkbuttonbusinessmalek");
chec3=lookup_widget(objet_graphique,"checkbuttonfirstmalek");

spinbutton1adulte=lookup_widget(objet_graphique,"spinbutton1adultemalek");
spinbutton2enfant=lookup_widget(objet_graphique,"spinbutton2enfantmalek");
spinbutton3bebe=lookup_widget(objet_graphique,"spinbutton3bebemalek");

strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(da,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(dr,gtk_entry_get_text(GTK_ENTRY(input6)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1adulte));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2enfant));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3bebe));

gboolean etat1,etat2,etat3;
etat1=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec1));
etat2=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec2));
etat3=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chec3));

if (etat1)
	strcpy(classe,"economique");
if (etat2)
	strcpy(classe,"business");
if (etat3)
	strcpy(classe,"first");

tarif=tarif_vol(aller,retour,comp,da,dr,classe);
nbr_voy=a+e+b;
total=calcul_prix_vol(tarif,nbr_voy);
sprintf(prix,"%f",total);

strcat(ch,prix);
output1=lookup_widget(objet_graphique,"label84malek");
gtk_label_set_text(GTK_LABEL(output1),prix);


}

//*********************************brody********************************************


GtkWidget *gestionfacture;
GtkWidget *idfacture;
GtkWidget *idclient;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *service;
GtkWidget *prix;
GtkWidget *treeview1;
/*void
on_ajout_clicked                       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
struct facture b;
idfacture=lookup_widget(objet_graphique,"entry2");
idclient=lookup_widget(objet_graphique,"entry3");
jour=lookup_widget(objet_graphique,"spinbutton1");
mois=lookup_widget(objet_graphique,"spinbutton2");
annee=lookup_widget(objet_graphique,"spinbutton3");
nom=lookup_widget(objet_graphique,"entry4");
prenom=lookup_widget(objet_graphique,"entry5");
service=lookup_widget(objet_graphique,"comboboxentry1");
prix=lookup_widget(objet_graphique,"entry6");
strcpy(b.idfacture,gtk_entry_get_text(GTK_ENTRY(idfacture)));
strcpy(b.idclient,gtk_entry_get_text(GTK_ENTRY(idclient)));
strcpy(b.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(b.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
b.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
b.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
b.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(b.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(service)));
strcpy(b.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
ajouter(b);
}*/


void
on_afficherbrody_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview1brody");
afficherbrody(treeview1);
}


void
on_modifierbrody_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestionfacture;
GtkWidget *idfacture;
GtkWidget *idclient;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *service;
GtkWidget *prix;
struct facture b;
idfacture=lookup_widget(objet_graphique,"entry2brody");
idclient=lookup_widget(objet_graphique,"entry3brody");
jour=lookup_widget(objet_graphique,"spinbutton1brody");
mois=lookup_widget(objet_graphique,"spinbutton2brody");
annee=lookup_widget(objet_graphique,"spinbutton3brody");
nom=lookup_widget(objet_graphique,"entry4brody");
prenom=lookup_widget(objet_graphique,"entry5brody");
service=lookup_widget(objet_graphique,"comboboxentry1brody");
prix=lookup_widget(objet_graphique,"entry6brody");
strcpy(b.idfacture,gtk_entry_get_text(GTK_ENTRY(idfacture)));
strcpy(b.idclient,gtk_entry_get_text(GTK_ENTRY(idclient)));
strcpy(b.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(b.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
b.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
b.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
b.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(b.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(service)));
strcpy(b.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
modifierbrody(b);
}


void
on_supprimerbrody_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
*idfacture;
char ch[30];
/*facture f;
char idfacture[20];
strcpy(idfacture,f.idfacture)*/
idfacture=lookup_widget(objet_graphique,"entry1brody");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(idfacture)));
supprimerbrody(ch);
}


//****************************khalil************************************************


void
on_ajouterunevoitureb_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_voiture, *ajouter_une_voiture;
gestion_voiture=lookup_widget(objet,"gestion_voiture");

gtk_widget_destroy(gestion_voiture);
ajouter_une_voiture=create_ajouter_une_voiture();
gtk_widget_show(ajouter_une_voiture);

}


void
on_afficherlesvoitures_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_voiture;
GtkWidget *ajouter_une_voiture;
GtkWidget *liste_voiture;
GtkWidget *treeviewvoiture;

gestion_voiture=lookup_widget(objet,"gestion_voiture");

gtk_widget_destroy(gestion_voiture);
liste_voiture=lookup_widget(objet,"liste_voiture");
liste_voiture = create_liste_voiture();
gtk_widget_show(liste_voiture);
treeviewvoiture=lookup_widget(liste_voiture,"treeviewvoiture");
afficher_voiture(treeviewvoiture);

}




void
on_retourgestion_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_voiture, *ajouter_une_voiture;
ajouter_une_voiture=lookup_widget(objet,"ajouter_une_voiture");

gtk_widget_destroy(ajouter_une_voiture);
gestion_voiture=create_gestion_voiture();
gtk_widget_show(gestion_voiture);


}


void
on_retourajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_voiture, *gestion_voiture;
GtkWidget *output;

liste_voiture=lookup_widget(objet,"liste_voiture");
gtk_widget_hide(liste_voiture);
gestion_voiture=create_gestion_voiture();
gtk_widget_show(gestion_voiture);

}


void
on_supprimer_voiture_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

char serie1[3000];
GtkWidget *inputmod;


inputmod=lookup_widget(objet,"entry_supprimer_voiture");
strcpy(serie1,gtk_entry_get_text(GTK_ENTRY(inputmod)));
supprimervoiture(serie1);
}




void
on_refresh1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_voiture;
GtkWidget *treeviewvoiture;

liste_voiture=lookup_widget(objet,"liste_voiture");

gtk_widget_destroy(liste_voiture);
liste_voiture=create_liste_voiture();
gtk_widget_show(liste_voiture);

treeviewvoiture=lookup_widget(liste_voiture,"treeviewvoiture");
afficher_voiture(treeviewvoiture);
}


void
on_modifierunevoiture_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *liste_voiture, *modifier_voiture,*inputmod;

char serie1[3000];
inputmod=lookup_widget(objet,"entry_supprimer_voiture");
strcpy(serie1,gtk_entry_get_text(GTK_ENTRY(inputmod)));


FILE *f_md;
f_md=fopen("/home/malekbouslah/Desktop/final/src/md.txt","w");
if(f_md!=NULL){
    fprintf(f_md,"%s",serie1);} 
fclose(f_md);

liste_voiture=lookup_widget(objet,"liste_voiture");
gtk_widget_destroy(liste_voiture);

modifier_voiture=create_modifier_voiture();
gtk_widget_show(modifier_voiture);

}


void
on_validerchangement_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input111,*input222,*input333,*input444,*input555,*input666,*inputmod;

/*GtkWidget *gestion_voiture;
GtkWidget *ajouter_une_voiture;
 */
GtkWidget *modifier_voiture;
GtkWidget *liste_voiture;
GtkWidget *treeviewvoiture;

Voiture p;
Voituremod m;

char serie1[3000];

FILE *f_md;
f_md=fopen("/home/malekbouslah/Desktop/final/src/md.txt","r");
if(f_md!=NULL){
    fscanf(f_md,"%s",serie1);} 
fclose(f_md);
remove("/home/malekbouslah/Desktop/final/src/md.txt");

input111=lookup_widget(objet,"combobox2khalil");
input222=lookup_widget(objet,"entryserie_mod");
input333=lookup_widget(objet,"entryage_mod");
input444=lookup_widget(objet,"entrykilometrage_mod");
input555=lookup_widget(objet,"entryprix_mod");
input666=lookup_widget(objet,"entrydate_mod");


strcpy(m.modmarque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input111)));
strcpy(m.modserie,gtk_entry_get_text(GTK_ENTRY(input222)));
strcpy(m.modage,gtk_entry_get_text(GTK_ENTRY(input333)));
strcpy(m.modkilometrage,gtk_entry_get_text(GTK_ENTRY(input444)));
strcpy(m.modprix,gtk_entry_get_text(GTK_ENTRY(input555)));
strcpy(m.moddate,gtk_entry_get_text(GTK_ENTRY(input666)));
modifiervoiture(m,serie1);

modifier_voiture=lookup_widget(objet,"modifier_voiture");
gtk_widget_destroy(modifier_voiture);

liste_voiture=create_liste_voiture();
gtk_widget_show(liste_voiture);


treeviewvoiture=lookup_widget(liste_voiture,"treeviewvoiture");
afficher_voiture(treeviewvoiture);




}


void
on_retourliste_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_voiture, *modifier_voiture,*treeviewvoiture;
modifier_voiture=lookup_widget(objet,"modifier_voiture");

gtk_widget_destroy(modifier_voiture);
liste_voiture=create_liste_voiture();
gtk_widget_show(liste_voiture);
treeviewvoiture=lookup_widget(liste_voiture,"treeviewvoiture");
afficher_voiture(treeviewvoiture);

}


void
on_validerkk_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
GtkWidget *gestion_voiture;
GtkWidget *ajouter_une_voiture;
GtkWidget *liste_voiture;

char erreur[50],*markup; const char *format="<span foreground=\"blue\"><b>\%s</b></span>";
char empty[]="\0";
int r,z;
char serieh[100];
GtkWidget *output;
GtkWidget *output1,*output2,*output3,*output4,*output5,*output6;
output1=lookup_widget(objet,"errr1");
output2=lookup_widget(objet,"errr2");
output3=lookup_widget(objet,"errr3");
output4=lookup_widget(objet,"errr4");
output5=lookup_widget(objet,"errr5");
output6=lookup_widget(objet,"errr6");



Voiture p;
input1=lookup_widget(objet,"comboboxkhalil");
input2=lookup_widget(objet,"entryserie_voiture");
input3=lookup_widget(objet,"entryage_voiture");
input4=lookup_widget(objet,"entrykilometrage_voiture");
input5=lookup_widget(objet,"entryprix_voiture");
input6=lookup_widget(objet,"entrydate_voiture");
output=lookup_widget(objet,"label7k");

strcpy(p.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(p.serie,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.kilometrage,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.date,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(serieh,gtk_entry_get_text(GTK_ENTRY(input2)));
r=test_serie(serieh);
///////////controlesaisi///////////////
do {

if(r==1)
{
sprintf(erreur,"serie de voiture existante");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output2),markup);}




else if(strcmp(p.marque,empty)==0) /*marque*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);}

else if(strcmp(p.serie,empty)==0) /*serie*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output2),markup);}

else if(strcmp(p.age,empty)==0) /*age*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output3),markup);}

else if(strcmp(p.kilometrage,empty)==0) /*kilometrage*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output4),markup);}

else if(strcmp(p.prix,empty)==0) /*prix*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output5),markup);}

else if(strcmp(p.date,empty)==0) /*date*/
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output6),markup);}
else
{
ajouter_voiture(p);
z=1;
gtk_label_set_text(GTK_LABEL(output),"Voiture ajoutée");
}       }while(z!=1);

//////////////////controlesaisi//////////////////

}


//***************************************amal**************************************


void
on_AGAjouter_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
VOLa vol;

char *a[30];
float n;

int r,r1;
int num;
char ch[30],c[30];

GtkWidget *Num_vol,*Compagnie_aerienne,*Depart,*Destination,*Date_depart_jour,*Date_depart_mois,*Date_depart_annee,*Date_retour_jour,*Date_retour_mois,*Date_retour_annee,*Classe,*Tarif,*Nbr_max,*Confirmation;

char erreur[50], *markup; const char *format="<span foreground=\"red\"><b>\%s</b></span>";
char empty[]="\0";

Num_vol=lookup_widget(objet,"AGnum_vol");
Compagnie_aerienne=lookup_widget(objet,"AGcompagnie_aerienne");
Depart=lookup_widget(objet,"AGdepart");
Destination=lookup_widget(objet,"AGdestination");
Date_depart_jour=lookup_widget(objet,"AGdate_depart_jour");
Date_depart_mois=lookup_widget(objet,"AGdate_depart_mois");
Date_depart_annee=lookup_widget(objet,"AGdate_depart_annee");
Date_retour_jour=lookup_widget(objet,"AGdate_retour_jour");
Date_retour_mois=lookup_widget(objet,"AGdate_retour_mois");
Date_retour_annee=lookup_widget(objet,"AGdate_retour_annee");
Classe=lookup_widget(objet,"AGclasse");
Tarif=lookup_widget(objet,"AGtarif");
Nbr_max=lookup_widget(objet,"AGnbr_max");
Confirmation=lookup_widget(objet,"AGlabelConfirmation");

vol.num_vol=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));
strcpy(vol.compagnie_aerienne,gtk_entry_get_text(GTK_ENTRY(Compagnie_aerienne)));
strcpy(vol.depart,gtk_entry_get_text(GTK_ENTRY(Depart)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(Destination)));
vol.date_depart.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_jour));
vol.date_depart.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_mois));
vol.date_depart.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_annee));
vol.date_retour.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_jour));
vol.date_retour.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_mois));
vol.date_retour.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_annee));
strcpy(vol.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
n=strtof(gtk_entry_get_text(GTK_ENTRY(Tarif)),&a);
vol.tarif=n;
vol.nbr_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Nbr_max));
num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(Tarif)));

r1=AGtest_tarif(ch);

r=AGtest_num_vol(num);

gcvt(vol.tarif,6,c);

if((strcmp(empty,vol.compagnie_aerienne)==0) || (strcmp(empty,vol.destination)==0) || (strcmp(empty,vol.depart)==0) || (strcmp(empty,vol.destination)==0) || (strcmp(empty,c)==0))
{
	sprintf(erreur,"* champs obligatoires");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(Confirmation),markup);
}
else if(r==1)
{
	sprintf(erreur,"Ce numero existe deja");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(Confirmation),markup);
}
else if(r1==1)
{
	sprintf(erreur,"tarif non valide");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(Confirmation),markup);
}
else
{
	AGajouter_vol(vol);	
	sprintf(erreur,"Vol ajoutee");
	markup=g_markup_printf_escaped(format,erreur);
	gtk_label_set_markup(GTK_LABEL(Confirmation),markup);
}
ajoutcataloguemalek();
}


void
on_AGAfficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowAffichage;
GtkWidget *treeview1;

windowAjout=lookup_widget(objet,"AGwindowAjout");

gtk_widget_destroy(windowAjout);
windowAffichage=lookup_widget(objet,"AGwindowAffichage");
windowAffichage=create_AGwindowAffichage();

gtk_widget_show(windowAffichage);

treeview1=lookup_widget(windowAffichage,"AGtreeview1");

AGafficher_vol(treeview1);

}


void
on_AGRetour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAjout, *windowAffichage;

windowAffichage = lookup_widget(objet,"AGwindowAffichage");

gtk_widget_destroy(windowAffichage);
windowAjout = create_AGwindowAjout();
gtk_widget_show(windowAjout);
}


void
on_AGrecherche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Num_vol,*Compagnie_aerienne,*Depart,*Destination,*Date_depart_jour,*Date_depart_mois,*Date_depart_annee,*Date_retour_jour,*Date_retour_mois,*Date_retour_annee,*Classe,*Tarif,*Nbr_max,*output;

GtkWidget *windowModifier;

VOLa vol;

int num_volR;

char c1[30],c2[30],c3[30],c4[30],c5[30],c6[30],c7[30],c8[30];

char erreur[50], *markup; const char *format="<span foreground=\"red\"><b>\%s</b></span>";

Num_vol=lookup_widget(objet,"AGnum_volM");
Compagnie_aerienne=lookup_widget(objet,"AGcompagnie_aerienneM");
Depart=lookup_widget(objet,"AGdepartM");
Destination=lookup_widget(objet,"AGdestinationM");
Date_depart_jour=lookup_widget(objet,"AGdate_depart_jourM");
Date_depart_mois=lookup_widget(objet,"AGdate_depart_moisM");
Date_depart_annee=lookup_widget(objet,"AGdate_depart_anneeM");
Date_retour_jour=lookup_widget(objet,"AGdate_retour_jourM");
Date_retour_mois=lookup_widget(objet,"AGdate_retour_moisM");
Date_retour_annee=lookup_widget(objet,"AGdate_retour_anneeM");
Classe=lookup_widget(objet,"AGclasseM");
Tarif=lookup_widget(objet,"AGtarifM");
Nbr_max=lookup_widget(objet,"AGnbr_maxM");
output=lookup_widget(objet,"AGlabelConfirmationM");

num_volR=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));

FILE *f;
f=fopen("/home/malekbouslah/Desktop/final/src/catalogue_vol.txt","r"); 
if (f!=NULL)
{
while (fscanf(f, " %d %s %s %s %d %d %d %d %d %d %s %f %d		 \n",&vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,&vol.date_depart.jour,&vol.date_depart.mois,&vol.date_depart.annee,&vol.date_retour.jour,&vol.date_retour.mois,&vol.date_retour.annee,vol.classe,&vol.tarif,&vol.nbr_max)!=EOF)
	{
		if (num_volR!=vol.num_vol)
		{   
			sprintf(erreur,"ce numéro n'éxiste pas");
			markup=g_markup_printf_escaped(format,erreur);
			gtk_label_set_markup(GTK_LABEL(output),markup);
		}
		if  (num_volR==vol.num_vol)
		{
			sprintf(erreur,"Voici votre recherche");
			markup=g_markup_printf_escaped(format,erreur);
			gtk_label_set_markup(GTK_LABEL(output),markup);
			gtk_entry_set_text (GTK_ENTRY (Compagnie_aerienne),vol.compagnie_aerienne);
			gtk_entry_set_text (GTK_ENTRY (Depart), vol.depart);
			gtk_entry_set_text (GTK_ENTRY (Destination), vol.destination);
			sprintf(c1,"%d",vol.date_depart.jour);
			gtk_entry_set_text (GTK_ENTRY (Date_depart_jour),c1);
			sprintf(c2,"%d",vol.date_depart.mois);
			gtk_entry_set_text (GTK_ENTRY (Date_depart_mois),c2);
			sprintf(c3,"%d",vol.date_depart.annee);
			gtk_entry_set_text (GTK_ENTRY (Date_depart_annee), c3);
			sprintf(c4,"%d",vol.date_retour.jour);
			gtk_entry_set_text (GTK_ENTRY (Date_retour_jour),c4);
			sprintf(c5,"%d",vol.date_retour.mois);
			gtk_entry_set_text (GTK_ENTRY (Date_retour_mois),c5);
			sprintf(c6,"%d",vol.date_retour.annee);
			gtk_entry_set_text (GTK_ENTRY (Date_retour_annee),c6);
			gtk_entry_set_text (GTK_ENTRY (Classe), vol.classe);
			gcvt(vol.tarif,6,c7);
			gtk_entry_set_text (GTK_ENTRY (Tarif), c7);
			sprintf(c8,"%d",vol.nbr_max);
			gtk_entry_set_text (GTK_ENTRY (Nbr_max), c8);

		}
	}
fclose(f);
}
}

void
on_AGvalider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Num_vol,*Compagnie_aerienne,*Depart,*Destination,*Date_depart_jour,*Date_depart_mois,*Date_depart_annee,*Date_retour_jour,*Date_retour_mois,*Date_retour_annee,*Classe,*Tarif,*Nbr_max,*output;

VOLa vol;

char empty[]="\0";

int r;

char erreur[50], *markup; const char *format="<span foreground=\"red\"><b>\%s</b></span>";

char ch[30],c[30];

char *a[30];
float n;

Num_vol=lookup_widget(objet,"AGnum_volM");
Compagnie_aerienne=lookup_widget(objet,"AGcompagnie_aerienneM");
Depart=lookup_widget(objet,"AGdepartM");
Destination=lookup_widget(objet,"AGdestinationM");
Date_depart_jour=lookup_widget(objet,"AGdate_depart_jourM");
Date_depart_mois=lookup_widget(objet,"AGdate_depart_moisM");
Date_depart_annee=lookup_widget(objet,"AGdate_depart_anneeM");
Date_retour_jour=lookup_widget(objet,"AGdate_retour_jourM");
Date_retour_mois=lookup_widget(objet,"AGdate_retour_moisM");
Date_retour_annee=lookup_widget(objet,"AGdate_retour_anneeM");
Classe=lookup_widget(objet,"AGclasseM");
Tarif=lookup_widget(objet,"AGtarifM");
Nbr_max=lookup_widget(objet,"AGnbr_maxM");
output=lookup_widget(objet,"AGlabelConfirmationM");

vol.num_vol=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));
strcpy(vol.compagnie_aerienne,gtk_entry_get_text(GTK_ENTRY(Compagnie_aerienne)));
strcpy(vol.depart,gtk_entry_get_text(GTK_ENTRY(Depart)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(Destination)));
vol.date_depart.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_jour));
vol.date_depart.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_mois));
vol.date_depart.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_depart_annee));
vol.date_retour.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_jour));
vol.date_retour.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_mois));
vol.date_retour.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Date_retour_annee));
strcpy(vol.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
n=strtof(gtk_entry_get_text(GTK_ENTRY(Tarif)),&a);
vol.tarif=n;
vol.nbr_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Nbr_max));

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(Tarif)));

r=AGtest_tarif(ch);

gcvt(vol.tarif,6,c);

if((strcmp(empty,vol.compagnie_aerienne)==0) || (strcmp(empty,vol.destination)==0) || (strcmp(empty,vol.depart)==0) || (strcmp(empty,vol.destination)==0) || (strcmp(empty,c)==0))
{
	sprintf(erreur,"* champs obligatoires");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output),markup);
}

else if(r==1)
{
	sprintf(erreur,"tarif non valide");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output),markup);
}
else
{
	AGmodifier_vol(vol);	
	sprintf(erreur,"Vol modifiee");
	markup=g_markup_printf_escaped(format,erreur);
	gtk_label_set_markup(GTK_LABEL(output),markup);
}
}


void
on_AGmodifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowModifier,*windowAffichage;
windowModifier=create_AGwindowModifier ();
windowAffichage=lookup_widget(objet,"AGwindowAffichage");
gtk_widget_show(windowModifier);
gtk_widget_hide(windowAffichage);
}


void
on_AGRetourM_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowAffichage;
GtkWidget *treeview1;

windowModifier=lookup_widget(objet,"AGwindowModifier");

gtk_widget_destroy(windowModifier);
windowAffichage=lookup_widget(objet,"AGwindowAffichage");
windowAffichage=create_AGwindowAffichage();

gtk_widget_show(windowAffichage);

treeview1=lookup_widget(windowAffichage,"AGtreeview1");

AGafficher_vol(treeview1);
}


void
on_AGsupprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

int r;

char erreur[50], *markup; const char *format="<span foreground=\"red\"><b>\%s</b></span>";

GtkWidget* num_volS;
GtkWidget *windowAffichage;
GtkWidget *treeview1;
GtkWidget *output,*input,*confirmation;

input=lookup_widget(objet,"AGspinButtonSupprimer");
output=lookup_widget(objet,"AGlabelConfirmationS");


num_volS=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

r=AGtest_num_vol(num_volS);

if(r==1)
{
	AGsupprimer_vol(num_volS);
	windowAffichage=lookup_widget(objet,"AGwindowAffichage");

	gtk_widget_destroy(windowAffichage);
	windowAffichage=lookup_widget(objet,"AGwindowAffichage");
	windowAffichage=create_AGwindowAffichage();

	gtk_widget_show(windowAffichage);

	treeview1=lookup_widget(windowAffichage,"AGtreeview1");

	AGafficher_vol(treeview1);

	confirmation=lookup_widget(objet,"AGwindowConfirmation");
	confirmation=create_AGwindowConfirmation();
	gtk_widget_show(confirmation);
}
else
{
		sprintf(erreur,"ce numéro n'éxiste pas");
		markup=g_markup_printf_escaped(format,erreur);
		gtk_label_set_markup(GTK_LABEL(output),markup);
}
}


//*********** amir***************




void
on_afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview1;

window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
window2=lookup_widget(objet,"window2");
window2=create_window2();

gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeview1");

afficher_hotel(treeview1);
}
void
on_ajouter_clicked                     (GtkButton       *objet,
                                      gpointer         user_data)
{
hotel p;
GtkWidget *numh,*input1,*input2,*input3,*jour,*mois,*annee,*rank,*input4;
GtkWidget *output1,*output2,*output3,*output4;
char erreur[50], *markup; const char *format="<span foreground=\"blue\"><b>\%s</b></span>";
char empty[]="\0",ch[30],ch1[20];
int num,num1,r,test,test1;
GtkWidget *window1;
gboolean toggle1,toggle2,toggle3;

window1=lookup_widget(objet,"window1");
output1=lookup_widget(objet,"err1");
output2=lookup_widget(objet,"err2");
output3=lookup_widget(objet,"err3");
output4=lookup_widget(objet,"err4");
numh=lookup_widget(objet,"numh");
input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"lieu");
input3=lookup_widget(objet,"chambre_vide");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
input4=lookup_widget(objet,"prix");
p.numh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numh));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.chambre_vide,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(p.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(p.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));
toggle1=on_checkbutton1_toggled(objet,user_data);
toggle2=on_checkbutton2_toggled(objet,user_data);
toggle3=on_checkbutton3_toggled(objet,user_data);
strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numh));
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input4)));
                 if (toggle1)
			strcpy(p.rank,"3etoille");
		else if(toggle2)
			strcpy(p.rank,"4etoille");
		else if(toggle3)
			strcpy(p.rank,"5etoille");
r=test_num(num);
num1=atoi(ch);
test=test_nombre(ch);
test1=test_nombre(ch1);
if(r==1)
{
sprintf(erreur,"Ce numero est existant");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
}
else if(strcmp(p.nom,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
}
else if (strlen(p.nom)<3)
{
sprintf(erreur,"Nom est trop courte");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
}
else if(strcmp(p.lieu,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output2),markup);
}
else if(strcmp(p.chambre_vide,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output3),markup);
}
else if (test==1)
{
sprintf(erreur,"numéro doit etre formé par des chiffres");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output3),markup);
}
else if(strcmp(p.prix,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output4),markup);
}

else if (test1==1)
{sprintf(erreur,"numéro doit etre formé par des chiffres");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output4),markup);
}
else
{
ajouter_hotel(p);
sprintf(erreur,"Ajout avec succés");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output4),markup);
}
}


void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window2=lookup_widget(objet,"window2");

gtk_widget_destroy(window2);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window3;

window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
window3=lookup_widget(objet,"window3");
window3=create_window3();
gtk_widget_show(window3);
}


void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window4;

window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
window4=lookup_widget(objet,"window4");
window4=create_window4();
gtk_widget_show(window4);
}


void
on_rechercher_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window6;

window1=lookup_widget(objet,"window1");

window6=lookup_widget(objet,"window6");
window6=create_window6();
gtk_widget_show(window6);
}
void
on_retour2_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window3;

window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_confirmer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3,*window5,*window1;
GtkWidget *numh1;


numh1=lookup_widget(objet,"numh1");
numh1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numh1));
supprimer(numh1);

window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window5=lookup_widget(objet,"window5");
window5=create_window5();
gtk_widget_show(window5);
window1=lookup_widget(objet,"window1");
window1=create_window1();
gtk_widget_show(window1);

}



void
on_valider_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*output1 , *output2 , *output3,*output4,*output5, *output9;
hotel p;
int numh;
char erreur[50], *markup; const char *format="<span foreground=\"blue\"><b>\%s</b></span>";
input1=lookup_widget(objet,"numh2");
output1=lookup_widget(objet,"oui");
output2=lookup_widget(objet,"nnom");
output3=lookup_widget(objet,"nlieu");
output4=lookup_widget(objet,"nchambre_vide");
output5=lookup_widget(objet,"nrank");
output9=lookup_widget(objet,"nprix");

numh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));

FILE *f;
  f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%d %s %s %s %s %s %s %s %s \n",&p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix)!=EOF)
    {
   if (p.numh==numh)
   {
     
     gtk_entry_set_text (GTK_ENTRY (output2), p.nom);
     gtk_entry_set_text (GTK_ENTRY (output3), p.lieu);
     gtk_entry_set_text (GTK_ENTRY (output4), p.chambre_vide);
     gtk_entry_set_text (GTK_ENTRY (output9), p.prix);
      
   }
else   
           {
      sprintf(erreur,"ce numéro n'éxiste pas");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
            }
   }
}
}


void
on_ret_modif_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window4;

window4=lookup_widget(objet,"window4");

gtk_widget_destroy(window4);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_modif_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
hotel p;

GtkWidget *window4; 
GtkWidget *numh,*input1, *input2,*input3,*jour,*mois,*annee,*rank,*input4,*output,*output1,*output2,*output3,*output4;
char erreur[50], *markup; const char *format="<span foreground=\"red\"><b>\%s</b></span>";
char empty[]="\0";
window4=lookup_widget(objet,"window4");
numh=lookup_widget(objet,"nnumh");
input1=lookup_widget(objet,"nnom");
input2=lookup_widget(objet,"nlieu");
input3=lookup_widget(objet,"nchambre_vide");
jour=lookup_widget(objet,"njour");
mois=lookup_widget(objet,"nmois");
annee=lookup_widget(objet,"nannee");
rank=lookup_widget(objet,"nrank");
input4=lookup_widget(objet,"nprix");
output=lookup_widget(objet,"label87");
output1=lookup_widget(objet,"label88");
output2=lookup_widget(objet,"label89");
output3=lookup_widget(objet,"label90");
output4=lookup_widget(objet,"label91");
p.numh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numh));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.chambre_vide,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(p.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(p.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));
strcpy(p.rank,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rank)));
strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
if(strcmp(p.nom,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
}
else if (strlen(p.nom)<3)
{
sprintf(erreur,"Nom est trop courte");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output1),markup);
}
else if(strcmp(p.lieu,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output2),markup);
}
else if(strcmp(p.chambre_vide,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output3),markup);
}
else if(strcmp(p.prix,empty)==0)
{
sprintf(erreur,"Ce champ est obligatoire");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output4),markup);
}
else
{
modifier_hotel(p);
sprintf(erreur,"modification succé");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output),markup);
}
}

gboolean
on_checkbutton1_toggled                (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2,*togglebutton3;
	gboolean etat;
	togglebutton1=lookup_widget(objet,"checkbutton1");
	togglebutton2=lookup_widget(objet,"checkbutton2");
	togglebutton3=lookup_widget(objet,"checkbutton3");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton1));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton3),FALSE);
	}
	return etat;
}


gboolean
on_checkbutton3_toggled                (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2,*togglebutton3;
	gboolean etat;
	togglebutton1=lookup_widget(objet,"checkbutton1");
	togglebutton2=lookup_widget(objet,"checkbutton2");
	togglebutton3=lookup_widget(objet,"checkbutton3");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton3));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
	}
	return etat;
}


gboolean
on_checkbutton2_toggled                (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2,*togglebutton3;
	gboolean etat;
	togglebutton1=lookup_widget(objet,"checkbutton1");
	togglebutton2=lookup_widget(objet,"checkbutton2");
	togglebutton3=lookup_widget(objet,"checkbutton3");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton2));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton3),FALSE);
	}
	return etat;
}


void
on_ret_rech_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window6;

window6=lookup_widget(objet,"window6");

gtk_widget_destroy(window6);


}


void
on_button1_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window6,*window1,*input1,*output1 , *output2 , *output3,*output4,*output5,*output6,*output7;
hotel p;
char ch[30];
char erreur[50], *markup; const char *format="<span foreground=\"sky blue\"><b>\%s</b></span>";
int rnum;
window1=lookup_widget(objet,"window1");
window6=lookup_widget(objet,"window6");
input1=lookup_widget(objet,"rnumh");
output7=lookup_widget(objet,"label85");
output1=lookup_widget(objet,"rnom");
output2=lookup_widget(objet,"rlieu");
output3=lookup_widget(objet,"rchambre");
output4=lookup_widget(objet,"rdate");
output5=lookup_widget(objet,"rrank");
output6=lookup_widget(objet,"rprix");

rnum=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));

FILE *f;
  f=fopen("/home/malekbouslah/Desktop/final/src/hotel.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%d %s %s %s %s %s %s %s %s\n",&p.numh,p.nom,p.lieu,p.chambre_vide,p.jour,p.mois,p.annee,p.rank,p.prix)!=EOF)
    {strcpy(ch,p.jour);
	         strcat(ch,"/");
		 strcat(ch,p.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,p.annee);
   if (p.numh==rnum)
   {  sprintf(erreur,"VOICI VOTRE RECHERCHE");
      markup=g_markup_printf_escaped(format,erreur);
      gtk_label_set_markup(GTK_LABEL(output7),markup);
      gtk_entry_set_text (GTK_ENTRY (output1), p.nom);
      gtk_entry_set_text (GTK_ENTRY (output2), p.lieu);
      gtk_entry_set_text (GTK_ENTRY (output3), p.chambre_vide);
      gtk_entry_set_text (GTK_ENTRY (output4), ch);
      gtk_entry_set_text (GTK_ENTRY (output5), p.rank);
      gtk_entry_set_text (GTK_ENTRY (output6), p.prix);

}
}
}
}
//**************************zahra*******************************

void
on_connexion_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel;
GtkWidget *connexion;

skytravel=lookup_widget(objet_graphique,"skytravel");
connexion=lookup_widget(objet_graphique,"connexion");

gtk_widget_destroy(skytravel);
connexion=create_connexion();
gtk_widget_show(connexion);
}


void
on_retourconn_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel;
GtkWidget *connexion;

skytravel=lookup_widget(objet_graphique,"skytravel");
connexion=lookup_widget(objet_graphique,"connexion");

gtk_widget_destroy(connexion);
skytravel=create_skytravel();
gtk_widget_show(skytravel);

}



void
on_identifier_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *connexion,*input1,*input2,*output,*output1;
 GtkWidget *menuadmin,*reservations,*menuagent;
 char nom[30],mdp[30],test[30];
 int role;


 input1=lookup_widget(objet_graphique,"entry1");
 input2=lookup_widget(objet_graphique,"entry2");
 output=lookup_widget(objet_graphique,"label96");
 strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));
role=veriflogin(nom,mdp);
switch(role)
{
	case 1:
		{
		connexion=lookup_widget(objet_graphique,"connexion");
		menuadmin=create_menuadmin();
		gtk_widget_show(menuadmin);
		gtk_widget_hide(connexion);
	break;
		}
	case 2:
		{
		connexion=lookup_widget(objet_graphique,"connexion");
		menuagent=create_menuagent();
		gtk_widget_show(menuagent);
		gtk_widget_hide(connexion);
	break;
		}
	case 3:
		{
		connexion=lookup_widget(objet_graphique,"connexion");
		reservations=create_reservations();
		gtk_widget_show(reservations);
		gtk_widget_hide(connexion);
		
		output1=lookup_widget(reservations,"label67malek");
		gtk_label_set_text(GTK_LABEL(output1),nom);
		
	break;
		}
	case 0:
		gtk_label_set_text(GTK_LABEL(output),"Erreur: verifier login ou mot de passe");
}

}



void
on_deconnexionclientmalek_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel,*reservations;
reservations=lookup_widget(objet_graphique,"reservations");
skytravel=create_skytravel();
gtk_widget_show(skytravel);
gtk_widget_hide(reservations);
}


void
on_deconnexionagent_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel,*menuagent;
menuagent=lookup_widget(objet_graphique,"menuagent");
skytravel=create_skytravel();
gtk_widget_show(skytravel);
gtk_widget_hide(menuagent);
}


void
on_gestionclient_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuadmin,*clientadmin;
GtkWidget *treeview2;

menuadmin=lookup_widget(objet_graphique,"menuadmin");

//gtk_widget_destroy(menuadmin);
//clientadmin=lookup_widget(objet_graphique,"clientadmin");
clientadmin=create_clientadmin();

gtk_widget_show(clientadmin);

treeview2=lookup_widget(clientadmin,"treeview2");

afficher_personne(treeview2);
}


void
on_retourca_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *menuadmin;
GtkWidget *clientadmin;

clientadmin=lookup_widget(objet_graphique,"clientadmin");
gtk_widget_destroy(clientadmin);
//menuadmin=create_menuadmin();
//gtk_widget_show(menuadmin);
}


void
on_ajoutca_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *clientadmin,*window3zahra;

clientadmin=lookup_widget(objet_graphique,"clientadmin");
//gtk_widget_destroy(clientadmin);
window3zahra=create_window3zahra();
gtk_widget_show(window3zahra);

}


void
on_supprimerca_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *clientadmin,*treeview2;
GtkWidget *input;
char supp[30];
input=lookup_widget(objet_graphique,"entry3zahra");
strcpy(supp,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_client (supp);
clientadmin=lookup_widget(objet_graphique,"clientadmin");
gtk_widget_destroy(clientadmin);
clientadmin=create_clientadmin();
gtk_widget_show(clientadmin);

treeview2=lookup_widget(clientadmin,"treeview2");

afficher_personne(treeview2);

}


void
on_inscription_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel,*window3zahra;

skytravel=lookup_widget(objet_graphique,"skytravel");
//gtk_widget_destroy(skytravel);
window3zahra=create_window3zahra();
gtk_widget_show(window3zahra);
}


void
on_s_inscrire_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
personne p;
GtkWidget *input1,*input2,*input3,*input4,*sexe,*jour,*mois,*annee,*input5,*input6,*input7;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output20;

char empty[]="\0";
GtkWidget *window3;

window3=lookup_widget(objet_graphique,"window3zahra");

output7=lookup_widget(objet_graphique,"erreur7zahra");
output6=lookup_widget(objet_graphique,"erreur6zahra");
output5=lookup_widget(objet_graphique,"erreur5zahra");
output4=lookup_widget(objet_graphique,"erreur4zahra");
output3=lookup_widget(objet_graphique,"erreur3zahra");
output2=lookup_widget(objet_graphique,"erreur2zahra");
output1=lookup_widget(objet_graphique,"erreur1zahra");

input1=lookup_widget(objet_graphique,"identifiantzahra");
input2=lookup_widget(objet_graphique,"mot_de_passezahra");
input3=lookup_widget(objet_graphique,"nomzahra");
input4=lookup_widget(objet_graphique,"prenomzahra");
input5=lookup_widget(objet_graphique,"telzahra");
input6=lookup_widget(objet_graphique,"emailzahra");
input7=lookup_widget(objet_graphique,"adressezahra");
jour=lookup_widget(objet_graphique,"jourzahra");
mois=lookup_widget(objet_graphique,"moiszahra");
annee=lookup_widget(objet_graphique,"anneezahra");
sexe=lookup_widget(objet_graphique,"sexezahra");


strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
p.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
p.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
p.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

if(strcmp(p.identifiant,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output1),"Veuillez saisir votre identifiant"); 
}
else if(strcmp(p.mot_de_passe,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"Veuillez saisir votre mot de passe");
}
else if(strcmp(p.nom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"Veuillez saisir votre nom");
}
else if(strcmp(p.prenom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output4),"Veuillez saisir votre prenom");
}
else if(strcmp(p.tel,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output5),"Veuillez saisir votre tel");
}
else if(strcmp(p.email,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output6),"Veuillez saisir votre email");
}
else if(strcmp(p.adresse,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output7),"Veuillez saisir votre adresse");
}
else
{
ajouter_personne(p);
FILE *f=fopen("/home/malekbouslah/Desktop/final/src/users.txt","a+");
if(f==NULL)
{
return;
}
fprintf(f,"%s %s %s\n",gtk_entry_get_text(GTK_ENTRY(input1)),gtk_entry_get_text(GTK_ENTRY(input2)),"3");
fclose(f);
output20=lookup_widget(objet_graphique,"label113");
gtk_label_set_text(GTK_LABEL(output20),"user ajouté!!");
}

//window3=lookup_widget(objet_graphique,"window3zahra");
//gtk_widget_destroy(window3);
}



void
on_deconnexionadmin_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuadmin,*connexion;
menuadmin=lookup_widget(objet_graphique,"menuadmin");
gtk_widget_destroy(menuadmin);
connexion=lookup_widget(objet_graphique,"connexion");
connexion=create_connexion();
gtk_widget_show(connexion);
}


void
on_modifierca_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
personne p;
GtkWidget *clientadmin,*window5zahra;
GtkWidget *input1,*output1,*output2,*output3,*output4,*output5,*output6,*output7;

char id [30];
//clientadmin=lookup_widget(objet_graphique,"clientadmin");

//window5zahra=lookup_widget(objet_graphique,"window5zahra");

input1=lookup_widget(objet_graphique,"entry3zahra");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
clientadmin=lookup_widget(objet_graphique,"clientadmin");
gtk_widget_destroy(clientadmin);
window5zahra=create_window5zahra();
gtk_widget_show(window5zahra);

output1=lookup_widget(window5zahra,"nidzahra");
gtk_entry_set_text (GTK_ENTRY (output1),id);
output2=lookup_widget(window5zahra,"nmot_de_passezahra");
output3=lookup_widget(window5zahra,"nnomzahra");
output4=lookup_widget(window5zahra,"nprenomzahra");
output5=lookup_widget(window5zahra,"ntelzahra");
output6=lookup_widget(window5zahra,"nemailzahra");
output7=lookup_widget(window5zahra,"nadressezahra");


FILE *f;
	f=fopen("/home/malekbouslah/Desktop/final/src/client.txt","r");
	if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,&p.jour,&p.mois,&p.annee,p.tel,p.email,p.adresse)!=EOF)
{
	if (strcmp(p.identifiant,id)==0)
{

gtk_entry_set_text (GTK_ENTRY (output2),p.mot_de_passe);
gtk_entry_set_text (GTK_ENTRY (output3),p.nom);
gtk_entry_set_text (GTK_ENTRY (output4),p.prenom);
gtk_entry_set_text (GTK_ENTRY (output5),p.tel);
gtk_entry_set_text (GTK_ENTRY (output6),p.email);
gtk_entry_set_text (GTK_ENTRY (output7),p.adresse);
}
}
}
fclose(f);

}


void
on_retourmodifzahra_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *clientadmin,*window5zahra,*treeview2;
window5zahra=lookup_widget(objet_graphique,"window5zahra");
gtk_widget_destroy(window5zahra);
clientadmin=create_clientadmin();
gtk_widget_show(clientadmin);
treeview2=lookup_widget(clientadmin,"treeview2");

afficher_personne(treeview2);

}


void
on_enregistrermodifzahra_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
personne p;
GtkWidget *window5zahra;
GtkWidget *input1,*input2,*input3,*input4,*sexe,*jour,*mois,*annee,*input5,*input6,*input7,*output,*output1;

window5zahra=lookup_widget(objet_graphique,"window5zahra");
char id [30];

input1=lookup_widget(objet_graphique,"nidzahra");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"nmot_de_passezahra");
input3=lookup_widget(objet_graphique,"nnomzahra");
input4=lookup_widget(objet_graphique,"nprenomzahra");

sexe=lookup_widget(objet_graphique,"nsexezahra");
jour=lookup_widget(objet_graphique,"njourzahra");
mois=lookup_widget(objet_graphique,"nmoiszahra");
annee=lookup_widget(objet_graphique,"nanneezahra");

input5=lookup_widget(objet_graphique,"ntelzahra");
input6=lookup_widget(objet_graphique,"nemailzahra");
input7=lookup_widget(objet_graphique,"nadressezahra");

if(strcmp(id,gtk_entry_get_text(GTK_ENTRY(input1)))!=0)
{
output1=lookup_widget(objet_graphique,"label47zahra");
gtk_label_set_text(GTK_LABEL(output1),"a ne pas modifier!!"); 
}
else{
strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(p.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));

p.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
p.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
p.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

modifier_personne (p);
output=lookup_widget(objet_graphique,"label45zahra");
gtk_label_set_text(GTK_LABEL(output),"modification enregistré avec succes!!");}
}




void
on_hotelagent_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*window1;
menuagent=lookup_widget(objet_graphique,"menuagent");
gtk_widget_destroy(menuagent);

window1=create_window1();
gtk_widget_show(window1);
}


void
on_retourhotelamir_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*window1;
window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);

menuagent=create_menuagent();
gtk_widget_show(menuagent);
}


void
on_volhome_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *AGwindowCatalogue,*treeview1;

AGwindowCatalogue=create_AGwindowCatalogue();
gtk_widget_show(AGwindowCatalogue);

treeview1=lookup_widget(AGwindowCatalogue,"AGtreeview2");

AGafficher_vol(treeview1);

}


void
on_hotelhome_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel,*cataloguehotel;
GtkWidget *treeviewamircatalogue;
//cataloguehotel=lookup_widget(objet_graphique,"cataloguehotel");
cataloguehotel=create_cataloguehotel();
gtk_widget_show(cataloguehotel);


treeviewamircatalogue=lookup_widget(cataloguehotel,"treeviewamircatalogue");

afficher_hotel(treeviewamircatalogue);
}


void
on_clientagent_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*clientadmin;
GtkWidget *treeview2;

menuagent=lookup_widget(objet_graphique,"menuagent");

//gtk_widget_destroy(menuagent);
//clientadmin=lookup_widget(objet_graphique,"clientadmin");
clientadmin=create_clientadmin();

gtk_widget_show(clientadmin);

treeview2=lookup_widget(clientadmin,"treeview2");

afficher_personne(treeview2);
}


void
on_voitureagent_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*gestion_voiture;
menuagent=lookup_widget(objet_graphique,"menuagent");
gtk_widget_destroy(menuagent);

gestion_voiture=create_gestion_voiture();
gtk_widget_show(gestion_voiture);
}


void
on_retourkhalil1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*gestion_voiture;
gestion_voiture=lookup_widget(objet_graphique,"gestion_voiture");
gtk_widget_destroy(gestion_voiture);

menuagent=create_menuagent();
gtk_widget_show(menuagent);
}


void
on_voiturehome_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *skytravel;

GtkWidget *liste_voitureclient;
GtkWidget *treeviewvoitureclient;

skytravel=lookup_widget(objet_graphique,"skytravel");


liste_voitureclient=lookup_widget(objet_graphique,"liste_voitureclient");
liste_voitureclient = create_liste_voitureclient();
gtk_widget_show(liste_voitureclient);
treeviewvoitureclient=lookup_widget(liste_voitureclient,"treeviewvoitureclient");
afficher_voitureclient(treeviewvoitureclient);

}

//***********************************anis nouv**********************************************



void
on_creationanis__clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *Creer;
timeanis();
Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
Creer=lookup_widget(objet,"Creer");
Creer=create_Creer();
gtk_widget_show(Creer);
}


void
on_buttonanis2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *consulter;
GtkWidget *treeviewanis1;

Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
consulter=lookup_widget(objet,"consulter");
consulter=create_consulter();

gtk_widget_show(consulter);
treeviewanis1=lookup_widget(consulter,"treeviewanis1");
afficher_repense(treeviewanis1);
}


void
on_buttonanis3_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reservations, *Reclamation_client,*input,*output;
char id[50];
Reclamation_client=lookup_widget(objet,"Reclamation_client");
input=lookup_widget(objet,"label112");
strcpy(id,gtk_label_get_text(GTK_LABEL(input))); 
gtk_widget_destroy(Reclamation_client);
reservations=create_reservations();
gtk_widget_show(reservations);
output=lookup_widget(reservations,"label67malek");
gtk_label_set_text(GTK_LABEL(output),id);

}


void
on_buttonanis4_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client, *Creer;
Creer=lookup_widget(objet,"Creer");
gtk_widget_destroy(Creer);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}


void
on_buttonanis5_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *comboboxanis1;
GtkWidget *input2,*input3,*input4;
GtkWidget *Creer;
GtkWidget *output;
reclamation c ;
GtkWidget *output1,*output2,*output3;
char vide[]="\0"; 
char type[100];
char rec[100];
char date[100];
char id[100];

Creer=lookup_widget(objet,"Creer");
output1=lookup_widget(objet,"labelanis24");
output2=lookup_widget(objet,"labelanis25");
output3=lookup_widget(objet,"labelanis26");

comboboxanis1=lookup_widget(objet,"comboboxanis1");
input4=lookup_widget(objet,"entryanis3");
input2=lookup_widget(objet,"entryanis1");
input3=lookup_widget(objet,"entryanis2");
output=lookup_widget(objet,"labelanis15");
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxanis1)));
strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input4)));

if(strcmp(c.id,vide)==0)
{
gtk_label_set_text(GTK_LABEL(output1),"Ce champ est obligatoire");
}
else if(strcmp(c.date,vide)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"Ce champs est obligatoire");
}
else if(strcmp(c.rec,vide)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"Veuillez saisir votre réclamation");
}
else
{int mois,annee,jour,datesys,jr,mo,an,anx,mox,dateuser,moisx,anneex;
FILE *f1;
FILE *f2;
f1=fopen("/home/malekbouslah/Desktop/final/src/datesys.txt","r");
fscanf(f1,"%d;%d;%d",&jour,&mois,&annee);
anneex=annee*365;
moisx=mois*30;
datesys=anneex+moisx+jour;
fclose(f1);
sscanf(c.date,"%d/%d/%d",&jr,&mo,&an);
anx=an*365;
mox=mo*30;
dateuser=anx+mox+jr;
if ((datesys-dateuser)<30)
{
gtk_label_set_text(GTK_LABEL(output),"Reclamation est envoyée"); 
ajouter_reclamation(c);
}
else 
{
gtk_label_set_text(GTK_LABEL(output),"Reclamation a dépassé 30jours"); 
}
}
}


void
on_buttonanis8_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input4,*input2,*input3,*comboboxanis1;
GtkWidget *output;
GtkWidget *Creer ;
char id[100];
char type[100];
char rec[100];
char date[100];
reclamation c;

Creer=lookup_widget(objet,"Creer");
input4=lookup_widget(objet,"entryanis3");
comboboxanis1=lookup_widget(objet,"comboboxanis1");
input2=lookup_widget(objet,"entryanis1");
input3=lookup_widget(objet,"entryanis2");


strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxanis1)));
strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input4)));
supprimer_reclamation(id);
ajouter_reclamation(c);
output=lookup_widget(objet,"labelanis15");
gtk_label_set_text(GTK_LABEL(output),"Reclamation est modifieé");
}


void
on_buttonanis7_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client, *consulter;


consulter=lookup_widget(objet,"consulter");
gtk_widget_destroy(consulter);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}


void
on_buttonanis10_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menuagent, *employe;

employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
menuagent=create_menuagent();
gtk_widget_show(menuagent);
}


void
on_buttonanis13_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[30];
char reclamation1[100];


 GtkWidget *input5;

 GtkWidget *employe;
 GtkWidget *output;

employe=lookup_widget(objet,"employe");
input5=lookup_widget(objet,"entryanis5");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));

output=lookup_widget(objet,"labelanis27");
reclamation c  ;
    FILE *f;
    
    f=fopen("/home/malekbouslah/Desktop/final/src/utilisateur.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s ",c.id,c.type,c.date,c.rec)!=EOF)
        {
            
            if (strcmp(c.id,id)==0)
            {
                strcpy(reclamation1,c.rec);
		gtk_label_set_text(GTK_LABEL(output),reclamation1);
            }
        }
    }

}


void
on_buttonanis9_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
reclamation c ;
	GtkWidget *input5 ;
	GtkWidget *window1;
	GtkWidget *output3;
	GtkWidget *employe;
	GtkWidget *treeview2;	
    char id[50];
  window1=lookup_widget(objet,"window1");
  input5=lookup_widget(objet,"entryanis5");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
supprimer_reclamation(id);
output3=lookup_widget(objet,"labelanis23");
gtk_label_set_text(GTK_LABEL(output3),"Reclamation est supprimée");
}


void
on_buttonanis12_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input5,*input4;
GtkWidget *window1;
GtkWidget *output1;

char id[100];
char rep[100];

window1=lookup_widget(objet,"window1");

input5=lookup_widget(objet,"entryanis5");
input4=lookup_widget(objet,"entryanis4");
output1=lookup_widget(objet,"labelanis22");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rep,gtk_entry_get_text(GTK_ENTRY(input4)));


ajouter_repense(id,rep);

gtk_label_set_text(GTK_LABEL(output1),"La reponse de reclamation est envoyée");
}


void
on_buttonanis14_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewanis2, *employe;
employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
employe=create_employe();
gtk_widget_show(employe);	
treeviewanis2=lookup_widget(employe,"treeviewanis2");
afficher_reclamation(treeviewanis2);
}


void
on_reclamationagent_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menuagent;
GtkWidget *employe;
GtkWidget *treeviewanis2;

menuagent=lookup_widget(objet,"menuagent");

gtk_widget_destroy(menuagent);
employe=lookup_widget(objet,"employe");
employe=create_employe();

gtk_widget_show(employe);

treeviewanis2=lookup_widget(employe,"treeviewanis2");
afficher_reclamation(treeviewanis2);
}


void
on_anismalek_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations,*Reclamation_client,*input,*output;
char id[50];
reservations=lookup_widget(objet_graphique,"reservations");
input=lookup_widget(objet_graphique,"label67malek");
strcpy(id,gtk_label_get_text(GTK_LABEL(input))); 
reservations=lookup_widget(objet_graphique,"reservations");
gtk_widget_destroy(reservations);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);

output=lookup_widget(Reclamation_client,"label112");
gtk_label_set_text(GTK_LABEL(output),id);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////:



void
on_volagent_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*AGwindowAffichage,*treeview1;

menuagent=lookup_widget(objet_graphique,"menuagent");
gtk_widget_destroy(menuagent);

AGwindowAffichage=create_AGwindowAffichage();
gtk_widget_show(AGwindowAffichage);

treeview1=lookup_widget(AGwindowAffichage,"AGtreeview1");

AGafficher_vol(treeview1);
}


void
on_retouragentvol_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*AGwindowAffichage;

AGwindowAffichage=lookup_widget(objet_graphique,"AGwindowAffichage");
gtk_widget_destroy(AGwindowAffichage);

menuagent=create_menuagent();
gtk_widget_show(menuagent);
}


void
on_fermerres_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservationagent;
reservationagent=lookup_widget(objet_graphique,"reservationagent");
gtk_widget_destroy(reservationagent);
}


void
on_gestionreservationadmin_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuadmin,*reservationagent,*treeview3;

menuadmin=lookup_widget(objet_graphique,"menuadmin");
//gtk_widget_destroy(menuadmin);

reservationagent=create_reservationagent();
gtk_widget_show(reservationagent);

treeview3=lookup_widget(reservationagent,"treeview3");

afficher_resagent(treeview3);
}


void
on_affreservationagent_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*reservationagent,*treeview3;

menuagent=lookup_widget(objet_graphique,"menuagent");
//gtk_widget_destroy(menuagent);

reservationagent=create_reservationagent();
gtk_widget_show(reservationagent);

treeview3=lookup_widget(reservationagent,"treeview3");

afficher_resagent(treeview3);
}


void
on_brodymalek_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations,*gestionfacture;

reservations=lookup_widget(objet_graphique,"reservations");
gestionfacture=create_gestionfacture();
gtk_widget_show(gestionfacture);
}


void
on_payerfacturemalek_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage,*input,*input1;

reservation r;
char idclient[30],idfacture[30],nom[30],prenom[30],service[30]="vol",prix[30];
int jour,mois,annee;
char identifiant1[50],mot_de_passe1[50],nom1[50],prenom1[50],sexe1[50],jour1[50],mois1[50],annee1[50],tel1[50],email1[50],adresse1[50];

affichage=lookup_widget(objet_graphique,"affichage");

input1=lookup_widget(objet_graphique,"label68malek");

strcpy(idclient,gtk_label_get_text(GTK_LABEL(input1)));


input=lookup_widget(objet_graphique,"entry8malek");
strcpy(idfacture,gtk_entry_get_text(GTK_ENTRY(input)));
FILE *f=fopen("/home/malekbouslah/Desktop/final/src/reservation.txt","r");
if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %f  \n",r.num_res,r.identifiant,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
        {
            
          
		if(strcmp(idclient,r.identifiant)==0 && strcmp(idfacture,r.num_res)==0)
		{
			jour=atoi(r.date_reservation.jour);
			mois=atoi(r.date_reservation.mois);
			annee=atoi(r.date_reservation.annee);
			sprintf(prix,"%f",r.devis);
			fclose(f);
					
		}
                
            
        }
	fclose(f);
	
    }

FILE *f1=fopen("/home/malekbouslah/Desktop/final/src/client.txt","r");
if(f1!=NULL)
	{
		while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s\n",identifiant1,mot_de_passe1,nom1,prenom1,sexe1,jour1,mois1,annee1,tel1,email1,adresse1)!=EOF)
		{
			if(strcmp(idclient,identifiant1)==0)
			{
			strcpy(nom,nom1);
			strcpy(prenom,prenom1);
			}
		}

	}
ajouterbrody(idclient,idfacture,jour,mois,annee,nom,prenom,service,prix);
}


void
on_gestionfactureadmin_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuadmin,*gestionfacture;

menuadmin=lookup_widget(objet_graphique,"menuadmin");
gestionfacture=create_gestionfacture();
gtk_widget_show(gestionfacture);
}


void
on_factureagent_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuagent,*gestionfacture;

menuagent=lookup_widget(objet_graphique,"menuagent");
gestionfacture=create_gestionfacture();
gtk_widget_show(gestionfacture);
}

