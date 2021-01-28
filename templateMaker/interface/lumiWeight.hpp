#ifndef LUMIWEIGHT_H
#define LUMIWEIGHT_H

#include "module.hpp"

class lumiWeight : public Module
{

private:
    float _targetLumi;
    float _xsec;
    float _genEventSumwClipped;

public:
  lumiWeight(float xsec, float sumwclipped, float targetLumi = 35.9)
    {
        _targetLumi = targetLumi;
        _xsec = xsec/ 0.001;
        _genEventSumwClipped = sumwclipped;
    };

    ~lumiWeight(){};

    RNode run(RNode) override;
};

#endif
