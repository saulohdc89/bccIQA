#include <math.h>
#include <string.h>
#include "iqa.h"
#include <locale.h>

// Define dos Status
#define OTIMO_M 100.00
#define OTIMO_P 80.00
#define BOM_M 79.99
#define BOM_P 51.00
#define ACEITAVEL_M 50.99
#define ACEITAVEL_P 37.00
#define RUIM_M 36.99
#define RUIM_P 20.00
#define PESSIMO_M 19.99
#define PESSIMO_P 0

double iqa(IQA_L t,IQA_P pe){
  double p = 1;

  p *= pow(fO2(t.O2), pe.pO2);
  p *= pow(fCF(t.CF), pe.pCF);
  p *= pow(fPH(t.PH),  pe.pPH);
  p *= pow(fDBO(t.DBO), pe.pDBO);
	p *= pow(fDT(t.DT),  pe.pDT);
	p *= pow(fNT(t.NT),  pe.pNT);
	p *= pow(fFT(t.FT),  pe.pFT);
	p *= pow(fTU(t.TU),  pe.pTU);
	p *= pow(fST(t.ST),  pe.pST);
  return p;
}
// Converte o IQAState para string
char* iqa_state(double iqa_v)
{
  // Para aceitar caracteres em português
  setlocale(LC_ALL, "Portuguese");

  if (iqa_v <= PESSIMO_P)
  return "Péssima";
	if (iqa_v >= OTIMO_M)
  return "Òtima";
	if (iqa_v > PESSIMO_P && iqa_v < PESSIMO_M)
  return "Péssima";
	if (iqa_v > RUIM_P   && iqa_v < RUIM_M)
  return "Ruim";
	if (iqa_v > ACEITAVEL_P    && iqa_v < ACEITAVEL_M)
  return "Aceitável";
	if (iqa_v > BOM_P  && iqa_v < BOM_M)
  return "Bom";
	if (iqa_v > OTIMO_P  && iqa_v < OTIMO_M)
  return "Ótima";
}


// Equação ajustada à curva do parâmetro O2

double fO2 ( double O2 ) {
    if ( O2 > 140.0 )
    	return 47.0;

    return O2_PAR_A * exp(pow( (O2 + O2_PAR_B), 2 ) / O2_PAR_C);
}
// Equação ajustada à curva do parâmetro CF

double fCF (double CF)
{
	if (CF > 100000)
  return 3.0;

  CF = CF_PAR_A + ( CF_PAR_B * log10(CF)) + ( CF_PAR_C * pow( log10(CF), 2 )) + (CF_PAR_D * pow( log10(CF), 3 ));

	return CF;
}
// Equação ajustada à curva do parâmetro PH
double fPH (double PH)
{
	if (PH > 12)
  return 3.0;
	if (PH < 2)
  return 2.0;

	return PH_PAR_A  * pow(PH, ((PH_PAR_B*PH) + (PH_PAR_C*pow(PH,2)))) + 5.213;
}

// Equação ajustada à curva do parâmetro DBO
double fDBO (double DBO)
{
	if (DBO > 30)
  return 2.0;

	return  DBO_PAR_A * exp((DBO_PAR_B * DBO));
}

// Equação ajustada à curva do parâmetro FT
double fFT (double FT)
{
	if (FT > 10)
  return 5.0;

	return  FT_PAR_A * exp((FT_PAR_B*pow(FT, FT_PAR_C)));
}

// Equação ajustada à curva do parâmetro NT
double fNT (double NT)
{
	if (NT > 100)
  return 1.0;

	return NT_PAR_A * pow(NT, NT_PAR_B + NT_PAR_C * NT);
}

// Equação ajustada à curva do parâmetro TU
double fTU (double TU)
{
	if (TU > 100)
  return 5.0;

	return  TU_PAR_A * exp((TU_PAR_B * TU) + (TU_PAR_C*sqrt(TU)));
}

// Equação ajustada à curva do parâmetro DT
double fDT (double DT)
{
	if (DT > 15)
  return 9.0;

	return (1 / (DT_PAR_A * pow(DT + DT_PAR_B, 2) + DT_PAR_C));
}

// Equação ajustada à curva do parâmetro ST
double fST (double ST)
{
	if (ST > 500)
  return 32.0;

	return (ST_PAR_A * exp( (ST_PAR_B*ST) + (ST_PAR_C*sqrt(ST)))) + (ST_PAR_D * ST );
}
