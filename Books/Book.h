#include <bits/stdc++.h>


using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;
    static int totalBooks;

public:
    Book(string t, string a, string i, bool avail);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isAvailable() const;
    static int getTotalBooks();
    static void decrementTotalBooks();

    Book& setAvailability(bool avail);
};