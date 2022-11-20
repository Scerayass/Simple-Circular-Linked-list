#ifndef SECONDASSIGNMENT_COMMANDS_H
#define SECONDASSIGNMENT_COMMANDS_H

#include "structs.h"
class Commands {
public:
    apartmentNode* headNode = new apartmentNode();
    /**
     * \n This function adds a new apartment at required position in the apartment linked list.
     * @param head
     * @param id
     * @param position
     * @param max_bandwith
     */
    void add_apartment(apartmentNode* head,string id , string position,int max_bandwith);

    /**
     *  \n
     *  This function adds a new flat at required index in the flat linked list of the apartment whose
name is given apartment_name. If there is a flat at the given index, add new flat in the
correct position.
     * @param head
     * @param apartId
     * @param index
     * @param initial_bandwith
     * @param flatId
     */
    void add_flat(apartmentNode* head,string apartId,int index,int initial_bandwith,string flatId);

    /**
     *  \n
     *  This function removes the apartment whose name is equal to given apartment name from
the apartment linked list.
     * \n After the freeing operations, it returns the changed apartment linked list.
     * @param head
     * @param apartId
     * @return apartmentNode
     */
    apartmentNode* remove_apartment(apartmentNode* head,string apartId);

     /**
      * freeing flats from selected apartment
      * @param node
      */
     void removeFlats(apartmentNode* node);

    /**
     *  \n This function changes selected flat's empty flag to 1 and initial bandwith to 0.
     * @param head
     * @param apartId
     * @param flatId
     */
    void make_flat_empty(apartmentNode* head,string apartId,int flatId);

    /**
     *  \n This function sums the max bandwidth values of the apartments in the given apartment
linked list, then returns the sum.
     * @param head
     * @return string
     */
    string find_sum_of_max_bandwidths(apartmentNode* head);

    /**
     *  \n This function appends the flats of the second apartment whose name is apartment name second
to the end of the first apartment whose name is apartment name first.
     * @param head
     * @param firstId
     * @param secondId
     */
    void merge_two_apartments(apartmentNode* head ,string firstId, string secondId);

    /**
     *  \n This function relocates the different flats in different apartments to a specific place at the
same apartment consecutively
     * @param head
     * @param apartId
     * @param flatId
     * @param list
     */
    void relocate_flats_to_same_apartment(apartmentNode* head,string apartId,int flatId,string list);

    /**
     *  \n This function lists apartments and their flats with max_bandwidth value and initial_bandwidth
values, respectively.
     * @param headNode
     * @return string
     */
    string list_apartments(apartmentNode* headNode);

    /**
     *  \n This function is a helpful function for list_apartments function. it returns the flats list's string
     * @param node
     * @return string
     */
    string listFlats(apartmentNode* node);
};


#endif //SECONDASSIGNMENT_COMMANDS_H
