#ifndef SECONDASSIGNMENT_COMMANDS_H
#define SECONDASSIGNMENT_COMMANDS_H

#include "struct.h"
class Commands {
public:
    void add_apartment(int apartmentNumber,apartmentNode* node,string id , string position,int max_bandwith);
    void add_flat();
    void remove_apartment();
    void make_flat_empty();
    void find_sum_of_max_bandwidths();
    void merge_two_apartments();
    void relocate_flats_to_same_apartment();
    void list_apartments();
};


#endif //SECONDASSIGNMENT_COMMANDS_H
