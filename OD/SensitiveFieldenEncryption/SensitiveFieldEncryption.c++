#include <vector>
#include<iostream>

using namespace std;

string solution(string& s, int k) {
    vector<string> commands;

    // 双引号是否处于开启状态
    bool isQuotaOpen = false;

    // 避免收尾操作, s 尾部追加一个 '_' 不影响结果
    s += "_";

    string command;
    for (const auto& c : s) {
        // 如果遇到双引号, 则先将 isQuotaOpen 取反
        if (c == '"') {
            isQuotaOpen = !isQuotaOpen;
        }

        if (c != '_' || isQuotaOpen) {
            // 如果遇到的 c 不是 '_' 或者是双引号里面的 '_', 则此时 c 不是命令字分隔符, 而是命令字一部分
            command += c;
        }
        else if (!command.empty()) {
            // 如果 c 是命令字分隔符, 且 command 命令字不为空, 则命令字被截断
            commands.emplace_back(command);
            // 清空command, 用于下个命令字的收集
            command = "";
        }
    }

    if (k >= commands.size()) {
        // 如果无法找到指定索引的命令字，输出字符串ERROR
        return "ERROR";
    }
    else {
        // 对指定索引的敏感字段进行加密，替换为******（6个*），并删除命令字前后多余的下划线_
        commands[k] = "******";

        string res;
        for (int i = 0; i < commands.size(); i++) {
            res += commands[i];

            if (i < commands.size() - 1) {
                res += "_";
            }
        }

        return res;
    }
}

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    cout << solution(s, k) << endl;

    return 0;
}
