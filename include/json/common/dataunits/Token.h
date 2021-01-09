//
// Created by zeyad-osama on 03/06/2020.
//

#pragma once

#include <json/common/datatypes/Types.h>

#include <string>
#include <utility>

namespace json {
    namespace dataunits {

        class Token {

        public:
            explicit Token(std::string value = "", types::TOKEN_TYPE type = types::T_UNKNOWN)
                    : mValue(std::move(value)), mType(type) {}

            inline std::string GetValue() {
                return mValue;
            }

            inline types::TOKEN_TYPE GetType() {
                return mType;
            }

        private:
            std::string mValue;
            types::TOKEN_TYPE mType;
        };
    } //namespace dataunits
} //namespace json