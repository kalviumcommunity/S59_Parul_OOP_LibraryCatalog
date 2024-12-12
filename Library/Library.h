#ifndef LIBRARY_H
#define LIBRARY_H

#include <bits/stdc++.h>
#include "../Books/Book.h"

using namespace std;
using namespace std;

class Library {
private:
    vector<Book*> books;

public:
    void addBook(Book* book);
    void removeBook(const string& ISBN);
    vector<Book*> searchByTitle(const string& title) const;
    vector<Book*> searchByAuthor(const string& author) const;
    vector<Book*> getAllBooks() const;
    ~Library();
};

#endif