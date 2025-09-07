#pragma once
#include "Organization.h"

class Registrar 
    {
        Organization* orgs[100]; 
        int count;
        public:
            Registrar() : count(0) {}
            bool registerOrg(Organization* org) 
                {
                    if (count >= 100) 
                        {
                            return false;
                        }
                    for (int i = 0; i < count; i++) 
                        {
                            if (orgs[i]->getName() == org->getName()) 
                                {
                                    delete org; 
                                    return false;
                                }
                        }

                    orgs[count++] = org;
                    return true;
                }
            int size() const 
                { 
                    return count; 
                }
            Organization* get(int index) 
                {
                    if (index < 0 || index >= count) 
                        {
                            return nullptr;
                        }
                    return orgs[index];
                }   
    };
