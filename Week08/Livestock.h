#ifndef _LIVESTOCK_H
#define _LIVESTOCK_H

#include <vector>
#define MALE true
#define FEMALE false

class Livestock
{
protected:
    /// True for male, false for female
    bool m_gender;
    bool m_isHungry;
    int m_maxChildDeliverOnce;
    double m_maxMilkSupply;

    Livestock(bool gender, bool isHungry);
    
public:

    enum { CATTLE, SHEEP, GOAT };

    ~Livestock();

    bool gender() const;

    bool isHungry() const;

    int maxOffspringsDeliverOnce() const;

    double maxMilkSupply() const;
};

#endif
