#include "Utils.h"

#include <sstream>

Point* ParsePoint(const std::string &input, int n, char separator)
{
    Point *result = nullptr;
    size_t sep = 0;
    int i = 0;
    do {
        size_t open_paren = input.find('(', sep);
        size_t close_paren = input.find(')', open_paren);
        sep = input.find(separator, close_paren);
        if (open_paren == std::string::npos || close_paren == std::string::npos)
            break;
        Point *p = Point::Parse(input.substr(open_paren, close_paren - open_paren + 1));
        if (!p)
            break;
        if (!result)
            result = new Point[n];
        result[i] = *p;
        delete p;
        ++i;
    } while (i < n);
    
    if (i < n) {
        delete[] result;
        return nullptr;
    }
    return result;
}

int CountWords(const std::string &str)
{
    std::stringstream s(str);
    std::string t;
    int numOfWords = 0;
    while (s >> t)
        ++numOfWords;
    return numOfWords;
}
