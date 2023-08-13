#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int k;
    cin >> k;
    int count = 0;
    int isPlagiarized = 69;
    for(int i = 0; i < a.size(); i++){
        if(b[i] != a[i]){
            if(a[i] == ' ' || b[i] == ' '){
                isPlagiarized = 0;
                break;
            }else count++;
        }
    }
    if(isPlagiarized == 0)cout << "No plagiarism";
    else if(count > k)cout << "No plagiarism";
    else cout << "Plagiarized";
    return 0;
}