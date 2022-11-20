#include "ReadFile.h"
#include <fstream>
#include <string>
#include <iostream>
#include "sstream"
#include "Commands.h"
#include "structs.h"
using namespace std;

int apartmentNumber = 0; // to understand how much apartment there is


void ReadFile::ReadInput(string inputFileName,string outputFileName) {

    ifstream inputFile;
    fstream outputFile(inputFileName, ios::out | ios :: trunc);
    inputFile.open(outputFileName,ios::in);

    string inputString;
    Commands commands; // all functions are in this commands class .

    int spaceIndex = 0; // to arrange the starting space for txt

    while (getline(inputFile,inputString)){
        istringstream inputStringStream(inputString);
        string streamString;
        string inputsArray[5];

        int arrayIndex = 0;
        while(getline(inputStringStream,streamString,'\t')){
            inputsArray[arrayIndex] = streamString;
            arrayIndex++;
        }

        if(inputsArray[0] == "add_apartment"){

            commands.add_apartment(commands.headNode,inputsArray[1],inputsArray[2], stoi(inputsArray[3]));
            apartmentNumber++;

        }else if(inputsArray[0] == "add_flat"){

            commands.add_flat(commands.headNode,inputsArray[1], stoi(inputsArray[2]), stoi(inputsArray[3]),inputsArray[4]);

        }else if(inputsArray[0] == "remove_apartment"){

            commands.remove_apartment(commands.headNode,inputsArray[1]);
            apartmentNode* temp = commands.headNode->next;

        }else if(inputsArray[0] == "make_flat_empty"){

            commands.make_flat_empty(commands.headNode,inputsArray[1],stoi(inputsArray[2]));

        }else if(inputsArray[0] == "find_sum_of_max_bandwidths"){
            if(spaceIndex != 0){outputFile << "\n";}

            outputFile << commands.find_sum_of_max_bandwidths(commands.headNode);

            spaceIndex++;
        }else if(inputsArray[0] == "merge_two_apartments"){

            commands.merge_two_apartments(commands.headNode,inputsArray[1],inputsArray[2]);

        }else if(inputsArray[0] == "relocate_flats_to_same_apartment"){

            commands.relocate_flats_to_same_apartment(commands.headNode,inputsArray[1], stoi(inputsArray[2]),inputsArray[3]);

        }else if(inputsArray[0] == "list_apartments"){
            if(spaceIndex != 0){outputFile << "\n";}
            outputFile << commands.list_apartments(commands.headNode);
            spaceIndex++;
        }
    }
    outputFile.close();
    inputFile.close();
}