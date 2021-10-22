//
// Created by Ceyda Dereci on 3.03.2021.
//

#ifndef HW1_MOVIEBOOKINGSYSTEM_H
#define HW1_MOVIEBOOKINGSYSTEM_H
#include "Movie.h"
#include "Reservation.h"

class MovieBookingSystem {
    public:
        const static int numOfRow = 30 ;
        const static int numOfColumn = 26 ;
        MovieBookingSystem();
        ~MovieBookingSystem();
        void addMovie ( const long movieID, const int audienceRadius );
        void cancelMovie ( const long movieID);
        void showAllMovies ();
        void showMovie ( const long movieID);
        int makeReservation ( const long movieID, const int row, const char col);
        void cancelReservations ( const int numRes, const int * resCode);
        void showReservation ( const int resCode);

    private:
        Movie *movies;
        Reservation *reservations;
        int size;
        int resSize;
        int resCode;

        //helper functions to calculate time and check is reserved and is occupiable
        string calculateTime(const long movieID);
        bool isReserved(int row, char col);
        bool isOccupiable(const long movieID, int row, char col);
};

#endif //HW1_MOVIEBOOKINGSYSTEM_H
