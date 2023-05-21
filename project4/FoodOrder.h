#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
using namespace std;

#ifndef FOODORDER_H
#define FOODORDER_H

// FoodOrder is similar to BobaOrder that it inherits from DeliveryOrder with public inheritance.
class FoodOrder : public DeliveryOrder {
    
    //// PRIVATE ////
    private:
    string restaurantName;
    int foodCount;


    //// PUBLIC ////
    public:
    //// RECEIPT() ////
    const void receipt(); // constant receipt() function that will print out the order receipt

    //// VIPDISCOUNT() ////
    float VIPdiscount(); // It will also override the VIPdiscount() function as it's required for pure virtual functions.

    /*
    It will also override the VIPdiscount() function as it's required for pure virtual functions. The discount function will:
    > return 0.85 if the orderBalance(without tax and shipping cost) is greater than 50
    > return 0.9 if the orderBalance(without tax and shipping cost) is greater than 30
    > return 0.95 if the orderBalance(without tax and shipping cost) is greater than 20
    > return 1 if the orderBalance(without tax and shipping cost) is less than or equal to 20
    */ 

};

#endif