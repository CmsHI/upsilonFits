#define newTree_cxx
#include "newTree.h"

#include <TStyle.h>
#include "TMath.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TPaveStats.h"
#include "TH1.h"
#include "TF1.h"
#include "TLegend.h"

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooCategory.h"
#include "RooAbsPdf.h"
#include "RooResolutionModel.h"
#include "RooFitResult.h"
#include "RooDataSet.h"
#include "RooGlobalFunc.h"
#include "RooProdPdf.h"
#include "RooGaussian.h"
#include "RooAddPdf.h"
#include "RooPlot.h"
#include "RooGaussModel.h"
#include "RooTruthModel.h"
#include "RooLandau.h"
#include "RooProdPdf.h"
#include "RooChebychev.h"
#include "RooExponential.h"
#include "RooDecay.h"
#include "RooPolynomial.h"
#include "RooGenericPdf.h"
#include "RooHistPdf.h"
#include "RooHist.h"
#include "RooWorkspace.h"
#include "RooDataHist.h"
#include "RooKeysPdf.h"
#include "RooNDKeysPdf.h"
#include "RooCBShape.h"
#include "TLatex.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
using namespace RooFit;

void fit(int ncpu=4,bool trig=0,int ntrig=4, double minPt=0, double maxPt=150, string cuts=" ")
{

  TChain *tree = new TChain("rootuple/oniaTree");
  tree->Add("/higgs/raid/garamire/CMS/Upsilon/dataTrees/rootuple-Run2015B-MuOnia-lumi.root");
  newTree *Tree = new newTree(tree);
  Long64_t nevent = Tree->fChain->GetEntries();
  cout << "MC loaded: " << nevent << " candidates" << endl;
  double minMass=8.6;
  double maxMass=11.5;
  double minPtP;
  double minPtN;
  double nbins=145;

//Fit parameters
  //Upsilon widths
  RooRealVar pdgups1s("pdgups1s","mass Y1S PDG", 9.46030);
  RooRealVar pdgups2s("pdgups2s","mass Y2S PDG",10.02326);
  RooRealVar pdgups3s("pdgups3s","mass Y3S PDG",10.35520);

  RooFormulaVar ratio2to1("ratio2to1","@0/@1",RooArgList(pdgups2s,pdgups1s));
  RooFormulaVar ratio3to1("ratio3to1","@0/@1",RooArgList(pdgups3s,pdgups1s));

  RooRealVar ups1swidth("ups1swidth","#upsilon 1s width", 0.);
  RooFormulaVar ups2swidth("ups2swidth","@0*@1",RooArgList(ups1swidth,ratio2to1));
  RooFormulaVar ups3swidth("ups3swidth","@0*@1",RooArgList(ups1swidth,ratio3to1));

  //Upsilons masses
 
  RooRealVar scalemass("scalemass","global scale factor for upsilons masses", 0.);
  RooFormulaVar ups1smean("ups1smean","@0*@1",RooArgList(scalemass,pdgups1s));
  RooFormulaVar ups2smean("ups2smean","@0*@1",RooArgList(scalemass,pdgups2s));
  RooFormulaVar ups3smean("ups3smean","@0*@1",RooArgList(scalemass,pdgups3s));

  // Additional signal parameters
  RooRealVar alpha("alpha","alpha", 0.,0.,5.);
  RooRealVar n("n","n", 0.);
  RooRealVar cb1frac1S("cb1frac1S","cb1frac1S",0.);
  //RooRealVar cb1frac2S("cb1frac2S","cb1frac2S",.1,0,1.);
  //RooRealVar cb1frac3S("cb1frac3S","cb1frac3S",.1,0,1.);


  //Background coefficients.
  RooRealVar c0("c0","coefficient #0",0.) ;
  RooRealVar c1("c1","coefficient #1",0.);

  //yields
  RooRealVar nups1("nups1", "Number of #upsilon(1s) cadidates", 0.);
  RooRealVar nups2("nups2", "Number of #upsilon(2s) cadidates", 0.);
  RooRealVar nups3("nups3", "Number of #upsilon(3s) cadidates", 0.);
  RooRealVar nbkg("nbkg", "Number of bkg cadidates", 0.);


//Data
  TLorentzVector JPsi;
  RooRealVar* Mass = new RooRealVar("Mass", "m_{#mu^{+} #mu^{-}} (GeV)",minMass,maxMass);
  RooRealVar* Pt   = new RooRealVar("Pt","Pt (GeV/c)",10, 120);
  RooRealVar* EtaMuM  = new RooRealVar("EtaMuM","Eta_muM",-10,10);
  RooRealVar* EtaMuP  = new RooRealVar("EtaMuP","Eta_muP",-10,10);
  RooRealVar* Rapidity = new RooRealVar("Rapidity","Rapidity",-10,10);

  RooDataSet* data = new RooDataSet("data","data",RooArgSet(*Mass,*Pt,*EtaMuP,*EtaMuM,*Rapidity));
//PDFs
  //Signal Pdf

  //CB model.

  RooCBShape ups1s("ups1s", "#upsilon(1s) Pdf",*Mass,ups1smean,ups1swidth,alpha,n);
  RooCBShape ups2s("ups2s", "#upsilon(2s) Pdf",*Mass,ups2smean,ups2swidth,alpha,n);
  RooCBShape ups3s("ups3s", "#upsilon(3s) Pdf",*Mass,ups3smean,ups1swidth,alpha,n);

   //Background Pdf
  RooChebychev bkgpol("bkgpol","background p.d.f.",*Mass,RooArgList(c0,c1)) ; 

  //
  RooAddPdf model("model", "Tree peaks model", RooArgList(ups1s,ups2s,ups3s,bkgpol),RooArgList(nups1,nups2,nups3,nbkg));
  RooArgSet* params = model.getParameters(*Mass);
  params->readFromFile("param-test.txt","READ","test");
  params->Print("v"); 
  for (Long64_t i=0;i< nevent;i++) {
    Tree->GetEntry(i);
    TLorentzVector* dimuon = Tree->dimuon_p4;    
    TLorentzVector* muonP = Tree->muonP_p4;
    TLorentzVector* muonN = Tree->muonN_p4;

    UInt_t Trigger = Tree->trigger;
    Int_t Charge = Tree->charge;
    Float_t VProb = Tree->vProb;
    *Mass = dimuon->M();
    *Pt = dimuon->Pt();
    *Rapidity = dimuon->Rapidity();
    *EtaMuM = muonN->Eta();
    *EtaMuP = muonP->Eta();
    
    if(ntrig == 4){
      if(muonP->Pt() > muonN->Pt()){
        minPtP = 11.;
        minPtN = 3.5;
      }
      else{
        minPtP = 3.5;
        minPtN = 11.;
      }
    }
    else if(ntrig == 32){
      minPtP= 3.5;
      minPtN= 3.5;
    }

    if (dimuon->M() > minMass && dimuon->M()<maxMass && TMath::Abs(dimuon->Rapidity())<2.4 && TMath::Abs(muonP->Eta())< 2.4 && TMath::Abs(muonN->Eta()) < 2.4 && VProb > 0.005 && Charge == 0){          
    
    if (trig==1 && Trigger & ntrig && dimuon->Pt() > minPt && dimuon->Pt() < maxPt && muonP->Pt() > minPtP && muonN->Pt() > minPtN) data->add(RooArgSet(*Mass,*Pt,*EtaMuP,*EtaMuM,*Rapidity));
       
    
    else if (!trig==1 && dimuon->Pt()>minPt && dimuon->Pt()<maxPt ) {data->add(RooArgSet(*Mass,*Pt,*EtaMuP,*EtaMuM,*Rapidity));} 
    }
  }
  RooDataSet* dataReduced = data->reduce(RooArgSet(*Mass),cuts.c_str());

  n.setConstant(kTRUE);
  //alpha.setConstant(kTRUE);
  //c0.setConstant(kTRUE);
  //c1.setConstant(kTRUE);
  //nups1.setConstant(kTRUE);
  //nups2.setConstant(kTRUE);
  //nups3.setConstant(kTRUE);
  //scalemass.setConstant(kTRUE);
  //ups1swidth.setConstant(kTRUE);


//  RooFitResult* r = model.fitTo(*dataReduced,Minos(kTRUE),Extended(),Save());
  RooFitResult* r = model.fitTo(*dataReduced,Minos(kTRUE),Extended(),Range(minMass,maxMass),NumCPU(ncpu), Timer(),Save());
  r->Print();

  RooPlot* Mframe = Mass->frame(Bins(nbins),Title(" "));
  //dataReduced->plotOn(Mframe,MarkerSize(0.5),XErrorSize(0),RooFit::Name("dataReduced"));
  dataReduced->plotOn(Mframe,RooFit::Name("dataReduced"));
   model.plotOn(Mframe,LineWidth(2),RooFit::Name("model"));

  Double_t chi2 = Mframe->chiSquare("model","dataReduced",10);
  cout<< chi2<<"   "<<cuts.c_str()<<"   "<<trig<<"   "<<ntrig<<"   "<<minPt<<"  "<<maxPt<<"\n";

  RooHist* hpull = Mframe->pullHist();
  RooPlot* Pframe = Mass->frame(Range(minMass,maxMass));
  model.plotOn(Mframe,Components(RooArgSet(ups1s,ups2s,ups3s)),LineStyle(kDashed),LineColor(kGreen),LineWidth(2));
  model.plotOn(Mframe,Components(bkgpol),LineStyle(kDashed),LineColor(kRed),LineWidth(2));

  Pframe->addPlotable(hpull,"P");
  TPad* pullPad = new TPad("pullPad","pullPad",0.005,0.05,0.95,0.35);
  TPad* fitPad = new TPad("fitPad","fitPad",0.005,0.35,0.95,0.95);
  pullPad->Draw();
  fitPad->Draw();
  fitPad->cd();
  Mframe->SetTitle("");
  Mframe->GetXaxis()->SetTitle("#mu^{+}#mu^{-} invariant mass [GeV]");
  Mframe->GetXaxis()->SetLabelFont(42);
  Mframe->GetXaxis()->SetLabelOffset(0.002);
  Mframe->GetXaxis()->SetTitleSize(0.055);
  Mframe->GetXaxis()->SetTitleOffset(0.9);
  Mframe->GetXaxis()->SetLabelFont(42);
  Mframe->GetXaxis()->SetLabelSize(0.045);
  Mframe->GetXaxis()->SetTitleFont(42);
  Mframe->GetYaxis()->SetTitle("Events / 20 MeV");
  Mframe->GetYaxis()->SetLabelFont(42);
  Mframe->GetYaxis()->SetLabelOffset(0.004);
  Mframe->GetYaxis()->SetTitleOffset(1.0);
  Mframe->GetYaxis()->SetTitleSize(0.055);
  Mframe->GetYaxis()->SetTitleFont(42);
  Mframe->GetYaxis()->SetLabelFont(42);
  Mframe->GetYaxis()->SetLabelSize(0.045);
  Mframe->Draw();
  
  pullPad->cd();
  Pframe->SetTitle("");
  Pframe->GetXaxis()->SetTitle("#mu^{+}#mu^{-} invariant mass [GeV]");
  Pframe->GetXaxis()->SetLabelFont(42);
  Pframe->GetXaxis()->SetLabelOffset(0.002);
  Pframe->GetXaxis()->SetTitleSize(0.06);
  Pframe->GetXaxis()->SetTitleOffset(0.9);
  Pframe->GetXaxis()->SetLabelFont(42);
  Pframe->GetXaxis()->SetLabelSize(0.045);
  Pframe->GetXaxis()->SetTitleFont(42);
  Pframe->GetYaxis()->SetTitle("Events / 20 MeV");
  Pframe->GetYaxis()->SetLabelFont(42);
  Pframe->GetYaxis()->SetLabelOffset(0.004);
  Pframe->GetYaxis()->SetTitleOffset(.3);
  Pframe->GetYaxis()->SetTitleSize(0.1);
  Pframe->GetYaxis()->SetTitleFont(42);
  Pframe->GetYaxis()->SetLabelFont(42);
  Pframe->GetYaxis()->SetLabelSize(0.045);
  Pframe->Draw();
    
  fitPad->cd();
  ofstream myfile1s;
  myfile1s.open ("Results1s.dat", ios::out | ios::app);
  myfile1s << (minPt+maxPt)/2 << ", " << nups1->getVal() << ", "  << (maxPt-minPt)/2 << ", " << nups1->getError()  << "\n";
  myfile1s.close(); 
  
  ofstream myfile2s;
  myfile2s.open ("Results2s.dat", ios::out | ios::app);
  myfile2s << (minPt+maxPt)/2 << ", " << nups2->getVal() << ", "  << (maxPt-minPt)/2 << ", " << nups2->getError()  << "\n";
  myfile2s.close();

  ofstream myfile3s;
  myfile3s.open ("Results3s.dat", ios::out | ios::app);
  myfile3s << (minPt+maxPt)/2 << ", " << nups3->getVal() << ", "  << (maxPt-minPt)/2 << ", " << nups3->getError()  << "\n";
  myfile3s.close();

  ofstream myfileStat;
  myfileStat.open ("Status.dat", ios::out | ios::app);
  myfileStat << (minPt+maxPt)/2 << " Status: "<< r->statusLabelHistory(0) << " " << r->statusCodeHistory(0) << ", "<< r->statusLabelHistory(1) << " " << r->statusCodeHistory(1)<<", "<< r->statusLabelHistory(2) << " " << r->statusCodeHistory(2)<< "\n";
  myfileStat.close();
  return;
}
