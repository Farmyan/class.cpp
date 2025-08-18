#pragma once
#include <string>
#include <iostream>
#include "Organization.h"

class Registrar 
    {
        Organization** db;    
        int capacity;
        int count;

        void grow() 
            {
                int newCap = capacity * 2;
                Organization** newDb = new Organization*[newCap];
                for (int i = 0; i < count; i++)
                   {
                        newDb[i] = db[i];
                   }
                delete[] db;
                db = newDb;
                capacity = newCap;
            }
        public:
            Registrar() : capacity(10), count(0) 
                {
                    db = new Organization*[capacity];
                }
            ~Registrar() 
                {
                    for (int i = 0; i < count; i++)
                        delete db[i];
                    delete[] db;
                }
            bool registerOrg(Organization* org) 
                {
                    for (int i = 0; i < count; i++) 
                        {
                            if (db[i]->getName() == org->getName() && db[i]->getCountry() == org->getCountry()) 
                                {
                                    return false;
                                }
                        }
                    if (count >= capacity) grow();
                    db[count++] = org;
                    return true;
                }
            int size() const 
                { 
                    return count; 
                }
            Organization* get(int index) const 
                {
                    if (index < 0 || index >= count) return 0;
                    return db[index];
                }
    };
