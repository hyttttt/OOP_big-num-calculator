#include "Decimal.h"

using namespace std;
Decimal& Decimal::About_minutes(string l, string s) {
    Decimal result;
    result.numerator=l;
    result.denominator = s;
    if (l == "1" || s == "1") {
        return result;
    }
    while (l != "1" && s != "1") {
        if (l.size() > s.size()) {
            l = BigNumMinus(l, s);
        }
        else if (l.size() < s.size()) {
            s = BigNumMinus(s, l);
        }
        else {
            if (l < s) {
                s = BigNumMinus(s, l);
            }
            else if (s < l) {
                l = BigNumMinus(l, s);
            }
            else if (s == l) {
                result.numerator = BigNumDivision(result.numerator, l);
                result.denominator = BigNumDivision(result.denominator, s);
                return result;
            }

        }

    }
    return result;
};



string Decimal::BigNumAdd(string l, string s) { //l means the longer one value, s means the shorter one.
    if (l == "0" && s == "0") {
        return "0";
    }
    else if (l == "0") {
        return s;
    }
    else if (s == "0") {
        return l;
    }
    bool IfequalMinus = false, IfNeg = false;
    string res;
    if (l[0] == '-' && s[0] == '-') { IfNeg = true; l.erase(l.begin()); s.erase(s.begin()); }
    if (l[0] == '-' && s[0] != '-') { l.erase(l.begin()); return Decimal::BigNumMinus(s, l); }
    if (l[0] != '-' && s[0] == '-') { s.erase(s.begin()); return Decimal::BigNumMinus(l, s); }
    if (IfequalMinus) { return BigNumMinus(l, s); }
    if (l.length() < s.length()) { swap(l, s); }
    reverse(l.begin(), l.end()), reverse(s.begin(), s.end());
    bool IfTwoStrSameLeng = false;
    if (l.length() == s.length()) {
        IfTwoStrSameLeng = true;
    }
    bool IfNeedCarry = false;
    for (int str_cnt = 0; str_cnt < s.size(); str_cnt++) {
        int int_l = l[str_cnt] - '0', int_s = s[str_cnt] - '0';
        if (IfNeedCarry) { int_l += int_s + 1; }
        else { int_l += int_s; }
        if (int_l >= 10) {
            IfNeedCarry = true;
            int_l %= 10;
        }
        else {
            IfNeedCarry = false;
        }
        res.insert(res.begin(), (int_l + '0'));
    }
    if (IfNeedCarry && IfTwoStrSameLeng) { res.insert(res.begin(), '1'); }
    if (!IfTwoStrSameLeng) {
        for (int str_cnt = s.size(); str_cnt < l.size(); str_cnt++) {
            int int_l = l[str_cnt] - '0';
            if (IfNeedCarry) { int_l += 1; }
            if (int_l >= 10) {
                IfNeedCarry = true;
                int_l %= 10;
            }
            else {
                IfNeedCarry = false;
            }
            res.insert(res.begin(), (int_l + '0'));
        }
        if (IfNeedCarry) { res.insert(res.begin(), '1'); }
    }
    if (IfNeg) { res.insert(res.begin(), '-'); return res; }
    else return res;
};

string Decimal::BigNumMinus(string l, string s) {
    if (l == "0" && s == "0") {
        return "0";
    }
    else if (l == "0") {
        if (s[0] == '-') s.erase(s.begin());
        else s.insert(s.begin(), '-');
        return s;
    }
    else if (s == "0") {
        return l;
    }
    string res;
    bool IfTwoBigNumNeg = false, IfTwoBigNumSwitch = false;
    if (l[0] != '-' && s[0] == '-') { s.erase(s.begin()); return Decimal::BigNumAdd(l, s); }
    else if (l[0] == '-' && s[0] != '-') { s.insert(s.begin(), '-'); return Decimal::BigNumAdd(l, s); }
    if (l[0] == '-' && s[0] == '-') { l.erase(l.begin()); s.erase(s.begin()); IfTwoBigNumNeg = true; } //???t????
    if (l.length() < s.length()) { swap(l, s); IfTwoBigNumSwitch = true; }
    else if (l.length() == s.length()) {
        for (int str_cnt = 0; str_cnt < l.size(); str_cnt++) {
            if (l[str_cnt] == s[str_cnt]) { continue; }
            if (l[str_cnt] < s[str_cnt]) { swap(l, s); IfTwoBigNumSwitch = true; break; }
            if (l[str_cnt] > s[str_cnt]) { ; break; }
        }
    }
    reverse(l.begin(), l.end()), reverse(s.begin(), s.end());
    bool IfNeedBorrow = false;
    for (int str_cnt = 0; str_cnt < s.length(); str_cnt++) {
        int int_l = l[str_cnt] - '0', int_s = s[str_cnt] - '0';
        if (IfNeedBorrow == true) { int_l -= 1; }
        int_l -= int_s;
        if (int_l < 0) {
            int_l += 10;
            IfNeedBorrow = true;
        }
        else {
            IfNeedBorrow = false;
        }
        res.insert(res.begin(), (int_l + '0'));
    }
    for (int str_cnt = s.length(); str_cnt < l.length(); str_cnt++) {
        int int_l = l[str_cnt] - '0';
        if (IfNeedBorrow == true) {
            int_l -= 1;
        }
        if (int_l < 0) {
            int_l += 10;
            IfNeedBorrow = true;
        }
        else {
            IfNeedBorrow = false;
        }
        res.insert(res.begin(), (int_l + '0'));
    }
    for (int str_cnt = 0; str_cnt < res.size(); str_cnt++) {
        if (res[str_cnt] != '0') {
            res = res.substr(res.find_first_not_of('0'));
            if (IfTwoBigNumNeg ^ IfTwoBigNumSwitch) { res.insert(res.begin(), '-'); }
            return res;
        }
    }
    return "0";
}
string Decimal::BigNumMultiply(string l, string s) {
    bool IfNeg = false;
    if (l[0] == '-' && s[0] != '-') { IfNeg = true; l.erase(l.begin()); }
    if (l[0] != '-' && s[0] == '-') { IfNeg = true; s.erase(s.begin()); }
    if (l[0] == '-' && s[0] == '-') { l.erase(l.begin()); s.erase(s.begin()); }
    string res;
    int len_l = l.length(), len_s = s.length();
    int Arr_row = len_l * len_s;
    int Arr_col = len_l + 1;
    int** table;
    table = new int* [Arr_col];
    for (int i = 0; i < Arr_col; i++) {
        table[i] = new int[Arr_row];
    }
    reverse(l.begin(), l.end()), reverse(s.begin(), s.end());
    for (int i = 0; i < Arr_col; i++) {
        for (int j = 0; j < Arr_row; j++) {
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < Arr_col - 1; i++) {
        int tmp = l[i] - '0';
        for (int j = i; j < len_s + i; j++) {
            int t = s[j - i] - '0';
            table[i][j] = tmp * t;
        }
    }
    for (int i = 0; i < Arr_col - 1; i++) {
        for (int j = 0; j < Arr_row; j++) {
            table[Arr_col - 1][j] += table[i][j];
        }
    }
    for (int j = 0; j < Arr_row - 1; j++) {
        if (table[Arr_col - 1][j] >= 10) {
            table[Arr_col - 1][j + 1] += (table[Arr_col - 1][j] / 10);
            table[Arr_col - 1][j] %= 10;
        }
    }


    for (int i = 0; i < Arr_row; i++) {
        res.push_back((table[Arr_col - 1][i] + '0'));
    }
    reverse(res.begin(), res.end());
    if (res.find_first_not_of('0') == string::npos) {
        return "0";
    }
    res = res.substr(res.find_first_not_of('0'));
    if (IfNeg) { res.insert(res.begin(), '-'); }
    return res;
}
bool Decimal::DivJudgement(string l, string r) {
    if (r.length() > l.length()) {
        return false;
    }
    else if (l.length() > r.length()) {
        return true;
    }
    else {
        for (int str_cnt = 0; str_cnt < l.size(); str_cnt++) {
            if (l[str_cnt] == r[str_cnt]) { continue; }
            if (l[str_cnt] < r[str_cnt]) { return false; }
            if (l[str_cnt] > r[str_cnt]) { return true; }
        }
        return true;
    }
}
string Decimal::BigNumDivision(string l, string r) {
    if (r == "0") return "Nonsense";
    if (l == "0") return "0";
    string tmp = "", res = "0";
    bool IfNeg = false;
    if (l[0] == '-' && r[0] != '-') { IfNeg = true; l.erase(l.begin()); }
    if (l[0] != '-' && r[0] == '-') { IfNeg = true; r.erase(r.begin()); }
    if (l[0] == '-' && r[0] == '-') { l.erase(l.begin()); r.erase(r.begin()); }
    int tmp_cnt = 0;
    while (tmp_cnt < l.size()) {

        tmp.push_back(l[tmp_cnt]);
        string append = "0";
        if (DivJudgement(tmp, r) == true) {
            while (DivJudgement(tmp, r) == true) {
                tmp = BigNumMinus(tmp, r);
                append = BigNumAdd(append, "1");
            }
            res.append(append);
            if (tmp == "0") tmp.clear();
            tmp_cnt++;
        }
        else {
            if (tmp == "0") tmp.clear();
            res.append(append);
            tmp_cnt++;
        }
    }
    for (int str_cnt = 0; str_cnt < res.size(); str_cnt++) {
        if (res[str_cnt] != '0') {
            res = res.substr(res.find_first_not_of('0'));
            if (IfNeg) {
                res = "-" + res;
            }
            return res;
        }
    }

    return "0";
}