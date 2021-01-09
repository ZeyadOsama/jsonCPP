//
// Created by zeyad-osama on 16/08/2020.
//

#include <json/utils//Utils.h>

using namespace std;

namespace json {
    namespace utils {

        int next_whitespace(const string &source, int i) {
            while (i < (int) source.length()) {
                if (source[i] == '"') {
                    i++;
                    while (i < (int) source.length() && (source[i] != '"' || source[i - 1] == '\\')) i++;
                }
                if (source[i] == '\'') {
                    i++;
                    while (i < (int) source.length() && (source[i] != '\'' || source[i - 1] == '\\')) i++;
                }
                if (isspace(source[i])) return i;
                i++;
            }
            return (int) source.length();
        }

        int skip_whitespaces(const string &source, int i) {
            while (i < (int) source.length()) {
                if (!isspace(source[i])) return i;
                i++;
            }
            return -1;
        }

        string deserialize(const string &ref) {
            string out;
            for (size_t i = 0; i < ref.length(); i++) {
                if (ref[i] == '\\' && i + 1 < ref.length()) {
                    int plus = 2;
                    if (ref[i + 1] == '\"')
                        out += '"';
                    else if (ref[i + 1] == '\\')
                        out += '\\';
                    else if (ref[i + 1] == '/')
                        out += '/';
                    else if (ref[i + 1] == 'b')
                        out += '\b';
                    else if (ref[i + 1] == 'f')
                        out += '\f';
                    else if (ref[i + 1] == 'n')
                        out += '\n';
                    else if (ref[i + 1] == 'r')
                        out += '\r';
                    else if (ref[i + 1] == 't')
                        out += '\t';
                    else if (ref[i + 1] == 'u' && i + 5 < ref.length()) {
                        unsigned long long v = 0;
                        for (int j = 0; j < 4; j++) {
                            v *= 16;
                            if (ref[i + 2 + j] <= '9' && ref[i + 2 + j] >= '0') v += ref[i + 2 + j] - '0';
                            if (ref[i + 2 + j] <= 'f' && ref[i + 2 + j] >= 'a') v += ref[i + 2 + j] - 'a' + 10;
                        }
                        out += (char) v;
                        plus = 6;
                    }
                    i += plus - 1;
                    continue;
                }
                out += ref[i];
            }
            return out;
        }

        string add_space(int len) {
            string s;
            while (len--) s += "  ";
            return s;
        }
    } //namespace utils
} //namespace json
