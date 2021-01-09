//
// Created by zeyad-osama on 03/06/2020.
//

#include <json/parsers/Parser.h>
#include <json/common/dataunits/Token.h>
#include <json/utils/Utils.h>

#include <fstream>

using namespace std;

using namespace json;
using namespace json::types;
using namespace json::dataunits;
using namespace json::utils;

vector<Token> Parser::Tokenize(string source) {
    source += " ";
    vector<Token> tokens;
    int index = skip_whitespaces(source, 0);
    while (index >= 0) {
        int next = next_whitespace(source, index);
        string str = source.substr(index, next - index);

        size_t k = 0;
        while (k < str.length()) {
            if (str[k] == '"') {
                size_t tmp_k = k + 1;
                while (tmp_k < str.length() && (str[tmp_k] != '"' || str[tmp_k - 1] == '\\')) tmp_k++;
                tokens.emplace_back(str.substr(k + 1, tmp_k - k - 1), T_STRING);
                k = tmp_k + 1;
                continue;
            }
            if (str[k] == '\'') {
                size_t tmp_k = k + 1;
                while (tmp_k < str.length() && (str[tmp_k] != '\'' || str[tmp_k - 1] == '\\')) tmp_k++;
                tokens.emplace_back(str.substr(k + 1, tmp_k - k - 1), T_STRING);
                k = tmp_k + 1;
                continue;
            }
            if (str[k] == ',') {
                tokens.emplace_back(",", T_COMMA);
                k++;
                continue;
            }
            if (str[k] == 't' && k + 3 < str.length() && str.substr(k, 4) == "true") {
                tokens.emplace_back("true", T_BOOL);
                k += 4;
                continue;
            }
            if (str[k] == 'f' && k + 4 < str.length() && str.substr(k, 5) == "false") {
                tokens.emplace_back("false", T_BOOL);
                k += 5;
                continue;
            }
            if (str[k] == 'n' && k + 3 < str.length() && str.substr(k, 4) == "null") {
                tokens.emplace_back("null", T_NULL);
                k += 4;
                continue;
            }
            if (str[k] == '}') {
                tokens.emplace_back("}", T_CURL_CLOSE);
                k++;
                continue;
            }
            if (str[k] == '{') {
                tokens.emplace_back("{", T_CURL_OPEN);
                k++;
                continue;
            }
            if (str[k] == ']') {
                tokens.emplace_back("]", T_BRACKET_CLOSE);
                k++;
                continue;
            }
            if (str[k] == '[') {
                tokens.emplace_back("[", T_BRACKET_OPEN);
                k++;
                continue;
            }
            if (str[k] == ':') {
                tokens.emplace_back(":", T_COLON);
                k++;
                continue;
            }
            if (str[k] == '-' || (str[k] <= '9' && str[k] >= '0')) {
                size_t tmp_k = k;
                if (str[tmp_k] == '-') tmp_k++;
                while (tmp_k < str.size() && ((str[tmp_k] <= '9' && str[tmp_k] >= '0') || str[tmp_k] == '.'))
                    tmp_k++;
                tokens.emplace_back(str.substr(k, tmp_k - k), T_NUMBER);
                k = tmp_k;
                continue;
            }
            tokens.emplace_back(str.substr(k), T_UNKNOWN);
            k = str.length();
        }

        index = skip_whitespaces(source, next);
    }
    return tokens;
}

Value Parser::ParseJSON(vector<Token> token_vector, int i, int &r) {
    Value current;
    if (token_vector[i].GetType() == T_CURL_OPEN) {
        current.SetType(J_OBJECT);
        int k = i + 1;
        while (token_vector[k].GetType() != T_CURL_CLOSE) {
            string key = token_vector[k].GetValue();
            k += 2; // k+1 should be ':'
            int j = k;
            Value val = ParseJSON(token_vector, k, j);
            current.AddProperty(key, val);
            k = j;
            if (token_vector[k].GetType() == T_COMMA) k++;
        }
        r = k + 1;
        return current;
    }
    if (token_vector[i].GetType() == T_BRACKET_OPEN) {
        current.SetType(J_ARRAY);
        int k = i + 1;
        while (token_vector[k].GetType() != T_BRACKET_CLOSE) {
            int j = k;
            Value vv = ParseJSON(token_vector, k, j);
            current.AddElement(vv);
            k = j;
            if (token_vector[k].GetType() == T_COMMA) k++;
        }
        r = k + 1;
        return current;
    }
    if (token_vector[i].GetType() == T_NUMBER) {
        current.SetType(J_NUMBER);
        current.SetValue(token_vector[i].GetValue());
        r = i + 1;
        return current;
    }
    if (token_vector[i].GetType() == T_STRING) {
        current.SetType(J_STRING);
        current.SetValue(token_vector[i].GetValue());
        r = i + 1;
        return current;
    }
    if (token_vector[i].GetType() == T_BOOL) {
        current.SetType(J_BOOL);
        current.SetValue(token_vector[i].GetValue());
        r = i + 1;
        return current;
    }
    if (token_vector[i].GetType() == T_NULL) {
        current.SetType(J_NULL);
        current.SetValue("null");
        r = i + 1;
        return current;
    }
    return current;
}

Value Parser::ParseString(const string &str) {
    int k;
    return ParseJSON(Tokenize(str), 0, k);
}

Value Parser::ParseFile(const string &file_path) {
    ifstream in(file_path.c_str());
    string str;
    string tmp;
    while (getline(in, tmp)) str += tmp;
    in.close();
    return ParseString(str);
}

Value Parser::ParseMultiple(const vector<string> &file_paths) {
    string total;
    for (const string &file:file_paths) {
        string str;
        ifstream in(file.c_str());
        string tmp;
        while (getline(in, tmp)) str += tmp;
        in.close();
        str.erase(0, 1);
        str.erase(str.size() - 1);
        total += str;
    }
    return ParseString("{" + total + "}");
}
