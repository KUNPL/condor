#include "TFile.h"
#include "TH1D.h"
#include "TRandom.h"

void random_gaus(Double_t mean=0, Double_t sigma=1)
{
  TFile* file = new TFile("random_gaus.root","recreate");
  TH1D* hist = new TH1D("hist","",100,-5,5);
  for(Int_t i=0; i<10000; i++) hist -> Fill(gRandom->Gaus(mean, sigma));
  hist -> Write();
}
