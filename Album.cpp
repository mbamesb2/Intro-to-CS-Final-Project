#include "Album.hpp"
#include <string>

std::string Album::getArtist()
{
    return artist;
}
void Album::setArtist(std::string art)
{
    artist = art;
}

Album::Album(std::string id, std::string title , std::string arts) : LibraryItem(id, title)
{
    setArtist(arts);
}

int Album::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}
