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
#ifndef G4HadSignalHandler_hh
#define G4HadSignalHandler_hh

//#ifndef G4HadSignalHandler_off
#if 0
#include <iostream>
#include <signal.h>
#include <vector>
#include "G4Types.hh"

// A simple, reasonably portable, but at present 
// semantic-wise totally unsafe signalhandler prototype meant for SEGFAULT.
// Being rushed into production or various reasons.

extern "C"
{
  typedef void (*sighandler_t)(int);
}

class G4HadSignalHandler
{
  public: 
  
  G4HadSignalHandler(sighandler_t aNew);
  
  ~G4HadSignalHandler();
      
  static G4ThreadLocal std::vector<sighandler_t> *theCache;  
  static G4ThreadLocal bool registered;
};

 

#endif

#endif
