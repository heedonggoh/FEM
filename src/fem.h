#ifndef FEM_H
#define FEM_H

#include <petsc.h>

#define boolean PetscBool
#define integer PetscInt
#define real PetscReal
#define scalar PetscScalar
#define True PETSC_TRUE
#define False PETSC_FALSE
#define ecode PetscErrorCode
#define iI PETSC_i

enum ElementType { CONST1D = 1, LIN1D = 2, QUAD1D = 3 };

/* Public functions */
ecode FEMInitialize();
ecode FEMFinalize();
ecode FEMPreprocess();


/* Private functions */
ecode FEMDefault();


/* Set functions */
ecode FEMSetDimension(integer _dim);
ecode FEMSetNumberOfElements(integer _ne);
ecode FEMSetNumberOfNodalDOF(integer _nnd);
ecode FEMSetNumberOfNodes(integer _nn);
ecode FEMSetNumberOfNodesPerElements(integer _nen);

/* Get functions */

#endif

