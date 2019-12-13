#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_creation___clicked                  (GtkWidget       *objet,
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
GtkWidget *principal, *Reclamation_client;

gtk_widget_destroy(Reclamation_client);
principal=create_principal();
gtk_widget_show(principal);
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
{int mois,annee,jour,datesys,jr,mo,an,anx,mox,dateuser,moisx,anneex,b,i;
FILE *f1;
FILE *f2;
f1=fopen("datesys.txt","r");
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
/*b=strlen(c.rec);
for (i=0;i<b;i++)
if (strcmp(c.rec(i),' ')==0)
strcpy(c.rec(i),'_');*/
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
    
    f=fopen("utilisateur.txt","r");
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
on_buttonanis10_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1, *employe;

employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
principal1=create_principal1();
gtk_widget_show(principal1);
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
on_buttonanis11_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1;
GtkWidget *employe;
GtkWidget *treeviewanis2;

principal1=lookup_widget(objet,"principal1");

gtk_widget_destroy(principal1);
employe=lookup_widget(objet,"employe");
employe=create_employe();

gtk_widget_show(employe);

treeviewanis2=lookup_widget(employe,"treeviewanis2");
afficher_reclamation(treeviewanis2);
}

