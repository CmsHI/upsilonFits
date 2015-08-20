#!/bin/bash

#int ncpu=4,bool trig=1,string histoname="upsilonfit", double ptMin=10., double ptMax=120., double etaMax=0.9
#root -l -q -b 'PlotMass_1CB_eta0_5.C' 
#root -l -q -b 'PlotMass_1CB.C'
rm Results/*
rm Plots/*
rm Status/*
#root -l -q -b 'PlotMass.C(1,32,0.,120.,"Mass>8.6 && Mass<11.0 && TMath::Abs(EtaMuP)<1.2 && TMath::Abs(EtaMuM)<1.2 && Rapidity<1.2 ","MassUps-EtaLess1_2-Trigg32","#sqrt{f_{1}#sigma_{1}^{2}+f_{2}#sigma_{2}^{2}} = 110 MeV","p_{T}^{#mu^{+}#mu^{-}} > 13 GeV"," ")'

#root -l -q -b 'PlotMass.C(1,32,8.,100.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt-All","8 GeV < p_{T}^{#mu^{+}#mu^{-}} "," "," ")'

root -l -q -b 'PlotMass.C(1,32,8.,10.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt8-10","8 GeV < p_{T}^{#mu^{+}#mu^{-}} < 10 GeV","|Rapidity|<1.2 ","nups(1s) = 3681 #pm 66 ")'
root -l -q -b 'PlotMass.C(1,32,10.,12.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt10-12","10 GeV < p_{T}^{#mu^{+}#mu^{-}} < 12 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,12.,14.,"TMath::Abs(Rapidity<1.2)","MassUps-RapidityLess1_2-Trigg32-pt12-14","12 GeV < p_{T}^{#mu^{+}#mu^{-}} < 14 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,14.,16.,"TMath::Abs(Rapidity<1.2)","MassUps-RapidityLess1_2-Trigg32-pt14-16","14 GeV < p_{T}^{#mu^{+}#mu^{-}} < 16 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,16.,18.,"TMath::Abs(Rapidity<1.2)","MassUps-RapidityLess1_2-Trigg32-pt16-18","16 GeV < p_{T}^{#mu^{+}#mu^{-}} < 18 GeV ","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,18.,20.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt18-20","18 GeV < p_{T}^{#mu^{+}#mu^{-}} < 20 GeV","|Rapidity|<1.2 ","nups(1s) = 526 #pm 19 ")'
root -l -q -b 'PlotMass.C(1,32,20.,22.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt20-22","20 GeV < p_{T}^{#mu^{+}#mu^{-}} < 22 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,22.,24.,"TMath::Abs(Rapidity<1.2)","MassUps-RapidityLess1_2-Trigg32-pt22-24","22 GeV < p_{T}^{#mu^{+}#mu^{-}} < 24 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,24.,26.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt24-26","24 GeV < p_{T}^{#mu^{+}#mu^{-}} < 26 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,32,26.,28.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg32-pt26-28","26 GeV < p_{T}^{#mu^{+}#mu^{-}} < 28 GeV","|Rapidity|<1.2 ","nups(1s) = 124 #pm 19 ")'

mv Results1s.dat Results/Results1s-trigg32-Less1_2.dat
mv Results2s.dat Results/Results2s-trigg32-Less1_2.dat
mv Results3s.dat Results/Results3s-trigg32-Less1_2.dat
mv Status.dat Status/Status-trigg32-Less1_2.dat
#root -l -q -b 'PlotMass.C(1,4,13.,120.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt-All","13 GeV < p_{T}^{#mu^{+}#mu^{-}} ","|Rapidity|<1.2 "," ")'

root -l -q -b 'PlotMass.C(1,4,13.,15.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt13-15","13 GeV < p_{T}^{#mu^{+}#mu^{-}} < 15 GeV","|Rapidity|<1.2 ","nups(1s) = 3716 #pm 26 ")'
root -l -q -b 'PlotMass.C(1,4,15.,17.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt15-17","15 GeV < p_{T}^{#mu^{+}#mu^{-}} < 17 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,17.,19.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt17-19","17 GeV < p_{T}^{#mu^{+}#mu^{-}} < 19 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,19.,21.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt19-21","19 GeV < p_{T}^{#mu^{+}#mu^{-}} < 21 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,21.,23.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt21-23","21 GeV < p_{T}^{#mu^{+}#mu^{-}} < 23 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,23.,25.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt23-25","23 GeV < p_{T}^{#mu^{+}#mu^{-}} < 25 GeV","|Rapidity|<1.2 ","nups(1s) = 651 #pm 30 ")'
root -l -q -b 'PlotMass.C(1,4,25.,27.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt25-27","25 GeV < p_{T}^{#mu^{+}#mu^{-}} < 27 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,27.,29.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt27-29","27 GeV < p_{T}^{#mu^{+}#mu^{-}} < 29 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,29.,31.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt29-31","29 GeV < p_{T}^{#mu^{+}#mu^{-}} < 31 GeV","|Rapidity|<1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,31.,33.,"TMath::Abs(Rapidity<1.2) ","MassUps-RapidityLess1_2-Trigg4-pt31-33","31 GeV < p_{T}^{#mu^{+}#mu^{-}} < 33 GeV","|Rapidity|<1.2 ","nups(1s) = 162 #pm 13 ")'

mv Results1s.dat Results/Results1s-trigg4-Less1_2.dat
mv Results2s.dat Results/Results2s-trigg4-Less1_2.dat
mv Results3s.dat Results/Results3s-trigg4-Less1_2.dat
mv Status.dat Status/Status-trigg4-Less1_2.dat

#root -l -q -b 'PlotMass.C(1,4,13.,120.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityLess1_2-Trigg4-pt-All","13 GeV < p_{T}^{#mu^{+}#mu^{-}} ","|Rapidity|>1.2 "," ")'

root -l -q -b 'PlotMass.C(1,4,13.,15.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt13-15","13 GeV < p_{T}^{#mu^{+}#mu^{-}} < 15 GeV","|Rapidity|>1.2 ","nups(1s) = 966 #pm 44")'
root -l -q -b 'PlotMass.C(1,4,15.,17.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt15-17","15 GeV < p_{T}^{#mu^{+}#mu^{-}} < 17 GeV","|Rapidity|>1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,17.,19.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt17-19","17 GeV < p_{T}^{#mu^{+}#mu^{-}} < 19 GeV","|Rapidity|>1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,19.,21.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt19-21","19 GeV < p_{T}^{#mu^{+}#mu^{-}} < 21 GeV","|Rapidity|>1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,21.,23.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt21-23","21 GeV < p_{T}^{#mu^{+}#mu^{-}} < 23 GeV","|Rapidity|>1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,23.,25.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt23-25","23 GeV < p_{T}^{#mu^{+}#mu^{-}} < 25 GeV","|Rapidity|>1.2 ","nups(1s) = 171 #pm 35")'
root -l -q -b 'PlotMass.C(1,4,25.,27.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt25-27","25 GeV < p_{T}^{#mu^{+}#mu^{-}} < 27 GeV","|Rapidity|>1.2 "," ")'
#root -l -q -b 'PlotMass.C(1,4,27.,29.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt27-29","27 GeV < p_{T}^{#mu^{+}#mu^{-}} < 29 GeV","|Rapidity|>1.2 "," ")'
#root -l -q -b 'PlotMass.C(1,4,29.,31.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt29-31","29 GeV < p_{T}^{#mu^{+}#mu^{-}} < 31 GeV","|Rapidity|>1.2 "," ")'
#root -l -q -b 'PlotMass.C(1,4,31.,33.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt31-33","31 GeV < p_{T}^{#mu^{+}#mu^{-}} < 33 GeV","|Rapidity|>1.2 "," ")'
root -l -q -b 'PlotMass.C(1,4,27.,31.,"TMath::Abs(Rapidity>1.2) ","MassUps-RapidityMore1_2-Trigg4-pt27-31","27 GeV < p_{T}^{#mu^{+}#mu^{-}} < 31 GeV","|Rapidity|>1.2 ","nups(1s) = 133 #pm 19")'
mv Results1s.dat Results/Results1s-trigg4-More1_2.dat
mv Results2s.dat Results/Results2s-trigg4-More1_2.dat
mv Results3s.dat Results/Results3s-trigg4-More1_2.dat
mv Status.dat Status/Status-trigg4-More1_2.dat

