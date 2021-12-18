#include "Author.h"

Author::Author(string last_name, string first_name) {
    last_name_ = last_name;
    first_name_ = first_name;
}

Author::Author(string last_name, string first_name, short birth_year) {
    last_name_ = last_name;
    first_name_ = first_name;
    birth_year_ = birth_year;
}

Author::Author(string last_name, string first_name, string second_name, short birth_year) {
    last_name_ = last_name;
    first_name_ = first_name;
    second_name_ = second_name;
    birth_year_ = birth_year;
}

string Author::last_name() {
    return last_name_;
}

string Author::first_name() {
    return first_name_;
}

string Author::second_name() {
    return second_name_;
}

short Author::birth_year() {
    return birth_year_;
}

string Author::full_name() {
    return last_name_ + first_name_ + second_name_;
}

bool Author::operator==(Author *author) {
    if (author->first_name_ == first_name_ && author->last_name_ == last_name_ && author->birth_year_ == birth_year_ &&
        author->second_name_ == second_name_) {
        return true;
    }
    return false;
}




