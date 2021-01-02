#include "Livestock.h"

Livestock::Livestock(bool gender, bool isHungry)
    : m_gender{gender}, m_isHungry{isHungry}, m_maxChildDeliverOnce{}, m_maxMilkSupply{}
{}

Livestock::~Livestock()
{}

bool Livestock::gender() const
{
    return m_gender;
}

bool Livestock::isHungry() const
{
    return m_isHungry;
}

int Livestock::maxOffspringsDeliverOnce() const
{
    return m_maxChildDeliverOnce;
}

double Livestock::maxMilkSupply() const
{
    return m_maxMilkSupply;
}
