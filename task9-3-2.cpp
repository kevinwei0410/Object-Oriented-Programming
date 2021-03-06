#include "pch.h"
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
class Package
{
private:
	string senderName;
	string senderCity;
	string recipientName;
	string recipientCity;
	double costPerWeight; 
protected:
	double weight;
public:
	Package(string str1, string str2, string str3, string str4, double num1, double num2) :
		senderName(str1), senderCity(str2), recipientName(str3), recipientCity(str4), weight(num1), costPerWeight(num2) {;}
	double calculateCost() const{ return  costPerWeight * weight; }
};
class TwoDayPackage : public Package
{
private:
	double flatFee; 
public:
	TwoDayPackage(string str1, string str2, string str3, string str4, double num1, double num2, double num3) :Package(str1, str2, str3, str4, num1, num2) { flatFee = num3; }
	double calculateCost() const { return Package::calculateCost() + flatFee; }
};
class OvernightPackage : public Package
{
private:
	double overnightFreePerWeight;
public:
	OvernightPackage(string str1, string str2, string str3, string str4, double num1, double num2, double num4) :Package(str1, str2, str3, str4, num1, num2){ overnightFreePerWeight = num4; }
	double calculateCost() const { return Package::calculateCost() + overnightFreePerWeight * weight; }
};
/*void display(const Package &p1)
{
	cout << "Package 1:" << endl << "Sender:" << endl;
	cout << p1.senderName << "/" << p1.senderCity << endl;
	cout << "Recipient:" << endl;
	cout << p1.recipientName << "/" << p1.recipientCity << endl;
	cout << "Cost: $" << p1.calculateCost() << endl;
}*/
int main()
{
	Package package1("Lou Brown", "Boston", "Mary Smith", "New York", 8.5, .5);
	TwoDayPackage package2("Lisa Klein", "Somerville", "Bob George", "Cambridge", 10.5, .65, 2.0);
	OvernightPackage package3("E Lewis", "Boston", "Don Kelly", "Denver", 12.25, .7, .25);
	

	return 0;
}