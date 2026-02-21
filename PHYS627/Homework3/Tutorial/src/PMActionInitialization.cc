#include "PMActionInitialization.hh"
#include "PMEventAction.hh"

PMActionInitialization::PMActionInitialization(){

}


PMActionInitialization::~PMActionInitialization(){

}

void PMActionInitialization::BuildForMaster() const{

}
void PMActionInitialization::Build() const{
    PMPrimaryGenerator *generator = new PMPrimaryGenerator();
    DisplayEventInfo *info = new DisplayEventInfo();
    SetUserAction(generator);
    SetUserAction(info);

    //SetUserAction(new DisplayEventInfo);
}