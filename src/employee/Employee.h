#pragma once

#include <ctime>
#include <random>
#include <string>
#include <iostream>

class Employee
{
public:

    Employee();

    explicit Employee(const std::string&, const std::string&, const std::string&);

    unsigned int get_age() const;

    std::string to_string() const;

    void generate_man();

    friend std::ostream& operator<<(std::ostream&, const Employee&);

private:

    std::string generate_random_string(std::size_t);

    std::string generate_random_date();

    std::string generate_random_sex();

private:

    std::string SNP_;
    std::string date_;
    std::string sex_;
};
