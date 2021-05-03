//
// Created by Ceyda Dereci on 14.04.2021.
//

#ifndef HW3_RESERVATIONLIST_H
#define HW3_RESERVATIONLIST_H
#include <string>
#include <iostream>
using namespace std;

class ReservationList{
public:
    ReservationList();
    ReservationList( const ReservationList& aList );
    ~ReservationList();
    bool isEmpty() const;
    int getLength() const ;
    bool retrieve(int index, int& resCode) const;
    bool insert(int index, int resCode);
    bool remove(int index);
    void makeRes(int id,int row,int col,int resCode);
    void showRes(int resCode) const;
    bool checkAllExist(ReservationList resCode);
    ReservationList findByID(long id);
    bool isReserved(long id, int row, int col) const;
    void cancelRes(ReservationList resCode);
private:
    struct ReservationNode{
        int Code;
        int row;
        char col;
        long id;
        ReservationNode* next;
    };
    int size;
    ReservationNode *head;
    ReservationNode *tail;
    ReservationNode *find(int index) const;
    string calculateTime(const long movieID) const;

};


#endif //HW3_RESERVATIONLIST_H
