//
// Created by zeyad-osama on 03/06/2020.
//

#pragma once

#include <Utils/DataTypes/Types.h>

#include <string>
#include <utility>

namespace json {

    class Token {

    public:
        explicit Token(std::string value = "", TOKEN_TYPE type = T_UNKNOWN)
                : mValue(std::move(value)), mType(type) {}

        inline std::string GetValue() {
            return mValue;
        }

        inline TOKEN_TYPE GetType() {
            return mType;
        }

    private:
        std::string mValue;
        TOKEN_TYPE mType;
    };
}