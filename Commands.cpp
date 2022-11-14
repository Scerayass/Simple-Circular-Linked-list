#include <iostream>
#include <sstream>
#include <cstring>
#include "Commands.h"
#include "struct.h"

using namespace std;
string headId;

void Commands::add_apartment(apartmentNode* head,string id ,string position,int max_bandwith) {


    if(position == "head"){

        cout << id << endl;
        head->flats = NULL;
        head ->id = id;
        head->max_bandwith = max_bandwith;
        head->next = head;
        headId = id;
        //cout<< head->max_bandwith <<endl;
        //head = newNode;

    }else{
        istringstream positionStream(position);
        string tempString;
        string positionArray[2];
        int index = 0;

        while(getline(positionStream,tempString,'_')){
            positionArray[index] = tempString;
            index++;
        }

        if(positionArray[0] == "before"){
            if(positionArray[1] == head->id){
                apartmentNode* newHead = new apartmentNode();
                headId = id;
                newHead->id = id;
                newHead->max_bandwith = max_bandwith;
                newHead->flats = NULL;
                newHead->next = head;

                apartmentNode* temp = head -> next;

                while(temp != head){
                    temp = temp->next;
                }

                temp->next = newHead;

            }else{
                cout << "before" << endl;
                apartmentNode* newNode = new apartmentNode();

                newNode->id = id;
                newNode->max_bandwith = max_bandwith;
                newNode->flats = NULL;
                apartmentNode* temp = head ;

                while(temp->next->id != positionArray[1]){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }

        }
        else if( positionArray[0] == "after"){
            apartmentNode* newNode = new apartmentNode();
            newNode->id = id;
            newNode->flats = NULL;
            newNode->max_bandwith = max_bandwith;

            apartmentNode* temp = head;
            while(temp->id != positionArray[1]){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

        }

    }

    cout << "headID : " << headId << endl; ;
    apartmentNode* tempx = head;
    cout << tempx->id << " -> "  ;
    while (tempx-> next != head){
        tempx = tempx->next;
        cout << tempx->id << " -> "  ;
    }
    cout << head->id  << endl;


}

void Commands::add_flat(apartmentNode* head,string apartId,int index,int initial_bandwith,string flatId) {
    flatNode* newFlat = new flatNode();
    newFlat->id = stoi(flatId);
    newFlat->initial_bandwith = initial_bandwith;

    apartmentNode* temp = head;
    while(temp->id != apartId){temp = temp->next;}

    if(temp->flats == NULL){
        temp->flats = newFlat;
        temp->flatNumber++;
    }else{
        if(index == 0){
            newFlat->next = temp->flats;
            temp->flats->prev = newFlat;
            temp->flats = newFlat;
            temp->flatNumber++;
        }else if(index == temp->flatNumber){
            flatNode* tempFlat = temp->flats;
            while(tempFlat->next != NULL){
                tempFlat = tempFlat->next;
            }
            tempFlat->next = newFlat;
            newFlat->prev = tempFlat;
            temp->flatNumber++;
        }else{
            flatNode* tempFlat = temp->flats;
            for(int i = 0;i < index-1;i++){
                tempFlat = tempFlat->next;
            }
            tempFlat->next->prev = newFlat;
            newFlat->next = tempFlat->next;
            tempFlat->next = newFlat;
            newFlat->prev = tempFlat;
        }
    }
}
void Commands::remove_apartment() {

}
void Commands::make_flat_empty() {

}

void Commands::find_sum_of_max_bandwidths() {

}

void Commands::merge_two_apartments() {

}

void Commands::relocate_flats_to_same_apartment() {

}

void Commands::list_apartments(apartmentNode* headNode) {
    while(headNode->id != headId){headNode = headNode->next;}

    do {
        cout << headNode->id << "(" << headNode->max_bandwith << ")" <<  listFlats(headNode) << "\n";
        headNode = headNode->next;
    }
    while (headNode->id != headId);
}

string Commands::listFlats(apartmentNode* node){
    flatNode* flats = node->flats;

    string flatString = "";


    while(flats != NULL){

        string temp = "\tFlat";
        temp += to_string(flats->id);
        temp += "(";
        temp += to_string(flats->initial_bandwith);
        temp += ")";
        flatString += temp;
        flats = flats->next;
    }
    return flatString;
}
