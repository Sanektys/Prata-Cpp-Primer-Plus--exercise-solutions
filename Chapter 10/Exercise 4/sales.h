#pragma once


namespace SALES
{
    class Sales
    {
        public :
            Sales() : sales_(), average_(0.0), max_(0.0), min_(0.0) {};
            Sales(const double ar[], int n);

            void setSales();
            void show() const;

        private :
            enum { QUARTERS = 4 };
            double sales_[QUARTERS];
            double average_;
            double max_;
            double min_;
    };
}
