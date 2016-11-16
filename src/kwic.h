#ifndef SRC_KWIC_H
#define SRC_KWIC_H

#include <set>
#include <vector>
#include <iosfwd>
#include "Word.h"

void kwic(std::istream& in, std::ostream& out);
std::set<std::vector<Word>> insertLine(std::istream& in);
std::set<std::vector<Word>> rotateLine(std::set<std::vector<Word>> input);
void printLine(std::set<std::vector<Word>> result, std::ostream& outputStream);

#endif
