#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "../Books/InterfaceBookRepository.h"

class Library {
private:
    IBookRepository* bookRepo;  

public:
    Library(IBookRepository* repo) : bookRepo(repo) {}

    void addBook(Book* book) {
        bookRepo->addBook(book);
    }

    void removeBook(const std::string& ISBN) {
        bookRepo->removeBook(ISBN);
    }

    std::vector<Book*> searchByTitle(const std::string& title) {
        return bookRepo->searchByTitle(title);
    }

    std::vector<Book*> searchByAuthor(const std::string& author) {
        return bookRepo->searchByAuthor(author);
    }

    std::vector<Book*> getAllBooks() {
        return bookRepo->getAllBooks();
    }

    ~Library() {
        
    }
};

#endif
