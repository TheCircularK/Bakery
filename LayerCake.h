//
// Created by Andrew on 12/9/2021.
//

#ifndef LAB9_LAYERCAKE_H
#define LAB9_LAYERCAKE_H

#include "Cake.h"
using namespace std;

class LayerCake : public Cake{
public:
    LayerCake();
    LayerCake(vector<string> pInput);
    string ToString() override;
    double ComputeDiscount(int pNumItems);
private:
    int numLayers;
};


#endif //LAB9_LAYERCAKE_H
