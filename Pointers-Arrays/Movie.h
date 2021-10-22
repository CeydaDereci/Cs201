//
// Created by Ceyda Dereci on 3.03.2021.
//

#ifndef HW1_MOVIE_H
#define HW1_MOVIE_H
#include <string>

using namespace std;

class Movie {
    public:
        Movie();
        Movie(const Movie &movie);
        ~Movie();

        Movie& operator=(const Movie &other);

        long getMovieID();
        void setMovieID(long movieID);

        int getAudienceRadius();
        void setAudienceRadius(int audienceRadius);

        int getAvailableSeats();
        void setAvailableSeats(int availableSeats);

        int getOccupiableSeats();
        void setOccupiableSeats(int occupiableSeats);

        string getMovieTime();
        void setMovieTime(string time);

        int getNumRes();
        void setNumRes(int numRes);

        int getNumRows();
        void setNumRows(int r);

        int getNumColumns();
        void setNumColumns(int c);

    private:
        long movieID;
        string movieTime;
        int audienceRadius;
        int availableSeats;
        int occupiableSeats;
        int numRes;
        int numRows;
        int numColumns;
};


#endif //HW1_MOVIE_H
