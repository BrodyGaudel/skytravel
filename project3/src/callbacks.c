#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


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
GtkWidget *treeview1brody;

void
on_modifierbrody_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestionfacture;
GtkWidget *idfacture;
GtkWidget *idclient;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *anneeb;
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
on_supprimerbrody_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{*idfacture;
char ch[30];
idfacture=lookup_widget(objet_graphique,"entry1brody");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(idfacture)));
supprimerbrody(ch);
}
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
on_afficherbrody_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1brody=lookup_widget(objet_graphique,"treeview1brody");
afficherbrody(treeview1brody);
}
