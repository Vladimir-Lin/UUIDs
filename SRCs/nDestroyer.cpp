#include "UUIDs.hpp"

Destroyer:: Destroyer(void)
{
}

Destroyer::~Destroyer(void)
{
  this -> Destructor ( ) ;
}

bool Destroyer::Interrupt(void)
{
  return true ;
}

bool Destroyer::Recycling(void)
{
  return true ;
}

bool Destroyer::Destructor(void)
{
  return true ;
}

void * Destroyer::Register(void *)
{
  return nullptr ;
}
