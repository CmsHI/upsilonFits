{
gr = new TGraphErrors("Results1s-trigg4-More1_2.dat","%lg %lg %lg %lg",", ");
gr->SetMarkerColor(kBlue);
gr->SetMarkerStyle(21);
gr2s = new TGraphErrors("Results2s-trigg4-More1_2.dat","%lg %lg %lg %lg",", ");
gr2s->SetMarkerColor(kRed);
gr2s->SetMarkerStyle(21);
gr3s = new TGraphErrors("Results3s-trigg4-More1_2.dat","%lg %lg %lg %lg",", ");
gr3s->SetMarkerColor(kGreen);
gr3s->SetMarkerStyle(21);
gr->SetTitle("Yield Vs Pt");

gr2 = new TGraphErrors("Results1s-trigg32-Less1_2.dat","%lg %lg %lg %lg",", ");
gr2->SetMarkerColor(kBlue);
gr2->SetMarkerStyle(21);
gr2s2 = new TGraphErrors("Results2s-trigg32-Less1_2.dat","%lg %lg %lg %lg",", ");
gr2s2->SetMarkerColor(kRed);
gr2s2->SetMarkerStyle(21);
gr3s2 = new TGraphErrors("Results3s-trigg32-Less1_2.dat","%lg %lg %lg %lg",", ");
gr3s2->SetMarkerColor(kGreen);
gr3s2->SetMarkerStyle(21);
gr2->SetTitle("Yield Vs Pt");

gr3 = new TGraphErrors("Results1s-trigg4-Less1_2.dat","%lg %lg %lg %lg",", ");
gr3->SetMarkerColor(kBlue);
gr3->SetMarkerStyle(21);
gr2s3 = new TGraphErrors("Results2s-trigg4-Less1_2.dat","%lg %lg %lg %lg",", ");
gr2s3->SetMarkerColor(kRed);
gr2s3->SetMarkerStyle(21);
gr3s3 = new TGraphErrors("Results3s-trigg4-Less1_2.dat","%lg %lg %lg %lg",", ");
gr3s3->SetMarkerColor(kGreen);
gr3s3->SetMarkerStyle(21);
gr3->SetTitle("Yield Vs Pt");

gr->Draw("AP");
gr2s->Draw("PSAME");
gr3s->Draw("PSAME");
c1->SaveAs("MassUps-RapidityMore1_2-Trigg4.pdf");
c1->SaveAs("MassUps-RapidityMore1_2-Trigg4.png");

gr2->Draw("AP");
gr2s2->Draw("PSAME");
gr3s2->Draw("PSAME");
c1->SaveAs("MassUps-RapidityLess1_2-Trigg32.pdf");
c1->SaveAs("MassUps-RapidityLess1_2-Trigg32.png");

gr3->Draw("AP");
gr2s3->Draw("PSAME");
gr3s3->Draw("PSAME");
c1->SaveAs("MassUps-RapidityLess1_2-Trigg4.pdf");
c1->SaveAs("MassUps-RapidityLess1_2-Trigg4.png");
}
