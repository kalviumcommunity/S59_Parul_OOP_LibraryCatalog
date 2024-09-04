#include <bits/stdc++.h>
#include "./Library.h"

using namespace std;

void Library::addBook(const Book& book){
    books.push_back(book);
    cout << "Total books in the library now: " << Book::getTotalBooks() << endl;
}

void Library::removeBook(const string& ISBN){
    for(auto i = books.begin(); i != books.end(); ++i){
        if(i->getISBN() == ISBN){
            books.erase(i);
            Book::decrementTotalBooks();
            cout << "Book removed from the library. Total books now: " << Book::getTotalBooks() << endl;
            return;
        }
    }
    cout << "Book with ISBN " << ISBN << " not found in the library." << endl;
}

vector<Book> Library::searchByTitle(const string& title) const {
    vector<Book> foundBooks;
    if (title == "") return books;
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

vector<Book> Library::getAllBooks() const { 
    return books;
}