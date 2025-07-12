// Formed by treaties between governments (e.g., UN, WHO).
#include "Organization.h"
class IGO : public Organization
{
          std::string focusArea;
public:
    IGO(std::string n, std::string c, std::string i, std::string f)
        : Organization(n, c, i), focusArea(f) {}

    std::string getDescription() const override {
        return "IGO: " + name + " from " + country + " focused on " + focusArea;
    }
};