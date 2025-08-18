#include "FixedDecimal.h"
#include "FloatingDecimal.h"

DecimalBase* FixedDecimal::Add(const DecimalBase& other) const 
    {
        return other.AddToFixed(*this);
    }
DecimalBase* FixedDecimal::Subtract(const DecimalBase& other) const 
    {
        return other.SubtractFromFixed(*this);
    }

DecimalBase* FixedDecimal::AddToFixed(const FixedDecimal& other) const 
    {
        return new FixedDecimal(value + other.GetValue(), precision);
    }
DecimalBase* FixedDecimal::AddToFloating(const FloatingDecimal& other) const 
    {
        return new FloatingDecimal(value + other.GetValue());
    }
DecimalBase* FixedDecimal::SubtractFromFixed(const FixedDecimal& other) const 
    {
        return new FixedDecimal(other.GetValue() - value, precision);
    }
DecimalBase* FixedDecimal::SubtractFromFloating(const FloatingDecimal& other) const 
    {
        return new FloatingDecimal(other.GetValue() - value);
    }
