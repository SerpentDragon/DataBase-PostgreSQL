#include "DBConnector.h"

DBConnector& DBConnector::getConnector()
{
    static DBConnector connector;
    return connector;
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

pqxx::result DBConnector::select_distinct_snp_date()
{
    pqxx::work request(*connection_);

    pqxx::result result = request.exec(
        "WITH distinct_table AS( \
            SELECT SNP, date \
            FROM Employee \
            GROUP BY SNP, date \
            HAVING COUNT(*) = 1 \
        ) \
        SELECT Employee.SNP, Employee.date, Employee.sex \
        FROM Employee JOIN distinct_table on \
            Employee.SNP = distinct_table.SNP AND \
            Employee.date = distinct_table.date \
        "
    );

    request.commit();

    return result;
}
