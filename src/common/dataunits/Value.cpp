//
// Created by zeyad-osama on 03/06/2020.
//

#include <json/common/dataunits/Value.h>
#include <json/utils/Utils.h>

#include <iostream>
#include <sstream>
#include <cstring>
#include <map>

using namespace std;

using namespace json;
using namespace json::types;
using namespace json::utils;

Value::Value(JSON_TYPE t) {
    mType = t;
}

Value Value::operator[](int index) {
    if (mType == J_ARRAY)
        return mValues[index];
    if (mType == J_OBJECT)
        return mProperties[index].second;
    return Value();
}

Value Value::operator[](const string &key) {
    if (mMapValues.find(key) == mMapValues.end())
        return Value();
    return mProperties[mMapValues[key]].second;
}

void Value::AddProperty(const string &key, const Value &aValue) {
    mMapValues[key] = mProperties.size();
    mProperties.emplace_back(key, aValue);
}

void Value::AddElement(const Value &aValue) {
    mValues.push_back(aValue);
}

string Value::AsString() {
    return deserialize(mValue);
}

int Value::AsInteger() {
    stringstream ss;
    ss << mValue;
    int k;
    ss >> k;
    return k;
}

long Value::AsLong() {
    stringstream ss;
    ss << mValue;
    long k;
    ss >> k;
    return k;
}

double Value::AsDouble() {
    stringstream ss;
    ss << mValue;
    double k;
    ss >> k;
    return k;
}

float Value::AsFloat() {
    stringstream ss;
    ss << mValue;
    float k;
    ss >> k;
    return k;
}

bool Value::AsBoolean() {
    return mValue == "true";
}

int Value::Size() {
    if (mType == J_ARRAY)
        return (int) mValues.size();
    if (mType == J_OBJECT)
        return (int) mProperties.size();
    return 0;
}

string Value::ToString() {
    return ToStringSpace();
}

string Value::ToStringSpace(int space) {
    if (mType == J_STRING) return string("\"") + mValue + string("\"");
    if (mType == J_NUMBER) return mValue;
    if (mType == J_BOOL) return mValue;
    if (mType == J_NULL) return "null";
    if (mType == J_OBJECT) {
        string s = string("{\n");
        for (size_t i = 0; i < mProperties.size(); i++) {
            s += add_space(space) + string("\"") + mProperties[i].first + string("\": ") +
                 mProperties[i].second.ToStringSpace(space + 1) + string(i == mProperties.size() - 1 ? "" : ",") +
                 string("\n");
        }
        s += add_space(space - 1) + string("}");
        return s;
    }
    if (mType == J_ARRAY) {
        string s = "[";
        for (size_t i = 0; i < mValues.size(); i++) {
            if (i) s += ", ";
            s += mValues[i].ToStringSpace(space + 1);
        }
        s += "]";
        return s;
    }
    return "##";
}
