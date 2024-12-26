#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    // 发动机的总个数, 计划手动启动的发动机总个数
    int n, e;
    cin >> n >> e;
 
    // 记录每个发动机的最终启动时刻, 初始化为极大值，方便后面取最早启动时刻
    vector<int> launches(n, 2001);
 
    for (int i = 0; i < e; i++) {
        // 发动机的手动启动时刻, 发动机的位置编号
        int t, p;
        cin >> t >> p;
 
        launches[p] = t; // p号发动机在t时刻手动启动
    }
 
    // 从编号 i 的发动机手动启动后, 关联启动到编号 j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 内关联距离
            int innerDis = abs(i - j);
            // 外关联距离
            int outerDis = n - innerDis;
            // 最短关联距离
            int dis = min(innerDis, outerDis);
            launches[j] = min(launches[j], launches[i] + dis);
        }
    }
 
    // 最晚启动时刻
    int maxT = 0;
 
    // 最晚启动的发动机编号集合
    vector<int> last;
 
    for (int p = 0; p < n; p++) {
        int t = launches[p]; // 当前发动机启动时刻
 
        if (t < maxT) continue; // 不是最晚启动的发动机
 
        if (t > maxT) { // 更晚启动的时刻
            maxT = t;
            last.clear();
        }
 
        last.emplace_back(p);  // 记录该发动机编号
    }
 
    sort(last.begin(), last.end());
 
    cout << last.size() << endl;
    for (const auto &p: last) {
        cout << p << " ";
    }
 
    return 0;
}
