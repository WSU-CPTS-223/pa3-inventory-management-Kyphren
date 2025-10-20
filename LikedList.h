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

    Node(int id, string pName, string bName, string Sin, string catagory, string info) : inventoryID(id), productName(pName), brandName(bName), Asin(Sin), Catagory(catagory), otherInfo(info), pNext(nullptr) {};
    
    int inventoryID;
    //posible vector for sting values
    string productName;
    string brandName;
    string Asin;
    string Catagory;
    string otherInfo;
    Node* pNext;
};

class LinkedList{
public:

LinkedList() : head(nullptr) {};

void insert(int id, string product, string brand, string Asin, string catagory, string info);//helper function
void deleteItem(int Id);//deletion helper funcion
void Traversal();//travers helper function
void Find(int id);//search helper function
void listInvintory(string catagory);//search catagory helper function

private:
Node* head;//head node

Node* insertNode(Node* node, int id, string product, string brand, string Asin, string catagory, string info); //insert function
Node* deleteNode(Node* node, int id);//deletion

void searchID(Node* node, int id) const;//search function
void TraversalNode(Node* node) const;//travers function
void searchCatagory(Node* node, string catagory);//seach catagories

bool catagoryTrue(Node* node, string catagory);

};

Node* LinkedList::insertNode(Node* node, int id, string product, string brand, string Asin, string catagory, string info){
    Node* newNode = new Node(id, product, brand, Asin, catagory, info);
    newNode->pNext = node;
    return newNode; 
}

void LinkedList::insert(int id, string product, string brand, string Asin, string catagory, string info){
    head = insertNode(head, id, product, brand, Asin, catagory, info);
}

Node* LinkedList::deleteNode(Node* node, int id){
    int ifTrue = 0;//check if id was valid to delete

    if (node == nullptr){
        cout << "List is empty" << endl;
        return nullptr;
    }

    if (node->inventoryID == id){//if head node is ID
        Node* temp = node->pNext;
        ifTrue = 1;
        delete node;
        return temp;
    }

    while (node != nullptr){
        if (node->inventoryID == id){
            Node* temp = node->pNext;//create temp node list
            ifTrue = 1;
            delete node;
            return temp;
            break;
        }
        node = node->pNext;//iterate through list
    }

    if (ifTrue == 0){
        cout << "Invalid ID to delete" << endl;
    }
    return node;
}

void LinkedList::deleteItem(int Id){
    deleteNode(head, Id);
}

void LinkedList::TraversalNode(Node* node) const{
    if (node != nullptr){
        cout << node->inventoryID << ',' << node->productName << ',' << node->brandName << ',' << node->Asin << ',' << node->Catagory << ',' << node->otherInfo << endl;
        TraversalNode(node->pNext);
    }
}

void LinkedList::Traversal(){
    TraversalNode(head);
}

void LinkedList::searchID(Node* node, int id) const{
    if (node != nullptr){
        if (node->inventoryID == id){
            cout << node->inventoryID << ',' << node->productName << ',' << node->brandName << ',' << node->Asin << ',' << node->Catagory << ',' << node->otherInfo << endl;
            return;
        }
        searchID(node->pNext, id);
    }
}

void LinkedList::Find(int id){
    searchID(head, id);
}

void LinkedList::searchCatagory(Node* node, string catagory){
    if(catagoryTrue(node, catagory) == false){
        cout << "Invalid Catagory" << endl;
    }
    while (node != nullptr){
    if (catagoryTrue(node, catagory) == true){
        if (node->Catagory == catagory){
                cout << node->inventoryID << "," << node->productName << endl;
        }
        node = node->pNext;
    } 
    }
}

void LinkedList::listInvintory(string catagory){
    searchCatagory(head, catagory);
}

bool LinkedList::catagoryTrue(Node* node, string catagory){
    if (node == nullptr) return false;   
    if (node->Catagory == catagory){
        return true;
    }
    return catagoryTrue(node->pNext, catagory);
}