#include <bits/stdc++.h>
#include "./Book.h"

using namespace std;

Book::Book(string t, string a, string i, bool avail)  
    : title(t), author(a), ISBN(i), available(avail) {}

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

void Book::setAvailability(bool avail){
    available = avail;
}