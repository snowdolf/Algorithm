#include <iostream>

using namespace std;

string id, fan = ":fan:";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> id;
    
    cout << fan << fan << fan << "\n";
    cout << fan << ":" << id << ":" << fan << "\n";
    cout << fan << fan << fan << "\n";

    return 0;
}