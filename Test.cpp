#include "Test.h"
#include "LikedList.h"

#include <cassert>
#include <iostream>

using namespace std;

class Testies{
    public:
    LinkedList F1;

void testInsert(){

    cout << "Testing insert" << endl;

    F1.insert("a","alpha", "1", "spell","hammer", "faster","some","other","this is a test info");
    F1.insert("2","Guitar", "Fender", "IM", "Musical Instrament", "player base","some other thins","Is mayonnaise and intrument", "No Patric");

}

void testTraversal(){

    cout << "Testing Traversal" << endl;
    F1.Traversal(); 
}

void testFind(){
    cout << "Testing Find" << endl;
    assert(F1.testFind("2") == true);
    assert(F1.testFind("a") == true);

}

void testInventory(){
    cout << "Testing Inventory" << endl;
    assert(F1.testInvintory("Guitar") == true);
    assert(F1.testInvintory("faster") == true);
}
};

void testAll(){
    Testies taster;
    cout << "Runing Assert Testing" << endl;

    taster.testInsert();
    taster.testTraversal();
    taster.testFind();
    taster.testInventory();

    cout << "Testing completed: Passed" << endl;
}

int main(void){
    testAll();
    return 0;
}