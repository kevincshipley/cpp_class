#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// SYSTEM DETAIL //

/* Our system will read combat information and default settings for D.Va’s mech. It will then run three steps to analyze and prepare the mech for combat. First step is to calculate how much power D.Va needs given the number of enemies she's facing in combat. The second step is to load D.Va's mech with required power to fight the combat. Finally, the system will write a report into a file that D.Va can review before she goes into combat. */

//////// FUNCTION PROTOTYPES ////////

////// THREAT POWER CALCULATOR //////
float matrix_power(int bots_Power[], int bots_Count, float boss_Power)
{
    /* Arguments:
    - an integer array storing bots' power
    - an integer indicating the number of bots
    - a float indicating the boss' power */
    float sum = 0;
    // add the power of each bot
    for (int i=0;i<bots_Count;i++) {
        sum += bots_Power[i];
    }
    // add the power of the boss
    sum += boss_Power;

    // The function will return a float telling us the total damage of all our enemies.
    return sum;
};

////// MISSILE POWER CALCULATOR //////
template <typename T>
T single_missile_power(T args) {
    if (args <= 15) {
        return args * 2;
    } else {
        return args * 5;
    }
};

////// LOAD DEFENSE MATRIX //////
void load_dva(float& defense_Matrix, float matrix_Power_Required)
// Parameters: 
// currently loaded power of defense matrix (defenseMatrix)*
// required power (matrixPowerRequired)

// *function will update the value of defenseMatrix (pass-by-reference)
{
    // check how much damage the current defense matric can absorb (value of defenseMatrix):
    
    // if matrixPowerRequired > defenseMatrix we need to update the defenseMatrix with the value from matrixPowerRequired
    if (matrix_Power_Required > defense_Matrix) {
        defense_Matrix = matrix_Power_Required;
        cout << "\tDefense Matrix insufficient. Updating..." << endl << "\tDefense Matrix: " << defense_Matrix << endl;
    } 
    // if matrixPowerRequired < defenseMatrix then we don't need to update
    else {
        cout << "\tDefense Matrix suficient for combat." << endl;
    };

};

////// LOAD MICRO MISSILES ////// 
void load_dva(int& micro_Missiles, float missile_Power_Required)
// Parameters:
// the number of micro missiles we currently have in the mech (microMissiles)
// the missilePowerRequired
{
    // The number of micro missiles needed is equal to missilePowerRequired divided by 60.
    // Make sure you round up to an integer, you can use ceil() from <cmath> to round up.
    int missile_Need = ceil(missile_Power_Required / 60);
    
    // if the number of missiles needed is less than the current missiles loaded(microMissiles) then we don't need to change it, but if it's larger, we update the number of micro missiles in the mech.
    if (missile_Need > micro_Missiles) {
        micro_Missiles = missile_Need;
        cout << "\tMicro Missiles loaded insufficient. Updating..." << endl << "\tMicro Missiles: " << micro_Missiles << endl;
    } else {
        cout << "\tMicro Missiles loaded sufficient for combat." << endl;
    }
};

int main() {

    //////// STEP 1: READ COMBAT INFORMATION ////////

    // The monitoring system will give your system a file("combat.txt") containing combat information. When you test your code locally, feel free to download the "combat.txt" file from Canvas to test your code.

    ifstream combat;
    combat.open("combat.txt", ios::in);

    // an integer botsCount to store the number of bots
    int botsCount = 0;
    // an integer array botsPower[] to store all bot damages [9 13 4 8 6]
    int botsPower[10];
    // a float bossPower to store the damage of the boss [87.15]
    float bossPower = 0.00;
    // an integer microMissiles to store the number of missiles that are already loaded: 10
    int microMissiles = 0;
    // a float defenseMatrix to store the loaded power of the defense matrix: 100.0
    float defenseMatrix = 0.0;
    
    // check combat.txt is open
    if (combat.is_open()) {

        ////// THREAT ASSESSMENT //////
        
        // number of bots = line 1 of file = 5
        combat >> botsCount;
        // power of bots = line 2 except for end = [9 13 4 8 6]
        for (int i=0;i<botsCount;i++) {
            combat >> botsPower[i];
        }
        // boss power = line 2 end only = 87.15
        combat >> bossPower;

        ////// SELF ASSESSMENT //////

        // count of micro missiles = line 3 first = 10
        combat >> microMissiles;
        // defense matrix rating - line 3 second = 100.0
        combat >> defenseMatrix;

    } else {
        cout << "ERROR: combat file failed to open.\n";
    }
    
    combat.close();

    ////// REPORT //////

    // read count of bots
    cout << "ALERT: " << botsCount << " enemy bots and 1 enemy boss detected!" << endl;
    // read threat power levels of bots
    cout << "ASSESSING THREAT POWER LEVELS..." << endl;
    cout << "\tBots power levels: ";
    for (int i=0;i<botsCount; i++) {
        cout << botsPower[i] << " ";
    }   
    // read the boss power level
    cout << setprecision(2) << fixed; // round to 2 decimals
    cout << endl << "\tBoss power level: " << bossPower << endl;

    // read micro missile count
    cout << "ASSESSING MECH STATUS..." << endl;
    cout << "\tMicro Missiles: " << microMissiles << endl;
    // read defense matrix rating
    cout << setprecision(1) << fixed; // round to 1 decimal
    cout << "\tDefense Matrix: " << setprecision(1) << defenseMatrix << endl;

    cout << "ANALYZING COMBAT STATUS..." << endl;

    //////// STEP 2: CALCULATE POWER NEEDED ////////

    // Now your system needs to calculate how much more power is needed for the defense matrix system and how many more micro missiles D.Va needs to defeat the enemies. You will write two functions, one to calculate the damage the defense matrix system needs to absorb and another to calculate the power needed by the micro missile system.

    ////// THREAT POWER CALCULATOR //////
    cout << setprecision(2) << fixed; // round to 2 decimals
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);
    // report matrix power required
    cout << "\tTotal Threat Power Level: " << matrixPowerRequired << endl;

    ////// MISSILE POWER CALCULATOR //////
    float missilePowerRequired = 0.00;
    // calculate missiles needed for Boss
    missilePowerRequired += single_missile_power(bossPower);
    // calculate missiles needed for bots
    for (int i=0;i<botsCount;i++) {
        missilePowerRequired += botsPower[i];
    }
    // report micro missiles required
    cout << "\tDefense Matrix Required: " << missilePowerRequired << endl;

    //////// STEP 3: LOAD D.VA ////////

    // Now that we know how much power is needed for both the micro missile system and the defense matrix system, let's load D.Va's mech to make sure D.Va can win the battle. You will write two functions both with name load_dva. Both load_dva functions will return void and take in two parameters. The two functions have different behaviors. This is where you will use function overloading.    

    cout << "LOADING D.VA..." << endl;
    ////// LOAD DEFENSE MATRIX //////
    load_dva(defenseMatrix, matrixPowerRequired);

    ////// LOAD MICRO MISSILES ////// 
    load_dva(microMissiles, missilePowerRequired);

    //////// STEP 4: REPORT ////////

    // Finally, let's write a summary report for D.Va to review before she heads into the combat. Write a file name "report.txt" into the current directory. 
    ofstream report;
    report.open("report.txt", ios::out);

    // check report.txt is open
    if (report.is_open()) {
        // D.VA's Combat Report
        report << "D.VA's Combat Report:\n";
        // Combat with [botsCount] enemy bots and one enemy boss with power [bossPower].
        report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << ".\n";
        // Loaded mech with [microMissiles] micro missiles and the defense matrix with power [defenseMatrix].
        report << "Loaded mech with " << microMissiles << " Micro Missiles and the Defense Matrix with power " << defenseMatrix << ".\n";
        // Ready for combat!
        report << "Ready for combat!" << endl;

        cout << "D.Va Combat Report submitted successfully.";
    } else {
        cout << "ERROR: report file failed to open.\n";
    }

    report.close();

    return 0;
}

/*1. READ COMBAT INFORMATION

The monitoring system will give your system a file("combat.txt") containing combat information. When you test your code locally, feel free to download the "combat.txt" file from Canvas to test your code.

In main(), open the file with ifstream and read the information. Please make sure you have logic to check file open in your code and close the file after you finish the file operations.

The given file will contain 3 lines. The first line has one number indicating the number of bots attacking the city. The next line has many integers indicating each enemy bot's damage followed by one float number indicating the enemy boss' damage. The last line is the default setting of D.Va's mech, one integer indicating the number of micro missiles the mech has loaded by default and one float indicating the default power of the defense matrix(the amount of damage defense matrix can absorb).

combat.txt:
5
9 13 4 8 6 87.15
10 100.0

This file is indicating that there're 5 enemy bots
with damage 9, 13, 4, 8, and 6. And an enemy boss with damage 87.15.
D.Va's mech by default has 10 micro missiles loaded and the defense matrix can absorb 100.0 damage from enemies.

When reading the combat file, you will have the following:

    an integer botsCount to store the number of bots
    an integer array botsPower[] to store all bot damages
    a float bossPower to store the damage of the boss
    an integer microMissiles to store the number of missiles that are already loaded
    a float defenseMatrix to store the loaded power of the defense matrix*/

/*2. CALCULATE POWER NEEDED

Now your system needs to calculate how much more power needed for the defense matrix system and how many more micro missiles D.Va needs to defeat the enemies. You will write two functions, one to calculate the damage the defense matrix system needs to absorb and another to calculate the power needed by the micro missile system.

    I. Defense Matrix Power:

    D.Va's defense matrix would need to take all damages from enemies. Your program will have a function named matrix_power which takes in three parameters:

        an integer array storing bots' power
        an integer indicating the number of bots
        a float indicating the boss' power
    
    The function will return a float telling us the total damage of all our enemies.

    II. Micro Missile Power:

    D.Va's micro missile system would need to be more powerful than the enemies' power. We will make a function named single_missile_power which takes in an int or a float depends on what's being passed in as the parameter. If the passed in argument is less than or equal to 15, then it will returns 2 times the argument. If the passed in argument is greater than 15, then the function will return 5 times the argument. Note that this function will only take one parameter at a time, and the parameter could be of type int or float. The return type will match the type of the parameter. For example, single_missile_power(5) will return 10, and single_missile_power(16.5) will return 82.5. Therefore you will use template for this function.

    III. Main Function

    In main() you will call the matrix_power function and store the returned value in a float named matrixPowerRequired. You will also calculate the float missilePowerRequired which is the sum of all the returned values from the single_missile_power function by passing in all the bot's power(int) and the boss power(float).*/

/*3. Load D.Va

Now that we know how much power is needed for both the micro missile system and the defense matrix system, let's load D.Va's mech to make sure D.Va can win the battle. You will write two functions both with name load_dva. Both load_dva functions will return void and take in two parameters. The two functions have different behaviors. This is where you will use function overloading.

Load Defense Matrix: The first load_dva function will take the currently loaded power of the defense matrix(variable defenseMatrix) and the required power(variable matrixPowerRequired) as the two parameters. The function will update the value of defenseMatrix, therefore you will need to pass-by-reference. Inside the function you need to first check how much damage the current defense matrix can absorb(the value of defenseMatrix). If the matrixPowerRequired is less than the defenseMatrix then we don't need to update it. But if matrixPowerRequired is larger, we need to update the defenseMatrix with the value from matrixPowerRequired.

Load Micro Missiles: Similar to the load_dva function above, this function will also take two parameters: the number of micro missiles we currently have in the mech microMissiles(read from file) and the missilePowerRequired(calculated from step2). This function can update the number of micro missiles, so make sure you pass in the number of micro missiles by reference. Inside this function, you want to update the number of micro missiles loaded in our mech(microMissiles). The number of micro missiles needed is equal to missilePowerRequired divided by 60. Make sure you round up to an integer, you can use ceil() from <cmath> to round up. For example, ceil(23.6) would return integer 24. Similar to the other load_dva function, if the number of missiles needed is less than the current missiles loaded(microMissiles) then we don't need to change it, but if it's larger, we update the number of micro missiles in the mech.

Main Function: In main(), you will need to run the load_dva function when loading the defense matrix system and when loading the micro missile system.*/

/*4. REPORT

Finally, let's write a summary report for D.Va to review before she heads into the combat. Write a file name "report.txt" into the current directory. The content of the report should look like this:

D.Va's Combat Report
Combat with 5 enemy bots and one enemy boss with power 87.15.
Loaded mech with 10 micro missiles and the defense matrix with power 127.15.
Ready for combat!

Note that the number of enemy bots, the boss power, the number of missiles, and the defense matrix power in the file are all results calculated from your program and inserted into the file.

Please make sure you have logic to check file open in your code and close the file after you finish.*/