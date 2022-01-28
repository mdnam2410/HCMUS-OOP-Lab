#ifndef OPNODE_H
#define OPNODE_H

#include "NumNode.h"

using namespace std;

class OpNode : public NumNode
{
private:
    char m_op;
    NumNode *m_l;
    NumNode *m_r;
    
public:
    OpNode(char op);

    OpNode(const OpNode &other);

    OpNode();

    virtual double evaluate() const;

    void add_left(const OpNode &opnode);

    void add_left(const NumNode &numnode);

    void add_right(const OpNode &opnode);

    void add_right(const NumNode &numnode);
};

#endif
