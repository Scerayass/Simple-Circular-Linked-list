#ifndef SECONDASSIGNMENT_STRUCT_H
#define SECONDASSIGNMENT_STRUCT_H
#include <string>

using namespace std;

struct flatNode{  // flat's doubly linked list
    int id;
    int initial_bandwith;
    flatNode* prev;
    flatNode* next;
};

struct apartmentNode{ // apartment's circular linked list
    int max_bandwith;
    string id;
    apartmentNode* node;
    flatNode* flats;

};

#endif //SECONDASSIGNMENT_STRUCT_H
