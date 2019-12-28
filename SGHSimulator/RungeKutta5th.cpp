#include "RungeKutta5th.h"

RungeKutta5th::RungeKutta5th()
{
}

double RungeKutta5th::next_step(std::function<double(double)> g, double var) // Move to RungeKutta?
{
	double arg[SIZE_Y];
	double k[SIZE_Y];
	std::fill_n(arg, SIZE_Y, var);
	std::fill_n(k, SIZE_Y, 0);
	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < i; j++)
			arg[i] += aij[j][i] * k[j];
		k[i] = h * g(arg[i]);
	}

	double var_next = var;
	double var_next_prim = var;
	for (int i = 0; i < bi.size(); i++)
	{
		var_next += bi[i] * k[i];
	}
		return var_next;
}