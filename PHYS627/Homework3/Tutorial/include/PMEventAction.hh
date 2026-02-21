#ifndef PMEVENTACTION_HH
#define PMEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "globals.hh"

class DisplayEventInfo : public G4UserEventAction{

    public:
        DisplayEventInfo(){

        }
        virtual ~DisplayEventInfo(){

        }

        virtual void EndOfEventAction(const G4Event* event) override;

};

#endif