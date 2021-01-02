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

    virtual ~Livestock();

    bool gender() const;

    bool isHungry() const;

    int maxOffspringsDeliverOnce() const;

    double maxMilkSupply() const;

    virtual double produceMilk() const = 0;

    virtual void makeSound() const = 0;

    virtual int type() const = 0;

    virtual Livestock* giveBirthOnce() const = 0;

    //virtual int maxOffspringsDeliverOnce() const;

    //virtual std::vector<Livestock*> giveBirth() const;

    /**
     * @brief Return a list of new born offsprings and modify the variable numOfOffsprings
     * 
     * @param numOfOffsprings Will be modified to the number of offsprings that the function
     *                        creates
     * @return A list of new Livestock* object, nullptr if fail
     */
    //virtual Livestock** t_giveBirth(int &numOfOffsprings) const;
};

#endif
