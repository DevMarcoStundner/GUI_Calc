/* 
* Author: Stundner Marco
* Filename: main.c
* Task: GTK3 GUI Calc
* https://github.com/DevMarcoStundner/GUI_Calc.git
* Date 20.06.22
* clang main.c $(pkg-config --cflags --libs gtk+-3.0) -Wall -g -I. tinyexpr.c -lm
*/

#include <gtk/gtk.h>
#include "tinyexpr.h"
#include <stdbool.h>

struct calc_arg
{
    GtkWidget *input_entry;
    GtkWidget *history_label1;
    GtkWidget *history_label2;
    GtkWidget *history_label3;

    GtkWidget *equalbutton;
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
    GtkWidget *minusbutton;
    GtkWidget *squarebutton;
    GtkWidget *sqrtbutton;
    GtkWidget *rbracebutton;
    GtkWidget *lbracebutton;
    GtkWidget *mulbutton;
    GtkWidget *dividebutton;
    GtkWidget *clearbutton;
    GtkWidget *backbutton;
    const char *text;
    const char *history1;
    const char *history2;
    const char *history3;
    int history_index;
};


static void print_button(GtkWidget *widget, gpointer data)
{
    struct calc_arg *c = (struct calc_arg*)data;
    gchar *buffer1, *buffer2;

    buffer1 = (gchar*) gtk_entry_get_text (GTK_ENTRY (c->input_entry));
    buffer2 = g_malloc (sizeof(gchar) * (strlen(buffer1) + 256));
    if(widget == c->zerobutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'0');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->onebutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'1');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->twobutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'2');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->threebutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'3');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->fourbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'4');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->fivebutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'5');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->sixbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'6');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->sevenbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'7');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->eightbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'8');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->ninebutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'9');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->dotbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'.');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->percentbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'%');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->plusbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'+');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->minusbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'-');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->squarebutton)
    {
        sprintf(buffer2,"(%s)^%c",buffer1,'2');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    }
    if(widget == c->sqrtbutton)
    {
        sprintf(buffer2,"sqrt(%s)",buffer1);
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);   
    }
    if(widget == c->rbracebutton)
    {
        sprintf(buffer2,"%s)",buffer1);
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);   
    }
    if(widget == c->lbracebutton)
    {
        sprintf(buffer2,"(%s",buffer1);
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);   
    }
    if(widget == c->mulbutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'*');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);   
    }
    if(widget == c->dividebutton)
    {
        sprintf(buffer2,"%s%c",buffer1,'/');
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);  
    }
    if(widget == c->clearbutton)
    {
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), "");  
    }
    if(widget == c->backbutton)
    {

        sprintf(buffer2,"%s",buffer1);
        buffer2[strlen(buffer2)-1] = '\0'; 
        gtk_entry_set_text (GTK_ENTRY (c->input_entry), buffer2);
    } 
    g_free(buffer2);
}

static void calc_history(GtkWidget *widget, gpointer data)
{
    struct calc_arg *p = (struct calc_arg *) data;

    if(p->history_index == 2)
    {
        p->history3 = p->history2;
        gtk_label_set_text(GTK_LABEL (p->history_label3),p->history3);  

        p->history2 = p->history1;
        gtk_label_set_text(GTK_LABEL (p->history_label2),p->history2);   
        
        p->history1 = p->text;
        gtk_label_set_text(GTK_LABEL (p->history_label1),p->history1);   

        p->history3 = p->history2; 
        p->history2 = p->history1;
        p->history1 = p->text;
    }

    if(p->history_index == 1)
    {
        printf("anfang%s\n",p->history2);
        printf("%s\n",p->history1);
        p->history2 = p->history1;
        gtk_label_set_text(GTK_LABEL (p->history_label2),p->history2);   
        
        printf("danach%s\n",p->history2);
        printf("%s\n",p->history1);
        p->history1 = p->text;
        gtk_label_set_text(GTK_LABEL (p->history_label1),p->history1);
        p->history_index++;
    }

    if(p->history_index == 0)
    {
        p->history1 = p->text;
        gtk_label_set_text(GTK_LABEL (p->history_label1),p->history1);
        p->history_index++;
    }
    
}

static void equal_func(GtkWidget *widget, gpointer data)
{
    int *error = NULL;
    double result = 0;
    struct calc_arg *p = (struct calc_arg *) data;
    p->text = gtk_entry_get_text (GTK_ENTRY (p->input_entry));
    calc_history(p->history_label1, p);
    result = te_interp(p->text, error);
    char *output = g_strdup_printf ("%f", result);
    gtk_entry_set_text (GTK_ENTRY (p->input_entry), output);
    
}


static void activate (GtkApplication *app, gpointer user_data)
{
    struct calc_arg *m = (struct calc_arg *) user_data;

	GtkWidget *window;
    GtkWidget *box;
    GtkWidget *fixed;

    

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

    // Creates labels for the history
    m->history_label1 = gtk_label_new("");
    gtk_fixed_put(GTK_FIXED(fixed), m->history_label1, 0, 0);

    m->history_label2 = gtk_label_new("");
    gtk_fixed_put(GTK_FIXED(fixed), m->history_label2, 0, 25);

    m->history_label3 = gtk_label_new("");
    gtk_fixed_put(GTK_FIXED(fixed), m->history_label3, 0, 50);

    // Create new buttons 
    //@400
    m->zerobutton = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(m->zerobutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->zerobutton, 0, 400);      //place of button
    g_signal_connect(GTK_BUTTON(m->zerobutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->zerobutton);

    m->dotbutton = gtk_button_new_with_label(".");
    gtk_widget_set_size_request(m->dotbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->dotbutton, 60, 400);      //place of button
    g_signal_connect(GTK_BUTTON(m->dotbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->dotbutton);

    m->percentbutton = gtk_button_new_with_label("%");
    gtk_widget_set_size_request(m->percentbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->percentbutton, 120, 400);      //place of button
    g_signal_connect(GTK_BUTTON(m->percentbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->percentbutton);

    m->plusbutton = gtk_button_new_with_label("+");
    gtk_widget_set_size_request(m->plusbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->plusbutton, 180, 400);      //place of button
    g_signal_connect(GTK_BUTTON(m->plusbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->plusbutton);

    m->equalbutton = gtk_button_new_with_label("=");
    gtk_widget_set_size_request(m->equalbutton, 110, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->equalbutton, 240, 400);      //place of button
    g_signal_connect(m->equalbutton, "clicked", G_CALLBACK(equal_func), (gpointer) m); //function behind button
    gtk_widget_grab_focus(m->equalbutton);

    //@350
    m->onebutton = gtk_button_new_with_label("1");
    gtk_widget_set_size_request(m->onebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->onebutton, 0, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->onebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->onebutton);

    m->twobutton = gtk_button_new_with_label("2");
    gtk_widget_set_size_request(m->twobutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->twobutton, 60, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->twobutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->twobutton);

    m->threebutton = gtk_button_new_with_label("3");
    gtk_widget_set_size_request(m->threebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->threebutton, 120, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->threebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->threebutton);

    m->minusbutton = gtk_button_new_with_label("-");
    gtk_widget_set_size_request(m->minusbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->minusbutton, 180, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->minusbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->minusbutton);

    m->squarebutton = gtk_button_new_with_label("x²");
    gtk_widget_set_size_request(m->squarebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->squarebutton, 240, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->squarebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->squarebutton);

    m->sqrtbutton = gtk_button_new_with_label("x²");
    gtk_widget_set_size_request(m->sqrtbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->sqrtbutton, 300, 350);      //place of button
    g_signal_connect(GTK_BUTTON(m->sqrtbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->sqrtbutton);


    //@300
    m->fourbutton = gtk_button_new_with_label("4");
    gtk_widget_set_size_request(m->fourbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->fourbutton, 0, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->fourbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->fourbutton);

    m->fivebutton = gtk_button_new_with_label("5");
    gtk_widget_set_size_request(m->fivebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->fivebutton, 60, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->fivebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->fivebutton);

    m->sixbutton = gtk_button_new_with_label("6");
    gtk_widget_set_size_request(m->sixbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->sixbutton, 120, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->sixbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->sixbutton);

    m->mulbutton = gtk_button_new_with_label("*");
    gtk_widget_set_size_request(m->mulbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->mulbutton, 180, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->mulbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->mulbutton);

    m->lbracebutton = gtk_button_new_with_label("(");
    gtk_widget_set_size_request(m->lbracebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->lbracebutton, 240, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->lbracebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->lbracebutton);

    m->rbracebutton = gtk_button_new_with_label(")");
    gtk_widget_set_size_request(m->rbracebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->rbracebutton, 300, 300);      //place of button
    g_signal_connect(GTK_BUTTON(m->rbracebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->rbracebutton);


    //@250
    m->sevenbutton = gtk_button_new_with_label("7");
    gtk_widget_set_size_request(m->sevenbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->sevenbutton, 0, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->sevenbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->sevenbutton);

    m->eightbutton = gtk_button_new_with_label("8");
    gtk_widget_set_size_request(m->eightbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->eightbutton, 60, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->eightbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->eightbutton);

    m->ninebutton = gtk_button_new_with_label("9");
    gtk_widget_set_size_request(m->ninebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->ninebutton, 120, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->ninebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->ninebutton);

    m->dividebutton = gtk_button_new_with_label("/");
    gtk_widget_set_size_request(m->dividebutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->dividebutton, 180, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->dividebutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->dividebutton);

    m->clearbutton = gtk_button_new_with_label("C");
    gtk_widget_set_size_request(m->clearbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->clearbutton, 240, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->clearbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->clearbutton);

    m->backbutton = gtk_button_new_with_label("<-");
    gtk_widget_set_size_request(m->backbutton, 50, 25);          //size of button
    gtk_fixed_put(GTK_FIXED(fixed), m->backbutton, 300, 250);      //place of button
    g_signal_connect(GTK_BUTTON(m->backbutton), "clicked",G_CALLBACK(print_button), m); //function behind button
    gtk_widget_grab_focus(m->backbutton);

    m->input_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(m->input_entry),"INPUT");
    gtk_fixed_put(GTK_FIXED(fixed), m->input_entry, 0, 190);
    gtk_widget_set_size_request(m->input_entry, 350, 50);

	gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;
    struct calc_arg *d = g_malloc (sizeof (struct calc_arg));
    d->history1 = "0";
    d->history2 = "0";
    d->history2 = "0";
    d->history_index = 0;

    

	app = gtk_application_new ("org.gtk.minimal", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), (gpointer) d);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
    g_free (d);
	return status;
}

