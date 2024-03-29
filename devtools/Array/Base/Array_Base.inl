// -*- C++ -*-
//$Id: Array_Base.inl 2023-10-3 by Tristan Kolat$

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
//size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
  return this->cur_size_;
}

//
//max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
  return this->max_size_;
}