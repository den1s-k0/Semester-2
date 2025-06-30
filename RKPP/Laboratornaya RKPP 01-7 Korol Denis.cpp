#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Figure {
protected:
	friend void get_count();
	const int ID;
	const string Name;
public:
	static int Count;

	Figure(): ID(++Count), Name("M" + to_string(Count)) {}
	Figure(string aName): ID(++Count), Name(aName) {}
	Figure(const Figure& F) : ID(++Count), Name(F.Name) {}
	~Figure() {}
	virtual int get_ID() = 0;
	virtual string get_Name() = 0;
	virtual void Show() = 0;
};
int Figure::Count = 0;

void get_count() {
	cout << "Count = " << Figure::Count << endl;
}

class Point {
protected:
	friend ostream& operator << (ostream& os, const Point& P);
	string Color;
	string Name;
public:
	int x;
	int y;
	static int CountPoints;
	Point(): Name("P" + to_string(++CountPoints)), Color("Black"), x(0), y(0) {}
	Point(int a, int b) : Name("P" + to_string(++CountPoints)), Color("Black"), x(a), y(b) {}
	Point(string NAME, int a, int b) : Name(NAME), Color("Black"), x(a), y(b) {}
	Point(string NAME) : Name(NAME), Color("Black"), x(0), y(0) {}
	Point(string NAME, string COLOR, int a, int b) : Name(NAME), Color(COLOR), x(a), y(b) {}

	void set_x(int a) {
		x = a;
	}
	void set_y(int b) {
		y = b;
	}
	void set_color(string C) {
		Color = C;
	}
	void set_name(string N) {
		Name = N;
	}
	void set_point(int a, int b, string C, string N) {
		x = a;
		y = b;
		Color = C;
		Name = N;
	}
	void set_point() {
		int a, b;
		string C, N;
		cout << "Введите координаты: \n";
		cin >> a >> b;
		cout << "Введите цвет и имя: \n";
		cin >> C >> N;
		cout << endl;
		x = a;
		y = b;
		Color = C;
		Name = N;
	}
	~Point() {}
};

int Point::CountPoints = 0;

ostream& operator << (ostream &os, const Point& P) {
	cout << "Point: Name = " << P.Name << "  Color = " << P.Color << "\tX = " << P.x << "\tY = " << P.y << endl;
	return os;
}

class Polygon : public Figure {
protected:
	double S;
	int N;
	Point* tochki;
	friend ostream& operator << (ostream& os, const Polygon& Pol);
public:
	Polygon() : Figure(), S(0), tochki(0), N(0) {}
	Polygon(const Polygon& Pol) : Figure(Pol), S(Pol.S), N(Pol.N) {
		tochki = new Point[N];
		for (int i = 0; i < N; i++)
			tochki[i] = Pol.tochki[i];
	}
	Polygon(string aName) : Figure(aName), S(0), N(0), tochki(0) {}
	Polygon(int aN) : Figure(), S(0), N(aN) {
		if (aN < 0) N = 0;
		tochki = new Point[N];
	}
	Polygon(string aName, int aN) : Figure(aName), S(0), N(aN) {
		if (aN < 0) N = 0;
		tochki = new Point[N];
	}
	Polygon(string aName, Point A, Point B, Point C) : Figure(aName), S(0), N(3) {
		tochki = new Point[3];
		tochki[0] = A;
		tochki[1] = B;
		tochki[2] = C;
	}
	void find_s() {
		if (N < 3) {
			S = 0;
			cout << " S = 0\n";
		}
		if (N == 3) {
			double a = sqrt((tochki[1].x - tochki[0].x) * (tochki[1].x - tochki[0].x) + (tochki[1].y - tochki[0].y) * (tochki[1].y - tochki[0].y));
			double b = sqrt((tochki[2].x - tochki[0].x) * (tochki[2].x - tochki[0].x) + (tochki[2].y - tochki[0].y) * (tochki[2].y - tochki[0].y));
			double c = sqrt((tochki[1].x - tochki[2].x) * (tochki[1].x - tochki[2].x) + (tochki[1].y - tochki[2].y) * (tochki[1].y - tochki[2].y));
			double p = (a + b + c) / 2;
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "S = " << S << endl;
		}
		if (N > 3) {
			cout << "Введите S: \n";
			cin >> S;

		}
	}
	void set_point(int i) {
		if (i - 1 < N && i > 0) tochki[i - 1].set_point();
		else cout << "Error\n";
	}
	int get_ID() {
		return ID;
	}
	string get_Name() {
		return Name;
	}
	void Show() {
		cout << *this;
	}
	~Polygon() {
		delete[] tochki;
	}
};

ostream& operator << (ostream& os, const Polygon& Pol) {
	cout << "Name = " << Pol.Name << " ID = " << Pol.ID << " N = " << Pol.N << " S = " << Pol.S << endl;
	for (int i = 0; i < Pol.N; i++) cout << Pol.tochki[i];
	cout << endl;
	return os;
}


int main()
{
    setlocale(LC_ALL, "rus");
	Point a(0, 0), b(0, 1), c(1, 0);
	Polygon A("AAA"), B, C(5),D("DDD", -1), E(A), F("FFF", a, b, c);
	cout << A.get_ID() << '\t' << A.get_Name() << endl;
	cout << A << B << C << D << E << F;
	F.find_s();
	C.find_s();
	cout << F << C;
	C.set_point(1);
	C.set_point(2);
	cout << C;
	A.Show();
	get_count();
}
