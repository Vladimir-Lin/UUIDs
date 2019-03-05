#include "UUIDs.hpp"
#include "PrivateUUIDs.hpp"

typedef struct              {
  ManageDestroyers * manage ;
} PrivateDestroyers         ;

typedef struct    {
  int      Type   ;
  Convoy * convoy ;
} ConvoyGuard     ;

static std::map<std::string,Convoy *> StaticConvoy ;

Convoy:: Convoy        ( void    )
       : Destroyer     (         )
       , PrivatePacket ( nullptr )
{
  ConvoyGuard * cg = new ConvoyGuard ( ) ;
  cg -> Type   = 0                       ;
  cg -> convoy = this                    ;
  PrivateGuard = (void *) cg             ;
}

Convoy:: Convoy        ( std::string key )
       : Destroyer     (                 )
       , PrivatePacket ( nullptr         )
       , ConvoyKey     ( key             )
{
  ConvoyGuard * cg = new ConvoyGuard ( ) ;
  cg -> Type   = 0                       ;
  cg -> convoy = this                    ;
  PrivateGuard = (void *) cg             ;
}

Convoy::~Convoy(void)
{
  if ( nullptr != this -> PrivatePacket )                        {
    PrivateDestroyers * pd = (PrivateDestroyers *) PrivatePacket ;
    if ( nullptr != pd -> manage )                               {
      delete pd -> manage                                        ;
      pd -> manage = nullptr                                     ;
    }                                                            ;
    delete pd                                                    ;
    this -> PrivatePacket = nullptr                              ;
  }                                                              ;
  ////////////////////////////////////////////////////////////////
  if ( nullptr != this -> PrivateGuard )                         {
    ConvoyGuard * cg = (ConvoyGuard *) this -> PrivateGuard      ;
    delete cg                                                    ;
    this -> PrivateGuard = nullptr                               ;
  }                                                              ;
}

void Convoy::setKey(std::string key)
{
  ConvoyKey = key ;
}

std::string Convoy::Key(void) const
{
  return ConvoyKey ;
}

bool Convoy::Interrupt(void)
{
  return Discontinue ( ) ;
}

bool Convoy::Recycling(void)
{
  return Eliminate ( ) ;
}

bool Convoy::Destructor(void)
{
  return true ;
}

void * Convoy::Register(void *)
{
  return nullptr ;
}

int Convoy::Join(Destroyer * destroyer)
{
  if ( nullptr == this -> PrivatePacket ) return 0                     ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  if ( nullptr == pd   -> manage        ) return 0                     ;
  return int ( pd -> manage -> add ( destroyer ) )                     ;
}

int Convoy::Remove(Destroyer * destroyer)
{
  if ( nullptr == this -> PrivatePacket ) return 0                     ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  if ( nullptr == pd   -> manage        ) return 0                     ;
  return int ( pd -> manage -> remove ( destroyer ) )                  ;
}

Destroyer * Convoy::Visit(int index)
{
  if ( nullptr == this -> PrivatePacket ) return nullptr               ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  if ( nullptr == pd   -> manage        ) return nullptr               ;
  return pd -> manage -> at ( index )                                  ;
}

void * Convoy::Guard(void)
{
  return this -> PrivateGuard ;
}

bool Convoy::Prepare(void)
{
  if ( nullptr != this -> PrivatePacket ) return false ;
  PrivateDestroyers * pd = new PrivateDestroyers ( )   ;
  pd -> manage = new ManageDestroyers ( )              ;
  this -> PrivatePacket = (void *) pd                  ;
  return true                                          ;
}

bool Convoy::Discontinue(void)
{
  if ( nullptr == this -> PrivatePacket ) return false                 ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  //////////////////////////////////////////////////////////////////////
  if ( nullptr != pd -> manage )                                       {
    pd -> manage -> discontinue ( )                                    ;
  }                                                                    ;
  //////////////////////////////////////////////////////////////////////
  return true                                                          ;
}

bool Convoy::Eliminate(void)
{
  if ( nullptr == this -> PrivatePacket ) return false                 ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  //////////////////////////////////////////////////////////////////////
  if ( nullptr != pd -> manage )                                       {
    pd -> manage -> clean ( )                                          ;
    ////////////////////////////////////////////////////////////////////
    delete pd -> manage                                                ;
    pd -> manage = nullptr                                             ;
  }                                                                    ;
  delete pd                                                            ;
  this -> PrivatePacket = nullptr                                      ;
  //////////////////////////////////////////////////////////////////////
  return true                                                          ;
}

int Convoy::Survived(void) const
{
  if ( nullptr == this -> PrivatePacket ) return 0                     ;
  PrivateDestroyers * pd = (PrivateDestroyers *) this -> PrivatePacket ;
  if ( nullptr == pd   -> manage        ) return 0                     ;
  return int ( pd -> manage -> count ( ) )                             ;
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
  if ( nullptr == convoy ) return 0        ;
  return  convoy -> Join ( destroyer )     ;
}

int Convoy::remove(std::string key,Destroyer * destroyer)
{
  Convoy * convoy = Convoy::find ( key ) ;
  if ( nullptr == convoy ) return 0        ;
  return  convoy -> Remove ( destroyer )   ;
}
