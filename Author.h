#ifndef GOOGLE_TESTS_AUTHOR_H
#define GOOGLE_TESTS_AUTHOR_H

#include "string"

using namespace std;

class Author {
    string last_name_;
    string first_name_;
    string second_name_;
    short birth_year_;
public:
    Author(string last_name, string first_name);

    Author(string last_name, string first_name, short birth_year);

    Author(string last_name, string first_name, string second_name, short birth_year);

    ~Author() = default;

    string last_name();

    string first_name();

    string second_name();

    short birth_year();

    string full_name();

    bool operator==(Author *author);
};


#endif //GOOGLE_TESTS_AUTHOR_H
