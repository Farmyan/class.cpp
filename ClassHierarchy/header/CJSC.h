// A company with a limited number of shareholders, shares are not publicly traded.
#include "Organization.h"
class CJSC : public Organization
{
         std::string focusArea;
public:
    CJSC(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "CJSC: " + name + " from " + country + " focused on " + focusArea;
    }
};