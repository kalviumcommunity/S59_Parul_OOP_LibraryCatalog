#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string ISBN;
    bool available;
    static int totalBooks;

public:
    Book();
    Book(string t, string a, string i, bool avail);
    virtual ~Book() { totalBooks--; }

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isAvailable() const;
    Book& setAvailability(bool avail);

    static int getTotalBooks();

    virtual void displayBookInfo() const = 0; 
};

class Historical : public Book {
private:
    string country;

public:
    Historical();
    Historical(string t, string a, string i, bool avail, string country);

    string getCountry() const;
    void displayBookInfo() const override;
};

class Mystery : public Historical {
private:
    string type;

public:
    Mystery();
    Mystery(string t, string a, string i, bool avail, string country, string type);

    string getType() const;
    void displayBookInfo() const override;
};

#endif