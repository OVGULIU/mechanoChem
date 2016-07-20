//extern "C" {
#include "petiga.h"
//}

#include "applicationHeaders.h"
//include automatic differentiation library
#include <Sacado.hpp>

int defineParameters(AppCtx& user){

  PetscErrorCode ierr;
 
	user.dim = 3;
	user.GridScale = 1.0;
	user.ADSacado = PETSC_TRUE;
	user.numVars = 162;
	user.uDirichlet = 0.1;
	user.NVal = 2;
	user.dtVal = 0.01;
	user.skipOutput = 1;
	user.RESTART_IT = 0;
	user.RESTART_TIME = 0.;
	user.beamRatio = 1; //Ratio of length to width of beam. Keep it an integer to make setting the number of elements easy.

	//Anisotropic St. Venant-Kirchhoff
	user.matParam["mu"] = 1e5;
	user.matParam["betaC"] = 1e5;
	user.matParam["alphaC"] = 2e5;
	user.matParam["anisoCoeff"] = 5.;

	//Nonconvex free energy parameters
	user.matParam["Es"] = 0.01;
	user.matParam["Ed"] = 1.0;
	user.matParam["El"] = sqrt(1.5/(user.matParam["Es"]*user.matParam["Es"]));

  return 0;
}