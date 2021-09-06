#include <string>
#include <valarray>

#include "pair.hpp"


class Wine
{
    public :
        Wine();
        Wine(const char* label, size_t yearsAmount, const int years[],
             const int bottles[]);
        Wine(const char* label, int yearsAmount);

        void getBottles();
        void show() const;
        std::string& label() { return label_; }
        int sum() const { return value_.second().sum(); }

    private :
        using ArrayInt = std::valarray<int>;
        using PairArray = Pair<ArrayInt, ArrayInt>;

        std::string label_;
        PairArray value_;
};
