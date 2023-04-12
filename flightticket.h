#ifndef FLIGHT_TICKET_H
#define FLIGHT_TICKET_H

#include <iostream>
using namespace std;

class Flight_Ticket
{
private:
	string companyName;
	int flightNumber;
	string country_of_origin;
	string country_of_destination;
	string stopOver;
	string price;
	string time_of_departure;
	string time_of_arrival;
	string date;

public:
	Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date);

	string getCompanyName();
	int getFlightNumber();
	string getCountry_of_origin();
	string getCountry_of_destination();
	string getStopOver();
	string getPrice();
	string getTime_of_departure();
	string getTime_of_arrival();
	string getDate();

	void setCompanyName(string);
	void setFlightNumber(int);
	void setCountry_of_origin(string);
	void setCountry_of_destination(string);
	void setStopOver(string);
	void setPrice(string);
	void setTime_of_departure(string);
	void setTime_of_arrival(string);
	void setDate(string);
};
Flight_Ticket::Flight_Ticket(string compName, int flightNumb, string country_of_Origin, string country_of_Destination, string stopOvers, string pr, string time_of_Departure, string time_of_Arrival, string d)
{
	companyName=compName;
	flightNumber=flightNumb;
	country_of_origin=country_of_Origin;
	country_of_destination=country_of_Destination;
	stopOver=stopOvers;
	price=pr;
	time_of_departure=time_of_Departure;
	time_of_arrival=time_of_Arrival;
	date=d;
}


string Flight_Ticket::getCompanyName()
{
	return companyName;
}
int Flight_Ticket::getFlightNumber()
{
	return flightNumber;
}
string Flight_Ticket::getCountry_of_origin()
{
	return country_of_origin;
}
string Flight_Ticket::getCountry_of_destination()
{
	return country_of_destination;
}
string Flight_Ticket::getStopOver()
{
	return stopOver;
}
string Flight_Ticket::getPrice()
{
	return price;
}
string Flight_Ticket::getTime_of_departure()
{
	return time_of_departure;
}
string Flight_Ticket::getTime_of_arrival()
{
	return time_of_arrival;
}
string Flight_Ticket::getDate()
{
	return date;
}

void Flight_Ticket::setCompanyName(string data)
{
	companyName = data;
}
void Flight_Ticket::setFlightNumber(int data)
{
	flightNumber = data;
}
void Flight_Ticket::setCountry_of_origin(string data)
{
	country_of_origin = data;
}
void Flight_Ticket::setCountry_of_destination(string data)
{
	country_of_destination = data;
}
void Flight_Ticket::setStopOver(string data)
{
	stopOver = data;
}
void Flight_Ticket::setPrice(string data)
{
	price = data;
}

void Flight_Ticket::setTime_of_departure(string data)
{
	time_of_departure=data;
}

void Flight_Ticket::setTime_of_arrival(string data)
{
	time_of_arrival = data;
}

void Flight_Ticket::setDate(string data)
{
	date = data;
}

#endif
