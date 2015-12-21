#include "Patron.hpp"
#include <string>
#include <vector>


Patron::Patron(std::string idn, std::string n)
{
    idNum = idn;
    name = n;
    fineAmount = NULL;
}
std::string Patron::getIdNum()
{
    return idNum;
}
std::string Patron::getName()
{
    return name;
}
std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
    return checkedOutItems;
}
void Patron::addLibraryItem(LibraryItem* b)
{
    checkedOutItems.push_back(b);
}
void Patron::removeLibraryItem(LibraryItem* b)
{
    for (int i = 0; i < checkedOutItems.size(); i++)
    {
        if (checkedOutItems[i] == b)
        {
            checkedOutItems.erase(checkedOutItems.begin() + i);
        }
    }
}
double Patron::getFineAmount()
{
    return fineAmount;
}
void Patron::amendFine(double amount)
{
    fineAmount = amount + fineAmount;
}

