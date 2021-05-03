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
        int getLength();
        bool checkExists(const long movieID) const;
        void addMovie(const long movieID, const int audienceRadius);
        void removeMovie(int index);
        void showAll() const;
        int getRadius(const long movieID) const;
        int getAvailableSeats(const long movieID)const;
        void decreaseOneSeat(const long movieID);
        void increaseOneSeat(const long movieID);
        int findIndex(const long movieID);

    private:
        struct MovieNode{
            long movieID;
            string movieTime;
            int audienceRadius;
            int availableSeats;
            int numRows;
            int numColumns;

            MovieNode* next;
            MovieNode* prev;
        };
        int size;
        MovieNode *head;
        MovieNode *tail;

        //helper functions
        string calculateTime(const long movieID) const;
        int calculateRows(int audienceRadius);
        int calculateColumns(int audienceRadius);
        MovieNode *find(int index) const;

};


#endif //HW3_MOVIELIST_H
