#ifndef GOOGLE_TESTS_SHOP_H
#define GOOGLE_TESTS_SHOP_H

#include "Book.h"
#include <map>
#include <memory>

class Shop {
    map<long long int, Book *> books_;
    int count_authors_ = 0;
    vector<Author *> authors_;
public:
    Shop() = default;

    ~Shop() = default;

    Book *CreateBook(long long int isbn, string title, int count_authors, int price, vector<Author *> authors,
                     char *publisher, int year, int pages);

    bool AddBook(Book *book);

    vector<Book *> FindByTitle(string title);

    vector<Book *> FindByPublisher(string publisher);

    vector<Book *> AllBooks();

    bool DeleteBook(Book *book);

    Author *CreateAuthor(string last_name, string first_name);

    Author *CreateAuthor(string last_name, string first_name, short birth_year);

    Author *CreateAuthor(string last_name, string first_name, string second_name, short birth_year);

    bool AddAuthor(Author *author);

    vector<Author *> FindBySubstringInFullName(string substring);

    vector<Book *> FindBooksByAuthorLastName(string last_name);

    vector<long long> DeleteBooks(shared_ptr<Book> book);
};


#endif //GOOGLE_TESTS_SHOP_H
