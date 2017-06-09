#include <unistd.h>
#include <sys/types.h>
#include "macros.h"
#include "fem.h"

static char help[] = 
  "\n------------------------------------------------------------------------------\n\
 FEM module \n\
                                         by Heedong Goh <wellposed@gmail.com> \n\
------------------------------------------------------------------------------\n";

ecode GetProcInfo(integer* pCPURank, integer* pCPUsize);

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc, char **args)
{
  ecode ierr;
  char title[50];
  integer CPURank, CPUsize;
  ierr = PetscInitialize(&argc,&args,(char*)0,help);  CHKERRQ(ierr);
  ierr = GetProcInfo(&CPURank, &CPUsize);             CHKERRQ(ierr);

  ierr = FEMInitialize(); CHKERRQ(ierr);
  ierr = FEMFinalize();   CHKERRQ(ierr);

  ierr = wmessage("\n" BOLD "The end." RESET "\n\n"); CHKERRQ(ierr);
  ierr = PetscFinalize();                             CHKERRQ(ierr);
  return 0;
}

ecode GetProcInfo(integer* pCPURank, integer* pCPUsize)
{
  ecode ierr;
  ierr = MPI_Comm_size(PETSC_COMM_WORLD,pCPUsize);                 CHKERRQ(ierr);
  ierr = MPI_Comm_rank(PETSC_COMM_WORLD,pCPURank);                 CHKERRQ(ierr);
  ierr = wprintf("\n" BLUE "cpu size = %ld" RESET "\n",*pCPUsize); CHKERRQ(ierr);
  ierr = syprintf(BLUE "cpu %d:\tpid = %ld, ppid = %ld" RESET "\n",
		  *pCPURank,(long)getpid(),(long)getppid());       CHKERRQ(ierr); 
  ierr = sypflush();                                               CHKERRQ(ierr); 
  return 0;
}
