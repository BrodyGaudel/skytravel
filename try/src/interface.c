/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_AGwindowAffichage (void)
{
  GtkWidget *AGwindowAffichage;
  GtkWidget *AGfixed1;
  GtkWidget *AGtreeview1;
  GtkObject *AGspinButtonSupprimer_adj;
  GtkWidget *AGspinButtonSupprimer;
  GtkWidget *AGimageAffichage;
  GtkWidget *AGmodifier;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label2;
  GtkWidget *AGlabelListe;
  GtkWidget *AGsupprimer;
  GtkWidget *AGalignment4;
  GtkWidget *AGhbox4;
  GtkWidget *AGimage4;
  GtkWidget *AGlabel4;
  GtkWidget *AGlabelConfirmationS;
  GtkWidget *AGRetour;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label3;

  AGwindowAffichage = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (AGwindowAffichage), _("windowAffichage"));

  AGfixed1 = gtk_fixed_new ();
  gtk_widget_show (AGfixed1);
  gtk_container_add (GTK_CONTAINER (AGwindowAffichage), AGfixed1);

  AGtreeview1 = gtk_tree_view_new ();
  gtk_widget_show (AGtreeview1);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGtreeview1, 8, 136);
  gtk_widget_set_size_request (AGtreeview1, 1112, 224);

  AGspinButtonSupprimer_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  AGspinButtonSupprimer = gtk_spin_button_new (GTK_ADJUSTMENT (AGspinButtonSupprimer_adj), 1, 0);
  gtk_widget_show (AGspinButtonSupprimer);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGspinButtonSupprimer, 896, 80);
  gtk_widget_set_size_request (AGspinButtonSupprimer, 100, 50);

  AGimageAffichage = create_pixmap (AGwindowAffichage, "interface-generale.png");
  gtk_widget_show (AGimageAffichage);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGimageAffichage, 0, 0);
  gtk_widget_set_size_request (AGimageAffichage, 1128, 464);

  AGmodifier = gtk_button_new ();
  gtk_widget_show (AGmodifier);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGmodifier, 24, 392);
  gtk_widget_set_size_request (AGmodifier, 100, 45);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (AGmodifier), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label2 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Modifier</b></span>"));
  gtk_widget_show (label2);
  gtk_box_pack_start (GTK_BOX (hbox2), label2, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label2), TRUE);

  AGlabelListe = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"dark blue\" size=\"large\"><b>Liste des Vols</b></span>"));
  gtk_widget_show (AGlabelListe);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGlabelListe, 480, 48);
  gtk_widget_set_size_request (AGlabelListe, 159, 35);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelListe), TRUE);

  AGsupprimer = gtk_button_new ();
  gtk_widget_show (AGsupprimer);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGsupprimer, 1008, 80);
  gtk_widget_set_size_request (AGsupprimer, 110, 50);

  AGalignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (AGalignment4);
  gtk_container_add (GTK_CONTAINER (AGsupprimer), AGalignment4);

  AGhbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (AGhbox4);
  gtk_container_add (GTK_CONTAINER (AGalignment4), AGhbox4);

  AGimage4 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (AGimage4);
  gtk_box_pack_start (GTK_BOX (AGhbox4), AGimage4, FALSE, FALSE, 0);

  AGlabel4 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Supprimer</b></span>"));
  gtk_widget_show (AGlabel4);
  gtk_box_pack_start (GTK_BOX (AGhbox4), AGlabel4, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (AGlabel4), TRUE);

  AGlabelConfirmationS = gtk_label_new ("");
  gtk_widget_show (AGlabelConfirmationS);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGlabelConfirmationS, 440, 392);
  gtk_widget_set_size_request (AGlabelConfirmationS, 300, 50);

  AGRetour = gtk_button_new ();
  gtk_widget_show (AGRetour);
  gtk_fixed_put (GTK_FIXED (AGfixed1), AGRetour, 992, 392);
  gtk_widget_set_size_request (AGRetour, 100, 45);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (AGRetour), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label3 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Ajouter</b></span>"));
  gtk_widget_show (label3);
  gtk_box_pack_start (GTK_BOX (hbox3), label3, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label3), TRUE);

  g_signal_connect ((gpointer) AGmodifier, "clicked",
                    G_CALLBACK (on_AGmodifier_clicked),
                    NULL);
  g_signal_connect ((gpointer) AGsupprimer, "clicked",
                    G_CALLBACK (on_AGsupprimer_clicked),
                    NULL);
  g_signal_connect ((gpointer) AGRetour, "clicked",
                    G_CALLBACK (on_AGRetour_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (AGwindowAffichage, AGwindowAffichage, "AGwindowAffichage");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGfixed1, "AGfixed1");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGtreeview1, "AGtreeview1");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGspinButtonSupprimer, "AGspinButtonSupprimer");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGimageAffichage, "AGimageAffichage");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGmodifier, "AGmodifier");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, image2, "image2");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, label2, "label2");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGlabelListe, "AGlabelListe");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGsupprimer, "AGsupprimer");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGalignment4, "AGalignment4");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGhbox4, "AGhbox4");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGimage4, "AGimage4");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGlabel4, "AGlabel4");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGlabelConfirmationS, "AGlabelConfirmationS");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, AGRetour, "AGRetour");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, image3, "image3");
  GLADE_HOOKUP_OBJECT (AGwindowAffichage, label3, "label3");

  return AGwindowAffichage;
}

GtkWidget*
create_AGwindowAjout (void)
{
  GtkWidget *AGwindowAjout;
  GtkWidget *AGfixed2;
  GtkWidget *AGcompagnie_aerienne;
  GtkWidget *AGdestination;
  GtkWidget *AGtarif;
  GtkObject *AGnbr_max_adj;
  GtkWidget *AGnbr_max;
  GtkWidget *AGdepart;
  GtkObject *AGnum_vol_adj;
  GtkWidget *AGnum_vol;
  GtkObject *AGdate_depart_jour_adj;
  GtkWidget *AGdate_depart_jour;
  GtkObject *AGdate_depart_mois_adj;
  GtkWidget *AGdate_depart_mois;
  GtkObject *AGdate_depart_annee_adj;
  GtkWidget *AGdate_depart_annee;
  GtkObject *AGdate_retour_jour_adj;
  GtkWidget *AGdate_retour_jour;
  GtkObject *AGdate_retour_mois_adj;
  GtkWidget *AGdate_retour_mois;
  GtkObject *AGdate_retour_annee_adj;
  GtkWidget *AGdate_retour_annee;
  GtkWidget *AGimageAjouter;
  GtkWidget *AGlabelAjout;
  GtkWidget *AGclasse;
  GtkWidget *AGAfficher;
  GtkWidget *AGalignment2;
  GtkWidget *AGhbox2;
  GtkWidget *AGimage2;
  GtkWidget *AGlabel2;
  GtkWidget *AGAjouter;
  GtkWidget *AGalignment1;
  GtkWidget *AGhbox1;
  GtkWidget *AGimage1;
  GtkWidget *AGlabel;
  GtkWidget *AGlabelConfirmation;
  GtkWidget *AGlabelNum;
  GtkWidget *AGlabelCompagnieAerienne;
  GtkWidget *AGlabelDepart;
  GtkWidget *AGlabelDestination;
  GtkWidget *AGlabelDateDepart;
  GtkWidget *AGlabelDateRetour;
  GtkWidget *AGlabelClasse;
  GtkWidget *AGlabelTarif;
  GtkWidget *AGlabelNbrMax;

  AGwindowAjout = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (AGwindowAjout), _("Ajouter vol"));

  AGfixed2 = gtk_fixed_new ();
  gtk_widget_show (AGfixed2);
  gtk_container_add (GTK_CONTAINER (AGwindowAjout), AGfixed2);

  AGcompagnie_aerienne = gtk_entry_new ();
  gtk_widget_show (AGcompagnie_aerienne);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGcompagnie_aerienne, 200, 176);
  gtk_widget_set_size_request (AGcompagnie_aerienne, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGcompagnie_aerienne), 8226);

  AGdestination = gtk_entry_new ();
  gtk_widget_show (AGdestination);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdestination, 200, 304);
  gtk_widget_set_size_request (AGdestination, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGdestination), 8226);

  AGtarif = gtk_entry_new ();
  gtk_widget_show (AGtarif);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGtarif, 376, 384);
  gtk_widget_set_size_request (AGtarif, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGtarif), 8226);

  AGnbr_max_adj = gtk_adjustment_new (100, 1, 500, 1, 10, 10);
  AGnbr_max = gtk_spin_button_new (GTK_ADJUSTMENT (AGnbr_max_adj), 1, 0);
  gtk_widget_show (AGnbr_max);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGnbr_max, 376, 440);
  gtk_widget_set_size_request (AGnbr_max, 200, 30);

  AGdepart = gtk_entry_new ();
  gtk_widget_show (AGdepart);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdepart, 200, 240);
  gtk_widget_set_size_request (AGdepart, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGdepart), 8226);

  AGnum_vol_adj = gtk_adjustment_new (1, 1, 1000, 1, 10, 10);
  AGnum_vol = gtk_spin_button_new (GTK_ADJUSTMENT (AGnum_vol_adj), 1, 0);
  gtk_widget_show (AGnum_vol);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGnum_vol, 384, 104);
  gtk_widget_set_size_request (AGnum_vol, 200, 30);

  AGdate_depart_jour_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  AGdate_depart_jour = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_jour_adj), 1, 0);
  gtk_widget_show (AGdate_depart_jour);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_depart_jour, 568, 176);
  gtk_widget_set_size_request (AGdate_depart_jour, 70, 34);

  AGdate_depart_mois_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  AGdate_depart_mois = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_mois_adj), 1, 0);
  gtk_widget_show (AGdate_depart_mois);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_depart_mois, 640, 176);
  gtk_widget_set_size_request (AGdate_depart_mois, 70, 34);

  AGdate_depart_annee_adj = gtk_adjustment_new (2019, 2019, 2025, 1, 10, 10);
  AGdate_depart_annee = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_annee_adj), 1, 0);
  gtk_widget_show (AGdate_depart_annee);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_depart_annee, 712, 176);
  gtk_widget_set_size_request (AGdate_depart_annee, 70, 34);

  AGdate_retour_jour_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  AGdate_retour_jour = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_jour_adj), 1, 0);
  gtk_widget_show (AGdate_retour_jour);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_retour_jour, 568, 240);
  gtk_widget_set_size_request (AGdate_retour_jour, 70, 34);

  AGdate_retour_mois_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  AGdate_retour_mois = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_mois_adj), 1, 0);
  gtk_widget_show (AGdate_retour_mois);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_retour_mois, 640, 240);
  gtk_widget_set_size_request (AGdate_retour_mois, 70, 34);

  AGdate_retour_annee_adj = gtk_adjustment_new (2019, 2019, 2025, 1, 10, 10);
  AGdate_retour_annee = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_annee_adj), 1, 0);
  gtk_widget_show (AGdate_retour_annee);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGdate_retour_annee, 712, 240);
  gtk_widget_set_size_request (AGdate_retour_annee, 70, 34);

  AGimageAjouter = create_pixmap (AGwindowAjout, "interface generale1.png");
  gtk_widget_show (AGimageAjouter);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGimageAjouter, 0, 0);
  gtk_widget_set_size_request (AGimageAjouter, 800, 544);

  AGlabelAjout = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"dark blue\" size=\"large\"><b>Ajouter une vol</b></span>"));
  gtk_widget_show (AGlabelAjout);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelAjout, 304, 24);
  gtk_widget_set_size_request (AGlabelAjout, 216, 40);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelAjout), TRUE);

  AGclasse = gtk_combo_box_new_text ();
  gtk_widget_show (AGclasse);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGclasse, 568, 304);
  gtk_widget_set_size_request (AGclasse, 200, 30);
  gtk_combo_box_append_text (GTK_COMBO_BOX (AGclasse), _("economic"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (AGclasse), _("business"));

  AGAfficher = gtk_button_new ();
  gtk_widget_show (AGAfficher);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGAfficher, 696, 496);
  gtk_widget_set_size_request (AGAfficher, 95, 40);

  AGalignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (AGalignment2);
  gtk_container_add (GTK_CONTAINER (AGAfficher), AGalignment2);

  AGhbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (AGhbox2);
  gtk_container_add (GTK_CONTAINER (AGalignment2), AGhbox2);

  AGimage2 = gtk_image_new_from_stock ("gtk-select-all", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (AGimage2);
  gtk_box_pack_start (GTK_BOX (AGhbox2), AGimage2, FALSE, FALSE, 0);

  AGlabel2 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Afficher</b></span>"));
  gtk_widget_show (AGlabel2);
  gtk_box_pack_start (GTK_BOX (AGhbox2), AGlabel2, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (AGlabel2), TRUE);

  AGAjouter = gtk_button_new ();
  gtk_widget_show (AGAjouter);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGAjouter, 8, 496);
  gtk_widget_set_size_request (AGAjouter, 95, 40);

  AGalignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (AGalignment1);
  gtk_container_add (GTK_CONTAINER (AGAjouter), AGalignment1);

  AGhbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (AGhbox1);
  gtk_container_add (GTK_CONTAINER (AGalignment1), AGhbox1);

  AGimage1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (AGimage1);
  gtk_box_pack_start (GTK_BOX (AGhbox1), AGimage1, FALSE, FALSE, 0);

  AGlabel = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Ajouter</b></span>"));
  gtk_widget_show (AGlabel);
  gtk_box_pack_start (GTK_BOX (AGhbox1), AGlabel, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (AGlabel), TRUE);

  AGlabelConfirmation = gtk_label_new ("");
  gtk_widget_show (AGlabelConfirmation);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelConfirmation, 264, 488);
  gtk_widget_set_size_request (AGlabelConfirmation, 248, 49);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelConfirmation), TRUE);
  gtk_misc_set_alignment (GTK_MISC (AGlabelConfirmation), 0.5, 0.49);
  gtk_label_set_width_chars (GTK_LABEL (AGlabelConfirmation), 0);

  AGlabelNum = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Numero de Vol :</b></span>"));
  gtk_widget_show (AGlabelNum);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelNum, 224, 112);
  gtk_widget_set_size_request (AGlabelNum, 128, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelNum), TRUE);

  AGlabelCompagnieAerienne = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Compagnie aerienne :</b></span>"));
  gtk_widget_show (AGlabelCompagnieAerienne);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelCompagnieAerienne, 16, 184);
  gtk_widget_set_size_request (AGlabelCompagnieAerienne, 170, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelCompagnieAerienne), TRUE);

  AGlabelDepart = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Depart :</b></span>"));
  gtk_widget_show (AGlabelDepart);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelDepart, 112, 248);
  gtk_widget_set_size_request (AGlabelDepart, 71, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDepart), TRUE);

  AGlabelDestination = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Destination :</b></span>"));
  gtk_widget_show (AGlabelDestination);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelDestination, 72, 312);
  gtk_widget_set_size_request (AGlabelDestination, 113, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDestination), TRUE);

  AGlabelDateDepart = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Date de depart :</b></span>"));
  gtk_widget_show (AGlabelDateDepart);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelDateDepart, 432, 184);
  gtk_widget_set_size_request (AGlabelDateDepart, 129, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDateDepart), TRUE);

  AGlabelDateRetour = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Date de retour :</b></span>"));
  gtk_widget_show (AGlabelDateRetour);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelDateRetour, 424, 248);
  gtk_widget_set_size_request (AGlabelDateRetour, 145, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDateRetour), TRUE);

  AGlabelClasse = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Classe :</b></span>"));
  gtk_widget_show (AGlabelClasse);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelClasse, 480, 312);
  gtk_widget_set_size_request (AGlabelClasse, 73, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelClasse), TRUE);

  AGlabelTarif = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Tarif :</b></span>"));
  gtk_widget_show (AGlabelTarif);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelTarif, 280, 392);
  gtk_widget_set_size_request (AGlabelTarif, 70, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelTarif), TRUE);

  AGlabelNbrMax = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Nombre maximal de voyageurs :</b></span>"));
  gtk_widget_show (AGlabelNbrMax);
  gtk_fixed_put (GTK_FIXED (AGfixed2), AGlabelNbrMax, 104, 448);
  gtk_widget_set_size_request (AGlabelNbrMax, 241, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelNbrMax), TRUE);

  g_signal_connect ((gpointer) AGAfficher, "clicked",
                    G_CALLBACK (on_AGAfficher_clicked),
                    NULL);
  g_signal_connect ((gpointer) AGAjouter, "clicked",
                    G_CALLBACK (on_AGAjouter_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (AGwindowAjout, AGwindowAjout, "AGwindowAjout");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGfixed2, "AGfixed2");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGcompagnie_aerienne, "AGcompagnie_aerienne");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdestination, "AGdestination");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGtarif, "AGtarif");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGnbr_max, "AGnbr_max");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdepart, "AGdepart");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGnum_vol, "AGnum_vol");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_depart_jour, "AGdate_depart_jour");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_depart_mois, "AGdate_depart_mois");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_depart_annee, "AGdate_depart_annee");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_retour_jour, "AGdate_retour_jour");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_retour_mois, "AGdate_retour_mois");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGdate_retour_annee, "AGdate_retour_annee");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGimageAjouter, "AGimageAjouter");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelAjout, "AGlabelAjout");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGclasse, "AGclasse");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGAfficher, "AGAfficher");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGalignment2, "AGalignment2");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGhbox2, "AGhbox2");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGimage2, "AGimage2");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabel2, "AGlabel2");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGAjouter, "AGAjouter");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGalignment1, "AGalignment1");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGhbox1, "AGhbox1");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGimage1, "AGimage1");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabel, "AGlabel");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelConfirmation, "AGlabelConfirmation");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelNum, "AGlabelNum");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelCompagnieAerienne, "AGlabelCompagnieAerienne");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelDepart, "AGlabelDepart");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelDestination, "AGlabelDestination");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelDateDepart, "AGlabelDateDepart");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelDateRetour, "AGlabelDateRetour");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelClasse, "AGlabelClasse");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelTarif, "AGlabelTarif");
  GLADE_HOOKUP_OBJECT (AGwindowAjout, AGlabelNbrMax, "AGlabelNbrMax");

  return AGwindowAjout;
}

GtkWidget*
create_AGwindowModifier (void)
{
  GtkWidget *AGwindowModifier;
  GtkWidget *AGfixed4;
  GtkWidget *AGcompagnie_aerienneM;
  GtkWidget *AGdestinationM;
  GtkWidget *AGtarifM;
  GtkObject *AGnbr_maxM_adj;
  GtkWidget *AGnbr_maxM;
  GtkWidget *AGdepartM;
  GtkObject *AGnum_volM_adj;
  GtkWidget *AGnum_volM;
  GtkObject *AGdate_depart_jourM_adj;
  GtkWidget *AGdate_depart_jourM;
  GtkObject *AGdate_depart_moisM_adj;
  GtkWidget *AGdate_depart_moisM;
  GtkObject *AGdate_depart_anneeM_adj;
  GtkWidget *AGdate_depart_anneeM;
  GtkObject *AGdate_retour_jourM_adj;
  GtkWidget *AGdate_retour_jourM;
  GtkObject *AGdate_retour_moisM_adj;
  GtkWidget *AGdate_retour_moisM;
  GtkObject *AGdate_retour_anneeM_adj;
  GtkWidget *AGdate_retour_anneeM;
  GtkWidget *AGimageModifier;
  GtkWidget *AGlabelNumVolM;
  GtkWidget *AGclasseM;
  GtkWidget *AGrecherche;
  GtkWidget *AGimage6;
  GtkWidget *AGvalider;
  GtkWidget *AGalignment5;
  GtkWidget *AGhbox5;
  GtkWidget *AGimage7;
  GtkWidget *AGlabel19;
  GtkWidget *AGlabelConfirmationM;
  GtkWidget *AGRetourM;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label1;
  GtkWidget *AGlabelCompagnieAerienneM;
  GtkWidget *AGlabelDepartM;
  GtkWidget *AGlabelDestinationM;
  GtkWidget *AGlabelDateDepartM;
  GtkWidget *AGlabelDateRetourM;
  GtkWidget *AGlabelClasseM;
  GtkWidget *AGlabelTarifM;
  GtkWidget *AGlabelNbrMaxM;
  GtkWidget *AGlabel1;

  AGwindowModifier = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (AGwindowModifier), _("Modifier vol"));

  AGfixed4 = gtk_fixed_new ();
  gtk_widget_show (AGfixed4);
  gtk_container_add (GTK_CONTAINER (AGwindowModifier), AGfixed4);

  AGcompagnie_aerienneM = gtk_entry_new ();
  gtk_widget_show (AGcompagnie_aerienneM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGcompagnie_aerienneM, 192, 184);
  gtk_widget_set_size_request (AGcompagnie_aerienneM, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGcompagnie_aerienneM), 8226);

  AGdestinationM = gtk_entry_new ();
  gtk_widget_show (AGdestinationM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdestinationM, 192, 320);
  gtk_widget_set_size_request (AGdestinationM, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGdestinationM), 8226);

  AGtarifM = gtk_entry_new ();
  gtk_widget_show (AGtarifM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGtarifM, 416, 392);
  gtk_widget_set_size_request (AGtarifM, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGtarifM), 8226);

  AGnbr_maxM_adj = gtk_adjustment_new (100, 1, 500, 1, 10, 10);
  AGnbr_maxM = gtk_spin_button_new (GTK_ADJUSTMENT (AGnbr_maxM_adj), 1, 0);
  gtk_widget_show (AGnbr_maxM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGnbr_maxM, 416, 448);
  gtk_widget_set_size_request (AGnbr_maxM, 200, 30);

  AGdepartM = gtk_entry_new ();
  gtk_widget_show (AGdepartM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdepartM, 192, 248);
  gtk_widget_set_size_request (AGdepartM, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (AGdepartM), 8226);

  AGnum_volM_adj = gtk_adjustment_new (1, 1, 1000, 1, 10, 10);
  AGnum_volM = gtk_spin_button_new (GTK_ADJUSTMENT (AGnum_volM_adj), 1, 0);
  gtk_widget_show (AGnum_volM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGnum_volM, 408, 104);
  gtk_widget_set_size_request (AGnum_volM, 200, 30);

  AGdate_depart_jourM_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  AGdate_depart_jourM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_jourM_adj), 1, 0);
  gtk_widget_show (AGdate_depart_jourM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_depart_jourM, 568, 176);
  gtk_widget_set_size_request (AGdate_depart_jourM, 70, 34);

  AGdate_depart_moisM_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  AGdate_depart_moisM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_moisM_adj), 1, 0);
  gtk_widget_show (AGdate_depart_moisM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_depart_moisM, 640, 176);
  gtk_widget_set_size_request (AGdate_depart_moisM, 70, 34);

  AGdate_depart_anneeM_adj = gtk_adjustment_new (2019, 2019, 2015, 1, 10, 10);
  AGdate_depart_anneeM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_depart_anneeM_adj), 1, 0);
  gtk_widget_show (AGdate_depart_anneeM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_depart_anneeM, 712, 176);
  gtk_widget_set_size_request (AGdate_depart_anneeM, 70, 34);

  AGdate_retour_jourM_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  AGdate_retour_jourM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_jourM_adj), 1, 0);
  gtk_widget_show (AGdate_retour_jourM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_retour_jourM, 568, 240);
  gtk_widget_set_size_request (AGdate_retour_jourM, 70, 34);

  AGdate_retour_moisM_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  AGdate_retour_moisM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_moisM_adj), 1, 0);
  gtk_widget_show (AGdate_retour_moisM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_retour_moisM, 640, 240);
  gtk_widget_set_size_request (AGdate_retour_moisM, 70, 34);

  AGdate_retour_anneeM_adj = gtk_adjustment_new (2019, 2019, 2015, 1, 10, 10);
  AGdate_retour_anneeM = gtk_spin_button_new (GTK_ADJUSTMENT (AGdate_retour_anneeM_adj), 1, 0);
  gtk_widget_show (AGdate_retour_anneeM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGdate_retour_anneeM, 712, 240);
  gtk_widget_set_size_request (AGdate_retour_anneeM, 70, 34);

  AGimageModifier = create_pixmap (AGwindowModifier, "interface generale1.png");
  gtk_widget_show (AGimageModifier);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGimageModifier, 0, 0);
  gtk_widget_set_size_request (AGimageModifier, 808, 544);

  AGlabelNumVolM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Numero de la vol :</b></span>"));
  gtk_widget_show (AGlabelNumVolM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelNumVolM, 248, 112);
  gtk_widget_set_size_request (AGlabelNumVolM, 139, 19);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelNumVolM), TRUE);

  AGclasseM = gtk_combo_box_new_text ();
  gtk_widget_show (AGclasseM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGclasseM, 568, 320);
  gtk_widget_set_size_request (AGclasseM, 200, 30);
  gtk_combo_box_append_text (GTK_COMBO_BOX (AGclasseM), _("economic"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (AGclasseM), _("business"));

  AGrecherche = gtk_button_new ();
  gtk_widget_show (AGrecherche);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGrecherche, 624, 104);
  gtk_widget_set_size_request (AGrecherche, 35, 30);

  AGimage6 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (AGimage6);
  gtk_container_add (GTK_CONTAINER (AGrecherche), AGimage6);

  AGvalider = gtk_button_new ();
  gtk_widget_show (AGvalider);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGvalider, 0, 496);
  gtk_widget_set_size_request (AGvalider, 120, 40);

  AGalignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (AGalignment5);
  gtk_container_add (GTK_CONTAINER (AGvalider), AGalignment5);

  AGhbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (AGhbox5);
  gtk_container_add (GTK_CONTAINER (AGalignment5), AGhbox5);

  AGimage7 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (AGimage7);
  gtk_box_pack_start (GTK_BOX (AGhbox5), AGimage7, FALSE, FALSE, 0);

  AGlabel19 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Valider</b></span>"));
  gtk_widget_show (AGlabel19);
  gtk_box_pack_start (GTK_BOX (AGhbox5), AGlabel19, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (AGlabel19), TRUE);

  AGlabelConfirmationM = gtk_label_new ("");
  gtk_widget_show (AGlabelConfirmationM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelConfirmationM, 280, 497);
  gtk_widget_set_size_request (AGlabelConfirmationM, 248, 40);

  AGRetourM = gtk_button_new ();
  gtk_widget_show (AGRetourM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGRetourM, 680, 496);
  gtk_widget_set_size_request (AGRetourM, 120, 40);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (AGRetourM), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-file", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label1 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>Afficher</b></span>"));
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (hbox1), label1, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label1), TRUE);

  AGlabelCompagnieAerienneM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Compagnie aerienne :</b></span>"));
  gtk_widget_show (AGlabelCompagnieAerienneM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelCompagnieAerienneM, 16, 192);
  gtk_widget_set_size_request (AGlabelCompagnieAerienneM, 160, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelCompagnieAerienneM), TRUE);

  AGlabelDepartM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Depart :</b></span>"));
  gtk_widget_show (AGlabelDepartM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelDepartM, 104, 256);
  gtk_widget_set_size_request (AGlabelDepartM, 71, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDepartM), TRUE);

  AGlabelDestinationM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Destination :</b></span>"));
  gtk_widget_show (AGlabelDestinationM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelDestinationM, 64, 328);
  gtk_widget_set_size_request (AGlabelDestinationM, 113, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDestinationM), TRUE);

  AGlabelDateDepartM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Date de depart :</b></span>"));
  gtk_widget_show (AGlabelDateDepartM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelDateDepartM, 432, 192);
  gtk_widget_set_size_request (AGlabelDateDepartM, 129, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDateDepartM), TRUE);

  AGlabelDateRetourM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Date de retour :</b></span>"));
  gtk_widget_show (AGlabelDateRetourM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelDateRetourM, 424, 256);
  gtk_widget_set_size_request (AGlabelDateRetourM, 145, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelDateRetourM), TRUE);

  AGlabelClasseM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Classe :</b></span>"));
  gtk_widget_show (AGlabelClasseM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelClasseM, 480, 328);
  gtk_widget_set_size_request (AGlabelClasseM, 73, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelClasseM), TRUE);

  AGlabelTarifM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Tarif :</b></span>"));
  gtk_widget_show (AGlabelTarifM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelTarifM, 312, 400);
  gtk_widget_set_size_request (AGlabelTarifM, 70, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelTarifM), TRUE);

  AGlabelNbrMaxM = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"black\" size=\"small\"><b>*Nombre maximal de voyageurs :</b></span>"));
  gtk_widget_show (AGlabelNbrMaxM);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabelNbrMaxM, 136, 456);
  gtk_widget_set_size_request (AGlabelNbrMaxM, 234, 17);
  gtk_label_set_use_markup (GTK_LABEL (AGlabelNbrMaxM), TRUE);

  AGlabel1 = gtk_label_new (_("<span font_desc=\"pursia\"foreground=\"dark blue\" size=\"large\"><b>Modifier une Vol</b></span>"));
  gtk_widget_show (AGlabel1);
  gtk_fixed_put (GTK_FIXED (AGfixed4), AGlabel1, 288, 32);
  gtk_widget_set_size_request (AGlabel1, 259, 29);
  gtk_label_set_use_markup (GTK_LABEL (AGlabel1), TRUE);

  g_signal_connect ((gpointer) AGrecherche, "clicked",
                    G_CALLBACK (on_AGrecherche_clicked),
                    NULL);
  g_signal_connect ((gpointer) AGvalider, "clicked",
                    G_CALLBACK (on_AGvalider_clicked),
                    NULL);
  g_signal_connect ((gpointer) AGRetourM, "clicked",
                    G_CALLBACK (on_AGRetourM_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (AGwindowModifier, AGwindowModifier, "AGwindowModifier");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGfixed4, "AGfixed4");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGcompagnie_aerienneM, "AGcompagnie_aerienneM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdestinationM, "AGdestinationM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGtarifM, "AGtarifM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGnbr_maxM, "AGnbr_maxM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdepartM, "AGdepartM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGnum_volM, "AGnum_volM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_depart_jourM, "AGdate_depart_jourM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_depart_moisM, "AGdate_depart_moisM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_depart_anneeM, "AGdate_depart_anneeM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_retour_jourM, "AGdate_retour_jourM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_retour_moisM, "AGdate_retour_moisM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGdate_retour_anneeM, "AGdate_retour_anneeM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGimageModifier, "AGimageModifier");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelNumVolM, "AGlabelNumVolM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGclasseM, "AGclasseM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGrecherche, "AGrecherche");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGimage6, "AGimage6");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGvalider, "AGvalider");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGalignment5, "AGalignment5");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGhbox5, "AGhbox5");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGimage7, "AGimage7");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabel19, "AGlabel19");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelConfirmationM, "AGlabelConfirmationM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGRetourM, "AGRetourM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, image1, "image1");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, label1, "label1");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelCompagnieAerienneM, "AGlabelCompagnieAerienneM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelDepartM, "AGlabelDepartM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelDestinationM, "AGlabelDestinationM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelDateDepartM, "AGlabelDateDepartM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelDateRetourM, "AGlabelDateRetourM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelClasseM, "AGlabelClasseM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelTarifM, "AGlabelTarifM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabelNbrMaxM, "AGlabelNbrMaxM");
  GLADE_HOOKUP_OBJECT (AGwindowModifier, AGlabel1, "AGlabel1");

  return AGwindowModifier;
}

GtkWidget*
create_AGwindowCatalogue (void)
{
  GtkWidget *AGwindowCatalogue;
  GtkWidget *AGscrolledwindow1;
  GtkWidget *AGtreeview1;

  AGwindowCatalogue = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (AGwindowCatalogue), _("Catalogue"));

  AGscrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (AGscrolledwindow1);
  gtk_container_add (GTK_CONTAINER (AGwindowCatalogue), AGscrolledwindow1);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (AGscrolledwindow1), GTK_SHADOW_IN);

  AGtreeview1 = gtk_tree_view_new ();
  gtk_widget_show (AGtreeview1);
  gtk_container_add (GTK_CONTAINER (AGscrolledwindow1), AGtreeview1);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (AGwindowCatalogue, AGwindowCatalogue, "AGwindowCatalogue");
  GLADE_HOOKUP_OBJECT (AGwindowCatalogue, AGscrolledwindow1, "AGscrolledwindow1");
  GLADE_HOOKUP_OBJECT (AGwindowCatalogue, AGtreeview1, "AGtreeview1");

  return AGwindowCatalogue;
}
