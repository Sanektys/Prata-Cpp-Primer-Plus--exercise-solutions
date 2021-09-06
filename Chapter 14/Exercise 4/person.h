#include <string>


class Person
{
    public :
        Person() {}
        Person(const char* name, const char* surname) : name_(name),
                                                        surname_(surname) {}
        virtual ~Person() {}

        virtual void set();
        virtual void show() const;

    private :
        std::string name_;
        std::string surname_;
};


class Gunslinger : virtual public Person
{
    public :
        Gunslinger() {}

        void show() const override;
        void set() override { Person::set(); subSet(); };

    protected :
        double draw() const { return timeToReady_; }
        void info() const;
        void subSet();

    private :
        double timeToReady_;
        int numberOfNotchings_;

};


class PokerPlayer : public virtual Person
{
    public :
        void show() const override;
        void set() override { Person::set();}

    protected :
        int draw() const;
        void info() const;
};


class BadDude : public PokerPlayer, public Gunslinger
{
    public :
        BadDude() {}

        void show() const override;
        void set() override { Person::set(); Gunslinger::subSet(); }

    private :
        int cDraw() const { return PokerPlayer::draw(); }
        double gDraw() const { return Gunslinger::draw(); }
};