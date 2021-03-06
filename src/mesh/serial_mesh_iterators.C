// The libSerialMesh Finite Element Library.
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

// Local includes
// #include "libmesh/mesh_base.h"
#include "libmesh/serial_mesh.h"
#include "libmesh/elem.h"

namespace libMesh
{

// This file contains the implementation of all the different iterator
// functions for the mesh class.  They were put here to save space in the
// header files.


// default begin() accessor
SerialMesh::element_iterator
SerialMesh::elements_begin ()
{
  Predicates::NotNull<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// active elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_elements_begin ()
{
  Predicates::Active<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// not active elements begin() accessor
SerialMesh::element_iterator
SerialMesh::not_active_elements_begin ()
{
  Predicates::NotActive<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// ancestor elements begin() accessor
SerialMesh::element_iterator
SerialMesh::ancestor_elements_begin ()
{
  Predicates::Ancestor<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// not ancestor elements begin() accessor
SerialMesh::element_iterator
SerialMesh::not_ancestor_elements_begin ()
{
  Predicates::Ancestor<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// subactive elements begin() accessor
SerialMesh::element_iterator
SerialMesh::subactive_elements_begin ()
{
  Predicates::SubActive<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// not subactive elements begin() accessor
SerialMesh::element_iterator
SerialMesh::not_subactive_elements_begin ()
{
  Predicates::NotSubActive<elem_iterator_imp> p;
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// local elements begin() accessor
SerialMesh::element_iterator
SerialMesh::local_elements_begin ()
{
  Predicates::Local<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// not_local elements begin() accessor
SerialMesh::element_iterator
SerialMesh::not_local_elements_begin ()
{
  Predicates::NotLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// active local elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_local_elements_begin ()
{
  Predicates::ActiveLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// active_not_local elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_not_local_elements_begin ()
{
  Predicates::ActiveNotLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// level elements begin() accessor
SerialMesh::element_iterator
SerialMesh::level_elements_begin (const unsigned int level)
{
  Predicates::Level<elem_iterator_imp> p(level);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// not level elements begin() accessor
SerialMesh::element_iterator
SerialMesh::not_level_elements_begin (const unsigned int level)
{
  Predicates::NotLevel<elem_iterator_imp> p(level);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// local level elements begin() accessor
SerialMesh::element_iterator
SerialMesh::local_level_elements_begin (const unsigned int level)
{
  Predicates::LocalLevel<elem_iterator_imp> p(this->processor_id(),level);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// local not level elements begin() accessor
SerialMesh::element_iterator
SerialMesh::local_not_level_elements_begin (const unsigned int level)
{
  Predicates::LocalNotLevel<elem_iterator_imp> p(this->processor_id(),level);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// pid elements begin() accessor
SerialMesh::element_iterator
SerialMesh::pid_elements_begin (const processor_id_type proc_id)
{
  Predicates::PID<elem_iterator_imp> p(proc_id);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// type elements begin() accessor
SerialMesh::element_iterator
SerialMesh::type_elements_begin (const ElemType type)
{
  Predicates::Type<elem_iterator_imp> p(type);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// active type elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_type_elements_begin (const ElemType type)
{
  Predicates::ActiveType<elem_iterator_imp> p(type);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// active pid elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_pid_elements_begin (const processor_id_type proc_id)
{
  Predicates::ActivePID<elem_iterator_imp> p(proc_id);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// unpartitioned elements begin() accessor
SerialMesh::element_iterator
SerialMesh::unpartitioned_elements_begin ()
{
  return this->pid_elements_begin(DofObject::invalid_processor_id);
}



// subdomain elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_local_subdomain_elements_begin (const subdomain_id_type subdomain_id)
{
  Predicates::ActiveLocalSubdomain<elem_iterator_imp> p(this->processor_id(),subdomain_id);
  return element_iterator(_elements.begin(), _elements.end(), p);
}



// subdomain elements begin() accessor
SerialMesh::element_iterator
SerialMesh::active_subdomain_elements_begin (const subdomain_id_type subdomain_id)
{
  Predicates::ActiveSubdomain<elem_iterator_imp> p(subdomain_id);
  return element_iterator(_elements.begin(), _elements.end(), p);
}







// default const begin() accessor
SerialMesh::const_element_iterator
SerialMesh::elements_begin () const
{
  Predicates::NotNull<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const active begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_elements_begin () const
{
  Predicates::Active<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const not active begin() accessor
SerialMesh::const_element_iterator
SerialMesh::not_active_elements_begin () const
{
  Predicates::NotActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const ancestor begin() accessor
SerialMesh::const_element_iterator
SerialMesh::ancestor_elements_begin () const
{
  Predicates::Ancestor<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const not ancestor begin() accessor
SerialMesh::const_element_iterator
SerialMesh::not_ancestor_elements_begin () const
{
  Predicates::Ancestor<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const subactive begin() accessor
SerialMesh::const_element_iterator
SerialMesh::subactive_elements_begin () const
{
  Predicates::SubActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const not subactive begin() accessor
SerialMesh::const_element_iterator
SerialMesh::not_subactive_elements_begin () const
{
  Predicates::NotSubActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const local begin() accessor
SerialMesh::const_element_iterator
SerialMesh::local_elements_begin () const
{
  Predicates::Local<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const not_local begin() accessor
SerialMesh::const_element_iterator
SerialMesh::not_local_elements_begin () const
{
  Predicates::NotLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const active local begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_local_elements_begin () const
{
  Predicates::ActiveLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const active not_local begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_not_local_elements_begin () const
{
  Predicates::ActiveNotLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const level begin() accessor
SerialMesh::const_element_iterator
SerialMesh::level_elements_begin (const unsigned int level) const
{
  Predicates::Level<const_elem_iterator_imp> p(level);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const not level begin() accessor
SerialMesh::const_element_iterator
SerialMesh::not_level_elements_begin (const unsigned int level) const
{
  Predicates::NotLevel<const_elem_iterator_imp> p(level);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const local level begin() accessor
SerialMesh::const_element_iterator
SerialMesh::local_level_elements_begin (const unsigned int level) const
{
  Predicates::LocalLevel<const_elem_iterator_imp> p(this->processor_id(),level);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const local not level begin() accessor
SerialMesh::const_element_iterator
SerialMesh::local_not_level_elements_begin (const unsigned int level) const
{
  Predicates::LocalNotLevel<const_elem_iterator_imp> p(this->processor_id(),level);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const pid begin() accessor
SerialMesh::const_element_iterator
SerialMesh::pid_elements_begin (const processor_id_type proc_id) const
{
  Predicates::PID<const_elem_iterator_imp> p(proc_id);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const type begin() accessor
SerialMesh::const_element_iterator
SerialMesh::type_elements_begin (const ElemType type) const
{
  Predicates::Type<const_elem_iterator_imp> p(type);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const active type begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_type_elements_begin (const ElemType type) const
{
  Predicates::ActiveType<const_elem_iterator_imp> p(type);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const active pid elements begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_pid_elements_begin (const processor_id_type proc_id) const
{
  Predicates::ActivePID<const_elem_iterator_imp> p(proc_id);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// const unpartitioned elements begin() accessor
SerialMesh::const_element_iterator
SerialMesh::unpartitioned_elements_begin () const
{
  return this->pid_elements_begin(DofObject::invalid_processor_id);
}



// subdomain elements begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_local_subdomain_elements_begin (const subdomain_id_type subdomain_id) const
{
  Predicates::ActiveLocalSubdomain<const_elem_iterator_imp> p(this->processor_id(),subdomain_id);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}



// subdomain elements begin() accessor
SerialMesh::const_element_iterator
SerialMesh::active_subdomain_elements_begin (const subdomain_id_type subdomain_id) const
{
  Predicates::ActiveSubdomain<const_elem_iterator_imp> p(subdomain_id);
  return const_element_iterator(_elements.begin(), _elements.end(), p);
}







// default end() accessor
SerialMesh::element_iterator
SerialMesh::elements_end ()
{
  Predicates::NotNull<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// active end() accessor
SerialMesh::element_iterator
SerialMesh::active_elements_end ()
{
  Predicates::Active<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// active end() accessor
SerialMesh::element_iterator
SerialMesh::not_active_elements_end ()
{
  Predicates::NotActive<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// ancestor end() accessor
SerialMesh::element_iterator
SerialMesh::ancestor_elements_end ()
{
  Predicates::Ancestor<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// ancestor end() accessor
SerialMesh::element_iterator
SerialMesh::not_ancestor_elements_end ()
{
  Predicates::Ancestor<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// subactive end() accessor
SerialMesh::element_iterator
SerialMesh::subactive_elements_end ()
{
  Predicates::SubActive<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// subactive end() accessor
SerialMesh::element_iterator
SerialMesh::not_subactive_elements_end ()
{
  Predicates::NotSubActive<elem_iterator_imp> p;
  return element_iterator(_elements.end(), _elements.end(), p);
}



// local end() accessor
SerialMesh::element_iterator
SerialMesh::local_elements_end ()
{
  Predicates::Local<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.end(), _elements.end(), p);
}



// not_local end() accessor
SerialMesh::element_iterator
SerialMesh::not_local_elements_end ()
{
  Predicates::NotLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.end(), _elements.end(), p);
}



// active local end() accessor
SerialMesh::element_iterator
SerialMesh::active_local_elements_end ()
{
  Predicates::ActiveLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.end(), _elements.end(), p);
}



// not_local end() accessor
SerialMesh::element_iterator
SerialMesh::active_not_local_elements_end ()
{
  Predicates::ActiveNotLocal<elem_iterator_imp> p(this->processor_id());
  return element_iterator(_elements.end(), _elements.end(), p);
}



// level end() accessor
SerialMesh::element_iterator
SerialMesh::level_elements_end (const unsigned int level)
{
  Predicates::Level<elem_iterator_imp> p(level);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// not level end() accessor
SerialMesh::element_iterator
SerialMesh::not_level_elements_end (const unsigned int level)
{
  Predicates::NotLevel<elem_iterator_imp> p(level);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// local level end() accessor
SerialMesh::element_iterator
SerialMesh::local_level_elements_end (const unsigned int level)
{
  Predicates::LocalLevel<elem_iterator_imp> p(this->processor_id(),level);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// local not level end() accessor
SerialMesh::element_iterator
SerialMesh::local_not_level_elements_end (const unsigned int level)
{
  Predicates::LocalNotLevel<elem_iterator_imp> p(this->processor_id(),level);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// pid end() accessor
SerialMesh::element_iterator
SerialMesh::pid_elements_end (const processor_id_type proc_id)
{
  Predicates::PID<elem_iterator_imp> p(proc_id);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// type end() accessor
SerialMesh::element_iterator
SerialMesh::type_elements_end (const ElemType type)
{
  Predicates::Type<elem_iterator_imp> p(type);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// active type end() accessor
SerialMesh::element_iterator
SerialMesh::active_type_elements_end (const ElemType type)
{
  Predicates::ActiveType<elem_iterator_imp> p(type);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// active PID end() accessor
SerialMesh::element_iterator
SerialMesh::active_pid_elements_end (const processor_id_type proc_id)
{
  Predicates::ActivePID<elem_iterator_imp> p(proc_id);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// unpartitioned elements end() accessor
SerialMesh::element_iterator
SerialMesh::unpartitioned_elements_end ()
{
  return this->pid_elements_end(DofObject::invalid_processor_id);
}



// subdomain elements end() accessor
SerialMesh::element_iterator
SerialMesh::active_local_subdomain_elements_end (const subdomain_id_type subdomain_id)
{
  Predicates::ActiveLocalSubdomain<elem_iterator_imp> p(this->processor_id(),subdomain_id);
  return element_iterator(_elements.end(), _elements.end(), p);
}



// subdomain elements end() accessor
SerialMesh::element_iterator
SerialMesh::active_subdomain_elements_end (const subdomain_id_type subdomain_id)
{
  Predicates::ActiveSubdomain<elem_iterator_imp> p(subdomain_id);
  return element_iterator(_elements.end(), _elements.end(), p);
}











// default const end() accessor
SerialMesh::const_element_iterator
SerialMesh::elements_end () const
{
  Predicates::NotNull<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// active const end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_elements_end () const
{
  Predicates::Active<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// not active const end() accessor
SerialMesh::const_element_iterator
SerialMesh::not_active_elements_end () const
{
  Predicates::NotActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// ancestor const end() accessor
SerialMesh::const_element_iterator
SerialMesh::ancestor_elements_end () const
{
  Predicates::Ancestor<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// not ancestor const end() accessor
SerialMesh::const_element_iterator
SerialMesh::not_ancestor_elements_end () const
{
  Predicates::Ancestor<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// subactive const end() accessor
SerialMesh::const_element_iterator
SerialMesh::subactive_elements_end () const
{
  Predicates::SubActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// not subactive const end() accessor
SerialMesh::const_element_iterator
SerialMesh::not_subactive_elements_end () const
{
  Predicates::NotSubActive<const_elem_iterator_imp> p;
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// local const end() accessor
SerialMesh::const_element_iterator
SerialMesh::local_elements_end () const
{
  Predicates::Local<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// not_local const end() accessor
SerialMesh::const_element_iterator
SerialMesh::not_local_elements_end () const
{
  Predicates::NotLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// local active const end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_local_elements_end () const
{
  Predicates::ActiveLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// const local active const end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_not_local_elements_end () const
{
  Predicates::ActiveNotLocal<const_elem_iterator_imp> p(this->processor_id());
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// level const end() accessor
SerialMesh::const_element_iterator
SerialMesh::level_elements_end (const unsigned int level) const
{
  Predicates::Level<const_elem_iterator_imp> p(level);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// not level const end() accessor
SerialMesh::const_element_iterator
SerialMesh::not_level_elements_end (const unsigned int level) const
{
  Predicates::NotLevel<const_elem_iterator_imp> p(level);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// local level const end() accessor
SerialMesh::const_element_iterator
SerialMesh::local_level_elements_end (const unsigned int level) const
{
  Predicates::LocalLevel<const_elem_iterator_imp> p(this->processor_id(),level);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// local not level const end() accessor
SerialMesh::const_element_iterator
SerialMesh::local_not_level_elements_end (const unsigned int level) const
{
  Predicates::LocalNotLevel<const_elem_iterator_imp> p(this->processor_id(),level);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// pid const end() accessor
SerialMesh::const_element_iterator
SerialMesh::pid_elements_end (const processor_id_type proc_id) const
{
  Predicates::PID<const_elem_iterator_imp> p(proc_id);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// type const end() accessor
SerialMesh::const_element_iterator
SerialMesh::type_elements_end (const ElemType type) const
{
  Predicates::Type<const_elem_iterator_imp> p(type);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// active type const end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_type_elements_end (const ElemType type) const
{
  Predicates::ActiveType<const_elem_iterator_imp> p(type);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// active PID end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_pid_elements_end (const processor_id_type proc_id) const
{
  Predicates::ActivePID<const_elem_iterator_imp> p(proc_id);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// unpartitioned elements end() accessor
SerialMesh::const_element_iterator
SerialMesh::unpartitioned_elements_end () const
{
  return this->pid_elements_end(DofObject::invalid_processor_id);
}



// subdomain elements end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_local_subdomain_elements_end (const subdomain_id_type subdomain_id) const
{
  Predicates::ActiveLocalSubdomain<const_elem_iterator_imp> p(this->processor_id(),subdomain_id);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}



// subdomain elements end() accessor
SerialMesh::const_element_iterator
SerialMesh::active_subdomain_elements_end (const subdomain_id_type subdomain_id) const
{
  Predicates::ActiveSubdomain<const_elem_iterator_imp> p(subdomain_id);
  return const_element_iterator(_elements.end(), _elements.end(), p);
}






// default nodes begin() accessor
SerialMesh::node_iterator
SerialMesh::nodes_begin ()
{
  Predicates::NotNull<node_iterator_imp> p;
  return node_iterator(_nodes.begin(), _nodes.end(), p);
}



// active nodes begin() accessor
SerialMesh::node_iterator
SerialMesh::active_nodes_begin ()
{
  Predicates::Active<node_iterator_imp> p;
  return node_iterator(_nodes.begin(), _nodes.end(), p);
}



// local nodes begin() accessor
SerialMesh::node_iterator
SerialMesh::local_nodes_begin ()
{
  Predicates::Local<node_iterator_imp> p(this->processor_id());
  return node_iterator(_nodes.begin(), _nodes.end(), p);
}



// pid nodes begin() accessor
SerialMesh::node_iterator
SerialMesh::pid_nodes_begin (const processor_id_type proc_id)
{
  Predicates::PID<node_iterator_imp> p(proc_id);
  return node_iterator(_nodes.begin(), _nodes.end(), p);
}



// default const nodes begin() accessor
SerialMesh::const_node_iterator
SerialMesh::nodes_begin () const
{
  Predicates::NotNull<const_node_iterator_imp> p;
  return const_node_iterator(_nodes.begin(), _nodes.end(), p);
}



// active const nodes begin() accessor
SerialMesh::const_node_iterator
SerialMesh::active_nodes_begin () const
{
  Predicates::Active<const_node_iterator_imp> p;
  return const_node_iterator(_nodes.begin(), _nodes.end(), p);
}



// local const nodes begin() accessor
SerialMesh::const_node_iterator
SerialMesh::local_nodes_begin () const
{
  Predicates::Local<const_node_iterator_imp> p(this->processor_id());
  return const_node_iterator(_nodes.begin(), _nodes.end(), p);
}



// pid const nodes begin() accessor
SerialMesh::const_node_iterator
SerialMesh::pid_nodes_begin (const processor_id_type proc_id) const
{
  Predicates::PID<const_node_iterator_imp> p(proc_id);
  return const_node_iterator(_nodes.begin(), _nodes.end(), p);
}



// default nodes end() accessor
SerialMesh::node_iterator
SerialMesh::nodes_end ()
{
  Predicates::NotNull<node_iterator_imp> p;
  return node_iterator(_nodes.end(), _nodes.end(), p);
}



// active nodes end() accessor
SerialMesh::node_iterator
SerialMesh::active_nodes_end ()
{
  Predicates::Active<node_iterator_imp> p;
  return node_iterator(_nodes.end(), _nodes.end(), p);
}



// local nodes end() accessor
SerialMesh::node_iterator
SerialMesh::local_nodes_end ()
{
  Predicates::Local<node_iterator_imp> p(this->processor_id());
  return node_iterator(_nodes.end(), _nodes.end(), p);
}



// pid nodes end() accessor
SerialMesh::node_iterator
SerialMesh::pid_nodes_end (const processor_id_type proc_id)
{
  Predicates::PID<node_iterator_imp> p(proc_id);
  return node_iterator(_nodes.end(), _nodes.end(), p);
}



// default const nodes end() accessor
SerialMesh::const_node_iterator
SerialMesh::nodes_end () const
{
  Predicates::NotNull<const_node_iterator_imp> p;
  return const_node_iterator(_nodes.end(), _nodes.end(), p);
}



// const active nodes end() accessor
SerialMesh::const_node_iterator
SerialMesh::active_nodes_end () const
{
  Predicates::Active<const_node_iterator_imp> p;
  return const_node_iterator(_nodes.end(), _nodes.end(), p);
}



// local const nodes end() accessor
SerialMesh::const_node_iterator
SerialMesh::local_nodes_end () const
{
  Predicates::Local<const_node_iterator_imp> p(this->processor_id());
  return const_node_iterator(_nodes.end(), _nodes.end(), p);
}



// pid const nodes end() accessor
SerialMesh::const_node_iterator
SerialMesh::pid_nodes_end (const processor_id_type proc_id) const
{
  Predicates::PID<const_node_iterator_imp> p(proc_id);
  return const_node_iterator(_nodes.end(), _nodes.end(), p);
}

} // namespace libMesh
