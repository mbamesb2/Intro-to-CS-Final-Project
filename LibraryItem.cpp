#include "LibraryItem.hpp"
#include <iostream>
#include <string>


LibraryItem::LibraryItem(std::string idc, std::string t)      // constructor
{
    idCode = idc;
    title = t;
    setCheckedOutBy(NULL);
    setRequestedBy(NULL);
    location = ON_SHELF;
    
}
std::string LibraryItem::getIdCode()
{
    return idCode;
}

std::string LibraryItem::getTitle()
{
    return title;
}

Locale LibraryItem::getLocation()
{
    return location;
}

void LibraryItem::setLocation(Locale loc)
{
    location = loc;
}

Patron* LibraryItem::getCheckedOutBy()
{
    return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron* pat)
{
    checkedOutBy = pat;
}

Patron* LibraryItem::getRequestedBy()
{
    return requestedBy;
}

void LibraryItem::setRequestedBy(Patron* req)
{
    requestedBy = req;
}

int LibraryItem::getDateCheckedOut()
{
    return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int date)
{
    dateCheckedOut = date;
}










