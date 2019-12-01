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
#include <string.h>


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *affichage;
GtkWidget *treeview1;

reservations=lookup_widget(objet_graphique,"reservations");

gtk_widget_destroy(reservations);
affichage=lookup_widget(objet_graphique,"affichage");
affichage=create_affichage();

gtk_widget_show(affichage);

treeview1=lookup_widget(affichage,"treeview1");
afficher_res(treeview1);
}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *reservations;
GtkWidget *vol;
GtkWidget *combobox10;
GtkWidget *input1;
char pres[50];

combobox10=lookup_widget(objet_graphique,"combobox10");
strcpy(pres,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)));
if (strcmp(pres,"vol")==0)
{
reservations=lookup_widget(objet_graphique,"reservations");
gtk_widget_destroy(reservations);
vol=lookup_widget(objet_graphique,"vol");
vol=create_vol();

gtk_widget_show(vol);
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
int test,i,n;
char aller[100];
char retour[100];
char compagnie[50][50];
//char date_dispo[50][50];
GtkWidget *vol;
GtkWidget *input1;
GtkWidget *input2;
/*GtkWidget *combobox4;
GtkWidget *combobox3;*/
GtkWidget *combobox7;
//GtkWidget *combobox9;
GtkWidget *output3;



input1=lookup_widget(objet_graphique,"entry5");
input2=lookup_widget(objet_graphique,"entry7");
output3=lookup_widget(objet_graphique,"label28");
/*combobox4=lookup_widget(objet_graphique,"combobox4");
combobox3=lookup_widget(objet_graphique,"combobox3");*/
combobox7=lookup_widget(objet_graphique,"combobox7");
//combobox9=lookup_widget(objet_graphique,"combobox9");
strcpy(aller,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(retour,gtk_entry_get_text(GTK_ENTRY(input2)));
test=cherchervol(aller,retour);
if(test==0)
{
gtk_label_set_text(GTK_LABEL(output3),"ville de départ ou d'arriver indisponnible pour le moment, voir catalogue!! ");
}
if(test==1)
{
gtk_label_set_text(GTK_LABEL(output3)," choisir la compagnie ");
n=tableau_compagnie_disponible(compagnie,aller,retour);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox7),_(compagnie[i]));
//gtk_combo_box_append_text(GTK_COMBO_BOX(combobox9),_(date_dispo[i]));
}
}
}


