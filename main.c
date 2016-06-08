#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "iqa.h"
#include <locale.h>


//Para receber os valores
double eO2,eCF,ePH,eDBO,eDT,eNT,eFT,eTU,eRT;
// Para enviar a estruturas
IQA_L v;
//Para retornar valores
char *iqastring;

GtkWidget *janela,*calcular,*lO2,*tO2,*lCF,*tCF,*lPH,*tPH,*lDBO,*tDBO,*lFT,*tFT,*lNT,*tNT,*lTU,*tTU,*lDT,*tDT,*lST,*tST,*lestado,*testado,*sobre,*tabela,*lvalor,*tvalor;
GtkWidget *messagedialog;

GtkAdjustment *adjustment1,*adjustment2,*adjustment3,*adjustment4,*adjustment5,*adjustment6,*adjustment7,*adjustment8,*adjustment9;

// Recebe O2
void cO2(GtkButton *calcular, GtkEntry *valor ){
  eO2 = atof(gtk_entry_get_text(valor));

}
// Recebe CF
void cCF(GtkButton *calcular, GtkEntry *valor){
  eCF = atof(gtk_entry_get_text(valor));
}
//Recebe PH
void cPH(GtkButton *calcular, GtkEntry *valor ){
  ePH = atof(gtk_entry_get_text(valor));
}
//Recebe DBO
void cDBO(GtkButton *calcular, GtkEntry *valor ){
  eDBO = atof(gtk_entry_get_text(valor));
}
//Recebe Temperatura
void cDT(GtkButton *calcular, GtkEntry *valor ){
  eDT = atof(gtk_entry_get_text(valor));
}
//Recebe NT
void cNT(GtkButton *calcular, GtkEntry *valor ){
  eNT = atof(gtk_entry_get_text(valor));
}
//Recebe FT
void cFT(GtkButton *calcular, GtkEntry *valor ){
  eFT = atof(gtk_entry_get_text(valor));
}
//Recebe TU
void cTU(GtkButton *calcular, GtkEntry *valor ){
  eTU = atof(gtk_entry_get_text(valor));
}
//Recebe RT
void cRT(GtkButton *calcular, GtkEntry *valor ){
eRT = atof(gtk_entry_get_text(valor));
}
//Resultado a receber
void Resultado(GtkButton *calcular, GtkEntry *valor)
{
  gchar *display;
double val;
v.O2 = eO2;
v.CF = eCF;
v.PH = ePH;
v.DBO = eDBO;
v.DT = eDT;
v.NT = eNT;
v.FT = eFT;
v.TU = eTU;
v.ST = eRT;
val = iqa(v);
display = g_strdup_printf("%lf", val);
iqastring = iqa_state(val);
gtk_entry_set_text (GTK_ENTRY(valor), display);
g_free(display);
g_print("%lf\n",val);
}

//Autor
static void on_button_clicked(GtkWidget *button, gchar* message)
{
    gchar *text = "Criado por: \n\n Saulo Henrique de Castro";
    gchar *sobre = "Sobre...";
    messagedialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,"%s",text);
    gtk_window_set_title(GTK_WINDOW(messagedialog), sobre);
    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}
//Recebe a qualidade
void Classificacao(GtkButton *calcular, GtkEntry *valor)
{

gchar *display;
display = g_strdup_printf("%s", iqastring);
gtk_entry_set_text (GTK_ENTRY(valor), display);
g_free(display);
}

//Botão Spin
gfloat grab_float_value (GtkSpinButton *button, gpointer user_data)
{
  return gtk_spin_button_get_value (button);
}


// Fechar
void sair(GtkWidget *widget, gpointer data) {

g_print("Saindo...\n");
gtk_main_quit();

}

int main (int argc,  char **argv)
{
  gtk_init(&argc,&argv);
  janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW (janela),"Indice de Qualidade Àgua(IQA)");
  g_signal_connect (G_OBJECT (janela), "delete_event",G_CALLBACK (sair), NULL);
  adjustment1 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment2 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment3 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment4 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment5 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment6 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment7 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment8 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
  adjustment9 = gtk_adjustment_new (0.0, 0.0, 10000000.0, 0.001, 0.1, 0.0);
// Grid para tabela
  tabela = gtk_grid_new();
  gtk_grid_get_row_homogeneous (GTK_GRID (tabela));
  gtk_grid_set_row_spacing (GTK_GRID (tabela), 2);
  gtk_grid_set_column_spacing (GTK_GRID (tabela), 12);
  //Botões e Labels
  lO2 = gtk_label_new("Oxigênio Dissolvido: (% saturação)");
  tO2 = gtk_spin_button_new (adjustment1, 0.001, 4);
  lCF = gtk_label_new("Coliformes Fecais: (NMP/100mL)");
  tCF = gtk_spin_button_new (adjustment2, 0.001, 4);
  lPH = gtk_label_new("Potencial Hidrogênico: (unidades de pH)");
  tPH = gtk_spin_button_new (adjustment3, 0.001, 4);
  lDBO = gtk_label_new("Demanda Bioquímica de Oxigênio: (mg/L)");
  tDBO = gtk_spin_button_new (adjustment4, 0.001, 4);
  lDT = gtk_label_new("Temperatura: (°C)");
  tDT = gtk_spin_button_new (adjustment5, 0.001, 4);
  lNT = gtk_label_new("Nitrogênio Total: (mg/L)");
  tNT = gtk_spin_button_new (adjustment6, 0.001, 4);
  lFT = gtk_label_new("Fósforo Total: (mg/L)");
  tFT = gtk_spin_button_new (adjustment7, 0.001, 4);
  lTU = gtk_label_new("Turbidez: (UNT)");
  tTU = gtk_spin_button_new (adjustment8, 0.001, 4);
  lST = gtk_label_new("Resíduo Total: (mg/L)");
  tST = gtk_spin_button_new (adjustment9, 0.001, 4);
  lvalor = gtk_label_new("Valor IQA:");
  tvalor = gtk_entry_new();
  lestado = gtk_label_new("Classificação:");
  testado = gtk_entry_new();
  calcular = gtk_button_new_with_mnemonic("Calcular");
  sobre = gtk_button_new_with_mnemonic("Sobre...");
  // Posição, tamanho...
  gtk_grid_attach(GTK_GRID(tabela), lO2, 0,0,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tO2, 1,0,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lCF, 0,1,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tCF, 1,1,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lPH, 0,2,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tPH, 1,2,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lDBO, 0,3,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tDBO, 1,3,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lDT, 0,4,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tDT, 1,4,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lNT, 0,5,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tNT, 1,5,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lFT, 0,6,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tFT, 1,6,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lTU, 0,7,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tTU, 1,7,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lST, 0,8,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tST, 1,8,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lvalor, 0,9,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tvalor, 1,9,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lestado, 0,10,1,1);
  gtk_grid_attach(GTK_GRID(tabela), testado, 1,10,1,1);
  gtk_grid_attach(GTK_GRID(tabela), calcular, 0,11,1,1);
  gtk_grid_attach(GTK_GRID(tabela), sobre, 1,11,1,1);
  gtk_container_add(GTK_CONTAINER(janela), tabela);
  gtk_widget_show_all(janela);
  // Para funções receberem os valores
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cO2), tO2);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cCF), tCF);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cPH), tPH);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cDBO), tDBO);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cDT), tDT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cNT), tNT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cFT), tFT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cTU), tTU);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(cRT), tST);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(Resultado), tvalor);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(Classificacao), testado);
  g_signal_connect(G_OBJECT(sobre), "clicked", G_CALLBACK(on_button_clicked), "NULL");
  gtk_main ();


  return 0;


}
