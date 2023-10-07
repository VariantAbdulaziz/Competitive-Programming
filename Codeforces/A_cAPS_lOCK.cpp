#include <string>
#include <iostream>

using namespace std;

int main(){
    string sentence;
    cin >> sentence;

    for(int i = 0; i < sentence.size(); i++){
        int k = i, hi = 0;
        while(k < sentence.size() && sentence[k] != ' '){
            hi += isupper(sentence[k]);
            k++;
        }
        if((k - i - 1) == hi && islower(sentence[i])){
            sentence[i] = toupper(sentence[i]);
            i++;
            while(i < k){
                sentence[i] = tolower(sentence[i]);
                i++;
            }
        } else if((k - i) == hi) {
            sentence[i] = tolower(sentence[i]);
            i++;
            while(i < k){
                sentence[i] = tolower(sentence[i]);
                i++;
            }
        } else i = k;
    }
    cout << sentence << endl;
}