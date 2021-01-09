//
// Created by zeyad-osama on 16/08/2020.
//

#pragma once

#include <string>

namespace json {
    namespace utils {

        int next_whitespace(const std::string &source, int i);

        int skip_whitespaces(const std::string &source, int i);

        std::string deserialize(const std::string &ref);

        std::string add_space(int len);
    } //namespace utils
} //namespace json