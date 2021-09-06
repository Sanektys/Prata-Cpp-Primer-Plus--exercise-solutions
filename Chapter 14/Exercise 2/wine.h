#include <string>
#include <valarray>

#include "pair.hpp"


using PairArray = Pair<std::valarray<int>, std::valarray<int>>;

class Wine : std::string, PairArray
{
    public :
        Wine();
        Wine(const char* label, size_t yearsAmount, const int years[],
             const int bottles[]);
        Wine(const char* label, int yearsAmount);

        void getBottles();
        void show() const;
        std::string& label() { return *(std::string*)this; }
        int sum() const { return ((PairArray*)this)->second().sum(); }

    private :
        using ArrayInt = std::valarray<int>;
};
