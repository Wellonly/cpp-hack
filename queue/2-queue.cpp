#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
using std::string;
using std::cin;
using std::cout;
 
int main() {
    const uint minsum = 500;
    uint n = 4;
    cin >> n;
    if (n<1 || n >=20000) return 1;
    if (n == 1) {
      cout << minsum;
      return 0;
    }

    uint rating[20000] = {}; //{4,2,3,3}:3000; //{5,5,5,5}:2000; //{1,2,3,4}:5000;

    for (uint i = 0; i< n; i++) {
      cin >> rating[i];
    }

    uint prevrate = rating[0];
    uint prevsum = rating[1] < prevrate ? minsum*2: minsum;
    unsigned long long result = prevsum;
    for (uint i = 1; i < n; i++) {
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
    cout << result;
    return 0;
}

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

Пример 1
Ввод
4
1
2
3
4
Вывод
5000
Пример 2
Ввод
4
5
5
5
5
Вывод
2000
Пример 3
Ввод
4
4 500->1000
2 1000-> 500
3 1000
3 500
Вывод
3000
Примечание
Водители в очереди стоят строго друг за другом, циклов в ней нет

Ограничение памяти
64.0 Мб
Ограничение времени
1 с
Ввод
стандартный ввод или input.txt
Вывод
стандартный вывод или output.txt

*/