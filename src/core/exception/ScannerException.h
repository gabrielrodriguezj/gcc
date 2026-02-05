#ifndef GCC_SCANNEREXCEPTION_H
#define GCC_SCANNEREXCEPTION_H


#include <exception>
#include <string>

class ScannerException: public std::exception{

private:
    std::string message;

public:
    ScannerException(const std::string &);
    const char* what() const throw();
};



#endif //GCC_SCANNEREXCEPTION_H