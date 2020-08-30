#ifndef ACCMAP_H
#define ACCMAP_H


#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"
#include "TH1D.h"
#include "TH2D.h"
#include "TString.h"
#include "TMath.h"
#include "interface/module.hpp"
#include "interface/TH2weightsHelper.hpp"

using RNode = ROOT::RDF::RNode;

class accMap : public Module {

    private:

    std::vector<ROOT::RDF::RResultPtr<TH1D>> _h1List;
    std::vector<ROOT::RDF::RResultPtr<TH2D>> _h2List;
    std::vector<ROOT::RDF::RResultPtr<TH3D>> _h3List;

    // groups of histos
    std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> _h1Group;
    std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> _h2Group;
    std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> _h3Group;

    std::vector<float> _yArr = {0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.5, 3.0, 6.0};
    std::vector<float> _ptArr = {0., 4., 8., 12., 16., 20., 24., 32., 40., 60., 100., 200.};

    int _nBinsY = 8;
    int _nBinsPt = 11;

public:
    
    ~accMap() {};

    RNode run(RNode) override;
    std::vector<ROOT::RDF::RResultPtr<TH1D>> getTH1() override;
  	std::vector<ROOT::RDF::RResultPtr<TH2D>> getTH2() override;
  	std::vector<ROOT::RDF::RResultPtr<TH3D>> getTH3() override;

    std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> getGroupTH1() override;
    std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> getGroupTH2() override;
    std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> getGroupTH3() override;

    void reset() override;

};

#endif