
#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "LibraryItem.hpp"
#include <string>

class Movie : public LibraryItem
{
private:
    std::string director;
public:
    Movie(std::string id, std::string title , std::string dir);
    static const int CHECK_OUT_LENGTH = 7;
    std::string getDirector();
    void setDirector(std::string);
    int getCheckOutLength();
    
};
#endif


