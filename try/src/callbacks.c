#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"

void
on_AGAjouter_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
VOL vol;

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

VOL vol;

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
f=fopen("/home/macbookair/Projects/try/src/catalogue_vol.txt","r"); 
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

VOL vol;

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

