#include <iostream>

#include <json.h>

using namespace std;
using namespace json;

int main() {
    string path = DATA_PATH "dummy.json";

    vector<string> v;
    v.push_back(path);

    // Single file parsing
    json::Value val_sing = Parser::ParseFile(path);

    // Multiple files parsing
    json::Value val_mul = Parser::ParseMultiple(v);

    return 0;
}


