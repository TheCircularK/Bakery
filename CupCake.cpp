//
// Created by Andrew on 12/9/2021.
//

#include "CupCake.h"
CupCake::CupCake() {
    itemDescription = "Generic Cupcake";
}

CupCake::CupCake(vector<string> pInput) {
    cakeFlavor = pInput.at(1);
    frostingFlavor = pInput.at(2);
    sprinkleColor = pInput.at(3);
    itemPrice = 1.95;
    if (frostingFlavor == "cream-cheese") {
        itemPrice += 0.2;
    }
}

string CupCake::ToString() {
    string returnString = cakeFlavor + " cupcake with " + frostingFlavor + " frosting and " + sprinkleColor + " sprinkles ($" + to_string(itemPrice) + ")";
    return returnString;
}

double CupCake::ComputeDiscount(int pNumItems) {
    if (pNumItems >= 4) {
        double totalDiscount = .40 * pNumItems;
        return totalDiscount;
    }
    else if (pNumItems >= 2) {
        double totalDiscount = .30 * pNumItems;
        return totalDiscount;
    }
    return 0;
}