#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cctype>


struct Review
{
    std::string title;
    double price;
    int rating;
};


bool alphabetOrder(const std::shared_ptr<Review>& r1,
                   const std::shared_ptr<Review>& r2);
bool betterThan(const std::shared_ptr<Review>& r1,
                const std::shared_ptr<Review>& r2);
bool worseThan(const std::shared_ptr<Review>& r1,
               const std::shared_ptr<Review>& r2);
bool higherPrice(const std::shared_ptr<Review>& r1,
                 const std::shared_ptr<Review>& r2);
bool lowerPrice(const std::shared_ptr<Review>& r1,
                const std::shared_ptr<Review>& r2);

bool fillReview(Review& rr);
inline void showReview(const std::shared_ptr<Review>& rr);

char chooseDisplayType();

void fixCin();


int main() {
    std::vector<std::shared_ptr<Review>> books;
    Review temp;
    while (fillReview(temp))
        books.push_back(std::shared_ptr<Review>(new Review(temp)));

    if (books.size() > 0) {
        char choose{};
        while ('q' != (choose = chooseDisplayType())) {
            std::cout << "You entered the following "
                      << books.size() << " ratings:\n";
            switch (choose) {
                case 'a' :
                    std::cout << "Price\tRating\tBook\n";
                    break;
                case 'b' :
                    std::cout << "Price\tRating\t/\\Book\n";
                    std::sort(books.begin(), books.end(), alphabetOrder);
                    break;
                case 'c' :
                    std::cout << "Price\t\\/Rating\tBook\n";
                    std::sort(books.begin(), books.end(), worseThan);
                    break;
                case 'd' :
                    std::cout << "\\/Price\tRating\tBook\n";
                    std::sort(books.begin(), books.end(), lowerPrice);
                    break;
                case 'e' :
                    std::cout << "/\\Price\tRating\tBook\n";
                    std::sort(books.begin(), books.end(), higherPrice);
                    break;
            }
            std::for_each(books.begin(), books.end(), showReview);
        }
    }
    else
        std::cout << "No entries. ";

    std::cout << "Bye.\n";


    return 0;
}


bool alphabetOrder(const std::shared_ptr<Review>& r1,
                   const std::shared_ptr<Review>& r2) {
    if (r1->title <= r2->title)
        return true;
    else
        return false;
}

bool betterThan(const std::shared_ptr<Review>& r1,
                const std::shared_ptr<Review>& r2) {
    if (r1->rating >= r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review>& r1,
               const std::shared_ptr<Review>& r2) {
    if (r1->rating <= r2->rating)
        return true;
    else
        return false;
}

bool higherPrice(const std::shared_ptr<Review>& r1,
                 const std::shared_ptr<Review>& r2) {
    if (r1->price >= r2->price)
        return true;
    else
        return false;
}

bool lowerPrice(const std::shared_ptr<Review>& r1,
                const std::shared_ptr<Review>& r2) {
    if (r1->price <= r2->price)
        return true;
    else
        return false;
}


bool fillReview(Review& rr) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit" || !std::cin)
        return false;

    while (true) {
        std::cout << "Enter book rating: ";
        std::cin >> rr.rating;
        if (std::cin && rr.rating <= 0)
            std::cin.setstate(std::ios_base::failbit);
        if (!std::cin) {
            std::cout << "Incorrect entered book rating, try again\n";
            fixCin();
        }
        else
            break;
    }
    while (std::cin.get() != '\n')
        continue;

    while (true) {
        std::cout << "Enter book price: ";
        std::cin >> rr.price;
        if (std::cin && rr.price <= 0.0)
            std::cin.setstate(std::ios_base::failbit);
        if (!std::cin) {
            std::cout << "Incorrect entered book price, try again\n";
            fixCin();
        }
        else
            break;
    }
    while (std::cin.get() != '\n')
        continue;

    return true;
}

inline void showReview(const std::shared_ptr<Review>& rr) {
    std::cout << rr->price << '\t' << rr->rating << '\t' << rr->title << '\n';
}


char chooseDisplayType() {
    std::cout << "\nSelect the type of appearance of the book list\n";
    std::cout << "\"a\" - in original order\t\t\"b\" - in alphabet order\n"
              << "\"c\" - in rating increase order\t"
                 "\"d\" - in price increase order\n"
              << "\"e\" - in price decrease order\t"
                 "\"q\" - terminate the program\n";
    char choose{};
    fixCin();
    do {
        std::cout << " -> ";
        std::cin >> choose;
        if (!std::cin.eof()) {
            choose = std::tolower(choose);
            if (choose != 'a' && choose != 'b' && choose != 'c' &&
                choose != 'd' && choose != 'e' && choose != 'q') {
                std::cout << "Incorrect selected point, try again:\n";
                std::cin.clear(std::cin.failbit);
            }
        }
        if (!std::cin.good()) {
            if (std::cin.eof())
                return 'q';
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }
        else {
            while (std::cin.get() != '\n');
            break;
        }
    } while (true);

    return choose;
}


void fixCin() {
    while (!std::cin.good()) {
        if (std::cin.eof()) {
            std::cin.clear();
            std::cin.unget();
        }
        else {
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    }
}