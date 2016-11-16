#include <iostream>

using namespace std;

string str;

// 131

int main(){
    int l = 1; 
    freopen("data.csv", "r", stdin);
    freopen("data1.csv", "w", stdout);
    int cnt = 0;
while(getline(cin, str)){
        cnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ',') cnt++;
        }
        if(cnt > 3){
            cerr << l << endl;
            int sec = -1, com = 0;
            for(int i = 0; i < str.length(); i++){
                if(str[i] == ','){
                    com++;
                    if(com == 2){
                        sec = i;
                        int fir_non_empt;
                        for(int j = i; j < str.length(); j++){
                            if((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')){
                                fir_non_empt = j;
                                break;
                            }
                        }
                        str.erase(sec + 1, (fir_non_empt - sec - 1));
                        str.insert(sec + 1, " ");
                        break;
                    }
                }
            }
        }
        cout << str << endl; 
        l++;
    }
}
