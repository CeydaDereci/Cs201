//
// Created by Ceyda Dereci on 3.03.2021.
//

#include <iostream>
#include <ctime>
#include "MovieBookingSystem.h"
using namespace std;

MovieBookingSystem::MovieBookingSystem() {
    movies = NULL;
    reservations = NULL;
    size = 0;
    resSize = 0;
    resCode = 1;
}

MovieBookingSystem::~MovieBookingSystem() {
    delete[] movies;
    delete[] reservations;
}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
    //check if the id unique
    bool isUnique = true;
    for (int i = 0; i < size; i++) {
        if (movieID == movies[i].getMovieID()) {
            isUnique = false;
        }
    }

    //add movie if id is unique
    if (isUnique) {
        if(audienceRadius > -1 && audienceRadius < 8) {
            //Calculate occupiable seats
            int rows, columns;
            rows = 0;
            columns = 0;
            for (int c = 0; c < numOfRow; c++) {
                if (c % (audienceRadius + 1) == 0) {
                    rows++;
                }
            }
            for (int d = 0; d < numOfColumn; d++) {
                if (d % (audienceRadius + 1) == 0) {
                    columns++;
                }
            }
            if(size == 0){
                movies = new Movie[size + 1];
                movies[size].setOccupiableSeats(rows * columns);
                movies[size].setMovieID(movieID);
                movies[size].setAudienceRadius(audienceRadius);
                movies[size].setMovieTime(calculateTime(movieID));
                movies[size].setAvailableSeats(rows * columns - 0); //initial
                movies[size].setNumRows(rows);
                movies[size].setNumColumns(columns);
                movies[size].setNumRes(0); //initial
                size++;
            }
            else {
                //copy movies to a temp array
                Movie *temp = movies;
                movies = new Movie[size + 1];

                for (int i = 0; i < size; i++) {
                    //add old movies
                    movies[i].setOccupiableSeats(temp[i].getOccupiableSeats());
                    movies[i].setMovieID(temp[i].getMovieID());
                    movies[i].setAudienceRadius(temp[i].getAudienceRadius());
                    movies[i].setMovieTime(temp[i].getMovieTime());
                    movies[i].setAvailableSeats(temp[i].getAvailableSeats());
                    movies[i].setNumRows(temp[i].getNumRows());
                    movies[i].setNumColumns(temp[i].getNumColumns());
                    movies[i].setNumRes(temp[i].getNumRes());
                }
                //add the movie to the end of movies array
                movies[size].setOccupiableSeats(rows * columns);
                movies[size].setMovieID(movieID);
                movies[size].setAudienceRadius(audienceRadius);
                movies[size].setMovieTime(calculateTime(movieID));
                movies[size].setAvailableSeats(rows * columns - 0); //initial
                movies[size].setNumRows(rows);
                movies[size].setNumColumns(columns);
                movies[size].setNumRes(0); //initial
                delete[] temp;
                size++;
            }
            cout << "Movie at " << movies[size - 1].getMovieTime() <<  " has been added." << endl;

        }
        else{
            cout << "Audience Radius should be between (0,7)!";
        }
    }
    else
        cout << "Movie at " << calculateTime(movieID) << " already exists!" << endl;


}

void MovieBookingSystem::cancelMovie(const long movieID) {
    if(size < 1)
    {
        cout << "There are no movies on the show." << endl;
    }
    else{
        bool isExists = false;
        int index;
        for(index = 0; index < size ; index++){
            if(movieID == movies[index].getMovieID()){
                isExists = true;
                break;
            }
        }
        if(isExists) {
            cout << "Movie at " << movies[index].getMovieTime() << " is cancelled." <<  endl << "Its reservations cancelled are:" << endl;
            //find how many reservations movie has
            int numRes = 0;
            for(int a = 0; a < resSize; a ++){
                if(movies[index].getMovieID() == reservations[a].getID()){
                    numRes ++;
                }
            }
            //add resCodes to the array
            int *resCode = new int[numRes];
            int resCode_index = 0;
            for(int b = 0; b < resSize; b ++) {
                if (movies[index].getMovieID() == reservations[b].getID()) {
                    resCode[resCode_index] = reservations[b].getResCode();
                    resCode_index++;
                }
            }
            //cancel reservations
            cancelReservations(numRes, resCode);

            //Cancel the movie
            Movie *temp = movies;
            movies = new Movie[size - 1];
            for(int i = 0; i < index ; i++){
                movies[i].setOccupiableSeats(temp[i].getOccupiableSeats());
                movies[i].setMovieID(temp[i].getMovieID());
                movies[i].setAudienceRadius(temp[i].getAudienceRadius());
                movies[i].setMovieTime(temp[i].getMovieTime());
                movies[i].setAvailableSeats(temp[i].getAvailableSeats());
                movies[i].setNumRows(temp[i].getNumRows());
                movies[i].setNumColumns(temp[i].getNumColumns());
                movies[i].setNumRes(temp[i].getNumRes());
            }
            for(int k = index; k < size - 1; k ++){
                movies[k].setOccupiableSeats(temp[k + 1].getOccupiableSeats());
                movies[k].setMovieID(temp[k + 1].getMovieID());
                movies[k].setAudienceRadius(temp[k + 1].getAudienceRadius());
                movies[k].setMovieTime(temp[k + 1].getMovieTime());
                movies[k].setAvailableSeats(temp[k + 1].getAvailableSeats());
                movies[k].setNumRows(temp[k + 1].getNumRows());
                movies[k].setNumColumns(temp[k + 1].getNumColumns());
                movies[k].setNumRes(temp[k + 1].getNumRes());
            }

            delete[] temp;
            size--;
        }
        else{
            cout<<"Movie at "<< calculateTime(movieID) << " does not exits!"<<endl;
        }
    }
}

void MovieBookingSystem::showAllMovies() {
    if(size == 0){
        cout << "No movies in the system!" << endl;
    }
    else{
        cout << "Movies currently in the system: " << endl;
        for(int i = 0; i < size; i++){
            cout << "Movie at " << movies[i].getMovieTime() << " (" << movies[i].getAvailableSeats() << " available seats)" << endl;
        }
    }
}

void MovieBookingSystem::showMovie(const long movieID) {
    bool idExists;
    idExists = false;
    int index;
    //check id exists
    for(index = 0; index < size ; index++) {
        if (movieID == movies[index].getMovieID()) {
            idExists = true;
            break;
        }

    }

    //Print representation of seats
    if(idExists){
        cout << "Movie at " << movies[index].getMovieTime() << " has (" << movies[index].getAvailableSeats() << " available seats)" << endl;
        char seatLetter = 'A';
        cout << "\t";
        for(int k = 0; k < numOfColumn; k++)
        {
            if(k % (movies[index].getAudienceRadius() + 1) == 0) {
                cout << seatLetter << "\t";
            }
            seatLetter++;
        }
        cout << "" << endl;
        for(int i = 0; i < numOfRow; i++)
        {
            if(i % (movies[index].getAudienceRadius() + 1) == 0) {
                cout << i + 1;
                for (int m = 0; m < numOfColumn; m++) {
                    if(m % (movies[index].getAudienceRadius() + 1) == 0) {
                        //to do check is reserved
                        if (isReserved(i + 1, m + 'A')) {
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
    else
        cout<<"Movie at "<< calculateTime(movieID) << " is not found" << endl;
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
    bool idExists;
    idExists = false;
    int index;
    if(size < 1)
        return -1;
    //Check movie exists
    for(index = 0; index < size ; index++ ){
        if(movies[index].getMovieID() == movieID){
            idExists = true;
            break;
        }
    }
    if(idExists){
        //Check occupiable
        if(isOccupiable(movieID,row,col)){
            //Check if reserved
            if(isReserved(row,col)){
                cout<<"Seat " << col << row << " is not available in Movie at " << calculateTime(movieID) << endl;
                return -1;
            }
            else{
                if(resSize == 0){
                    reservations = new Reservation[resSize + 1];
                    reservations[resSize].setID(movieID);
                    reservations[resSize].setCol(col);
                    reservations[resSize].setRow(row);
                    reservations[resSize].setResCode(resCode);
                    resCode ++;
                    resSize ++;
                    //increase 1 resNum and decrease 1 available seats
                    movies[index].setNumRes(movies[index].getNumRes() + 1);
                    movies[index].setAvailableSeats(movies[index].getAvailableSeats() - 1);

                }
                else{
                    Reservation * temp = reservations;
                    reservations = new Reservation[resSize + 1];
                    for(int o = 0 ; o < resSize ; o++){
                        reservations[o].setResCode(temp[o].getResCode());
                        reservations[o].setRow(temp[o].getRow());
                        reservations[o].setCol(temp[o].getCol());
                        reservations[o].setID(temp[o].getID());
                    }
                    reservations[resSize].setResCode(resCode);
                    reservations[resSize].setRow(row);
                    reservations[resSize].setCol(col);
                    reservations[resSize].setID(movieID);
                    //find movie and increase 1 resNum and decrease 1 available seats
                    movies[index].setNumRes(movies[index].getNumRes() + 1);
                    movies[index].setAvailableSeats(movies[index].getAvailableSeats() - 1);
                    resSize++;
                    resCode++;
                    delete[] temp;
                }
                cout<<"Reservation done with Code " << resCode - 1 << ": Seat " << col << row << " in Movie at " << calculateTime(movieID) << endl;
                return resCode - 1;
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

void MovieBookingSystem::cancelReservations(const int numRes, const int *resCode) {
    if(resSize == 0)
        cout << "There are no reservations to cancel." << endl;
    else{
        //check all resCodes exits
        bool all_exist;
        all_exist = true;
        for(int i = 0; i < numRes; i++){
            if(resCode[i] == -1)
                all_exist = false;
        }

        if(all_exist){
            Reservation * temp = reservations;
            int res_index = 0;
            for(int q = 0; q < numRes; q++){
                for (int i = 0; i < resSize; i++) {
                    if(temp[i].getResCode() == resCode[q]){
                        reservations = new Reservation[resSize - 1];
                        cout << "Reservation on Code " << temp[i].getResCode() << " cancelled: Seat "<< temp[i].getRow() << temp[i].getCol();
                        cout << " on Movie at " << calculateTime(temp[i].getID()) << endl;
                        for(int b = 0 ; b < size; b++ ){
                            if(temp[i].getID() == movies[b].getMovieID()){
                                movies[b].setNumRes(movies[b].getNumRes() - 1);
                                movies[b].setAvailableSeats(movies[b].getAvailableSeats() + 1);
                            }
                        }
                    }
                    else{
                        reservations[res_index].setID(temp[i].getID());
                        reservations[res_index].setCol(temp[i].getCol());
                        reservations[res_index].setRow(temp[i].getRow());
                        reservations[res_index].setResCode(temp[i].getResCode());
                        res_index++;
                    }
                }
            }
            delete[] temp;
            resSize = resSize - res_index;

        }
        else{
            cout << "Some reservation codes do not exist. Cancellation is failed!" << endl;
        }
    }

}

void MovieBookingSystem::showReservation(const int resCode) {
    bool resExists = false;
    for(int i = 0; i < resSize; i++)
    {
        if(reservations[i].getResCode() == resCode)
        {
            resExists = true;
            cout << "Reservation with Code " << resCode <<": Seat " << reservations[i].getCol() << reservations[i].getRow() <<" in Movie at " << calculateTime(reservations[i].getID()) << endl;
        }
    }
    if(!resExists)
        cout << "No reservation with Code " << resCode << endl;
}

string MovieBookingSystem::calculateTime(const long movieID) {
    timeval time;
    time.tv_sec = movieID ;
    time.tv_usec = (movieID%1000)*1000;
    string t = string(ctime(reinterpret_cast<const time_t *>(&time)));
    return t.substr(0, t.size() - 1);
}

bool MovieBookingSystem::isReserved(int row, char col) {
    bool isRes = false;
    for(int i = 0; i < resSize ; i++){
        if(reservations[i].getRow() == row && reservations[i].getCol() == col )
            isRes = true;
    }
    return isRes;
}

// precondition: movieId already exists (makeRes function already checks it)
bool MovieBookingSystem::isOccupiable(const long movieID,int row, char col) {
    bool isRowOc, isColOc;
    isColOc = false;
    isRowOc = false;

    //find movie

    int i;
    for(i = 0; i < size ; i++){
        if(movies[i].getMovieID() == movieID) {
            break;
        }
    }
    isRowOc = row % (movies[i].getAudienceRadius() + 1) == 1;
    isColOc = (col - 'A' + 1) % (movies[i].getAudienceRadius() + 1) == 1;

    return isColOc && isRowOc;
}





