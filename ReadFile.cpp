#include "ReadFile.h"
#include <fstream>
#include <string>
#include <iostream>
#include "sstream"
#include "Commands.h"
#include "struct.h"
using namespace std;

int apartmentNumber = 0;


void ReadFile::ReadInput() {

    ifstream inputFile;
    inputFile.open("C:\\Users\\GameGaraj\\CLionProjects\\secondAssignment\\input2.txt",ios::in);

    string inputString;

    apartmentNode *headNode =  new apartmentNode();
    Commands commands;

    while (getline(inputFile,inputString)){
        istringstream inputStringStream(inputString);
        string streamString;

        string inputsArray[5];
        int arrayIndex = 0;
        while(getline(inputStringStream,streamString,'\t')){
            inputsArray[arrayIndex] = streamString;
            arrayIndex++;
        }
        //for(string x : inputsArray ){
        //    cout << x << " ";
        //}
        //cout << endl;

        if(inputsArray[0] == "add_apartment"){
            commands.add_apartment(headNode,inputsArray[1],inputsArray[2], stoi(inputsArray[3]));
            apartmentNumber++;
        }else if(inputsArray[0] == "add_flat"){
            commands.add_flat(headNode,inputsArray[1], stoi(inputsArray[2]), stoi(inputsArray[3]),inputsArray[4]);
        }else if(inputsArray[0] == "remove_apartment"){
            commands.remove_apartment(headNode,inputsArray[1]);
        }else if(inputsArray[0] == "make_flat_empty"){
            commands.make_flat_empty(headNode,inputsArray[1],stoi(inputsArray[2]));
        }else if(inputsArray[0] == "find_sum_of_max_bandwidths"){
            commands.find_sum_of_max_bandwidths(headNode);
        }else if(inputsArray[0] == "merge_two_apartments"){
            commands.merge_two_apartments(headNode,inputsArray[1],inputsArray[2]);
        }else if(inputsArray[0] == "relocate_flats_to_same_apartment"){
            commands.relocate_flats_to_same_apartment(headNode,inputsArray[1], stoi(inputsArray[2]),inputsArray[3]);
        }else if(inputsArray[0] == "list_apartments"){
            commands.list_apartments(headNode);
        }
    }
    inputFile.close();
}