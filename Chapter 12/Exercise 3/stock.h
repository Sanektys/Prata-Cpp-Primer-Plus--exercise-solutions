#pragma once

#include <iostream>


class Stock
{
    public :
        Stock();
        Stock(const std::string& company, long number = 0, double price = 0.0);
        ~Stock();

        void buy(long number, double price);
        void sell(long number, double price);
        void update(double price);
        void show() const;
        const Stock& topValue(const Stock&) const;

        friend std::ostream& operator<<(std::ostream&, const Stock&);

    private :
        char* company_;
        int shares_;
        double shareValue_;
        double totalValue_;

    private :
        void setTotal() { totalValue_ = shares_ * shareValue_; }
        
        Stock(const Stock&) = delete;
        const Stock& operator=(const Stock&) = delete;
};
