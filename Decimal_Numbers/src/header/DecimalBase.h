#pragma once
#include <string>

class FixedDecimal;
class FloatingDecimal;

class DecimalBase 
    {
        public:
            virtual ~DecimalBase() = default;
            virtual DecimalBase* Add(const DecimalBase& other) const = 0;
            virtual DecimalBase* Subtract(const DecimalBase& other) const = 0;
            virtual DecimalBase* AddToFixed(const FixedDecimal& other) const = 0;
            virtual DecimalBase* AddToFloating(const FloatingDecimal& other) const = 0;
            virtual DecimalBase* SubtractFromFixed(const FixedDecimal& other) const = 0;
            virtual DecimalBase* SubtractFromFloating(const FloatingDecimal& other) const = 0;
            virtual std::string ToString() const = 0;
    };
