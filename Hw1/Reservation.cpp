//
// Created by Ceyda Dereci on 20.03.2021.
//

#include "Reservation.h"


Reservation::Reservation() {
    this->id = 0;
    this->row = 0;
    this->col = 0;
    this->resCode = 0;
}

void Reservation::setRow(int row) {
    this->row = row;
}

void Reservation::setCol(char col) {
    this->col = col;
}

void Reservation::setResCode(int resCode) {
    this->resCode = resCode;
}

void Reservation::setID(long id) {
    this->id = id;
}

long Reservation::getID() {
    return id;
}

int Reservation::getRow() {
    return row;
}

char Reservation::getCol() {
    return col;
}

int Reservation::getResCode() {
    return resCode;
}


