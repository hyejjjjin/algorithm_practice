#include <iostream>
#include <vector>
using namespace std;

int N, a, b;
vector<int> res;

int minRes(n){
  if(res[n]<0){
  if (a < n)
  {
    if (b < n)
    {
      res[n] = 1 + minRes(n-1-b);
    }
    else
    {
      res[n] = 1 + minRes(n-1-a);
    }
  } else {
    res[n] = n;
  }
  }
  return res[n];
}

int main()
{
  cin >> N, a, b;
  if (a > b)
  {
    int tmp = a;
    a = b;
    b = tmp;
  }
  res.resize(N + 1, -1);
  cout<<minRes(N);
}
