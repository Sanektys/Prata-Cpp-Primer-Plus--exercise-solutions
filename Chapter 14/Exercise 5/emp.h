#include <iostream>
#include <string>


class AbstrEmp
{
    public :
        AbstrEmp();
        AbstrEmp(const std::string& fn, const std::string& ln,
                 const std::string& j);
        virtual ~AbstrEmp() = 0;
        
        virtual void showAll() const;
        virtual void setAll();

        friend std::ostream& operator<<(std::ostream& os, const AbstrEmp& e);

    private :
        std::string firstName_;
        std::string lastName_;
        std::string job_;
};


class Employee : public AbstrEmp
{
    public :
        Employee();
        Employee(const std::string& fn, const std::string&,
                 const std::string& j);
        ~Employee() override {}

        virtual void showAll() const { AbstrEmp::showAll(); }
        virtual void setAll() { AbstrEmp::setAll(); }
};


class Manager : virtual public AbstrEmp
{
    public :
        Manager();
        Manager(const std::string& fn, const std::string& ln,
                const std::string& j, int ico = 0);
        Manager(const AbstrEmp& e, int ico);
        Manager(const Manager& m);
        ~Manager() override {}

        virtual void showAll() const;
        virtual void setAll();

    protected :
        int inChargeOf() const { return inChargeOf_; }
        int& inChargeOf() { return inChargeOf_; }

    private :
        int inChargeOf_;
};


class Fink : virtual public AbstrEmp
{
    public :
        Fink();
        Fink(const std::string& fn, const std::string& ln,
             const std::string& j, const std::string& rpo);
        Fink(const AbstrEmp& e, const std::string& rpo);
        Fink(const Fink& e);
        ~Fink() override {}

        virtual void showAll() const;
        virtual void setAll();

    protected :
        const std::string reportsTo() const { return reportsTo_; }
        std::string& reportsTo() { return reportsTo_; }

    private :
        std::string reportsTo_;
};


class Highfink : public Manager, public Fink
{
    public :
        Highfink();
        Highfink(const std::string& fn, const std::string& ln,
                 const std::string& j, const std::string& rpo,
                 int  ico);
        Highfink(const AbstrEmp& e, const std::string& rpo, int ico);
        Highfink(const Fink& f, int ico);
        Highfink(const Manager& m, const std::string& rpo);
        Highfink(const Highfink& h);
        ~Highfink() override {}

        virtual void showAll() const;
        virtual void setAll();
};