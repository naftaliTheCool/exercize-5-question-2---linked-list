/*
naftali vilner 216179200
sadna in c++
exercize 6 question 1
manage the employee's data in the college "learn in fun"
*/
#include "Employee.h"

Employee::Employee() : name(" "), id(0), seniority(0), pay(0) {}
Employee::Employee(const string name1,const int id1,const int sen,const float pay1): name(name1),id(id1),seniority(sen),pay(pay1) {}
Employee::Employee(const Employee& employee) {
	name = employee.name;
	id = employee.id;
	seniority = employee.seniority;
	pay = employee.pay;
}
void Employee::setName(const string str) { //set the name
	name = str;
}
string Employee::getName() { //return the name of the employee
	return name;
}
void Employee::setId(const int id1) { //set the id
	id = id1;
}
int Employee::getId() { //return the id
	return id;
}
void Employee::setSeniority(const int sen) { //set the seniority
	seniority = sen;
}
int Employee::getSeniority() { //return the seniority
	return seniority;
}
void Employee::setPay(const float pay1) { //set the pay per hour
	pay = pay1;
}
float Employee::getPay() { //return the pay per hour
	return pay;
}
float Employee::salaryAfterBonus() { //calculate the salary after the bonus of Tishrey
	return pay + ((seniority <= 5) * 500 + (seniority > 5) * pay * 0.25);
}
Employee& Employee::operator=(const Employee& employee) { //assinment operator
	name = employee.name;
	id = employee.id;
	seniority = employee.seniority;
	pay = employee.pay;
	return *this;
}
istream& operator>>(istream& is, Employee& employee) { //get the employee's data
	cout << "Enter employee details: ";
	is >> employee.name >>  employee.id >> employee.seniority >>  employee.pay;
	if (employee.id <= 0) throw "ERROR";
	if (employee.seniority < 0) throw "ERROR";
	if (employee.pay < 0) throw "ERROR";
	return is;
}

ostream& operator<<(ostream& os, const Employee& employee) { //print the employee's data
	os << "Employee:" << employee.name << endl << "Employee ID: " << employee.id << endl << "Years Seniority: " << employee.seniority << endl;
	return os;
}
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
