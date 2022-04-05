//
// Created by Andrew on 12/9/2021.
//

#include "Bread.h"

Bread::Bread() {
    itemDescription = "Generic bread";
}

Bread::Bread(vector<string> pInput) {
    breadVariety = pInput.at(1);
    itemPrice = 4.5;
}

string Bread::ToString() {
    string returnString = breadVariety + " bread ($" + to_string(itemPrice) + ")";
    return returnString;
}

double Bread::ComputeDiscount(int pNumItems) {
    int numFreeItems = pNumItems / 3;
    return numFreeItems * itemPrice;
}