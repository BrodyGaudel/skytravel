#include<gtk/gtk.h>
#include<string.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

typedef struct
{
char marque[100];
char serie[100];
char age[100];
char kilometrage[100];
char prix[100];
char date[100];
}Voiture;
void afficher_voitureclient(GtkWidget *liste);

