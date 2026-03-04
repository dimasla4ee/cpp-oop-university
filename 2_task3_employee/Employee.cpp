#include <iostream>

class Employee {
   protected:
    int id;
    std::string name;
    std::string hireDate;

   public:
    Employee(int id, std::string name, std::string hireDate)
        : id(id), name(name), hireDate(hireDate) {};

    int getId() const { return id; }
    void setId(int value) { id = value; }

    std::string getName() const { return name; }
    void setName(std::string value) { name = value; }

    std::string getHireDate() const { return hireDate; }
    void setHireDate(std::string value) { hireDate = value; }

    virtual void displayInfo() {
        std::cout << id << ". " << name << "since " << hireDate << std::endl;
    }
};

class SalariedEmployee : public Employee {
   private:
    double monthlySalary;

   public:
    SalariedEmployee(int id, std::string name, std::string hireDate,
                     double monthlySalary)
        : Employee(id, name, hireDate), monthlySalary(monthlySalary) {};

    double calculateAnnualSalary() {
        const int MONTHS_TOTAL = 12;
        return monthlySalary * MONTHS_TOTAL;
    }

    virtual void displayInfo() override {
        std::cout << id << ". " << name << " with salary " << monthlySalary
                  << "RUB since " << hireDate << std::endl;
    }
};

class HourlyEmployee : public Employee {
   private:
    double hourlyRate;
    int hoursWorked;

   public:
    HourlyEmployee(int id, std::string name, std::string hireDate,
                   double hourlyRate, int hoursWorked)
        : Employee(id, name, hireDate),
          hourlyRate(hourlyRate),
          hoursWorked(hoursWorked) {};

    double calculateWeeklyPay() { return hourlyRate * hoursWorked; }

    void displayInfo() override {
        std::cout << id << ". " << name << " worked " << hoursWorked
                  << " hours with hourly rate " << hourlyRate << "RUB since "
                  << hireDate << std::endl;
    }
};
