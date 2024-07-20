#pragma once

#include <memory>
#include <iostream>
#include <pqxx/pqxx>

class DBConnector
{
public:

    static DBConnector& getConnector();

    bool connect();

    void disconnect();

    bool create_table();

    bool send_data(const std::string&);

    pqxx::result select_distinct_snp_date();

private:

    DBConnector() = default;

    DBConnector(const DBConnector&) = delete;

    DBConnector(DBConnector&&) noexcept = delete;

    DBConnector& operator=(const DBConnector&) = delete;
    
    DBConnector& operator=(DBConnector&&) noexcept = delete;

    ~DBConnector() = default;

private:

    class Employee;

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