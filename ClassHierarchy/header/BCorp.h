// A for-profit entity certified to meet social and environmental performance standards. (Benefict Corporation)
#include "Organization.h"
class BCorp : public Organization
{
        std::string focusArea;
public:
    BCorp(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "BCorp: " + name + " from " + country + " focused on " + focusArea;
    }
};