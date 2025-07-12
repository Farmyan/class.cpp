// A flexible legal entity combining elements of partnerships and corporations.
#include "Organization.h"
class LLC : public Organization
{
         std::string focusArea;
public:
    LLC(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "LLC: " + name + " from " + country + " focused on " + focusArea;
    }
};