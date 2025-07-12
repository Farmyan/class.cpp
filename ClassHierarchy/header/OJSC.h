// Shares are publicly traded; similar to a public corporation.
#include "Organization.h"
class OJSC : public Organization 
{
     std::string focusArea;
public:
    OJSC(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "OJSC: " + name + " from " + country + " focused on " + focusArea;
    }
};
