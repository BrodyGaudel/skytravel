#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "voiture.h"


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
on_valider_clicked                     (GtkWidget       *objet,
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
f_md=fopen("/home/khalil/Desktop/voiture1/voiture1/src/md.txt","w");
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
f_md=fopen("/home/khalil/Desktop/voiture1/voiture1/src/md.txt","r");
if(f_md!=NULL){
    fscanf(f_md,"%s",serie1);} 
fclose(f_md);
remove("/home/khalil/Desktop/voiture1/voiture1/src/md.txt");

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

