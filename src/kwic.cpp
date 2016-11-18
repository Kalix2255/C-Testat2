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
	std::set<std::vector<Word>> resultWord {input};

	for (auto currentLine : input) {
		std::vector<Word> rotated {currentLine};
		for(auto word : rotated){
			std::rotate(rotated.begin(), rotated.begin()+rotated.size()/2, rotated.end());
			resultWord.insert(rotated);
		}

	}

	return resultWord;
}

void printLine(std::set<std::vector<Word>> resulti, std::ostream& outputStream) {
	for (auto line : resulti) {
		auto outputIterator = std::ostream_iterator<Word> { outputStream, " " };
		std::copy(line.cbegin(), line.cend(), outputIterator);
	}
}

