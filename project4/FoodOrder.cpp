#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"
using namespace std;


//// CONSTRUCTOR ////
// The constructor of FoodOrder takes the same parameters as DeliveryOrder's constructor and also takes in an extra string to initialize the member attribute restaurantName.

//// DESTRUCTOR ////
//The destructor will simply output
// "FoodOrder destroyed.\n"

const void FoodOrder::receipt() {
    // Make sure you call the receipt() function of the DeliveryOrder class instead of rewriting the same piece of code again.
    DeliveryOrder::receipt();
    // FoodOrder will override the receipt() function by adding one extra line to the receipt as following:
    cout << "\tFood Count: " << foodCount << endl;
}

DeliveryOrder::orderBalance

// It will also override the VIPdiscount() function as it's required for pure virtual functions. The discount function will
float VIPdiscount() {
    if ()// return 0.85 if the orderBalance(without tax and shipping cost) is greater than 50

    // return 0.9 if the orderBalance(without tax and shipping cost) is greater than 30

    // return 0.95 if the orderBalance(without tax and shipping cost) is greater than 20

    // return 1 if the orderBalance(without tax and shipping cost) is less than or equal to 20

}


// FoodOrder also has a new function addFood() which will take in the name of the main course ordered, an integer default to 0 indicating how many sides one wants to order, and a boolean default to false indicating whether one wants to add soup to the order. There are four meals available for people to order from:

// Thick Cauliflower Steaks: $15
// Rack of Lamb: $38
// Organic Scottish Salmon: $23
// Grilled Lobster Risotto: $46

// You will do string comparison to match the meal and if the passed in meal doesn't match any of the meal listed on the menu, throw the InvalidInput exception with meal name as the parameter. Adding soup costs $5, and each additional side costs $6. For example, if Bob orders the Rack of Lamb with one additional side and soup, the cost will be $38 + $5 + $6.

// At the end of the function make sure you update the foodCount and add the cost of this food order to the orderBalance of the order.