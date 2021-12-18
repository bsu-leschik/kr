#include "Book.h"

Book::Book(long long int isbn) {
    isbn_ = isbn;
}

Book::Book(long long int isbn, string title, int price) {
    isbn_ = isbn;
    title_ = title;
    price_ = price;
}

Book::Book(long long int isbn, string title, int price, vector<Author *> authors, char *publisher, int year,
           int pages) {
    isbn_ = isbn;
    title_ = title;
    price_ = price;
    authors_ = authors;
    publisher_ = publisher;
    year_ = year;
    pages_ = pages;
}

long long int Book::isbn() {
    return isbn_;
}

string Book::title() {
    return title_;
}

unsigned long Book::count_authors() {
    return authors_.size();
}

vector<Author *> Book::authors() {
    return authors_;
}

char *Book::publisher() {
    return publisher_;
}

int Book::year() {
    return year_;
}

int Book::pages() {
    return pages_;
}

int Book::price() {
    return price_;
}

Book::Book(Book &book) {
    isbn_ = book.isbn_;
    title_ = book.title_;
    price_ = book.price_;
    authors_ = book.authors_;
    publisher_ = book.publisher_;
    year_ = book.year_;
    pages_ = book.pages_;
}

Book::Book(Book &&book) {
    isbn_ = book.isbn_;
    title_ = book.title_;
    price_ = book.price_;
    authors_ = book.authors_;
    publisher_ = book.publisher_;
    year_ = book.year_;
    pages_ = book.pages_;
    delete &book;
}

Book &Book::operator=(Book book) {
    isbn_ = book.isbn_;
    title_ = book.title_;
    price_ = book.price_;
    authors_ = book.authors_;
    publisher_ = book.publisher_;
    year_ = book.year_;
    pages_ = book.pages_;
    delete &book;
    return *this;
}

Book &Book::operator=(Book &&book) {
    isbn_ = book.isbn_;
    title_ = book.title_;
    price_ = book.price_;
    authors_ = book.authors_;
    publisher_ = book.publisher_;
    year_ = book.year_;
    pages_ = book.pages_;
    delete &book;
    return *this;
}

ostream &Book::operator<<(ostream &out) {
    out << "ISBN: " << isbn_ << endl;
    out << "Title: " << title_ << endl;
    out << "Price: " << price_ << endl;
    out << "Authors: ";
    for (Author *author: authors_) {
        out << author << " ";
    }
    out << endl;
    out << "Publisher: " << publisher_ << endl;
    out << "Year: " << year_ << endl;
    out << "Pages: " << pages_ << endl;

    return out;
}

bool Book::operator<(Book &book) {
    return price_ < book.price_;
}




