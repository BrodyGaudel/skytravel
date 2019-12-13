#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <assert.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


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
int num,num1,r,test,test1,w;
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
else if (strlen(p.nom)<4)
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
  f=fopen("/home/amir07/Projects/project5/src/hotel.txt","r"); 
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
        else{
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
  f=fopen("/home/amir07/Projects/project5/src/hotel.txt","r"); 
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

