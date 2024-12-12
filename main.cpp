#include <iostream>
#include <vector>
#include "./Books/Book.cpp" 
#include "./Library/Library.cpp" 
using namespace std;

int main()
{
    Library library;

    Book* book1 = new Historical("IT ENDS WITH US FOREVER", "Colleen Hoover", "978-1-5011-1036-8", false, "USA");
    Book* book2 = new Historical("You Can Sell", "Shiv Khera", "9788129116000", true, "India");
    Book* book3 = new Mystery("Atomic Habits", "James Clear", "9780735211292", true, "USA", "Self-Improvement");
    Historical* defBook1 = new Historical(); 
    Book* book4 = new Historical("The Book Thief", "Markus Zusak", "978-0375842207", true, "Australia");
    Book* book5 = new Mystery("The Girl with the Dragon Tattoo", "Stieg Larsson", "978-0307949486", true, "Sweden", "Crime Fiction");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);

    cout << "\nWelcome to the Library Catalog!" << endl;
    cout << "Default Historical Book Country: " << defBook1->getCountry() << endl;

    while (true)
    {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Find a book by Title" << endl;
        cout << "2. Find a book by Author" << endl;
        cout << "3. Add a new book" << endl;
        cout << "4. Remove a book by ISBN" << endl;
        cout << "5. Check all books in the library" << endl;
        cout << "6. Check total count of books in the library" << endl;
        cout << "7. Display details of Historical or Mystery books" << endl;
        cout << "8. Exit" << endl;
        cout << "\nPlease enter your choice (1-8): ";
        
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string title;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);

            vector<Book*> results = library.searchByTitle(title);
            if (results.empty())
            {
                cout << "No books found with the title \"" << title << "\"." << endl;
            }
            else
            {
                for (const auto& book : results)
                {
                    cout << "Found the book: " << book->getTitle() << " by " << book->getAuthor() << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string author;
            cout << "Enter the author's name: ";
            cin.ignore();
            getline(cin, author);

            vector<Book*> results = library.searchByAuthor(author);
            if (results.empty())
            {
                cout << "No books found by the author \"" << author << "\"." << endl;
            }
            else
            {
                for (const auto& book : results)
                {
                    cout << "Found book: " << book->getTitle() << " by " << book->getAuthor() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            string title, author, isbn, country;
            bool available;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the author's name: ";
            getline(cin, author);
            cout << "Enter the ISBN: ";
            getline(cin, isbn);
            cout << "Enter the country: ";
            getline(cin, country);
            cout << "Is the book available? (1 for Yes, 0 for No): ";
            cin >> available;

            Book* newBook = new Historical(title, author, isbn, available, country);
            library.addBook(newBook);
            cout << "Book added successfully!" << endl;
        }
        else if (choice == 4)
        {
            string isbn;
            cout << "Enter the ISBN of the book to remove: ";
            cin.ignore();
            getline(cin, isbn);

            library.removeBook(isbn);
        }
        else if (choice == 5)
        {
            cout << "Listing all books in the library:\n";
            vector<Book*> allBooks = library.getAllBooks();
            for (const auto& book : allBooks)
            {
                book->displayBookInfo();
            }
        }
        else if (choice == 6)
        {
            cout << "Total books in the library: " << Book::getTotalBooks() << endl;
        }
        else if (choice == 7)
        {
            cout << "Displaying details of Historical books:\n";
            book4->displayBookInfo();

            cout << "\nDisplaying details of Mystery books:\n";
            book5->displayBookInfo();
        }
        else if (choice == 8)
        {
            cout << "Exiting the Library Catalog. Goodbye!\n" << endl;
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
    delete book4;
    delete book5;
    delete defBook1;

    return 0;
}