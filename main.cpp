#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;

int HowMany(string& userInput, int& howMany);
vector<string> SplitString(string pStringInput);

//Define struct
struct namesAndNumbers {
    string name;
    int number;
    BakedGood* firstInstance;
    double totalPrice = 0;
};

int main() {
    //Variables
    string userInput = "";
    int howMany = 0;

    //Vectors
    vector<BakedGood*> orderList;
    vector<string> splitInput;

    cout << "**Bread and Cakes Bakery**" << endl << endl;

    cout << "Enter sub-order (enter \"done\" to finish)" << endl;

    while (userInput != "done") {
        cout << "Sub-order: ";
        getline(cin, userInput);

        //If the input is done, get out
        if (userInput == "done") {
            break;
        }

        //Split the input
        splitInput = SplitString(userInput);

        //Get the number of items and delete from vector
        howMany = stoi(splitInput.back());
        splitInput.pop_back();

        if (splitInput[0] == "Bread") {
            for (int i = 0; i < howMany; i++) {
                Bread* newBread = new Bread(splitInput);
                orderList.push_back(newBread);
            }

        }
        else if (splitInput[0] == "Cupcake") {
            for (int i = 0; i < howMany; i++) {
                CupCake *newCupCake = new CupCake(splitInput);
                orderList.push_back(newCupCake);
            }
        }
        else if (splitInput[0] == "Layer-cake") {
            for (int i = 0; i < howMany; i++) {
                LayerCake *newLayerCake = new LayerCake(splitInput);
                orderList.push_back(newLayerCake);
            }
        }
    }

    //Print the list
    cout << "Order Confirmations:" << endl;
    for (size_t i = 0; i < orderList.size(); i++) {
        cout << orderList.at(i)->ToString();
        cout << endl;
    }
    cout << endl;

    //How many of each
    vector<namesAndNumbers> tempVector;
    for (BakedGood* good: orderList) {
        bool addedStuff = false;
        for (namesAndNumbers& name: tempVector) {
            if (name.name == good->ToString()) {
                name.number += 1;
                addedStuff = true;
                break;
            }
        }
        if (!addedStuff) {
            namesAndNumbers tempObject = {good->ToString(), 1, good};
            tempVector.push_back(tempObject);
        }
    }

    //Calculate discount
    for (size_t i = 0; i < tempVector.size(); i++) {
        BakedGood* bgPointer = tempVector[i].firstInstance;
        tempVector[i].totalPrice = bgPointer->ReturnPrice() * tempVector[i].number - bgPointer->ComputeDiscount(tempVector[i].number);
    }

    //Print everything
    cout << "Invoice: " << endl;
    cout << setw(75) << left << "Baked Good" << setw(9) << "Quantity" << "Total" << endl;

    int finalQuantity = 0;
    double finalTotal = 0;

    for (size_t i = 0; i < tempVector.size(); i++) {
        cout << setw(75) << tempVector[i].name
             << setw(9)  << tempVector[i].number
             << fixed << setprecision(2) << tempVector[i].totalPrice << endl;
        finalQuantity += tempVector[i].number;
        finalTotal += tempVector[i].totalPrice;
    }

    cout << setw(75) << "Totals" << setw(9) << finalQuantity << finalTotal << endl;
    cout << "Good Bye" << endl;


    return 0;
}



//Functions
vector<string> SplitString(string pStringInput) {
    vector<string> tempVector;
    size_t indexNum = 0;
    for (size_t i = 0; i < pStringInput.size(); i = indexNum + 1) {
        indexNum = pStringInput.find(" ", i);
        if (indexNum != static_cast<size_t>(-1)) {
            tempVector.push_back(pStringInput.substr(i, indexNum - i));
        }
        else {
            tempVector.push_back(pStringInput.substr(i));
            break;
        }
    }
    return tempVector;
}