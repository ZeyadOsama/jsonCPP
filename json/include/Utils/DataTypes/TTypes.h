//
// Created by zeyad-osama on 16/08/2020.
//

#pragma once

namespace json {

    enum TOKEN_TYPE {
        T_STRING,
        T_NUMBER,
        T_BOOL,
        T_NULL,
        T_UNKNOWN,
        T_CURL_OPEN,
        T_CURL_CLOSE,
        T_BRACKET_OPEN,
        T_BRACKET_CLOSE,
        T_COMMA,
        T_COLON
    };
}
