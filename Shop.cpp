#include "Shop.h"
#include "exception"

Book *Shop::CreateBook(long long int isbn, string title, int count_authors, int price, vector<Author *> authors,
                       char *publisher, int year, int pages) {
    Book *book = new Book(isbn, title, price, authors, publisher, year, pages);
    count_authors_ += count_authors;
    for (Author *author: authors) {
        authors_.push_back(author);
    }
    pair<long long int, Book *> pair;
    pair.first = isbn;
    pair.second = book;
    books_.insert(pair);
    return book;
}

bool Shop::AddBook(Book *book) {
    if (book == nullptr) {
        throw range_error("Book* is nullptr");
    }

    if (books_.contains(book->isbn())) {
        return false;
    }

    count_authors_ += book->count_authors();
    for (Author *author: book->authors()) {
        authors_.push_back(author);
    }

    pair<long long int, Book *> pair;
    pair.first = book->isbn();
    pair.second = book;
    books_.insert(pair);
    return true;
}

vector<Book *> Shop::FindByTitle(string title) {
    vector<Book *> books;
    for (int i = 0; i < books_.size(); ++i) {
        if (books_[i]->title() == title) {
            books.push_back(books_[i]);
        }
    }
    return books;
}

vector<Book *> Shop::FindByPublisher(string publisher) {
    vector<Book *> books;
    for (int i = 0; i < books_.size(); ++i) {
        if (books_[i]->publisher() == publisher) {
            books.push_back(books_[i]);
        }
    }
    return books;
}

vector<Book *> Shop::AllBooks() {
    vector<Book *> books;
    for (int i = 0; i < books_.size(); ++i) {
        books.push_back(books_[i]);
    }
    return books;
}

bool Shop::DeleteBook(Book *book) {
    if (book == nullptr) {
        throw range_error("Book* is nullptr");
    }

    if (books_.contains(book->isbn())) {
        return false;
    }
    int i = books_.erase(book->isbn());
    delete book;
    return i;
}

Author *Shop::CreateAuthor(string last_name, string first_name) {
    Author *author = new Author(last_name, first_name);
    authors_.push_back(author);
    count_authors_++;
    return author;
}

Author *Shop::CreateAuthor(string last_name, string first_name, short birth_year) {
    Author *author = new Author(last_name, first_name, birth_year);
    authors_.push_back(author);
    count_authors_++;
    return author;
}

Author *Shop::CreateAuthor(string last_name, string first_name, string second_name, short birth_year) {
    Author *author = new Author(last_name, first_name, second_name, birth_year);
    authors_.push_back(author);
    count_authors_++;
    return author;
}

bool Shop::AddAuthor(Author *author) {
    if (author == nullptr) {
        throw range_error("Author* is nullptr");
    }

    if (std::find(authors_.begin(), authors_.end(), author) != authors_.end()) {
        return false;
    }
    authors_.push_back(author);
    count_authors_++;
    return true;
}

vector<Author *> Shop::FindBySubstringInFullName(string substring) {
    vector<Author *> authors;
    for (int i = 0; i < books_.size(); ++i) {
        vector<Author *> temp = books_[i]->authors();
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j]->first_name().find(substring) || temp[j]->second_name().find(substring) ||
                temp[j]->last_name().find(substring)) {
                authors.push_back(temp[j]);
            }
        }
    }
    return authors;
}

vector<Book *> Shop::FindBooksByAuthorLastName(string last_name) {
    vector<Book *> books;
    for (int i = 0; i < books_.size(); ++i) {
        vector<Author *> authors = books_[i]->authors();
        for (int j = 0; j < authors.size(); ++j) {
            if (authors[j]->last_name() == last_name) {
                books.push_back(books_[i]);
            }
        }
    }
    return books;
}

vector<long long> Shop::DeleteBooks(shared_ptr<Book> book) {
    vector<long long int> isbns;
    Author* author = book->authors()[0];//удаляются книжки только одного автора
    for (int i = 0; i < authors_.size(); ++i) {
        if (authors_[i] == author){
            authors_.erase(i);
        }
    }
    vector<Book*> books = FindBooksByAuthorLastName(author->last_name());

    for (Book* bookI : books) {
        isbns.push_back(bookI->isbn());
    }

    for (Book* bookI : books) {

    }



    return isbns;
}
