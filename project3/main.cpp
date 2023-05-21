#include "Minion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    // 1. READ FILE
    ifstream minions;
    minions.open("minions.txt", ios::in);

    // check to see if minions is open
    if (minions.is_open())
    {
        const Minion minion1;
        Minion minion2;
        Minion minion3;

        // name, height, eyes, and bananasOwned.
        minions >> minion1;
        minions >> minion2;
        minions >> minion3;

    } else {
        cout << "ERROR: minion file failed to open.\n";
    }
    // close minions file
    minions.close();

    // 2. COMPARE HEIGHT
    //Find the taller minion
    if (minion1 > minion2) {
       cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) {
       cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;

    // 3. GET BANANAS
    // We first want to use the overloaded insertion operator to print out the info for Minion2. Followed by a statement indicating minion2 is getting bananas. See example output for detail.

    //  Minion2 will get two bananas with pre-increment:
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;
    // Minion3 will then get one banana with post increment:
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;

    // 4. GET MINION COUNT
    // Finally, output the minion count with the static function printMinionCount().

    return 0;
}