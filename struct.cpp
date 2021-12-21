
#include "struct.h"
void fillStruct(Worker* x)
{
	std::cout << "Name is ";
	std::cin >>x->name;

	std::cout << "Sername is ";
	std::cin >> x->sername;

	std::cout << "Patronomic is ";
	std::cin >> x->patronomic;

	std::cout << "Password is ";
	std::cin >>x->password;

	std::cout << "Resident is ";
	std::cin >>x->residence;

	std::cout << "Age is ";
	std::cin >>x->age;

	std::cout << "Gender is ";
	std::cin >>x->gender;

	std::cout << "Family status is ";
	std::cin >>x->familyStatus;

	std::cout << "Telephone number is ";
	std::cin >>x->telephone;

	std::cin.ignore();
}

void initconsol(std::vector<Worker> &a, int n)
{
	Worker* t = new Worker;
	for (int i = 0; i < n; i++) {
		fillStruct(t);
		a.push_back(*t);
	}
}

ostream& operator<<(std::ostream& out, Worker& user)
{
	out << user.name << " " << user.sername << " " << user.patronomic << " " << user.password << " " <<
		user.residence << " " << user.age << " " <<  user.gender << " " << user.familyStatus << " " << user.telephone
		<< " " << "\n";

	return out;
}

void printconsol(std::vector<Worker> &a)
{
	std::cout << "---------------------------------------------------------------\n";
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i];
}

void printbinfile(std::vector<Worker> a)
{
	char namefile[15];
	std::cout << "Input filename ";
	cin >> namefile;
	ofstream outfile(namefile, ios::binary | ios::out);
	if (outfile.is_open())
	{
		for (auto it = a.begin(); it != a.end(); it++)
				outfile.write(reinterpret_cast<char*> (&(*it)), sizeof(Worker));
	}
	else cerr << "File not found";
	outfile.close();
}
void fillVectorFromBin(std::vector<Worker> &a)
{
	char namefile[15];
	cout << "Input filename ";
	cin >> namefile;
	ifstream infile(namefile, ios::binary | ios::in);
	if (infile.is_open())
	{
		Worker* x = new Worker;
		while (infile.read(reinterpret_cast<char*>(x), sizeof(Worker)))
		{
			a.push_back(*x);
		}
	}
	else cerr << "File not found";
	infile.close();
}
std::vector<Worker> selection(std::vector<Worker>& a)
{
	std::vector<Worker> sel;
	for (std::vector<Worker>::iterator it = a.begin(); it != a.end(); it++)
		if (it->age > 60)
			sel.push_back(*it);
	return sel;
}
void changeElement(std::vector<Worker>& a)
{
	int num;
	std::cout << "Input number of worker ";
	std::cin >> num;
	std::vector<Worker>::iterator it;
	it = a.begin();
	for (int i = 0; i < num; i++)
		it++;
	fillStruct((&(*it)));
	std::cout << it->residence;
}
Worker findFemale(std::vector<Worker> x)
{
	sort
	(
		x.begin(),
		x.end(),
		[](Worker a, Worker b)
		{
			return a.age < b.age;
		}
	);
	std::vector<Worker>::iterator it;
	it = find_if
	(
		x.begin(),
		x.end(),
		[](Worker a)
		{
			return a.familyStatus == "N";
		}
	);
	if (it != x.end())
		return *it;
	else 
	{
		Worker empty{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		return empty;
	}
}