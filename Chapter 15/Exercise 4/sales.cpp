#include "sales.h"

///////////////////////////////////////////////////////////////////////////////
// exception class of Sales
Sales::BadIndex::BadIndex(int index, const std::string& str)
                          : std::logic_error(str), badIndex_(index) {}


///////////////////////////////////////////////////////////////////////////////
// class Sales
Sales::Sales(int year) : year_(year), gross_() {}

Sales::Sales(int year, const double* gross, int number) {
    year_ = year;
    int limit = (number < MONTHS) ? number : MONTHS;
    int i{};
    for (i = 0; i < limit; i++)
        gross_[i] = gross[i];
    for (; i < MONTHS; i++)
        gross_[i] = 0;
}

double Sales::operator[](int i) const {
    if (i < 0 || i >= MONTHS)
        throw BadIndex(i);

    return gross_[i];
}

double& Sales::operator[](int i) {
    if (i < 0 || i >= MONTHS)
        throw BadIndex(i);
    
    return gross_[i];
}


///////////////////////////////////////////////////////////////////////////////
// exception class of LabeledSales
LabeledSales::LabelBadIndex::LabelBadIndex(const std::string& label, int index,
                                           const std::string& str)
                                           : Sales::BadIndex(index, str),
                                             labelValue_(label) {}


///////////////////////////////////////////////////////////////////////////////
// class LabeledSales
LabeledSales::LabeledSales(const std::string& label, int year)
                           : Sales(year), label_(label) {}

LabeledSales::LabeledSales(const std::string& label, int year,
                           const double* gross, int number)
                           : Sales(year, gross, number),
                             label_(label) {}

double LabeledSales::operator[](int i) const {
    if (i < 0 || i >= MONTHS)
        throw LabelBadIndex(label(), i);
    
    return Sales::operator[](i);
}

double& LabeledSales::operator[](int i) {
    if (i < 0 || i >= MONTHS)
        throw LabelBadIndex(label(), i);

    return Sales::operator[](i);
}