#include <iostream>
#include <string>

using namespace std;

int main(){
    string binary_string;
    cin >> binary_string;
    for(int i = 0; i < binary_string.size();){
        int k = i;
        while(k < binary_string.size() && binary_string[k] == binary_string[i]){
            k++;
        }
        if((k - i) > 6){
            cout << "YES" << endl;
            return 0;
        }
        i = k;
    }
    cout << "NO" << endl;
}