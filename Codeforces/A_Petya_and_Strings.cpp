#include <string>
#include <iostream>


using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < min(b.size(), a.size()); i++){

        if(tolower(a[i]) > tolower(b[i])){
            cout << 1 << endl;
            return 0;
        }
        else if(tolower(a[i]) < tolower(b[i])){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}