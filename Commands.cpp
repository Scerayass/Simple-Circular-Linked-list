#include <iostream>
#include "Commands.h"
#include "struct.h"

void Commands::add_apartment(int apartmentNumber,apartmentNode* node,string id ,string position,int max_bandwith) {


    if(position == "head"){

        node->node = node;
        node->flats = NULL;
        node->id = id;
        node->max_bandwith = max_bandwith;
        std::cout<< node->max_bandwith <<endl;
        //head = newNode;
    }else{

    }
    
}

void Commands::add_flat() {

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

void Commands::list_apartments() {

}
