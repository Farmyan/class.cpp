#pragma once
#include "DecimalBase.h"
#include <string>
#include <cmath>

class FixedDecimal : public DecimalBase 
    {
        double value;
        int precision;
        public:
            FixedDecimal(double v, int p) : value(v), precision(p) {}
            double GetValue() const { return value; }
            DecimalBase* Add(const DecimalBase& other) const override;
            DecimalBase* Subtract(const DecimalBase& other) const override;
            DecimalBase* AddToFixed(const FixedDecimal& other) const override;
            DecimalBase* AddToFloating(const FloatingDecimal& other) const override;
            DecimalBase* SubtractFromFixed(const FixedDecimal& other) const override;
            DecimalBase* SubtractFromFloating(const FloatingDecimal& other) const override;
            std::string ToString() const override 
                {
                    double factor = std::pow(10, precision);
                    double rounded = std::round(value * factor) / factor;
                    std::string s = std::to_string(rounded);
                    size_t dot = s.find('.');
                    if (dot != std::string::npos) 
                        {
                            if (s.size() > dot + 1 + precision)
                               {
                                    s = s.substr(0, dot + 1 + precision);
                               } 
                        } 
                    else if (precision > 0) 
                        {
                            s += '.';
                            for (int i = 0; i < precision; i++)
                               {
                                    s += '0';
                               } 
                        }
                    return s;
                }
    };
