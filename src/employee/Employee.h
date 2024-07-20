#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include "../data_base/DBConnector.h"

class Employee
{
public:

    Employee(const std::string&, const std::string&, const std::string&);

    bool send_object() const;

    unsigned int get_age() const;

    friend std::ostream& operator<<(std::ostream&, const Employee&);

private:

    std::string SNP_;
    std::string date_;
    std::string sex_;
};
