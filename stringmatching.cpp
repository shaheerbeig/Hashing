#include<iostream>
#include<limits.h>
#include<string>
using namespace std;

bool matchstring(string &text , string &pattern){
    int n = text.length();
    int m = pattern.length();
    int patterncode = 0;
    int textcode = 0;
    int power = 1;
    for(int i=0;i<m;i++){
        //calculating hashcode for the pattern and the part of the text.
        textcode = (textcode * 26 + text[i])%INT_MAX;
        patterncode = (patterncode * 26 + pattern[i])%INT_MAX;

        if(i < m-1){
            power = (power * 26)%INT_MAX;
        }
    }
    //if the patterncode and the textcode matches
    for(int i=0;i<n-m;i++){
        if(textcode == patterncode){
            bool match = true;
            for(int j=0;j<m;j++){
                if(pattern[i+j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if(match == true){
                return true;
            }
        }
        if (i < n - m) {
            textcode = (26 * (textcode - text[i] * power) + text[i + m]) % INT_MAX;
            if (textcode < 0) {
                textcode += INT_MAX; // Ensure the hash value is non-negative
            }
        }    
    }
}

int main(){

    string text = "ababcababcabc";
    string pattern = "abc";

    if (matchstring(text,pattern)) {
        cout << "Pattern found in the text.\n";
    } else {
        cout << "Pattern not found in the text.\n";
    }

    return 0;
}
