#pragma once

#include <iostream>
#include <stdexcept>


class BadHmean : public std::logic_error
{
    public :
        BadHmean(const std::string& message) : std::logic_error(message) {}
};


class BadGmean : public std::logic_error
{
    public :
        BadGmean(const std::string& message) : std::logic_error(message) {}
};