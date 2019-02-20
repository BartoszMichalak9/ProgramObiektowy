#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class poly //klasa poly
{
private:
	double* tabpoly;
	unsigned int size;
public:



	poly(double w=0) //wpisanie do tablicy
	{
	
	tabpoly = new double[1];
	size = 1;

	tabpoly[0]=w;
	}


~poly()
{
		
	delete [] tabpoly;

}

poly(const poly &p)
{
	tabpoly = new double [p.size];
	size=p.size;

	for (unsigned int i=0;i<p.size;++i)
		tabpoly[i]=p.tabpoly[i];
}


poly & operator=(const poly & p)
{
	double* newtabpoly;

	newtabpoly = new double [p.size];
	size = p.size;
	
	for (unsigned int i=0;i<p.size;i++)
		newtabpoly[i]=p.tabpoly[i];

	swap(tabpoly, newtabpoly);

	delete [] newtabpoly;
	
	return * this;
}


	double & operator[] (unsigned int nr) //przypisanie [] dostêpu do ka¿dego elementu w tablicy
	{
		double* newtabpoly;

		if(size <= nr)
		{	
			
			newtabpoly = new double [nr+1];		
			for(unsigned int i=0; i<size; ++i)
				newtabpoly[i]=tabpoly[i];
			for(unsigned int j=size; j<nr+1; ++j)
				newtabpoly[j]=0;
			size = nr+1;
			swap(tabpoly, newtabpoly);	
			delete [] newtabpoly;		
		}


		return tabpoly [nr];

	};
	
	double operator() (double x) //funktor klasy, wartosc wielomianu w pkt
	{
		double wyn=0;
		
		for(unsigned int i=0; i< size; ++i)
		{
			wyn += this->tabpoly[i] * pow(x, i);
		}
		
		return wyn;
	}

	friend ostream & operator << (ostream & s, const poly &p) // wyswietlanie
	{
		
		for(unsigned int i=0; i<p.size; ++i)
		{
			if (p.tabpoly[i]!=0)
			{
				if(i==0) //wyswietlanie stopnia 0
				{
					s << p.tabpoly[i];					
				}	 
				else if(i==1)  //wyswietlanie stopnia 1
				{
					s << " + " << p.tabpoly[i]<<"x";				
				}
	
				else // wyswietlanie stopnia > 1
				{
					s << " + "<< p.tabpoly[i]<<"x^"<< i;				
				}
		   	}
		}
		return s;
	};


	poly operator+ (const poly& p) //sumowanie wielomianow
	{
		poly Poly;
		
		for(unsigned int i=0; i<this->size; ++i)
				Poly[i] = this->tabpoly[i];
		
		for(unsigned int i=0; i<p.size; ++i)
				Poly[i] += p.tabpoly[i];

		return Poly;
	};
	friend poly operator* (const poly& p1, const poly &p2) //mno¿enie wielomianów 
		{
			poly Poly;
			for(unsigned int i=0; i<p1.size; ++i)
			{	
				for(unsigned int n=0; n<p2.size; n++)
							Poly[i+n] += p2.tabpoly[n] * p1.tabpoly[i];
			}


			return Poly;
		}
	
};


