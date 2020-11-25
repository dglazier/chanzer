#include "Cut_RefineElectronID.h"

namespace chanser{

    double _ecal_e_sampl_mu[3][6] = {
      {  0.2531 ,  0.2550 ,  0.2514 ,  0.2494,  0.2528 ,  0.2521 },
      { -0.6502 , -0.7472 , -0.7674 , -0.4913, -0.3988 , -0.703  },
      {  4.939  ,  5.350  ,  5.102  ,  6.440 ,  6.149  ,  4.957  }
    };

    double _ecal_e_sampl_sigma[3][6] = {
        {  2.726e-3 ,  4.157e-3 ,  5.222e-3 , 5.398e-3 ,  8.453e-3 ,  6.533e-3 },
        {  1.062    ,  0.859    ,  0.5564   , 0.6576   ,  0.3242   ,  0.4423   },
        { -4.089    , -3.318    , -2.078    ,-2.565    , -0.8223   , -1.274    }
    };

}
 
