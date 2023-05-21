#include "DeliveryOrder.h" // DeliveryOrder.h
#include "FoodOrder.h" // FoodOrder.h
#include "BobaOrder.h" // BobaOrder.h
#include "Account.h" // Account.h
#include "InvalidInput.h" // InvalidInput.h
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//// APPLYDISCOUNT() ////
// We will have one function for this system. The function is applyDiscount() which will take in a DeliveryOrder pointer and a constant reference account. The function will return the discounted balance of the order. For example, if the total balance(returned from function getTotalBalance()) is $100 and the discount is 0.1, then this function will return the float 10 which is (100 * 0.1).

// The applyDiscount() function will check the account status to determine how to apply the discount.

// If the account status is "Owner", it will apply 90% off to the order, so it will return 0.1 multiply by the delivery balance
// If the account status is "VIP", it will trigger the corresponding VIPdiscount() function of the order depending on whether it's a BobaOrder or a FoodOrder with dynamic binding. It will then take the returned value of VIPdiscount() and multiply with delivery balance then return the result.
// If the account status is "Regular", no discount will be applied and the delivery balance of the order will remain unchanged and returned.

float applyDiscount(DeliveryOrder, const Account&);

int main () {
    // 
    return 0;
}

//// APPLYDISCOUNT() ////
float applyDiscount(DeliveryOrder order, const Account& accountType) // take in a DeliveryOrder pointer and a constant reference account
{
    // Check the account status to determine how to apply the discount

    // return the discounted balance of the order
}