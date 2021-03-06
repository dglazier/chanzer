//////////////////////////////////////////////////////////////
///
///Class:		OutEventManager
///Description:
///
#pragma once

#include "BaseOutEvent.h"
#include "FiledTree.h"
#include "ntuple_writer.h"
#include <TList.h>

namespace chanser{
  
  enum class FSOutputType{NONE, ROOTTREE, HIPONTUPLE};

  class OutEventManager {

  public :
    OutEventManager()=default;
    virtual ~OutEventManager()=default;


    void TakeReal( base_outevt_uptr out ){ _realTD=std::move(out);} //now owner
    BaseOutEvent* GetReal( ) const {return _realTD.get();}
    void TakeTruth( base_outevt_uptr out  ){ _truTD =std::move(out);} //now owner
    BaseOutEvent* GetTruth( ) const {return _truTD.get();}
    
    void Init(TString outDir);
    
    void CreateFinalTree(const TString& fname);
    void CreateFinalHipo(const TString& filename);
      
    virtual void ConfigureOutTree(TTree* tree) const;
    virtual void ConfigureOutHipo(hipo::ntuple_writer* writer) const;

    ttree_ptr FinalTree()const noexcept{ return _finalTree.get()!=nullptr ? _finalTree->Tree() : nullptr;}
    hipo::ntuple_writer* FinalHipo()const noexcept{return _finalHipo.get();}
 
    void Fill();
    void Finish();

    void UseOutputRootTree(){_outputType=FSOutputType::ROOTTREE;}
    void UseOutputHipoNtuple(){_outputType=FSOutputType::HIPONTUPLE;}

    std::unique_ptr<TList> UniqueFinalTreeList() {return std::move(_listOfFinalTrees);}
    
  private:

   //Tree Output Data
    BaseOutEvent* TD={nullptr};//!
    std::unique_ptr<BaseOutEvent> _realTD={nullptr};//!
    std::unique_ptr<BaseOutEvent> _truTD={nullptr};//!

    filed_uptr _finalTree={nullptr};//!
    
    std::unique_ptr<hipo::ntuple_writer> _finalHipo={nullptr};//!
    // TString _finalHipoFile;
    
    FSOutputType  _outputType=FSOutputType::NONE;

    std::unique_ptr<TList> _listOfFinalTrees={nullptr};
    
    ClassDef(chanser::OutEventManager,1);

  };

}
