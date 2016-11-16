#include "kwic.h"
#include <sstream>
#include <algorithm>
#include <istream>
#include <iterator>
#include <ostream>

void kwic(std::istream& inputStream, std::ostream& outputStream) {
	std::set<std::vector<Word>> result = rotateLine(insertLine(inputStream));
	printLine(result, outputStream);
}

std::set<std::vector<Word>> insertLine(std::istream& input) {
	std::set<std::vector<Word>> inputSet { };
	std::string lineString { };
	std::vector<Word> lineList { };

	Word readWord { };

	while (getline(input, lineString)) {
		std::stringstream line { lineString };
		lineList.clear();

		while (line >> readWord) {
			lineList.push_back(readWord);
		}

		inputSet.insert(lineList);
	}

	return inputSet;
}

std::set<std::vector<Word>> rotateLine(std::set<std::vector<Word>> input) {
	std::set<std::vector<Word>> resultWord { };

	for (auto currentLine : input) {
		for (size_t index { 0 }; index < currentLine.size(); ++index) {
			std::vector<Word> outputLine { };
			std::rotate_copy(currentLine.begin(), currentLine.begin() + 1, currentLine.end(), std::back_inserter(outputLine));
			resultWord.insert(outputLine);
		}
	}
/*
	for (std::vector<Word>::iterator it = a.begin(); it != a.end(); ++it) {
		for (std::vector<Word>::iterator it = a.begin(); it != a.end(); ++it) {
			std::cout << ' ' << *it;
		}
		std::cout << '\n';
		std::rotate(a.begin(), a.begin() + 1, a.end());
	}
*/
	return resultWord;
}

void printLine(std::set<std::vector<Word>> resulti, std::ostream& outputStream) {
	for (auto line : resulti) {
		auto outputIterator = std::ostream_iterator<Word> { outputStream, " " };
		std::copy(line.cbegin(), line.cend(), outputIterator);
	}
}

