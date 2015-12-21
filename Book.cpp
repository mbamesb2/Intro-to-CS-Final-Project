#include "Book.hpp"
#include <string>

std::string Book::getAuthor()
{
    return author;
}
void Book::setAuthor(std::string auth)
{
    author = auth;
}

int Book::getCheckOutLength()
{
    return CHECK_OUT_LENGTH;
}
Book::Book(std::string id, std::string title, std::string auth) : LibraryItem(id, title)
{
    setAuthor(auth);
    title = title;
    id = id;
    
}
