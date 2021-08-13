#include <iostream>


class Port
{
    public :
        Port(const char* brand = "none", const char* style = "none",
             int bottles = 0);
        Port(const Port&);
        virtual ~Port() { delete[] brand_; }

        int bottleCount() const { return bottles_; }
        virtual void show() const;

        Port& operator=(const Port&);
        Port& operator+=(int bottles);
        Port& operator-=(int bottles);

        friend std::ostream& operator<<(std::ostream&, const Port&);

    private :
        char* brand_;
        char style_[20];
        int bottles_;
};
