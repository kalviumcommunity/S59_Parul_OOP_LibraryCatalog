#include <bits/stdc++.h>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;
    static int totalBooks;

public:
    Book();
    Book(string t, string a, string i, bool avail);
    ~Book();

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isAvailable() const;
    static int getTotalBooks();
    static void decrementTotalBook();

    Book& setAvailability(bool avail);
};

class Historical : public virtual Book {
private:
    string country;

public:
    Historical(string t, string a, string i, bool avail, string country)
        : Book(t, a, i, avail), country(country) {}

    string getCountry() const {
        return country;
    }
};

class Mystery : public virtual Book, public Historical {
private:
    string type;

public:
    Mystery(string t, string a, string i, bool avail, string country, string type)
        : Book(t, a, i, avail), Historical(t, a, i, avail, country), type(type) {}

    string getType() const {
        return type;
    }
};