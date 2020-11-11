#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    Random();

    ~Random();

    int next() const;

    int next(int max) const;
};

#endif