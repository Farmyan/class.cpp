#include "FloatingDecimal.h"
#include "FixedDecimal.h"

// double dispatch
DecimalBase* FloatingDecimal::Add(const DecimalBase& other) const 
    {
        return other.AddToFloating(*this);
    }
DecimalBase* FloatingDecimal::Subtract(const DecimalBase& other) const 
    {
        return other.SubtractFromFloating(*this);
    }
DecimalBase* FloatingDecimal::AddToFixed(const FixedDecimal& other) const 
    {
        return new FloatingDecimal(value + other.GetValue());
    }
DecimalBase* FloatingDecimal::AddToFloating(const FloatingDecimal& other) const 
    {
        return new FloatingDecimal(value + other.GetValue());
    }
DecimalBase* FloatingDecimal::SubtractFromFixed(const FixedDecimal& other) const 
    {
        return new FloatingDecimal(other.GetValue() - value);
    }
DecimalBase* FloatingDecimal::SubtractFromFloating(const FloatingDecimal& other) const 
    {
        return new FloatingDecimal(other.GetValue() - value);
    }
