#pragma once
#include <iostream>

class EmptyStackException : public std::exception {
protected:
    std::string message;
public:
    EmptyStackException(const std::string& message = "Stos jest pusty") : message(message) {}

    virtual const char* what() const noexcept {
        return this->message.c_str();
    }
};
