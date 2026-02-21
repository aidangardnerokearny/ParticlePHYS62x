#include "PMEventAction.hh"
#include "G4VVisManager.hh"
#include "G4Text.hh"
#include "G4Circle.hh"
#include "G4Color.hh"
#include "G4UnitsTable.hh"
#include "G4MTRunManager.hh"
#include "G4RunManager.hh"
#include "G4VisAttributes.hh"
#include "G4UImanager.hh"

#include "PMPrimaryGenerator.hh"
#include "PMDetectorConstruction.hh"

void DisplayEventInfo::EndOfEventAction(const G4Event*){
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

    if (!pVVisManager){
        return;
    }

    if (pVVisManager){
        auto runManager = G4RunManager::GetRunManager();
        if (!runManager) return;

        G4String pName = "Unknown";
        G4double energy = 0;
        auto genAction = (PMPrimaryGenerator*)runManager->GetUserPrimaryGeneratorAction();
    
        if (genAction && genAction->GetParticleGun()) {
        pName = genAction->GetParticleGun()->GetParticleDefinition()->GetParticleName();
        energy = genAction->GetParticleGun()->GetParticleEnergy();
        } else {
            G4cout << "DEBUG: Particle Gun pointer is NULL!" << G4endl;
        }


        // 3. Safely get the Material Info
        G4String matName = "Unknown";
        auto detConstruction = (PMDetectorConstruction*)runManager->GetUserDetectorConstruction();
        
        if (detConstruction && detConstruction->GetTargetMaterial()) {
            matName = detConstruction->GetTargetMaterial()->GetName();
        } else {
            G4cout << "DEBUG: Material pointer is NULL!" << G4endl;
        }

        // 4. Draw only if we have data
        /*std::stringstream ss;
        ss << "Particle: " << pName << " | Energy: " << G4BestUnit(energy, "Energy") << " | Mat: " << matName;
        G4cout << "Attempting to Draw" << G4endl;
        G4Text text2D(ss.str(), G4Point3D(0, 0, 0)); // Start at center for testing
    
        // Use 'SetScreenSize' (pixels) instead of world units
        text2D.SetScreenSize(24.); 
        
        // Set color to something bright that won't match background
        G4Colour colour(1.0, 1.0, 1.0);
        text2D.SetVisAttributes(G4VisAttributes(colour)); 
        // Force the layout to be centered so it's harder to miss
        text2D.SetLayout(G4Text::centre);

        pVVisManager->Draw2D(text2D); */
        std::stringstream ss;
        ss << "Particle: " << pName << " | Energy: " << G4BestUnit(energy, "Energy");
        G4String info = ss.str();

        // 2. Use the UI Manager to "Add" text to the 2D scene
        // Syntax: /vis/scene/add/text2D [x] [y] [size] [unit] [layout] [text]
        G4UImanager* UI = G4UImanager::GetUIpointer();
        
        // Clear previous text strings if you don't want them to overlap
        UI->ApplyCommand("/vis/scene/notifyHandlers"); 

        std::string cmd = "/vis/scene/add/text2D -0.9 0.9 20 ! ! " + info;
        UI->ApplyCommand(cmd);
        UI->ApplyCommand("/vis/viewer/rebuild");

        G4cout << info << G4endl;

    }
}