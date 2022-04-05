//
// Created by ajame on 12/9/2021.
//

#include "Cake.h"

Cake::Cake() {
    itemDescription = "Generic cake";
}

Cake::Cake(string pInput) {
    itemDescription = pInput;
}

string Cake::ToString() {
    return itemDescription;
}