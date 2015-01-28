#include <Xbox/CustomMath.h>

#define tol 1.e-9

CustomMath::CustomMath() {

}

/* Trigonomatry functions */
double CustomMath::custom_sin(double x) {
	double sum, term, y, factor, power, z;
	while (x > CUSTOM_2PI)
		x -= CUSTOM_2PI;
	while (x < -CUSTOM_2PI)
		x += CUSTOM_2PI;
	if (x == 0.)
		return 0.;
	if (x == CUSTOM_2PI)
		return 0.;
	power = factor = term = 1.;
	sum = 1.;
	z = 2.;
	y = x * x;
	do {

		factor /= (-z * (z + 1.));
		power *= y;
		term = factor * power;
		sum += term;
		z += 2.;
	} while (!(custom_abs(term) < tol));
	return sum * x;
}
double CustomMath::custom_cos(double x) {
	return (custom_sin(CUSTOM_PI_2 - x));
}
double CustomMath::custom_tan(double x) {
	return (custom_sin(x) / custom_cos(x));
}

/* Inverse Trig Functions */
double CustomMath::custom_asin(double x) {
	double sum, term/*,old*/, y, factor, power, z, q;/*int i;*/
	if (x == 0.)
		return 0.;
	if (x == 1.)
		return CUSTOM_PI_2;
	if (x == -1.)
		return -CUSTOM_PI_2;
	if (custom_abs(x) > 1.)
		return errorcode;
	if (custom_abs(x) > .7071) {
		sum = custom_atan(x / custom_sqrt(1. - x * x));
		return sum;
	}
	/*		return halfpi-arc_sine(square_rt(1.-x*x));*/
	power = factor = term = 1.;
	sum = 1.;
	z = 2.;
	y = x * x;
	do {
		/*old=term;*/
		q = z - 1.;
		factor *= q * q / (z * (z + 1.));
		power *= y;
		term = factor * power;
		sum += term;
		//if(custom_abs(term)< tol)break;
		z += 2.;
	} while (!(custom_abs(term) < tol));
	return sum * x;
}
double CustomMath::custom_atan(double x) {
	double sum, term, old, y, power/*,sign,factor*/, z;
	int i;
	if (x == 0.)
		return 0.;
	if (custom_abs(x) > 1.) {
		sum = custom_atan(1. / x);
		if (x > 0.)
			return CUSTOM_PI * .5 - sum;
		else
			return -CUSTOM_PI * .5 - sum;
	}
	y = x * x;
	old = 1. / (1. + y);
	z = y * old;
	sum = 1.;
	i = 4;
	power = z * 2. / 3.;
	do {
		term = power;
		sum += term;
		power *= (z * i / (i + 1.));
		i += 2;
	} while (!(custom_abs(term) < tol));
	return x * old * sum;
}
double CustomMath::custom_atan2(double x, double y) {
	double at;
	if (x == 0.) {
		if (y == 0.)
			return 0.;
		if (y > 0.)
			return CUSTOM_PI_2;
		else
			return -CUSTOM_PI_2;
	}
	at = custom_atan(y / x);
	if (x > 0.)
		return at;
	if (y < 0.)
		return at - CUSTOM_PI;
	return at + CUSTOM_PI;
}

/* Log functions */
double CustomMath::custom_log(double x) {
	double sum, term, y, ys, factor, power, offset;
	int i;
	double e = 2.718281828459045;
	if (x <= 0.)
		return errorcode;
	if (x == 1.)
		return 0.;
	if (x < .5)
		return -custom_log(1. / x);
	offset = 0.;
	power = factor = term = 1.;
	sum = 1.;
	i = 3;
	while (x > e) {
		x /= e;
		offset += 1.;
	}
	y = (x - 1.) / (x + 1.);
	ys = y * y;
	do {
		factor = 1. / ((double) i);
		power *= ys;
		term = factor * power;
		sum += term;
		i += 2;
	} while (!(custom_abs(term) < tol));
	return 2. * y * sum + offset;
}

/* Exponential Functions */
double CustomMath::custom_sqrt(double x) {
	double z, old;
	if (x < 0.)
		return errorcode;
	if (x == 0.)
		return 0.;
	if (x == 1.)
		return 1.;
	z = 1.;
	do {
		old = z;
		z = .5 * (z + x / z);
	} while (!(custom_abs(old - z) < tol));
	return z;
}
double CustomMath::custom_expon(double x) {
	double sum, term, factor, power;
	int i;
	if (x < -65.)
		return 0.;
	if (x > 65.)
		return -errorcode;
	if (x >= 1.)
		return 1. / custom_expon(-x);
	power = factor = term = 1.;
	sum = 1.;
	i = 1;
	do {
		factor /= ((double) i);
		power *= x;
		term = factor * power;
		sum += term;
		i++;
	} while (!(custom_abs(term) < tol));
	return sum;
}
double CustomMath::custom_pow(double x, double n) {
	int k, i;
	double pow, p;
	if (n == 0.)
		return 1.0;
	if (x == 1.)
		return 1.;
	if (x == 0.) {
		if (n > 0.)
			return 0.;
		return errorcode;
	}
	k = n;
	/*non-integral*/
	if (((double) k - n) != 0.) {
		if (x <= 0.)
			return errorcode;
		return custom_expon(n * custom_log(x));
	}
	pow = 1.;
	p = x;
	if (x < 0)
		p = -p;
	if (k < 0) {
		k = -k;
		i = 1;
	} else
		i = 0;
	while (k) {
		if (1 & k)
			pow *= p;
		p *= p;
		k >>= 1;
	}
	if (x < 0 && (((int) n) % 2)) {
		if (i)
			return -1. / pow;
		return -pow;
	}
	if (i)
		return 1. / pow;
	return pow;
}
double CustomMath::custom_root(double x, double root) {
	double mult, a, z, b, c, zo;
	int d, n;
	mult = 1.;
	n = custom_abs(root);
	if (n == 0)
		return 1.0;
	if (x == 0.)
		return 0.0;
	if (x == 1.)
		return 1.;
	if (x < 0 && !(n % 2))
		return errorcode;
	if (x < 0) {
		x = -x;
		mult = -1.;
	}
	a = 1. / n;
	b = 1. - a;
	c = a * x;
	d = n - 1;
	z = zo = 1.;
	for (;;) {
		z = b * z + c / custom_pow(z, d);
		if (custom_abs(z - zo) < tol) {
			if (root > 0)
				return z * mult;
			return mult / z;
		}
		zo = z;
	}
}

/* Operand Functions */
double CustomMath::custom_abs(double input) {
	double output = input;
	if (input < 0) {
		output = -1 * input;
	}
	return (output);

}
short CustomMath::custom_round(double input) {
	input = input + .5;
	short output = (short) input;
	return (output);
}
short CustomMath::custom_sign(double input) {
	short sign = 1;
	if (input < 0) {
		sign = -1;
	}
	return (sign);
}
