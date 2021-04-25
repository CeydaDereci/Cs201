//
// Created by Ceyda Dereci on 14.04.2021.
//

#ifndef HW3_RESERVATIONLIST_H
#define HW3_RESERVATIONLIST_H


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
    ReservationNode *find(int index) const;

};


#endif //HW3_RESERVATIONLIST_H
