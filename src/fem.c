#include "fem.h"

ecode ierr;

/** Input variables **/
/* dim = number of dimensions
 * nen = number of elemental nodes
 * ne  = number of elements
 * nn  = number of nodes
 * nnd = number of nodal DOF */
integer dim, nen, ne, nn, nnd; 

/** Output variables **/
/* ned   = number of elemental DOF
 * ntdof = number of todal DOF
 * nfdof = number of free DOF
 * nsdof = number of constrained DOF */
integer ned, ntdof, nfdof, nsdof;

ecode FEMInitialize()
{
  ierr = FEMDefault(); CHKERRQ(ierr);

  return 0;
}

ecode FEMFinalize()
{

  return 0;
}


ecode FEMPreprocess()
{
  ned   = nen*nnd;
  ntdof = nn*nnd;
  return 0;
}

ecode FEMDefault()
{
  dim = 1;
  nnd = 1;
  nen = QUAD1D;
  return 0;
}


/* Set functions */
ecode FEMSetDimension(integer _dim)
{
  dim = _dim;
  return 0;
}

ecode FEMSetNumberOfNodalDOF(integer _nnd)
{
  nnd=_nnd;
  return 0;
}

ecode FEMSetNumberOfNodes(integer _nn)
{
  nn=_nn;
  return 0;
}

ecode FEMSetNumberOfElements(integer _ne)
{
  ne=_ne;
  return 0;
}

ecode FEMSetNumberOfNodesPerElements(integer _nen)
{
  nen = _nen;
  return 0;
}

/* Get functions */
