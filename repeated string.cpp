#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
 char c_to_find = 'a';
    long repeated_qty = 0;
    long size = s.length();

    // Count occurrences of 'a' in the string s
    long count_in_s = std::count(s.begin(), s.end(), c_to_find);

    // Calculate the full repetitions of s within n
    repeated_qty = count_in_s * (n / size);

    // Calculate the remainder of s to be considered
    long remainder = n % size;

    // Count occurrences of 'a' in the remainder substring
    if (remainder != 0) {
        repeated_qty += std::count(s.begin(), s.begin() + remainder, c_to_find);
    }

    return repeated_qty;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
