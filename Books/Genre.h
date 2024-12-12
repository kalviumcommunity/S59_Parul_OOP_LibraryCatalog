// #include "./Book.h"

// class Historical : public virtual Book {
// private:
//     string country;

// public:
//     Historical(string t, string a, string i, bool avail, string country)
//         : Book(t, a, i, avail), country(country) {}

//     string getCountry() const {
//         return country;
//     }
// };

// class Mystery : public virtual Book, public Historical {
// private:
//     string type;

// public:
//     Mystery(string t, string a, string i, bool avail, string country, string type)
//         : Book(t, a, i, avail), Historical(t, a, i, avail, country), type(type) {}

//     string getType() const {
//         return type;
//     }
// };