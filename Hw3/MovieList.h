//
// Created by Ceyda Dereci on 25.04.2021.
//

#ifndef HW3_MOVIELIST_H
#define HW3_MOVIELIST_H
#include <string>
#include <iostream>
using namespace std;

class MovieList {
    public:
        MovieList();
        ~MovieList();
        MovieList(const MovieList& aList);
        bool isEmpty() const;
        void add(const long movieID, const int audienceRadius);
        void remove(const long movieID);
        void showAll() const;
        void show(const long movieID) const;

    private:
        struct MovieNode{
            long movieID;
            string movieTime;
            int audienceRadius;
            int availableSeats;
            int occupiableSeats;
            int numRes;
            int numRows;
            int numColumns;

            MovieNode* next;
            MovieNode* prev;
        };
        int size;
        MovieNode *head;
        MovieNode *tail;

        //helper methods
        string calculateTime(const long movieID) const;
        bool checkExists(const long movieID) const;
        int calculateRows(int audienceRadius);
        int calculateColumns(int audienceRadius);
        void printSeatPlan(int audienceRadius) const;

};


#endif //HW3_MOVIELIST_H
