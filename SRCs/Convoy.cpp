#include "UUIDs.hpp"
#include "PrivateUUIDs.hpp"

static std::map<std::string,Convoy *> StaticConvoy ;

Convoy:: Convoy        ( void    )
       : Destroyer     (         )
       , PrivatePacket ( nullptr )
{
}

Convoy::~Convoy(void)
{
  if ( nullptr != PrivatePacket ) {
  }
}

bool Convoy::Interrupt(void)
{
  return true ;
}

bool Convoy::Recycling(void)
{
  return true ;
}

bool Convoy::Destructor(void)
{
  return true ;
}

void * Convoy::Register(void *)
{
  return nullptr ;
}

int Convoy::Join(Destroyer *)
{
  return 0 ;
}

int Convoy::Remove(Destroyer *)
{
  return 0 ;
}

bool Convoy::Prepare(void)
{
  return true ;
}

bool Convoy::Discontinue(void)
{
  return true ;
}

bool Convoy::Eliminate(void)
{
  return true ;
}

int Convoy::Survived(void) const
{
  return 0 ;
}

bool Convoy::add(std::string key,Convoy * convoy)
{
  if ( nullptr == convoy ) return false ;
  StaticConvoy [ key ] = convoy         ;
  return true                           ;
}

bool Convoy::remove(std::string key)
{
  std::map<std::string,Convoy *>::iterator it      ;
  it = StaticConvoy . find ( key )                 ;
  if ( it == StaticConvoy . end ( ) ) return false ;
  StaticConvoy . erase ( it )                      ;
  return true                                      ;
}

Convoy * Convoy::find(std::string key)
{
  std::map<std::string,Convoy *>::iterator it        ;
  it = StaticConvoy . find ( key )                   ;
  if ( it == StaticConvoy . end ( ) ) return nullptr ;
  return StaticConvoy [ key ]                        ;
}

int Convoy::join(std::string key,Destroyer * destroyer)
{
  Convoy * convoy = Convoy::find ( key ) ;
  if ( nullptr == convoy ) return 0      ;
  return  convoy -> Join ( destroyer )   ;
}

int Convoy::remove(std::string key,Destroyer * destroyer)
{
  Convoy * convoy = Convoy::find ( key ) ;
  if ( nullptr == convoy ) return 0      ;
  return  convoy -> Remove ( destroyer ) ;
}
