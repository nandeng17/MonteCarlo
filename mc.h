#ifndef MONTE_CARLOee_H
#define MONTE_CARLOee_H
#include <chrono>
#include<algorithm>
#include<random>
#include<vector>
using namespace std;

class Monte_Carlo{
public:
	Monte_Carlo(double a, double b, double c, double d, double e, double f);
	double normal_factor();
	void price();
	vector<double>result;

private:
	double s0;
	double k;
	double rf;
	double t;
	double sigma;
	double num;
};


#endif