#include"bs.h"
#include<string>
#include<math.h>
using namespace std;
BS_Model::BS_Model(double p, double s0, double T, double r, double sigma, string type){
	underlying_asset_price = p;
	strike_price = s0;
	time_to_exp = T;
	risk_free_rate = r;
	volatility = sigma;
	option_type = type;
};
double BS_Model::standard_N_CDF(double x){
	double cdf = 0.5*(1 + (erf(x / sqrt(2))));
	return cdf;
}
double BS_Model::pricing(){

	double d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double d2 = d1 - volatility*sqrt(time_to_exp);
	double price;
	if (option_type == "call")
		price = underlying_asset_price*standard_N_CDF(d1) - exp(-risk_free_rate*time_to_exp)*strike_price*standard_N_CDF(d2);;
	if (option_type == "put")
		price = underlying_asset_price*standard_N_CDF(d1) - exp(-risk_free_rate*time_to_exp)*strike_price*standard_N_CDF(d2) - underlying_asset_price + strike_price*exp(-risk_free_rate*time_to_exp);
	return price;
}
double BS_Model::para_delta(){
	double d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double delta;
	if (option_type == "call")
		delta = standard_N_CDF(d1);
	else
		delta = standard_N_CDF(d1) - 1;
	return delta;
}
double BS_Model::para_gamma(){
	double d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double deriv = exp(-d1*d1 / 2.0) / sqrt(2.0*3.14159265359);
	return deriv / underlying_asset_price / volatility / sqrt(time_to_exp);
}
double BS_Model::para_vega(){
	double d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double deriv = exp(-d1*d1 / 2.0) / sqrt(2.0*3.14159265359);
	return underlying_asset_price*deriv*sqrt(time_to_exp);
}
double BS_Model::para_theta(){

	double d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double d2 = d1 - volatility*sqrt(time_to_exp);
	double deriv = exp(-d1*d1 / 2.0) / sqrt(2.0*3.14159265359);
	double theta;
	if (option_type == "call")
		theta = -underlying_asset_price*deriv*volatility / 2 / sqrt(time_to_exp) - risk_free_rate*strike_price*exp(-risk_free_rate*time_to_exp)*standard_N_CDF(d2);
	else
		theta = -underlying_asset_price*deriv*volatility / 2 / sqrt(time_to_exp) + risk_free_rate*strike_price*exp(-risk_free_rate*time_to_exp)*standard_N_CDF(-d2);
	return theta;
}
double BS_Model::para_rho(){

	double  d1 = (log(underlying_asset_price / strike_price) + time_to_exp*(risk_free_rate + 0.5*volatility*volatility)) / (volatility*sqrt(time_to_exp));
	double d2 = d1 - volatility*sqrt(time_to_exp);
	double deriv = exp(-d1*d1 / 2.0) / sqrt(2.0*3.14159265359);
	double rho;
	if (option_type == "call")
		rho = time_to_exp*strike_price*exp(-risk_free_rate*time_to_exp)*standard_N_CDF(d2);
	else
		rho = -time_to_exp*strike_price*exp(-risk_free_rate*time_to_exp)*standard_N_CDF(-d2);
	return rho;
}