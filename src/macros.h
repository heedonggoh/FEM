#ifndef MACROS_H
#define MACROS_H

#include <petsc.h>

#define boolean PetscBool
#define integer PetscInt
#define real PetscReal
#define scalar PetscScalar
#define True PETSC_TRUE
#define False PETSC_FALSE
#define ecode PetscErrorCode
#define iI PETSC_i

#define BOLD    "\033[1m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define WHITE   "\x1b[37m"
#define BBLACK  "\x1b[40m"
#define BRED    "\x1b[41m"
#define BGREEN  "\x1b[42m"
#define BYELLOW "\x1b[43m"
#define BBLUE   "\x1b[44m"
#define BWHITE  "\x1b[47m"
#define RESET   "\x1b[0m"

#define wprintf(f_, ...) PetscPrintf(PETSC_COMM_WORLD,f_,__VA_ARGS__)
#define wfprintf(f_,g_, ...) PetscFPrintf(PETSC_COMM_WORLD,f_,g_,__VA_ARGS__)
#define wmessage(f_) PetscPrintf(PETSC_COMM_WORLD,f_)
#define wfmessage(f_,g_) PetscFPrintf(PETSC_COMM_WORLD,f_,g_)
#define werror(f_)   PetscPrintf(PETSC_COMM_WORLD,"\n" RED BOLD f_ RESET "\n")
#define serror(f_)   PetscPrintf(PETSC_COMM_SELF,"\n" RED BOLD f_ RESET "\n")
#define sfmessage(f_,g_) PetscFPrintf(PETSC_COMM_SELF,f_,g_)
#define ssprintf(f_, ...) PetscPrintf(PETSC_COMM_SELF,f_,__VA_ARGS__)
#define syprintf(f_, ...) PetscSynchronizedPrintf(PETSC_COMM_WORLD,f_,__VA_ARGS__)
#define sfprintf(f_,g_, ...) PetscFPrintf(PETSC_COMM_SELF,f_,g_,__VA_ARGS__)
#define syfprintf(f_,g_, ...) PetscSynchronizedFPrintf(PETSC_COMM_WORLD,f_,g_,__VA_ARGS__)
#define sypflush(f_) PetscSynchronizedFlush(PETSC_COMM_WORLD,PETSC_STDOUT)


#define wmatview(f_) MatView(f_,PETSC_VIEWER_STDOUT_WORLD)
#define smatview(f_) MatView(f_,PETSC_VIEWER_STDOUT_SELF)
#define wvecview(f_) VecView(f_,PETSC_VIEWER_STDOUT_WORLD)
#define svecview(f_) VecView(f_,PETSC_VIEWER_STDOUT_SELF)

#endif
