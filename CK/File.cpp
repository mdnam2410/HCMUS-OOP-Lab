#include "File.h"

using namespace std;

File::File(const string &name) : m_name {name} {}

File::~File() {}

long File::size() const
{
    return 1L;
}
