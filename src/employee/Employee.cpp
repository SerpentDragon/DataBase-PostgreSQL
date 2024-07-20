#include "Employee.h"

Employee::Employee(const std::string& SNP, const std::string& date, const std::string& sex)
    : SNP_(SNP), date_(date), sex_(sex) {}

bool Employee::send_object() const
{
    std::string data = "'" + SNP_ + "', '" + date_ + "', '" + sex_ + "'";
    return DBConnector::getConnector().send_data(data);
}

unsigned int Employee::get_age() const
{
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;

    sscanf(date_.c_str(), "%d-%d-%d", &birth_year, &birth_month, &birth_day);

    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);

    current_year = now->tm_year + 1900;
    current_month = now->tm_mon + 1;
    current_day = now->tm_mday;

    int age = current_year - birth_year;
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) 
    {
        age--;
    }

    return age;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    return os << employee.SNP_ << " " << employee.date_ << " " 
        << employee.sex_ << employee.get_age();
}
