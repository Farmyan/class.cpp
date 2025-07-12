//  A government-owned entity that operates like a business (e.g., postal service).
#include "Organization.h"
class PublicCorporation : public Organization
{
          std::string focusArea;
public:
    PublicCorporation(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "PublicCorporation: " + name + " from " + country + " focused on " + focusArea;
    }
};