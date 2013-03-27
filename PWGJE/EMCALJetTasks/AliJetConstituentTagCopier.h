#ifndef ALIJETCONSTITUENTTAGCOPIER_H
#define ALIJETCONSTITUENTTAGCOPIER_H

// $Id: AliJetConstituentTagCopier.h  $

#include "AliAnalysisTaskEmcal.h"

class TClonesArray;
class TString;
class AliNamedArrayI;

class AliJetConstituentTagCopier : public AliAnalysisTaskEmcal {
 public:
  AliJetConstituentTagCopier();
  AliJetConstituentTagCopier(const char *name);
  virtual ~AliJetConstituentTagCopier();

  void                        SetMCParticlesName(const char *n)      { fMCParticlesName       = n         ; }
  void                        SetCleanBeforeCopy(Bool_t c)           { fCleanBeforeCopy       = c         ; }
  void                        SetMCLabelShift(Int_t s)               { fMCLabelShift          = s         ; }

 protected:
  void                        ExecOnce();
  Bool_t                      Run();
  void                        DoClusterLoop(TClonesArray *array);
  void                        DoTrackLoop(TClonesArray *array);
  void                        DoEmcalParticleLoop(TClonesArray *array);

  TString                     fMCParticlesName;                       // name of MC particle collection
  Bool_t                      fCleanBeforeCopy;                       // clean bit map before copying
  Int_t                       fMCLabelShift;                          // if MC label > fMCLabelShift, MC label -= fMCLabelShift
  TClonesArray               *fMCParticles;                           //!MC particle collection
  AliNamedArrayI             *fMCParticlesMap;                        //!MC particle map

 private:
  AliJetConstituentTagCopier(const AliJetConstituentTagCopier&);            // not implemented
  AliJetConstituentTagCopier &operator=(const AliJetConstituentTagCopier&); // not implemented

  ClassDef(AliJetConstituentTagCopier, 3) // Copy tags from particle level constituent to detector level
};

#endif
