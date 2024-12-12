#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include <vector>
#include <algorithm>
#include "InterfaceBookRepository.h"

class BookRepository : public IBookRepository {
private:
    std::vector<Book*> books;  

public:
    void addBook(Book* book) override {
        books.push_back(book);
        cout << "Book added: " << book->getTitle() << endl;
    }

    void removeBook(const std::string& ISBN) override {
        auto it = std::find_if(books.begin(), books.end(), [&](Book* book) {
            return book->getISBN() == ISBN;
        });
        if (it != books.end()) {
            delete *it;  
            books.erase(it);  
            cout << "Book removed: " << ISBN << endl;
        } else {
            cout << "Book with ISBN " << ISBN << " not found." << endl;
        }
    }

    std::vector<Book*> searchByTitle(const std::string& title) const override {
        std::vector<Book*> foundBooks;
        for (auto book : books) {
            if (book->getTitle().find(title) != string::npos) {
                foundBooks.push_back(book);
            }
        }
        return foundBooks;
    }

    std::vector<Book*> searchByAuthor(const std::string& author) const override {
        std::vector<Book*> foundBooks;
        for (auto book : books) {
            if (book->getAuthor().find(author) != string::npos) {
                foundBooks.push_back(book);
            }
        }
        return foundBooks;
    }

    std::vector<Book*> getAllBooks() const override {
        return books;
    }

    ~BookRepository() {
        for (auto book : books) {
            delete book;  
        }
    }
};

#endif
