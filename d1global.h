#include <gtk/gtk.h>

GdkPixmap *pixmap = NULL;
GdkFont *fixed_font;
GtkWidget *table;
GtkWidget *button_exit;
GtkWidget *drawing_area;
double avspec[32768];
double spec[32768];
double wav[16384];
double fspec[32768];
double bandp[32768];
double oznn[132768];
int fnum[32768];
int midx, midy;
d1type d1;

