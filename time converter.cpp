#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
 int hour = std::stoi(s.substr(0, 2));
    std::string substring = s.substr(0, s.length() - 2);

    if (s.find("P") != std::string::npos) {
        if (hour == 12) {
            return substring;
        } else {
            hour = 12 + hour;
            return std::to_string(hour) + substring.substr(2);
        }
    } else {
        if (hour == 12) {
            return "00" + substring.substr(2);
        } else {
            return substring;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
