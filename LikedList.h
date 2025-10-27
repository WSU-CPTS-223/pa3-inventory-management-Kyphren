#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//template <class T>
class Node{
public:

    Node(string id, string Catagory1,string Catagory2, string Catagory3, string Catagory4, string Catagory5, string Catagory6, string Catagory7, string info) : inventoryID(id),Catagory1(Catagory1), Catagory2(Catagory2), Catagory3(Catagory3),
    Catagory4(Catagory4), Catagory5(Catagory5), Catagory6(Catagory6), Catagory7(Catagory7), info(info), pNext(nullptr) {};
    
    string inventoryID;
 
    string Catagory1;
    string Catagory2;
    string Catagory3;
    string Catagory4;
    string Catagory5;
    string Catagory6;
    string Catagory7;

    string info;

    Node* pNext;
};

class LinkedList{
public:

LinkedList() : head(nullptr) {};

void insert(string id, string Catagory1,string Catagory2, string Catagory3, string Catagory4, string Catagory5, string Catagory6, string Catagory7, string info);//helper function
void deleteItem(string Id);//deletion helper funcion
void Traversal();//travers helper function
void Find(string id);//search helper function
void listInvintory(string catagory);//search catagory helper function

bool testFind(string id);//for assert testing
bool testInvintory(string catagory);

private:
Node* head;//head node

Node* insertNode(Node* node, string id, string Catagory1,string Catagory2, string Catagory3, string Catagory4, string Catagory5, string Catagory6, string Catagory7, string info); //insert function
Node* deleteNode(Node* node, string id);//deletion

void searchID(Node* node, string id) const;//search function
void TraversalNode(Node* node) const;//travers function
void searchCatagory(Node* node, string catagory);//seach catagories

bool catagoryTrue(Node* node, string catagory);
bool findTrue(Node* node, string id);

};