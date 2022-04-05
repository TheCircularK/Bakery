//
// Created by Andrew on 12/9/2021.
//

#include "BakedGood.h"
BakedGood::BakedGood() {
    itemDescription = "Generic baked good. You should never see this";
}

BakedGood::BakedGood(string pInput) {
    itemDescription = pInput;
}

string BakedGood::ToString() {
    return itemDescription;
}

double BakedGood::ReturnPrice() {
    return itemPrice;
}