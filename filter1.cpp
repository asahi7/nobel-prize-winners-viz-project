#include <iostream>

using namespace std;

int main(){
    freopen("data.csv", "r", stdin);
    string str;
    int ln = 1;
    while(getline(cin, str)){
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(' || str[i] == ')'){
                cout << ln << endl;
                break;
            }
        }
        ln++;
    }
    return 0;
}
