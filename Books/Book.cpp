#include <bits/stdc++.h>
#include "./Book.h"

using namespace std;

int Book::totalBooks = 0;

Book::Book(string t, string a, string i, bool avail) {
    this->title = t;
    this->author = a;
    this->ISBN = i;
    this->available = avail;

    totalBooks++;
}

string Book::getTitle() const {
    return this->title;
}

string Book::getAuthor() const {
    return this->author;
}

string Book::getISBN() const {
    return this->ISBN;
}

bool Book::isAvailable() const {
    return this->available;
}

Book& Book::setAvailability(bool avail) {
    this->available = avail;
    return *this;
}

int Book::getTotalBooks() {
    return totalBooks;
}

void Book::decrementTotalBooks() {
    totalBooks--;
}