#pragma once

#include "../employee/Employee.h"

class Controller
{
private:

    enum class ACTION : unsigned short { 
        CREATE_TABLE = 1,
        CREATE_EMPLOYEE,
        UNIQUE_SNP_DATE,
        FILL_DICTIONARY
    };

public:

    void execute(int, char**) const noexcept;
};
