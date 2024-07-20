#include "Controller.h"

void Controller::execute(int argc, char** argv) const noexcept
{
    unsigned int mode = std::atoi(argv[1]);

    switch(mode)
    {
        case 1: // заменить на enum
        {
            std::cout << "Creating the table...\n";

            std::cout << (DBConnector::getConnector()->create_table() ? 
                "The table was successfully created!\n" :
                "Can not create the table!\n");
            break;
        }
        case 2:
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
    }
}