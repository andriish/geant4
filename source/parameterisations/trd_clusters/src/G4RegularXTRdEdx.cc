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
//
// $Id: G4RegularXTRdEdx.cc,v 1.2 2004/12/07 09:00:05 gcosmo Exp $
// GEANT4 tag $Name: geant4-07-00-cand-03 $
//

#include <complex>

#include "G4RegularXTRdEdx.hh"
#include "Randomize.hh"

#include "G4Gamma.hh"

////////////////////////////////////////////////////////////////////////////
//
// Constructor, destructor

G4RegularXTRdEdx::G4RegularXTRdEdx(G4Envelope *anEnvelope, 
                                                  G4double a, G4double b) :
  G4VXTRdEdx(anEnvelope,a,b)
{
  G4cout<<"Regular X-ray TR dE/dx radiator model is called"<<G4endl ;

  // Build energy and angular integral spectra of X-ray TR photons from
  // a radiator

  BuildTable() ;
}

///////////////////////////////////////////////////////////////////////////

G4RegularXTRdEdx::~G4RegularXTRdEdx()
{
  ;
}



///////////////////////////////////////////////////////////////////////////
//
// Approximation for radiator interference factor for the case of
// fully Regular radiator. The plate and gas gap thicknesses are fixed .
// The mean values of the plate and gas gap thicknesses 
// are supposed to be about XTR formation zones but much less than 
// mean absorption length of XTR photons in coresponding material.

G4double 
G4RegularXTRdEdx::GetStackFactor( G4double energy, 
                                         G4double gamma, G4double varAngle )
{
  G4double result, Qa, Qb, Q, aZa, bZb, aMa, bMb, D ;
  
  aZa = fPlateThick/GetPlateFormationZone(energy,gamma,varAngle) ;
  bZb = fGasThick/GetGasFormationZone(energy,gamma,varAngle) ;

  aMa = fPlateThick*GetPlateLinearPhotoAbs(energy) ;
  bMb = fGasThick*GetGasLinearPhotoAbs(energy) ;

  Qa = std::exp(-aMa) ;
  Qb = std::exp(-bMb) ;
  Q  = Qa*Qb ;

  G4complex Ha( std::exp(-0.5*aMa)*std::cos(aZa),
               -std::exp(-0.5*aMa)*std::sin(aZa)   ) ; 
 
  G4complex Hb( std::exp(-0.5*bMb)*std::cos(bZb),
               -std::exp(-0.5*bMb)*std::sin(bZb)    ) ;

  G4complex H  = Ha*Hb ;

  G4complex Hs = std::conj(H) ;

  D            = 1.0 /( (1 - std::sqrt(Q))*(1 - std::sqrt(Q)) + 
                  4*std::sqrt(Q)*std::sin(0.5*(aZa+bZb))*std::sin(0.5*(aZa+bZb)) ) ;

  G4complex F1 = (1.0 - Ha)*(1.0 - Hb)*(1.0 - Hs)
                 * G4double(fPlateNumber)*D ;

  G4complex F2 = (1.0-Ha)*(1.0-Ha)*Hb*(1.0-Hs)*(1.0-Hs)
                 * (1.0 - std::pow(H,fPlateNumber)) * D*D ;

  G4complex R  = (F1 + F2)*OneInterfaceXTRdEdx(energy,gamma,varAngle) ;

  result       = 2.0*std::real(R) ;
 
  return      result ;
}


//
//
////////////////////////////////////////////////////////////////////////////







