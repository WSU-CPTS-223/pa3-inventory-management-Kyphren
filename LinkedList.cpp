#include "LikedList.h"

Node* LinkedList::insertNode(Node* node, string id, string Catagory1,string Catagory2, string Catagory3, string Catagory4, string Catagory5, string Catagory6, string Catagory7, string info){
    Node* newNode = new Node(id, Catagory1, Catagory2, Catagory3, Catagory4, Catagory5, Catagory6, Catagory7, info);
    newNode->pNext = node;
    return newNode; 
}

void LinkedList::insert(string id, string Catagory1, string Catagory2, string Catagory3, string Catagory4, string Catagory5, string Catagory6, string Catagory7, string info){
    head = insertNode(head, id, Catagory1, Catagory2, Catagory3, Catagory4, Catagory5, Catagory6, Catagory7, info);
}

Node* LinkedList::deleteNode(Node* node, string id){//delete does not work, don't need
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

void LinkedList::deleteItem(string Id){
    deleteNode(head, Id);
}

void LinkedList::TraversalNode(Node* node) const{
    if (node != nullptr){
        cout << node->info << endl;
        TraversalNode(node->pNext);
    }
}

void LinkedList::Traversal(){
    TraversalNode(head);
}

void LinkedList::searchID(Node* node, string id) const{
    if (node != nullptr){
        if (node->inventoryID == id){
            cout << node->info << endl;
            return;
        }
        else if(node->pNext == nullptr){
            cout << "Inventory/Product not found" <<endl;
        }
        searchID(node->pNext, id);
    }
}

void LinkedList::Find(string id){
    searchID(head, id);
}

void LinkedList::searchCatagory(Node* node, string catagory){//fix catagory
    if(catagoryTrue(node, catagory) == false){
        cout << "Invalid Catagory" << endl;
        return; 
    }
    while (node != nullptr){
    if (catagoryTrue(node, catagory) == true){
        if (node->Catagory1 == catagory){
                cout << node->info << endl;
        }
        node = node->pNext;
    } 
    }
}

void LinkedList::listInvintory(string catagory){
    searchCatagory(head, catagory);
}

bool LinkedList::catagoryTrue(Node* node, string catagory){//fix catagory
    if (node == nullptr) return false;   
    if (node->Catagory1 == catagory || node->Catagory2 == catagory || node->Catagory3 == catagory || node->Catagory4 == catagory || node->Catagory5 == catagory || node->Catagory6 == catagory || node->Catagory7 == catagory){
        return true;
    }
    return catagoryTrue(node->pNext, catagory);
}


bool LinkedList::testFind(string id){
    if (findTrue(head,id) == false){
        return false;
    }
    else if (findTrue(head, id) == true){
        return true;
    }
}

bool LinkedList::testInvintory(string catagory){
    if (catagoryTrue(head, catagory) == false){
        return false;
    } 
    else if (catagoryTrue(head, catagory) == true){
        return true;
    }
}

bool LinkedList::findTrue(Node* node, string id){
    if (node == nullptr) return false;
    if (node->inventoryID == id){
        return true;
    }
    return findTrue(node->pNext, id);
}