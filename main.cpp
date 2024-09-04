#include <bits/stdc++.h>
#include "./Books/Book.cpp"
#include "./Library/Library.cpp"

using namespace std;

int main()
{
    Library library;

    Book* book1 = new Book("IT ENDS WITH US FOREVER", "Colleen Hoover", "978-1-5011-1036-8", false);
    Book* book2 = new Book("You Can Sell", "Shiv Khera", "9788129116000", true);
    Book* book3 = new Book("Atomic Habits", "James Clear", "9780735211292", true);  

    library.addBook(*book1);
    library.addBook(*book2);
    library.addBook(*book3);

    cout << "\nWelcome to the Library Catalog!" << endl;

    while (true)
    {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Find a book by Title" << endl;
        cout << "2. Find a book by Author" << endl;
        cout << "3. Add a new book" << endl;
        cout << "4. Remove a book by ISBN" << endl;
        cout << "5. Check all books in the library" << endl;
        cout << "6. Check total count of books in the library" << endl; 
        cout << "7. Exit" << endl;
        cout << "\nPlease enter your choice (1-6): ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string title;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);

            vector<Book> results = library.searchByTitle(title);
            if (results.empty())
            {
                cout << "No books found with the title \"" << title << "\"." << endl;
            }
            else
            {
                for (const auto &book : results)
                {
                    cout << "Found book: " << book.getTitle() << " by " << book.getAuthor() << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string author;
            cout << "Enter the author's name: ";
            cin.ignore();
            getline(cin, author);

            vector<Book> results = library.searchByAuthor(author);
            if (results.empty())
            {
                cout << "No books found by the author \"" << author << "\"." << endl;
            }
            else
            {
                for (const auto &book : results)
                {
                    cout << "Found book: " << book.getTitle() << " by " << book.getAuthor() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            string title, author, isbn;
            bool available;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the author's name: ";
            getline(cin, author);
            cout << "Enter the ISBN: ";
            getline(cin, isbn);
            cout << "Is the book available? (1 for Yes, 0 for No): ";
            cin >> available;

            Book* newBook = new Book(title, author, isbn, available);
            library.addBook(*newBook);  
            cout << "Book added successfully!" << endl;
        }
        else if (choice == 4)
        {
            string isbn;
            cout << "Enter the ISBN of the book to remove: ";
            cin.ignore();
            getline(cin, isbn);

            library.removeBook(isbn);
            cout << "Book removed successfully, if it existed." << endl;
        } 
        else if (choice == 5) 
        {
            cout << "Listing all books in the library:\n";
            vector<Book> allBooks = library.searchByTitle("");
            for (const auto& book : allBooks) {
                cout << "Title: " << book.getTitle()
                     << ", Author: " << book.getAuthor()
                     << ", ISBN: " << book.getISBN()
                     << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
            }
        } 
        else if (choice == 6)
        {
            cout << "Total books in the library: " << Book::getTotalBooks() << endl;
        }
        else if (choice == 7)
        {
            cout << "Exiting the Library Catalog. Goodbye!\n"
                 << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    delete book1;
    delete book2;
    delete book3;

    return 0;
}