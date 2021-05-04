// list.cpp
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Sanchit Kumar
// Lab Section: B02
// Date: Nov. 21/2020

#include <iostream>

#include <fstream>
using namespace std;
#include <stdlib.h>

#include "list.h"

FlowList::FlowList()
: headM(0)
{
}

double FlowList::average(int b){
	double sum = 0;
	Node *current = headM;
	while(current != 0){
		sum = sum + current->item.flow;
		current = current->next;
	}
	return sum/b;
}

void FlowList::saveData(){
	ofstream outObj;
	outObj.open("flow.txt");
	
	if ( outObj.fail() ){   
		cout << "Error: cannot open the file."<< endl;
		exit(1);
	}
	
	Node *current = headM;
	outObj <<"\n";
	while(current != 0){
		outObj << current->item.year;
		outObj <<"      ";
		outObj << current->item.flow;
		outObj <<"\n";
		current = current->next;
	}
	
	outObj.close();
	
}

double FlowList::addData(){
	int year = 0;
	double flow = 0;
	int count = 0;
	
	cout <<"Please Enter a Year:";
	cin >> year;
	cout <<"Please Enter the Flow:";
	cin >> flow;
	
	Node *current = headM;
	while(current != 0){
		if(year != current->item.year){
			current = current->next;
		}
		else{
			return 0;
		}
	}
	
	Node *new_node = new Node;
	new_node->item.year = year;
	new_node->item.flow = flow;
	new_node->next = headM;
	headM = new_node;
	
	
	current = headM;
	double temp = 0;
	while (current != 0){
		count++;
		Node *index = current->next;
		while(index != 0){
			if(current->item.year > index->item.year){
				temp = current->item.year;
				current->item.year = index->item.year;
				index->item.year = temp;
				
				temp = current->item.flow;
				current->item.flow = index->item.flow;
				index->item.flow = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	
	return count;
}

double FlowList::removeData(){
	int year = 0;
	int num = 0;
	int count = 0;
	
	cout <<"Please Enter a Year:";
	cin >> year;
	
	Node *current = headM;
	while(current != 0){
		if(year == current->item.year){
			num++;	
			current = current->next;
		}
		else{
			current = current->next;
		}
	}
	
	if(num == 1){
		Node *doomed = 0;
		if(year == headM->item.year){
			doomed = headM;
			headM = headM->next;
		}
		else{
			Node *before = NULL;
			Node *maybe = headM;
			while(maybe != 0 && year != maybe->item.year){
				before = maybe;
				maybe = maybe->next;
				
			}
			before->next = maybe->next;
			delete maybe;
		}
		
	}
	
	else{
		return 0;
	}
	
	current = headM;
	double temp = 0;
	while (current != 0){
		count++;
		Node *index = current->next;
		while(index != 0){
			if(current->item.year > index->item.year){
				temp = current->item.year;
				current->item.year = index->item.year;
				index->item.year = temp;
				
				temp = current->item.flow;
				current->item.flow = index->item.flow;
				index->item.flow = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	
	return count;
	
}

void FlowList::print()const{
	Node *current = headM;
	double temp = 0;
	while (current != 0){
		Node *index = current->next;
		while(index != 0){
			if(current->item.year > index->item.year){
				temp = current->item.year;
				current->item.year = index->item.year;
				index->item.year = temp;
				
				temp = current->item.flow;
				current->item.flow = index->item.flow;
				index->item.flow = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	cout <<"Year";
	cout <<"       Flow(in billions of cubic meters)\n";
	current = headM;
	while(current != 0){
		cout <<""<<current->item.year;
		cout <<"               "<<current->item.flow;
		cout<<"\n";
		current = current->next;
	}
}	

int FlowList::readData(){
	int count = 0;
	double num1 = 0;
	
	ifstream inObj;
	inObj.open("flow.txt");
	
	if ( inObj.fail() ){   
		cout << "Error: cannot open the file."<< endl;
		exit(1);
	}
	
	while(inObj >> num1){
		count++;
		if(count%2 != 0){
			Node *new_node = new Node;
			new_node->item.year = num1;
    
			if (headM == 0) {
				new_node->next = headM;
				headM = new_node;
				
        
			}
			else {
				Node *before = headM;      
				Node *after = headM->next;
				while(after != 0) {
					before = after;
					after = after->next;
				}
				new_node->next = after;
				before->next = new_node;
				
        
			}
			
		}
		
		else{
			Node *current = headM;
			while(current != 0){
				if(current->item.flow != 0){
					current = current->next;
				}
				else{
					current->item.flow = num1;
				}
			}
		}
		
	}
	
	Node *current = headM;
	
	double temp = 0;
	while (current != 0){
		Node *index = current->next;
		while(index != 0){
			if(current->item.flow > index->item.flow){
				temp = current->item.flow;
				current->item.flow = index->item.flow;
				index->item.flow = temp;
				
				temp = current->item.year;
				current->item.year = index->item.year;
				index->item.year = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	
	inObj.close();
	
	return count/2;
}