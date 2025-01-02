#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int courseSum = 0;
        double gradeSum = 0;
        for(int i = 0; i < n; i++){
            int c;
            double g;
            cin >> c >> g;

            courseSum += c;
            gradeSum += c * g;
        }
        gradeSum = round(gradeSum / courseSum * 10) / 10;

        cout << courseSum << " " << gradeSum << "\n";
    }

    return 0;
}