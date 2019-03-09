#include "PrivateUUIDs.hpp"

PrivateEnabler:: PrivateEnabler(void)
{
  this -> shouldLock = true              ;
  ::InitializeCriticalSection ( &mutex ) ;
}

PrivateEnabler::~PrivateEnabler(void)
{
  ::DeleteCriticalSection ( &mutex ) ;
}

void PrivateEnabler::lock(void)
{
  if ( ! this -> shouldLock ) return ;
  ::EnterCriticalSection ( &mutex )  ;
}

void PrivateEnabler::unlock(void)
{
  if ( ! this -> shouldLock ) return ;
  ::LeaveCriticalSection ( &mutex )  ;
}

void PrivateEnabler::clear(void)
{
  this -> lock                     ( ) ;
  this -> PrivateEnablings . clear ( ) ;
  this -> UuidEnablings    . clear ( ) ;
  this -> StringEnablings  . clear ( ) ;
  this -> unlock                   ( ) ;
}

bool PrivateEnabler::hasEnabled(int Id)
{
  std::map<int,bool>::iterator it                              ;
  it = this -> PrivateEnablings . find ( Id )                  ;
  if ( it == this -> PrivateEnablings . end ( ) ) return false ;
  return true                                                  ;
}

bool PrivateEnabler::hasEnabled(SUID Id)
{
  std::map<SUID,bool>::iterator it                          ;
  it = this -> UuidEnablings . find ( Id )                  ;
  if ( it == this -> UuidEnablings . end ( ) ) return false ;
  return true                                               ;
}

bool PrivateEnabler::hasEnabled(std::string Id)
{
  std::map<std::string,bool>::iterator it                     ;
  it = this -> StringEnablings . find ( Id )                  ;
  if ( it == this -> StringEnablings . end ( ) ) return false ;
  return true                                                 ;
}

bool PrivateEnabler::isAllTrue(void)
{
  bool result = false                                                        ;
  lock   ( )                                                                 ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<int,bool>::iterator iti                                           ;
  for ( iti  = PrivateEnablings . begin ( )                                  ;
        iti != PrivateEnablings . end   ( )                                  ;
        ++iti                                                              ) {
    if ( ! iti -> second ) return false                                      ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<SUID,bool>::iterator itu                                          ;
  for ( itu  = UuidEnablings . begin ( )                                     ;
        itu != UuidEnablings . end   ( )                                     ;
        ++itu                                                              ) {
    if ( ! itu -> second ) return false                                      ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<std::string,bool>::iterator its                                   ;
  for ( its  = StringEnablings . begin ( )                                   ;
        its != StringEnablings . end   ( )                                   ;
        ++its                                                              ) {
    if ( ! its -> second ) return false                                      ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  unlock ( )                                                                 ;
  return result                                                              ;
}

bool PrivateEnabler::isAllFalse(void)
{
  bool result = false                                                        ;
  lock   ( )                                                                 ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<int,bool>::iterator iti                                           ;
  for ( iti  = PrivateEnablings . begin ( )                                  ;
        iti != PrivateEnablings . end   ( )                                  ;
        ++iti                                                              ) {
    if ( iti -> second ) return false                                        ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<SUID,bool>::iterator itu                                          ;
  for ( itu  = UuidEnablings . begin ( )                                     ;
        itu != UuidEnablings . end   ( )                                     ;
        ++itu                                                              ) {
    if ( itu -> second ) return false                                        ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  std::map<std::string,bool>::iterator its                                   ;
  for ( its  = StringEnablings . begin ( )                                   ;
        its != StringEnablings . end   ( )                                   ;
        ++its                                                              ) {
    if ( its -> second ) return false                                        ;
    result = true                                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  unlock ( )                                                                 ;
  return result                                                              ;
}
