#include "Controller.h"

void Controller::execute(int argc, char** argv) const noexcept
{
    unsigned int mode = std::atoi(argv[1]);

    switch(static_cast<ACTION>(mode))
    {
        case ACTION::CREATE_TABLE:
        {
            std::cout << "Creating the table...\n";

            std::cout << (DBConnector::getConnector().create_table() ? 
                "The table was successfully created!\n" :
                "Can not create the table!\n");
            break;
        }
        case ACTION::CREATE_EMPLOYEE:
        {
            if (argc != 5)
            {
                std::cerr << "Usage: ./main <mode> <Surname Name Patronymic> <Birthday> <Sex>\n";
                return;
            }

            std::cout << "Secnding Employee object to the data base...\n";
            
            Employee employee(argv[2], argv[3], argv[4]);

            std::cout << (employee.send_object() ? 
                "The object was successfully send to the data base!\n" :
                "Error sending object to the data base!\n");

            break;
        }
        case ACTION::UNIQUE_SNP_DATE:
        {
            auto result = DBConnector::getConnector().select_distinct_snp_date();

            for(const auto& row : result)
            {
                Employee employee(row[0].c_str(), row[1].c_str(), row[2].c_str());

                std::cout << employee << std::endl;
            }

            break;
        }
        case ACTION::FILL_DICTIONARY:
        {
            break;
        }
        default:
        {
            std::cout << "Wrong argument!\n";
            break;
        }
    }
}