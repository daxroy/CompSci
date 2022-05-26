#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Map.h"
#include "User.h"
#include "LogBook.h"
#include "Crew.h"
#include "Planet.h"

using namespace std;


int split(string userString, char theDelimeter, string storageArr[], int capacity){ // this function return the amount of substring between seperators 
    
    int lengthStr =userString.length(); 
    int counter  = 0; 
    int j=0;
    string container ="";
    if (userString == ""){ 
        return 0;
    }
    else{
        for (int i= 0; i<lengthStr; i++){ 
            if (counter < capacity){
                if (userString[i] != theDelimeter ){ 
                    container = container + userString[i];
                    if (i == lengthStr-1 ){ 
                        storageArr[j] = container; 
                        counter++; 
                    }
                }
                else {
                    storageArr[j] = container; 
                    container = ""; 
                    j++; 
                    counter++; 
                }
            }
            else {
                return -1;
            }
            
        }
        if (counter == 0){
            storageArr[0] = container; 
            return 1;
        }
        else{
            return counter; 
        }
    }

}


int main() {
    //Phase 1:
    bool test = true;
    User person;
    crew crewlist;
    string username;
    string ready;
    string line;
    int choice; 
    int money;
    int mn;
    int numWep;
    int numHealth;
    int diff;
    int num;
    string questions[86];
    string split1[2];
    string split2[4];
    vector<string> aliens;
    int left;
    int death; // 0 = give up, 1 = No Health, 2 = No Fuel, 3 = All Humans Left
    bool repeat = true;
    bool rep;
    int count = 0;
    string wep;
    logbook first;
    first.setPageNumber(count+1);
    vector<logbook> fullLog = {first};
    ifstream fin("crewmates.txt");
    if(fin.fail()) {
        cout << "File not found" << endl;
    } else {  
        char delimeter = ';';
        string arraySplit[2];
        int j = 0;
        while(getline(fin, line)) {

            split (line, delimeter,arraySplit, 2);
            
            crewlist.setName(j, arraySplit[0]);
            crewlist.setPerk(j, arraySplit[1]);
            j++;
        }
    }
    ifstream fin2("questions.txt");
    if(fin2.fail()) {
        cout << "Questions file not found" << endl;
    }
    int k = 0;
    while(getline(fin2, line)) {
        questions[k] = line;
        k++;
    }
    ifstream alien("alien_names.txt");
    if(alien.fail()) {
        cout << "Alien names file not found" << endl;
    }
    while(getline(alien, line)) {
        aliens.push_back(line);
    }
    cout << "Welcome to Space Exploration Game(tbd)! Enter your name to get started." << endl; 
    cin >> username;
    person.setName(username);
    cout << "Welcome " << person.getName() << "!" << endl;
    cout << "Now pick a cremate to help you with your journey!" << endl;
    cout << endl;
    cout << "1. " << crewlist.getName(0) << endl;
    cout << "Ability: " << crewlist.getPerk(0) << endl;
    cout << "2. " << crewlist.getName(1) << endl;
    cout << "Ability: " << crewlist.getPerk(1) << endl;
    cout << "3. " << crewlist.getName(2) << endl;
    cout << "Ability: " << crewlist.getPerk(2) << endl;
    cout << "4. " << crewlist.getName(3) << endl;
    cout << "Ability: " << crewlist.getPerk(3) << endl;
    cout << endl;
    cin >> choice;
    while(cin.fail()) {
        cout << "Insert a number as opposed to letters!"<<endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    } /// stops here 
    while(repeat == true) {
         
        switch(choice) {
            case 1:
                person.setCrew(0, 1);
            repeat = false;
            break;
            case 2:
                person.setCrew(0, 2);
            repeat = false;
            break;
            case 3:
                person.setCrew(0, 3);
            repeat = false;
            break;
            case 4:
                person.setCrew(0, 4);
            repeat = false;
            break;
            default:
            cout << "Invalid Input. Please re-enter a valid option" << endl;
            cin >> choice;
            repeat = true;
            break;
        }
    }
    repeat = true;
    cout << "Great choice! " << crewlist.getName(person.getCrew(0)-1) << " will bring a lot to your team. Pick another crewmate." << endl;
    cout << endl;
    if(choice != 1) {
        cout << "1. " << crewlist.getName(0) << endl;
        cout << "Ability: " << crewlist.getPerk(0) << endl;
    }
    if(choice != 2) {
        cout << "2. " << crewlist.getName(1) << endl;
        cout << "Ability: " << crewlist.getPerk(1) << endl;
    }
    if(choice != 3) {
        cout << "3. " << crewlist.getName(2) << endl;
        cout << "Ability: " << crewlist.getPerk(2) << endl;
    }
    if(choice != 4) {
        cout << "4. " << crewlist.getName(3) << endl;
        cout << "Ability: " << crewlist.getPerk(3) << endl;
    }
    cout << endl;
    cin >> choice;
    while(repeat == true) {
        switch(choice) {
            case 1:
            person.setCrew(1, 1);
            repeat = false;
            break;
            case 2:
            person.setCrew(1, 2);
            repeat = false;
            break;
            case 3:
            person.setCrew(1, 3);
            repeat = false;
            break;
            case 4:
            person.setCrew(1, 4);
            repeat = false;
            break;
            default:
                cout << "Invalid Input. Please re-enter a valid option" << endl;
                repeat = true;
            break;
        }
    }
    

    cout << "You have a very impressive crew. With your leadership, you will be sure to succeed!" << endl;
    cout << endl;
    cout << "WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!" << endl;
    cout << "TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien." << endl;
    cout << "SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack." << endl;
    cout << "MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%." << endl;
    cout << "FUEL. Fuel is an essential element for the spacecraft to travel to more planets." << endl;
    cout << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game." << endl;
    cout << endl;
    cout << "Hit enter when you have understood" << endl;
    
    cin.ignore();
    string confirm;
    do {
        getline(cin, confirm);
    } while(confirm.length()!= 0);

    repeat = true;
    while(repeat == true) {
        cout << "Which item do you wish to buy?" << endl << "1. Weapon" << endl << "2. Space Suit" << endl;
        cout << "3. Medical Kits" << endl << "4. Translator" << endl << "5. Fuel" << endl << "6. Purchase and Leave" << endl;
        cout << endl;
        cin >> choice;
         while(cin.fail()) {
            cout << "Insert a number as opposed to letters!"<<endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        } /// stops here 
        cout << endl;

        switch(choice) {
            case 1:
                cout << "Which weapon type do you wish to buy?" << endl << "1. Light Saber" << endl;
                cout << "2. Blaster" << endl << "3. Beam Gun" << endl << "4. Go back to menu" << endl;
                cin >> choice;
                while(repeat == true) {
                    switch(choice) {
                        case 1:
                            cout << "How many Light Sabres would you like ($1,000 each)?" << endl;
                            cin >> choice;
                            numWep = person.getWeapon(3); 
                            while(repeat == true) {
                                if(choice<=(2 - numWep)) {
                                    money = person.getMoney(); 
                                    if(money < choice * 1000) {
                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                    } else {
                                        person.setWeapon(0, to_string(choice));
                                        person.setMoney(money-(1000*choice));
                                        left = money-(1000*choice);
                                        cout << "You have $"+ to_string(left) +" left."<< endl;
                                    }
                                    repeat = false;
                                } else if(choice < 1) {  
                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                    cin >> choice;
                                } else {
                                    cout << "You cannot have more than two weapons at the same time" << endl;
                                    repeat = false;
                                }
                            }
                            break;
                        case 2:
                            cout << "How many Blasters would you like ($2,000 each)?" << endl;
                            cin >> choice;
                            numWep = person.getWeapon(3);
                            while(repeat == true) {
                                if(choice<=(2-numWep)) {
                                    money = person.getMoney();
                                    if(money<(choice*2000)) {
                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                    } else {
                                        person.setWeapon(1, to_string(choice));
                                        person.setMoney(money-(2000*choice));
                                        left = (money-(2000*choice));
                                        cout<< "You have $"+to_string(left)+" left."<<endl;
                                    }
                                    repeat = false;
                                } else if(choice<1) {
                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                    cin >> choice;
                                } else {
                                    cout << "You cannot have more than two weapons at the same time" << endl;
                                    repeat = false;
                                }
                            }
                            break;
                        case 3:
                            cout << "How many Beam Guns would you like ($5,000 each)?" << endl;
                            cin >> choice;
                            numWep = person.getWeapon(3);
                            while(repeat == true) {
                                if(choice<=(2-numWep)) {
                                    money = person.getMoney();
                                    if(money<(choice*5000)) {
                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                    } else {
                                        person.setWeapon(2, to_string(choice));
                                        person.setMoney(money-(5000*choice));
                                        left = (money-(5000*choice));
                                        cout<< "You have $"+to_string(left)+" left."<<endl;
                                    }
                                    repeat = false;
                                } else if(choice<1) {
                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                    cin >> choice;
                                } else {
                                    cout << "You cannot have more than two weapons at the same time" << endl;
                                    repeat = false;
                                }
                            }
                            break;
                        case 4:
                            repeat = false;
                            break;
                        default:
                            cout << "Invalid Input. Please re-enter a valid option" << endl;
                            repeat = true;
                            break;
                    }
                }
                repeat = true;
            break;
            case 2:
                cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
                cout << "1. Space Suit T2 is $5,000" << endl << "2. Space Suit T3 is $10,000" << endl;
                cout << "3. Space Suit T4 is $15,000" << endl << "4. Space Suit T5 is $20,000" << endl << "5. Return to menu" << endl;
                cin >> choice;
                while(repeat == true) {
                    switch(choice) {
                        case 1:
                            money = person.getMoney();
                            if(money<5000) {
                                cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            } else {
                                person.setSuitGrade(choice);
                                person.setMoney(money-5000);
                                person.setSuitHealth(100);
                                left = (money-5000);
                                cout<<"Your spacesuit is now a grade 2."<<endl;
                                cout<< "You have $ "+to_string(left)+" left."<<endl;
                            }
                            repeat = false;
                        break;
                        case 2:
                            money = person.getMoney();
                            if(money<10000) {
                                cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            } else {
                                person.setSuitGrade(choice);
                                person.setSuitHealth(100);
                                person.setMoney(money-10000);
                                left = (money-10000);
                                cout<<"Your spacesuit is now a grade 3."<<endl;
                                cout<< "You have $ "+to_string(left)+" left."<<endl;
                            }
                            repeat = false;
                        break;
                        case 3:
                            money = person.getMoney();
                            if(money<15000) {
                                cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            } else {
                                person.setSuitGrade(choice);
                                person.setSuitHealth(100);
                                person.setMoney(money-15000);
                                left = (money-15000);
                                cout<<"Your spacesuit is now a grade 4."<<endl;
                                cout<< "You have $ "+to_string(left)+" left."<<endl;
                            }
                            repeat = false;
                        break;
                        case 4:
                            money = person.getMoney();
                            if(money<20000) {
                                cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            } else {
                                person.setSuitGrade(choice);
                                person.setSuitHealth(100);
                                person.setMoney(money-20000);
                                left = (money-20000);
                                cout<<"Your spacesuit is now a grade 5."<<endl;
                                cout<< "You have $ "+to_string(left)+" left."<<endl;
                            }
                            repeat = false;
                        break;
                        case 5:
                            repeat = false;
                        break;
                    }
                }
                repeat = true;
            break;
            case 3: {
                cout << "How many medical kits would you like to purchase ($2,000)?" << endl;
                cin >> choice;
                numHealth = person.getHealthKits();
                while(repeat == true) {
                    if(choice<=(5-numHealth)) {
                        money = person.getMoney();
                        if(money<2000*choice) {
                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                        } else {
                            person.setHealthKits(choice);
                            person.setMoney(money-(2000*choice));
                            left = (money-(2000*choice));
                            cout<< "You have $"<<to_string(left)<<" left."<<endl;
                        }
                        repeat = false;
                    } else if(choice<1) {
                        cout << "Invalid input. Please re-enter a valid quantity" << endl;
                        cin >> choice;
                    } else {
                        cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
                        cin >> choice;
                    }
                }
                repeat = true;
                break;
            }
            case 4:
                if(!(person.getTranslator()))  {
                    cout << "Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no." << endl;
                    cin >> choice;
                    while(repeat == true) {
                        if(choice == 1) {
                            money = person.getMoney();
                            
                            if(money<5000) {
                                cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            } else {
                                person.setTranslator(true);
                                person.setMoney(money-5000);
                                left = (money-5000);
                                cout<< "You have $"<<to_string(left)<<" left."<<endl;
                            }
                            repeat = false;
                        } else if(choice == 0) {
                            cout << "Okay, come back if you ever find yourself needing it!" << endl;
                        } else {
                            cout << "Invalid input. Please re-enter a valid quantity" << endl;
                            cin >> choice;
                        }
                    }
                    repeat = true;
                } else {
                    cout << "You already have one" << endl;
                    cout << endl;
                }
            break;
            case 5:
                if(person.getCrew(0) == 3 || person.getCrew(1) == 3) {
                    person.setFuel(400000);
                }
                cout << "You have " << person.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel.";
                if(person.getFuel()==400000) {
                    cout << endl;
                    cout << "You already have the max amount of fuel." << endl;
                    break;
                }
                cout << " How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                cin >> choice;
                while(repeat == true) {
                    if(choice%10000!=0) {
                        cout << "Input must be in multiples of 10000s. Please re-enter a valid quantity" << endl;
                        cin >> choice;
                    } else if(choice<10000) {
                        cout << "Invalid Input. Please re-enter a valid multiple of 10000" << endl;
                        cin >> choice;
                    } else if(choice>400000-person.getFuel()) {
                        cout << "You cannot buy more fuel than the fuel tank's capacity, which is 400K. Please re-enter a valid input" << endl;
                        cin >> choice;
                    } else {
                        money = person.getMoney();
                        if(money<(choice/10)) {
                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                            cout << "Please re-enter a valid quantity" << endl;
                            cin >> choice;
                        } else {
                            int fuel = person.getFuel();
                            person.setFuel(choice+fuel);
                            person.setMoney(money-(choice/10));
                            left = (money-(choice/10));
                            cout<< "You have $"<<to_string(left)<<" left."<<endl;
                            repeat = false;
                        }
                    }
                }
                repeat = true;
            break;
            case 6:
                cout << "Great purchases, Elon is sending a Cybertruck with your supplies to you right now" << endl;
                repeat = false;
            break;
            default:
                cout << "Invalid Input. Please re-enter a valid option" << endl;
                choice = 0;
            break;
        }
    }
    cout << endl;
    cout << "Hit enter when you are ready to go to your first planet" << endl;
    cin.ignore();
    do {
        getline(cin, confirm);
    } while(confirm.length()!= 0);
    cout << "3... 2... 1... LIFTOFF! You are now in space. Press enter to start exploring your first planet" << endl;
    
    cin.ignore();
    do {
        getline(cin, confirm);
    } while(confirm.length()!= 0);
    //getch();
    //cin.get();








    //Phase 2: ///////
    //generate new planet and map
    planet nextPlanet;
    /// create map 
    /// spawn all the needed site,misfortune, npc on the map
    
    Map currentMap; // 
    person.setFuel(person.getFuel()-50000);
    
    int siteNum = rand()%6 + 1; 
    for(int i=0; i<siteNum; i++){
        int newRow = rand()%12;
        int newCol =  rand()%12;
        int typerand = rand()%6 + 1; 
        bool outcome = currentMap.spawnSite(newRow,newCol, typerand);
        if(outcome == false){ // false means spot alredy taken 
            siteNum++;
        }
    }
    int misfortuneNum = rand()%8 + 1; 
    for(int i=0; i<misfortuneNum; i++){
        int newRow = rand()%12;
        int newCol =  rand()%12;
        int typerand = rand()%4 + 1; 
        bool outcome = currentMap.spawnMisfortune(newRow,newCol,typerand);
        if(outcome == false){ // false means spot alredy taken 
            misfortuneNum++;
        }
    }
    int numNpc = 1;
    for(int i=0; i<numNpc; i++){
        int newRow = rand()%12;
        int newCol =  rand()%12;
        bool outcome = currentMap.spawnNPC( newRow,newCol);
        if(outcome == false){ // false means spot alredy taken 
            numNpc++;
        }
    }
    
    
    repeat = true;
    while(repeat == true) {
        cout << endl;
        cout << "Planet: " << fullLog[count].getPlanet().getName() << endl; // gets the planets name 
        currentMap.displayMap(); //Map print
        cout << "Select one:" << endl << "1. Move" << endl << "2. View status" << endl << "3. View log book" << endl << "4. Resource center" << endl;
        cout << "5. Report planet as habitable" << endl << "6. Enter wormhole to next planet" << endl << "7. Give up" << endl;
        cin >> choice;// HEREREREERRERR
        while(cin.fail()) {
            cout << "Insert a number as opposed to letters!"<<endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        } /// stops here 
        switch(choice) {
            case 1:
                while(repeat == true) {  
                    cout << endl;
                    cout << "Planet: " << fullLog[count].getPlanet().getName() << endl; 
                    currentMap.displayMap(); //print map again
                    cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
                    cin >> ready;
                    bool result;
                    if(ready == "w") {
                        result = currentMap.executeMove('w');
                        if(result == false){
                            cout<<"outside the range of the map!"<<endl;
                        }
                        
                    } else if(ready == "s") {
                        bool result2 = currentMap.executeMove('s');
                        if(result2 == false){
                            cout<<"outside the range of the map!"<<endl;
                        }
                    } else if(ready == "d") {
                        bool result3 = currentMap.executeMove('d');
                        if(result3 == false){
                            cout<<"outside the range of the map!"<<endl;
                        }
                    } else if(ready == "a") {
                       bool result4 = currentMap.executeMove('a');
                        if(result4 == -1){
                            cout<<"outside the range of the map!"<<endl;
                        }
                    } else if(ready == "m") {
                        //repeat = false;
                        break;
                    } else {
                        cout << "Invalid Input. Please enter a valid option" << endl;
                        continue;
                    }
                    cout << endl;
                    mn = person.getMoney();
                    person.setMoney(mn+50);
                    repeat = true;
                    if(currentMap.isMisfortuneLocation() == true) {
                        int MisfortuneType = currentMap.getMisfortuneType();
                        if(MisfortuneType == 1){
                            money = person.getMoney();
                            int rd = rand()%aliens.size();
                            numWep = person.getWeapon(3);
                            string alienName = aliens[rd];
                            aliens.erase(aliens.begin()+rd-1);
                            cout << "You just ran into " << alienName << "! Think you can beat this dangerous alien to help save humanity?" << endl;
                            cout << "1. Attack" << endl;
                            cout << "2. Forefit" << endl;
                            cin >> choice;
                            while(repeat = true) {
                                switch(choice) {
                                    case 1:
                                        if(numWep<1) {
                                            if(money<1000) {
                                                cout << "You neither have a weapon nor enough money to buy a weapon. Consequently, the alien attacked and defeated you :(" << endl;
                                                repeat = false;
                                                break;
                                            } else {
                                                repeat = true;
                                                while(repeat == true) {
                                                    cout << "You do not have a weapon to fight! Lets visit the resource center and buy a weapon!" << endl;
                                                    cout << "Which weapon type do you wish to buy?" << endl << "1. Light Saber" << endl;
                                                    cout << "2. Blaster" << endl << "3. Beam Gun" << endl;
                                                    cin >> choice;
                                                    switch(choice) {
                                                        case 1:
                                                            cout << "How many Light Sabres would you like ($1,000 each)?" << endl;
                                                            cin >> choice;
                                                            numWep = person.getWeapon(3);
                                                            while(repeat == true) {
                                                                if(choice<=(2 - numWep)) {
                                                                    money = person.getMoney();  
                                                                    if(money < choice * 1000) {
                                                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                                    } else {
                                                                        person.setWeapon(0, to_string(choice));
                                                                        person.setMoney(money-(1000*choice));
                                                                        cout<< "You have $" << money-(1000*choice) << " left."<<endl;
                                                                        repeat = false;
                                                                        break;
                                                                    }
                                                                    repeat = false;
                                                                } else if(choice < 1) {  
                                                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                                    cin >> choice;
                                                                } else {
                                                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                                    cin >> choice;
                                                                }
                                                            }
                                                        break;
                                                        case 2:
                                                            cout << "How many Blasters would you like ($2,000 each)?" << endl;
                                                            cin >> choice;
                                                            numWep = person.getWeapon(3);
                                                            while(repeat = true) {
                                                                if(choice<=(2-numWep)) {
                                                                    money = person.getMoney();
                                                                    if(money<(choice*2000)) {
                                                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                                    } else {
                                                                        person.setWeapon(1, to_string(choice));
                                                                        person.setMoney(money-(2000*choice));
                                                                        cout<< "You have $" << (money-(2000*choice)) << " left."<<endl;
                                                                        repeat = false;
                                                                        break;
                                                                    }
                                                                    repeat = false;
                                                                } else if(choice<1) {
                                                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                                    cin >> choice;
                                                                } else {
                                                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                                    cin >> choice;
                                                                }
                                                            }
                                                        break;
                                                        case 3:
                                                            cout << "How many Beam Guns would you like ($5,000 each)?" << endl;
                                                            cin >> choice;
                                                            numWep = person.getWeapon(3);
                                                            while(repeat = true) {
                                                                if(choice<=(2-numWep)) {
                                                                    money = person.getMoney();
                                                                    if(money<choice*5000) {
                                                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                                    } else {
                                                                        person.setWeapon(2, to_string(choice));
                                                                        person.setMoney(money-(5000*choice));
                                                                        cout<< "You have $" << (money-(5000*choice)) << " left."<<endl;
                                                                        repeat = false;
                                                                        break;
                                                                    }
                                                                    repeat = false;
                                                                } else if(choice<1) {
                                                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                                    cin >>choice;
                                                                } else {
                                                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                                    cin >> choice;
                                                                }
                                                            }
                                                        break;
                                                        default:
                                                            cout << "Invalid Input. Please re-enter a valid option" << endl;
                                                            repeat = true;
                                                        break;
                                                    }
                                                }
                                            }
                                            cout << "Let’s attack! Choose a weapon from your arsenal quickly and attack before the enemy advances!" << endl;
                                            if(person.getWeapon(0)>0) {
                                                cout << "1. Light Saber" << endl;
                                            }
                                            if(person.getWeapon(1)>0) {
                                                cout << "2. Blaster" << endl;
                                            }
                                            if(person.getWeapon(2)>0) {
                                                cout << "3. Beam Gun" << endl;
                                            }
                                            cin >> choice;
                                            rep = true;
                                            int r1 = 1+rand()%6;
                                            int r2 = 1+rand()%6;
                                            int fight;
                                            while(rep == true) {
                                                switch(choice) {
                                                    case 1:
                                                        if(person.getWeapon(0)>0) {
                                                            cout << "Invalid input, Please re-enter a valid option" <<endl;
                                                            cin >> choice;
                                                        } else {
                                                            if(person.getCrew(0) == 2||person.getCrew(1) == 2) {
                                                                fight  = (r1 * 1)*(1 + 1) - (r2 * person.getNumExplored());
                                                            } else {
                                                                fight  = (r1 * 1)*(1 + 0) - (r2 * person.getNumExplored());
                                                            }
                                                            rep = false;
                                                        }
                                                        break;
                                                    case 2:
                                                        if(person.getWeapon(1)>0) {
                                                            cout << "Invalid input, Please re-enter a valid option" <<endl;
                                                            cin >> choice;
                                                        } else {
                                                            if(person.getCrew(0) == 2||person.getCrew(1) == 2) {
                                                                fight  = (r1 * 2)*(1 + 1) - (r2 * person.getNumExplored());
                                                            } else {
                                                                fight  = (r1 * 2)*(1 + 0) - (r2 * person.getNumExplored());
                                                            }
                                                            rep = false;
                                                        }
                                                        break;
                                                    case 3:
                                                        if(person.getWeapon(2)>0) {
                                                            cout << "Invalid input, Please re-enter a valid option" <<endl;
                                                            cin >> choice;
                                                        } else {
                                                            if(person.getCrew(0) == 2||person.getCrew(1) == 2) {
                                                                fight  = (r1 * 3)*(1 + 1) - (r2 * person.getNumExplored());
                                                            } else {
                                                                fight  = (r1 * 3)*(1 + 0) - (r2 * person.getNumExplored());
                                                            }
                                                            rep = false;
                                                        }
                                                        break;
                                                    default:
                                                        cout << "Invalid input, Please re-enter a valid option" <<endl;
                                                        cin >> choice;
                                                    break;
                                                }
                                            }
                                            numWep = person.getWeapon(3);
                                            if(fight>0) {
                                                if(numWep == 2) {
                                                    cout << "You defeated " << alienName <<  "! Great Job! You saw the enemy's weapon lying down but you cannot carry with you as you already have 2 weapons. Unfortunately, you lost 10% of space suit health while fighting." << endl;
                                                    int h = person.getHealth();
                                                    if(person.getCrew(0) == 2||person.getCrew(1) == 2) {
                                                        person.setHealth(h-5);
                                                        cout << "Thanks to your doctor Lola, you gained back 5% Health." << endl;
                                                    } else {
                                                        person.setHealth(h-10);
                                                    }
                                                } else {
                                                    int r3 = rand()%3;
                                                    if(r3 == 0) {
                                                        wep = "Light Saber";
                                                    } else if(r3 == 1) {
                                                        wep = "Blaster";
                                                    } else {
                                                        wep = "Beam Gun";
                                                    }
                                                    cout << "You defeated " << alienName << "! Great Job! You won a " << wep<<  ". But you lost 10% of space suit health while fighting." << endl;
                                                    int h = person.getHealth();
                                                    person.setHealth(h-10);
                                                }
                                            } else {
                                                cout << "Aggh! You lost the battle! "<<alienName<<" seems to be hard for you! Tough times. Unfortunately, you experience the following due to this loss:" << endl;
                                                cout << "1. Your health was decreased by 30%." << endl;
                                                int h = person.getHealth();
                                                if(person.getCrew(0) == 2||person.getCrew(1) == 2) {
                                                        person.setHealth(h-5);
                                                        cout << "Thanks to your doctor Lola, you gained back 5% Health." << endl;
                                                } else {
                                                        person.setHealth(h-30);
                                                }
                                                int sh = 100-20*person.getSuitGrade();
                                                cout << "2. Your suit health was decreased by " << sh << "%" << endl;
                                                int suith = person.getSuitHealth();
                                                person.setSuitHealth(suith-sh);
                                                if(choice == 1) {
                                                        wep = "Light Saber";
                                                        num = person.getWeapon(0);
                                                        person.setWeapon(0, to_string(num-1));
                                                    } else if(choice == 2) {
                                                        wep = "Blaster";
                                                        num = person.getWeapon(1);
                                                        person.setWeapon(1, to_string(num-1));
                                                    } else if(choice == 3){
                                                        wep = "Beam Gun";
                                                        num = person.getWeapon(2);
                                                        person.setWeapon(2, to_string(num-1));
                                                    }
                                                cout << "3. You lost " << wep << ", the weapon you used for attacking the alien." << endl;
                                            }
                                            if(person.getHealth()<=0||person.getSuitHealth()<=0) {
                                                death = 1;
                                            }
                                        }
                                    break;
                                    case 2:
                                        numWep = person.getWeapon(3);
                                        if(numWep>0) {
                                            cout << "Really?! You chose to forfeit the battle? This is disappointing! You lost a weapon due to this decision. Hopefully, you git gud before you encounter the next alien." << endl;
                                            srand(time(NULL));
                                            diff = rand()%3;
                                            if(diff = 0) {
                                                num = person.getWeapon(diff);
                                                person.setWeapon(diff, to_string(num-1));
                                            } else if(diff == 1) {
                                                num = person.getWeapon(diff);
                                                person.setWeapon(diff, to_string(num-1));
                                            } else if(diff == 2) {
                                                num = person.getWeapon(diff);
                                                person.setWeapon(diff, to_string(num-1));
                                            }
                                        } else {
                                            cout << "Really?! You chose to forfeit the battle? This is disappointing! Since you do not have a weapon, you just lost a huge chunk of money from your account. Hopefully, you git gud before you encounter the next alien." << endl;
                                            if(money<=10000) {
                                                person.setMoney(0);
                                            } else {
                                                person.setMoney(money-10000);
                                            }
                                        }
                                        repeat = false;
                                    break;
                                    default:
                                        cout << "Invalid input, Please re-enter a valid option" << endl;
                                        cin >> choice;
                                    break;
                                }
                            }
                            cout << endl << endl;
                        }
                        else if(MisfortuneType == 2){
                            int helathNow =  person.getHealth();
                            int calculatedBody = helathNow-10; // the health of player after calculating 
                            person.setHealth(helathNow-10);  ///if event caused him death it should terminate program 
                            
                            int suitNow = person.getSuitHealth(); 
                            int calculatedHealth  =   suitNow - (50 - (10*person.getSuitGrade())) ;   
                            person.setSuitHealth(calculatedHealth);
                            cout<<"Oh no! You encountered Weather storm. Your health decreased by 10%."<<endl;
                            if(calculatedHealth ==0||calculatedBody==0){  //check if either suit or body are 0 and end game
                                repeat = true; 
                                death = 1;
                            }
                            cout << endl << endl;
                        }
                        else if(MisfortuneType == 3){
                            int helathyou =  person.getHealth();
                            person.setHealth(helathyou-50); 
                            int calculatedBody = helathyou-50; 
                            int calculatedHealth  =   person.getSuitHealth() - (50 - (10*person.getSuitGrade())) ;   
                            person.setSuitHealth(calculatedHealth);
                            cout<<"Oh no! You Fell into a crater. Your health decreased by 50%."<<endl;
                            if(calculatedHealth ==0||calculatedBody==0){  //check if either suit or body are 0 and end game
                                repeat = true; 
                                death = 1;
                            }
                            cout << endl << endl;
                        }
                        else if(MisfortuneType == 4){   
                            int healthy =  person.getHealth();
                            person.setHealth(healthy-30);
                            int calculatedBody =  healthy-30;
                            cout<<"Oh no! You have space sickness. Your health decreased by 30%."<<endl;
                            if(calculatedBody==0){  //check if either suit or body are 0 and end game
                                repeat = true; 
                                death = 1;
                            }
                        }
                        currentMap.revealMisfortune(currentMap.getPlayerRowPosition(),currentMap.getPlayerColPosition()); //might need to use getPlayerColPosition() as parameter
                        if(death == 1) {
                            repeat = false;
                            break;
                        }
                    } else if (currentMap.isNPCLocation()) {
                        cout<<"You have run into a friendly alien!"<<endl;
                        if(person.getTranslator()==false){
                            cout<<"You do not have a translator and cannot communicate with this alien. This alien may have useful information for you or money to offer, you can purchase a translator from the store if you would like to talk to them."<<endl;
                            repeat = true;
                            break;
                        }
                        else{
                            bool rep = true;
                            while(rep){
                                char order;
                                cout<<"You can communicate with this alien. You can defeat them in rock, paper, scissors three times and gain $200 (c) or you can ask them about the habitability of this planet (a). The chance of the alien telling the truth is 70%. You can only pick one option."<<endl;
                                cin>>order;
                                if(order == 'c'){
                                    char play;
                                    char toolsPlay[3]= {'r','p','s'}; 
                                    string toolsNames[3]= {"rock","paper","scissors"}; 
                                    int keepScore = 0;
                                    for(int i =0; i<3;i++){
                                        cout<<"Choose: rock(r), paper(p) or scissors(s)"<<endl;
                                        cin>>play;
                                        if(play == 'r' ||play=='p'||play=='s'){
                                            srand(time(NULL));
                                            int nums =   rand()%3; // the random number to choose from array of r,p,s for alien 
                                            cout<<"The alien chose "+toolsNames[nums]<<endl;
                                            if(toolsPlay[nums] == 's' && play=='p' ){
                                                cout<<"You lose this round"<<endl;
                                                keepScore--;
                                            }
                                            else if(toolsPlay[nums] == 'p' && play=='r' ){
                                                cout<<"You lose this round"<<endl;
                                                keepScore--;
                                            }
                                            else if(toolsPlay[nums] == 'r' && play=='s' ){
                                                cout<<"You lose this round"<<endl;
                                                keepScore--;
                                            }
                                            else if(toolsPlay[nums] == 'r'  && play=='p' ){
                                                cout<<"You win this round"<<endl;
                                                keepScore++;
                                            }
                                            else if(toolsPlay[nums] == 'p' && play=='s' ){
                                                cout<<"You win this round"<<endl;
                                                keepScore++;
                                            }
                                            else if(toolsPlay[nums] == 's' && play=='r' ){
                                                cout<<"You win this round"<<endl;
                                                keepScore++;
                                            }
                                            else if (toolsPlay[nums] ==play){
                                                cout<<"You tied this  round"<<endl;
                                                i--;
                                            }
                                        }
                                        else{
                                            cout<<"Invalid input"<<endl;
                                            i--;
                                        }
                                        
                                        
                                    }
                                    if(keepScore>0){
                                        cout<<"Congratulations! You defeated the alien and won $200"<<endl;
                                        int rich =  person.getMoney();
                                        person.setMoney(rich+200);
                                        
                                    }else{
                                        cout<<"You failed to deafeat the alien! You don't get any money."<<endl;
                                    }
                                    rep = false;
                                }
                                else if(order == 'a'){
                                    bool planetTruth = currentMap.isHabitable();
                                    int randVal =   rand()%10+1;
                                    int percent =  7;
                                    if(person.getCrew(0) == 4||person.getCrew(1) == 4) {
                                        percent =8;
                                        } 
                                    
                                    if(randVal <= percent){
                                        if(planetTruth==true){
                                            cout<<"Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                            fullLog[count].setAlienAssess(true);
                                        }
                                        else{
                                            cout<<"Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else."<<endl;
                                            fullLog[count].setAlienAssess(false);
                                        }
                                    }
                                    else{
                                        
                                        if(planetTruth==true){
                                            cout<<"Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else."<<endl;
                                            fullLog[count].setAlienAssess(false);
                                        }
                                        else{
                                            cout<<"Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                            fullLog[count].setAlienAssess(true);
                                        }
                                        
                                    }

                                    ifstream fin("alien_conversation.txt");

                                   
                                    if(fin.fail()) {
                                        cout << "Planet name file not found" << endl;
                                    }
                                    string liner;
                                    string arr[10];
                                    int number =  0;

                                    while(getline(fin, liner)) {

                                        arr[number] = liner.substr(2);
                                        number++;
                                    }
                                    if(fullLog[count].getAlienAssess() == "Habitable" ){
                                        int sideNum = 1;
                                        for(int i =5;i<10;i++) {    
                                            cout<<sideNum<<"."<<arr[i]<<endl;
                                            sideNum++;
                                        }
                                    }
                                    else{
                                        int sideNu = 1;
                                        for(int i=0;i<5;i++){
                                            cout<<sideNu<<"."<<arr[i]<<endl;
                                            sideNu++;
                                        }
                                        
                                    }
                                    cin >> choice;
                                    while(cin.fail()) {
                                        cout << "Insert a number as opposed to letters!"<<endl;
                                        cin.clear();
                                        cin.ignore();
                                        cin >> choice;
                                    } /// stops here 
                                    cout << endl;
                                    choice -=1;
                                    if(fullLog[count].getAlienAssess() == "Habitable") {
                                        cout << arr[choice+5] << endl;
                                    } else {
                                        cout << arr[choice] << endl;
                                    }
                                    
                                    
                                    rep = false;// terminating the Npc interaction loop
                                    

                                    ////

                                }
                                else {
                                    cout<<"Invalid input"<<endl;
                                }
                            }
                            
                        }
                        cout << endl << endl;


                    } else if (currentMap.isSiteLocation()==true) {
                        srand(time(NULL));
                        int trait = currentMap.getSiteTrait();
                        int diff = rand()%86;
                        string q = questions[diff];
                        split(q, ';', split1, 2);
                        split(split1[1], ',', split2, 4);
                        string placeholder;
                        string ans;
                        bool switch1 = false;
                        int dou = rand()%2;
                        if(dou == 0) {
                            placeholder = split2[0];
                            split2[0] = split2[1];
                            split2[1] = placeholder;
                            switch1 = true;
                        } else {
                            placeholder = split2[0];
                            split2[0] = split2[1];
                            split2[1] = split2[3];
                            split2[3] = placeholder;
                        }
                        cout << "Good job, you have found a site that may have some useful information about this planet. If you get this question right, the information will be revealed. "<<endl;
                        cout << "If you answer incorrectly though, you’ll become more frustrated and lose 1% health due to stress." << endl;
                        while(repeat == true) {
                            int hl = person.getHealth();
                            cout << split1[0] << endl;
                            cout << "a. " << split2[0] << endl;
                            cout << "b. " << split2[1] << endl;
                            cout << "c. " << split2[2] << endl;
                            cout << "d. " << split2[3] << endl;
                            cin >> ans;
                            cout << endl;
                            if(ans == "a") {
                                cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
                                person.setHealth(hl-1);
                            } else if(ans == "b") {
                                if(switch1) {
                                    cout << "Correct answer!" << endl;
                                    repeat = false;
                                } else {
                                    cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
                                    person.setHealth(hl-1);
                                }
                            } else if(ans == "c") {
                                cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
                                person.setHealth(hl-1);
                            } else if(ans == "d") {
                                if(switch1) {
                                    cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
                                    person.setHealth(hl-1);
                                } else {
                                    cout << "Correct answer!" << endl;
                                    repeat = false;
                                }
                            } else {
                                cout << "Invalid Input. Please enter a valid option." << endl;
                            }
                        }
                        repeat = true;
                        switch(trait) {
                            case 1:
                                cout << "You just discovered that this planet has water. This is a great sign. This discovery has been added to your log book." << endl;
                                fullLog[count].addHabitTrait("water");
                            break;
                            case 2:
                                cout << "You just discovered that this planet has oxygen. This is a great sign. This discovery has been added to your log book." << endl;
                                fullLog[count].addHabitTrait("oxygen");
                            break;
                            case 3:
                                cout << "You just discovered that this planet has fertile soil. This is a great sign. This discovery has been added to your log book." << endl;
                                fullLog[count].addHabitTrait("fertile soil");
                            break;
                            case 4:
                                cout << "You just discovered that this planet has toxic gas. This is not a promising sign... This discovery has been added to your log book." << endl;
                                fullLog[count].addInhabitTrait("toxic gas");
                            break;
                            case 5:
                                cout << "You just discovered that this planet has a bad atmosphere. This is not a promising sign... This discovery has been added to your log book." << endl;
                                fullLog[count].addInhabitTrait("bad atmosphere");
                            break;
                            case 6:
                                cout << "You just discovered that this planet has extreme temperatures. This is not a promising sign... This discovery has been added to your log book." << endl;
                                fullLog[count].addInhabitTrait("extreme temperatures");
                            break;
                        }
                        cout << endl << endl;
                    }
                } 
            break;
            case 2:
                cout << endl;
                cout << "Name: " << person.getName() << endl;
                cout << "Health: " << endl;
                for(int i = 0; i<20; i++) {
                    int bar = person.getHealth()/5;
                    if(i<bar) {
                        cout << "_";
                    } else {
                        cout << " ";
                    }
                }
                cout << " " << person.getHealth() << "%" << endl;

                cout << "Space Suit Health" << endl;
                for(int i = 0; i<20; i++) {
                    int bar = person.getSuitHealth()/5;
                    if(i<bar) {
                        cout << "_";
                    } else {
                        cout << " ";
                    }
                }
                cout << "  " << person.getSuitHealth() << "%" << endl;

                cout << "Fuel tank: " << person.getFuel() << " gallons" << endl;
                for(int i = 0; i<20; i++) {
                    int bar = (person.getFuel()/20000);
                    if(i<bar) {
                        cout << "_";
                    } else {
                        cout << " ";
                    }
                }
                cout << " " << person.getFuel()/4000 << "%" << endl;
                cout << endl;

                cout << "Money: $" << person.getMoney() << endl;
                cout << "Space Suit Tier: T" << person.getSuitGrade() << endl;
                cout << "Medical Kits: " << person.getHealthKits() << endl;
                cout << "WEAPONS: " << person.getWeapon(3) << endl;
                cout << "1. Light Saber: " << person.getWeapon(0) << endl;
                cout << "2. Blaster: " << person.getWeapon(1) << endl;
                cout << "3. Beam gun: " << person.getWeapon(2) << endl;
                cout << "Translator: " << person.getTranslator() << endl;
                cout << "Planets explored: " << person.getNumExplored() << endl;
                cout << "Planets accurately reported habitable: " << person.getRepHabit() << endl;
                cout << "Planets inaccurately reported habitable: " << person.getRepInhabit() << endl;
                cout << "Humans saved (in millions): " << person.getNumSaved() << endl;
                cout << "Humans perished (in millions): " << person.getNumLost() << endl;
                cout << "Humans left on Earth(in millions): " << person.getPopLeft() << endl;
                cout << endl << endl;
            break;
            case 3:
                cout << endl;
                cout << person.getName() << "'s Log Book page #" << fullLog[count].getPageNumber() << ": Planet " << fullLog[count].getPlanet().getName() << endl;
                cout << "Planet size (in diameter of 1000 kms): " << fullLog[count].getPlanet().getSize() << endl;
                cout << "Planet’s carrying capacity (in millions): " << fullLog[count].getPlanet().getCap() << endl;
                cout << "Habitable traits discovered: " << fullLog[count].getHabitTraits() << endl;
                cout << "Non-habitable traits discovered: " << fullLog[count].getInhabitTraits()<< endl;
                cout << "Friendly alien assessment: " << fullLog[count].getAlienAssess() << endl;
                cout << endl;
            break;
            case 4:
                while(repeat == true) {
                    if(person.getTranslator() == false) {
                        cout << "Which item do you wish to buy?" << endl << "1. Weapon" << endl << "2. Space Suit" << endl;
                        cout << "3. Medical Kits" << endl << "4. Translator" << endl << "5. Fuel" << endl << "6. Purchase and Leave" << endl;
                    } else {
                        cout << "Which item do you wish to buy?" << endl << "1. Weapon" << endl << "2. Space Suit" << endl;
                        cout << "3. Medical Kits" << endl << "5. Fuel" << endl << "6. Purchase and Leave" << endl;
                    }
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            cout << "Which weapon type do you wish to buy?" << endl << "1. Light Saber" << endl;
                            cout << "2. Blaster" << endl << "3. Beam Gun" << endl << "4. Go back to menu" << endl;
                            cin >> choice;
                            while(repeat == true) {
                                switch(choice) {
                                    case 1:
                                        cout << "How many Light Sabres would you like ($1,000 each)?" << endl;
                                        cin >> choice;
                                        numWep = person.getWeapon(3); 
                                        while(repeat = true) {
                                            if(choice<=(2 - numWep)) {
                                                money = person.getMoney();  
                                                if(money < choice * 1000) {
                                                    cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                } else {
                                                    person.setWeapon(0, to_string(choice));
                                                    person.setMoney(money-(1000*choice));
                                                    cout<< "You have $" << person.getMoney() << " left."<<endl;
                                                }
                                                repeat = false;
                                            } else if(choice < 1) {  
                                                cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                cin >> choice;
                                            } else {
                                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                cin >> choice;
                                            }
                                        }
                                        repeat = true;
                                    break;
                                    case 2:
                                        cout << "How many Blasters would you like ($2,000 each)?" << endl;
                                            cin >> choice;
                                            numWep = person.getWeapon(3);
                                            while(repeat = true) {
                                                if(choice<=(2-numWep)) {
                                                    money = person.getMoney();
                                                    if(money<(choice*2000)) {
                                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                    } else {
                                                        person.setWeapon(1, to_string(choice));
                                                        person.setMoney(money-(2000*choice));
                                                        cout<< "You have $" << person.getMoney() << " left."<<endl;
                                                    }
                                                    repeat = false;
                                                } else if(choice<1) {
                                                    cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                    cin >> choice;
                                                } else {
                                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                    cin >> choice;
                                                }
                                            }
                                            repeat = true;
                                    break;
                                    case 3:
                                        cout << "How many Beam Guns would you like ($5,000 each)?" << endl;
                                        cin >> choice;
                                        numWep = person.getWeapon(3);
                                        while(repeat = true) {
                                            if(choice<=(2-numWep)) {
                                                money = person.getMoney();
                                                if(money<choice*5000) {
                                                    cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                                } else {
                                                    person.setWeapon(2, to_string(choice));
                                                    person.setMoney(money-(5000*choice));
                                                    cout<< "You have $" << person.getMoney() << " left."<<endl;
                                                }
                                                repeat = false;
                                            } else if(choice<1) {
                                                cout << "Invalid Input. Please re-enter a valid quantity" << endl;
                                                cin >>choice;
                                            } else {
                                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                                cin >> choice;
                                            }
                                        }
                                        repeat = true;
                                    break;
                                    case 4:
                                        repeat = false;
                                    break;
                                    default:
                                        cout << "Invalid Input. Please re-enter a valid option" << endl;
                                        repeat = true;
                                    break;
                                }
                            }
                            
                            repeat = true;
                            break;
                        case 2:
                            cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
                            cout << "1. Space Suit T2 is $5,000" << endl << "2. Space Suit T3 is $10,000" << endl;
                            cout << "3. Space Suit T4 is $15,000" << endl << "4. Space Suit T5 is $20,000" << endl << "5. Return to menu";
                            cin >> choice;
                            while(repeat == true) {
                                switch(choice) {
                                    case 1:
                                        money = person.getMoney();
                                        if(money<5000) {
                                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                        } else {
                                            person.setSuitGrade(choice);
                                            person.setMoney(money-5000);
                                        }
                                    break;
                                    case 2:
                                        money = person.getMoney();
                                        if(money<10000) {
                                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                        } else {
                                            person.setSuitGrade(choice);
                                            int grade = person.getSuitGrade();
                                            person.setMoney(money-(10000-((grade-1)*5000)));
                                        }
                                    break;
                                    case 3:
                                        money = person.getMoney();
                                        if(money<15000) {
                                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                        } else {
                                            person.setSuitGrade(choice);
                                            person.setMoney(money-(15000-((person.getSuitGrade()-1)*5000)));
                                        }
                                    break;
                                    case 4:
                                        money = person.getMoney();
                                        if(money<20000) {
                                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                        } else {
                                            person.setSuitGrade(choice);
                                            person.setMoney(money-(20000-((person.getSuitGrade()-1)*5000)));
                                        }
                                    break;
                                    case 5:
                                        repeat = false;
                                    break;
                                }
                            }
                            repeat = true;
                            break;
                        case 3:
                            cout << "How many medical kits would you like to purchase ($2,000)?" << endl;
                            cin >> choice;
                            numHealth = person.getHealthKits();
                            while(repeat == true) {
                                if(choice<=(5-numHealth)) {
                                    money = person.getMoney();
                                    if(money<2000*choice) {
                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                    } else {
                                        person.setSuitGrade(choice);
                                        person.setMoney(money-5000);
                                    }
                                    repeat = false;
                                } else if(choice<1) {
                                    cout << "Invalid input. Please re-enter a valid quantity"<<endl;
                                    cin >> choice;
                                } else {
                                    cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
                                    cin >> choice;
                                }
                            }
                            repeat = true;
                            break;
                        case 4:
                            if(!(person.getTranslator()))  {
                                cout << "Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no." << endl;
                                cin >> choice;
                                while(repeat == true) {
                                    if(choice == 1) {
                                        money = person.getMoney();
                                        if(money<5000) {
                                            cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                        } else {
                                            person.setTranslator(true);
                                            person.setMoney(money-5000);
                                        }
                                        repeat = false;
                                    } else if(choice == 0) {
                                        cout << "Okay, come back if you ever find yourself needing it!" << endl;
                                    } else {
                                        cout << "Invalid input. Please re-enter a valid quantity" << endl;
                                        cin >> choice;
                                    }
                                }
                                repeat = true;
                            }
                            break;
                        case 5:
                            cout << "You have " << person.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel."<<endl;
                            cout << " How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                            cin >> choice;
                            while(repeat == true) {
                                if(choice%10000!=0) {
                                    cout << "Input must be in multiples of 10000s. Please re-enter a valid quantity" << endl;
                                    cin >> choice;
                                } else if(choice<10000) {
                                    cout << "Invalid Input. Please re-enter a valid multiple of 10000"<<endl;
                                    cin >> choice;
                                } else if(choice>400000-person.getFuel()) {
                                    cout << "You cannot buy more fuel than the fuel tank's capacity, which is 400K. Please re-enter a valid input"<< endl;
                                    cin >> choice;
                                } else {
                                    money = person.getMoney();
                                    if(money<(choice/10)) {
                                        cout << "You do not have enough funds to make this purchase. Your current balance is $" << money << endl;
                                    } else {
                                        int fuel = person.getFuel();
                                        person.setFuel(choice+fuel);
                                        person.setMoney(money-(choice/10));
                                    }
                                }
                            }
                            repeat = true;
                            break;
                        case 6:
                            cout << "Great purchases, Elon is sending a Falcon rocket with your supplies to you right now" << endl;
                            repeat = false;
                            break;
                        default:
                            cout << "Invalid Input. Please re-enter a valid option" << endl;
                            break;
                    }
            break;
            case 5:
                cout << "Are you sure you want to report back to mission control that this planet is habitable? As a reminder here is your logbook:" << endl;
                cout << person.getName() << "'s Log Book page #" << fullLog[count].getPageNumber() << ": Planet " << fullLog[count].getPlanet().getName() << endl;
                cout << "Planet size (in diameter of 1000 kms): " << fullLog[count].getPlanet().getSize() << endl;
                cout << "Planet’s carrying capacity (in millions): " << fullLog[count].getPlanet().getCap() << endl;
                cout << "Habitable traits discovered: " << fullLog[count].getHabitTraits() << endl;
                cout << "Non-habitable traits discovered: " << fullLog[count].getInhabitTraits() << endl;
                cout << "Friendly alien assessment: " << fullLog[count].getAlienAssess() << endl;
                cout << endl;
                cout << "Reporting this planet is irreversible. If the planet is in fact habitable you will save " << fullLog[count].getPlanet().getCap() << " million people! If it's not, the people sent to this planet will die" << endl;
                cout << endl;
                cout << "Ready to report? [y/n]" << endl;
                cin >> ready;
                rep = true; 
                while(rep == true) {
                    if(ready == "y") {
                        if(currentMap.isHabitable()) {
                            int saved = fullLog[count].getPlanet().getCap(); 
                            if(saved>person.getPopLeft()) {
                                saved = person.getPopLeft();
                            }
                            cout << "Congratulations! You have saved " << saved << "  million people! Planet " << fullLog[count].getPlanet().getName() << " is their new home. You have " << person.getPopLeft() << " million people to save left." << endl;
                            person.setRepHabit(person.getRepHabit()+1);
                            person.setPopLeft(saved);
                            person.setNumSaved(saved+person.getNumSaved());
                        } else {
                            int lost = fullLog[count].getPlanet().getCap();
                            if(lost>person.getPopLeft()) {
                                lost = person.getPopLeft();
                            }
                            cout << "Your choice has led to tragedy. " << lost << " million people were sent to planet " << fullLog[count].getPlanet().getName() << " and died due to its in-hospitable conditions. You still have " << person.getPopLeft() << " million people left to save, so keep exploring." << endl;
                            person.setRepInhabit(person.getRepInhabit()+1);
                            person.setPopLeft(lost);
                            person.setNumLost(lost+person.getNumLost());
                        }

                        rep = false;
                        if(person.getPopLeft()==0){
                            death = 3;
                            repeat = false;
                        }
                    } else if(ready == "n") {
                        cout << "Okay, feel free to come back to this page at any point" << endl;
                        rep = false;
                    } else {
                        cout << "Invalid input. Note that your input must be case-sensitive" << endl;
                        cin >> ready;
                    }
                }
            break;
            case 6:
                cout << "Are you sure you want to enter this wormhole? You will start a new page in your log book and you will lose fuel." << endl;
                cout << endl;
                cout << "Enter wormhole? [y/n]" << endl;
                cin >> ready;
                rep = true;
                while(rep == true) {
                    if(ready == "y") {
                        int planetFuel = fullLog[count].getPlanet().getFuelForPlanet();
                        nextPlanet.setFuelForPlanet(planetFuel);
                        int nextPlanetFuel = nextPlanet.getFuelForPlanet();
                        if(person.getFuel()<nextPlanetFuel) {
                            int reqFuel = nextPlanetFuel-person.getFuel();
                            cout << "You are about to travel to planet " << nextPlanet.getName() << " but you do not have sufficient fuel to travel. You will need " << reqFuel;
                            cout << " more gallons of fuel to travel to this planet, which costs $" << reqFuel/10 << ". Go ahead and make the purchase? [y/n]" << endl;
                            cin >> ready;
                            while(rep == true) {
                                if(ready == "y") {
                                    rep = false;
                                    money = person.getMoney();
                                    if(money<reqFuel/10) {
                                        cout << "You do not have the funds to make this purchase. Due to poor planning you have run out of fuel and money for exploration and you're left stranded on your current planet." << endl;
                                        death = 2;
                                        repeat = false;
                                    } else {
                                        person.setMoney(money-(reqFuel/10));
                                        person.setFuel(nextPlanetFuel);
                                        money = person.getMoney();
                                        cout << "Great Choice. Your current balance is $" << money << endl;
                                        cout << endl;
                                        cout << "Get ready! You are entering the wormhole in 3...2...1..." << endl;
                                        person.setFuel(0);
                                        count++;
                                        fullLog.push_back(logbook());
                                        fullLog[count].setPlanet(nextPlanet);
                                        fullLog[count].setPageNumber(count+1);
                                        nextPlanet = planet();
                                        currentMap.resetMap();
                                        siteNum = rand()%6 + 1; 
                                        for(int i=0; i<siteNum; i++){
                                            int newRow = rand()%12;
                                            int newCol =  rand()%12;
                                            int typerand = rand()%6 + 1; 
                                            bool outcome = currentMap.spawnSite(newRow,newCol, typerand);
                                            if(outcome == false){ // false means spot alredy taken 
                                                siteNum++;
                                            }
                                        }
                                        misfortuneNum = rand()%8 + 1; 
                                        for(int i=0; i<misfortuneNum; i++){
                                            int newRow = rand()%12;
                                            int newCol =  rand()%12;
                                            int typerand = rand()%4 + 1; 
                                            bool outcome = currentMap.spawnMisfortune(newRow,newCol,typerand);
                                            if(outcome == false){ // false means spot alredy taken 
                                                misfortuneNum++;
                                            }
                                        }
                                        numNpc = 1;
                                        for(int i=0; i<numNpc; i++){
                                            int newRow = rand()%12;
                                            int newCol =  rand()%12;
                                            bool outcome = currentMap.spawnNPC( newRow,newCol);
                                            if(outcome == false){ // false means spot alredy taken 
                                                numNpc++;
                                            }
                                        }
                                        //transport to new planet
                                    }
                                } else if(ready == "n") {
                                    cout << "You are not moving to the next planet as you have declined the payment. Redirecting you to the current planet..." << endl;
                                    rep = false;
                                } else {
                                    cout << "Invalid Input. Please re-enter a valid input(case-sensitive)" << endl;
                                    cin >> ready;
                                }
                            }
                        } else {
                            cout << "You are entering the wormhole in 3...2...1..." << endl;
                            rep = false;
                            count++;
                            person.setFuel(person.getFuel()-nextPlanetFuel);
                            fullLog.push_back(logbook());
                            fullLog[count].setPlanet(nextPlanet);
                            fullLog[count].setPageNumber(count+1);
                            nextPlanet = planet();
                            currentMap.resetMap();
                            siteNum = rand()%6 + 1; 
                            for(int i=0; i<siteNum; i++){
                                int newRow = rand()%12;
                                int newCol =  rand()%12;
                                int typerand = rand()%6 + 1; 
                                bool outcome = currentMap.spawnSite(newRow,newCol, typerand);
                                if(outcome == false){ // false means spot alredy taken 
                                    siteNum++;
                                }
                            }
                            misfortuneNum = rand()%8 + 1; 
                            for(int i=0; i<misfortuneNum; i++){
                                int newRow = rand()%12;
                                int newCol =  rand()%12;
                                int typerand = rand()%4 + 1; 
                                bool outcome = currentMap.spawnMisfortune(newRow,newCol,typerand);
                                if(outcome == false){ // false means spot alredy taken 
                                        misfortuneNum++;
                                }
                            }
                            numNpc = 1;
                            for(int i=0; i<numNpc; i++){
                                int newRow = rand()%12;
                                int newCol =  rand()%12;
                                bool outcome = currentMap.spawnNPC( newRow,newCol);
                                if(outcome == false){ // false means spot alredy taken 
                                    numNpc++;
                                }
                            }
                            //transport to new planet
                        }
                    } else if(ready == "n") {
                        cout << "Okay, feel free to come back to this page at any point" << endl;
                        rep = false;
                    } else {
                        cout << "Invalid Input. Please re-enter a valid input(case-sensitive)" << endl;
                        cin >> ready;
                    }
                }
            break;
            case 7:
                cout << "Are you sure you want to give up? [y/n]" << endl;
                cin >> ready;
                rep = true;
                while(rep == true) {
                    if(ready == "y") {
                        death = 0;
                        repeat = false;
                        rep = false;
                    } else if(ready == "n") {
                        rep = false;
                    } else {
                        cout << "Invalid Input. Please re-enter a valid input(case-sensitive)" << endl;
                        cin >> ready;
                    }
                }
                break;
            default:
                cout << "Invalid Input. Please re-enter a valid option" << endl;
                choice = 0;
            break;
            }
        }
    }
    






    //Phase 3:
    switch(death) {
        case 0: 
            cout << "It is disappointing to hear that you have quit, humanity was depending on you." << endl;
        break;
        case 1:
            cout << "You have died due to health loss. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space." << endl;
        break;
        case 2:
            cout << "You have died tue to a lack of fuel. Had you planned better you may have been able to prevent this. You can no longer explore space." << endl;
        break;
        case 3:
            cout << "All of humanity has left Earth! Your mission is over." << endl;
        break;
    }
    ofstream fout("results.txt");
    if(fout.fail()) {
        cout << "Results file failed to initialize" << endl;
        return 0;
    }
    int size;
    do {
        int min = 99;
        int index;
        size = fullLog.size();
        cout << "test1" << endl;
        for(int i = 0; i<size; i++) {
            string name1 = fullLog[i].getPlanet().getName();
            if(int(name1[7])<min) {
                index = i;
                min = int(name1[0]);
            }
        }
        fout << person.getName() << "'s Log Book page #" << fullLog[index].getPageNumber() << ": Planet " << fullLog[index].getPlanet().getName() << endl;
        fout << "Planet size (in diameter of 1000 kms): " << fullLog[index].getPlanet().getSize() << endl;
        fout << "Planet’s carrying capacity (in millions): " << fullLog[index].getPlanet().getCap() << endl;
        fout << "Habitable traits discovered: " << fullLog[index].getHabitTraits() << endl;
        fout << "Non-habitable traits discovered: " << fullLog[index].getInhabitTraits() << endl;
        fout << "Friendly alien assessment: " << fullLog[index].getAlienAssess() << endl;
        fout << endl;   
        fullLog.erase(fullLog.begin()+index);
    } while(size>1);
    ifstream fin3("results.txt");
    if(fin3.fail()) {
        cout << "Results file failed to initialize" << endl;
    }
    while(getline(fin3, line)) {
        cout << line << endl;
    }
    cout << "Here is a summary of how you did:" << endl;
    cout << "Cause of death: ";
    switch(death) {
        case 0: 
            cout << "Gave up" << endl;
        break;
        case 1:
            cout << "Health loss" << endl;
        break;
        case 2:
            cout << "Not enough fuel" << endl;
        break;
        case 3:
            cout << "All of humanity left" << endl;
        break;
    }
    int explored = person.getRepHabit()+person.getRepInhabit();
    cout << "Planets explored: " << explored << endl;
    cout << "Planets accurately reported as habitable: " << person.getRepHabit() << endl;
    cout << "Planets inaccurately reported as habitable: " << person.getRepInhabit() << endl;
    cout << "Humans saved(in millions): " << person.getNumSaved() << endl;
    cout << "Humans perished(in millions): " << person.getNumLost() << endl;
    int score = ((person.getNumSaved() - person.getNumLost()) / 8000 * (person.getRepHabit() + person.getRepInhabit()) / (explored)) * 100 ;
    cout << "TOTAL SCORE: " << score << endl;
    if(score == 100) {
        cout << "Great Job! You saved humanity! Try again to see if you can get the same score!" << endl;
    } else {
        cout << "Play again to see if you can do better!" << endl;
    }
    return 0;
}