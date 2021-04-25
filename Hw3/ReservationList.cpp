//
// Created by Ceyda Dereci on 14.04.2021.
//

#include "ReservationList.h"
#include <string>
//Constructor
ReservationList::ReservationList(): size(0), head(NULL){

}
//Copy Constructor
ReservationList::ReservationList(const ReservationList &aList) {
    if(aList.head != NULL){
        head = new ReservationNode;
        head->Code = aList.head->Code;
        head->next = NULL;
        ReservationNode* origNode = aList.head->next;
        while(origNode != NULL){
            //TO DO
        }
    }
}
//Destructor
ReservationList::~ReservationList() {
    while(!isEmpty()){
        //remove
    }
}

bool ReservationList::isEmpty() const {
    return size == 0;
}

int ReservationList::getLength() const {
    return size;
}

bool ReservationList::retrieve(int index, int& resCode) const {
    return false;
}

bool ReservationList::insert(int index, int resCode) {
    return false;
}

bool ReservationList::remove(int index) {
    return false;
}

ReservationList::ReservationNode *ReservationList::find(int index) const {
    return nullptr;
}


