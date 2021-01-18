# --------------------------------------------------------------
# GNUmakefile for examples module.
# --------------------------------------------------------------
name := mctruthex
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
  G4INSTALL = ../../../../..
endif

.PHONY: all

ifdef HEPMC3_DIR
all: lib bin
  include $(G4INSTALL)/config/binmake.gmk

  INCFLAGS  += -I$(HEPMC3_DIR)/include
  LDLIBS    += -L$(HEPMC3_DIR)/lib -lHepMC3
else
all:
	@echo 'ERROR - HEPMC_DIR not defined in the environment !'
	@echo '        Tested with HepMC release 3.02.03.'
endif
