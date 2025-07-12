// A group formed around a common interest
#include "Organization.h"
class Association : public Organization
{
     std::string focusArea;
public:
    Association(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "Association: " + name + " from " + country + " focused on " + focusArea;
    }
};