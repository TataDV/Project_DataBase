#include <iostream>
#include <vector>

#include "lib/model/ModelCar.h"
#include "lib/model/Automaker.h"
#include "lib/DB.h"

#include "lib/helper/FileHelper.h"
#include "lib/helper/ConsoleHelper.h"

using namespace std;

int main() {

 DB db;
 db.automakers = ImportFromFile("F:\\DB_cars_version2\\DB.csv");

 bool exit = false;
 do {
    cout << "+++Actions+++" << endl;
    cout << "1. Show all" << endl;
    cout << "2. Add" << endl;
    cout << "3. Find" << endl;
    cout << "4. Delete" << endl;
    cout << "0. Exit" << endl;

    char input;
    cin >> input;

     switch (input) {
         case '1': //1.Show all
             PrintAutomakers(db.GetAllAutomakers());
         break;
         case '2' : // 2. Add
         {
             string name;
             string country;
             cout << "Enter name of automaker";
             cin >> name;
             cout << "Enter country of automaker";
             cin >> country;

             Automaker automaker;
             automaker.name = name;
             automaker.country = country;

             db.InsertAutomaker(&automaker);
         }
             break;
         case '3' : // 3. Find
         {
             string name;
             cout << "Enter name of automaker";
             cin >> name;

             auto automaker = db.FindAutomaker(name);
             if(automaker == nullptr){
                 cout << "Not found" << endl;
             }else {
                 PrintAutomaker(automaker);
             }
         }
             break;

         case '4': // 4. Delete
         //TODO DeleteStudents()
             break;
         case '0': // 0. Exit
             exit = true;
             break;
     }
 } while (!exit);

    return 0;
}
