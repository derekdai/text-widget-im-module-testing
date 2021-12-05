#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *text;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 1280, 720);

  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
  gtk_container_add(GTK_CONTAINER(window), box);

  gtk_box_pack_end(GTK_BOX(box), gtk_label_new("Left"), FALSE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(box), gtk_text_view_new(), TRUE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(box), gtk_label_new("Right"), FALSE, TRUE, 0);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
