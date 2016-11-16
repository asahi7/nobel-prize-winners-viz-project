#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;
using namespace rapidjson;

int main(){
    FILE* fp = fopen("world_map.json", "rb");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    //cout << d["type"].IsString();
    const Value& features = d["features"];
    assert(features.IsArray());
    for(SizeType i = 0; i < features.Size(); i++){
        cout << " " << features[i]["properties"]["name"].GetString() << endl;
    }
    fclose(fp);
    return 0;
}
