#pragma once
#include "DecimalBase.h"
#include <string>

class FloatingDecimal : public DecimalBase 
    {
        double value;
        public:
            explicit FloatingDecimal(double v) : value(v) {}
            double GetValue() const { return value; }
            DecimalBase* Add(const DecimalBase& other) const override;
            DecimalBase* Subtract(const DecimalBase& other) const override;
            DecimalBase* AddToFixed(const FixedDecimal& other) const override;
            DecimalBase* AddToFloating(const FloatingDecimal& other) const override;
            DecimalBase* SubtractFromFixed(const FixedDecimal& other) const override;
            DecimalBase* SubtractFromFloating(const FloatingDecimal& other) const override;
            std::string ToString() const override 
                {
                    return std::to_string(value);
                }
    };
