#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;



int Game::split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

//try catch function for checking  if input is valid
bool Game::menuChecker(string choice)
{
    try
    {
        //tries to store as integer
        int c = stoi(choice);
        if (c > 0 and c <= 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(...)
    {
        return false;
    }
}
//function for tracking date
void Game::dayTracker(int day)
{
    //may
    if (trip.getMonth() == 3)
    {
        //checks for greater than number of days in month
        if (trip.getDay() + day > 31)
        {
            //adjusts date accordingly
            trip.setDay(day - (31 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        //handles case where day fits within bounds of month
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    //repeated this for every month through november
    else if (trip.getMonth() == 4)
    {
        if (trip.getDay() + day > 30)
        {
            trip.setDay(day - (30 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 5)
    {
        if (trip.getDay() + day > 31)
        {
            trip.setDay(day - (31 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 6)
    {
        if (trip.getDay() + day > 30)
        {
            trip.setDay(day - (30 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 7)
    {
        if (trip.getDay() + day > 31)
        {
            trip.setDay(day - (31 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 8)
    {
        if (trip.getDay() + day > 31)
        {
            trip.setDay(day - (31 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 9)
    {
        if (trip.getDay() + day > 30)
        {
            trip.setDay(day - (30 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 10)
    {
        if (trip.getDay() + day > 31)
        {
            trip.setDay(day - (31 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
    else if (trip.getMonth() == 11)
    {
        if (trip.getDay() + day > 30)
        {
            trip.setDay(day - (30 - trip.getDay()));
            trip.setMonth(trip.getMonth() + 1);
        }
        else
        {
            trip.setDay(trip.getDay() + day);
        }
    }
}

//another try catch for checking valid inputs for store amounts
bool Game::amountChecker(string choice)
{
    try
    {
        int c = stoi(choice);
        return true;
    }
    catch(...)
    {
        return false;
    }
}

//another try catch for the store, checking for valid inputs
bool Game::storeChecker(string choice)
{
    try
    {
        int c = stoi(choice);
        if(c >= 1 and c <=5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(...)
    {
        return false;
    }
}
//try catch for checking valid inputs in hunt function
bool Game::huntChecker(string choice)
{
    try
    {
        int c = stoi(choice);
        if(c >= 1 and c <= 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(...)
    {
        return false;
    }
}
//another try catch
bool Game::storeChecker2(string choice)
{
    try
    {
        int c = stoi(choice);
        if(c >= 1 and c <=6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(...)
    {
        return false;
    }
}
//try catch for picking month
bool Game::monthchecker(string month)
{
    try
    {
        int store = stoi(month);
        if(store <= 3 and store >= 1)
        {
            return true;            
        }
        else
        {
            return false;
        }

    }
    catch (...)
    {
        return false;
    }
}
//try catch for checking if chosen starting day fits withing chosen starting month
bool Game::daychecker(int month, string day)
{
    try
    {
        if (month == 1)
        {
            if (stoi(day) >= 1 and stoi(day) <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (month == 2)
        {
            if (stoi(day) >= 1 and stoi(day) <=30)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (stoi(day) >= 1 and stoi(day) <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    catch(...)
    {
        return false;
    }
}
//status update
void Game::statusUpdate()
{
    //prints everything needed for update
    cout << "Current date: " << trip.getMonth() << "/" << trip.getDay() << "/1847" << endl;
    cout << "Miles traveled: " << trip.getMileage() << " miles" << endl;
    if (trip.getClosestFort() < trip.getClosestRiver())
    {
        cout << "Distance until next milestone: " << trip.getClosestFort() - trip.getMileage() << " miles" << endl;
    }
    else
    {
        cout << "Distance until next milestone: " << trip.getClosestRiver() - trip.getMileage() << " miles" << endl;
    }
    cout << "Food available: " << trip.getFood() << " pounds" << endl;
    cout << "Bullets remaining: " << trip.getBullets() << endl;
    cout << "Cash remaining: " << "$" << fixed << setprecision(2) << trip.getMoney() << endl;
}
//prints current bill for store visit
void Game::currentBill()
{
    cout << "Bill: " << endl;
    cout << "Oxen: " << trip.getOxen() / 2 << " yokes" << " | $" << (trip.getOxen() / 2) * 40 << endl;
    cout << "Food: " << trip.getFood() << " pounds" << " | $" << trip.getFood() * 0.50 << endl;
    cout << "Bullets: " << trip.getBullets() / 20 << " boxes" << " | $" << (trip.getBullets() / 20) * 2 << endl;
    cout << "Wagon parts: " << trip.getParts() << " parts" << " | $" << trip.getParts() * 20 << endl;
    cout << "Medical kits: " << trip.getMedkits() << " kits" << " | $" << trip.getMedkits() * 25 << endl;
    cout << "Remaining balance: " << "$" << trip.getMoney() << endl;
}
void Game::store()
{
    //variable declarations
    string choice;
    string oxen;
    string food;
    string bullets;
    string parts;
    string kits;
    bool one;
    bool two;
    bool three;
    bool four;
    bool five;
    //prints options
    cout << "Select a numerical option:" << endl << "1. Purchase Food (recommended at least 200 lbs.)" << endl << "2. Purchase bullets" << endl << "3. Purchase extra wagon parts (in case wagon breaks down)" << endl << "4. Purchase medical kits (in case of illness)" << endl << "5. Purchase oxen" << endl << "6. Leave store" << endl;
    cin >> choice;
    //checks for not exiting the store
        while (stoi(choice) != 6)
        {
            //invalid input checker
            while (!storeChecker2(choice))
            {
                cout << "invalid choice. Please pick again." << endl;
                cin >> choice;
            }
            if (stoi(choice) == 1)
            {
                //prints prices adjusted for price increases
                cout << "Food: 1 pound = $" << 0.50 + ( 0.50 * (trip.getFortIndex() * 0.25)) << endl;
                cout << "How many pounds would you like to purchase?" << endl;
                cin >> food;
                //checks for chosen amount less than current money
                while (!one)
                {
                    //invalid input
                    while (!amountChecker(food))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> food;
                    }
                    //checks for available funds
                    if (stoi(food) * (0.50 + (0.50 * trip.getFortIndex() * 0.25)) <= trip.getMoney())
                    {
                        //sets money and food accordingly
                        trip.setMoney(-stoi(food) * (0.50 + (0.50 * trip.getFortIndex() * 0.25)));
                        trip.setFood(stoi(food));
                        currentBill();
                        one = true;
                    }
                    //prints not enough funds
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> food;
                        one = false;
                    }
                }
                //resetting money variable
                one = false;
            }
            //THE ABOVE STEPS ARE REPEATED FOR ALL OPTIONS IN THE STORE
            else if (stoi(choice) == 2)
            {
                cout << "Bullets: 20 bullets in a box | box price: $" << 2 + (2 * (trip.getFortIndex() * 0.25)) << endl;
                cout << "How many boxes would you like to purchase?" << endl;
                cin >> bullets;
                while (!two)
                {
                    while(!amountChecker(bullets))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> bullets;                        
                    }
                    if (stoi(bullets) * (2 + (2 * trip.getFortIndex() * 0.25)))
                    {
                        trip.setMoney(-stoi(bullets) * (2 + (2 * trip.getFortIndex() * 0.25)));
                        trip.setBullets(stoi(bullets) * 20);
                        currentBill();
                        two = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> bullets;
                        two = false;
                    }
                }
                two = false;
            }
            else if (stoi(choice) == 3)
            {
                cout << "Wagon parts | part price: $" << 20 + (20 * (trip.getFortIndex() * 0.25)) << endl;
                cout << "How many parts would you like to purchase?" << endl;
                cin >> parts;
                while (!three)
                {
                    while(!amountChecker(parts))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> parts;
                    }
                    if (stoi(parts) * (20 + (20 * trip.getFortIndex() * 0.25)))
                    {
                        trip.setMoney(-stoi(parts) * (20 + (20 * trip.getFortIndex() * 0.25)));
                        trip.setParts(stoi(parts));
                        currentBill();
                        three = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> parts;
                        three = false;
                    }
                }
                three = false;
            }
            else if (stoi(choice) == 4)
            {
                cout << "Medkits | kit price: $" << 25 + (25 * (trip.getFortIndex() * 0.25)) << endl;
                cout << "How many kits would you like to purchase?" << endl;
                cin >> kits;
                while (!four)
                {
                    while(!amountChecker(kits))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> kits;
                    }
                    if (stoi(kits) * (25 + (25 * trip.getFortIndex() * 0.25)))
                    {
                        trip.setMoney(-stoi(kits) * (25 + (25 * trip.getFortIndex() * 0.25)));
                        trip.setParts(stoi(kits));
                        currentBill();
                        four = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> kits;
                        four = false;
                    }
                }
            }
            else if (stoi(choice) == 5)
            {
                cout << "Oxen | yoke price: $" << 40 + (40 * trip.getFortIndex() * 0.25) << endl;
                cout << "How many yokes would you like to purchase?" << endl;
                cin >> oxen;
                while (!five)
                {
                    while(!amountChecker(oxen))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> oxen;
                    }
                    if (stoi(oxen) * (40 + (40 * trip.getFortIndex() * 0.25)))
                    {
                        trip.setMoney(-stoi(oxen) * (40 + (40 * trip.getFortIndex() * 0.25)));
                        trip.setMedkits(stoi(oxen) * 2);
                        currentBill();
                        five = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> oxen;
                        five = false;
                    }
                }
                four = false;
            }
            //rechecking for exiting the store
            if (stoi(choice) == 5)
            {
                return;
            }
            //reprinting options
            cout << "1. Purchase Food (recommended at least 200 lbs.)" << endl << "2. Purchase bullets" << endl << "3. Purchase extra wagon parts (in case wagon breaks down)" << endl << "4. Purchase medical kits (in case of illness)" << endl << "5. Purchase oxen" << endl << "6. Leave store" << endl;
            cin >> choice;
            
            while (!storeChecker2(choice))
            {
                cout << "invalid choice. Please pick again." << endl;
                cin >> choice;
            }
        }
}
//initial store visit
void Game::storeInitial()
{
    string choice;
    string oxen;
    string food;
    string bullets;
    string parts;
    string kits;
    bool one;
    bool two;
    bool three;
    bool four;
    //special case for initial oxen purchasing with $100-200 conditions
    cout << "Oxen: 2 oxen in a yoke | yoke price: $40. You will not be able to purchase oxen again this store visit." << endl;
    cout << "How many yokes would you like to buy?" << endl;
    cin >> oxen;
    while (!amountChecker(oxen) or (stoi(oxen) * 40) < 100 or (stoi(oxen) * 40) > 200)
    {
        cout << "Invalid input. You must enter an integer number of yokes that equates to a dollar amount between $100-$200 inclusive." << endl;
        cout << "current balance: " << trip.getMoney() << endl;
        cout << "Enter a valid number of yokes" << endl;
        cin >> oxen;
    }
    //sets money and oxen accordingly
    trip.setMoney(-stoi(oxen) * 40);
    trip.setOxen(stoi(oxen) * 2);
    currentBill();
    //EVERYTHING HERE IS THE SAME AS PREVIOUS STORE FUNCTION without OXEN OPTION
    cout << "Select a numerical option:" << endl << "1. Purchase Food (recommended at least 200 lbs.)" << endl << "2. Purchase bullets" << endl << "3. Purchase extra wagon parts (in case wagon breaks down)" << endl << "4. Purchase medical kits (in case of illness)" << endl << "5. Leave store" << endl;
    cin >> choice;

        while (stoi(choice) != 5)
        {
            while (!storeChecker(choice))
            {
                cout << "invalid choice. Please pick again." << endl;
                cin >> choice;
            }
            if (stoi(choice) == 1)
            {
                cout << "Food: 1 pound = $0.50" << endl;
                cout << "How many pounds would you like to purchase?" << endl;
                cin >> food;
                while (!one)
                {
                    while (!amountChecker(food))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> food;
                    }
                    if (stoi(food) * 0.50 <= trip.getMoney())
                    {
                        trip.setMoney(-stoi(food) * 0.50);
                        trip.setFood(stoi(food));
                        currentBill();
                        one = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> food;
                        one = false;
                    }
                }
                one = false;
            }
            else if (stoi(choice) == 2)
            {
                cout << "Bullets: 20 bullets in a box | box price: $2" << endl;
                cout << "How many boxes would you like to purchase?" << endl;
                cin >> bullets;
                while (!two)
                {
                    while(!amountChecker(bullets))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> bullets;                        
                    }
                    if (stoi(bullets) * 2 <= trip.getMoney())
                    {
                        trip.setMoney(-stoi(bullets) * 2);
                        trip.setBullets(stoi(bullets) * 20);
                        currentBill();
                        two = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> bullets;
                        two = false;
                    }
                }
                two = false;
            }
            else if (stoi(choice) == 3)
            {
                cout << "Wagon parts | part price: $20" << endl;
                cout << "How many parts would you like to purchase?" << endl;
                cin >> parts;
                while (!three)
                {
                    while(!amountChecker(parts))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> parts;
                    }
                    if (stoi(parts) * 20 <= trip.getMoney())
                    {
                        trip.setMoney(-stoi(parts) * 20);
                        trip.setParts(stoi(parts));
                        currentBill();
                        three = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> parts;
                        three = false;
                    }
                }
                three = false;
            }
            else if (stoi(choice) == 4)
            {
                cout << "Medkits | kit price: $25" << endl;
                cout << "How many kits would you like to purchase?" << endl;
                cin >> kits;
                while (!four)
                {
                    while(!amountChecker(kits))
                    {
                        cout << "invalid input. Please pick again" << endl;
                        cin >> kits;
                    }
                    if (stoi(kits) * 25 <= trip.getMoney())
                    {
                        trip.setMoney(-stoi(kits) * 25);
                        trip.setMedkits(stoi(kits));
                        currentBill();
                        four = true;
                    }
                    else
                    {
                        cout << "not enough funds. choose another quantity" << endl;
                        cin >> kits;
                        four = false;
                    }
                }
                four = false;
            }
            if (stoi(choice) == 5)
            {
                return;
            }
            cout << "1. Purchase Food (recommended at least 200 lbs.)" << endl << "2. Purchase bullets" << endl << "3. Purchase extra wagon parts (in case wagon breaks down)" << endl << "4. Purchase medical kits (in case of illness)" << endl << "5. Leave store" << endl;
            cin >> choice;
            while (!storeChecker(choice))
            {
                cout << "invalid choice. Please pick again." << endl;
                cin >> choice;
            }
        }
}

    
//initial conditions
void Game::initialize()
{
    string p1;
    string p2;
    string p3;
    string p4;
    string p5;
    string choice;
    string choice2;
    string choice3;
    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN A FEW MONTHS --- IF YOU MAKE IT ALIVE." << endl;
    cout << "Enter your name" << endl;
    //adding player names to players vector
    cin >> p1;
    players.push_back(p1);
    cout << "Enter the names of your 4 companions, pressing enter after each name" << endl;
    cin >> p2;
    cin >> p3;
    cin >> p4;
    cin >> p5;
    players.push_back(p2);
    players.push_back(p3);
    players.push_back(p4);
    players.push_back(p5);
    cout << "1. Start on 3/28/1847" << endl << "2. Pick your own starting date" << endl;
    cin >> choice;
    //checking for valid input
    while (!huntChecker(choice))
    {
        cout << "invalid choice. Please pick again." << endl;
        cin >> choice;
    }
    //picking given starting date
    if (stoi(choice) == 1)
    {
        trip.setMonth(3);
        trip.setDay(28);
    }
    //picking your own date
    else
    {
        cout << "1. March" << endl << "2. April" << endl << "3. May" << endl;
        cin >> choice2;
        //checking for invalid input
        while (!monthchecker(choice2))
        {
            cout << "invalid choice. Please pick again" << endl;
            cin >> choice2;
        }
        //setting month accordingly
        trip.setMonth(stoi(choice2) + 2);
        if (stoi(choice2) == 1)
        {
            cout << "Enter a starting date in March" << endl;
            cin >> choice3;
            while(!daychecker(1, choice3))
            {
                cout << "invalid choice. Please pick again" << endl;
                cin >> choice3;
            }
            //setting day accordingly
            trip.setDay(stoi(choice3));
        }
        //REPEATED FOR OTHER TWO MONTHS
        else if (stoi(choice2) == 2)
        {
            cout << "Enter a starting date in April" << endl;
            cin >> choice3;
            while(!daychecker(2, choice3))
            {
                cout << "invalid choice. Please pick again" << endl;
                cin >> choice3;
            }
            trip.setDay(stoi(choice3));
        }
        else if (stoi(choice2) == 3)
        {
            cout << "Enter a starting date in May" << endl;
            cin >> choice3;
            while(!daychecker(3, choice3))
            {
                cout << "invalid choice. Please pick again" << endl;
                cin >> choice3;
            }
            trip.setDay(stoi(choice3));
        }
        
    }
    //prints instructions of game
    cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
    cout << "- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. OXEN MAY DIE ALONG THE ROUTE SO BUY AS MANY AS YOU THINK YOU'LL NEED" << endl;
    cout << "- FOOD. YOU'LL NEED ENOUGH TO SURVIVE THE JOURNEY" << endl;
    cout << "- AMMUNITION - YOU WILL NEED BULLETS FOR ATTACKS BY BANDITS, AND FOR HUNTING FOOD" << endl;
    cout << "- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
    cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW." << endl;
    cout << "HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
    //sets initial money
    trip.setMoney(1000);
}
//displays the menu
 void Game::displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "1. Rest" << endl;
     cout << "2. Continue on trail" << endl;
     cout << "3. Hunt" << endl;
     cout << "4. Quit" << endl;
 }

bool Game::puzzle()
{
    string choice;
    bool yesno;
    //generates 1-10 number
    int num = (rand() % 10) + 1;
    cout << "You have 3 tries to guess a number between 1-10." << endl;
    //asks for three choices
    for (int i = 0; i <= 2; i++)
    {
         cout << "Enter a guess" << endl;
         cin >> choice;
         //checks for if guess = number
         if (stoi(choice) == num)
         {
             yesno = true;
             break;
         }
         else
         {
             yesno = false;
         }
    }
    return yesno;
    
}
void Game::hunt()
{
    bool yesno = false;
    int rabbit = 0;
    int fox = 0;
    int deer = 0;
    int bear = 0;
    int moose = 0;
    //generates poundage between bounds for each animal
    int dpounds = (rand() % 26) + 30;
    int bpounds = (rand() % 251) + 100;
    int mpounds = (rand() % 301) + 300;
    string choice;
    string choice2;
    //checks for if you encountered each animal
     int num = (rand() % 100) + 1;
     if (num >= 1 and num <= 50)
     {
         yesno = true;
         cout << "You encountered a rabbit!" << endl;
         rabbit = 1;
         
         if (num >= 1 and num <= 25)
         {
             cout << "You encountered a fox!" << endl;
             fox = 1;
             if (num >= 1 and num <= 15)
             {
                 cout << "You encountered a deer!" << endl;
                 deer = 1;
                 if (num >= 1 and num <= 7)
                 {
                     cout << "You encountered a bear!" << endl;
                     bear = 1;
                     if (num >= 1 and num <= 5)
                     {
                         cout << "You encountered a moose!" << endl;
                         moose = 1;
                     }
                  }
             }
         }
     }
     //if you encounter no animals
     else
     {
         cout << "You encountered no animals." << endl;
     }
     //checks if animals are encountered
     if (yesno == true)
     {
         //prints choices
         cout << "Hunt:" << endl << "1. yes" << endl << "2. no" << endl;
         cin >> choice;
         //checks for invalid input
         while(!huntChecker(choice))
         {
             cout << "invalid choice. Please pick 1 or 2." << endl;
             cin >> choice;
         }
         if (stoi(choice) == 1)
         {
             //checks for adequate bullets
             if (trip.getBullets() < 10)
             {
                 cout << "not enough bullets, hunt failed." << endl;
                 return;
             }
             //checks if puzzle and hunt is successfull
             if(puzzle())
             {
                 cout << "hunt successful" << endl;
                 //sets ammo and food accordingly
                 trip.setBullets((-rabbit * 10) + (-fox * 8) + (-deer * 5) + (-bear * 10) + (-moose * 12));
                 trip.setFood((rabbit * 2) + (fox * 5) + (deer * dpounds) + (bear * bpounds) + (moose * mpounds));
                 //checks for if food exceeds 1000
                 if (trip.getFood() > 1000)
                 {
                     cout << "The wagon cannot hold more than 1000 pounds of food, so you leave the rest behind" << endl;
                     trip.setFood(1000 - trip.getFood());
                 }
             }
             else
             {
                 cout << "hunt failed" << endl;
             }
             cout << "How well would your party like to eat?" << endl << "1. Poorly" << endl << "2. Moderately" << endl << "3. Well" << endl;
             cin >> choice2;
             //invalid inputs
             while (!monthchecker(choice2))
             {
                 cout << "invalid choice. Please pick again." << endl;
             }
             //sets food according to choice of how well to eat
             if (stoi(choice2) == 1)
             {
                 trip.setFood(players.size() * -2);
             }
             else if (stoi(choice2) == 2)
             {
                 trip.setFood(players.size() * -3);
             }
             else
             {
                 trip.setFood(players.size() * -5);
             }
         }
         else
         {
             cout << "You chose not to hunt." << endl;
             return;
             
         }
     }
     //increments day
     dayTracker(1);
     return;
}
//rest function sets food and days according to random generated number of days
void Game::rest()
{
    //  random generate num between 1-3
    int num = (rand() % 3) + 1;
    dayTracker(num);
    trip.setFood(players.size() * (-3) * num);
    
    
}
//continue on trail function
void Game::trail()
{
    bool yesno = false;
    bool yesno2 = false;
    int num = (rand() % 71) + 70;
    //checks for if fort is closer than rivera nd if fort is closer than randomly generated miles
    if (trip.getClosestFort() < trip.getClosestRiver() and (trip.getClosestFort() <= trip.getMileage() + num))
    {
        yesno = true;
    }
    //same as above but for river instead
    else if (trip.getClosestRiver() < trip.getClosestFort() and (trip.getClosestRiver() <= trip.getMileage() + num))
    {
        yesno2 = true;
    }
    //sets mileage to fort mileage, prints message, opens store
    if (yesno)
    {
        trip.setMileage(trip.getClosestFort() - trip.getMileage());
        // cout << index << endl;
        cout << "You've arrived at " << trip.getFortnameAt(trip.getFortIndex()) << endl;
        store();
    }
    //setes mileage to river mileage, asks to rest or cross
    else if (yesno2)
    {
        string choice;
        trip.setMileage(trip.getClosestRiver() - trip.getMileage());
        cout << "You've arrived at " << trip.getRivernameAt(trip.getRiverIndex()) << endl;
        cout << "1. Rest" << endl << "2. Cross" << endl;
        cin >> choice;
        //invalid inputs
        while (!huntChecker(choice))
        {
            cout << "invalid input. Please pick again." << endl;
            cin >> choice;
        }
        while (stoi(choice) == 1 or stoi(choice) == 2)
        {
            //if choose to rest
            if (stoi(choice) == 1)
            {
                //sets days and food accordingly
                cout << "You rest for one day." << endl;
                dayTracker(1);
                trip.setFood(players.size() * -3);
                cout << "1. Rest" << endl << "2. Cross" << endl;
                cin >> choice;
                //invalid inputs
                while (!huntChecker(choice))
                {
                    cout << "invalid input. Please pick again." << endl;
                    cin >> choice;
                }
                if (stoi(choice) == 2)
                {
                    //checks for if depth > 3
                    if (trip.getRiverDepthAt(trip.getRiverIndex()) <= 3)
                    {
                        cout << "You cross the river." << endl;
                    }
                    else
                    {
                        //checks for sufficient funds to ferry
                        if (trip.getMoney() >= (players.size() * 10))
                        {
                            cout << "The cost for the ferry over this deep river was $10 per person." << endl;
                        }
                        //ends game if not sufficient funds
                        else
                        {
                            cout << "You don't have the funds to cross this river. Unfortunately you can't continue your journey." << endl;
                            gameEnd2();
                        }
                    }
                    break;
                }
            }
            //same as river code above but for if player chooses to cross immediately
            else
            {
                if (trip.getRiverDepthAt(trip.getRiverIndex()) <= 3)
                {
                    cout << "You cross the river." << endl;
                }
                else
                {
                    if (trip.getMoney() >= (players.size() * 10))
                    {
                        cout << "The cost for the ferry over this deep river was $10 per person." << endl;
                    }
                    else
                    {
                        cout << "You don't have the funds to cross this river. Unfortunately you can't continue your journey." << endl;
                        gameEnd2();
                    }
                }
                break;
            }
        }
    }
    //if mileage is less than nearest fort/river
    else
    {
        trip.setMileage(num);
    }
    //increments days and food
    dayTracker(14);
    trip.setFood(players.size() * -3 * 14);
}
//function for some certain ending conditions
bool Game::gameEnd2()
{
    bool yesno;
    yesno = true;
    return yesno;
}
//game end boolean function for conditions for overall while loop
bool Game::gameEnd()
{
    bool yesno = false;
    //no food
    if (trip.getFood() <= 0)
    {
        cout << "Your party ran out of food. You are unable to continue your journey" << endl;
        trip.setFood(0 - trip.getFood());
        yesno = true;
        
    }
    //0 oxen
    else if (trip.getOxen() <= 0)
    {
        yesno = true;
    }
    else if (gameEnd2())
    {
        yesno == true;
    }
    //took to long to reach Oregon
    else if (trip.getMonth() >= 11 and trip.getDay() >= 30 and trip.getMileage() < 2040)
    {
        cout << "You failed to reach Oregon City by the end of fall (November 30th)." << endl;
        yesno = true;
    }
    return yesno;
}
void Game::misfortune()
{
    string choice;
    int number = (rand() % 10) + 1;
    int num = (rand() % 3) + 1;
    int num2 = (rand() % 6) + 1;
    int num3 = (rand() % players.size());
    int num4 = (rand() % 2) + 1;
    int num5 = (rand() % 10) + 1;
    int num6 = (rand() % 3) + 1;
    //40 % chance
    if (number <= 4)
    {
        //checks for if sickness is the misfortune
        if (num == 1)
        {
            if (num2 == 1)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS TYPHOID!" << endl;
                //checks for if medkit
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    //50% chance of medkitt working
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        //erases dead player from vector
                        players.erase(players.begin() + (num3 - 1));
                        // checks if party leader is the one to die
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;
                            gameEnd2();
                        }
                    }
                }
                //if no medkits
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
            //REPEATED FOR ALL 6 DISEASES
            else if (num2 == 2)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS CHOLERA!" << endl;
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        players.erase(players.begin() + (num3 - 1));
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;

                            gameEnd2();
                        }
                    }
                }
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
            else if (num2 == 3)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS DIARRHEA!" << endl;
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        players.erase(players.begin() + (num3 - 1));
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;

                            gameEnd2();
                        }
                    }
                }
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
            else if (num2 == 4)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS THE MEASLES!" << endl;
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        players.erase(players.begin() + (num3 - 1));
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;

                            gameEnd2();
                        }
                    }
                }
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
            else if (num2 == 5)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS DYSENTERY!" << endl;
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        players.erase(players.begin() + (num3 - 1));
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;

                            gameEnd2();
                        }
                    }
                }
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
            else if (num2 == 6)
            {
                cout << "OH NO! " << players[num3].getName() << " HAS A FEVER!" << endl;
                if (trip.getMedkits() >= 1)
                {
                    cout << "You use a medkit, but they're not always effective." << endl;
                    if (num4 == 1)
                    {
                        cout << "The medkit worked! " << players[num3].getName() << " survived!" << endl;
                    }
                    else
                    {
                        cout << "The medkit was ineffective. " << players[num3].getName() << " died." << endl;
                        players.erase(players.begin() + (num3 - 1));
                        if (num3 == 0)
                        {
                            cout << "You, the party leader, have died!" << endl;

                            gameEnd2();
                        }
                    }
                }
                else
                {
                    cout << "You have no medkits. You may choose to:" << endl << "1. Rest" << endl << "2. Press on" << endl;
                    cin >> choice;
                    while (!huntChecker(choice))
                    {
                        cout << "invalid choice. please pick again." << endl;
                        cin >> choice;
                    }
                    if (stoi(choice) == 1)
                    {
                        dayTracker(3);
                        if (num5 <= 3)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                    else
                    {
                        if (num5 <= 7)
                        {
                            cout << "Unfortunately, " << players[num3].getName() << " has died." << endl;
                            players.erase(players.begin() + (num3 - 1));
                            if (num3 == 0)
                            {
                                cout << "You, the party leader, have died!" << endl;

                                gameEnd2();
                            }
                        }
                        else
                        {
                            cout << players[num3].getName() << " has become healthy again!" << endl;
                        }
                    }
                }
            }
        }
        //oxen dying
        else if (num == 2)
        {
            cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << trip.getOxen() - 1 << " OXEN LEFT." << endl;
            //sets oxen accordingly
            trip.setOxen(-1);
            if (trip.getOxen() == 0)
            {
                gameEnd();
            }
        }
        //wagon parts breaking
        else if (num == 3)
        {
            //if wheel
            if (num6 == 1)
            {
                cout << "OH NO! ONE OF YOUR WAGON WHEELS IS BROKEN!" << endl;
                //checks for if sufficient parts
                if (trip.getParts() >= 1)
                {
                    cout << "You replace the wheel and continue on your journey." << endl;
                    trip.setParts(-1);
                }
                //game end if no spare parts
                else
                {
                    cout << "You don't have anymore spare parts. Unfortunately, you're unable to continue your journey." << endl;
                    gameEnd2();
                }
            }
            //REPEATED FOR ALL 3 WAGON PARTS
            if (num6 == 2)
            {
                cout << "OH NO! ONE OF YOUR WAGON AXLES IS BROKEN!" << endl;
                if (trip.getParts() >= 1)
                {
                    cout << "You replace the axle and continue on your journey." << endl;
                    trip.setParts(-1);
                }
                else
                {
                    cout << "You don't have anymore spare parts. Unfortunately, you're unable to continue your journey." << endl;
                    gameEnd2();
                }
            }
            if (num6 == 3)
            {
                cout << "OH NO! ONE OF YOUR WAGON TONGUES IS BROKEN!" << endl;
                if (trip.getParts() >= 1)
                {
                    cout << "You replace the tongue and continue on your journey." << endl;
                    trip.setParts(-1);
                }
                else
                {
                    cout << "You don't have anymore spare parts. Unfortunately, you're unable to continue your journey." << endl;
                    gameEnd2();
                }
            }
        }
    }
    //if no misfortune
    else
    {
        return;
    }
    
   
}
void Game::raiders()
{
    string choice;
    //variables to make probability calculation easier
    double prob1 = pow(((trip.getMileage() / 100) - 4), 2) + 72;
    double prob2 = pow(((trip.getMileage() / 100) - 4), 2) + 12;
    double prob = ((prob1 / prob2) - 1) / 10;
    int num = (rand() % 1000) + 1;
    if (num <= (prob * 1000))
    {
        cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << "Select a numerical option:" << endl << "1. RUN!" << endl << "2. ATTACK! (You must pass a puzzle)" << endl << "3. SURRENDER!" << endl;
        cin >> choice;
        //invalid input
        while (!monthchecker(choice))
        {
            cout << "invalid choice. Please pick again." << endl;
            cin >> choice;
        }
        //sets oxen food and parts accordingly if chooses to run
        if (stoi(choice) == 1)
        {
            cout << "You escape with your lives, but in the hurry to escape you left behind an ox, 10 lbs of food, and a wagon part." << endl;
            trip.setOxen(-1);
            trip.setFood(-10);
            trip.setParts(-1);
        }
        //if chooses to attack
        else if (stoi(choice) == 2)
        {
            //if puzzle is successfull sets food and bullets accordingly
            if (puzzle())
            {
                cout << "You successfully vanquished the raiders! Your party gains 50 lbs. of food and 50 bullets." << endl;
                trip.setFood(50);
                trip.setBullets(50);
            }
            //if puzzle is unsuccessfull sets money and bullets accordingly
            else
            {
                cout << "You lost the battle. You lose a quarter of your cash and 50 bullets" << endl;
                trip.setMoney(trip.getMoney() * -0.25);
                trip.setBullets(-50);
            }
        }
        //if surrender sets money
        else
        {
            cout << "You surrender and the raiders take a quarter of your cash." << endl;
            trip.setMoney(trip.getMoney() * -0.25);
        }
    }
    else
    {
        return;
    }
}
//menu function
bool Game::menu()
{
    bool yesno = true;
    string num;
    statusUpdate();
    //display status update
    // display all three choices with numbers
    displayMenu();
    cin >> num;
    //invalid inputs
    while (!menuChecker(num))
    {
        cout << "invalid input. Please pick again." << endl;
        cin >> num;
    }
    //calls each funciton according to choice by players
    if (stoi(num) == 1)
    {
        // rest();
        rest();
    }
    else if (stoi(num) == 2)
    {
        trail();
    }
    else if (stoi(num) == 3)
    {
        hunt();
    }
    else 
    {
        yesno = false;
    }
    //call misfortune
    misfortune();
    //calls raiders
    if (!gameEnd())
    {
        raiders();
    }
    
    return yesno;

    // misfortune();

}
//prints ending stats
void Game::finalStatus()
{
    cout << "Final stats: " << endl << players[0].getName() << endl << "Miles travelled: " << trip.getMileage() << endl << "Food remaining: " << trip.getFood() << endl << "Cash remaining: $" << trip.getMoney() << endl;
}
void Game::start()
{
    bool yesno = true;
    
    string line;
    ifstream in_file;
    in_file.open("FORTS.TXT");
    //checks for if file is open
    if (in_file.is_open())
    {
        for (int i = 0; i < 6; i++)
        {
            string temp1[2];
            //reads line by line
            getline(in_file, line);
            //splits on comma
            split(line, ',', temp1, 2);
            string name = temp1[0];
            //sets each fortname in the fort array
            trip.setFortnameAt(i, name);
            int a = stoi(temp1[1]);
            //sets mileage
            trip.setFortMileageAt(i, a);
        }
    }
    //ABOVE IS REPEATED FOR RIVERS AS WELL BUT WITH DEPTH DATA MEMBER INCLUDED
    in_file.close();
    in_file.open("RIVERS.TXT");
    if (in_file.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            string temp2[3];
            getline(in_file, line);
            split(line, ',', temp2, 3);
            trip.setRivernameAt(i, temp2[0]);
            int b = stoi(temp2[1]);
            int c = stoi(temp2[2]);
            trip.setRiverMileageAt(i, b);
            trip.setRiverDepthAt(i, c);
        }
    }
    in_file.close();
    //calls initialize function
    initialize();
    //calls initial store function
    storeInitial();
    //while loop checking for end conditions
    while (!gameEnd() and trip.getMileage() < 2040 and yesno)
    {
        yesno = menu();
    }
    //prints message                                                                
    if (gameEnd())
    {
        cout << "Thanks for playing!" << endl;
        finalStatus();
    }
    //sets mileage to oregon city mileage, prints message
    else if (trip.getMileage() >= 2040)
    {
        cout << "Congratulations! You made it to Oregon City before Winter!" << endl;
        trip.setMileage(2040 - trip.getMileage());
        finalStatus();
    }
    else if (!yesno)
    {
        cout << "Thanks for playing!" << endl;
    }
    //outputting final stats to results.txt
    ofstream out_file;
    out_file.open("results.txt");
    out_file << "Final stats: " << endl << players[0].getName() << endl << "Miles travelled: " << trip.getMileage() << endl << "Food remaining: " << trip.getFood() << endl << "Cash remaining: " << trip.getMoney() << endl;



}
