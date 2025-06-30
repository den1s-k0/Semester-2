#include "Header.h"

istream& operator>>(istream& is, internet_service& elem)
{
	cout << "Ind = ";
	is >> elem.Indef;
	cout << "Name = ";
	is >> ws;
	getline(is, elem.Name);
	cout << "Time = ";
	is >> elem.Time;
	return is;
}

ostream& operator<<(ostream& os, const internet_service elem)
{
	os << "Ind: " << elem.Indef << "\tName: " << elem.Name << "\tTime: " << elem.Time;
	return os;
} 

void Dlist<internet_service>::fread(const string& path) {
	try {
		ifstream in(path);
		if (!in)
			throw string("������ �������� �����");

		string line;
		while (getline(in, line)) {
			try {
				if (line.empty())
					continue;

				istringstream iss(line);
				int ind;
				double time;
				string name;
				if (!(iss >> ind >> time))
					throw string("������������ ������");

				iss >> ws;
				getline(iss, name);

				if (name.empty())
					throw string("����������� ��������");

				internet_service A(ind, name, time);
				push_back(A);
			}
			catch (const string& e) {
				cerr << "������ ��������� ������: " << line << " - " << e << endl;
			}
		}
		in.clear();
		in.close();
	}
	catch (const string& e) {
		cerr << "������ ������ �����: " << e << endl;
		throw;
	}
}