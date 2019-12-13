#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtkclist.h>
#include  <gdk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
#include "fonction.h"


void
on_annuler_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}
void
on_connexion_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window1,*window2;

window1=lookup_widget(objet_graphique,"window1");


window2=create_window2();
gtk_widget_show(window2);
gtk_widget_hide(window1);


}




void
on_inscription_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

int x;
char username[100];
char password[100];
char message[29]="Bienvenue Dans Votre Espace";
GtkWidget *window3;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output1;
GtkWidget *output2;
input1=lookup_widget(objet_graphique,"entryuser");
input2=lookup_widget(objet_graphique,"entrypass");
output1=lookup_widget(objet_graphique,"labelespace");
output2=lookup_widget(objet_graphique,"labelerreur");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
x=verifier(username,password);
if (x!=-1)
{


GtkWidget *window2,*window7;

window2=lookup_widget(objet_graphique,"window2");


window7=create_window7();
gtk_widget_show(window7);
gtk_widget_hide(window2);



}
else
{
gtk_label_set_text(GTK_LABEL(output2),"le login ou password entré ne correspond à aucun compte");
}
}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window3;
GtkWidget *window4;
GtkWidget *treeview1;

window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window4=lookup_widget(objet,"window4");
window4=create_window4();

gtk_widget_show(window4);

treeview1=lookup_widget(window4,"treeview1");

afficher_personne(treeview1);
}

void
on_afficher5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window4;
GtkWidget *treeview1;

window5=lookup_widget(objet,"window5");

gtk_widget_destroy(window5);
window4=lookup_widget(objet,"window4");
window4=create_window4();

gtk_widget_show(window4);

treeview1=lookup_widget(window4,"treeview1");

afficher_personne(treeview1);
}



void
on_ajouter_clicked                     (GtkWidget       *objet,
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

char empty[]="\0";
GtkWidget *window3;

window3=lookup_widget(objet,"window3");

output7=lookup_widget(objet,"erreur7");
output6=lookup_widget(objet,"erreur6");
output5=lookup_widget(objet,"erreur5");
output4=lookup_widget(objet,"erreur4");
output3=lookup_widget(objet,"erreur3");
output2=lookup_widget(objet,"erreur2");
output1=lookup_widget(objet,"erreur1");

input1=lookup_widget(objet,"identifiant");
input2=lookup_widget(objet,"mot_de_passe");
input3=lookup_widget(objet,"nom");
input4=lookup_widget(objet,"prenom");
input5=lookup_widget(objet,"tel");
input6=lookup_widget(objet,"email");
input7=lookup_widget(objet,"adresse");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
sexe=lookup_widget(objet,"sexe");


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
}
}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window3,*window4;

window4=lookup_widget(objet,"window4");

gtk_widget_destroy(window4);
window3=lookup_widget(objet,"window3");
window3=create_window3();
gtk_widget_show(window3);

}








void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window6;


window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window6=lookup_widget(objet,"window6");
window6=create_window6();

gtk_widget_show(window6);

}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window5;


window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window5=lookup_widget(objet,"window5");
window5=create_window5();

gtk_widget_show(window5);


}


void
on_modifierr_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
GtkWidget *window5;
GtkWidget *input1,*input2,*input3,*input4,*sexe,*jour,*mois,*annee,*input5,*input6,*input7;

window5=lookup_widget(objet,"window5");
char id [30];

input1=lookup_widget(objet,"nid");
input2=lookup_widget(objet,"nmot_de_passe");
input3=lookup_widget(objet,"nnom");
input4=lookup_widget(objet,"nprenom");

sexe=lookup_widget(objet,"nsexe");
jour=lookup_widget(objet,"njour");
mois=lookup_widget(objet,"nmois");
annee=lookup_widget(objet,"nannee");

input5=lookup_widget(objet,"ntel");
input6=lookup_widget(objet,"nemail");
input7=lookup_widget(objet,"nadresse");


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
// gtk_labem_set_text(GTK_LABEL(OUTOUT),"MO MSG");
}

void
on_buttonz4_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window5;


window5=lookup_widget(objet,"window5");

gtk_widget_destroy(window5);
window3=lookup_widget(objet,"window3");
window3=create_window3();

gtk_widget_show(window3);


}


void
on_valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
GtkWidget window5;
GtkWidget *input1,*output1,*output2,*output3,*output4,*output5,*output6,*output7;

char id [30];


output1=lookup_widget(objet,"nid");
output2=lookup_widget(objet,"nmot_de_passe");
output3=lookup_widget(objet,"nnom");
output4=lookup_widget(objet,"nprenom");
output5=lookup_widget(objet,"ntel");
output6=lookup_widget(objet,"nemail");
output7=lookup_widget(objet,"nadresse");

input1=lookup_widget(objet,"id");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

FILE *f;
	f=fopen("/home/zohrafridhi/Projects/project5/src/client.txt","r");
	if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,&p.jour,&p.mois,&p.annee,p.tel,p.email,p.adresse)!=EOF)
{
	if (strcmp(p.identifiant,id)==0)
{
gtk_entry_set_text (GTK_ENTRY (output1),p.identifiant);
gtk_entry_set_text (GTK_ENTRY (output2),p.mot_de_passe);
gtk_entry_set_text (GTK_ENTRY (output3),p.nom);
gtk_entry_set_text (GTK_ENTRY (output4),p.prenom);
gtk_entry_set_text (GTK_ENTRY (output5),p.tel);
gtk_entry_set_text (GTK_ENTRY (output6),p.email);
gtk_entry_set_text (GTK_ENTRY (output7),p.adresse);
}
/*fclose(f);*/
}
}



}




void
on_confirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window6;
GtkWidget *input;
char supp[30];
input=lookup_widget(objet,"supp");
strcpy(supp,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer(supp);
}











void
on_deconnexion3_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window3;


window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window3);
window7=lookup_widget(objet,"window7");
window7=create_window7();

gtk_widget_show(window7);
}


void
on_deconnexion5_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window5;


window5=lookup_widget(objet,"window5");

gtk_widget_destroy(window5);
window7=lookup_widget(objet,"window7");
window7=create_window7();

gtk_widget_show(window7);
}


void
on_deconnexion7_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window7;


window7=lookup_widget(objet,"window7");

gtk_widget_destroy(window7);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);

}


void
on_moncompte_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window8;
GtkWidget *window7;


window7=lookup_widget(objet,"window7");

gtk_widget_destroy(window7);
window8=lookup_widget(objet,"window8");
window8=create_window8();

gtk_widget_show(window8);


}


void
on_resevation_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_reclamation_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_deconnexion8_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window8;


window8=lookup_widget(objet,"window8");

gtk_widget_destroy(window8);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);

}


/*void
on_modifier8_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window9;
GtkWidget *window8;


window8=lookup_widget(objet,"window8");

gtk_widget_destroy(window8);
window9=lookup_widget(objet,"window9");
window9=create_window9();

gtk_widget_show(window9);



}*/


void
on_button4emp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window8;


window8=lookup_widget(objet,"window8");

gtk_widget_destroy(window8);
window7=lookup_widget(objet,"window7");
window7=create_window7();

gtk_widget_show(window7);
}


/*void
on_button9emp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window8;
GtkWidget *window9;


window9=lookup_widget(objet,"window9");

gtk_widget_destroy(window9);
window8=lookup_widget(objet,"window8");
window8=create_window8();

gtk_widget_show(window8);
}*/


/*void
on_button8emp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
GtkWidget *window9;
GtkWidget *input1,*input2,*input3,*input4,*sexe,*jour,*mois,*annee,*input5,*input6,*input7;

window9=lookup_widget(objet,"window9");
char entry1id7 [30];

input1=lookup_widget(objet,"entry1id7");
input2=lookup_widget(objet,"entry1empt");
input3=lookup_widget(objet,"entry6emp");
input4=lookup_widget(objet,"entry8emp");

sexe=lookup_widget(objet,"comboboxentry1emp");
jour=lookup_widget(objet,"spinbutton3emp");
mois=lookup_widget(objet,"spinbutton4emp");
annee=lookup_widget(objet,"spinbutton5emp");

input5=lookup_widget(objet,"entry9emp");
input6=lookup_widget(objet,"entry10emp");
input7=lookup_widget(objet,"entry11emp");


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

modifier_employer(p);
}*/

void
on_debutemp_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window6;


window6=lookup_widget(objet,"window6");

gtk_widget_destroy(window6);
window7=lookup_widget(objet,"window7");
window7=create_window7();

gtk_widget_show(window7);
}


void
on_validercemp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
GtkWidget window8;
GtkWidget *input1,*output1,*output2,*output3,*output4,*output5,*output6,*output7;

char entry1emptt [30];


output1=lookup_widget(objet,"entry28z");
output2=lookup_widget(objet,"entry2empty");
output3=lookup_widget(objet,"entry18z");
output4=lookup_widget(objet,"entry38z");
output5=lookup_widget(objet,"entry48z");
output6=lookup_widget(objet,"entry58z");
output7=lookup_widget(objet,"entry6z88");

input1=lookup_widget(objet,"entry1emptt");
strcpy(entry1emptt,gtk_entry_get_text(GTK_ENTRY(input1)));

FILE *f;
	f=fopen("/home/zohrafridhi/Projects/project5/src/employer.txt","r");
	if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,&p.jour,&p.mois,&p.annee,p.tel,p.email,p.adresse)!=EOF)
{
	if (strcmp(p.identifiant,entry1emptt)==0)
{
gtk_entry_set_text (GTK_ENTRY (output1),p.identifiant);
gtk_entry_set_text (GTK_ENTRY (output2),p.mot_de_passe);
gtk_entry_set_text (GTK_ENTRY (output3),p.nom);
gtk_entry_set_text (GTK_ENTRY (output4),p.prenom);
gtk_entry_set_text (GTK_ENTRY (output5),p.tel);
gtk_entry_set_text (GTK_ENTRY (output6),p.email);
gtk_entry_set_text (GTK_ENTRY (output7),p.adresse);
}
fclose(f);
}
}



}



/*void
on_button4etro_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
GtkWidget window9;
GtkWidget *input1,*output1,*output2,*output3,*output4,*output5,*output6,*output7,*sexe,*jour,*mois,*annee;

char entry1id7 [30],c1[30],c2[30],c3[30];


output1=lookup_widget(objet,"entry7emp");
output2=lookup_widget(objet,"entry1empt");
output3=lookup_widget(objet,"entry6emp");
output4=lookup_widget(objet,"entry8emp");

sexe=lookup_widget(objet,"comboboxentry1emp");
jour=lookup_widget(objet,"spinbutton3emp");
mois=lookup_widget(objet,"spinbutton4emp");
annee=lookup_widget(objet,"spinbutton5emp");

output5=lookup_widget(objet,"entry9emp");
output6=lookup_widget(objet,"entry10emp");
output7=lookup_widget(objet,"entry11emp");




input1=lookup_widget(objet,"entry1id7");
strcpy(entry1id7,gtk_entry_get_text(GTK_ENTRY(input1)));

FILE *f;
	f=fopen("/home/zohrafridhi/Projects/project5/src/employer.txt","r");
	if(f!=NULL)

{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,&p.jour,&p.mois,&p.annee,p.tel,p.email,p.adresse)!=EOF)
{
	if (strcmp(p.identifiant,entry1id7)==0)
{
gtk_entry_set_text (GTK_ENTRY (output1),p.identifiant);
gtk_entry_set_text (GTK_ENTRY (output2),p.mot_de_passe);
gtk_entry_set_text (GTK_ENTRY (output3),p.nom);
gtk_entry_set_text (GTK_ENTRY (output4),p.prenom);
gtk_entry_set_text (GTK_ENTRY (sexe),p.sexe);
sprintf(c1,"%d",p.jour);
gtk_entry_set_text (GTK_ENTRY (jour),c1);
sprintf(c2,"%d",p.mois);
gtk_entry_set_text (GTK_ENTRY (mois),c2);
sprintf(c3,"%d",p.annee);
gtk_entry_set_text (GTK_ENTRY (annee),c3);
gtk_entry_set_text (GTK_ENTRY (output5),p.tel);
gtk_entry_set_text (GTK_ENTRY (output6),p.email);
gtk_entry_set_text (GTK_ENTRY (output7),p.adresse);

}
fclose(f);
}
}
}*/








void
on_nosclient_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window7;


window7=lookup_widget(objet,"window7");

gtk_widget_destroy(window7);
window3=lookup_widget(objet,"window3");
window3=create_window3();

gtk_widget_show(window3);
}



