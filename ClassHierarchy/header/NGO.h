//   Independent of government, often focused on humanitarian or social missions.(Non-Governmental Organization)
#include "Organization.h"
class NGO  : public Organization
{
    std::string focusArea;
public:
    NGO(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "NGO: " + name + " from " + country + " focused on " + focusArea;
    }
};

