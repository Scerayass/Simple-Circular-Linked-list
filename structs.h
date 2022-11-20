#ifndef SECONDASSIGNMENT_STRUCTS_H
#define SECONDASSIGNMENT_STRUCTS_H
#include <string>

using namespace std;

struct flatNode{  // flat's doubly linked list
    int id;
    int initial_bandwith;
    int is_empty = 0;
    flatNode* prev;
    flatNode* next;
};

struct apartmentNode{ // apartment's circular linked list
    int max_bandwith;
    string id;
    apartmentNode* next;
    flatNode* flats;
    int flatNumber = 0;
    int currentMaxBandwith;

};

#endif //SECONDASSIGNMENT_STRUCTS_H
