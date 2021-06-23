#include <iostream>


class Plorg
{
    public :
        Plorg(const char name[] = "Plorga", short contIndex = 50);

        void setContentmentIndex(short index) { contentmentIndex_ = index; }
        void show() const {
            std::cout << "Name: " << name_ << std::endl;
            std::cout << "contentmentIndex (CI): "
                      << contentmentIndex_ << std::endl;
        }

    private :
        char name_[19];
        short contentmentIndex_;
};
