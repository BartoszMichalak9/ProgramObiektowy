#include <iostream>
#include "poly.h"


using namespace std;

int main(void)
{
	poly P1 = 1;				
	P1[1] = 2;
	P1[2] = 3;
	poly P2 = 4;
	P2[1] = 5;
	P2[2] = 6;
	P2[3] = 7;
	P2[4] = 8;	
 



 	cout << "Polynomial P1: " << P1 << endl;

 	cout << "Polynomial P2: " << P2 << endl;

	
  poly P3 = P1  +  P2;						//Add P1 and P2
  cout << "Sum of polynomials P1 and P2: " << P3 << endl;	//Print sum of P1 and P2*/
  poly P4 = P1 * P2;
  cout << "Product of polynomials P1 and P2: " << P4 << endl;	//Print product of P1 and P2*/
  poly P5 =P1 * 2;							//Multiply P1 by 2
  cout << "Polynomial P1 multiplied by 2: " << P5 << endl;	//Print product of P1 and 2*/
  double val = P1(3.14);						//Calculate the value of P1 at point 3.14
  cout << "Value of polynomial P1 at point 3.14: " << val << endl;	//Print the value of P1 at point 3.14

}
