/*
naftali vilner 216179200
sadna in c++
exercize 6 question 1
manage the employee's data in the college "learn in fun"
*/
#include "PartTime.h"

PartTime::PartTime(): hoursOfWork(0),payPerHour(0) {}
PartTime::PartTime(const int hOW, const float pPH, const string name1, const int id1, const int sen, const float pay1) {
	Employee temp(name1, id1, sen, 0);
	(Employee&)(*this) = temp;
	hoursOfWork = hOW;
	payPerHour = pPH;
	this->salary();
}
PartTime::PartTime(const PartTime& employee) {
	(Employee&)(*this) = employee;
	hoursOfWork = employee.hoursOfWork;
	payPerHour = employee.payPerHour;
}
void PartTime::setHoursOfWork(const int hOW) { //set the amount of hours of work
	hoursOfWork = hOW;
}
int PartTime::getHoursOfWork() { //return the amount of hours of work
	return hoursOfWork;
}
void PartTime::setPayPerHour(const float pPH) { //set the pay per hour
	payPerHour = pPH;
}
float PartTime::getPayPerHour() { //return the pay per hour
	return payPerHour;
}
void PartTime::salary() { //calculate the salary for the employee
	setPay(hoursOfWork * payPerHour);
}

istream& operator>>(istream& is, PartTime& employee) { //get the "part time" employee's data
	try {
		is >> (Employee&)employee;
	}
	catch (const char* str) {
		is >> employee.payPerHour;
		throw str;
	}
	employee.hoursOfWork = (int)employee.getPay();
	is >> employee.payPerHour;
	if (employee.payPerHour < 0) throw "ERROR";
	employee.salary();
	return is;
}
ostream& operator<<(ostream& os, const PartTime& employee) { //print the "part time" employee's data
	os << Employee(employee) << "Hours: " << employee.hoursOfWork << endl << "Salary per Month: " << employee.hoursOfWork * employee.payPerHour << endl << endl;
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
