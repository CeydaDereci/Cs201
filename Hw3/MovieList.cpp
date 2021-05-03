//
// Created by Ceyda Dereci on 25.04.2021.
//

#include "MovieList.h"

//Constructor
MovieList::MovieList(): size(0),head(NULL),tail(NULL){

}
//Destructor
MovieList::~MovieList() {
    while (!isEmpty())
        removeMovie(1);
}
//Copy Constructor
MovieList::MovieList(const MovieList &aList) {
    if(aList.head != NULL){
        head = new MovieNode;
        head->movieID = aList.head->movieID;
        head->movieTime = aList.head->movieTime;
        head->audienceRadius = aList.head->audienceRadius;
        head->availableSeats = aList.head->availableSeats;
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
            tail->next->numRows = origNode->numRows;
            tail->next->numColumns = origNode->numColumns;
            tail->next->next = NULL;
            tail->next->prev = tail;
            tail = tail->next;
            origNode = origNode->next;
        }
    }
    else
        head = NULL;
}

bool MovieList::isEmpty() const {
    return size == 0;
}

int MovieList::getLength() {
    return size;
}

bool MovieList::checkExists(const long movieID) const {
    MovieNode* temp = head;
    while(temp != NULL){
        if(temp->movieID == movieID)
            return true;
        temp = temp->next;
    }
    return false;
}

void MovieList::addMovie(const long movieID, const int audienceRadius) {
    if(isEmpty()){
        head = new MovieNode;

        head->movieID = movieID;
        head->movieTime = calculateTime(movieID);
        head->audienceRadius = audienceRadius;
        head->numRows = calculateRows(audienceRadius);
        head->numColumns = calculateColumns(audienceRadius);
        head->availableSeats = head->numRows * head->numColumns;

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
                tail->availableSeats = tail->numRows * tail->numColumns;
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
                tail->next->availableSeats = tail->next->numRows * tail->next->numColumns;
                tail = tail->next;
            }

            cout << "Movie at " << calculateTime(movieID) <<  " has been added." << endl;
        }

    }
}

void MovieList::removeMovie(int index) {
    MovieNode *cur;
    if ((index < 1) || (index > getLength()))
        return;
    --size;
    if (index == 1){
        cur = head;
        head = head->next;
    }
    else{
        MovieNode *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
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

int MovieList::getRadius(const long movieID) const {
    if (checkExists(movieID)) {
        int radius = 0;
        MovieNode* temp = head;
        while(temp != NULL){
            if(temp->movieID == movieID){
                radius = temp->audienceRadius;
            }
            temp = temp->next;
        }
        return radius;
    }
    else{
        return -1;
    }
}

int MovieList::getAvailableSeats(const long movieID) const {
    if (checkExists(movieID)) {
        int seats = 0;
        MovieNode* temp = head;
        while(temp != NULL){
            if(temp->movieID == movieID){
                seats = temp->availableSeats;
            }
            temp = temp->next;
        }
        return seats;
    }
    else{
        return -1;
    }
}

void MovieList::decreaseOneSeat(const long movieID) {
    if (checkExists(movieID)) {
        MovieNode* temp = head;
        while(temp != NULL){
            if(temp->movieID == movieID){
                temp->availableSeats = temp->availableSeats - 1;
            }
            temp = temp->next;
        }
    }
}

void MovieList::increaseOneSeat(const long movieID) {
    if (checkExists(movieID)) {
        MovieNode* temp = head;
        while(temp != NULL){
            if(temp->movieID == movieID){
                temp->availableSeats = temp->availableSeats + 1;
            }
            temp = temp->next;
        }
    }
}

int MovieList::findIndex(const long movieID) {
    MovieNode* temp = head;
    int index = 1;
    if(checkExists(movieID)){
        while (temp != NULL){
            if (temp->movieID == movieID) {
                break;
            }
            index++;
            temp = temp->next;
        }
        return index;
    }
    else
        return -1;
}

//helper functions
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

MovieList::MovieNode *MovieList::find(int index) const {
    if ((index < 1) || (index > size))
        return NULL;
    else{
        MovieNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}
















