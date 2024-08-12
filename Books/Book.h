#include <bits/stdc++.h>


using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;

public:
    Book(string t, string a, string i, bool avail);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isAvailable() const;

    Book& setAvailability(bool avail);
};