#include <gtk/gtk.h>

int main (int    argc, char **argv)
{
  GtkWidget *window;
  GtkWidget *text;

  gtk_init(NULL, NULL);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 1280, 720);

  GtkWidget *box = gtk_hbox_new(FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), box);

  gtk_box_pack_end(GTK_BOX(box), gtk_label_new("Left"), FALSE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(box), gtk_text_view_new(), TRUE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(box), gtk_label_new("Right"), FALSE, TRUE, 0);

  gtk_widget_show_all (window);

  gtk_main();

  return 0;
}
