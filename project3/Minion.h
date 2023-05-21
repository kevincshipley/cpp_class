// This is the header file, where the Class Interface happens
    // NOTES: Compiler uses header files to match definition and function calls

/*
Interface:
- Defines objects being store in the class
- Defines operations that can happen in the class
- Implemented in header files
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Detail Implementation
// For the class Minion, you would declare in a header file with safe check to prevent duplicate declaration, and define the source code of your class within a cpp file.

// When the code is compiled, the preprocessor checks whether STUDENT_H has been previously defined.
// If this is the first time we included the header, STUDENT_H will not have been defined. Then, the compiler defines STUDENT_H  and includes the contents of the file.
// If the header is already defined; the ifndef guard will ensure that the contents of the header will not be re-defined.
#ifndef MINION_H
#define MINION_H

class Minion
{
    // You will have four private attributes for your class Minion, including
    private:
        string name;
        float height;
        int eyes;
        int bananasOwned;
        // You will also have a private class static variable int minionCount. Your constructor should initialize all four private variables and also increase the minionCount every time it's called. The minionCount is used to keep track of how many minions we have created with the class Minion.
        static int minionCount;
        // NOTES: A static member is a “class-wide” member shared by all objects of the class, i.e., data that is shared by all instances of the class.

        // We need two getter function getBananas() and getName(), both constant, to give us access to the int bananasOwned and the string name.
        const int getBananas();
        const string getName();

    public:
        // CONSTRUCTOR
        Minion() {
            minionCount++; // adds to the minionCount whenever constructor is call, whenever Minion calss is instantiated
        };
        // DESTRUCTOR
        ~Minion() {
            minionCount--; // removes from minionCount when Destructor is called
        };

        // We also need a static function to print out the minionCount, as following:
        void Minion::printMinionCount() {
          cout << minionCount << " minions created." << endl;
        }

        // We will overload the following operators for the class Minion:

        // The greater than operator(>) and the smaller than operator(<) should both return a boolean, be constant, and take constant reference as parameters. These two functions should compare the height of two minions. 
        bool operator>(const Minion&) const;
        bool operator<(const Minion&) const;

        // The pre and post increment operators should give minions banana one at a time. Make sure to return reference for pre-increment and return the un-incremented version of the class for post increment.

        // preincrement
        Minion &operator++() {
            ++bananasOwned;
        }
        // postincrement - summy int variable
        Minion operator++(int) {
            bananasOwned++;
        }

        // insertion and output operator overloading
        friend ostream& operator<<(ostream&, const Minion&); // NOTES: Use const reference when we don’t modify the second param for cout
        friend istream& operator<<(istream&, Minion&); // NOTES: Use reference when we want to modify the first param for cin
};

// The insertion operator should output the following:
// The minion <name> is <height> inches tall, has <eyes> eye(s), and owns <bananasOwned> banana(s).

// Read the name, height, eyes, and bananasOwned from the class attributes. Ends the line with a newline. Please double check that the output format and spaces between each character match the example above.
ostream &operator<<(ostream &output, const Minion &ion) {
    output << "The minion " << ion.name << " is " << ion.height << " inches tall, has " << ion.eyes << " eye(s), and owns " << ion.bananasOwned << " banana(s)." << endl;
}

istream &operator<<(istream &input, Minion &onion) {
    input >> onion.name >> onion.height >> onion.eyes >> onion.bananasOwned;
}

#endif // MINION_H
// These header guards prevent re-declaration of any identifiers