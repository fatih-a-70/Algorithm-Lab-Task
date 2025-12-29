#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> rub(4, vector<pair<ll, ll>>(4));

void print()
{
  cout << "\nprinting (rotating s2->s1->s2-opposite->s1-opposiote)\n\n";

  cout << "output s2:\n";
  cout << rub[0][3].first << " " << rub[0][3].second << endl
       << rub[1][3].first << " " << rub[1][3].second << endl;

  cout << "outpt  s1:\n";
  cout << rub[0][0].first << " " << rub[0][0].second << endl
       << rub[1][0].first << " " << rub[1][0].second << endl;

  cout << "output s2 oppsite:\n";
  cout << rub[0][1].first << " " << rub[0][1].second << endl
       << rub[1][1].first << " " << rub[1][1].second << endl;

  cout << "output s1 oppsite:\n";
  cout << rub[0][2].first << " " << rub[0][2].second << endl
       << rub[1][2].first << " " << rub[1][2].second << endl;

  cout << "output s3:\n";
  cout << rub[2][1].first << " " << rub[3][1].first << endl
       << rub[2][1].second << " " << rub[3][1].second << endl;

  cout << "output s3 oppsite:\n";
  cout << rub[2][3].first << " " << rub[3][3].first << endl
       << rub[2][3].second << " " << rub[3][3].second << endl;
}

void print_1()
{
  cout << "\nprinting (rotating s3->s1->s3-opposite->s1-opposiote)\n\n";

  cout << "output s3:\n";
  cout << rub[2][1].first << " " << rub[3][1].first << endl
       << rub[2][1].second << " " << rub[3][1].second << endl;

  cout << "outpt  s1:\n";
  cout << rub[0][0].first << " " << rub[0][0].second << endl
       << rub[1][0].first << " " << rub[1][0].second << endl;

  cout << "output s3 oppsite:\n";
  cout << rub[2][3].first << " " << rub[3][3].first << endl
       << rub[2][3].second << " " << rub[3][3].second << endl;

  cout << "output s1 oppsite:\n";
  cout << rub[1][2].second << " " << rub[1][2].first << endl
       << rub[0][2].second << " " << rub[0][2].first << endl;

  cout << "output s2:\n";
  cout << rub[0][3].first << " " << rub[0][3].second << endl
       << rub[1][3].first << " " << rub[1][3].second << endl;

  cout << "output s2 oppsite:\n";
  cout << rub[0][1].first << " " << rub[0][1].second << endl
       << rub[1][1].first << " " << rub[1][1].second << endl;
}

void right()
{
  print();
  cout << "\nright\n";

  pair<ll, ll> p = rub[0][3];

  for (int i = 3; i > 0; i--)
    rub[0][i] = rub[0][i - 1];

  rub[0][0] = p;

  auto px = rub[2][1];
  rub[2][1] = {rub[3][1].first, rub[2][1].first};
  rub[3][1] = {rub[3][1].second, px.second};

  rub[2][2].second = rub[3][0].first;
  rub[3][2].second = rub[2][0].first;

  rub[3][0].first = rub[0][0].second;
  rub[2][0].first = rub[0][0].first;

  print();
}

void down()
{
  print_1();
  cout << "\ndown\n";

  pair<ll, ll> p = rub[3][0];

  for (int i = 0; i < 3; i++)
    rub[3][i] = rub[3][i + 1];

  rub[3][3] = p;

  auto px = rub[0][1];
  rub[0][1] = {rub[0][1].second, rub[1][1].second};
  rub[1][1] = {px.first, rub[1][1].first};

  rub[0][0].second = rub[3][0].first;
  rub[1][0].second = rub[3][0].second;

  rub[0][2].first = rub[3][2].second;
  rub[1][2].first = rub[3][2].first;

  print_1();
}

void left()
{
  print();
  cout << "\nleft\n";

  pair<ll, ll> p = rub[1][0];

  for (int i = 0; i < 3; i++)
    rub[1][i] = rub[1][i + 1];

  rub[1][3] = p;

  auto px = rub[2][3];
  rub[2][3] = {rub[3][3].first, rub[2][3].first};
  rub[3][3] = {rub[3][3].second, px.second};

  rub[2][2].first = rub[3][0].second;
  rub[3][2].first = rub[2][0].second;

  rub[2][0].second = rub[1][0].first;
  rub[3][0].second = rub[1][0].second;

  print();
}

void up()
{
  print_1();
  cout << "\nup\n";

  pair<ll, ll> p = rub[2][3];

  for (int i = 3; i > 0; i--)
    rub[2][i] = rub[2][i - 1];

  rub[2][0] = p;

  auto px = rub[0][3];
  rub[0][3] = {rub[0][3].second, rub[1][3].second};
  rub[1][3] = {px.first, rub[1][3].first};

  rub[0][0].first = rub[2][0].first;
  rub[1][0].first = rub[2][0].second;

  rub[0][2].second = rub[2][2].second;
  rub[1][2].second = rub[2][2].first;

  print_1();
}

bool check()
{

  if (rub[0][0] == rub[1][0] && rub[0][1] == rub[1][1] && rub[0][2] == rub[1][2] && rub[0][3] == rub[1][3] && rub[2][1] == rub[3][1] && rub[2][3] == rub[3][3])
  {
    return true;
  }
  return false;
}

string s;

bool f()
{
  if (check())
    return true;

  auto temp = rub;

  right();
  if (f())
  {
    s += "right ";
    return true;
  }
  rub = temp;

  down();
  if (f())
  {
    s += "down ";
    return true;
  }
  rub = temp;

  up();
  if (f())
  {
    s += "up ";
    return true;
  }
  rub = temp;

  left();
  if (f())
  {
    s += "left ";
    return true;
  }
  rub = temp;

  return false;
}
int main()
{

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cout << "roll : 2207063 , 2207067 , 2207070 " << endl;
  cout << "\nRIGHT moves upper row of s1 to right:\n";
  cout << "LEFT moves lower row of s1 to left:\n";
  cout << "UP moves first column of s1 to up:\n";
  cout << "DOWN moves second column s1 to down:\n\n";

  cin >> rub[0][0].first >> rub[0][0].second >> rub[1][0].first >> rub[1][0].second;

  rub[2][0].first = rub[0][0].first;
  rub[2][0].second = rub[1][0].first;
  rub[3][0].first = rub[0][0].second;
  rub[3][0].second = rub[1][0].second;

  cin >> rub[0][2].first >> rub[0][2].second >> rub[1][2].first >> rub[1][2].second;

  rub[2][2].first = rub[0][2].first;
  rub[2][2].second = rub[0][2].second;
  rub[3][2].first = rub[1][2].first;
  rub[3][2].second = rub[1][2].second;

  cin >> rub[0][3].first >> rub[0][3].second >> rub[1][3].first >> rub[1][3].second;

  cin >> rub[0][1].first >> rub[0][1].second >> rub[1][1].first >> rub[1][1].second;

  cin >> rub[2][1].first >> rub[3][1].first >> rub[2][1].second >> rub[3][1].second;

  cin >> rub[2][3].first >> rub[3][3].first >> rub[2][3].second >> rub[3][3].second;

  print();
  right();
  left();
  up();
  down();

  //  f();
  print();
  print_1();
  cout << s << endl;
}
/* input
1 2 5 5 4 6 3 3 2 2 1 1 4 4 3 5 6 2 3 1 4 6 6 5
*/