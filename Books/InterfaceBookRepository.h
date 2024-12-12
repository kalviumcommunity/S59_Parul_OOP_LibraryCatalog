#ifndef IBOOKREPOSITORY_H
#define IBOOKREPOSITORY_H

#include <vector>
#include <string>
#include "Book.h"

class IBookRepository {
public:
    virtual void addBook(Book* book) = 0;                 
    virtual void removeBook(const std::string& ISBN) = 0;  
    virtual std::vector<Book*> searchByTitle(const std::string& title) const = 0; 
    virtual std::vector<Book*> searchByAuthor(const std::string& author) const = 0; 
    virtual std::vector<Book*> getAllBooks() const = 0;    
    virtual ~IBookRepository() = default;                   
};

#endif
