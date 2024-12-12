#include "Book.h"

int Book::totalBooks = 0;

Book::Book() : title("Unknown"), author("Unknown"), ISBN("Unknown"), available(false) {
    totalBooks++;
}

Book::Book(string t, string a, string i, bool avail)
    : title(t), author(a), ISBN(i), available(avail) {
    totalBooks++;
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return ISBN; }
bool Book::isAvailable() const { return available; }
Book& Book::setAvailability(bool avail) {
    available = avail;
    return *this;
}
int Book::getTotalBooks() { return totalBooks; }

Historical::Historical() : Book(), country("Unknown") {}

Historical::Historical(string t, string a, string i, bool avail, string country)
    : Book(t, a, i, avail), country(country) {}

string Historical::getCountry() const { return country; }

void Historical::displayBookInfo() const {
    cout << "Historical Book Info:\n";
    cout << "Title: " << title << "\nAuthor: " << author
         << "\nISBN: " << ISBN << "\nCountry: " << country
         << "\nAvailable: " << (available ? "Yes" : "No") << "\n";
}

Mystery::Mystery() : Historical(), type("Unknown") {}

Mystery::Mystery(string t, string a, string i, bool avail, string country, string type)
    : Historical(t, a, i, avail, country), type(type) {}

string Mystery::getType() const { return type; }

void Mystery::displayBookInfo() const {
    cout << "Mystery Book Info:\n";
    cout << "Title: " << title << "\nAuthor: " << author
         << "\nISBN: " << ISBN << "\nCountry: " << getCountry()
         << "\nType: " << type << "\nAvailable: " << (available ? "Yes" : "No") << "\n";
}