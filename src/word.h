#include <iosfwd>
#include <istream>
#include <ostream>
#include <string>

#ifndef SRC_WORD_H_
#define SRC_WORD_H_

class Word{
	std::string myWord;

public:
	Word():
		myWord {""}{
	}
	explicit Word(std::string const& in):
		myWord {in}{
			isValid(in);
	}

std::istream & read(std::istream&);
std::ostream & print(std::ostream&)const;

bool operator==(Word const &)const;
bool operator!=(Word const &)const;
bool operator<=(Word const &)const;
bool operator>=(Word const &)const;
bool operator<(Word const &)const;
bool operator>(Word const &)const;



private:
void isValid(std::string const&);


};


std::ostream & operator<<(std::ostream&, Word const &);
std::istream & operator>>(std::istream&, Word &);


#endif /* SRC_WORD_H_ */
