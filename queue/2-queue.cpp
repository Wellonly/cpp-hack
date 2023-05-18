#include <algorithm>
#include <iostream>
#include <vector>

#define TEST_ONLY //To compile as application comment out this line! ..or change it by a config.h file!

#ifdef TEST_ONLY
#include "catch.hpp"
#endif

using namespace std;

class Solution
{
public:
  const uint minpay = 500;
  unsigned long long solve(uint length, const vector<uint>& rating) {
    if (length < 1 || length >= 20000) return 0;
    const uint minsum = 1;
    if (length == 1) {
      return minsum;
    }
    uint prevrate = rating[0];
    uint prevsum = rating[1] < prevrate ? minsum*2: minsum;
    uint result = prevsum;
    for (uint i = 1; i < length; i++) {
      uint manrate = rating[i];
      uint sum;
      if (manrate > prevrate) {
        sum = prevsum+minsum;
      }
      else if (manrate <= prevrate) {
        sum = max(minsum, prevsum-minsum);
      }
      else {
        sum = minsum;
      }
      prevrate = manrate;
      prevsum = sum;
      result += sum;
    }
    return result*minpay;
  }
};

#ifndef TEST_ONLY
int main() {
    Solution sol;
    vector<uint> rating;
    uint count = 4;
    cout << "Введите размер очереди 1..20000:";
    cin >> count;
    if (count<1 || count >=20000) { cout << "out of range:" << count << endl; return 1; }

    for (uint i = 0; i< count; i++) {
      cout << "Введите рейтинг 0 <= Rn < 4096 для очереди:" << i+1 << " из " << count << ":" << endl;
      uint rate;
      cin >> rate;
      rating.push_back(rate);
    }

    cout << "Результат:" << sol.solve(rating.size(), rating);
    return 0;
}
#else
TEST_CASE("human queue with ratings", "[tests]")
{
    Solution solution;

    SECTION("Sample Input#1")
    {
      REQUIRE(solution.solve(4, {4,2,3,3}) == 3000);
    }
    SECTION("Sample Input#2")
    {
      REQUIRE(solution.solve(4, {5,5,5,5}) == 2000);
    }
    SECTION("Sample Input#3")
    {
      REQUIRE(solution.solve(4, {1,2,3,4}) == 5000);
    }
}
#endif

/*
Водители Яндекс.Такси узнали о раздаче бонусов и выстроились перед офисом. У каждого водителя есть рейтинг. Необходимо раздать водителям бонусы, соблюдая следующие условия:

• Сумма бонуса кратна 500 рублям.

• Каждый водитель должен получить как минимум 500 рублей.

• Водитель с бóльшим рейтингом должен получить бóльшую сумму бонуса, чем его соседи слева или справа с меньшим рейтингом.

Какое минимальное количество денег потребуется на бонусы?

Формат ввода
На первой строчке записано число N (1 <= N <= 20000), далее следует N строчек с рейтингами водителей Rn (0 <= Rn < 4096)

Формат вывода
Ответ должен содержать минимально необходимое количество денег для выплаты вознаграждений

*/