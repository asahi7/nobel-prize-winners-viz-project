#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std;

// first string before comma - name
// second string before second comma - country (check through the list of all countries and if not present than potential problem)
// third string - study field (compare with other fields)
// fourth - year (check if numerical)

// output the line of potential problem in data.csv

string remove_spaces(string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

string get_str_after_comma(int pos, string& str){
    int cnt = 0;
    string res = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ','){
            cnt++;
            if(cnt == pos + 1) break;
            continue;
        }
        if(cnt >= pos){
            res += str[i];
        }
    }
    res = remove_spaces(res);
    return res;
}

int main(){
    freopen("data.csv", "r", stdin);
    string str[2000], countries[2000];
    int n = 0;
    while(getline(cin, str[n])){
        countries[n] = get_str_after_comma(1, str[n]);
        n++;
    }
    fclose(stdin);
    /*ofstream new_data("data1.csv");
    for(int i = 0; i < n; i++){
        bool found = 0;
        if(str[i] == "\0") continue;
        for(int j = 0; j < n; j++){
            if(i != j && str[j] != "\0" && get_str_after_comma(0, str[i]) == get_str_after_comma(0, str[j])){
                found = 1;
                cout << j << " " << str[j] << " " << str[i] << endl;
                str[j] = "\0";
                break;
            } 
        }
        if(str[i] != "\0") new_data << str[i] << endl;
    }*/
    ifstream in("countries.txt");
    ofstream out("problem.txt");
    string countries_cor[300];
    int l = 0;
    while(getline(in, countries_cor[l])){
        countries_cor[l] = remove_spaces(countries_cor[l]);
        //cout << countries_cor[l] << endl;
        l++;
    }
    for(int i = 0; i < n; i++){
        bool found = 0;
        for(int j = 0; j < l; j++){
            if(countries[i] == countries_cor[j]){
                found = 1;
            }
        }
        if(found == false){
                out << i + 1 << endl;
        }
    }
    return 0;
}
