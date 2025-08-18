// header/Organization.h
#pragma once
#include <string>

class Organization 
    {
        protected:
            std::string name;
            std::string country;
            std::string industry;
        public:
            Organization(std::string n, std::string c, std::string i) : name(n), country(c), industry(i) {}
            const std::string& getName() const { return name; }
            const std::string& getCountry() const { return country; }
            const std::string& getIndustry() const { return industry; }
            virtual std::string getDescription() const = 0;
            virtual ~Organization() {}
    };
