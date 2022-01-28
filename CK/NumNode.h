#ifndef NUMNODE_H
#define NUMNODE_H

class NumNode
{
private:
    double m_val;

public:
    NumNode();

    NumNode(double value);

    virtual ~NumNode();

    virtual double evaluate() const;
};

#endif
