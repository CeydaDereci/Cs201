//
// Created by Ceyda Dereci on 3.03.2021.
//

#include "Movie.h"

#include <utility>
//constructor
Movie::Movie() {
    movieID = 0;
    audienceRadius = 0;
    occupiableSeats = 0;
    availableSeats = 0;
    numRes = 0;
    movieTime = "";
    numRows = 0;
    numColumns = 0;
}

//copy constructor
Movie::Movie(const Movie &movie) {
    movieID = movie.movieID;
    audienceRadius = movie.audienceRadius;
    occupiableSeats = movie.occupiableSeats;
    availableSeats = movie.availableSeats;
    numRes = movie.numRes;
    movieTime = movie.movieTime;
    numRows = movie.numRows;
    numColumns = movie.numColumns;
}
//destructor
Movie::~Movie(){
};

Movie &Movie::operator=(const Movie &other) {
    this->movieID = other.movieID;
    this->audienceRadius = other.audienceRadius;
    this->occupiableSeats = other.occupiableSeats;
    this->availableSeats = other.availableSeats;
    this->numRes = other.numRes;
    this->movieTime = other.movieTime;
    this->numRows = other.numRows;
    this->numColumns = other.numColumns;
}

//getters and setters
long Movie::getMovieID() {
    return movieID;
}

void Movie::setMovieID(long id) {
    this->movieID = id;
}


int Movie::getAvailableSeats() {
    return availableSeats;
}


void Movie::setAvailableSeats(int availableSeats) {
    this->availableSeats = availableSeats;
}

void Movie::setAudienceRadius(int audienceRadius) {
    this->audienceRadius = audienceRadius;

}

int Movie::getAudienceRadius() {
    return audienceRadius;
}

int Movie::getOccupiableSeats() {
    return occupiableSeats;
}

void Movie::setOccupiableSeats(int occupiableSeats) {
    this->occupiableSeats = occupiableSeats;
}

string Movie::getMovieTime() {
    return movieTime;
}

void Movie::setMovieTime(string time) {
    this->movieTime = time;
}

int Movie::getNumRes() {
    return numRes;
}

void Movie::setNumRes(int numRes) {
    this->numRes = numRes;
}

int Movie::getNumRows() {
    return numRows;
}

void Movie::setNumRows(int r) {
    this->numRows = r;
}

int Movie::getNumColumns() {
    return numColumns;
}

void Movie::setNumColumns(int c) {
    this->numColumns = c;
}











