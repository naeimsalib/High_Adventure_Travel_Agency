//CSC 211 Lab 2

// Naeim Salib

#include <iostream>

using namespace std;

//Function Declration
void climbing();
void scuba();
void skyDive();
void spelunk();
int menu();

//Assigned variavles
const double climbRate = 300; // to Hold base rate of Devil's Courthouse adventure
const double scubaRate = 1000; // to hold base rate of Scuba Bahamas package
const double skyDiveRate = 400; // to hold base rate of Sky Dive Colorado Package
const double caveRate = 700; // to hold base rate of Barron Cliff Spelunk Package
const double climbInstruct = 100; // to holds charge for rock Climbing instruction.
const double scubaInstruct = 100; // to holds charge for scuba instruction.
const double dailyCampRental = 40; //to hold daily charge, per person for equipment rental.
const double dayLodge1 = 65;  // holds daily cost of lodging option 1 of sky dive Colorado package.(Wilderness Lodge)
const double dayLodge2 = 120; // Holds daily cost of lodging option 2 of sky dive Colorado package.(Luxury Inn.)


//Main Function that calls Menu Function and Displays program Control to the appropriate module,
//Based on the User's Choice of package.
int main(){
    
    int choice; // Holds User Input Choice for package.
    
    do {
        choice = menu();
        
        //Switch Case to call the function according to user's choice
        switch (choice){
                
        case 1:
                climbing ();
        break;
                
        case 2:
                scuba ();
        break;
                
        case 3:
                skyDive ();
        break;
                
        case 4:
                spelunk ();
        break;
                
        default:
                cout << "Wrong input" << endl;
                
        }
        
    } while (choice != 5);
    
    cout << "Exiting Program" << endl;

    return 0;
}
   
//Function To Display a menu listing the vacation packages.
//Allows the user to enter a selection, which is returned to the main Function
int menu(){
    
    cout << "High Adventure tavel Agency" << endl;
    cout << "----------------------------" << endl;
    
    cout << "1. Camping\n";   //Choice index for users
    cout << "2. Scuba Diving\n";
    cout << "3. Sky Dive\n";
    cout << "4. Spelunk\n";
    cout << "Please 1, 2, 3, 4, or 5: ";
    int choice;
    cin >> choice;
    return choice;
}

// Function to Ask the user for data necessary to calculate charges for the Devil's Courthouse Adventure Weekend Package
void climbing() {
    
    double beginner, advanced, renting, baseCharge, instruction, totalCharge,discount = 0;
    
    cout << endl;
    cout << "Devil's Courthouse Adventure Weekend" << endl;
    cout << "--------------------------------------"<< endl;
    
    cout << "How many will be going who need an instructor? ";
    cin >> beginner;
    cout << "How many Advanced Climbers will be going? ";
    cin >> advanced;
    cout << "How many will rent camping eqipment? ";
    cin >> renting;
    
    baseCharge = climbRate * (beginner + advanced);
    instruction = climbInstruct * beginner;
    
    //calculates The Customer's Discounts
    if (beginner + advanced >= 5){
        discount = baseCharge * 0.1;
    }
    totalCharge = baseCharge + instruction - discount +
    40 * 3 * renting;
    
    cout << "Number in party: " << beginner + advanced << endl;
    cout << "Base Charge: $ " << baseCharge << endl;
    cout << "Instruction Cost: $" << instruction << endl;
    cout << "Equipment Rental: $" << 40 * 3 * renting << endl;
    cout << "Discount $" << discount << endl;
    cout << "Total charge: $"<< totalCharge << endl;
    cout << "Required Deposit: $" << totalCharge * 0.5 << endl;
    cout << endl;
    cout << endl;
}

// Function to Ask the user for data necessary to calculate charges for the Scuba bahamas Package
void scuba(){
    
    double beginner, advanced, baseCharge, instruction, totalCharge,discount = 0;
    
    cout << endl;
    cout << "Scuba Bahama" << endl;
    cout << "-------------------------------------" << endl;

    
    cout << "How many will be going who need an instructor? ";
    cin >> beginner;
    cout << "How many advanced scuba divers be going? ";
    cin >> advanced;
    
    baseCharge = scubaRate * (beginner + advanced);
    
    //calculates The Customer's Discounts
    if (beginner + advanced >= 5){
        discount = baseCharge * 0.1;
    }
    
    instruction = scubaInstruct * beginner;
    totalCharge = baseCharge + instruction - discount;
    
    cout << "Number in Party: " << beginner + advanced << endl;
    cout <<" Base charge: $ " << scubaRate << endl;
    cout << "Instruction Cost: $" << instruction << endl ;
    cout << "Discount: $" << discount << endl;
    cout << "Total charge: $" << totalCharge << endl;
    cout << "Required Deposit: $ " << totalCharge * 0.5 << endl;
    
    cout << endl;
    cout << endl;
    
}

// Function to Ask the user for data necessary to calculate charges for the Sky Dive Colorado package
void skyDive(){
    
    double number, baserate, wildernessLodge, luxuryInn, lodge, totalCharge,discount = 0;
    
    cout << "Sky Dive Colorado" << endl;
    cout << "-----------------------------------" << endl;
    
    cout << "How many will be going? ";
    cin >> number;
    
    cout << "How many Will stay at wilderness Lodge? ";
    cin >> wildernessLodge;
    
    cout << "How many will stay at Luxury Inn? ";
    cin >> luxuryInn;
    
    baserate = skyDiveRate * number;
    
    //calculates The Customer's Discounts
    if (number >= 5){
        discount = baserate * 0.1;
        cout << "\nYour discount amount is $" << discount;
    }
    
    lodge = luxuryInn * dayLodge2 + wildernessLodge * dayLodge1;
    totalCharge = baserate + lodge - discount;
    cout << "Number in party: " << number <<endl;
    cout << "Base Charge: " << baserate << endl;
    cout << "Lodging: $" << lodge << endl;
    cout << "Discount: $" << discount << endl;
    cout << "Total charge: $" << totalCharge << endl;
    cout << "Required Deposit: $ " << totalCharge * 0.5 << endl;
    
    cout << endl;
    cout << endl;
    
}

// Function to Asks the user for data necessary to calculate charges for Barron Cliff Spelunk package
void spelunk(){
    
    double number, baseRate, totalCharge,renting, rentalCost, discount = 0;
    
    cout << "Barron Cliff Spelunk weekend" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Please enter the number of people in party? ";
    cin >> number;
    cout << "Please enter the number of party renting equipment? ";
    cin >> renting;
    
    rentalCost = dailyCampRental * 8 * number;
    baseRate = caveRate * number;
    
    //calculates The Customer's Discounts
    if (number >= 5){
        discount = baseRate * 0.1;
    }
    
    cout << "Number in Party: " << number << endl;
    cout << "Base charge: $ " << baseRate << endl;
    cout << "Equipment rental $" << rentalCost << endl;
    cout << "Discount: $ " << discount << endl;
    cout << "Total charge: $" << baseRate + rentalCost - discount << endl;
    cout << "Required Deposit: $ " << totalCharge * 0.5 << endl;
    
    cout << endl;
    cout << endl;
}


