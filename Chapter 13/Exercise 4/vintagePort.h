#include <iostream>

#include "port.h"


class VintagePort : public Port
{
    public:
        VintagePort();
        VintagePort(const char* brand, int bottles, const char* nick, int year);
        VintagePort(const VintagePort&);
        ~VintagePort() override { delete[] nickname_; }

        void show() const override;

        VintagePort& operator=(const VintagePort&);

        friend std::ostream& operator<<(std::ostream&, const VintagePort&);

    private :
        char* nickname_;
        int year_;
};
