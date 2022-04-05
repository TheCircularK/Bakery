//
// Created by Andrew on 12/9/2021.
//

#ifndef LAB9_CUPCAKE_H
#define LAB9_CUPCAKE_H

#include <string>
#include "Cake.h"
using namespace std;

class CupCake : public Cake {
public:
    CupCake();
    CupCake(vector<string> pInput);
    double ComputeDiscount(int pNumItems);
private:
    string sprinkleColor;
    string ToString() override;
};


#endif //LAB9_CUPCAKE_H
