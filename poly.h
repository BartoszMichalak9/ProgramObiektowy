#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class poly //klasa poly
{
private:
	double* tabpoly;
	double* newtabpoly;
	unsigned int size;
	
public:
	poly(double w=0) 
		{		
			tabpoly = new double[0];
			tabpoly[0]=w;	
		}
	
	
	~poly()
		{
			delete [] tabpoly;
		}



	double & operator[] (unsigned int nr) //przypisanie [] dostêpu do ka¿dego elementu w tablicy
	{
		if(tabpoly.size() <= nr)
		{
			for(unsigned int i=0; i<nr; ++i)
			{
				this->tabpoly.push_back(0);
			}
		}
		return this->tabpoly[nr];
	};
	
	double operator() (double x) //funktor klasy, wartosc wielomianu w pkt
	{
		double wyn=0;
		
		for(unsigned int i=0; i< this->tabpoly.size(); ++i)
		{
			wyn += this->tabpoly[i] * pow(x, i);
		}
		
		return wyn;
	}

	friend ostream & operator << (ostream & s, const poly &wie) // wyswietlanie
	{
		int size = wie.tabpoly.size();
		
		for(unsigned int i=0; i< size; ++i)
		{
			if (wie.tabpoly[i]!=0)
			{
				if(i==0) //wyswietlanie stopnia 0
				{
					s << wie.tabpoly[i];					
				}	
				else if(i==1)  //wyswietlanie stopnia 1
				{
					s << " + " << wie.tabpoly[i]<<"x";				
				}
	
				else // wyswietlanie stopnia > 1
				{
					
					s << " + "<< wie.tabpoly[i]<<"x^"<< i;				
				}
		   	}
		}
		return s;
	};

	poly operator+ (const poly& pol) //sumowanie wielomianow
	{
		poly Poly;
		
		int size=0;
		size = pol.tabpoly.size();

		for(unsigned int i=0; i<this->tabpoly.size(); ++i)
		{
				Poly[i] = this->tabpoly[i];
		}
		
		for(unsigned int i=0; i<size; ++i)
		{
				Poly[i] += pol.tabpoly[i];
		}

		return Poly;
	};

	friend poly operator* (const poly& poly1, const poly& poly2) //mno¿enie wielomianów 
	{
		poly Poly;
		
		for(unsigned int i=0; i<poly1.tabpoly.size(); i++)
		{
			for(unsigned int n=0; n<poly2.tabpoly.size(); n++)
			{
				Poly[i+n] += poly1.tabpoly[i] * poly2.tabpoly[n];
			}
		}
		
		return Poly;
	};
	
};
