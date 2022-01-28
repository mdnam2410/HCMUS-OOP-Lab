#include "OpNode.h"

#include <string>
using namespace std;

OpNode::OpNode(char op)
{
    m_op = op;
}

OpNode::OpNode(const OpNode &other) : OpNode(other.m_op)
{
    m_l = new NumNode(*other.m_l);
    m_r = new NumNode(*other.m_r); 
}

double OpNode::evaluate() const
{
    double result = 0;
    switch (m_op)
    {
    case '+':
        result = m_l->evaluate() + m_r->evaluate();
        break;
    case '-':
        result = m_l->evaluate() - m_r->evaluate();
        break;
    case '*':
        result = m_l->evaluate() * m_r->evaluate();
        break;
    case '/':
        result = m_l->evaluate() / m_r->evaluate();
        break;
    default:
        throw m_op + ": unrecognized operator";
    }

    return result;
}

void OpNode::add_left(const OpNode &opnode)
{
    OpNode *o = new OpNode(opnode);
    m_l = o;
}

void OpNode::add_left(const NumNode &numnode)
{
    NumNode *n = new NumNode(numnode);
    m_l = n;
}

void OpNode::add_right(const OpNode &opnode)
{
    OpNode *o = new OpNode(opnode);
    m_r = o;
}

void OpNode::add_right(const NumNode &numnode)
{
    NumNode *n = new NumNode(numnode);
    m_r = n;
}
