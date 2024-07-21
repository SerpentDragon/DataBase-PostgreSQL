#pragma once

#include <chrono>
#include <iostream>
#include "DBConnector.h"

class Controller
{
private:

    enum class ACTION : unsigned short { 
        CREATE_TABLE = 1,
        CREATE_EMPLOYEE,
        UNIQUE_SNP_DATE,
        FILL_DICTIONARY,
        SELECT_MEN,
        SELECT_MEN_OPTIMIZED
    };

public:

    void execute(int, char**) const noexcept;

    void find_men() const noexcept;
};
