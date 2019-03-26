#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Figure{
public:
	Figure (){}
	Figure (const vector<double> &a): sides(a){}
	virtual double Perimeter() const{
		double ans = 0;
		for (int i = 0; i < sides.size(); i++){
			ans += sides[i];
		}
		return ans;
	}
private:
	std::vector <double> sides;
};
class Triangle: public Figure{
public:
	double Perimeter() const{
		return this -> a + this -> b + this -> c;
	}
	Triangle() {}
	Triangle(double A, double B, double C): a(A), b(B), c(C){}
private:
	double a, b, c;
};

class Rectangle: public Figure{
public:
	double Perimeter() const{
		return 2 * (this -> a + this -> b);
	}
	Rectangle() {}
	Rectangle(double A, double B): a(A), b(B){}
private:
	double a, b;
};

int main(){
	int a, b, c;
	vector <Figure*> figures;
	string type;
	while (cin >> type){
		if (type == "Triangle"){
			cin >> a >> b >> c;
			figures.push_back(new Triangle(a, b, c));
		}
		if (type == "Rectangle"){
			cin >> a >> b;
			figures.push_back(new Rectangle(a, b));
		}
		if (type == "Stop"){
			break;
		}
	}
	for (Figure *f: figures){
	    cout << f -> Perimeter() << endl;
	}
	for (Figure *f: figures){
	    delete f;
	}	
}
