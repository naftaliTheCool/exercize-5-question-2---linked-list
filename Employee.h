/*
naftali vilner 216179200
sadna in c++
exercize 6 question 1
manage the employee's data in the college "learn in fun"
*/
#pragma once
#include <iostream>
#include <string>

using namespace std;
class Employee {
private:
	string name;
	int id;
	int seniority;
	float pay;
protected:
	string getName();
	void setName(const string);
	void setId(const int);
	int getId();
	void setSeniority(const int);
	int getSeniority();
	void setPay(const float);
	float getPay();
public:
	friend ostream& operator<<(ostream&, const Employee&);
	friend istream& operator>>(istream&, Employee&);
	float salaryAfterBonus();
	Employee();
	Employee(const string,const int,const int,const float);
	Employee(const Employee&);
	Employee& operator=(const Employee&);
};
/*
Enter employee details: moshe  1234 3 36000
Enter employee details: moshe  1234 3 36000
Enter employee details: miriam  4321 8 48000
Enter employee details: aharon  5678 4 160 35
Enter employee details: jim 5666 6 100 10
Enter employee details: josef 8888 19 900 450
Employee:moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000

After Bonus: 3500
Employee:moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000

After Bonus: 3500
Employee:miriam
Employee ID: 4321
Years Seniority: 8
Salary per Month: 4000

After Bonus: 5000
Employee:aharon
Employee ID: 5678
Years Seniority: 4
Hours: 160
Salary per Month: 5600

After Bonus: 6100
Employee:jim
Employee ID: 5666
Years Seniority: 6
Hours: 100
Salary per Month: 1000

After Bonus: 1250
Employee:josef
Employee ID: 8888
Years Seniority: 19
Hours: 900
Salary per Month: 405000

After Bonus: 506250
*/
