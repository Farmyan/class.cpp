#pragma once
#include "Registrar.h"
#include <iostream>
#include <string>

class Report 
    {
        public:
            void generate(Registrar& reg) 
                {
                    for (int i = 0; i < reg.size(); i++) 
                        {
                            Organization* o = reg.get(i);
                            if (o) 
                                {
                                    std::cout << "Name: " << o->getName() << "\n";
                                    std::cout << "Country: " << o->getCountry() << "\n";
                                    std::cout << "Industry: " << o->getIndustry() << "\n";
                                    std::cout << "Description: " << o->getDescription() << "\n\n";
                                }
                        }
                }
            virtual ~Report() {} 
    };
