#pragma once

#include <memory>
#include <iostream>
#include <pqxx/pqxx>

class DBConnector
{
public:

    static DBConnector* getConnector();

    bool connect();

    void disconnect();

    bool create_table();

    bool send_data(const std::string&);

private:

    DBConnector() = default;

    DBConnector(const DBConnector&) = delete;

private:

    static DBConnector* connector_;

    std::unique_ptr<pqxx::connection> connection_;
};
