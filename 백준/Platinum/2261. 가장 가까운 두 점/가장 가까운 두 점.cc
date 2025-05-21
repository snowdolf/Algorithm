#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Point
{
    int x, y;
    bool operator<(const Point &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int dist(const Point &a, const Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int f(vector<Point> &points, int l, int r)
{
    if (r - l <= 3)
    {
        int d = INT_MAX;
        for (int i = l; i < r; i++)
        {
            for (int j = i + 1; j < r; j++)
            {
                d = min(d, dist(points[i], points[j]));
            }
        }
        sort(
            points.begin() + l,
            points.begin() + r,
            [](const Point &a, const Point &b)
            {
                return a.y < b.y;
            }
        );
        return d;
    }

    int m = (l + r) / 2;
    int mx = points[m].x;
    int d = min(f(points, l, m), f(points, m, r));

    vector<Point> tmp;
    merge(
        points.begin() + l, points.begin() + m,
        points.begin() + m, points.begin() + r,
        back_inserter(tmp),
        [](const Point &a, const Point &b)
        {
            return a.y < b.y;
        }
    );
    copy(tmp.begin(), tmp.end(), points.begin() + l);

    tmp.clear();
    for (int i = l; i < r; i++)
    {
        if ((points[i].x - mx) * (points[i].x - mx) < d)
        {
            tmp.push_back(points[i]);
        }
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        for (int j = i + 1; j < tmp.size() && (tmp[i].y - tmp[j].y) * (tmp[i].y - tmp[j].y) < d; j++)
        {
            d = min(d, dist(tmp[i], tmp[j]));
        }
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());

    cout << f(points, 0, n);

    return 0;
}