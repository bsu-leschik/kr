#ifndef GOOGLE_TESTS_BOOK_H
#define GOOGLE_TESTS_BOOK_H


#include "Author.h"
#include <vector>
#include <ostream>

using namespace std;

class Book {
    long long int isbn_;
    string title_;
    vector<Author *> authors_;
    char *publisher_;
    int year_;
    int pages_;
    int price_;
public:
    Book(long long int isbn);

    Book(long long int isbn, string title, int price);

    Book(long long int isbn, string title, int price, vector<Author *> authors, char *publisher, int year, int pages);

    ~Book() = default;

    Book(Book &book);

    Book(Book &&book);

    long long int isbn();

    string title();

    unsigned long count_authors();

    vector<Author *> authors();

    char *publisher();

    int year();

    int pages();

    int price();

    Book &operator=(Book book);

    Book &operator=(Book &&book);

    ostream &operator<<(ostream &out);

    bool operator<(Book &book);
};


#endif //GOOGLE_TESTS_BOOK_H
