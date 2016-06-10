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
//
// $Id: G4ListOfCollisions.hh 69856 2013-05-16 13:32:36Z gcosmo $
// GEANT4 tag $Name: not supported by cvs2svn $
//
// $Id: G4ListOfCollisions.hh,v 1.0 1998/06/30
// -----------------------------------------------------------------------------
//      GEANT 4 class header file
//
//      History: first implementation, A. Feliciello, 30th June 1998
//               16 Nov 1999  M.G. Pia  STL migration
// -----------------------------------------------------------------------------

#ifndef G4ListOfCollisions_h
#define G4ListOfCollisions_h 1

#include "globals.hh"
#include <vector>
#include "G4CollisionInitialState.hh"

typedef std::vector<G4CollisionInitialState*> G4ListOfCollisions;
struct DeleteCollisionInitialState { void operator()(G4CollisionInitialState *aC) {delete aC;} };

#endif
