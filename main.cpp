#include <iostream>
#include "Controller.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./main <mode> [params]" << std::endl;
        return 1;
    }

    if (!DBConnector::getConnector()->connect())
    {
        std::cerr << "Can not connect to the data base!\n";
        return 1;
    }

    Controller controller;
    controller.execute(argc, argv);

    DBConnector::getConnector()->disconnect();

    return 0;
}
