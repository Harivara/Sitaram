Given a number M in its decimal representation, your task is find the minimum base B such 
that in the representation of M at base B all digits are the same.



#include<bits/stdc++.h>
using namespace std;


bool converted (int M, int base)
{
  int rem = M % base;
  M /= base;

  while (M >= base)
    {
      if (M % base != rem)
	return 0;

      M /= base;
    }

  if (M == rem)
    return 1;

  return 0;
}

int main ()
{
  int M;
  cin >> M;

  int base = 2;

  while (converted (M, base) != 1)
    {
      base++;
    }

  cout << base;

  return 0;
}
Question 8
Asked in Infosys Placement Paper – Sept 2021

Probl