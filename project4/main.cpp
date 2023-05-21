#include "DeliveryOrder.h" // DeliveryOrder.h
#include "FoodOrder.h" // FoodOrder.h
#include "BobaOrder.h" // BobaOrder.h
#include "Account.h" // Account.h
#include "InvalidInput.h" // InvalidInput.h
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
// #include <iomanip>
// #include <cmath>
using namespace std;

//// APPLYDISCOUNT() ////
float applyDiscount(DeliveryOrder, const Account&);
/* 
We will have one function for this system. The function is applyDiscount() which will take in a DeliveryOrder pointer and a constant reference account. The function will return the discounted balance of the order. For example, if the total balance(returned from function getTotalBalance()) is $100 and the discount is 0.1, then this function will return the float 10 which is (100 * 0.1).

The applyDiscount() function will check the account status to determine how to apply the discount:
> If the account status is "Owner", it will apply 90% off to the order, so it will return 0.1 multiply by the delivery balance
> If the account status is "VIP", it will trigger the corresponding VIPdiscount() function of the order depending on whether it's a BobaOrder or a FoodOrder with dynamic binding. It will then take the returned value of VIPdiscount() and multiply with delivery balance then return the result.
> If the account status is "Regular", no discount will be applied and the delivery balance of the order will remain unchanged and returned.
*/


int main () {
    // Finally, it's our main function. We first have three accounts, one constant owner account, one VIP account, and one regular account.

    //// STUART ////
    // Stuart appears to be the secret owner of all the restaurants and boba shops of New York, he will have an owner account the system created for him and he can't change the account, so it's a constant account. The account username will be "Stuart" and the status will be "Owner".
    const Account stuart("Stuart", "Owner");

    //// KEVIN ////
    // Kevin appears to be the secret VIP of all the restaurants and boba shops of New York, and he created his VIP account with username "Kevin" and status "VIP".
    Account kevin("Kevin", "VIP");

    //// BOB ////
    // Bob appears to be a regular customer, who's not aware of Kevin and Stuart's secret identities, created his regular account with username "Bob".
    Account bob("Bob");

    // We will then have a DeliveryOrder pointer that we will later use to point to different orders to allow polymorphism.
    DeliveryOrder* order;

    return 0;
}

//// APPLYDISCOUNT() //// <----- needs work.....
float applyDiscount(DeliveryOrder ordr, Account& acct) // take in a DeliveryOrder pointer and a constant reference account
{
    if (acct.getStatus() == "VIP") // Check the account status to determine how to apply the discount
    {
        ordr.VIPdiscount(); // return the discounted balance of the order
    }
};