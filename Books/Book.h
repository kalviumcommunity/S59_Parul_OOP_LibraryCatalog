#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <iostream>
using namespace std;

class IDisplayable {
public:
    virtual void displayBookInfo() const = 0; 
};

class Book : public IDisplayable {
protected:
    string title;
    string author;
    string ISBN;
    bool available;

public:
    Book(string t, string a, string i, bool avail = true)
        : title(t), author(a), ISBN(i), available(avail) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool isAvailable() const { return available; }

    void displayBookInfo() const override {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << ISBN << "\nAvailable: " << (available ? "Yes" : "No") << endl;
    }

    virtual ~Book() = default; 
};

#endif
