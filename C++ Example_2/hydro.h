// hydro.h
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Sanchit Kumar
// Lab Section: B02
// Date: Nov. 21/2020
#include "list.h"
#ifndef hydro_h
#define hydro_h

void displayHeader();

int readData(FlowList &a);

int menu();

void display(FlowList &a, int b);

void average(FlowList &a, int b);

void pressEnter();

double addData(FlowList &a, int b);

void saveData(FlowList &a);

double removeData(FlowList &a, int b);
#endif