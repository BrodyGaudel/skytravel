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
on_Ajouter_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
VOL vol;

char *a[30];
float n;

GtkWidget *Num_vol,*Compagnie_aerienne,*Depart,*Destination,*Date_depart,*Date_retour,*Classe,*Tarif,*Nbr_max,*Confirmation;
GtkWidget *windowAjout;

windowAjout=lookup_widget(objet,"windowAjout");

Num_vol=lookup_widget(objet,"num_vol");
Compagnie_aerienne=lookup_widget(objet,"compagnie_aerienne");
Depart=lookup_widget(objet,"depart");
Destination=lookup_widget(objet,"destination");
Date_depart=lookup_widget(objet,"date_depart");
Date_retour=lookup_widget(objet,"date_retour");
Classe=lookup_widget(objet,"classe");
Tarif=lookup_widget(objet,"tarif");
Nbr_max=lookup_widget(objet,"nbr_max");
Confirmation=lookup_widget(objet,"labelConfirmation");

vol.num_vol=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));
strcpy(vol.compagnie_aerienne,gtk_entry_get_text(GTK_ENTRY(Compagnie_aerienne)));
strcpy(vol.depart,gtk_entry_get_text(GTK_ENTRY(Depart)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(Destination)));
strcpy(vol.date_depart,gtk_entry_get_text(GTK_ENTRY(Date_depart)));
strcpy(vol.date_retour,gtk_entry_get_text(GTK_ENTRY(Date_retour)));
strcpy(vol.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
n=strtof(gtk_entry_get_text(GTK_ENTRY(Tarif)),&a);
vol.tarif=n;
vol.nbr_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Nbr_max));

ajouter_vol(vol);

gtk_label_set_text(GTK_LABEL(Confirmation),"Vol ajoutee");
}


void
on_Afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowAffichage;
GtkWidget *treeview1;

windowAjout=lookup_widget(objet,"windowAjout");

gtk_widget_destroy(windowAjout);
windowAffichage=lookup_widget(objet,"windowAffichage");
windowAffichage=create_windowAffichage();

gtk_widget_show(windowAffichage);

treeview1=lookup_widget(windowAffichage,"treeview1");

afficher_vol(treeview1);
}


void
on_Retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAjout, *windowAffichage;

windowAffichage = lookup_widget(objet,"windowAffichage");

gtk_widget_destroy(windowAffichage);
windowAjout = create_windowAjout();
gtk_widget_show(windowAjout);
}


void
on_recherche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Num_vol,*Compagnie_aerienne,*Depart,*Destination,*Date_depart,*Date_retour,*Classe,*Tarif,*Nbr_max,*Confirmation;

VOL vol;

int num_volR;

char c1[30],c2[30];

Num_vol=lookup_widget(objet,"num_volM");
Compagnie_aerienne=lookup_widget(objet,"compagnie_aerienneM");
Depart=lookup_widget(objet,"departM");
Destination=lookup_widget(objet,"destinationM");
Date_depart=lookup_widget(objet,"date_departM");
Date_retour=lookup_widget(objet,"date_retourM");
Classe=lookup_widget(objet,"classeM");
Tarif=lookup_widget(objet,"tarifM");
Nbr_max=lookup_widget(objet,"nbr_maxM");

num_volR=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_vol));

FILE *f;
f=fopen("/home/macbookair/Desktop/try1/src/ListeVol.txt","r"); 
if (f!=NULL)
{
	while (fscanf(f, " %d %s %s %s %s %s %s %f 	%d" ,&vol.num_vol,vol.compagnie_aerienne,vol.depart,vol.destination,vol.date_depart,vol.date_retour,vol.classe,&vol.tarif,&vol.nbr_max)!=EOF)
	{
		if (num_volR==vol.num_vol)
		{   
			gtk_entry_set_text (GTK_ENTRY (Compagnie_aerienne),vol.compagnie_aerienne);
			gtk_entry_set_text (GTK_ENTRY (Depart), vol.depart);
			gtk_entry_set_text (GTK_ENTRY (Destination), vol.destination);
			gtk_entry_set_text (GTK_ENTRY (Date_depart), vol.date_depart);
			gtk_entry_set_text (GTK_ENTRY (Date_retour), vol.date_retour);
			gtk_entry_set_text (GTK_ENTRY (Classe), vol.classe);
			gcvt(vol.tarif,6,c1);
			gtk_entry_set_text (GTK_ENTRY (Tarif), c1);
			sprintf(c2,"%d",vol.nbr_max);
			gtk_entry_set_text (GTK_ENTRY (Nbr_max), c2);
		}
	}
fclose(f);
}
}


void
on_valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Num_volM,*Compagnie_aerienne,*Depart,*Destination,*Date_depart,*Date_retour,*Classe,*Tarif,*Nbr_max,*Confirmation,*output;

VOL vol;

char *a[30];
float n;

Num_volM=lookup_widget(objet,"num_volM");
Compagnie_aerienne=lookup_widget(objet,"compagnie_aerienneM");
Depart=lookup_widget(objet,"departM");
Destination=lookup_widget(objet,"destinationM");
Date_depart=lookup_widget(objet,"date_departM");
Date_retour=lookup_widget(objet,"date_retourM");
Classe=lookup_widget(objet,"classeM");
Tarif=lookup_widget(objet,"tarifM");
Nbr_max=lookup_widget(objet,"nbr_maxM");
output=lookup_widget(objet,"labelConfirmationM");

vol.num_vol=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Num_volM));
strcpy(vol.compagnie_aerienne,gtk_entry_get_text(GTK_ENTRY(Compagnie_aerienne)));
strcpy(vol.depart,gtk_entry_get_text(GTK_ENTRY(Depart)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(Destination)));
strcpy(vol.date_depart,gtk_entry_get_text(GTK_ENTRY(Date_depart)));
strcpy(vol.date_retour,gtk_entry_get_text(GTK_ENTRY(Date_retour)));
strcpy(vol.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
n=strtof(gtk_entry_get_text(GTK_ENTRY(Tarif)),&a);
vol.tarif=n;
vol.nbr_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Nbr_max));

modifier_vol(vol,Num_volM);


gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;
}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowModifier,*windowAffichage;
windowModifier=create_windowModifier ();
windowAffichage=lookup_widget(objet,"windowAffichage");
gtk_widget_show(windowModifier);
gtk_widget_hide(windowAffichage);
}


void
on_RetourM_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowAffichage;
GtkWidget *treeview1;

windowModifier=lookup_widget(objet,"windowModifier");

gtk_widget_destroy(windowModifier);
windowAffichage=lookup_widget(objet,"windowAffichage");
windowAffichage=create_windowAffichage();

gtk_widget_show(windowAffichage);

treeview1=lookup_widget(windowAffichage,"treeview1");

afficher_vol(treeview1);
}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget* num_volS;
GtkWidget *windowAffichage;
GtkWidget *treeview1;
GtkWidget *output,*input;

input=lookup_widget(objet,"spinButtonSupprimer");
output=lookup_widget(objet,"labelConfirmationS");

num_volS=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

supprimer_vol(num_volS);

windowAffichage=lookup_widget(objet,"windowAffichage");

gtk_widget_destroy(windowAffichage);
windowAffichage=lookup_widget(objet,"windowAffichage");
windowAffichage=create_windowAffichage();

gtk_widget_show(windowAffichage);

treeview1=lookup_widget(windowAffichage,"treeview1");

afficher_vol(treeview1);

gtk_label_set_text(GTK_LABEL(output),"supprime avec succés") ;
}

