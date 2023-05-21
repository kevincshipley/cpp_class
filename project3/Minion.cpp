// This is the class source file, where the Class Implementation happens

/*
Implementation:
- Defines the detail logic of each operations
- Normally implemented in a separate source file
*/

#include "Minion.h"
using namespace std;

// CONSTRUCTOR
Minion::Minion() {
    // Minion::name = mName;
    // Minion::height = mHeight;
    // Minion::eyes = mEyes;
    // Minion::bananasOwned = mBananasOwned;
}

// GETTERS
const int Minion::getBananas() {
    return Minion::bananasOwned;
}
const string Minion::getName() {
    return Minion::name;
}


// The greater than operator(>) and the smaller than operator(<) should both return a boolean, be constant, and take constant reference as parameters. These two functions should compare the height of two minions.
bool Minion::operator>(const Minion &m) const {
    return this->height > m.height;
};
bool Minion::operator<(const Minion &m) const {
    return this->height < m.height;
};
