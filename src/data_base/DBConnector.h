#pragma once

#include <string>
#include <vector>
#include <pqxx/pqxx>
#include "../employee/Employee.h"

class DBConnector
{
public:

    static DBConnector& getConnector();

    bool connect();

    void disconnect();

    bool create_table();

    bool send_employee(const Employee&);

    pqxx::result select_distinct_snp_date();

    pqxx::result select_men();

    void create_index();

    void send_block(const std::vector<Employee>&);

private:

    DBConnector() = default;

    DBConnector(const DBConnector&) = delete;

    DBConnector(DBConnector&&) noexcept = delete;

    DBConnector& operator=(const DBConnector&) = delete;
    
    DBConnector& operator=(DBConnector&&) noexcept = delete;

    ~DBConnector() = default;

private:

    std::unique_ptr<pqxx::connection> connection_;
};


/*
1 1 2
1 1 3
1 2 3
1 7 3
1 3 3 
1 7 1
*/