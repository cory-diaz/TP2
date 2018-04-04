//duree.cpp

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "duree.h"
nsUtil::Duree::Duree(unsigned long seconde): myDuree(seconde)
{

    normaliser();

}

unsigned long nsUtil::Duree::getDuree() const  { return myDuree; }

void nsUtil::Duree::incr (unsigned delta)
{
    myDuree += delta;
    normaliser ();
}

void nsUtil::Duree::decr (unsigned delta)
{
    myDuree -= delta <= myDuree ? delta : myDuree;
    normaliser ();
}

nsUtil::Duree nsUtil::Duree::operator + (const Duree & d1) const
{
    return nsUtil::Duree (myDuree + d1.myDuree);
}

nsUtil::Duree nsUtil::Duree::operator - (const Duree & d1) const
{
    return nsUtil::Duree (myDuree - d1.myDuree);
}

bool nsUtil::Duree::operator < (const Duree & d1) const
{
    return myDuree > d1.myDuree;
}

bool nsUtil::Duree::operator == (const Duree & d1) const
{
    return myDuree == d1.myDuree;
}



void nsUtil::Duree::display() const
{
    cout<< setfill(' ') << '['
        << setw(2) << myDays << ':'
        << setfill('0')
        << setw(2) << myHours << ':'
        << setw(2) << myMinutes << ':'
        << setw(2) << mySeconds << ']'
        << endl;

}

void nsUtil::Duree::normaliser()
{
    mySeconds = myDuree %60;
    myMinutes = myDuree /60 %60;
    myHours = myDuree /(60*60) %24;
    myDays = myDuree /(24*60*60);
}


