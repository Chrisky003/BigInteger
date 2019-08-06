#pragma once
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 20001;

int cmp(string a, string b) {
    if (a.size() > b.size()) {
        return 1;
    }
    else if (a.size() < b.size()) {
        return -1;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) {
            return 1;
        }
        else if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

string add(string a, string b) {
    int la, lb, lm;
    la = a.size();
    lb = b.size();
    string ans;
    int ia[MAX] = {0}, ib[MAX] = {0};
    for (int i = 0; i < la; i++) {
        ia[la - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < lb; i++) {
        ib[lb - 1 - i] = b[i] - '0';
    }
    lm = la > lb ? la : lb;
    for (int i = 0; i < lm; i++) {
        ia[i] += ib[i];
        ia[i + 1] += ia[i] / 10;
        ia[i] %= 10;
    }
    if (ia[lm]) {
        lm++;
    }
    for (int i = lm - 1; i >= 0; i--) {
        ans += ia[i] + '0';
    }
    return ans;
}

string sub(string a, string b) {
    string ans;
    if (cmp(a, b) == -1) {
        ans = sub(b, a);
        ans.insert(0, "-");
        return ans;
    }
    int la, lb, lm;
    la = a.size();
    lb = b.size();
    int ia[MAX] = {0}, ib[MAX] = {0};
    for (int i = 0; i < la; i++) {
        ia[la - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < lb; i++) {
        ib[lb - 1 - i] = b[i] - '0';
    }
    lm = la > lb ? la : lb;
    for (int i = 0; i < lm; i++) {
        ia[i] -= ib[i];
        if (ia[i] < 0) {
            ia[i] += 10;
            ia[i + 1]--;
        }
    }
    while (!ia[--lm] && lm > 0) {
    }
    lm++;
    for (int i = lm - 1; i >= 0; i--) {
        ans += ia[i] + '0';
    }
    return ans;
}

string _mul(string a, char b) {
    string ans;
    int ia[MAX] = {0};
    b -= '0';
    int la = a.size();
    for (int i = 0; i < la; i++) {
        ia[la - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i <= la; i++) {
        ia[i] *= b;
        if (i > 0) {
            ia[i] += ia[i - 1] / 10;
            ia[i - 1] %= 10;
        }
    }
    if (ia[la]) {
        la++;
    }
    for (int i = la - 1; i >= 0; i--) {
        ans += ia[i] + '0';
    }
    return ans;
}

string mul(string a, string b) {
    string ans;
    if (a.size() < b.size()) {
        return mul(b, a);
    }
    string str[b.size()];
    for (int i = 0; i < b.size(); i++) {
        str[i] = _mul(a, b[b.size() - i - 1]);
        for (int j = 0; j < i; j++) {
            str[i].push_back('0');
        }
    }
    ans = "0";
    for (int i = 0; i < b.size(); i++) {
        ans = add(ans, str[i]);
    }
    return ans;
}

/*     商      余数 */
pair<string, string> div(string a, string b) {
    pair<string, string> ans;
    string &ansa = ans.first;
    string &ansb = ans.second;
    int la = a.size(), lb = b.size();
    if (cmp(a, b) < 0) {
        ansa = "0";
        ansb = a;
    }
    int ia[MAX] = {0}, ib[MAX] = {0};
    for (int i = 0; i < la; i++) {
        ia[la - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < lb; i++) {
        ib[lb - 1 - i] = b[i] - '0';
    }
    int t = la - lb;
    for (int i = 0; i < t; i++) {
        b.push_back('0');
    }
    lb = la;
    for (int i = 0; i <= t; i++) {
        int temp = 0;
        while (cmp(a, b) >= 0) {
            a = sub(a, b);
            temp++;
        }
        ansa += temp + '0';
        b.pop_back();
    }
    ansb = a;
    string::iterator iter = ansa.begin();
    while (*iter == '0') {
        iter++;
    }
    iter = copy(iter, ansa.end(), ansa.begin());
    ansa.erase(iter, ansa.end());
    return ans;
}
