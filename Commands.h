#ifndef SECONDASSIGNMENT_COMMANDS_H
#define SECONDASSIGNMENT_COMMANDS_H

#include "struct.h"
class Commands {
public:
    void add_apartment(apartmentNode* head,string id , string position,int max_bandwith);
    void add_flat(apartmentNode* head,string apartId,int index,int initial_bandwith,string flatId);
    void remove_apartment(apartmentNode* head,string apartId);
    void make_flat_empty(apartmentNode* head,string apartId,int flatId);
    void find_sum_of_max_bandwidths(apartmentNode* head);
    void merge_two_apartments(apartmentNode* head ,string firstId, string secondId);
    void relocate_flats_to_same_apartment(apartmentNode* head,string apartId,int flatId,string list);
    void list_apartments(apartmentNode* headNode);
    string listFlats(apartmentNode* node);
};


#endif //SECONDASSIGNMENT_COMMANDS_H
