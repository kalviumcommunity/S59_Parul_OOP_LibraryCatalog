#include <bits/stdc++.h>
#include "./Library.h"

using namespace std;

void Library::addBook(const Book& book){
    books.push_back(book);
}

void Library::removeBook(const string& ISBN){
    for(auto i = books.begin(); i != books.end(); ++i){
        if(i->getISBN() == ISBN){
            books.erase(i);
            return;
        }
    }
}

vector<Book> Library::searchByTitle(const string& title) const {
    vector<Book> foundBooks;
    for(const auto& book : books){
        if(book.getTitle() == title){
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

vector<Book> Library::searchByAuthor(const string& author) const {
    vector<Book> foundBooks;
    for(const auto& book : books){
        if(book.getAuthor() == author){
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}