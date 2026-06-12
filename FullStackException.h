#pragma once
#include <iostream>
#include <string>
#include <exception>

class FullStackException : public std::exception {
protected:
    std::string message;
public:
    FullStackException(const std::string& message = "Stos jest pelny. Nie mozna dodac nowego elementu.") : message(message) {}

    virtual const char* what() const noexcept {
        return this->message.c_str();
    }
};