#include "DBConnector.h"

DBConnector* DBConnector::connector_ = nullptr;

DBConnector* DBConnector::getConnector()
{
    if (connector_ == nullptr) connector_ = new DBConnector();

    return connector_;
}

bool DBConnector::connect()
{
    try
    {
        connection_ = std::make_unique<pqxx::connection>(
            "dbname=task \
            user=dmitry \
            password=1234 \
            hostaddr=127.0.0.1 \
            port=5432");
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return false;
    }

    return connection_->is_open();
}

void DBConnector::disconnect()
{
    if (connection_) connection_->close();
}

bool DBConnector::create_table()
{
    if (!connection_->is_open()) return false;

    pqxx::transaction query(*connection_);

    try
    {
        query.exec(
            "CREATE TABLE Employee ( \
            id SERIAL PRIMARY KEY, \
            SNP VARCHAR(50) NOT NULL, \
            date DATE NOT NULL, \
            sex varchar(6) NOT NULL \
            )");

        query.commit();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
    return true;
}

bool DBConnector::send_data(const std::string& data)
{
    if (!connection_->is_open()) return false;
    
    pqxx::transaction query(*connection_);

    try
    {
        query.exec("INSERT INTO employee (snp, date, sex) VALUES (" + data + ");");
        query.commit();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return false;
    }

    return true;
}
