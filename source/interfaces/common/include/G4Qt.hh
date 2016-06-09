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
// $Id: G4Qt.hh,v 1.6 2010/05/20 07:01:03 lgarnier Exp $
// GEANT4 tag $Name: geant4-09-04-beta-01 $
//
//  To unify Qt event treatment between 
// G4/interfaces Qt sessions and G4/visualizations Qt drivers.
// L. Garnier

#ifndef G4QT_HH
#define G4QT_HH

#if defined(G4INTY_BUILD_QT) || defined(G4INTY_USE_QT)

#include "G4VInteractorManager.hh"

class QWidget;
class QString;

// Class description :
//
//  G4Qt : a singleton to handle GUI sessions and visualization 
// drivers built over Qt. It permits to have one Qt main loop for 
// the whole application. The Qt toolkit is inited in the 
// constructor. It is done once for the whole application.
//
// Class description - end :

class G4Qt : public G4VInteractorManager {
public:
  static G4Qt* getInstance();
  static G4Qt* getInstance(int,char**,char*);
  G4bool Inited();
  void* GetEvent();
  void FlushAndWaitExecution();
  virtual ~G4Qt();                     

private:
  G4Qt (int,char**,char*);                     
  static G4Qt* instance; // Pointer to single instance.
  int    argn;
  char** args;
};

#endif //HAS_QT

#endif