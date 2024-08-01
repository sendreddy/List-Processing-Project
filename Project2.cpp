/* Name       : Srujana Endreddy 
 * Date       : October 21, 2022 
 * File Name  : Project2.cpp
 * Description: This given cpp file is used to test List.h file to print the output to the terminal. */ 


// Project2.cpp
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {
    // Create List
    List<string> *list = new List<string>();

    // Fill List
    list->push_front("chia");
    list->push_front("poppy");
    list->push_back("sunflower");
    list->push_back("pumpkin");
    cout << *list << endl;

    // Erase second item
    list->erase( list->first()->next ); cout << *list << endl;
    // Erase first item
    list->pop_back();  cout << *list << endl;
    // Erase last item
    list->pop_front(); cout << *list << endl;
    cout << "List has " << list->size() << " item(s)" << endl;

    delete list;
}

// [poppy, chia, sunflower, pumpkin]
// [poppy, sunflower, pumpkin]
// [poppy, sunflower]
// [sunflower]
// List has 1 item(s)
