#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "iqa.h"
#include <locale.h>


//Para receber os valores
double eO2,eCF,ePH,eDBO,eDT,eNT,eFT,eTU,eRT;
double psO2,psCF,psPH,psDBO,psDT,psNT,psFT,psTU,psRT;
// Para enviar as estruturas
IQA_L v;
IQA_P pe;
//Para retornar valores
char *iqastring;

GtkWidget *janela,*calcular,*lO2,*tO2,*lCF,*tCF,*lPH,*tPH,*lDBO,*tDBO,*lFT,*tFT,*lNT,*tNT,*lTU,*tTU,*lDT,*tDT,*lST,*tST,*lestado,*testado,*sobre,*tabela,*lvalor,*tvalor;
GtkWidget *pO2,*pCF,*pPH,*pDBO,*pFT,*pNT,*pTU,*pDT,*pST;
GtkWidget *messagedialog;

GtkAdjustment *adjustment1,*adjustment2,*adjustment3,*adjustment4,*adjustment5,*adjustment6,*adjustment7,*adjustment8,*adjustment9;
GtkAdjustment *adjustmentp1,*adjustmentp2,*adjustmentp3,*adjustmentp4,*adjustmentp5,*adjustmentp6,*adjustmentp7,*adjustmentp8,*adjustmentp9;

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

// Recebe Peso O2
void PO2(GtkButton *calcular, GtkEntry *valor ){
  psO2 = atof(gtk_entry_get_text(valor));

}

// Recebe Peso CF
void PCF(GtkButton *calcular, GtkEntry *valor){
  psCF = atof(gtk_entry_get_text(valor));
}

//Recebe Peso PH
void PPH(GtkButton *calcular, GtkEntry *valor ){
  psPH = atof(gtk_entry_get_text(valor));
}
//Recebe Peso DBO
void PDBO(GtkButton *calcular, GtkEntry *valor ){
  psDBO = atof(gtk_entry_get_text(valor));
}
//Recebe peso Temperatura
void PDT(GtkButton *calcular, GtkEntry *valor ){
  psDT = atof(gtk_entry_get_text(valor));
}
//Recebe peso NT
void PNT(GtkButton *calcular, GtkEntry *valor ){
  psNT = atof(gtk_entry_get_text(valor));
}
//Recebe peso FT
void PFT(GtkButton *calcular, GtkEntry *valor ){
  psFT = atof(gtk_entry_get_text(valor));
}
//Recebe peso TU
void PTU(GtkButton *calcular, GtkEntry *valor ){
  psTU = atof(gtk_entry_get_text(valor));
}
//Recebe peso RT
void PRT(GtkButton *calcular, GtkEntry *valor ){
  psRT = atof(gtk_entry_get_text(valor));
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
pe.pO2 = psO2;
pe.pCF = psCF;
pe.pPH = psPH;
pe.pDBO = psDBO;
pe.pDT = psDT;
pe.pNT = psNT;
pe.pFT = psFT;
pe.pTU = psTU;
pe.pST = psRT;
val = iqa(v,pe);
iqastring = iqa_state(val);
display = g_strdup_printf("%lf", val);

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
  adjustmentp1 = gtk_adjustment_new (O2_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp2 = gtk_adjustment_new (CF_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp3 = gtk_adjustment_new (PH_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp4 = gtk_adjustment_new (DBO_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp5 = gtk_adjustment_new (DT_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp6 = gtk_adjustment_new (NT_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp7 = gtk_adjustment_new (FT_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp8 = gtk_adjustment_new (TU_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);
  adjustmentp9 = gtk_adjustment_new (ST_PESO, 0.0, 10000000.0, 0.01, 0.1, 0.0);

  // Grid para tabela
  tabela = gtk_grid_new();
  gtk_grid_get_row_homogeneous (GTK_GRID (tabela));
  gtk_grid_set_row_spacing (GTK_GRID (tabela), 3);
  gtk_grid_set_column_spacing (GTK_GRID (tabela), 12);
  //Botões,Labels,ponto flutante...
  lO2 = gtk_label_new("Oxigênio Dissolvido: (% saturação)");
  tO2 = gtk_spin_button_new (adjustment1, 0.001, 4);
  pO2 = gtk_spin_button_new (adjustmentp1, 0.001, 2);
  lCF = gtk_label_new("Coliformes Fecais: (NMP/100mL)");
  tCF = gtk_spin_button_new (adjustment2, 0.001, 4);
  pCF = gtk_spin_button_new (adjustmentp2, 0.001, 2);
  lPH = gtk_label_new("Potencial Hidrogênico: (unidades de pH)");
  tPH = gtk_spin_button_new (adjustment3, 0.001, 4);
  pPH = gtk_spin_button_new (adjustmentp3, 0.001, 2);
  lDBO = gtk_label_new("Demanda Bioquímica de Oxigênio: (mg/L)");
  tDBO = gtk_spin_button_new (adjustment4, 0.001, 4);
  pDBO = gtk_spin_button_new (adjustmentp4, 0.001, 2);
  lDT = gtk_label_new("Temperatura: (°C)");
  tDT = gtk_spin_button_new (adjustment5, 0.001, 4);
  pDT = gtk_spin_button_new (adjustmentp5, 0.001, 2);
  lNT = gtk_label_new("Nitrogênio Total: (mg/L)");
  tNT = gtk_spin_button_new (adjustment6, 0.001, 4);
  pNT = gtk_spin_button_new (adjustmentp6, 0.001, 2);
  lFT = gtk_label_new("Fósforo Total: (mg/L)");
  tFT = gtk_spin_button_new (adjustment7, 0.001, 4);
  pFT = gtk_spin_button_new (adjustmentp7, 0.001, 2);
  lTU = gtk_label_new("Turbidez: (UNT)");
  tTU = gtk_spin_button_new (adjustment8, 0.001, 4);
  pTU = gtk_spin_button_new (adjustmentp8, 0.001, 2);
  lST = gtk_label_new("Resíduo Total: (mg/L)");
  tST = gtk_spin_button_new (adjustment9, 0.001, 4);
  pST = gtk_spin_button_new (adjustmentp9, 0.001, 2);
  lvalor = gtk_label_new("Valor IQA:");
  tvalor = gtk_entry_new();
  lestado = gtk_label_new("Classificação:");
  testado = gtk_entry_new();
  calcular = gtk_button_new_with_mnemonic("Calcular");
  sobre = gtk_button_new_with_mnemonic("Sobre...");
  // Posição, tamanho...
  gtk_grid_attach(GTK_GRID(tabela), lO2, 0,0,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tO2, 1,0,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pO2, 2,0,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lCF, 0,1,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tCF, 1,1,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pCF, 2,1,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lPH, 0,2,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tPH, 1,2,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pPH, 2,2,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lDBO, 0,3,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tDBO, 1,3,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pDBO, 2,3,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lDT, 0,4,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tDT, 1,4,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pDT, 2,4,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lNT, 0,5,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tNT, 1,5,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pNT, 2,5,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lFT, 0,6,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tFT, 1,6,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pFT, 2,6,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lTU, 0,7,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tTU, 1,7,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pTU, 2,7,1,1);
  gtk_grid_attach(GTK_GRID(tabela), lST, 0,8,1,1);
  gtk_grid_attach(GTK_GRID(tabela), tST, 1,8,1,1);
  gtk_grid_attach(GTK_GRID(tabela), pST, 2,8,1,1);
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
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PO2), pO2);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PCF), pCF);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PPH), pPH);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PDBO), pDBO);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PDT), pDT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PNT), pNT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PFT), pFT);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PTU), pTU);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(PRT), pST);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(Resultado), tvalor);
  g_signal_connect(G_OBJECT(calcular), "clicked", G_CALLBACK(Classificacao), testado);
  g_signal_connect(G_OBJECT(sobre), "clicked", G_CALLBACK(on_button_clicked), "NULL");
  gtk_main ();


  return 0;


}
