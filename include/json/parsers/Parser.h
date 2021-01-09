//
// Created by zeyad-osama on 03/06/2020.
//

#pragma once

#include <json/common/dataunits/Value.h>
#include <json/common/dataunits/Token.h>

namespace json {

    class Parser {
        friend class Value;

    public:
        /**
         * Parses a given JSON string to a Value Map object.
         * @param str
         * @return Parsed string in form of Value Map
         * @related JSON Value
         */
        static Value ParseString(const std::string &str);

        /**
         * Parses a given JSON file to a Value Map object.
         * @param       file_path
         * @return      Parsed file in form of Value Map
         * @related     JSON Value
         */
        static Value ParseFile(const std::string &file_path);

        /**
         * Parses a given vector of JSON file paths to a Value Map object.
         * @param[in]   file_paths
         * @return      Parsed file in form of Value Map
         * @related     JSON Value
         */
        static Value ParseMultiple(const std::vector<std::string> &file_paths);

    private:
        static std::vector<dataunits::Token> Tokenize(std::string source);

        static Value ParseJSON(std::vector<dataunits::Token> token_vector, int i, int &r);
    };
} //namespace json