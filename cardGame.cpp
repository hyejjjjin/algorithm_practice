#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Card
{
  char color;
  int number;
  bool operator<(Card b)
  {
    return number > b.number;
  }
};

vector<Card> hand(5);
vector<int> num;
vector<int> cnt;
int maxCnt = 0;

/* 문제를 잘못 이해했다....ㅜㅠ 
 * 다시 풀자 */

bool checkColors()
{
  char c = hand[0].color;
  for (int i = 1; i < 5; ++i)
    if (hand[i].color != c)
      return false;
  return true;
}

void checkNumbers(int a, int b)
{
  if (hand[a].number == hand[b].number && b < 5)
  {
    checkNumbers(a, b + 1);
  }
  else
  {
    int res = b - a;
    num.push_back(hand[a].number);
    cnt.push_back(res);
    if (maxCnt < res)
      maxCnt = res;
    if (b < 5)
      checkNumbers(b, b + 1);
  }
}

int checkCards()
{
  sort(hand.begin(), hand.end());
  bool colors = checkColors();
  checkNumbers(0, 1);

  if (colors)
  {
    if (num[0] == num[4] + 4)
      return 900 + num[0];
    return 600 + num[0];
  }
  else if (num.size() == 2)
  {
    for (int i = 0; i < 2; ++i)
    {
      if (cnt[i] == 4)
        return 800 + num[i];
      else if (cnt[i] == 3)
        return 700 + num[i] * 10 + num[!i];
    }
  }
  else if (num.size() == 5 && num[0] == num[4] + 4)
    return 500 + num[0];
  else if (maxCnt == 3)
  {
    for (int i = 0; i < 3; ++i)
    {
      if (cnt[i] == 3)
        return 400 + num[i];
    }
  }
  else if (maxCnt == 2)
  {
    int a = -1;
    for (int i = 0; i < 5; ++i)
    {
      if (cnt[i] == 2)
      {
        if (a > 0)
        {
          if (a < num[i])
            return 300 + num[i] * 10 + a;
          else
            return 300 + a * 10 + num[i];
        }
        else
          a = num[i];
      }
    }
    return 200 + a;
  }

  return 100 + num[0];
}

int main()
{
  for (int i = 0; i < 5; ++i)
    cin >> hand[i].color >> hand[i].number;

  cout << checkCards();

  return 0;
}