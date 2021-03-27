//
// Created by Ceyda Dereci on 20.03.2021.
//

#ifndef HW1_RESERVATION_H
#define HW1_RESERVATION_H


class Reservation {
    public:
        Reservation();
        void setRow(int row);
        void setCol(char col);
        void setResCode(int resCode);
        void setID(long id);
        int getRow();
        char getCol();
        int getResCode();
        long getID();

    private:
        int row;
        char col;
        int resCode;
        long id;



};


#endif //HW1_RESERVATION_H
