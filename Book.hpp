
#ifndef BOOK_HPP
#define BOOK_HPP
#include "LibraryItem.hpp"
#include <string>

class Book : public LibraryItem
{
private:
    std::string author;
public:
    Book(std::string id, std::string title, std::string auth);
    static const int CHECK_OUT_LENGTH = 21;
    std::string getAuthor();
    void setAuthor(std::string);
    int getCheckOutLength();
   
};
#endif


