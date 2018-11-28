#include <gtk/gtk.h>

static void slider_moved (GtkRange *range, gpointer user_data){
  GtkWidget *label = user_data;
  gdouble pos = gtk_range_get_value (range);
  gchar *str = g_strdup_printf ("%.0f", pos);
  gtk_label_set_text(GTK_LABEL (label), str);
  g_free(str);
}

static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *slider;
  GtkWidget *label;
  GtkWidget *grid;
  GtkWidget *adjustment;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "GPU-Based Scalable Plant Architecture Simulation");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
  gtk_container_set_border_width (GTK_CONTAINER (window), 5);

  label = gtk_label_new ("Water Level");
  adjustment = gtk_adjustment_new (0, 0, 100, 5, 10, 0);

  slider = gtk_scale_new (GTK_ORIENTATION_HORIZONTAL, adjustment);
  gtk_scale_set_digits(GTK_SCALE (slider), 0);

  //can expand if space

gtk_widget_set_hexpand (slider, TRUE);

g_signal_connect (slider, "value-changed", G_CALLBACK (slider_moved), label);

grid = gtk_grid_new();
gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
gtk_grid_set_column_homogeneous (GTK_GRID (grid), TRUE);
gtk_grid_attach (GTK_GRID (grid), slider, 0, 0, 1, 1);
gtk_grid_attach (GTK_GRID (grid), label, 1, 1, 1, 1);

gtk_container_add (GTK_CONTAINER (window), grid);

gtk_widget_show_all(window);

}

int main(int argc, char **argv){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

return status;
}
