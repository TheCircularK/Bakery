//
// Created by Andrew on 12/9/2021.
//

#include "LayerCake.h"
LayerCake::LayerCake() {
    itemDescription = "Generic layer cake";
}

LayerCake::LayerCake(vector<string> pInput) {
    cakeFlavor = pInput.at(1);
    frostingFlavor = pInput.at(2);
    numLayers = stoi(pInput.at(3));
    itemPrice = 9.0;
    if (numLayers > 1) {
        itemPrice += (numLayers - 1) * 3;
    }
    if (frostingFlavor == "cream-cheese") {
        itemPrice += numLayers;
    }
}

string LayerCake::ToString() {
    string returnString = to_string(numLayers) + "-layer " + cakeFlavor + " cake with " + frostingFlavor + " frosting ($" +
            to_string(itemPrice) + ")";
    return returnString;
}

double LayerCake::ComputeDiscount(int pNumItems) {
    if (pNumItems >= 3) {
        double totalDiscount = pNumItems * 2;
        return totalDiscount;
    }
    return 0;
}