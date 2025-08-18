#pragma once
#include <string>
#include <iostream>
#include "Registrar.h"

class Report 
    {
        public:
            virtual ~Report() {}
            virtual void generate(const Registrar& r) const = 0;
    };

class CSVDetailReport : public Report 
    {
        public:
            void generate(const Registrar& r) const override 
                {
                    std::cout << "Type,Name,Country,Industry,Description\n";
                    for (int i = 0; i < r.size(); i++) 
                        {
                            Organization* o = r.get(i);
                            std::string desc = o->getDescription();
                            std::string type = desc.substr(0, desc.find(':'));
                            std::cout << type << "," << o->getName() << "," << o->getCountry() << "," << o->getIndustry() << "," << desc << "\n";
                        }
                }
    };

class MarkdownDetailReport : public Report 
    {
        public:
            void generate(const Registrar& r) const override 
                {
                    for (int i = 0; i < r.size(); i++) 
                        {
                            Organization* o = r.get(i);
                            std::cout << "- " << o->getDescription() << "\n";
                        }
                }
    };
