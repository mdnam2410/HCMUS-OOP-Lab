#ifndef FOLDER_H
#define FOLDER_H

#include "File.h"

#include <string>
#include <vector>
using namespace std;

class Folder : public File
{
private:
    vector<File*> m_items;

public:
    Folder(const string &name);

    Folder(const Folder &folder);

    ~Folder() override;

    long size() const override;

    void add(File *file);

    void add(Folder *folder);
};

#endif
