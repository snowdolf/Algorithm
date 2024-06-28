#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int day, month, year;
};

bool cmp(Student x, Student y)
{
    if (x.year != y.year)
        return x.year > y.year;
    else if (x.month != y.month)
        return x.month > y.month;
    return x.day > y.day;
}

int n;
vector<Student> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Student stu;
        cin >> stu.name >> stu.day >> stu.month >> stu.year;
        vec.push_back(stu);
    }

    sort(vec.begin(), vec.end(), cmp);

    cout << vec[0].name << "\n"
         << vec[vec.size() - 1].name;

    return 0;
}