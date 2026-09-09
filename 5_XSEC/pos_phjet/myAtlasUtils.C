/*
  Moving to root 6
*/

#include <iostream>
#include <cmath>

#include "AtlasUtils.h"

#include "TLatex.h"
#include "TMarker.h"
#include "TLine.h"
#include "TPave.h"
#include "TH1.h"

TColor *color1 = new TColor(232, 0.04, 0.32, 0.46); // steelblue
TColor *color2 = new TColor(237, 1.00, 0.40, 0.80); // redviolet
TColor *color3 = new TColor(161, 0.00, 1.00, 0.50); // emerald
TColor *color4 = new TColor(131, 0.90, 0.00, 0.20); // reddd
TColor *color5 = new TColor(132, 0.14, 0.42, 0.56); // steelblue
TColor *color6 = new TColor(151, 1.00, 0.11, 0.68); // spicypink
TColor *color7 = new TColor(141, 0.14, 0.56, 0.42); // seagreen
TColor *color8 = new TColor(133, 0.81, 0.71, 0.23); // oldgold
TColor *color9 = new TColor(134, 0.56, 0.14, 0.14); // mahogany
TColor *color10 = new TColor(135, 1.00, 0.00, 0.50); // wildstrawberry
TColor *color11 = new TColor(136, 1.00, 0.51, 0.07); // burntorange
TColor *color12 = new TColor(137, 0.80, 0.20, 0.60); // redviolet
TColor *color13 = new TColor(138, 1.00, 0.51, 0.46); // salmon
TColor *color14 = new TColor(139, 0.18, 0.31, 0.31); // darkslategrey
TColor *color15 = new TColor(140, 0.50, 0.02, 0.25); // wine
TColor *color16 = new TColor(142, 0.56, 0.42, 0.14); // sienna
TColor *color17 = new TColor(143, 0.40, 0.40, 0.80); // ncadetblue
TColor *color18 = new TColor(144, 0.72, 0.45, 0.20); // copper
TColor *color19 = new TColor(145, 0.55, 0.09, 0.09); // scarlet
TColor *color20 = new TColor(146, 0.156, 0.196, 0.705); // aquamarine
TColor *color21 = new TColor(147, 0.31, 0.18, 0.18); // indian
TColor *color22 = new TColor(148, 0.90, 0.00, 0.80); // npurple
TColor *color23 = new TColor(150, 0.55, 0.27, 0.07); // saddlebrown
TColor *color24 = new TColor(152, 0.98, 0.88, 0.70); // nwheat
TColor *color25 = new TColor(149, 0.37, 0.28, 0.55); // mediumpurple
TColor *color26 = new TColor(249, 1.00, 1.00, 1.00); // white
TColor *color27 = new TColor(153, 1.00, 1.00, 0.00); // yellow
TColor *color28 = new TColor(154, 0.00, 1.00, 0.00); // green
TColor *color29 = new TColor(155, 0.59, 0.98, 0.59); // green4
TColor *color30 = new TColor(156, 0.80, 0.80, 0.80); // grey
TColor *color31 = new TColor(157, 0.00, 1.00, 1.00); // cyan
TColor *color32 = new TColor(158, 0.5, 0.5, 1.0); // aquamarine 2
TColor *color33 = new TColor(159, 0.60, 0.60, 0.60); // grey 2
TColor *color34 = new TColor(160, 0.00, 0.31, 0.15); // green
TColor *color35 = new TColor(162, 0.90, 0.90, 0.10); // yellow pale
TColor *color36 = new TColor(163, 0.00, 0.60, 0.275); // green

void myhhdate_custom(TH1 *hh,const char *opt,float ms,int color,int st,float wd,int ls,int lc)
{
  hh->SetMarkerSize(ms);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->SetLineWidth(wd);
  hh->SetLineStyle(ls);
  hh->SetLineColor(lc);
  hh->SetFillColor(color);
  hh->Draw(opt);
}

void myggdate(TGraphErrors *gg,const char *opt,float ms,int color,int st,float wd,int ls,int lc)
{
  gg->SetMarkerSize(ms);
  gg->SetMarkerColor(color);
  gg->SetMarkerStyle(st);
  gg->SetLineWidth(wd);
  gg->SetLineStyle(ls);
  gg->SetLineColor(lc);
  gg->SetFillColor(color);
  gg->Draw(opt);
}

void myhhprof(TProfile *hh,const char *opt,float ms,int color,int st,float wd,int ls,int lc)
{
  hh->SetMarkerSize(ms);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->SetLineWidth(wd);
  hh->SetLineStyle(ls);
  hh->SetLineColor(lc);
  hh->SetFillColor(color);
  hh->Draw(opt);
}

void myhhdate(TH1 *hh,const char *opt,float ms,int color,int st,float wd,int ls,int lc,int fills,int color2)
{
  hh->SetMarkerSize(ms);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->SetLineWidth(wd);
  hh->SetLineStyle(ls);
  hh->SetLineColor(lc);
  hh->SetFillStyle(fills);
  hh->SetFillColor(color2);
  hh->Draw(opt);
}

void myhhdate_tr(TH1 *hh,const char *opt,float ms,int color,int st,float wd,int ls,int lc,int fills,int color2)
{
  hh->SetMarkerSize(ms);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->SetLineWidth(wd);
  hh->SetLineStyle(ls);
  hh->SetLineColor(lc);
  hh->SetFillStyle(fills);
  hh->SetFillColor(color2);
  hh->SetFillColorAlpha(color2, 0.35);
  hh->Draw(opt);
}

void myhherr(TH1 *hh,const char *opt,float ms,int color,int st,float wd,int ls,int lc,int fills,int color2)
{
  hh->SetMarkerSize(ms);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->SetLineWidth(wd);
  hh->SetLineStyle(ls);
  hh->SetLineColor(lc);
  hh->SetFillStyle(fills);
  hh->SetFillColor(color2);
  hh->Draw(opt);
}

void myhhdate2(TH2 *hh,const char *opt,float ms,int color,int st)
{
  hh->SetMarkerSize(ms);
  hh->SetFillColor(color);
  hh->SetMarkerColor(color);
  hh->SetMarkerStyle(st);
  hh->Draw(opt);
}

void myggdatae(TGraphAsymmErrors *gg,const char *opt,float ms,int color,int st,float wd,int ls,int fills,int lc)
{
  gg->Draw(opt);
  //
  gg->SetMarkerSize(ms);      // marker
  gg->SetMarkerColor(color); // marker
  gg->SetMarkerStyle(st);      // marker
  //
  gg->SetLineWidth(wd);       // line
  gg->SetLineStyle(ls);           // line
  gg->SetFillColor(color);
  gg->SetFillStyle(fills);
  gg->SetLineColor(lc);           // line
}

void myggth(TGraphAsymmErrors *gg,const char *opt,float ms,int color,int st,float wd,int ls,int lc,int hs)
{
  gg->SetMarkerSize(ms);
  gg->SetMarkerColor(color);
  gg->SetFillColor(color);
  gg->SetMarkerStyle(st);
  gg->SetLineWidth(wd);
  gg->SetLineStyle(ls);
  gg->SetLineColor(lc);
  gg->SetFillStyle(hs);
  gg->Draw(opt);
  gg->Draw("cx");
  //
}

void myepsfile(TCanvas *canvas,const char *file,const char *epp)
{
  canvas->Print(file,epp);
}

void myGethist(TH1 *hh,int nb1,int nb2,double xbins[100],double ex[100],double exx[100],double sigma[100],double esigma[100])
{
  for (int j=nb1;j<nb2;j++)
    {
      int i = j - nb1;
      xbins[i]  = hh->GetBinCenter(j+1);
      ex[i]     = hh->GetBinWidth(j+1)/2.;
      exx[i]    = 0.00000001;
      sigma[i]  = hh->GetBinContent(j+1);
      esigma[i] = hh->GetBinError(j+1);
      //cout << j << " " << xbins[i] << " " << ex[i] << " " << sigma[i] << " " << esigma[i] << endl;
    }
}

void ATLAS_LABEL(Double_t x,Double_t y,Color_t color) 
{
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextFont(72);
  l.SetTextColor(color);
  l.DrawLatex(x,y,"ATLAS");
}

TGraphErrors* myTGraphErrorsDivide(TGraphErrors* g1,TGraphErrors* g2) {
 
  const Int_t debug=0; 

  if (!g1) printf("**myTGraphErrorsDivide: g1 does not exist !  \n"); 
  if (!g2) printf("**myTGraphErrorsDivide: g2 does not exist !  \n"); 


  Int_t n1=g1->GetN();
  Int_t n2=g2->GetN();

  if (n1!=n2) {
   printf("**myTGraphErrorsDivide: vector do not have same number of entries !  \n"); 
  }

  TGraphErrors* g3= new TGraphErrors();

  Double_t  x1=0., y1=0., x2=0., y2=0.;
  Double_t dx1=0.,dy1=0.,       dy2=0.;

  Int_t iv=0;
  for (Int_t i1=0; i1<n1; i1++) {
   for (Int_t i2=0; i2<n2; i2++) {
     //if (debug) printf("**myTGraphErrorsDivide: %d  %d !  \n",i1,i2);

    g1->GetPoint(i1,x1,y1);
    g2->GetPoint(i2,x2,y2);
    if (x1!=x2) {
      //printf("**myTGraphErrorsDivide: %d x1!=x2  %f %f  !  \n",iv,x1,x2);
    }else{
      //if (debug) printf("**myTGraphErrorsDivide: %d x1=x2  %f %f  !  \n",iv,x1,x2);
     dx1  = g1->GetErrorX(i1);
     if (y1!=0) dy1  = g1->GetErrorY(i1)/y1;
     if (y2!=0) dy2  = g2->GetErrorY(i2)/y2;
   
     if (debug)
       printf("**myTGraphErrorsDivide: %d x1=%f x2=%f y1=%f y2=%f  \n",iv,x1,x2,y1,y2);

     if (y2!=0.) g3->SetPoint(iv, x1,y1/y2);
     else        g3->SetPoint(iv, x1,y2);
   
     Double_t e=0.;
     if (y1!=0 && y2!=0) e=std::sqrt(dy1*dy1+dy2*dy2)*(y1/y2); 
     g3->SetPointError(iv,dx1,e);


     if (debug) {
       //Double_t g3y, g3x,g3e;
       //g3->GetPoint(iv, g3y,g3x);
       //g3e=g3->GetErrorY(iv);
       //printf("%d g3y= %f g3e=%f  \n",iv,g3y,g3e);
     }
     iv++;
    }
    //    printf("**myTGraphErrorsDivide: ...next  \n");
   }
  }  
  return g3;

}


TGraphAsymmErrors* myTGraphErrorsDivide(TGraphAsymmErrors* g1,TGraphAsymmErrors* g2) {

  const Int_t debug=0; 

  TGraphAsymmErrors* g3= new TGraphAsymmErrors();
  Int_t n1=g1->GetN();
  Int_t n2=g2->GetN();

  if (n1!=n2) {
    printf(" vectors do not have same number of entries !  \n");
   return g3;
  }

  Double_t   x1=0.,   y1=0., x2=0., y2=0.;
  Double_t dx1h=0., dx1l=0.;
  Double_t dy1h=0., dy1l=0.;
  Double_t dy2h=0., dy2l=0.;

  Double_t* X1 = g1->GetX();
  Double_t* Y1 = g1->GetY();
  Double_t* EXhigh1 = g1->GetEXhigh();
  Double_t* EXlow1 =  g1->GetEXlow();
  Double_t* EYhigh1 = g1->GetEYhigh();
  Double_t* EYlow1 =  g1->GetEYlow();

  Double_t* X2 = g2->GetX();
  Double_t* Y2 = g2->GetY();
  Double_t* EXhigh2 = g2->GetEXhigh();
  Double_t* EXlow2 =  g2->GetEXlow();
  Double_t* EYhigh2 = g2->GetEYhigh();
  Double_t* EYlow2 =  g2->GetEYlow();

  for (Int_t i=0; i<g1->GetN(); i++) {
    g1->GetPoint(i,x1,y1);
    g2->GetPoint(i,x2,y2);
    dx1h  = EXhigh1[i];
    dx1l  = EXlow1[i];
    if (y1!=0.) dy1h  = EYhigh1[i]/y1;
    else        dy1h  = 0.;
    if (y2!=0.) dy2h  = EYhigh2[i]/y2;
    else        dy2h  = 0.;
    if (y1!=0.) dy1l  = EYlow1 [i]/y1;
    else        dy1l  = 0.;
    if (y2!=0.) dy2l  = EYlow2 [i]/y2;
    else        dy2l  = 0.;
   
    //if (debug)
    //printf("%d x1=%f x2=%f y1=%f y2=%f  \n",i,x1,x2,y1,y2);
    if (debug)
      printf("%d dy1=%f %f dy2=%f %f sqrt= %f %f \n",i,dy1l,dy1h,dy2l,dy2h,
	     std::sqrt(dy1l*dy1l+dy2l*dy2l), std::sqrt(dy1h*dy1h+dy2h*dy2h));

    if (y2!=0.) g3->SetPoint(i, x1,y1/y2);
    else       g3->SetPoint(i, x1,y2);
    Double_t el=0.; Double_t eh=0.;

    if (y1!=0. && y2!=0.) el=std::sqrt(dy1l*dy1l+dy2l*dy2l)*(y1/y2);
    if (y1!=0. && y2!=0.) eh=std::sqrt(dy1h*dy1h+dy2h*dy2h)*(y1/y2);

    if (debug) printf("dx1h=%f  dx1l=%f  el=%f  eh=%f \n",dx1h,dx1l,el,eh);
    g3->SetPointError(i,dx1h,dx1l,el,eh);

  }  
  return g3;

}



TGraphAsymmErrors* myMakeBand(TGraphErrors* g0, TGraphErrors* g1,TGraphErrors* g2) {
  // default is g0
    //const Int_t debug=0;

  TGraphAsymmErrors* g3= new TGraphAsymmErrors();

  Double_t  x1=0., y1=0., x2=0., y2=0., y0=0, x3=0.;
  //Double_t dx1=0.;
  Double_t dum;
  for (Int_t i=0; i<g1->GetN(); i++) {
    g0->GetPoint(i, x1,y0);
    g1->GetPoint(i, x1,y1);
    g2->GetPoint(i, x1,y2);

    // if (y1==0) y1=1;
    //if (y2==0) y2=1;

    if (i==g1->GetN()-1) x2=x1;
    else                 g2->GetPoint(i+1,x2,dum);

    if (i==0)            x3=x1;
    else                 g2->GetPoint(i-1,x3,dum);

    Double_t tmp=y2;
    if (y1<y2) {y2=y1; y1=tmp;}
    //Double_t y3=1.;
    Double_t y3=y0;
    g3->SetPoint(i,x1,y3);

    Double_t binwl=(x1-x3)/2.;
    Double_t binwh=(x2-x1)/2.;
    if (binwl==0.)  binwl= binwh;
    if (binwh==0.)  binwh= binwl;
    g3->SetPointError(i,binwl,binwh,(y3-y2),(y1-y3));

  }
  return g3;

}

void myAddtoBand(TGraphErrors* g1, TGraphAsymmErrors* g2) {

  Double_t  x1=0., y1=0.,  y2=0., y0=0;
  //Double_t dx1=0.;
  //Double_t dum;

  if (g1->GetN()!=g2->GetN())
    std::cout << " graphs have not the same # of elements " << std::endl;

  Double_t* EYhigh = g2-> GetEYhigh();
  Double_t* EYlow  = g2-> GetEYlow();

  for (Int_t i=0; i<g1->GetN(); i++) {
    g1->GetPoint(i, x1,y1);
    g2->GetPoint(i, x1,y2);

    if (y1==0) y1=1;
    if (y2==0) y2=1;

    //    if (i==g1->GetN()-1) x2=x1;
    //    else                 g2->GetPoint(i+1,x2,dum);
    //    if (i==0)            x3=x1;
    //    else                 g2->GetPoint(i-1,x3,dum);

    Double_t eyh=0., eyl=0.;
    //if (y1<y2) {y2=y1; y1=tmp;}
    //Double_t y3=1.;

    //printf("%d: y1=%f y2=%f Eyhigh= %f Eylow= %f \n",i,y1,y2,EYhigh[i],EYlow[i]);

    y0=y1-y2;
    if (y0!=0) {
     if (y0>0){
      eyh=EYhigh[i];
      eyh=std::sqrt(eyh*eyh+y0*y0);
      //printf("high: %d: y0=%f eyh=%f  \n",i,y0,eyh);
      g2->SetPointEYhigh(i,eyh);
     } else {
      eyl=EYlow[i];
      eyl=std::sqrt(eyl*eyl+y0*y0);
      // printf("low: %d: y0=%f eyl=%f  \n",i,y0,eyl);
      g2->SetPointEYlow (i,eyl);
     }
    }
  }
  return;

}

TGraphErrors* TH1TOTGraph(TH1 *h1){


  if (!h1) std::cout << "TH1TOTGraph: histogram not found !" << std::endl;

 TGraphErrors* g1= new TGraphErrors();

 Double_t x, y, ex, ey;
 for (Int_t i=0; i<h1->GetNbinsX(); i++) {
   y=h1->GetBinContent(i);
  ey=h1->GetBinError(i);
   x=h1->GetBinCenter(i);
  ex=h1->GetBinWidth(i);
  //cout << " i " << i << " x,y = " << x << " " << y << " ex,ey = " << ex << " " << ey << endl;

   g1->SetPoint(i,x,y);
   g1->SetPointError(i,ex,ey);

 }

 //g1->Print();

 return g1;
}

void myText(Double_t x,Double_t y,Color_t color,const char *text,Float_t mytsize) {

  //Double_t tsize=0.05;
  TLatex l; //l.SetTextAlign(12);
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.SetTextColor(color);
  l.DrawLatex(x,y,text);
}

void myTexta(Double_t x,Double_t y,Color_t color,const char *text,Float_t mytsize,float ang) {

  //Double_t tsize=0.05;
  TLatex l; //l.SetTextAlign(12);
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.SetTextColor(color);
  l.SetTextAngle(ang);
  l.DrawLatex(x,y,text);
}
 

void myBoxText(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,Int_t mstyle,const char *text,Float_t mytsize,Double_t tsize) 
{

  //Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  //TPave *mbox= new TPave(x1,y1,x2,y2,0,"NDC");
  TPave *mbox= new TPave(x1,y1,x2,y2,1,"NDC");

  mbox->SetFillColor(mcolor);
  mbox->SetLineColor(mcolor);
  //mbox->SetFillStyle(1001);
  mbox->SetFillStyle(mstyle);
  mbox->SetLineWidth(2.);
  mbox->Draw();

  TLine mline;
  mline.SetLineWidth(4);
  mline.SetLineColor(1);
  mline.SetLineStyle(1);
  Double_t y_new=(y1+y2)/2.;
  //mline.DrawLineNDC(x1,y_new,x2,y_new);

}

void myBoxText_tr(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,Int_t mcolor2,Int_t mstyle,const char *text,Float_t mytsize,Double_t tsize) 
{

  //Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  //TPave *mbox= new TPave(x1,y1,x2,y2,0,"NDC");
  TPave *mbox= new TPave(x1,y1,x2,y2,1,"NDC");

  mbox->SetFillColor(mcolor2);
  mbox->SetFillColorAlpha(mcolor2, 0.35);
  mbox->SetLineColor(mcolor);
  //mbox->SetFillStyle(1001);
  mbox->SetFillStyle(mstyle);
  mbox->SetLineWidth(2.);
  mbox->Draw();

  TLine mline;
  mline.SetLineWidth(4);
  mline.SetLineColor(1);
  mline.SetLineStyle(1);
  Double_t y_new=(y1+y2)/2.;
  //mline.DrawLineNDC(x1,y_new,x2,y_new);

}

void myBoxTextDan(Double_t x, Double_t y,Double_t boxsize,Int_t mstyle,Int_t mcolor,Int_t rstyle,Int_t rcolor,const char *text,Float_t mytsize,Double_t tsize) 
{

  //Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  //TPave *mbox= new TPave(x1,y1,x2,y2,0,"NDC");
  TPave *mbox= new TPave(x1,y1,x2,y2,1,"NDC");

  mbox->SetFillColor(rcolor);
  mbox->SetLineColor(mcolor);
  mbox->SetFillStyle(rstyle);
  mbox->SetLineWidth(2.);
  mbox->Draw();

  TLine mline;
  mline.SetLineWidth(0.);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle(mstyle);
  Double_t y_new=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y_new,x2,y_new);

}

void myBoxTextDan2(Double_t x, Double_t y,Double_t boxsize,Int_t mstyle,Int_t mcolor,Int_t rstyle,Int_t rcolor,const char *text,Float_t mytsize,Double_t tsize) 
{

  //Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  //TPave *mbox= new TPave(x1,y1,x2,y2,0,"NDC");
  TPave *mbox= new TPave(x1,y1,x2,y2,1,"NDC");

  mbox->SetFillColor(rcolor);
  mbox->SetLineColor(mcolor);
  mbox->SetFillStyle(rstyle);
  mbox->SetLineWidth(2.);
  mbox->Draw();

  TLine mline;
  mline.SetLineWidth(0);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle(mstyle);
  Double_t y_new=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y_new,x2,y_new);

}

void myLine(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,Int_t mstyle,const char *text,Float_t mytsize,Double_t tsize) 
{

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  TLine mline;
  mline.SetLineWidth(3);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle(mstyle);
  Double_t y_new=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y_new,x2,y_new);

}


void myLinecg(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,Int_t mstyle,const char *text,Float_t mytsize,Double_t tsize,Double_t lsize) 
{

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(mytsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  //printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  TLine mline;
  mline.SetLineWidth(lsize);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle(mstyle);
  Double_t y_new=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y_new,x2,y_new);

}

void myMarkerText(Double_t x,Double_t y,Int_t color,Int_t mstyle,const char *text,Float_t msize,Float_t mytsize,Float_t tsize) 
{
  //Double_t tsize=0.06;
  TMarker *marker = new TMarker(x-(0.4*tsize),y+(0.0*tsize),8);
  marker->SetMarkerColor(color);  marker->SetNDC();
  marker->SetMarkerStyle(mstyle);
  marker->SetMarkerSize(msize);
  marker->Draw();

  TLatex l;
  l.SetTextSize(mytsize); 
  l.SetTextAlign(12);
  l.SetNDC();
  l.DrawLatex(x,y,text);
}

double lorentzian(double *x, double *par)
{
  return (0.5*par[0]*par[1]/TMath::Pi()) / TMath::Max(
       1.e-10,(x[0]-par[2])*(x[0]-par[2]) + par[1]*par[1]/4.0);
}
double myfunco(double *x, double *par)
{
  return (par[2]*exp(-(x[0]-par[0])*(x[0]-par[0])/(2.*par[1]*par[1]))*exp(-x[0]*par[3]-par[4]));
}
double myfunc(double *x, double *par)
{
  Float_t xx =x[0];
  double f;
  par[4] = fabs(par[4]);
  double b = ((par[4]-par[0])/(par[1]*par[1]))-2*par[3]*par[4];
  double N1 = exp(-0.5*(pow((par[4]-par[0])/par[1],2)));
  double N2 = exp(-1.0*(par[2]+b*par[4]+par[3]*par[4]*par[4]));
  if(xx >= par[4]){
    f= exp(-1.0*(par[2]+b*xx+par[3]*xx*xx));
  }else{
    f = (N2/N1)*exp(-0.5*(pow((xx-par[0])/par[1],2)));
    }
               
  return f;
}
void ATLAS_LABEL_NN(Double_t x,Double_t y,Color_t color,string opt,bool coe) 
{
  TLatex l;
  TLatex lm;

  l.SetNDC();
  l.SetTextFont(72);
  l.SetTextColor(color);
  l.SetTextSize(0.05);

  if (opt == "sim"){
    l.DrawLatex(x,y,"ATLAS Simulation Internal");
  }
  if (opt == "int"){
    l.DrawLatex(x,y,"ATLAS Internal");
  }
  if (opt == "prel"){
    l.DrawLatex(x,y,"ATLAS Preliminary");
  }
  if (opt == "fin"){
    l.DrawLatex(x,y,"ATLAS");
  }

  if (coe == true){
    lm.SetNDC();
    lm.SetTextFont(42);
    lm.SetTextColor(color);
    lm.SetTextSize(0.04);
    lm.DrawLatex(x,y-0.05,"#sqrt{s} = 13 TeV");
  }
  
}
