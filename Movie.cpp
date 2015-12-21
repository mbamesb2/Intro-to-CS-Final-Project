#include "Movie.hpp"
#include <string>

std::string Movie::getDirector()
{
    return director;
}
void Movie::setDirector(std::string dir)
{
    director = dir;
}

Movie::Movie(std::string id, std::string title , std::string dir) : LibraryItem(id, title)
{
    setDirector(dir);
}

int Movie::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}
