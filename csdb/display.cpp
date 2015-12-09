#include "display.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include "personlist.h"
HANDLE hCon;

enum color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void setColor(color c){
    if(hCon == NULL)
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, c);
}

display::display(){

}

display::~display(){

}

void display::printSingle(person personToPrint){
    //colors in table
    color c1 = RED, c2 = DARKYELLOW, c3 = YELLOW, c4 = TEAL;
    //width of the columns in the table
    size_t l1 = 9, l2 = 15;
    //overwrites default value for column 2 if the length fields 'Name' or 'Known for' exceed the original size
    //length of column 1 always stays the same
    if(personToPrint.getKnownFor().size() > l2)
        l2 = personToPrint.getKnownFor().size();
    if(personToPrint.getName().size() > l2)
        l2 = personToPrint.getName().size();
    string tage;
    string fields[] = {"Name","Gender","Born","Died", "Age", "Known for"};
    setColor(c4);
    printf("id:%d\n", personToPrint.getId());
    for(int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        setColor(c2);
        cout << '+';
        for(int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        setColor(c3);
        cout << fields[i];
        setColor(c2);
        for(auto k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                setColor(c1);
                cout << personToPrint.getName();
                setColor(c2);
                for(auto k = personToPrint.getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //gender
            case 1:
                setColor(c1);
                cout << personToPrint.getGender();
                setColor(c2);
                for(auto k = personToPrint.getGender().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //born
            case 2:
                setColor(c1);
                cout << personToPrint.getDateBirth();
                setColor(c2);
                for(auto k = personToPrint.getDateBirth().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //died
            case 3:
                setColor(c1);
                cout << personToPrint.getDateDeath();
                setColor(c2);
                for(auto k = personToPrint.getDateDeath().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //age
            case 4:
                setColor(c1);
                tage = to_string(int(personToPrint.getAge()/365.25));
                cout << tage;
                setColor(c2);
                for(auto k = tage.size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //known for
            case 5:
                setColor(c1);
                cout << personToPrint.getKnownFor();
                setColor(c2);
                for(auto k = personToPrint.getKnownFor().size(); k < l2; k++){
                   cout << ' ';
                }
                cout << "|\n";\
            break;

            default:
                cout << "Error. " << endl;
            break;
        }

    }
    setColor(c2);
    cout << '+';
    for(int k = 0; k < l1; k++){
        cout << '-';
    }
    cout << '+';
    for(int k = 0; k < l2; k++){
        cout << '-';
    }
    cout << "+\n";
    setColor(WHITE);
}

person display::fillFormPerson(){
    bool valid = false, lastspace = false;
    string tname, tgender, tbirth, tdeath, tknown;
    char pos;
    person newPerson;

    cout << "Enter name(enter '-' to end input): "<< endl;
    //goes through each character in user input
    do {
        cin.get(pos);
        if (isspace(pos) && !lastspace && tname.size() > 0){
            tname += ' ';
            lastspace = true;
        }
        //'-' to end user input
        else if(pos == '-'){
            valid = true;
        }
        //if the character is neither '-' or ' ' it is appended to the name string
        else if(!isspace(pos)){
            tname += pos;
            lastspace = false;
        }

    } while (!valid);

    valid = false;
    lastspace = false;
    newPerson.setName(tname);

    cout << "Enter gender(Male/Female): " << endl;
    do{
        cin >> tgender;
        //changes user input so it isn't case sensitive
        transform(tgender.begin(), tgender.end(), tgender.begin(), ::tolower);
        if(tgender[0] == 'f')
            tgender[0] = 'F';
        else if(tgender[0] == 'm')
            tgender[0] = 'M';
        newPerson.setGender(tgender);
        valid = newPerson.isGenderValid();
        if(!valid)
            cout << "The gender you have entered is not valid. " << endl;
    }while(!valid);

    valid = false;

    cout << "Enter date of birth(dd/mm/yyyy): " << endl;
    do{
        cin >> tbirth;
        newPerson.setDateBirth(tbirth);
        valid = newPerson.isDateBirthValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    valid = false;

    cout << "Enter date of death(dd/mm/yyyy) or -1 if the person is still alive:" << endl;
    do{
        cin >> tdeath;
        newPerson.setDateDeath(tdeath);
        valid = newPerson.isDateDeathValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    valid = false;

    cout << "Enter what the person was known for(enter '-' to end input):" << endl;
    do {
        cin.get(pos);
        if (isspace(pos) && !lastspace && tknown.size() > 0){
            tknown += ' ';
            lastspace = true;
        }
        else if(pos == '-'){
            valid = true;
        }
        else if(!isspace(pos)){
            tknown += pos;
            lastspace = false;
        }

    }while (!valid);

    newPerson.setKnownFor(tknown);

    return newPerson;
}

void display::printSingleComputer(computer computerToPrint){
    //colors in table
    color c1 = RED, c2 = DARKYELLOW, c3 = YELLOW, c4 = TEAL;
    //width of the columns in the table
    size_t l1 = 11, l2 = 15;
    //overwrites default value for column 2 if the length fields 'Name' or 'Known for' exceed the original size
    //length of column 1 always stays the same
    if(computerToPrint.getType().size() > l2)
        l2 = computerToPrint.getType().size();
    if(computerToPrint.getName().size() > l2)
        l2 = computerToPrint.getName().size();
    ostringstream out;
    string s;
    string fields[] = {"Name", "Year built", "Type", "Built", "Weight(kg)"};
    setColor(c4);
    printf("id:%d\n", computerToPrint.getId());
    for(int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        setColor(c2);
        cout << '+';
        for(int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        setColor(c3);
        cout << fields[i];
        setColor(c2);
        for(auto k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                setColor(c1);
                cout << computerToPrint.getName();
                setColor(c2);
                for(auto k = computerToPrint.getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //year built
            case 1:
                if(computerToPrint.wasBuilt()){
                    setColor(c1);
                    cout << computerToPrint.getYearBuilt();
                    setColor(c2);
                    for(auto k = 4; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
                else{
                    setColor(c1);
                    cout << "N/A";
                    setColor(c2);
                    for(auto k = 3; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
            break;
            //type
            case 2:
                setColor(c1);
                cout << computerToPrint.getType();
                setColor(c2);
                for(auto k = computerToPrint.getType().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //was built
            case 3:
                if(computerToPrint.wasBuilt()){
                    setColor(c1);
                    cout << "Yes";
                    setColor(c2);
                    for(auto k = 3 ; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
                else{
                    setColor(c1);
                    cout << "No";
                    setColor(c2);
                    for(auto k = 2; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
            break;
            //weight
            case 4:
                setColor(c1);

                 std::cout.precision(4);
                cout << computerToPrint.getWeight();
                setColor(c2);
                out << setprecision(4) << computerToPrint.getWeight();

                s = out.str();

                for(auto k = s.size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            default:
                cout << "Error. " << endl;
            break;
        }

    }
    setColor(c2);
    cout << '+';
    for(int k = 0; k < l1; k++){
        cout << '-';
    }
    cout << '+';
    for(int k = 0; k < l2; k++){
        cout << '-';
    }
    cout << "+\n";
    setColor(WHITE);
}

computer display::fillFormComputer(){
    bool valid = false, lastspace = false;
    string tname;
    int tyearBuilt, ttype;
    double tweight;
    computer newComputer;
    char pos;
    cout << "Enter name(enter '-' to end input):" << endl;
    do{
        cin.get(pos);
        if (isspace(pos) && !lastspace && tname.size() > 0){
            tname += ' ';
            lastspace = true;
        }
        //'-' to end user input
        else if(pos == '-'){
            valid = true;
        }
        //if the character is neither '-' or ' ' it is appended to the name string
        else if(!isspace(pos)){
            tname += pos;
            lastspace = false;
        }

    }while(!valid);
    newComputer.setName(tname);
    valid = false;
    cout << "Enter year built (between 1600 and 2015):" << endl;
    do{
        cin >> tyearBuilt;
        if(cin.fail()) {
                cout << "Year built needs to be an integer." << endl;
                cin.clear();
                cin.ignore(256,'\n');

            }
        else{
            newComputer.setYearBuilt(tyearBuilt);
            valid = newComputer.isYearBuiltValid();
            if(!valid)
                cout << "The year you have entered is not valid. " << endl;
        }
    }while(!valid);
    valid = false;
    cout << "Enter type 1)'transistor', 2)'electromechanical', 3)'electronic', 4)'mechanical':" << endl;
    do{
        cin >> ttype;
        if(cin.fail()) {
                cout << "Type needs to be an integer." << endl;
                cin.clear();
                cin.ignore(256,'\n');

            }
        else{
            valid = newComputer.isTypeValid(ttype-1);
            if(!valid)
                cout << "The type you have entered is not valid. " << endl;
        }

    }while(!valid);
    newComputer.setType(ttype-1);

    valid = false;
    cout << "Enter weight (in kg):" << endl;
    do{
        cin >> tweight;
        if(cin.fail()) {
                cout << "Weight needs to be a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');

            }
       else{
            newComputer.setWeight(tweight);
            valid = true;
        }
    }while(!valid);

    return newComputer;
}

void display::displayRelComputer(crel c){
    size_t l1 = 3, l2 = 15;
    color c1 = YELLOW, c2 = DARKYELLOW, c3 = RED, c4 = TEAL;
    if(!c.cName.empty()){
        for(unsigned int i = 0; i < c.pName.size(); i++){
            if(c.pName[i].size() > l2)
                l2 = c.pName[i].size();
        }

        setColor(c1);
        printf("Persons connected to %s\n",c.cName.c_str());
        setColor(c2);
        cout << '+';
        for(int i = 0; i < l1; i++){
            cout << '-';
        }
        cout << '+';
        for(int i = 0; i < l2; i++){
            cout << '-';
        }
        cout << "+\n|";
        setColor(c1);
        cout <<  "id";
        setColor(c2);
        for(size_t x = 1; x < l1-1; x++)
                cout << ' ';
        cout << "|";
        setColor(c1);
        cout << "name";
        setColor(c2);
        for(size_t x = 4; x < l2; x++)
                cout << ' ';
        cout << "|\n";

        cout << '+';
        for(int i = 0; i < l1; i++){
            cout << '-';
        }
        cout << '+';
        for(int i = 0; i < l2; i++){
            cout << '-';
        }
        cout << "+\n";
        for(unsigned int i = 0; i < c.pName.size(); i++){
            cout <<'|';
            setColor(c4);
            cout << c.pId[i];
            for(size_t x = to_string(c.pId[i]).size(); x < l1; x++)
                    cout << ' ';
            setColor(c2);
            cout << '|';
            setColor(c3);
            cout << c.pName[i];
            setColor(c2);
            for(size_t x = c.pName[i].size(); x < l2; x++)
                    cout << ' ';
            cout << "|\n";

            cout << '+';
            for(int i = 0; i < l1; i++){
                cout << '-';
            }
            cout << '+';
            for(int i = 0; i < l2; i++){
                cout << '-';
            }
            cout << "+\n";
        }
        setColor(WHITE);
    }
    else
        cout << "Connection not found." <<endl;
}
void display::displayRelPerson(prel p){
    size_t l1 = 3, l2 = 15;
    color c1 = YELLOW, c2 = DARKYELLOW, c3 = RED, c4 = TEAL;
    if(!p.pName.empty()){
        for(unsigned int i = 0; i < p.cName.size(); i++){
            if(p.cName[i].size() > l2)
                l2 = p.cName[i].size();
        }

        setColor(c1);
        printf("Computers connected to %s\n",p.pName.c_str());
        setColor(c2);
        cout << '+';
        for(int i = 0; i < l1; i++){
            cout << '-';
        }
        cout << '+';
        for(int i = 0; i < l2; i++){
            cout << '-';
        }
        cout << "+\n|";
        setColor(c1);
        cout <<  "id";
        setColor(c2);
        for(size_t x = 1; x < l1-1; x++)
                cout << ' ';
        cout << "|";
        setColor(c1);
        cout << "name";
        setColor(c2);
        for(size_t x = 4; x < l2; x++)
                cout << ' ';
        cout << "|\n";

        cout << '+';
        for(int i = 0; i < l1; i++){
            cout << '-';
        }
        cout << '+';
        for(int i = 0; i < l2; i++){
            cout << '-';
        }
        cout << "+\n";
        for(unsigned int i = 0; i < p.cName.size(); i++){
            cout <<'|';
            setColor(c4);
            cout << p.cId[i];
            for(size_t x = to_string(p.cId[i]).size(); x < l1; x++)
                    cout << ' ';
            setColor(c2);
            cout << '|';
            setColor(c3);
            cout << p.cName[i];
            setColor(c2);
            for(size_t x = p.cName[i].size(); x < l2; x++)
                    cout << ' ';
            cout << "|\n";

            cout << '+';
            for(int i = 0; i < l1; i++){
                cout << '-';
            }
            cout << '+';
            for(int i = 0; i < l2; i++){
                cout << '-';
            }
            cout << "+\n";
        }
        setColor(WHITE);
    }
    else
        cout << "Connection not found." <<endl;


}

void display::displayListPerson(vector<person> pList){
    for(int i = 0; i < pList.size(); i++){
          printSingle(pList[i]);
    }
}

void display::displayListComputer(vector<computer> cList){
    for(int i = 0; i < cList.size(); i++){
          printSingleComputer(cList[i]);
    }
}

void display::printWelcome(){
    setColor(RED);
    cout << "                  ...::              ." << endl;
    cout << "               .:::   :             .:::." << endl;
    cout << "            .:':      ::::::::::::  :::::::." << endl;
    cout << "          .:''        '  ::::::::  ::::::::::." << endl;
    cout << "        .::'  .:.     ::::::::::: .::::::::::::." << endl;
    cout << "      .:   .::::.     :::::::::  :::::::::::::::" << endl;
    cout << "      :'   ::::::::    :::::::::.:::::::::::::::::" << endl;
    cout << "     :''  ::::::::::.  ::::::::::::::::::::::::'''" << endl;
    cout << "    .:   :::::::::::::  :::::::::::::::::::::::." << endl;
    cout << "    :'' :::::::::   '::. '''''''::::::::::::::::" << endl;
    cout << "   ''''.::::::::     .:'         ::::::::::::::::" << endl;
    cout << "       ''':'''':::...:            ::''' :::::::::" << endl;
    cout << "          :..........'            :.    :::::::::" << endl;
    cout << "                 ....:            :     :::::::::" << endl;
    cout << "         ....::::::::::.         ::..  .'''::::::" << endl;
    cout << "    ....::::::::::::::::: .....:::::::.::::..'''" << endl;
    cout << "    '::::::::::::::::::: . :::::::::::::::::::::..." << endl;
    cout << "     :::::::::::::::'::  '.::::::::::::::::::::::::" << endl;
    cout << "      ::::::::''::'    .: ::::::::::::::::::::::::" << endl;
    cout << "       '::::'   ''     :'  ::::::::::::  ':::::::" << endl;
    cout << "        ':'           :'   :::::::::::::.  ':::'" << endl;
    cout << "                     ::   :::::::::::::'     '" << endl;
    cout << "                    .'    ::::::::'''." << endl;
    cout << "                   .'                :." << endl;
    cout << "                   ''::..::::::..::'''" << endl;
    setColor(WHITE);
    cout << "             _  _  __                 ___ ___" << endl;
    cout << "            | || |/_/ _ __ _  _ _ _  | __| __|" << endl;
    cout << "            | __ / _ \\ \'_ \\ || | '_| |__ \\__ \\" <<endl;
    cout << "            |_||_\\___/ .__/\\_,_|_|   |___/___/" << endl;
    cout << "                     |_|" << endl;
    cout << "                               " << endl;

}

void display::printSecret(){
    cout << "                      ........" << endl;
    cout << "                    .@@@::.:::@@@." << endl;
    cout << "                 ..@:            @@." << endl;
    cout << "               ..@:               .@." << endl;
    cout << "              .@@..          ..    .@" << endl;
    cout << "            .@@@@@@@     .@@@@@@@  .@" << endl;
    cout << "           .@@@@@..@@:  .@@@@@. .: .@" << endl;
    cout << "            @@@@:@@: .. .@::....@  .@." << endl;
    cout << "           .@:.  .@...@.. .@:::.   .@." << endl;
    cout << "           .@..........@@@@@@@@:.  .@                ..@@." << endl;
    cout << "           .@........              .@               .@@  @@." << endl;
    cout << "           @@                      .@               :@    .@" << endl;
    cout << "           @@                      .@.             .@.    @@" << endl;
    cout << "           @@                @.@@   @@.           .@:   .:@" << endl;
    cout << "           @@                @:.@   :@. ...@@@@@..@.   @.@:" << endl;
    cout << "           .@                @:.@  ..@@@:.     .@@    ..@:..." << endl;
    cout << "            @:               @ .@.  .@:.. @@@@@@@@..  .@@:.@@@" << endl;
    cout << "            .@.              @..@.    . ..@:.     .:@@. .@@@@@::" << endl;
    cout << "             @@              @:.@.                    .@.   .@@" << endl;
    cout << "              @@            .@. .:@@.        .:        .@@..@@@" << endl;
    cout << "               @@          @:.@.@@@@@        .         .@::@@" << endl;
    cout << "                @@.        .@::@@           .         .@@" << endl;
    cout << "                 .@@.                                .@:" << endl;
    cout << "                   @@@..                     .:   ..@@." << endl;
    cout << "                     .@@@@....         .  .......@@:" << endl;
    cout << "                        .@@@@@@@@@@@@@@@: @@::::." << endl;
    cout << "                        .@.@@.    .... @: @@ ." << endl;
    cout << "                 .@@@...@ @@.     @@.@@@: @:" << endl;
    cout << "                  @@..@@:.@.       @@...  @@." << endl;
    cout << "                   .@@. .@:        ..:@@..@:." << endl;
    cout << "                     .@@@:              .::." << endl;

}

void display::printHelp(){
    cout << "+---------+------------+------------------------------------------------------+" << endl;
    cout << "|Commands |Subcommands |Examples/Description                                  |" << endl;
    cout << "+---------+------------+------------------------------------------------------+" << endl;
    cout << "|*Search  |            |                                                      |" << endl;
    cout << "|         |-p..........|'Search -p Bob'                                       |" << endl;
    cout << "|         |            |(search for person)                                   |" << endl;
    cout << "|         |-c..........|'Search -c Harvard'                                   |" << endl;
    cout << "|         |            |(search for computer)                                 |" << endl;
    cout << "|         |.....-i.....|'Display -p -i 12' or 'Display -c -i 3'               |" << endl;
    cout << "|         |            |(prints one element in list, matching the id)         |" << endl;
    cout << "|         |.....-m.....|'Display -p -m 25-35' or 'Display -c -m 1940-1950'    |" << endl;
    cout << "|_________|____________|(print all elements in requested age range/year built)|" << endl;
    cout << "|*Display |            |                                                      |" << endl;
    cout << "|         |-p...-e.....|'Display -p -e' or 'Display -c -e'                    |" << endl;
    cout << "|         |            |(print full list in ascending order, by id)           |" << endl;
    cout << "|         |-c...-a.....|'Display -p -a' or 'Display -c -a'                    |" << endl;
    cout << "|         |            |(print list, ascending order, alphabetically)         |" << endl;
    cout << "|         |.....-d.....|'Display -p -d' or 'Display -c -d'                    |" << endl;
    cout << "|         |            |(print list, descending order, aplhabetically)        |" << endl;
    cout << "|         |.....-g.....|'Display -p -g male'                                  |" << endl;
    cout << "|         |            |(print list, either male only or female only)         |" << endl;
    cout << "|         |.....-w.....|'Display -c -w'                                       |" << endl;
    cout << "|_________|____________|(print list order by weight, in ascending order)      |" << endl;
    cout << "|*Add     |            |                                                      |" << endl;
    cout << "|         |-p..........|'Add -p'                                              |" << endl;
    cout << "|         |            |(add a new person to database)                        |" << endl;
    cout << "|         |-c..........|'Add -c'                                              |" << endl;
    cout << "|_________|____________|(add a new computer to database)                      |" << endl;
    cout << "|*Edit    |            |                                                      |" << endl;
    cout << "|         |-p..........|'Edit -p 3'                                           |" << endl;
    cout << "|         |            |(change information about existing person)            |" << endl;
    cout << "|         |-c..........|'Edit -c 6'                                           |" << endl;
    cout << "|_________|____________|(change information about existing computer)          |" << endl;
    cout << "|*Delete  |            |                                                      |" << endl;
    cout << "|         |-p..........|'Delete -p 7'                                         |" << endl;
    cout << "|         |            |(remove person matching id from database)             |" << endl;
    cout << "|         |-c..........|'Delete -c 8'                                         |" << endl;
    cout << "|_________|____________|(remove computer matching id from database)           |" << endl;
    cout << "|*Rel     |            |                                                      |" << endl;
    cout << "|         |-p..........|'Rel -p 10'                                           |" << endl;
    cout << "|         |            |(show computers connected to person)                  |" << endl;
    cout << "|         |-c..........|'Rel -c 5'                                            |" << endl;
    cout << "|         |            |(show person connected to computer)                   |" << endl;
    cout << "|         |-r..........|'Rel -r 10 5'                                         |" << endl;
    cout << "|         |            |(remove connection between person & computer)         |" << endl;
    cout << "|         |-n..........|'Rel -n 10 5'                                         |" << endl;
    cout << "|_________|____________|(add new connection between person & computer)        |" << endl;
    cout << "|*Help    |            |                                                      |" << endl;
    cout << "|         |            |Show list of commands                                 |" << endl;
    cout << "|_________|____________|                                                      |" << endl;
    cout << "|*Quit    |            |                                                      |" << endl;
    cout << "|         |            |Quit program                                          |" << endl;
    cout << "+---------+------------+------------------------------------------------------+" << endl;
}
