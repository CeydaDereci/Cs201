//
// Created by Ceyda Dereci on 25.04.2021.
//

#include "MovieList.h"

//Constructor
MovieList::MovieList(): size(0),head(NULL),tail(NULL){

}
//Destructor
MovieList::~MovieList() {
    //while(!isEmpty()){
        //remove
    //}
}
//Copy Constructor
MovieList::MovieList(const MovieList &aList) {
    if(aList.head != NULL){
        head = new MovieNode;
        head->movieID = aList.head->movieID;
        head->movieTime = aList.head->movieTime;
        head->audienceRadius = aList.head->audienceRadius;
        head->availableSeats = aList.head->availableSeats;
        head->occupiableSeats = aList.head->occupiableSeats;
        head->numRes = aList.head->numRes;
        head->numRows = aList.head->numRows;
        head->numColumns = aList.head->numColumns;
        head->next = NULL;
        head->prev = NULL;
        MovieNode* origNode = aList.head->next;

        while(origNode != NULL){
            tail->next = new MovieNode;
            tail->next->movieID = origNode->movieID;
            tail->next->movieTime = origNode->movieTime;
            tail->next->audienceRadius = origNode->audienceRadius;
            tail->next->availableSeats = origNode->availableSeats;
            tail->next->occupiableSeats = origNode->occupiableSeats;
            tail->next->numRes = origNode->numRes;
            tail->next->numRows = origNode->numRows;
            tail->next->numColumns = origNode->numColumns;
            tail->next->next = NULL;
            tail->next->prev = tail;
            tail = tail->next;
            origNode = origNode->next;
        }
    }
}

bool MovieList::isEmpty() const {
    return size == 0;
}

void MovieList::add(const long movieID, const int audienceRadius) {
    if(isEmpty()){
        head = new MovieNode;

        head->movieID = movieID;
        head->movieTime = calculateTime(movieID);
        head->audienceRadius = audienceRadius;
        head->numRows = calculateRows(audienceRadius);
        head->numColumns = calculateColumns(audienceRadius);
        head->numRes = 0;
        head->availableSeats = head->numRows * head->numColumns;
        head->occupiableSeats = head->availableSeats;

        head->next = NULL;
        head->prev = NULL;
        tail = head;
        size++;
        cout << "Movie at " << calculateTime(movieID) <<  " has been added." << endl;

    }
    else{
        if(checkExists(movieID)){
            cout << "Movie at " << calculateTime(movieID) << " already exists!" << endl;
        }
        else{
            if(tail == head){
                tail = new MovieNode;
                tail->movieID = movieID;
                tail->movieTime = calculateTime(movieID);
                tail->audienceRadius = audienceRadius;
                tail->numRows = calculateRows(audienceRadius);
                tail->numColumns = calculateColumns(audienceRadius);
                tail->numRes = 0;
                tail->availableSeats = tail->numRows * tail->numColumns;
                tail->occupiableSeats = tail->availableSeats;
                head->next = tail;
                size ++;
            }
            else{
                tail->next = new MovieNode;
                tail->next->movieID = movieID;
                tail->next->movieTime = calculateTime(movieID);
                tail->next->audienceRadius = audienceRadius;
                tail->next->numRows = calculateRows(audienceRadius);
                tail->next->numColumns = calculateColumns(audienceRadius);
                tail->next->numRes = 0;
                tail->next->availableSeats = tail->next->numRows * tail->next->numColumns;
                tail->next->occupiableSeats = tail->next->availableSeats;
                tail = tail->next;
            }

            cout << "Movie at " << calculateTime(movieID) <<  " has been added." << endl;
        }

    }
}

void MovieList::remove(const long movieID) {
    if(size < 1){
        cout << "There are no movies on the show." << endl;
    }
    else {
        if (checkExists(movieID)) {
            //cancel reservations
            //delete movie
            MovieNode* temp = head;
            while(temp->next != NULL){
                if(temp->movieID = movieID){

                }
                temp = temp->next;
            }
        }
        else {
            cout << "Movie at " << calculateTime(movieID) << " does not exits!" << endl;
        }
    }
}

void MovieList::showAll() const {
    if(isEmpty()){
        cout << "No movies in the system!" << endl;
    }
    else{
        cout << "Movies currently in the system: " << endl;
        MovieNode* temp = head;
        while(temp != NULL){
            cout << "Movie at " << temp->movieTime << " (" << temp->availableSeats << " available seats)" << endl;
            temp = temp->next;
        }
    }
}

void MovieList::show(const long movieID) const {
    if (checkExists(movieID)) {
        int radius = 0;
        MovieNode* temp = head;
        while(temp != NULL){
            if(temp->movieID == movieID){
                cout << "Movie at " << calculateTime(movieID) << " has (" << temp->availableSeats << " available seats)" << endl;
                radius = temp->audienceRadius;
            }
            temp = temp->next;
        }
        printSeatPlan(radius);
    }
    else{
        cout<<"Movie at "<< calculateTime(movieID) << " is not found" << endl;
    }
}

//Helper Methods
bool MovieList::checkExists(const long movieID) const {
    MovieNode* temp = head;
    while(temp != NULL){
        if(temp->movieID == movieID)
            return true;
        temp = temp->next;
    }
    return false;
}

string MovieList::calculateTime(const long movieID) const {
    timeval time;
    time.tv_sec = movieID ;
    time.tv_usec = (movieID%1000)*1000;
    string t = string(ctime(reinterpret_cast<const time_t *>(&time)));
    return t.substr(0, t.size() - 1);
}

int MovieList::calculateRows(int audienceRadius) {
    int rows = 0;
    for (int c = 0; c < 30; c++) {
        if (c % (audienceRadius + 1) == 0){
            rows++;
        }
    }
    return rows;
}

int MovieList::calculateColumns(int audienceRadius) {
    int columns = 0;
    for (int d = 0; d < 26; d++) {
        if (d % (audienceRadius + 1) == 0){
            columns++;
        }
    }
    return columns;
}

void MovieList::printSeatPlan(int audienceRadius) const {
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
                    if (1){ //isReserved(i + 1, m + 'A'))
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






