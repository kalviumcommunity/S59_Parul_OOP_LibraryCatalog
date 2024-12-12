#include "Book.h"

int Book::totalBooks = 0;

Book::Book() : title("Unknown"), author("Unknown"), ISBN("Unknown"), available(false) {
    totalBooks++;
}

Book::Book(string t, string a, string i, bool avail)
    : title(t), author(a), ISBN(i), available(avail) {
    totalBooks++;
}

Book::~Book() {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}

bool Book::isAvailable() const {
    return available;
}

Book& Book::setAvailability(bool avail) {
    available = avail;
    return *this;
}

int Book::getTotalBooks() {
    return totalBooks;
}

void Book::decrementTotalBook() {
    totalBooks--;
}

string Historical::getCountry() const {
    return country;
}

string Mystery::getType() const {
    return type;
}