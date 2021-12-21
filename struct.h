#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Worker
{
	string name, sername, patronomic, password, residence, gender, familyStatus, telephone;
	int age;
};
void initconsol(std::vector<Worker>& a, int n);
void printconsol(std::vector<Worker>& a);
void printbinfile(std::vector<Worker>);
ostream& operator<<(std::ostream&, Worker&);
void fillStruct(Worker* x);
void fillVectorFromBin(std::vector<Worker>& a);
std::vector<Worker> selection(std::vector<Worker>& a);
void changeElement(std::vector<Worker>& a);
Worker findFemale(std::vector<Worker> x);