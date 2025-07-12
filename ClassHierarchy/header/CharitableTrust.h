//  Created to support specific charitable goals.
#include "Organization.h"
class CharitableTrust : public Organization
{
          std::string focusArea;
public:
    CharitableTrust(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "CharitableTrust: " + name + " from " + country + " focused on " + focusArea;
    }
};