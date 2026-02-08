#include<bits/stdc++.h>
using namespace std;
string s;
int n, cash, a, b;

void swapf (int &count)
{
  int i;

  for (int a = 0; a < s.length (); a++) 
  if (s[a] == '1') 
  { 
      i = a; 
      break; 
      
  } 
  int j = s.length () - 1; 
  while (j > i)
    {
      if (cash < a)
	break;

      if (s[j] == '0')
	{
	  if (s[i] == '0')
	    i++;

	  else
	    {
	      swap (s[i], s[j]);
	      cash -= a;
          count++;
	      j--;
	    }
	}
      else
	j--;
    }
}
void flipf (int &count)
{
  int i;
  for (int a = 0; a < s.length (); a++) 
  if (s[a] == '1') 
  { 
      i = a; break; 
      
  } 
  while (cash >= b)
    {

      if (i == s.length ())
      break;

      if (s[i] == '1')
	{
	  s[i] = '0';
	  i++;
	  cash -= b;
      count++;
	}
    }
}

int main ()
{
  cin >> n >> s >> cash >> a >> b;
  int count=0;

  if (a < b)
    {
      swapf (count);
      flipf (count);
    }

  else
    {
      flipf (count);
      swapf (count);
    }

  cout <<count;

}