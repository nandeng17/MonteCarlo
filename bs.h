#ifndef BS_MODEL_H
#define BS_MODEL_H
#include<math.h>
#include<string>
using namespace std;
class BS_Model{

public:
	BS_Model(){};
	BS_Model(double p, double s0, double T, double r, double sigma, string type);
	double standard_N_CDF(double x);
	double pricing();
	double para_delta();
	double para_gamma();
	double para_vega();
	double para_theta();
	double para_rho();
private:
	double underlying_asset_price;
	double strike_price;
	double time_to_exp;
	double risk_free_rate;
	double volatility;
	string option_type;
};


#endif