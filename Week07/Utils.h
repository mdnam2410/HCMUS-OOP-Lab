#include "Point.h"

#include <string>

/**
 * @brief Parse a number of Point objects specified by n
 * 
 * @param input The input to parse
 * @param n The number of Point objects
 * @param separator A character separates between each point
 * @return A list of n points parsed on success, nullptr if fail
 */
Point* ParsePoint(const std::string &input, int n, char separator = ',');

/**
 * @brief Count the number of words in STR
 * 
 * @param str 
 * @return int 
 */
int CountWords(const std::string &str);
