//////////////////////////////////////////////////////////////
///
///Class:		ParticleData
///Description:
///

#pragma once

#include "BaseParticle.h"
#include "ParticleOutEvent.h"
#include "FiledTree.h"
#include <vector>

namespace chanser{

   
  class ParticleData {
      
  public:
    ParticleData()=default;
  ParticleData(const TString& treename,const TString& filename,size_t np):_tree{FiledTree::Recreate(treename,filename)},_outputs(np){};
      
    virtual ~ParticleData()=default;
    ParticleData(const ParticleData& other) = default; //Copy Constructor
    ParticleData(ParticleData&& other) = default; //Move Constructor
      
    ParticleData& operator=(const ParticleData& other)=default;
    ParticleData& operator=(ParticleData&& other)=default;

    void AddParticle( ParticleOutEvent* out,BaseParticle* particle,TString name){
      _outputs[_nParticles]=(out->clone()); //make a copy as each particle needs its own
      _outputs[_nParticles]->SetName(name); 
      _outputs[_nParticles]->SetParticle(particle);
      _outputs[_nParticles]->Branches(_tree->Tree());
      _nParticles++;
    }

    void Fill();
    void Save(){_tree.reset();}

    TTree* GetTree() noexcept{return _tree->Tree();}
      
  private:
      
    std::vector<partoutev_uptr >_outputs;//!

    std::unique_ptr<FiledTree> _tree;//!

    UInt_t _nParticles{0};
      
    ClassDef(chanser::ParticleData,1);
      
  };//class ParticleData
    
  using partdata_ptr = ParticleData*;
  using partdatas =std::vector<partdata_ptr>;
}