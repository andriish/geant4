//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
// ====================================================================
//
//   G4HepMCInterface.hh
//   $Id: G4HepMCInterface.hh,v 1.2 2005/12/06 13:50:16 gcosmo Exp $
//
//   A base class for primary generation via HepMC object.
//   This class is derived from G4VPrimaryGenerator.
//
// ====================================================================
#ifndef G4_HEPMC_INTERFACE_H
#define G4_HEPMC_INTERFACE_H

#include "G4VPrimaryGenerator.hh"
#include <CLHEP/HepMC/GenEvent.h>

class G4HepMCInterface : public G4VPrimaryGenerator
{
public:
  // static service method for conversion from HepMC::GenEvent to G4Event
  static void HepMC2G4(const HepMC::GenEvent* hepmcevt, G4Event* g4event);

  // static service method for checking a point is included in the (current) world
  // static G4bool CheckVertexInsideWorld(const G4ThreeVector& pos);
  // ------------> This method has been moved to the base class

protected:
  // Note that the life of HepMC event object must be handled by users.
  // In the default implementation, a current HepMC event will be
  // deleted at GeneratePrimaryVertex() in the next event.
  HepMC::GenEvent* hepmcEvent; // (care for single event case only)

  // Implement this method in his/her own concrete class.
  // An empty event will be created in default.
  virtual HepMC::GenEvent* GenerateHepMCEvent();

public: 
  G4HepMCInterface();
  virtual ~G4HepMCInterface();

  // set/get methods
  HepMC::GenEvent* GetHepMCGenEvent() const;

  // The default behavior is that a single HepMC event generated by
  // GenerateHepMCEvent() will be converted to G4Event through HepMC2G4().
  virtual void GeneratePrimaryVertex(G4Event* anEvent);
};

// ====================================================================
// inline functions
// ====================================================================

inline HepMC::GenEvent* G4HepMCInterface::GetHepMCGenEvent() const 
{ 
  return hepmcEvent; 
}

#endif