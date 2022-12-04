


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GetBuilder *builder;
GtkWidget *window;

void on_window_main_destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file ("trabalhofinal.glade");
    gtk_builder_add_callback_symbols (builder,
                                      "on_window_main_destroy", G_CALLBACK (on_window_main_destroy),
                                      NULL);

    gtk_builder_connect_signals (builder, NULL);
    dilplay = GTK_ENTRY (gtk_builder_get_object (builder, "display"));
    gtk_entry_set_text (display, "0");

    GtkWidget *window = GTK_WIDGET (gtk_builder_get_object (builder, "window_main"));


    gtk_widget_show (window);
    gtk_main ();

    return 0;
}