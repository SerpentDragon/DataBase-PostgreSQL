#include "Employee.h"

Employee::Employee(const std::string& SNP, const std::string& date, const std::string& sex)
    : SNP_(SNP), date_(date), sex_(sex) {}

Employee::Employee()
{
    SNP_ = generate_random_string(5) + " " + 
        generate_random_string(7) + " " + generate_random_string(7);

    date_ = generate_random_date();

    sex_ = generate_random_sex();
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

std::string Employee::to_string() const
{
    return "('" + SNP_ + "', '" + date_ + "', '" + sex_ + "')";
}

void Employee::generate_man()
{
    SNP_[0] = 'F';
    sex_ = "Male";
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    return os << employee.SNP_ << " " << employee.date_ << " " 
        << employee.sex_ << " " << employee.get_age();
}

std::string Employee::generate_random_string(std::size_t length)
{
    std::string random_string;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(65, 90);

    for(std::size_t i = 0; i < length; i++)
    {
        random_string += dist(rng);
    }

    return random_string;
}

std::string Employee::generate_random_date()
{
    std::string random_date;

    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<> year_dist(1950, 2024);
    static std::uniform_int_distribution<> month_dist(1, 12);
    static std::uniform_int_distribution<> day_dist(1, 28);

    int year = year_dist(rng);
    int month = month_dist(rng);
    int day = day_dist(rng);

    char date[11];
    snprintf(date, sizeof(date), "%04d-%02d-%02d", year, month, day);
    return date;
}

std::string Employee::generate_random_sex()
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 1);

    return dist(rng) % 2 ? "Male" : "Female";
}
