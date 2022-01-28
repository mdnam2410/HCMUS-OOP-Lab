#include "Folder.h"

using namespace std;

Folder::Folder(const string &name) : File(name), m_items{} {}

Folder::Folder(const Folder &other) : Folder(other.m_name)
{
    m_items.resize(other.m_items.size());
    for (size_t i = 0; i < other.m_items.size(); ++i) {
        File *f = new File(*other.m_items[i]);
        m_items[i] = f;
    }
}

Folder::~Folder()
{
    for (auto &item : m_items)
        delete item;
}

long Folder::size() const
{
    long r = 0;
    for (auto item : m_items)
        r += item->size();
    return r;
}

void Folder::add(File *file)
{
    //File *f = new File(file);
    m_items.push_back(file);
}

void Folder::add(Folder *folder)
{
    //Folder *f = new Folder(folder);
    m_items.push_back(folder);
}
