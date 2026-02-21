#ifndef PMPHYSICSLISTS_HH
#define PMPHYSICSLIST_hh

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"

class PMPhysicsList : public G4VModularPhysicsList{
    public:
        PMPhysicsList();
        ~PMPhysicsList();
};

#endif