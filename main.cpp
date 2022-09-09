#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(n) space
string runLengthEncoding(string &str) {
    vector<char> encoded;// O(n) space
    int counter = 1;
    for(int i = 1; i < str.length(); i++) {// O(n) time
        if(str[i] != str[i - 1] || counter == 9) {
            encoded.push_back(to_string(counter)[0]);
            encoded.push_back(str[i - 1]);
            counter = 0;
        }
        counter++;
    }
    encoded.push_back(to_string(counter)[0]);
    encoded.push_back(str[str.length() - 1]);
    return string(encoded.begin(), encoded.end());
}

int main() {
    string input = "[(aaaaaaa,bbbbbbb,ccccc,dddddd)]";
    cout << runLengthEncoding(input);
    return 0;
}
