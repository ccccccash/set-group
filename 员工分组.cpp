// 1.创建10名员工随机分配部门和工资
// 2.员工信息为姓名和工资,部门分为策划.美术.研发
// 3.分部门显示员工信息
#include <iostream>
#include <string>
using namespace std;
#include <map>
#include <vector>

class Person {
public:
  Person(string name, int income) {
    this->m_name = name;
    this->m_income = income;
  }
  string m_name;
  int m_income;
};

void CreatEmploee(vector<Person> &v) {
  string nameSeed = "ABCDEFGHIJ";
  int income = 0;
  for (int i = 0; i < 10; i++) {
    string name = "员工";
    name += nameSeed[i];
    Person p(name, income);
    v.push_back(p);
  }
}

void RandomIncome(vector<Person> &v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    int income = rand() % 5000 + 5000;
    it->m_income = income;
  }
}

void RandomGroup(vector<Person> &v, multimap<string, Person> &m) {
  string arr[3] = {"策划", "美术", "研发"};
  for (auto it = v.begin(); it != v.end(); it++) {
    int dept = rand() % 3;
    m.insert(make_pair(arr[dept], *it));
  }
}

void ShowEmployee(multimap<string, Person> &m) {
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second.m_name << " " << it->second.m_income
         << endl;
  }
}

int main() {
  srand((unsigned)time(0));
  vector<Person> v;
  CreatEmploee(v);
  RandomIncome(v);
  multimap<string, Person> m;
  RandomGroup(v, m);
  ShowEmployee(m);
}