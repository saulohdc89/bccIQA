#ifndef IQA_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define IQA_H

//Pesos dos parametros
#define O2_PESO 0.17
#define CF_PESO 0.15
#define PH_PESO 0.12
#define DBO_PESO 0.10
#define DT_PESO 0.10
#define NT_PESO 0.10
#define FT_PESO 0.10
#define TU_PESO 0.08
#define ST_PESO 0.08

//Parâmetros Ajustados para equação do oxigênio dissolvio
#define O2_PAR_A 100.8
#define O2_PAR_B -106
#define O2_PAR_C -3745

//Parâmetros Ajustados para equação dos Coliformes Fecais
#define CF_PAR_A 98.03
#define CF_PAR_B -36.45
#define CF_PAR_C 3.138
#define CF_PAR_D 0.06776

//Parâmetros Ajustados para equação do pH
#define PH_PAR_A 0.05421
#define PH_PAR_B 1.23
#define PH_PAR_C -0.09873

//Parâmetros Ajustados para equação do DBO (Demanda Bioquímica de Oxigênio)
#define DBO_PAR_A 102.6
#define DBO_PAR_B -0.1101

//Parâmetros Ajustados para equação do Fósforo Total
#define FT_PAR_A 213.7
#define FT_PAR_B -1.680
#define FT_PAR_C 0.3325

//Parâmetros Ajustados para equação do Nitrogênio Total
#define NT_PAR_A 98.96
#define NT_PAR_B -0.2232
#define NT_PAR_C -0.006457

//Parâmetros Ajustados para equação da Turbidez
#define TU_PAR_A 97.34
#define TU_PAR_B -0.01139
#define TU_PAR_C -0.04917

//Parâmetros Ajustados para equação da Temperatura
#define DT_PAR_A 0.0003869
#define DT_PAR_B 0.1815
#define DT_PAR_C 0.01081

//Parâmetros Ajustados para equação dos Resíduo Totais
#define ST_PAR_A 80.26
#define ST_PAR_B -0.00107
#define ST_PAR_C 0.03009
#define ST_PAR_D -0.1185

//Estrutura para carregar os dados de uma medição
typedef struct{
  double O2;
	double CF;
	double PH;
	double DBO;
	double DT;
	double NT;
	double FT;
	double TU;
	double ST;
} IQA_L;

typedef struct{
  double pO2;
	double pCF;
	double pPH;
	double pDBO;
	double pDT;
	double pNT;
	double pFT;
	double pTU;
	double pST;
} IQA_P;


// Definição das funções de cada um dos parâmetros utilizados
double fO2  (double);
double fCF  (double);
double fPH  (double);
double fDBO (double);
double fFT  (double);
double fNT  (double);
double fTU  (double);
double fDT  (double);
double fST  (double);


//Funções pré-definidas no Header
double iqa(IQA_L,IQA_P);
char* iqa_state(double iqa_v);
#endif
