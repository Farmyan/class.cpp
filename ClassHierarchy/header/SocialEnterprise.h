// A business that prioritizes social or environmental goals alongside profit.
#include "Organization.h"
class SocialEnterprise : public Organization
{
          std::string focusArea;
public:
    SocialEnterprise(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "SocialEnterprise: " + name + " from " + country + " focused on " + focusArea;
    }
};