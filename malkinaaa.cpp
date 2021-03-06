#include "malkinaaa.h"

/**
 * Метод Гаусса
 */
void malkinaaa::lab1()
{
	for (int i = 0; i < N; i++)
			x[i] = b[i];
	long double m;
	for (int k = 0; k < N - 1; k++)     // прямой ход
		{
			for (int i = k + 1; i < N; i++)
				{
					m = A[i][k] / A[k][k]; // умножение k-й строки на число
  					for (int j = k; j < N; j++)
						{
							A[i][j] -= m * A[k][j]; // вычитание к-й строки
						}
					 x[i] -= m * x[k];
				 }
		}
	for (int i = N - 1; i >= 0; i--) //обратный ход
		{
			for (int j = i + 1; j < N; j++)
					x[i] -= A[i][j]*x[j];
			x[i] /= A[i][i];
		}
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void malkinaaa::lab2()
{
	long double m = 0;
	int index;
	for (int k = 0; k < N-1; k++)
			{
				index = k;
				for (int i = k + 1; i < N; i++)
				{
					if(abs(A[i][k]) > abs(A[index][k]))
						{
							index = i;
						}
				}
				std::swap(A[index], A[k]);
				std::swap(b[index], b[k]);
				for (int i = k + 1; i < N; i++)
				 {
 					m = A[i][k] / A[k][k];
  					for (int j = k; j < N; j++)
					{
  						A[i][j] -= m * A[k][j];
  					}
					 b[i] -= m * b[k];
				 }
			}
			for (int i = 0; i < N; i++)
				x[i] = b[i];
			for (int i = N - 1; i >= 0; i--)
			{
				for (int j = i + 1; j < N; j++)
				{
					 x[i] -= A[i][j] * x[j];
				}
				x[i] /= A[i][i];
			}
}

/**
 * Метод квадратного корня (метод Холецкого)
 */
void malkinaaa::lab3()
{
long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        {
                L[i][j]=0;
        }
	for (int i = 0; i < N; i++)
        {
            for(int k=0; k<i; k++)
                s+=L[i][k]*L[i][k];

            L[i][i]=sqrt(A[i][i]-s);
            s = 0;

        for (int j = i+1; j < N; j++)
            {
                for (int k=0; k<j-1; k++)
                    s+=L[j][k]*L[i][k];
                L[j][i] = (A[j][i]-s)/L[i][i];
                s = 0;
            };
        }

	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s += L[i][j]*y[j];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
	}
}



/**
 * Метод прогонки
 */
void malkinaaa::lab4()
{
		long double* P = new long double[N];
		long double* Q = new long double[N];
		for (int i = 0; i<N; i++)
			{
				P[i] = 0;
				Q[i] = 0;
			}
		P[0] = A[0][1]/(-A[0][0]);
		Q[0] = b[0]/A[0][0];
		for(int i = 1; i<N; i++)
			{
				P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
				Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i]-A[i][i-1]*P[i-1]);
			}
		x[N - 1] = Q[N - 1];
		for(int i = N - 2; i >= 0; i--)
			x[i] = P[i]*x[i+1] + Q[i];
		delete[] P;
		delete[] Q;
}



/**
 * Метод Якоби
 */
void malkinaaa::lab5()
{
	long double eps = 0.00000001;
    long double* p = new long double[N];
	long double norm;
    for (int i = 0; i < N; i++)
<<<<<<< HEAD
        x[i]=0;
=======
        x[i] = 0;
>>>>>>> 069048e47b42ef859803cc724b7d3901de298439
    do {
		for (int i = 0; i < N; i++)
        {
			p[i] = b[i];
			for (int j = 0; j < N; j++)
<<<<<<< HEAD
				if (i != j) p[i] -= A[i][j] * x[j];
=======
				{
				    if (i != j)
                     p[i] -= A[i][j] * x[j];
				}
>>>>>>> 069048e47b42ef859803cc724b7d3901de298439
			p[i] /= A[i][i];
		}
        norm = fabs(x[0] - p[0]);
		for (int h = 0; h < N; h++)
        {
			if (fabs(x[h] - p[h]) > norm)
				norm = fabs(x[h] - p[h]);
			x[h] = p[h];
		}
	} while (norm > eps);
	delete[] p;
}



/**
 * Метод Зейделя
 */
void malkinaaa::lab6()
{
<<<<<<< HEAD
	    long double eps = 0.00000001;
    long double *p = new long double [N];
    bool conv;
    for (int i = 0; i < N; i++)
        x[i]=0;
    do
    {
        for (int i = 0; i < N; i++)
            p[i] = x[i];
        for (int i = 0; i < N; i++)
        {
            double var = 0;
            for (int j = 0; j < i; j++)
                var += (A[i][j] * x[j]);
            for (int j = i + 1; j < N; j++)
                var += (A[i][j] * p[j]);
            x[i] = (b[i] - var) / A[i][i];
        }
        conv=true;
        for (int i = 0; i < N; i++)
            if (fabs(x[i]-p[i])>=eps){
                conv=false;
                break;
            }

    } while (conv==false);
    delete[] p;
=======
    long double eps = 0.00000001;
    double *y = new double[N];
    double norm = 0;
    double var = 0;
    do
    {
        for (int i = 0; i < N; i++)
		{
            y[i] = x[i];
		}

        for (int i = 0; i < N; i++)
        {
            var = 0;
            norm = 0;
            for (int j = 0; j < i; j++)
			{
                var += (A[i][j] * x[j]);
			}

            for (int j = i + 1; j < N; j++)
			{
                var += (A[i][j] * x[j]);
			}

            x[i] = (b[i] - var) / A[i][i];

            for (int i = 0; i < N; i++)
			{
                norm += (x[i] - y[i]) * (x[i] - y[i]);
			}
        }
    }
	while (sqrt(norm) >= eps);
>>>>>>> 069048e47b42ef859803cc724b7d3901de298439
}



/**
 * Один из градиентных методов
 */
void malkinaaa::lab7()
{

}
