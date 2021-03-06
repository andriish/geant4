#------------------------------------------------------------------------------
# Module : G4error_propagation
# Package: Geant4.src.G4error_propagation
#------------------------------------------------------------------------------

#
# Define the Geant4 Module.
#
geant4_define_module(NAME G4error_propagation
  HEADERS
    G4ErrorFreeTrajParam.hh
    G4ErrorFreeTrajState.hh
    G4ErrorGeomVolumeTarget.hh
    G4ErrorMagFieldLimitProcess.hh
    G4ErrorMatrix.hh
    G4ErrorMatrix.icc
    G4ErrorMessenger.hh
    G4ErrorPhysicsList.hh
    G4ErrorPropagator.hh
    G4ErrorPropagatorManager.hh
    G4ErrorRunManagerHelper.hh
    G4ErrorStepLengthLimitProcess.hh
    G4ErrorSurfaceTrajParam.hh
    G4ErrorSurfaceTrajState.hh
    G4ErrorSymMatrix.hh
    G4ErrorSymMatrix.icc
    G4ErrorTrackLengthTarget.hh
    G4ErrorTrajErr.hh
    G4ErrorTrajState.hh
    G4VErrorLimitProcess.hh
  SOURCES
    G4ErrorFreeTrajParam.cc
    G4ErrorFreeTrajState.cc
    G4ErrorGeomVolumeTarget.cc
    G4ErrorMagFieldLimitProcess.cc
    G4ErrorMatrix.cc
    G4ErrorMessenger.cc
    G4ErrorPhysicsList.cc
    G4ErrorPropagator.cc
    G4ErrorPropagatorManager.cc
    G4ErrorRunManagerHelper.cc
    G4ErrorStepLengthLimitProcess.cc
    G4ErrorSurfaceTrajParam.cc
    G4ErrorSurfaceTrajState.cc
    G4ErrorSymMatrix.cc
    G4ErrorTrackLengthTarget.cc
    G4ErrorTrajState.cc
    G4VErrorLimitProcess.cc
  GRANULAR_DEPENDENCIES
    G4baryons
    G4bosons
    G4csg
    G4cuts
    G4digits
    G4emstandard
    G4emutils
    G4event
    G4geometrymng
    G4globman
    G4hits
    G4intercoms
    G4ions
    G4leptons
    G4magneticfield
    G4materials
    G4mesons
    G4muons
    G4navigation
    G4partman
    G4procman
    G4run
    G4track
    G4tracking
    G4transportation
    G4volumes
  GLOBAL_DEPENDENCIES
    G4digits_hits
    G4event
    G4geometry
    G4global
    G4intercoms
    G4materials
    G4particles
    G4processes
    G4run
    G4track
    G4tracking
  LINK_LIBRARIES
)

# List any source specific properties here

