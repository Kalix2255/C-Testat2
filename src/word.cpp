
#include "Word.h"
#include <string>
#include <istream>
#include <exception>
#include <algorithm>

std::istream & Word::read(std::istream& in){
	std::string buffer{""};
	char input {};
	while(in){
		if(in.get(input)){
			if(::isalpha(input)){
				buffer += input;
			}else{
				myWord = buffer;
				break;
			}
		}
	}
	myWord = buffer;
	return in;
};

void Word::isValid(std::string const & in){
	if(in.empty()){
		throw std::invalid_argument("Empty String!!!");
	}
	if(!std::all_of(begin(in), end(in), ::isalpha)){
		throw std::invalid_argument("Minimum one non valid character!");
	}
}


std::ostream & Word::print(std::ostream& out) const{
	out << Word::myWord;
	return out;
};


bool Word::operator==(Word const & w1)const{
	return (!((*this) < w1) && !((*this) > w1));
}
bool Word::operator!=(Word const & w1)const{
	return !((*this) == w1);
}
bool Word::operator<=(Word const & w1)const{
	return !((*this) > w1);
}
bool Word::operator>=(Word const & w1)const{
	return !((*this) < w1);
}
bool Word::operator>(Word const & w1)const{
	return (w1 < (*this));
}
bool Word::operator<(Word const & w1)const{
	return (std::lexicographical_compare(myWord.begin(), myWord.end(), w1.myWord.begin(), w1.myWord.end(), ([](char c1, char c2) -> bool{
		return std::tolower(c1)<std::tolower(c2);
	})));
}


std::ostream & operator<<(std::ostream& out, Word const & w){
	return w.print(out);
};

std::istream & operator>>(std::istream& in, Word & w){
	return w.read(in);
};


