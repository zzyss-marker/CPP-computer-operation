#include <iostream>
#include <string>
using namespace std;
class Worker
{
    int empId;
    char name[32];
    char gender;
    double baseSalary;
    double bonus;
    double totalSalary;
public:
	Worker (int I,string na,char sex)
{
	ID=I;
	name=na;
	gender=sex;
}
    	void setSalary(double base, double b) 
{
        baseSalary = base;
        bonus = b;
        totalSalary = baseSalary + bonus;
}
	void display()
{
    	cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << totalSalary << endl;
}
};

int main() {

    Worker employee(101, "John Doe", 'M');
    employee.display();

    employee.setSalary(55000.0, 12000.0);
    employee.display();

    return 0;
}
