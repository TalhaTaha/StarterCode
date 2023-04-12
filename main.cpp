
//=================================================================================
// Name         : DS Assignment#3
// Author       :
// Version      : 1.0
// Date Created : 22-Nov-2022
// Date Modified:
// Description  : Starter Code for Flight-Ticket Management System using HASH TABLE in C++
//=================================================================================
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#include "flightticket.h"
// #include "flighthashtable.h"

//==========================================================
void listCommands()
{
	cout << "\n----------------------------------" << endl;
	cout << "import <path>      	:Import flight-tickets from a CSV file" << endl
		 << "export <path>      	:Export flight-tickets to a CSV file" << endl
		 << "count_collisions   	:Print number of collisions" << endl
		 << "add                	:Add a new flight-ticket" << endl
		 << "delete <key>       	:Delete a flight-ticket" << endl
		 << "find <key>         	:Find a flight-ticket's details" << endl
		 << "allinday <date>    	:Display all flight-tickets in a day" << endl
		 << "printASC <key>     	:Print flight-tickets in ascending order" << endl
		 << "exit               	:Exit the program" << endl;
}
//==========================================================

// to be completed with any necessary method definitions

int importCSV(string path,vector<Flight_Ticket> & data);
int exportCSV(string path,vector<Flight_Ticket> & data);
int add(Flight_Ticket * data);
long sfold(string s, int m);
void sort_Flight(vector<Flight_Ticket> & );
//==========================================================
int main(void)
{
	// FlightHASHTABLE myFlightHASHTABLE;
	// for (int i = 0; i < 10; i++)
	// {
		vector<Flight_Ticket> data;
		importCSV("test.csv",data);
		sort_Flight(data);
		exportCSV("test.csv",data);
	

	// while(true)
	// {
	// to be completed
	// cout<< "\nNO : "<<importCSV("flight-ticket10k.csv");
	// cout<<exportCSV("test.csv");
	// }

	return 0;
}
int add(Flight_Ticket * data)
{
	string temp;
	int num;
	cout<<"\nPlease enter the details of the flight ticket : ";
	cout<<"\nCompany Name : ";
	getline(cin,temp);
	data->setCompanyName(temp);
	cout<<"\nFlight number : ";
	cin>>num;
	data->setFlightNumber(num);
	cin.ignore();
	cout<<"\nCountry of origin : ";
	getline(cin,temp);
	data->setCountry_of_origin(temp);
	cout<<"\nCountry of destination : ";
	getline(cin,temp);
	data->setCountry_of_destination(temp);
	cout<<"\nStopover : ";
	getline(cin,temp);
	data->setStopOver(temp);
	cout<<"\nPrice : ";
	getline(cin,temp);
	data->setPrice(temp);
	cout<<"\nTime of departure : ";
	getline(cin,temp);
	data->setTime_of_departure(temp);
	cout<<"\nTime of arrival : ";
	getline(cin,temp);
	data->setTime_of_arrival(temp);
	cout<<"\nDate : ";
	getline(cin,temp);
	data->setDate(temp);
	cout<<"\nFlight-ticket has been succefully added!'n";
	return 1;
}

bool compare(Flight_Ticket a,Flight_Ticket b)
{
	return a.getCountry_of_destination()<b.getCountry_of_destination();
}
void sort_Flight(vector<Flight_Ticket> & data) 
{

	sort(data.begin(),data.end(),compare);

}

long sfold(string s, int m)
{
	long sum=0,mul=1;
	for (int i = 0; i <s.length(); i++)
	{
		mul=i%4==0?1:mul*256;
		sum+= s[i]*mul;

	}
	return ((int)(sum)%m);


}
int exportCSV(string path,vector<Flight_Ticket> & temp)
{
	ofstream file(path);
	if (!file.is_open())
	{
		cout << "Error ! file not open !\n";
	}
	// Flight_Ticket temp("temp",2,"temp1","temp2","temp3","temp4","temp5","temp6","temp7");
	for (int i = 0; i < temp.size(); i++)
	{
		/* code */
	
	
	file<<temp[i].getCompanyName();
	file<<',';
	file<<temp[i].getFlightNumber();
	file<<',';
	file<<temp[i].getCountry_of_origin();
	file<<',';
	file<<temp[i].getCountry_of_destination();
	file<<',';
	file<<temp[i].getStopOver();
	file<<',';
	file<<temp[i].getPrice();
	file<<',';
	file<<temp[i].getTime_of_departure();
	file<<',';
	file<<temp[i].getTime_of_arrival();
	file<<',';
	file<<temp[i].getDate();
	file<<'\n';
	}
	return 1;
}


int importCSV(string path,vector<Flight_Ticket> & data)
{
	int tempPos;
	string companyName, flightNumber, country_of_origin, country_of_destination,stopOver,price,time_of_departure,time_of_arrival,date;
	listCommands();
	fstream file(path);
	if (!file.is_open())
	{
		cout << "Error ! file not open !\n";
	}
	getline(file,price);	
	int count=0;
	while (getline(file, companyName, ','))
	{
		char temp;
		getline(file, flightNumber,',');
		int flightnum=stoi(flightNumber);
		tempPos=file.tellp();
		file >> temp;
		if (temp != '"')
		{
			file.seekp(tempPos);
			getline(file, country_of_origin, ',');
		}
		else
		{
			getline(file, country_of_origin, '"');
			country_of_origin='"'+country_of_origin+'"';

			file.ignore();
		}
		tempPos=file.tellp();
		file >> temp;
		if (temp != '"')
		{
			file.seekp(tempPos);
			getline(file, country_of_destination, ',');
		}
		else
		{
			getline(file, country_of_destination, '"');
			country_of_destination='"'+country_of_destination+'"';
			file.ignore();
		}

		getline(file ,stopOver,',');

		getline(file ,price,',');

		getline(file, time_of_departure, ',');
		getline(file, time_of_arrival, ',');
		getline(file, date);

		Flight_Ticket inst(companyName, flightnum, country_of_origin, country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date);
		count++;		
		data.push_back(inst);
		// cout<<inst.getCompanyName()<<" , ";
		// cout<<inst.getFlightNumber()<<" , ";
		// cout<<inst.getCountry_of_origin()<<" , ";
		// cout<<inst.getCountry_of_destination()<<" , ";
		// cout<<inst.getStopOver()<<" , ";
		// cout<<inst.getPrice()<<" , ";
		// cout<<inst.getTime_of_departure()<<" , ";
		// cout<<inst.getTime_of_arrival()<<" , ";
		// cout<<inst.getDate()<<"\n";
	}
	return count;
}
