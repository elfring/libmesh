// The libMesh Finite Element Library.
// Copyright (C) 2002-2012 Benjamin S. Kirk, John W. Peterson, Roy H. Stogner

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



// C++ includes

// Local Includes
#include "libmesh/nonlinear_solver.h"
#include "libmesh/petsc_nonlinear_solver.h"
#include "libmesh/petsc_dm_nonlinear_solver.h"
#include "libmesh/trilinos_nox_nonlinear_solver.h"
#include "libmesh/auto_ptr.h"

namespace libMesh
{


//------------------------------------------------------------------
// NonlinearSolver members
#if defined(LIBMESH_HAVE_PETSC) || defined(LIBMESH_HAVE_NOX)
template <typename T>
AutoPtr<NonlinearSolver<T> >
NonlinearSolver<T>::build(sys_type& s, const SolverPackage solver_package)
{
  AutoPtr<NonlinearSolver<T> > ap;

  // Build the appropriate solver
  switch (solver_package)
    {

#ifdef LIBMESH_HAVE_PETSC
    case PETSC_SOLVERS:
#if PETSC_VERSION_LESS_THAN(3,3,0)
      ap.reset(new PetscNonlinearSolver<T>(s));
      break;
#else
      if (libMesh::on_command_line ("--use-petsc-dm")){
	ap.reset(new PetscDMNonlinearSolver<T>(s));
      }
      else {
	ap.reset(new PetscNonlinearSolver<T>(s));
      }
      break;
#endif
#endif // LIBMESH_HAVE_PETSC

#ifdef LIBMESH_HAVE_NOX
    case TRILINOS_SOLVERS:
      ap.reset(new NoxNonlinearSolver<T>(s));
      break;
#endif

    default:
      libMesh::err << "ERROR:  Unrecognized solver package: "
		    << solver_package
		    << std::endl;
      libmesh_error();
    }

  return ap;
}
#else // LIBMESH_HAVE_PETSC || LIBMESH_HAVE_NOX
template <typename T>
AutoPtr<NonlinearSolver<T> >
NonlinearSolver<T>::build(sys_type&, const SolverPackage)
{
  libMesh::err << "ERROR: libMesh was compiled without nonlinear solver support"
	        << std::endl;
  libmesh_not_implemented();
}
#endif


template <typename T>
void
NonlinearSolver<T>::attach_preconditioner(Preconditioner<T> * preconditioner)
{
  if(this->_is_initialized)
  {
    libMesh::err << "Preconditioner must be attached before the solver is initialized!"<<std::endl;
    libmesh_error();
  }

  _preconditioner = preconditioner;
}


//------------------------------------------------------------------
// Explicit instantiations
template class NonlinearSolver<Number>;

} // namespace libMesh
