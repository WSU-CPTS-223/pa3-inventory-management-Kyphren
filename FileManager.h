#pragma once
#include "LikedList.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::ifstream;

class File{
    public:

    void populateList();
    void searchID(string id);
    void searchCatagory(string catagory);

    private:
    LinkedList Q1;
};