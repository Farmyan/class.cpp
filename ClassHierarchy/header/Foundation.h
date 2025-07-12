// A type of non-profit that typically has an endowment and funds grants or projects.
#include "Organization.h"
class Foundation : public Organization
{
         std::string focusArea;
public:
    Foundation(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "Foundation: " + name + " from " + country + " focused on " + focusArea;
    }
};