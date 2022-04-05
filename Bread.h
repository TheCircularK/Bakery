//
// Created by Andrew on 12/9/2021.
//

#ifndef LAB9_BREAD_H
#define LAB9_BREAD_H


#include "BakedGood.h"

class Bread : public BakedGood {
private:
public:
    Bread();
    Bread(vector<string> pInput);
    string ToString() override;
    double ComputeDiscount(int pNumItems);
};


#endif //LAB9_BREAD_H
