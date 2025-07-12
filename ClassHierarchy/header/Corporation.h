//  A legal entity separate from its owners, can raise capital through stock.
#include "Organization.h"
class Corporation : public Organization
{
          std::string focusArea;
public:
    Corporation(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "Corporation: " + name + " from " + country + " focused on " + focusArea;
    }
};