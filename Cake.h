//
// Created by ajames on 12/9/2021.
//

#ifndef LAB9_CAKE_H
#define LAB9_CAKE_H

#include "BakedGood.h"
#include <string>
using namespace std;

class Cake : public BakedGood {
protected:
    string cakeFlavor;
    string frostingFlavor;

public:
    Cake();
    explicit Cake(string pInput);
    string ToString() override;
};



#endif //LAB9_CAKE_H
