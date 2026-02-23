#ifndef PMPRIMARYGENERATOR_hh
#define PMPRIMARYGENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"



class PMPrimaryGenerator:public G4VUserPrimaryGeneratorAction{
    public:
        PMPrimaryGenerator();
        ~PMPrimaryGenerator();

        G4ParticleGun* GetParticleGun() const {return fParticleGun;}

        virtual void GeneratePrimaries(G4Event *);

    private:
        G4ParticleGun *fParticleGun;
};



#endif