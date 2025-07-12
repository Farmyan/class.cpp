//  Owned and run by one individual, not legally distinct from the owner.
#include "Organization.h"
class SoleProprietorship : Organization
{
         std::string focusArea;
public:
    SoleProprietorship(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "SoleProprietorship: " + name + " from " + country + " focused on " + focusArea;
    }
};