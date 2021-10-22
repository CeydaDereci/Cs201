//
// Created by Ceyda Dereci on 14.04.2021.
//

#include "MovieBookingSystem.h"

MovieBookingSystem::MovieBookingSystem() {
    resCode = 1;
}

MovieBookingSystem::~MovieBookingSystem() {

}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
    if(audienceRadius > 7 || audienceRadius < 0)
        cout << "Audience Radius should be between (0,7)!" << endl;
    else
        movies.addMovie(movieID, audienceRadius);
}

void MovieBookingSystem::cancelMovie(const long movieID) {
    if(movies.getLength() < 1){
        cout << "There are no movies on the showRes." << endl;
    }
    else {
        if (movies.checkExists(movieID)) {
            cout << "Movie at " << calculateTime(movieID) << " is cancelled." <<  endl << "Its reservations cancelled are:" << endl;
            //cancel reservations
            cancelReservations(reservationCodes.findByID(movieID));
            //delete movie
            movies.removeMovie(movies.findIndex(movieID));
        }
        else {
            cout << "Movie at " << calculateTime(movieID) << " does not exits!" << endl;
        }
    }
}

void MovieBookingSystem::showAllMovies() const {
    movies.showAll();
}

void MovieBookingSystem::showMovie(const long movieID) const {
    if(movies.getRadius(movieID) != -1) {
        cout << "Movie at " << calculateTime(movieID) << " has (" << movies.getAvailableSeats(movieID) << " available seats)" << endl;
        printSeatPlan(movieID, movies.getRadius(movieID));
    }
    else{
        cout<<"Movie at "<< calculateTime(movieID) << " is not found" << endl;
    }
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
    if(movies.checkExists(movieID)){
        if(isOccupiable(movieID,row,col)){
            if(!reservationCodes.isReserved(movieID,row,col)){
                //TO DO
                reservationCodes.makeRes(movieID,row,col,resCode);
                resCode++;
                movies.decreaseOneSeat(movieID);
                cout<<"Reservation done with Code " << resCode - 1 << ": Seat " << col << row << " in Movie at " << calculateTime(movieID) << endl;
                return resCode - 1;
            }
            else{
                cout<<"Seat " << col << row << " is not available in Movie at " << calculateTime(movieID) << endl;
                return -1;
            }
        }
        else{
            cout<<"Seat " << col << row << " is not occupiable in Movie at " << calculateTime(movieID) <<  endl;
            return -1;
        }
    }
    else{
        cout<< "Movie at " << calculateTime(movieID) << " does not exists!"<< endl;
        return -1;
    }
}

void MovieBookingSystem::cancelReservations(ReservationList resCode) {
    if(resCode.getLength() == 0){
        cout << "There are no reservations to cancel." << endl;
    }
    else{
        //check all reservation codes exist
        if(reservationCodes.checkAllExist(resCode)){
            reservationCodes.cancelRes(resCode);
            //increase seats
        }
        else{
            cout << "Some reservation codes do not exist. Cancellation is failed!" << endl;
        }

    }
}

void MovieBookingSystem::showReservation(const int resCode) const {
    reservationCodes.showRes(resCode);
}

//helper functions
void MovieBookingSystem::printSeatPlan(long id,int audienceRadius) const {
    char seatLetter = 'A';
    cout << "\t";
    for(int k = 0; k < 26; k++)
    {
        if(k % (audienceRadius + 1) == 0) {
            cout << seatLetter << "\t";
        }
        seatLetter++;
    }
    cout << "" << endl;
    for(int i = 0; i < 30; i++) {
        if (i % (audienceRadius + 1) == 0) {
            cout << i + 1;
            for (int m = 0; m < 26; m++) {
                if (m % (audienceRadius + 1) == 0) {
                    //to do check is reserved
                    if (reservationCodes.isReserved(id,i + 1, m + 'A')){
                        cout << "\t" << "x" << " "; //occupied seats
                    } else {
                        cout << "\t" << "o" << " "; //available seats
                    }
                }
            }
            cout << endl;
        }
    }
}

string MovieBookingSystem::calculateTime(const long movieID) const {
    timeval time;
    time.tv_sec = movieID ;
    time.tv_usec = (movieID%1000)*1000;
    string t = string(ctime(reinterpret_cast<const time_t *>(&time)));
    return t.substr(0, t.size() - 1);
}

bool MovieBookingSystem::isOccupiable(const long movieID, int row, char col) {
    bool isRowOc, isColOc;
    isColOc = false;
    isRowOc = false;
    isRowOc = row % (movies.getRadius(movieID)+ 1) == 1;
    isColOc = (col - 'A' + 1) % (movies.getRadius(movieID) + 1) == 1;
    return isColOc && isRowOc;
}


