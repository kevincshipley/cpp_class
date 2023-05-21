#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// 1. Your program will first make a struct named userAccount. The struct will contain four attributes storing the user information that you will be reading from input. Please make sure you name your attributes as following: username, nationality, age, accountBalance.

// USER ACCOUNT
struct userAccount {        // userAccount
    string username;        // <username>
    string nationality;     // <nationality>
    int age;                // <age>
    double accountBalance;  // <accountBalance>
};

int main()
{
    // 2. You will then read the user information and store them in an array of struct userAccount. The array can't hold more than 10 accounts, so you can set the size of the array to be 10.
    
    //ARRAY OF ACCOUNTS
    userAccount accounts[10]; 

    //INITIALIZE VARIABLES
    string username;        // <username>
    string nationality;     // <nationality>
    int age;                // <age>
    double accountBalance;  // <accountBalance>
    int acCounter = 0;      // acCounter will determine the position in the accounts array to store the inputted info

    //INPUT
    cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline:" << endl;
    //User will use EOF marker to indicate when they are done entering accounts.
    while (cin >> username >> nationality >> age >> accountBalance) { //will loop until \n or ctrl+Z is entered
        userAccount user;
        user.username = username; // enter input for username
        user.nationality = nationality; // enter input for nationality
        user.age = age; // enter input for age
        user.accountBalance = accountBalance; // enter input for accountBalance
        accounts[acCounter] = user; // add entered user to the accounts[]
        acCounter++; // increment count
    }

    // 3. Use all the stored user information to answer the following questions:

    int count = 0;
    double biggestBalance = 0; // answer for Q1
    double sumBalance = 0;  // answer for Q2
    int fromJapan = 0; // answer for Q3
    bool under21; // answer for Q4
    
    while (count <= acCounter) {
        // Q1
        double amount = accounts[count].accountBalance; // take the accountBalance and store in local variable "amount"
        sumBalance += amount; // add amount to the running sum

        // Q2
        if (amount > biggestBalance) { // compare amount to the previously biggest accountBalance and replace if bigger
            biggestBalance = amount;
        }

        // Q3
        // Use string comparison between users' nationality and "Japanese" to see whether the user is from Japan. You don't need to worry about upper or lower cases when comparing, so simply compare the string of a user's nationality with the string "Japanese".

        //the below for loop converts nationality to lowercase
        string origin = accounts[count].nationality;
        for (int i=0; i<origin.length(); i++) {
            origin[i] = tolower(origin[i]);
        }
        //then compares nationality without case mattering
        if (origin == "japanese") {
            fromJapan++;
        }

        // Q4
        // If there's at lease one user younger than 21, output "Yes" for this question. If not, output "No".
        if (accounts[count].age < 21) {
            under21 = true;
        }

        count++;
    }

    // (1) What's the highest account balance among all users?
    cout << "\nQ: What is the highest account balance of all users?" << endl;
    cout << setprecision(2) << fixed; // round to 2 decimals
    cout << "A: $" << biggestBalance << endl;

    // (2) What's the sum of account balance of all users?
    cout << "\nQ: What is the sum of all user account balances?" << endl;
    cout << setprecision(1) << fixed; // round to 1 decimal
    cout << "A: $" << sumBalance << endl;


    // (3) How many users come from Japan?
    cout << "\nQ: How many user come from Japan?" << endl;
    cout << "A: " << fromJapan << endl;

    // (4) Do we have any user younger than 21?
    cout << "\nQ: Are any users under 21?" << endl;
    if (under21) {
        cout << "A: Yes" << endl;
    }
    else {
        cout << "A: No" << endl;
    }
    cout << endl;

    // 4. Write the questions and answers to output in order with the following format.
    // Have questions and answers on separate lines, and have an empty line between each question.
    // Start the line of question with capital letter "Q" followed by a colon and a space.
    // Start the line of answer with capital letter "A" followed by a colon and a space again.
    // If the answer is a dollar amount, make sure you include the $ before the number at the output.
    // Always have two decimal places output for Q1(highest account balance), and have one decimal place output for Q2(average account balance). You can achieve that by using fixed and precision.

    return 0;
}