#include "Library.h"

void Library::addBook(const Book& book) {
    books.push_back(book);
    cout << "Book added to the library. Total books in the library now: " << Book::getTotalBooks() << endl;
}

void Library::removeBook(const string& ISBN) {
    for (auto i = books.begin(); i != books.end(); ++i) {
        if (i->getISBN() == ISBN) {
            books.erase(i);
            Book::decrementTotalBook();
            cout << "Book removed from the library. Total books now: " << Book::getTotalBooks() << endl;
            return;
        }
    }
    cout << "Book with ISBN " << ISBN << " not found in the library." << endl;
}

vector<Book> Library::searchByTitle(const string& title) const {
    vector<Book> foundBooks;
    string searchTitle = title;
    transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

    for (const auto& book : books) {
        string bookTitle = book.getTitle();
        transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);

        if (bookTitle.find(searchTitle) != string::npos) {
            foundBooks.push_back(book);
        }
    }

    if (foundBooks.empty()) {
        cout << "No books found with title: " << title << endl;
    }

    return foundBooks;
}

vector<Book> Library::searchByAuthor(const string& author) const {
    vector<Book> foundBooks;
    string searchAuthor = author;
    transform(searchAuthor.begin(), searchAuthor.end(), searchAuthor.begin(), ::tolower);

    for (const auto& book : books) {
        string bookAuthor = book.getAuthor();
        transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);

        if (bookAuthor.find(searchAuthor) != string::npos) {
            foundBooks.push_back(book);
        }
    }

    if (foundBooks.empty()) {
        cout << "No books found by author: " << author << endl;
    }

    return foundBooks;
}

vector<Book> Library::getAllBooks() const {
    if (books.empty()) {
        cout << "The library has no books currently." << endl;
    }
    return books;
}