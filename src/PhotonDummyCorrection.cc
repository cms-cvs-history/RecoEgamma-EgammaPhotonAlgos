#include "RecoEgamma/EgammaPhotonAlgos/interface/PhotonDummyCorrection.h"
//
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
//



PhotonDummyCorrection::PhotonDummyCorrection() {


}

reco::Photon PhotonDummyCorrection::makeCorrections(const reco::Photon& pho) {

  using namespace edm;

  LogDebug(" PhotonDummyCorrection::makeCorrections  ");
  LogDebug("  Photon energy and position  " ) << pho.energy() << " " << pho.vertex();


  // No coorections are applied. Here another cancidate is built taking the parameters of the initial one
  const reco::Particle::Point  vtx( 0, 0, 0 );
  math::XYZVector momentum  = pho.superCluster()->position() - vtx;
  const reco::Particle::LorentzVector  p4(momentum.x(), momentum.y(), momentum.z(), pho.superCluster()->energy() );

  reco::Photon correctedCandidate(0, p4, vtx);

  return correctedCandidate;

}
