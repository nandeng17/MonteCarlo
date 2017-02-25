#include"mc.h"
Monte_Carlo::Monte_Carlo(double a, double b, double c, double d, double e, double f){
	s0 = a;
	k = b;
	rf = c;
	t = d;
	sigma = e;
	num = f;
}
double Monte_Carlo::normal_factor(){

	static mt19937 superengine;
	normal_distribution<> nor(0.0, 1.0);
	double factor = nor(superengine);
	return factor;
}
void Monte_Carlo:: price(){
	double R = (rf - 0.5*pow(sigma, 2))*t;
	double SD = sigma*sqrt(t);
	double pay_off_c = 0.0;
	double pay_off_p = 0.0;
	for (int i = 1; i <= num; i++)
	{
		double ST = s0*exp(R + SD*normal_factor());
		pay_off_c = pay_off_c + max((ST - k), 0.0);
		pay_off_p = pay_off_p + max((k - ST), 0.0);
	}
	pay_off_c = pay_off_c / num;
	pay_off_p = pay_off_p / num;
	pay_off_c *= exp(-rf*t);
	pay_off_p *= exp(-rf*t);
	result.push_back(pay_off_c);
	result.push_back(pay_off_p);

}