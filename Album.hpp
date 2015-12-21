
#ifndef ALBUM_HPP
#define ALBUM_HPP
#include "LibraryItem.hpp"
#include <string>

class Album : public LibraryItem
{
private:
    std::string artist;
public:
    Album(std::string id, std::string title , std::string art);
    static const int CHECK_OUT_LENGTH = 14;
    std::string getArtist();
    void setArtist(std::string);
    int getCheckOutLength();
    
};
#endif


