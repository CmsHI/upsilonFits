void PlotMass(bool trigg, int ntrigg,double miniPt, double maxiPt, string cut,string histoname,string label1,string label2, string label3 )
{
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();

  gROOT->LoadMacro("CMS_lumi.C");

  writeExtraText = true;       // if extra text
  extraText  = "Preliminary";  // default extra text is "Preliminary"
  lumi_13TeV = "";
  lumi_8TeV  = "19.1 fb^{-1}"; // default is "19.7 fb^{-1}"
  lumi_7TeV  = "4.9 fb^{-1}";  // default is "5.1 fb^{-1}"

  int iPeriod = 4;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 4=13TeV, 7=7+8+13TeV 

  // second parameter in example_plot is iPos, which drives the position of the CMS logo in the plot
  // iPos=11 : top-left, left-aligned
  // iPos=33 : top-right, right-aligned
  // iPos=22 : center, centered

  gROOT->LoadMacro("fit.C");
  example_plot( iPeriod, 33, trigg,ntrigg,miniPt,maxiPt,cut,histoname,label1,label2,label3 );   

}

TCanvas* example_plot( int iPeriod, int iPos, bool t, int nt,double miPt, double maPt,string c,string hname, string lbl1, string lbl2,string lbl3 )
{ 
  //  if( iPos==0 ) relPosX = 0.12;

  int W = 800;
  int H = 600;

  int H_ref = 600; 
  int W_ref = 800; 

  // references for T, B, L, R
  float T = 0.08*H_ref;
  float B = 0.12*H_ref; 
  float L = 0.12*W_ref;
  float R = 0.04*W_ref;

  TString canvName = "FigMass_";
  canvName += W;
  canvName += "_";
  canvName += H;
  canvName += "_";  
  canvName += iPeriod;
  if( writeExtraText ) canvName += "_prelim";
  if( iPos%10==0 ) canvName += "_out";
  else if( iPos%10==1 ) canvName += "_left";
  else if( iPos%10==2 )  canvName += "_center";
  else if( iPos%10==3 )  canvName += "_right";

  TCanvas* canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetLeftMargin( L/W );
  canv->SetRightMargin( R/W );
  canv->SetTopMargin( T/H );
  canv->SetBottomMargin( B/H );
  canv->SetTickx(0);
  canv->SetTicky(0);
 
  fit(4,t,nt,miPt,maPt,c);
//  fit(4,1,32,"Mass>8.6 && Mass<11.0 && TMath::Abs(EtaMuP)<1.2 && TMath::Abs(EtaMuM)<1.2 && Rapidity<1.2 ");
  
    {
    TLatex latex;

    int n_ = 3;
    float x1_l = 0.95;
    float y1_l = 0.70;

    float dx_l = 0.37;
    float dy_l = 0.23;
    float x0_l = x1_l-dx_l;
    float y0_l = y1_l-dy_l;

    TPad* legend = new TPad("legend_0","legend_0",x0_l,y0_l,x1_l, y1_l );
    //    legend->SetFillColor( kGray );
    legend->Draw();
    legend->cd();
    float gap_ = 1./(n_+1);
    float bwx_ = 0.12;

    x_l[0] = 1.2*bwx_;
    y_l[0] = 1-gap_;

    latex.SetTextFont(42);
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    latex.SetTextSize(0.20);
    latex.SetTextAlign(12);

    float xx_ = x_l[0];
    float yy_ = y_l[0];
    //latex.DrawLatex(xx_+1.*bwx_,yy_,"#sigma = 26.5 #pm 2.2 MeV");
    //latex.DrawLatex(xx_+1.*bwx_,yy_,"#sigma = 13 MeV");
//    latex.DrawLatex(xx_+0.5*bwx_,yy_,"#sqrt{f_{1}#sigma_{1}^{2}+f_{2}#sigma_{2}^{2}} = 110 MeV");
   latex.DrawLatex(xx_+0.5*bwx_,yy_,lbl1.c_str());
    yy_ -= gap_;
//    latex.DrawLatex(xx_+0.5*bwx_,yy_,"p_{T}^{#mu^{+}#mu^{-}} > 13 GeV");
    latex.DrawLatex(xx_+0.5*bwx_,yy_,lbl2.c_str());
    yy_ -= gap_;
    latex.DrawLatex(xx_+0.5*bwx_,yy_,lbl3.c_str());
   // latex.DrawLatex(xx_+1.*bwx_,yy_,"|#eta_{#mu}| < 0.5");

    canv->cd();
  }
  // writing the lumi information and the CMS "logo"
  CMS_lumi( canv, iPeriod, iPos );

  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();

  string hn="Plots/"+hname+".pdf";
  string hnpng ="Plots/"+hname+".png";
  canv->SaveAs(hn.c_str());
  canv->SaveAs(hnpng.c_str());
//  canv->Print(hname+".png",".png");

  return canv;
}
