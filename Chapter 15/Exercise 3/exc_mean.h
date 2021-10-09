#pragma once

#include <stdexcept>


///////////////////////////////////////////////////////////////////////////////
// BadMean
class BadMean : public std::logic_error
{
    public :
        BadMean(const std::string& message, double valueOne,
                                            double valueTwo);
        BadMean(const BadMean&);
        ~BadMean() override { delete[] message_; }

        const char* what() const noexcept override;

        BadMean& operator=(const BadMean&) = delete;

    private :
        void setMessage();

    private :
        double valueOne_;
        double valueTwo_;
        mutable char* message_;
};


///////////////////////////////////////////////////////////////////////////////
// Geometric mean exception
class BadGmean : public BadMean
{
    public :
        BadGmean(const std::string& message, double valueOne,
                                             double valueTwo)
                 : BadMean(message, valueOne, valueTwo) {}
};


///////////////////////////////////////////////////////////////////////////////
// Harmonic mean exception
class BadHmean : public BadMean
{
    public :
        BadHmean(const std::string& message, double valueOne,
                                             double valueTwo)
                 : BadMean(message, valueOne, valueTwo) {}
};