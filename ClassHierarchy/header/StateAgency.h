// Operates as part of the government structure.
#include "Organization.h"
class StateAgency : public Organization
{
         std::string focusArea;
public:
    StateAgency(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "StateAgency: " + name + " from " + country + " focused on " + focusArea;
    }
};