//
// Created by Andrew on 12/9/2021.
//

#ifndef LAB9_BAKEDGOOD_H
#define LAB9_BAKEDGOOD_H

#include <string>
#include <vector>

using namespace std;

class BakedGood {
private:

protected:
    //Extremely important
    string itemDescription;
    double itemPrice;
    string breadVariety;
    vector<string> inputVector;

public:
    BakedGood();
    BakedGood(string pInput);
    virtual string ToString();
    virtual double ComputeDiscount(int pNumItems) = 0;
    double ReturnPrice();
};




#endif //LAB9_BAKEDGOOD_H
