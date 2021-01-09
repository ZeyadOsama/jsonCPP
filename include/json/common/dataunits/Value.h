//
// Created by zeyad-osama on 03/06/2020.
//

#pragma once

#include <json/common/datatypes/Types.h>

#include <vector>
#include <map>
#include <string>
#include <unordered_map>

namespace json {

    class Value {
        friend class Parser;

        typedef std::pair<std::string, Value> Property;

    public:
        explicit Value(types::JSON_TYPE= types::J_UNKNOWN);

        /**
         * @brief       Retrieves the object at the passed index. Useful for Values
         *
         * @param[in]   index
         * @return      Value for passed index
         */
        Value operator[](int index);

        /**
         * @brief       Retrieves the object with the passed key
         *
         * @param[in]   key
         * @return      Value for passed index
         */
        Value operator[](const std::string &key);

        /**
         * @return      Value object in form of String
         */
        std::string AsString();

        /**
         * @return      Value object in form of Integer
         */
        int AsInteger();

        /**
         * @return      Value object in form of Long
         */
        long AsLong();

        /**
         * @return      Value object in form of Double
         */
        double AsDouble();

        /**
         * @return      Value object in form of Float
         */
        float AsFloat();

        /**
         * @return      Value object in form of Boolean
         */
        bool AsBoolean();

        /**
         * @return Type of Value object
         */

        inline types::JSON_TYPE Type() {
            return mType;
        }

        int Size();

    private:
        std::string ToStringSpace(int= 1);

        void AddProperty(const std::string &key, const Value &aValue);

        void AddElement(const Value &aValue);

        std::string ToString();

        inline void SetType(types::JSON_TYPE aType) {
            mType = aType;
        }

        inline void SetValue(const std::string &aValue) {
            mValue = aValue;
        }

    private:
        std::string mValue;
        types::JSON_TYPE mType;
        std::vector<Property> mProperties;
        std::map<std::string, size_t> mMapValues;
        std::vector<Value> mValues;
    };
} //namespace json