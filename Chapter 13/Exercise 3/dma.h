#pragma once

#include <iostream>


class AbstractDma
{
    public :
        AbstractDma(const char* label = "null", int rating = 0);
        AbstractDma(const AbstractDma&);
        virtual ~AbstractDma();

        AbstractDma& operator=(const AbstractDma&);

        virtual void view() const = 0;

    private :
        char* label_;
        int rating_;
};

class BaseDma : public AbstractDma
{
    public :
        BaseDma(const char* label = "null", int rating = 0);
        //BaseDma(const BaseDma&);
        //~BaseDma() override;
        //BaseDma& operator=(const BaseDma&);

        void view() const override;

        friend std::ostream& operator<<(std::ostream& os,
                                        const BaseDma& copy);

    private :

};

class LackDma : public AbstractDma
{
    public :
        LackDma(const char* color = "blank", const char* label = "null",
                int rating = 0);
        //LackDma(const char* color, const AbstractDma& copy);

        void view() const override;

        friend std::ostream& operator<<(std::ostream& os,
                                        const LackDma&);

    private :
        enum { COLOR_LENTH = 40 };
        char color_[COLOR_LENTH];
};

class HasDma : public AbstractDma
{
    public :
        HasDma(const char* style = "none", const char* label = "null",
               int rating = 0);
        //HasDma(const char* style, const AbstractDma&);
        HasDma(const HasDma&);
        ~HasDma() override;

        void view() const override;

        HasDma& operator=(const HasDma&);

        friend std::ostream& operator<<(std::ostream& os,
                                        const HasDma&);

    private :
        char* style_;
};
