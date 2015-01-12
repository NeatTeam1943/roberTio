#ifndef CUSTOMMATH_H
#define CUSTOMMATH_H

#include "defs.h"

class CustomMath {
public:
	CustomMath();
	/* Mathematical Functions for variables declared as double */
	/* Trigonomatry functions */
	double custom_sin(double x);	//Tested, works on XP
	double custom_cos(double x);	//Tested, works on XP
	double custom_tan(double x);	//Tested, works on XP

	//Unable to test, do not exist in math.h
#define custom_csc(x) (1/custom_sin(x))	//Ready for Testing
#define custom_sec(x) (1/custom_cos(x))	//Ready for Testing
#define custom_cot(x) (1/custom_tan(x))	//Ready for Testing

	/* Inverse Trig Functions */
	double custom_asin(double x);	//Tested, works on XP
	double custom_atan(double x);	//Tested, works on XP
	double custom_atan2(double x, double y);	//Tested, works on XP
#define custom_acos(x) (CUSTOM_PI*.5-custom_asin(x))	//Tested, works on XP

	/* Log functions */
	double custom_log(double x);//Takes the natural logarithm of x //Tested, works on XP

	/* Exponential Functions */
	double custom_sqrt(double x);	//Tested, works on XP
	double custom_expon(double x);	//Tested, works on XP
	double custom_pow(double x, double n);	//Tested, works on XP
	double custom_root(double x, double root);//Not able to test, does not exist in math.h

	/* Operand Functions */
	double custom_abs(double input);
	short custom_round(double input);
	short custom_sign(double input);
};

#endif
