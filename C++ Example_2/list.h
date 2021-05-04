// list.h
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Sanchit Kumar
// Lab Section: B02
// Date: Nov. 21/2020
#ifndef list_H
#define list_H

struct ListItem{
	int year = 0;
	double flow = 0;
};

struct Node {
  ListItem item;
  Node *next;
};

class FlowList {
public:
	FlowList();
	void print() const;
	int readData();
	double average(int b);
	double addData();
	void saveData();
	double removeData();
  

private:
  Node *headM;
  

  
};
#endif