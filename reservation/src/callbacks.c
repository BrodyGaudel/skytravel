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
//#include "client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *affichage;
GtkWidget *treeview1;
GtkWidget *input;
GtkWidget *output;
char id[50];

affichage=lookup_widget(objet_graphique,"affichage");
input=lookup_widget(objet_graphique,"label67");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));


reservations=lookup_widget(objet_graphique,"reservations");
gtk_widget_hide(reservations);

affichage=create_affichage();

gtk_widget_show(affichage);
output=lookup_widget(affichage,"label68");
gtk_label_set_text(GTK_LABEL(output),id);

treeview1=lookup_widget(affichage,"treeview1");
afficher_res(treeview1,id);

}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
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
input1=lookup_widget(objet_graphique,"label68");

strcpy(id,gtk_label_get_text(GTK_LABEL(input1)));

input=lookup_widget(objet_graphique,"entry8");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
suppres(num);


gtk_widget_destroy(affichage);
affichage=lookup_widget(objet_graphique,"affichage");
affichage=create_affichage();

gtk_widget_show(affichage);

output=lookup_widget(affichage,"label68");
gtk_label_set_text(GTK_LABEL(output),id);
treeview1=lookup_widget(affichage,"treeview1");
afficher_res(treeview1,id);
}

void
on_button2_clicked                     (GtkWidget       *objet_graphique,
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
input=lookup_widget(objet_graphique,"label67");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));

combobox10=lookup_widget(objet_graphique,"combobox10");
strcpy(pres,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)));
output1=lookup_widget(objet_graphique,"label3");

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
output=lookup_widget(vol,"label70");
gtk_label_set_text(GTK_LABEL(output),id);
}
}

void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *affichage;
 GtkWidget *reservations;

 affichage=lookup_widget(objet_graphique,"affichage");
 reservations=create_reservations();

 gtk_widget_show(reservations);
 gtk_widget_destroy(affichage);
}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
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



input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");
output3=lookup_widget(objet_graphique,"label28");
combobox7=lookup_widget(objet_graphique,"combobox7");
combobox9=lookup_widget(objet_graphique,"combobox9");
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
}/*
combobox7=lookup_widget(objet_graphique,"combobox7");
strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
m=tableau_date_disponible(date,aller,retour,comp);
for(j=0;j<m;j++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox9),_(date[j]));
}*/
}
}



void
on_valider_clicked                     (GtkWidget       *objet_graphique,
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




input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");

combobox7=lookup_widget(objet_graphique,"combobox7");
combobox9=lookup_widget(objet_graphique,"combobox9");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));

test=cherchervol(aller,retour);

if(test==1)
{

//combobox7=lookup_widget(objet_graphique,"combobox7");
strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
m=tableau_date_disponible(date_aller,aller,retour,comp);
for(j=0;j<m;j++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox9),_(date_aller[j]));
}
}
}


void
on_valider_date_clicked                (GtkWidget       *objet_graphique,
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



input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");
combobox7=lookup_widget(objet_graphique,"combobox7");
combobox9=lookup_widget(objet_graphique,"combobox9");
combobox11=lookup_widget(objet_graphique,"combobox11");
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
on_retour_vol_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *vol;
 GtkWidget *reservations;

 vol=lookup_widget(objet_graphique,"vol");
 reservations=create_reservations();

 gtk_widget_show(reservations);
 gtk_widget_destroy(vol);
}


void
on_devis_vol_clicked                   (GtkWidget       *objet_graphique,
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


input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");
output2=lookup_widget(objet_graphique,"label65");

combobox7=lookup_widget(objet_graphique,"combobox7");
combobox9=lookup_widget(objet_graphique,"combobox9");
combobox11=lookup_widget(objet_graphique,"combobox11");

spinbuttonadulte=lookup_widget(objet_graphique,"spinbuttonadulte");
spinbuttonenfant=lookup_widget(objet_graphique,"spinbuttonenfant");
spinbuttonbebe=lookup_widget(objet_graphique,"spinbuttonbebe");

chec1=lookup_widget(objet_graphique,"economique");
chec2=lookup_widget(objet_graphique,"business");
chec3=lookup_widget(objet_graphique,"first");


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
output1=lookup_widget(objet_graphique,"label62");
gtk_label_set_text(GTK_LABEL(output1),ch);
}
}



void
on_reessayervol_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
GtkWidget *input;
GtkWidget *output;
char id[50];

input=lookup_widget(objet_graphique,"label70");
strcpy(id,gtk_label_get_text(GTK_LABEL(input)));
vol=lookup_widget(objet_graphique,"vol");
gtk_widget_hide(vol);

vol=create_vol();
gtk_widget_show(vol);
output=lookup_widget(vol,"label70");
gtk_label_set_text(GTK_LABEL(output),id);

}


void
on_enregistrementvol_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol;
GtkWidget *input;
GtkWidget *output2;

vol=lookup_widget(objet_graphique,"vol");
input=lookup_widget(objet_graphique,"label62");
output2=lookup_widget(objet_graphique,"label70");

char prix[50];
float total;
char id[50];

reservation r;
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");
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

enregistrer_vol(num_vol,id,j,m,ann,total);



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



input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");
output=lookup_widget(objet_graphique,"label65");

chec1=lookup_widget(objet_graphique,"economique");
chec2=lookup_widget(objet_graphique,"business");
chec3=lookup_widget(objet_graphique,"first");


combobox7=lookup_widget(objet_graphique,"combobox7");
combobox9=lookup_widget(objet_graphique,"combobox9");
combobox11=lookup_widget(objet_graphique,"combobox11");

spinbuttonadulte=lookup_widget(objet_graphique,"spinbuttonadulte");
spinbuttonenfant=lookup_widget(objet_graphique,"spinbuttonenfant");
spinbuttonbebe=lookup_widget(objet_graphique,"spinbuttonbebe");
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



FILE *f1;
f1=fopen("/home/malekbouslah/Projects/reservation/src/volreserver.txt", "a+");
		if (f1==NULL)
		{
		return;
		}

	fprintf(f1,"%s %s %s %s %s %s %s %s %d %f\n",num_vol,id,aller,retour,comp,da,dr,classe,nbr_voy,total );

	 fclose(f1);
gtk_label_set_text(GTK_LABEL(output),"vol enregistré avec succès!!");
numvol=numero_vol(aller,retour,comp,da,dr,classe);
modifier_nb_place(numvol,nbr_voy);
}




void
on_modifiervol_clicked                 (GtkWidget       *objet_graphique,
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
input1=lookup_widget(objet_graphique,"label68");

strcpy(id,gtk_label_get_text(GTK_LABEL(input1)));

input=lookup_widget(objet_graphique,"entry8");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
gtk_widget_hide(affichage);
modificationvol=create_modificationvol();
gtk_widget_show(modificationvol);
output=lookup_widget(modificationvol,"label73");
gtk_label_set_text(GTK_LABEL(output),id);
output1=lookup_widget(modificationvol,"entry9");
gtk_entry_set_text(GTK_ENTRY(output1),num);

output2=lookup_widget(modificationvol,"entry10");
output3=lookup_widget(modificationvol,"entry11");
output4=lookup_widget(modificationvol,"entry12");
output5=lookup_widget(modificationvol,"entry13");
output6=lookup_widget(modificationvol,"entry14");

FILE *f1=fopen("/home/malekbouslah/Projects/reservation/src/volreserver.txt","r");
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
on_retourmodif_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *modificationvol;
 GtkWidget *affichage;
 GtkWidget *treeview1;

 GtkWidget *input;
 GtkWidget *output;
 char id[50];

 
 modificationvol=lookup_widget(objet_graphique,"modificationvol");
 input=lookup_widget(objet_graphique,"label73");
 strcpy(id,gtk_label_get_text(GTK_LABEL(input)));
 
 gtk_widget_destroy(modificationvol);
 affichage=create_affichage();

 gtk_widget_show(affichage);
 output=lookup_widget(affichage,"label68");
 gtk_label_set_text(GTK_LABEL(output),id);
 treeview1=lookup_widget(affichage,"treeview1");
 afficher_res(treeview1,id);

 
}


void
on_enregistrermodif_clicked            (GtkWidget       *objet_graphique,
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
char ch[100];
char classe[50];
char id[50];


input1=lookup_widget(objet_graphique,"entry9");
input2=lookup_widget(objet_graphique,"entry10");
input3=lookup_widget(objet_graphique,"entry11");
input4=lookup_widget(objet_graphique,"entry12");
input5=lookup_widget(objet_graphique,"entry13");
input6=lookup_widget(objet_graphique,"entry14");
output1=lookup_widget(objet_graphique,"label85");
output2=lookup_widget(objet_graphique,"label84");

chec1=lookup_widget(objet_graphique,"checkbuttoneconomique");
chec2=lookup_widget(objet_graphique,"checkbuttonbusiness");
chec3=lookup_widget(objet_graphique,"checkbuttonfirst");

spinbutton1adulte=lookup_widget(objet_graphique,"spinbutton1adulte");
spinbutton2enfant=lookup_widget(objet_graphique,"spinbutton2enfant");
spinbutton3bebe=lookup_widget(objet_graphique,"spinbutton3bebe");

strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(da,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(dr,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(objet_graphique,"label73");
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

suppres(num);
reservation r;
FILE *f=fopen("/home/malekbouslah/Projects/reservation/src/reservation.txt","r");
int nume=1;int numvol;
char num_vol[50];char j[50];char m[50];char ann[50];

strcpy(prix,gtk_label_get_text(GTK_LABEL(output2)));
total=atof(prix);
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %f  \n",r.num_res,r.identifiant,r.date_reservation.jour,r.date_reservation.mois,r.date_reservation.annee,r.type,&r.devis)!=EOF)
{
nume=atof(r.num_res)+1;
sprintf(num_vol,"%d",nume);
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

enregistrer_vol(num_vol,id,j,m,ann,total);

nbr_voy=a+e+b;

FILE *f1;
f1=fopen("/home/malekbouslah/Projects/reservation/src/volreserver.txt", "a+");
		if (f1==NULL)
		{
		return;
		}

	fprintf(f1,"%s %s %s %s %s %s %s %s %d %f\n",num_vol,id,aller,retour,comp,da,dr,classe,nbr_voy,total );

	 fclose(f1);
gtk_label_set_text(GTK_LABEL(output1),"modification enregistré avec succès!!");
numvol=numero_vol(aller,retour,comp,da,dr,classe);
modifier_nb_place(numvol,nbr_voy);

}


void
on_devismodif_clicked                  (GtkWidget       *objet_graphique,
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


input1=lookup_widget(objet_graphique,"entry9");
input2=lookup_widget(objet_graphique,"entry10");
input3=lookup_widget(objet_graphique,"entry11");
input4=lookup_widget(objet_graphique,"entry12");
input5=lookup_widget(objet_graphique,"entry13");
input6=lookup_widget(objet_graphique,"entry14");

chec1=lookup_widget(objet_graphique,"checkbuttoneconomique");
chec2=lookup_widget(objet_graphique,"checkbuttonbusiness");
chec3=lookup_widget(objet_graphique,"checkbuttonfirst");

spinbutton1adulte=lookup_widget(objet_graphique,"spinbutton1adulte");
spinbutton2enfant=lookup_widget(objet_graphique,"spinbutton2enfant");
spinbutton3bebe=lookup_widget(objet_graphique,"spinbutton3bebe");

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
output1=lookup_widget(objet_graphique,"label84");
gtk_label_set_text(GTK_LABEL(output1),ch);


}

