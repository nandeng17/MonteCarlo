#include<iostream>
#include"mc.h"
#include"bs.h"


using namespace std;
int main()
{
    double underlying = 100.0;
	double strike = 100.0;
	double timeToExpiration = 0.50;
	double riskFreeRate = 0.05;
	double volatility = 0.20;
	
	cout << '\t' << '\t' << " [Black Scholes formula & Monte Carlo Simulation] Program" << endl;
	cout << endl;
	cout << "Basic parameters: " << endl;
	cout << "Strike price: " << strike << endl;
	cout << "Time to experiation: " << timeToExpiration << endl;
	cout << "Risk free rate: " << riskFreeRate << endl;
	cout << "Volatility: " << volatility << endl;
	cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;


	Monte_Carlo simu(underlying, strike, riskFreeRate, timeToExpiration, volatility, 50000);
	simu.price();
	BS_Model call_1(underlying,strike,timeToExpiration,riskFreeRate,volatility,"call"  );
	BS_Model put_1(underlying, strike, timeToExpiration, riskFreeRate, volatility, "put");

cout << '\t' << '\t' << " Result of Monte-Carlo Simulation:" << endl;
cout << "Call Price: "<<simu.result[0] << endl;
cout << "Put Price: "<<simu.result[1] << endl;
cout << endl;

cout << '\t' << '\t' << " Result of Black-Scholes Formula:" << endl;

cout << "Option type: Euro " << "Call" << endl;
cout << '\t' << "Option price : " << call_1.pricing()<< endl;
cout << '\t' << "Delta: " << call_1.para_delta() << endl;
cout << '\t' << "Gamma: " << call_1.para_gamma() << endl;
cout << '\t' << "Theta: " << call_1.para_theta()/365 << endl;
cout << '\t' << "Rho " << call_1.para_rho() << endl;
cout << '\t' << "Vega " << call_1.para_vega() << endl;
cout << "***********************************************" << endl;
//Put

cout << endl;
cout << "Option type: Euro " << "Put" << endl;
cout << '\t' << "Option price: " << put_1.pricing() << endl;
cout << '\t' << "Delta: " << put_1.para_delta() << endl;
cout << '\t' << "Gamma: " << put_1.para_gamma() << endl;
cout << '\t' << "Theta: " << put_1.para_theta()/365 << endl;
cout << '\t' << "Rho " << put_1.para_rho() << endl;
cout << '\t' << "Vega " << put_1.para_vega() << endl;

cout << endl;




}
