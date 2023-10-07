#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, curr; cin >> n;
    vector<int> freq(6);
    map<int, int> mapping = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
    int result = 0;

    while(cin >> curr){
        auto _min = min_element(begin(freq), begin(freq) + mapping[curr]);
        if(curr == 4 || freq[mapping[curr]] < *_min)
            freq[mapping[curr]]++;
        else
            result++;
    }
    int _min = *min_element(begin(freq), end(freq));
    for(int i=0; i<6; i++){
        result += freq[i] - _min;
    }
    cout << result << endl;
}