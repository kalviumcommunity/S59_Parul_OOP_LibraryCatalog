#include <bits/stdc++.h>
#include "./Book.h"

using namespace std;

Book::Book(string t, string a, string i, bool avail) {
    this->title = t;
    this->author = a;
    this->ISBN = i;
    this->available = avail;
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