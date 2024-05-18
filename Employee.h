#pragma once

#include <ctime>
#include <string>
#include "DBConnector.h"

class Employee
{
public:

    Employee(const std::string&, const std::string&, const std::string&);

    bool send_object() const;

    unsigned int get_age() const;

private:

    std::string SNP_;
    std::string date_;
    std::string sex_;
};
