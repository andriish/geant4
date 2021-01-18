//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file eventgenerator/HepMC/HepMCEx01/include/HepMC3G4Interface.hh
/// \brief Definition of the HepMC3G4Interface class
//
//

#ifndef HEPMC3_G4_INTERFACE_H
#define HEPMC3_G4_INTERFACE_H

#include "G4VPrimaryGenerator.hh"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"

/// A base class for primary generation via HepMC object.
/// This class is derived from G4VPrimaryGenerator.

class HepMC3G4Interface : public G4VPrimaryGenerator {
protected:
  // Note that the life of HepMC event object must be handled by users.
  // In the default implementation, a current HepMC event will be
  // deleted at GeneratePrimaryVertex() in the next event.
  HepMC3::GenEvent* hepmcEvent; // (care for single event case only)

  // We  have to take care for the position of primaries because
  // primary vertices outside the world voulme give rise to G4Execption.
  // If the default implementation is not adequate, an alternative
  // can be implemented in your own class.
  virtual G4bool CheckVertexInsideWorld(const G4ThreeVector& pos) const;

  // service method for conversion from HepMC3::GenEvent to G4Event
  void HepMC2G4(const HepMC3::GenEvent* hepmcevt, G4Event* g4event);

  // Implement this method in his/her own concrete class.
  // An empty event will be created in default.
  virtual HepMC3::GenEvent* GenerateHepMCEvent();

public:
  HepMC3G4Interface();
  virtual ~HepMC3G4Interface();

  // set/get methods
  HepMC3::GenEvent* GetHepMCGenEvent() const;

  // The default behavior is that a single HepMC event generated by
  // GenerateHepMCEvent() will be converted to G4Event through HepMC2G4().
  virtual void GeneratePrimaryVertex(G4Event* anEvent);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
inline HepMC3::GenEvent* HepMC3G4Interface::GetHepMCGenEvent() const
{
  return hepmcEvent;
}

#endif