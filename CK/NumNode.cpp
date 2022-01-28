#include "NumNode.h"

NumNode::NumNode() : m_val{}
{}

NumNode::NumNode(double value) : m_val {value} {}

NumNode::~NumNode() {}

double NumNode::evaluate() const
{
    return m_val;
}
