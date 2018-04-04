//main.cpp

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>    // sort(), find()

#include "duree.h"

using namespace std;
using namespace nsUtil;

void testDuree ()
{
    const unsigned KDureeMax (1000000);
    typedef vector <nsUtil::Duree> CVDuree;
    typedef CVDuree::const_iterator Iter;
     unsigned size;
    cout << "Taille du vector : ";
    cin >> size;
    CVDuree vDuree;
    cout << "Saisissez " << size << " durées en secondes:"<< endl;
    for (unsigned i = 0; i < size; ++i)
    {
        unsigned long long uneDuree;
        cin >> uneDuree;
        vDuree.push_back (uneDuree);
    }

    cout << "Vecteur non trié" << endl;
    for (const Duree & d : vDuree)
    {
        d.display ();
        cout << endl;
    }

    unsigned long long dureecomprise;
    for (;;)
    {
        cout<< "Saisir une durée: ";
        cin>> dureecomprise;
        if (cin.eof ()) break;
        if (find (vDuree.begin (), vDuree.end (), Duree (dureecomprise))!= vDuree.end())
                cout << "Cette valeur est dans le vector"<< endl;
        else
            cout << "Cette valeur n'est pas dans le vector"<< endl;

    }

    sort (vDuree.begin (), vDuree.end ());
    cout << "Vecteur trié" << endl;
    for (const Duree & d : vDuree)
    {
        d.display ();
        cout << endl;
    }

}


int main(void)
{
    testDuree();
    return 0;
}






