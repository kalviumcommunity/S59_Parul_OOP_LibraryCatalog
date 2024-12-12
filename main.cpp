#include <iostream>
#include "./Library/Library.h"
#include "./Books/BookRepository.h"

int main() {
    IBookRepository* repo = new BookRepository();

    Library library(repo);

    Book* book1 = new Book("C++ Programming", "John Doe", "1234", true);
    Book* book2 = new Book("Advanced C++", "Jane Doe", "5678", true);
    Book* book3 = new Book("C++ for Beginners", "John Smith", "9876", false);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    auto booksByTitle = library.searchByTitle("C++");
    for (auto book : booksByTitle) {
        book->displayBookInfo();
    }

    library.removeBook("1234");

    auto allBooks = library.getAllBooks();
    for (auto book : allBooks) {
        book->displayBookInfo();
    }

    delete repo;

    return 0;
}
