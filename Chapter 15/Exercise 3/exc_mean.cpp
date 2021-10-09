#include <cstring>

#include "exc_mean.h"


BadMean::BadMean(const std::string& message, double valueOne,
                                             double valueTwo)
                : std::logic_error(message), valueOne_(valueOne),
                                             valueTwo_(valueTwo),
                                             message_(nullptr) {
    setMessage();
}

BadMean::BadMean(const BadMean& source) : std::logic_error(source),
                                          valueOne_(source.valueOne_),
                                          valueTwo_(source.valueTwo_),
                                          message_(nullptr) {
    setMessage();
}

void BadMean::setMessage() {
    message_ = new (std::nothrow) char[std::strlen(std::logic_error::what())
                                       + 75];
    if (nullptr == message_)
        return;
    
    std::string value;
    value = std::to_string(valueOne_);
    std::strcpy(message_, std::logic_error::what());
    std::strncat(message_, "\nValues used: ", 15);
    std::strncat(message_, value.c_str(), 28);
    std::strncat(message_, ", ", 3);
    value = std::to_string(valueTwo_);
    std::strncat(message_, value.c_str(), 28);
    std::strncat(message_, "\n\0", 2);
}

const char* BadMean::what() const noexcept {
    return const_cast<const char*>(message_);
}