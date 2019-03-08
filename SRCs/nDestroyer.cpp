#include "UUIDs.hpp"

#pragma pack(push,1)

#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace PARALLEL_NAMESPACE {
#endif

Destroyer:: Destroyer(void)
{
}

Destroyer::~Destroyer(void)
{
  Destructor ( ) ;
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

#ifndef DONT_USE_NAMESPACE
}
#endif
