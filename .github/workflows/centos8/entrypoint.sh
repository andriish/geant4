#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum -y install dnf-plugins-core
dnf config-manager --set-enabled PowerTools
dnf config-manager --set-enabled powertools
yum -y install  gcc gcc-c++ gcc-gfortran make which cmake cmake-data cmake-filesystem
yum -y install  HepMC3 HepMC3-devel
yum -y install yum-plugin-copr
yum -y copr enable averbyts/HEPrpms
yum -y install geant4 geant4-devel
#yum -y install pythia8-devel pythia8 pythia8-data 

find /usr | grep cmake | grep Geant

mkdir -p test
cd test
cmake -B. -S ../examples/extended/eventgenerator -DGeant4_DIR=/usr/lib64/Geant4-10.7.0
make -j 2


out=$?
echo ::set-output name=out::$out
