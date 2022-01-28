#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File
{
protected:
    string m_name;

public:
    File(const string &name);

    virtual ~File();

    virtual long size() const;
};

#endif
