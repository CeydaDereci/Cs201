//
// Created by Ceyda Dereci on 14.04.2021.
//

#include "ReservationList.h"
#include <string>
//Constructor
ReservationList::ReservationList(): size(0), head(NULL), tail(NULL){

}
//Copy Constructor
ReservationList::ReservationList(const ReservationList &aList) {
    if(aList.head != NULL){
        head = new ReservationNode;
        head->Code = aList.head->Code;
        head->row = aList.head->row;
        head->col = aList.head->col;
        head->id = aList.head->id;
        head->next = NULL;
        ReservationNode* origNode = aList.head->next;
        while(origNode != NULL){
            tail->next = new ReservationNode;
            tail->next->Code = origNode->Code;
            tail->next->row = origNode->row;
            tail->next->col = origNode->col;
            tail->next->id = origNode->id;
            tail->next->next = NULL;
            tail = tail->next;
            origNode = origNode->next;
        }
    }
    else
        head = NULL;
}
//Destructor
ReservationList::~ReservationList() {
    while (!isEmpty())
        remove(1);
}

bool ReservationList::isEmpty() const {
    return size == 0;
}

int ReservationList::getLength() const {
    return size;
}

bool ReservationList::retrieve(int index, int& resCode) const {
    if ((index < 1) || (index > getLength()))
        return false;
    ReservationNode *cur = find(index);
    resCode = cur->Code;
    return true;

}

bool ReservationList::insert(int index, int resCode) {
    int newLength = getLength() + 1;
    if ((index < 1) || (index > newLength))
        return false;
    ReservationNode *newPtr = new ReservationNode;
    size = newLength;
    newPtr->Code = resCode;

    if (index == 1){
        newPtr->next = head;
        head = newPtr;
    }
    else{
        ReservationNode *prev = find(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    cout << "Reservation with code " << resCode << " is inserted" << endl;
    return true;
}

bool ReservationList::remove(int index){
    ReservationNode *cur;
    if ((index < 1) || (index > getLength()))
        return false;
    --size;
    if (index == 1){
        cur = head;
        head = head->next;
    }
    else{
        ReservationNode *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cout << "Reservation on Code " << cur->Code << " cancelled: Seat "<< cur->col << cur->row << endl;
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

void ReservationList::makeRes(int id, int row, int col,int resCode) {
    if(isEmpty()){
        head = new ReservationNode;
        head->id = id;
        head->row = row;
        head->col = col;
        head->Code = resCode;
        head->next = NULL;
        tail = head;
        size++;
    }
    else{
        if(tail == head){
            tail = new ReservationNode;
            tail->id = id;
            tail->row = row;
            tail->col = col;
            tail->Code = resCode;
            head->next = tail;
            size ++;
        }
        else{
            tail->next = new ReservationNode;
            tail->next->id = id;
            tail->next->Code = resCode;
            tail->next->row = row;
            tail->next->col = col;
            tail = tail->next;
        }
    }
}

void ReservationList::showRes(int resCode) const{
    bool isExists = false;
    ReservationNode* temp = head;
    while(temp != NULL){
        if(temp->Code == resCode){
            isExists = true;
            cout << "Reservation with Code " << resCode << ": Seat " << temp->col << temp->row << " in Movie at " << calculateTime(temp->id) << endl;
        }
        temp = temp->next;
    }
    if(!isExists){
        cout << "No reservation with Code " << resCode << endl;
    }
}

ReservationList ReservationList::findByID(long id) {
    ReservationList resCodes;
    ReservationNode* temp = head;
    int index = 0;
    while(temp != NULL){
        index ++;
        if(temp->id == id){
            resCodes.makeRes(id,temp->row,temp->col,temp->Code);
        }
        temp = temp->next;
    }
    return resCodes;
}

bool ReservationList::checkAllExist(ReservationList resCode) {
    bool isExists = true;
    ReservationNode* temp = head;
    ReservationNode* temp2 = resCode.head;
    while(temp2 != NULL){
        if(isExists){
            isExists = false;
            while(temp != NULL) {
                if (temp->Code == temp2->Code) {
                    isExists = true;
                    break;
                }
                temp = temp->next;
            }
        }
        else{
            break;
        }
        temp2 = temp2->next;
    }
    return isExists;

}

bool ReservationList::isReserved(long id, int row, int col) const {
    bool isRes = false;
    ReservationNode* temp = head;
    while(temp != NULL){
        if(temp->id == id && temp->row == row && temp->col == col){
            isRes = true;
        }
        temp = temp->next;
    }
    return isRes;
}

void ReservationList::cancelRes(ReservationList resCode) {
    //find index of all resCode and remove from reservation list
    ReservationNode* temp = head;
    ReservationNode* temp2 = resCode.head;
    int index;
    while (temp2 != NULL){
        index = 1;
        while(temp != NULL) {
            if (temp->Code == temp2->Code) {
                remove(index);
            }
            index++;
            temp = temp->next;
        }
        temp2 = temp2->next;
    }
}

ReservationList::ReservationNode *ReservationList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;
    else{
        ReservationNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}

string ReservationList::calculateTime(const long movieID) const {
    timeval time;
    time.tv_sec = movieID ;
    time.tv_usec = (movieID%1000)*1000;
    string t = string(ctime(reinterpret_cast<const time_t *>(&time)));
    return t.substr(0, t.size() - 1);
}




