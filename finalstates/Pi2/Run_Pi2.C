{

  clas12databases::SetCCDBLocalConnection("/home/dglazier/clas12root/RunRoot/ccdb.sqlite");
  clas12databases::SetQADBConnection("/home/dglazier/clas12root/RunRoot/qaDB.json");
  clas12databases::SetRCDBRootConnection("/home/dglazier/clas12root/RunRoot/rcdb.root");

   HipoData hdata;
   //hdata.SetFile("/work/jlab/clas12data/skim14_005038.hipo");
   hdata.SetFile("/home/dglazier/fastdata/skim3_005652.hipo");
   hdata.LoadAnaDB("$CHANSER/rga_actions/anadb/RGA_ACTIONS_PASS1.db");
   hdata.LoadAnaDB("$CHANSER/anadbs/RunPeriodPass1.db");
   
   //hdata.SetFile("/work/jlab/clas12data/adamtsim/EptoXto2pi_54.hipo");
   hdata.Reader()->useFTBased();	


   ////create FinalStateManager
  ////we can load as many saved final states as we like
  FinalStateManager fsm;
  fsm.SetBaseOutDir("/work/dump/WithDGCodeSim");
  ////Connect the data to the manager
  fsm.LoadData(&hdata);

  ////load one or more FinalStates
  fsm.LoadFinalState("Pi2","Pi2_NONE_ALL_STel.root");

  //Max number of particles of any 1 species
  //Whole event disgarded if this not met.
  //fsm.GetEventParticles().SetMaxParticles(8);

  ////Run through all events
  fsm.ProcessAll();


}
