//
// Created by Ceyda Dereci on 14.04.2021.
//

#include "MovieBookingSystem.h"

MovieBookingSystem::MovieBookingSystem() {

}

MovieBookingSystem::~MovieBookingSystem() {

}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
    if(audienceRadius > 7 || audienceRadius < 0)
        cout << "Audience Radius should be between (0,7)!" << endl;
    else
        movies.add(movieID,audienceRadius);
}

void MovieBookingSystem::cancelMovie(const long movieID) {
    movies.remove(movieID);
}

void MovieBookingSystem::showAllMovies() const {
    movies.showAll();
}

void MovieBookingSystem::showMovie(const long movieID) const {
    movies.show(movieID);
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
    return 0;
}

void MovieBookingSystem::cancelReservations(ReservationList resCode) {

}

void MovieBookingSystem::showReservation(const int resCode) const {

}


