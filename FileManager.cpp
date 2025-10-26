#include "FileManager.h"

void File::populateList(){
    ifstream inFile("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");

    if(!inFile.is_open()){
        cout << "Error in read" << endl;
    }

    string temp1, temp2, temp3, temp4;
    string initial, header, line;
    string ID,Catagory, info, catagory2, catagory3, catagory4, catagory5, catagory6, catagory7;

    char comma = ',', otherCat = '|', quote = '"';

    int place, extraCat;

    getline(inFile, header);//header line

    //getline(inFile,initial);//get parsing corrected 

    //initial.erase(std::remove(initial.begin(),initial.end(), '"'),initial.end());
    // cout << ID << endl;
    // cout << temp1 << endl;
    // cout << temp2 << endl;
    // cout << temp3 << endl;
    // cout << temp4 << endl;
    // cout << temp1 << endl;
    //cout << initial << endl;
    //cout << line << endl;
    // cout << Catagory << endl;
    // cout << catagory2 << endl;
    // cout << catagory3 << endl;
    // cout << catagory4 << endl;
    // cout << catagory5 << endl;
    // cout << catagory6 << endl;
    // cout << catagory7 << endl;

    while(getline(inFile, initial)){
            info = initial;//saves unchanged copy
    extraCat = initial.find(otherCat);//finds | if more that on catagory

    place = initial.find(comma);
    ID = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    temp1 = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    temp2 = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    temp3 = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    temp4 = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    temp1 = initial.substr(0,place);
    initial.erase(0, place + 1);

    place = initial.find(quote);
    line = initial.substr(0,place);
    initial.erase(0, place + 1);

    if (extraCat != string::npos){//if it finds

        place = line.find(otherCat);
        Catagory = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory2 = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory3 = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory4 = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory5 = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory6 = line.substr(0,place);
        line.erase(0, place + 1);

        place = line.find(otherCat);
        catagory7 = line.substr(0,place);
        line.erase(0, place + 1);

    } else {//if it does not find
        catagory2 = "NA";
        catagory3 = "NA";
        catagory4 = "NA";
        catagory5 = "NA";
        catagory6 = "NA";
        catagory7 = "NA";
    }

    Q1.insert(ID, Catagory, catagory2, catagory3, catagory4, catagory5, catagory6, catagory7, info);
    }

    inFile.close();
}

