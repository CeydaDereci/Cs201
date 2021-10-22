//
// Created by Ceyda Dereci on 14.04.2021.
//

#ifndef HW3_MOVIEBOOKINGSYSTEM_H
#define HW3_MOVIEBOOKINGSYSTEM_H


#include "ReservationList.h"
#include "MovieList.h"

class MovieBookingSystem {
public:
    const static int numOfRow = 30;
    const static int numOfColumn = 26;
    MovieBookingSystem();
    ~MovieBookingSystem();
    void addMovie( const long movieID, const int audienceRadius );
    void cancelMovie( const long movieID);
    void showAllMovies() const;
    void showMovie( const long movieID) const;
    int makeReservation( const long movieID, const int row, const char col);
    void cancelReservations( ReservationList resCode);
    void showReservation(const int resCode) const;
private:
    ReservationList reservationCodes;
    MovieList movies;
    int resCode;

    //helper functions
    void printSeatPlan(long id,int audienceRadius) const;
    string calculateTime(const long movieID) const;
    bool isOccupiable(const long movieID,int row, char col);
};


#endif //HW3_MOVIEBOOKINGSYSTEM_H
