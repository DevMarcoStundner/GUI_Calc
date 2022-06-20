/* 
* Author: Stundner Marco
* Filename: main.c
* Task: GTK3 GUI Calc
* https://github.com/DevMarcoStundner/GUI_Calc.git
* Date 20.06.22
*/

#include <gtk/gtk.h>
#include "tinyexpr.h"

struct calc_arg
{
    GtkWidget *input_label;
    GtkWidget *equalbutton;
};


static void equal_func(GtkWidget *widget, gpointer data)
{
    const char *text = NULL;
    int *error = NULL;
    struct calc_arg *p = (struct calc_arg *) data;
    //gtk_entry_set_text (GTK_ENTRY (p->input_label), "Test" );
    text = gtk_entry_get_text (GTK_ENTRY (p->input_label));
    printf("%f\n",te_interp(text, error));
}

static void activate (GtkApplication *app, gpointer user_data)
{
    struct calc_arg *m = (struct calc_arg *) user_data;

	GtkWidget *window;
    GtkWidget *box;
    GtkWidget *fixed;

    GtkWidget *zerobutton;
    GtkWidget *onebutton;
    GtkWidget *twobutton;
    GtkWidget *threebutton;
    GtkWidget *fourbutton;
    GtkWidget *fivebutton;
    GtkWidget *sixbutton;
    GtkWidget *sevenbutton;
    GtkWidget *eightbutton;
    GtkWidget *ninebutton;

    GtkWidget *dotbutton;
    GtkWidget *percentbutton;
    GtkWidget *plusbutton;
   // GtkWidget *equalbutton;
    GtkWidget *minusbutton;
    GtkWidget *squarebutton;
    GtkWidget *sqrtbutton;
    GtkWidget *rbracebutton;
    GtkWidget *lbracebutton;
    GtkWidget *mulbutton;
    GtkWidget *dividebutton;
    GtkWidget *clearbutton;
    GtkWidget *backbutton;

   // GtkWidget *input_label;
    //GtkWidget *output_label;
    

    // create the window and associate a title
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	gtk_window_set_title (GTK_WINDOW (window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    // Create a box and add it to the window 
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create a fixed container and add it to the box 
    fixed = gtk_fixed_new();
    gtk_box_pack_start(GTK_BOX(box), fixed, TRUE, TRUE, 4);

    // Create new buttons 
    //@400
    zerobutton = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(zerobutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), zerobutton, 0, 400);      //place of button
    //g_signal_connect(GTK_BUTTON(zerobutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(zerobutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(zerobutton);

    dotbutton = gtk_button_new_with_label(".");
    gtk_widget_set_size_request(dotbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), dotbutton, 60, 400);      //place of button
    //g_signal_connect(GTK_BUTTON(dotbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(dotbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(dotbutton);

    percentbutton = gtk_button_new_with_label("%");
    gtk_widget_set_size_request(percentbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), percentbutton, 120, 400);      //place of button
    //g_signal_connect(GTK_BUTTON(percentbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(percentbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(percentbutton);

    plusbutton = gtk_button_new_with_label("+");
    gtk_widget_set_size_request(plusbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), plusbutton, 180, 400);      //place of button
    //g_signal_connect(GTK_BUTTON(plusbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(plusbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(plusbutton);

    m->equalbutton = gtk_button_new_with_label("=");
    gtk_widget_set_size_request(m->equalbutton, 110, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->equalbutton, 240, 400);      //place of button
    g_signal_connect(m->equalbutton, "clicked", G_CALLBACK(equal_func), (gpointer) m); //function behind button
    gtk_widget_set_tooltip_text(m->equalbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(m->equalbutton);

    //@350
    onebutton = gtk_button_new_with_label("1");
    gtk_widget_set_size_request(onebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), onebutton, 0, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(onebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(onebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(onebutton);

    twobutton = gtk_button_new_with_label("2");
    gtk_widget_set_size_request(twobutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), twobutton, 60, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(twobutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(twobutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(twobutton);

    threebutton = gtk_button_new_with_label("3");
    gtk_widget_set_size_request(threebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), threebutton, 120, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(threebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(threebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(threebutton);

    minusbutton = gtk_button_new_with_label("-");
    gtk_widget_set_size_request(minusbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), minusbutton, 180, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(minusbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(minusbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(minusbutton);

    squarebutton = gtk_button_new_with_label("x²");
    gtk_widget_set_size_request(squarebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), squarebutton, 240, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(squarebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(squarebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(squarebutton);

    sqrtbutton = gtk_button_new_with_label("x²");
    gtk_widget_set_size_request(sqrtbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), sqrtbutton, 300, 350);      //place of button
    //g_signal_connect(GTK_BUTTON(sqrtbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(sqrtbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(sqrtbutton);


    //@300
    fourbutton = gtk_button_new_with_label("4");
    gtk_widget_set_size_request(fourbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), fourbutton, 0, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(fourbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(fourbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(fourbutton);

    fivebutton = gtk_button_new_with_label("5");
    gtk_widget_set_size_request(fivebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), fivebutton, 60, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(fivebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(fivebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(fivebutton);

    sixbutton = gtk_button_new_with_label("6");
    gtk_widget_set_size_request(sixbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), sixbutton, 120, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(sixbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(sixbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(sixbutton);

    mulbutton = gtk_button_new_with_label("*");
    gtk_widget_set_size_request(mulbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), mulbutton, 180, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(mulbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(mulbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(mulbutton);

    lbracebutton = gtk_button_new_with_label("(");
    gtk_widget_set_size_request(lbracebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), lbracebutton, 240, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(lbracebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(lbracebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(lbracebutton);

    rbracebutton = gtk_button_new_with_label(")");
    gtk_widget_set_size_request(rbracebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), rbracebutton, 300, 300);      //place of button
    //g_signal_connect(GTK_BUTTON(rbracebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(rbracebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(rbracebutton);



    //@250
    sevenbutton = gtk_button_new_with_label("7");
    gtk_widget_set_size_request(sevenbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), sevenbutton, 0, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(sevenbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(sevenbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(sevenbutton);

    eightbutton = gtk_button_new_with_label("8");
    gtk_widget_set_size_request(eightbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), eightbutton, 60, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(eightbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(eightbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(eightbutton);

    ninebutton = gtk_button_new_with_label("9");
    gtk_widget_set_size_request(ninebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), ninebutton, 120, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(ninebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(ninebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(ninebutton);

    dividebutton = gtk_button_new_with_label("/");
    gtk_widget_set_size_request(dividebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), dividebutton, 180, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(dividebutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(dividebutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(dividebutton);

    clearbutton = gtk_button_new_with_label("clear");
    gtk_widget_set_size_request(clearbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), clearbutton, 240, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(clearbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(clearbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(clearbutton);

    backbutton = gtk_button_new_with_label("<-");
    gtk_widget_set_size_request(backbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), backbutton, 300, 250);      //place of button
    //g_signal_connect(GTK_BUTTON(backbutton), "clicked",G_CALLBACK(print_button), "lb"); //function behind button
    gtk_widget_set_tooltip_text(backbutton, "Left-click to change the button label"); //Tooltip
    gtk_widget_grab_focus(backbutton);


    m->input_label = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(m->input_label),"INPUT");
    gtk_fixed_put(GTK_FIXED(fixed), m->input_label, 0, 140);
    gtk_widget_set_size_request(m->input_label, 350, 100);
    gtk_box_pack_start(GTK_BOX(box),m->input_label,FALSE,FALSE,0);



	gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

    struct calc_arg *d = g_malloc (sizeof (struct calc_arg));

	app = gtk_application_new ("org.gtk.minimal", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), (gpointer) d);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
    g_free (d);
	return status;
}

