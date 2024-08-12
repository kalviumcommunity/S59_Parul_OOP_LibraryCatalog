#include <bits/stdc++.h>
// #include "./Books/Book.h"

using namespace std;

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book);

    void removeBook(const string& ISBN);

    vector<Book> searchByTitle(const string& title) const;

    vector<Book> searchByAuthor(const string& title) const;

    vector<Book> getAllBooks() const;
};