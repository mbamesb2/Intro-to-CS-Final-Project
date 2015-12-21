#include "Library.hpp"
#include <string>
#include <vector>
#include <iostream>


Library::Library()
{
    currentDate = 0;
}

void Library::addLibraryItem(LibraryItem* lib)
{
    holdings.push_back(lib);
}

void Library::addPatron(Patron* pat)
{
    members.push_back(pat);
}

std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
    if (getLibraryItem(ItemID) && getPatron(patronID))
    {
        if (getLibraryItem(ItemID)->getLocation() == CHECKED_OUT)
        {
            return "item already checked out";
        }
        else if (getLibraryItem(ItemID)->getLocation() == ON_HOLD_SHELF)
        {
            if (getLibraryItem(ItemID)->getRequestedBy() == getPatron(patronID))
            {
                getLibraryItem(ItemID)->setDateCheckedOut(currentDate);
                getLibraryItem(ItemID)->setCheckedOutBy(getPatron(patronID));
                getLibraryItem(ItemID)->setLocation(CHECKED_OUT);
                getLibraryItem(ItemID)->setRequestedBy(NULL);
                getPatron(patronID)->addLibraryItem(getLibraryItem(ItemID));
                return "check out successful";
            }
            else
                return "item on hold by other patron";
        }
        else if (getLibraryItem(ItemID)->getLocation() == ON_SHELF)
        {
            
            getLibraryItem(ItemID)->setDateCheckedOut(currentDate);
            getLibraryItem(ItemID)->setCheckedOutBy(getPatron(patronID));
            getLibraryItem(ItemID)->setLocation(CHECKED_OUT);
            getPatron(patronID)->addLibraryItem(getLibraryItem(ItemID));
            return "check out successful";
        }
        else
            return "Error";
    }
    else if (getLibraryItem(ItemID))
    {
        return "patron not found";
    }
    
    else if (getPatron(patronID))
    {
        return "item not found";
    }
    return "Error";
}

std::string Library::returnLibraryItem(std::string ItemID)
{
   if (getLibraryItem(ItemID))
   {
       if (getLibraryItem(ItemID)->getLocation() == ON_SHELF)
       {
           return "item already in library";
       }
       else
       {
           Patron* pat = getLibraryItem(ItemID)->getCheckedOutBy();
           pat->removeLibraryItem(getLibraryItem(ItemID));
           if (getLibraryItem(ItemID)->getRequestedBy())
           {
               getLibraryItem(ItemID)->setLocation(ON_HOLD_SHELF);
           }
           else
           {
                getLibraryItem(ItemID)->setLocation(ON_SHELF);
           }
       return "return successful";
       }
    }
    else
    {
        return "item not found";
    }
}


std::string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
    if (getLibraryItem(ItemID) && getPatron(patronID))
    {
        
        if (getLibraryItem(ItemID)->getLocation() == ON_HOLD_SHELF)
        {
            return "item on hold by other patron";
        }
        else if (getLibraryItem(ItemID)->getLocation() == CHECKED_OUT)
        {
            if (getLibraryItem(ItemID)->getRequestedBy() == NULL)
            {
                getLibraryItem(ItemID)->setRequestedBy(getPatron(patronID));
                return "request successful";
            }
            else{
                return "item on hold by other patron";
            }
        }
        else if (getLibraryItem(ItemID)->getLocation() == ON_SHELF)
        {
            
            getLibraryItem(ItemID)->setRequestedBy(getPatron(patronID));
            getLibraryItem(ItemID)->setLocation(ON_HOLD_SHELF);
            return "request successful";
        }
        else
            return "Error";
    }
    else if (getLibraryItem(ItemID))
    {
        return "patron not found";
    }
    
    else if (getPatron(patronID))
    {
        return "item not found";
    }
    else
        return "neither patron nor item was found";
}

std::string Library::payFine(std::string patronID, double payment)
{
    if (getPatron(patronID))
    {
        getPatron(patronID)->amendFine(-payment);
        return "payment successful";
    }
    else
        return "patron not found";
}

void Library::incrementCurrentDate()
{
    
    currentDate = currentDate + 1;
    
    for (int i = 0; i < members.size(); i++)
    {
        std::vector<LibraryItem*> overdue = members.at(i)->getCheckedOutItems();
    
        for (int t = 0; t < overdue.size(); t++)
        {
            int date = overdue.at(t)->getDateCheckedOut();
        
            int overDate = (currentDate - date);
        
            if (overDate > overdue.at(t)->getCheckOutLength())
            {
            members.at(i)->amendFine(.10);
            }
        }
    }
}

Patron* Library::getPatron(std::string patronID)
{
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i]->getIdNum() == patronID)
        {
            return members[i];
        }
    }
    return NULL;
}

LibraryItem* Library::getLibraryItem(std::string ItemID)
{
    for (int i = 0; i < holdings.size(); i++)
    {
        if (holdings[i]->getIdCode() == ItemID)
        {
            return holdings[i];
        }
    }
    
    return NULL;
}


