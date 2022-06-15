#include <gtk/gtk.h>

static void activate (GtkApplication *app,gpointer user_data)
{
	GtkWidget *window;
    GtkWidget *box;
    GtkWidget *fixed;
    GtkWidget *lbutton;

    // create the window and associate a title
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	gtk_window_set_title (GTK_WINDOW (window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    // Create a box and add it to the window 
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    /* Create a fixed container and add it to the box */
    fixed = gtk_fixed_new();
    gtk_box_pack_start(GTK_BOX(box), fixed, FALSE, FALSE, 0);

    /* Create new buttons */
    lbutton = gtk_button_new_with_label("Label Button");
    gtk_widget_set_size_request(lbutton, 150, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), lbutton, 100, 40);      //place of button
    //g_signal_connect(GTK_BUTTON(lbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(lbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(lbutton);

	gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.minimal", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	return status;
}
