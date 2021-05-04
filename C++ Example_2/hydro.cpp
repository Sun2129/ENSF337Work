// hydro.cpp
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Sanchit Kumar
// Lab Section: B02
// Date: Nov. 21/2020
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "list.h"
#include "hydro.h"


int main(){
	FlowList x;
	int numRecords;
	displayHeader();
	numRecords = readData(x);
	int quit = 0;
	
	while(1){
		switch(menu()){
			case 49:
				display(x, numRecords);
				pressEnter();
				break;
			case 50:
				numRecords = addData(x, numRecords);
				pressEnter();
				break;
			case 51:
				saveData(x);
				pressEnter();
				break;
			case 52:
				numRecords = removeData(x, numRecords);
				pressEnter();
				break;
			case 53:
				cout <<"\n Program Terminated!\n\n";
				quit = 1;
				break;
			default:
				cout <<"\n Not a valid input.\n";
				pressEnter();
		}
		if(quit == 1) break;
	}
	
	return 0;
}

void displayHeader(){
	cout <<"Program: Flow Studies - Fall 2020\n";
	cout <<"Version: 1.0\n";
	cout <<"Lab Section: B02\n";
	cout <<"Produced By: Sanchit Kumar\n";
	cout <<"\n<<<< Press Enter to Continue >>>>\n";
	cin.get();
}

int menu(){
	int num = 0;
	cout <<"\nPlease select one of the following operations\n";
	cout <<"    1. Display flow list, and the average.\n";
	cout <<"    2. Add data.\n";
	cout <<"    3. Save data into the file.\n";
	cout <<"    4. Remove data.\n";
	cout <<"    5. Quit.\n";
	num = cin.get();
	return num;
}

void pressEnter(){
	cin.ignore();
	cout <<"\n<<<< Press Enter to Continue >>>>\n";
	cin.get();
	
}

void display(FlowList &a, int b){
	a.print();
	average(a,b);
}

int readData(FlowList &a){
	int num = 0;
	num = a.readData();
	return num;
}

void average(FlowList &a, int b){
	double average = 0;
	average = a.average(b);
	std::cout << std::setprecision(2) << std::fixed;
	cout <<"\nThe annual average of the flow is: "<<average<<" billions of cubic meter.\n";
}

double addData(FlowList &a, int b){
	int newRecords = 0;
	newRecords = a.addData();
	if(newRecords == 0){
		cout <<"Error: Duplicate Data\n";
		return b;
	}
	else{
		cout <<"New record inserted successfully.\n";
		return newRecords;
	}
	
}

double removeData(FlowList &a, int b){
	int newRecords = 0;
	newRecords = a.removeData();
	if(newRecords == 0){
		cout <<"Error: No such data.\n";
		return b;
	}
	else{
		cout <<"Record was successfully removed.\n";
		return newRecords;
	}
	
}

void saveData(FlowList &a){
	a.saveData();
	cout <<"Data was saved in the file.\n";
}