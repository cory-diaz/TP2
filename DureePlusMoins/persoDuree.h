//duree.h
 
#ifndef DUREE_H
#define DUREE_H

namespace nsUtil {
    class Duree {

    private:
        unsigned long myDuree;
        unsigned long mySeconds;
        unsigned myMinutes;
        unsigned myHours;
        unsigned myDays;
        void normaliser();

    public:
        unsigned long getDuree() const;
        void display() const;
        void incr (unsigned delta);
        void decr (unsigned delta);
        Duree(unsigned long seconde);
        Duree operator + (const Duree & d1) const;
        Duree operator - (const Duree & d1) const;
        bool  operator < (const Duree & d1) const;
        bool operator == (const Duree & d1) const;
    }; // Duree
} // nsUtil
#endif // DUREE_H

