#include <iostream>
#include <sstream>
#include <cstring>
#include "Commands.h"
#include "struct.h"

using namespace std;
string headId;

void Commands::add_apartment(apartmentNode* head,string id ,string position,int max_bandwith) {


    if(position == "head"){


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
    /*
    cout << "headID : " << headId << endl; ;
    apartmentNode* tempx = head;
    cout << tempx->id << " -> "  ;
    while (tempx-> next != head){
        tempx = tempx->next;
        cout << tempx->id << " -> "  ;
    }
    cout << head->id  << endl;
    */

}

void Commands::add_flat(apartmentNode* head,string apartId,int index,int initial_bandwith,string flatId) {
    flatNode* newFlat = new flatNode();
    newFlat->id = stoi(flatId);


    apartmentNode* temp = head;
    while(temp->id != apartId){temp = temp->next;}
    if(temp->max_bandwith >= (temp->currentMaxBandwith + initial_bandwith)){
        temp->currentMaxBandwith += initial_bandwith;
    }else{
        initial_bandwith =  temp->max_bandwith - temp->currentMaxBandwith ;
        temp->currentMaxBandwith = temp->max_bandwith;
    }
    newFlat->initial_bandwith = initial_bandwith;

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
void Commands::remove_apartment(apartmentNode* head,string apartId) {
    apartmentNode* temp;
    apartmentNode* nextTemp;
    while(head->next->id != apartId){
        head = head->next;
    }
    temp = head->next;
    nextTemp = temp->next;
    head->next = nextTemp;
    if(temp->flats != NULL){
        flatNode* flatTemp = temp->flats;
        while(flatTemp != NULL){
            flatNode* flatDeleted = flatTemp;
            flatTemp = flatTemp->next;
            delete flatDeleted;
        }
    }
    delete temp;
}
void Commands::make_flat_empty(apartmentNode* head,string apartId,int flatId) {
    while(head->id != apartId){head = head->next;}

    flatNode* flatTemp = head->flats;
    while(flatTemp != NULL){
        if(flatTemp->id == flatId){
            flatTemp->is_empty = 1;
            flatTemp->initial_bandwith = 0;
            break;
        }
        flatTemp = flatTemp->next;
    }
}

void Commands::find_sum_of_max_bandwidths(apartmentNode* head) {
    apartmentNode* temp = head;
    int sum = temp->max_bandwith;
    while(temp->next != head){
        temp = temp->next;
        sum += temp->max_bandwith;
    }
    cout << "sum of bandwidth: "<<to_string(sum) << "\n\n" ;
}

void Commands::merge_two_apartments(apartmentNode* head ,string firstId, string secondId) {
    apartmentNode* firstNode;
    apartmentNode* secondNode;

    while(head->id != firstId){head = head->next;}
    firstNode = head;
    while(head->next->id != secondId){head = head->next;}
    secondNode = head->next;

    head->next = secondNode->next;

    firstNode->max_bandwith += secondNode->max_bandwith;
    firstNode->currentMaxBandwith += secondNode->currentMaxBandwith;

    if(firstNode->flats == NULL){
        firstNode->flats = secondNode->flats;
    }else{
        flatNode* firstTemp = firstNode->flats;
        while(firstTemp->next != NULL){firstTemp = firstTemp->next;}

        flatNode* secondTemp = secondNode->flats;
        if(secondTemp != NULL){
            firstTemp->next = secondTemp;
            secondTemp->prev = firstTemp;
        }

    }
    delete secondNode;

}

void Commands::relocate_flats_to_same_apartment(apartmentNode* head,string apartId,int flatId,string list) {

    list.erase( list.length() - 1);
    list.erase(list.begin());

    istringstream listStream(list);
    string listString;

    apartmentNode* selectedApart = head->next;
    while(selectedApart->id != apartId){selectedApart = selectedApart->next;}


    flatNode* selectedFlat = selectedApart->flats;
    while(selectedFlat != NULL && selectedFlat->id != flatId){selectedFlat = selectedFlat->next;}



    flatNode* allSelectedFlats;
    int flatIndex = 0;
    while(getline(listStream,listString,',')){
        int listInt = stoi(listString);
        apartmentNode* temp = head;
        int index = 0;
        while(temp != head || index == 0){

            index++;
            flatNode* tempFlat = temp->flats;

            while(tempFlat != NULL){

                if(tempFlat->id == listInt){

                    flatNode* locatedFlat;

                    if(tempFlat->prev == NULL && tempFlat->next != NULL){
                        flatNode* nextFlat = tempFlat->next;
                        tempFlat->next = NULL;
                        nextFlat->prev = NULL;
                        temp->flats = nextFlat;
                        locatedFlat = tempFlat;
                        tempFlat = nextFlat;

                    }else if(tempFlat->prev == NULL && tempFlat->next == NULL){

                        locatedFlat = tempFlat;
                        tempFlat = NULL;

                    }else if(tempFlat->next == NULL){

                        flatNode* prevFlat = tempFlat->prev;
                        tempFlat->prev = NULL;
                        prevFlat->next = NULL;
                        locatedFlat = tempFlat;

                        tempFlat = NULL;
                    }else{

                        flatNode* prevFlat = tempFlat->prev;
                        flatNode* nextFlat = tempFlat->next;
                        prevFlat->next = nextFlat;
                        nextFlat->prev = prevFlat;
                        tempFlat->next = NULL;
                        tempFlat->prev = NULL;
                        locatedFlat = tempFlat;
                        tempFlat = nextFlat;
                    }
                    temp->max_bandwith -= locatedFlat->initial_bandwith;
                    temp->currentMaxBandwith -= locatedFlat->initial_bandwith;

                    if(flatIndex == 0){
                        if (locatedFlat == NULL){cout << "111";}
                        allSelectedFlats = locatedFlat;
                        flatIndex++;
                    }else{

                        allSelectedFlats->next = locatedFlat;

                        locatedFlat->prev = allSelectedFlats;
                        allSelectedFlats = locatedFlat;
                    }


                }else{
                    tempFlat = tempFlat->next;
                }

            }
            temp = temp->next;
        }
    }



    if(selectedFlat->prev == NULL){

        selectedFlat->prev = allSelectedFlats;
        allSelectedFlats->next = selectedFlat;
        while(allSelectedFlats->prev !=NULL){

            selectedApart->currentMaxBandwith += allSelectedFlats->initial_bandwith;
            selectedApart->max_bandwith += allSelectedFlats->initial_bandwith;
            allSelectedFlats = allSelectedFlats->prev;
        }
        selectedApart->currentMaxBandwith += allSelectedFlats->initial_bandwith;
        selectedApart->max_bandwith += allSelectedFlats->initial_bandwith;
        selectedApart->flats = allSelectedFlats;
    }else{
        flatNode* prevFlat = selectedFlat->prev;
        selectedFlat->prev = allSelectedFlats;
        allSelectedFlats->next = selectedFlat;

        while(allSelectedFlats->prev !=NULL){

            selectedApart->currentMaxBandwith += allSelectedFlats->initial_bandwith;
            selectedApart->max_bandwith += allSelectedFlats->initial_bandwith;
            cout << selectedApart->id << " " << selectedApart->max_bandwith << endl;
            allSelectedFlats = allSelectedFlats->prev;
        }
        selectedApart->currentMaxBandwith += allSelectedFlats->initial_bandwith;
        selectedApart->max_bandwith += allSelectedFlats->initial_bandwith;
        prevFlat->next = allSelectedFlats;
        allSelectedFlats->prev = prevFlat;
    }


}

void Commands::list_apartments(apartmentNode* headNode) {
    while(headNode->id != headId){headNode = headNode->next;}

    do {
        cout << headNode->id << "(" << headNode->max_bandwith << ")" <<  listFlats(headNode) << "\n";
        headNode = headNode->next;
    }
    while (headNode->id != headId);
    cout << "\n";
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
