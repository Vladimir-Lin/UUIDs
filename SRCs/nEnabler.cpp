#include "PrivateUUIDs.hpp"

typedef struct             {
  PrivateEnabler * enabler ;
} PrivateHandler           ;

static bool alwaysFalse = false ;

Enabler:: Enabler(bool lock)
{
  PrivateHandler * ph = new PrivateHandler ( )            ;
  this -> PrivatePacket = reinterpret_cast<void *> ( ph ) ;
  ph -> enabler  = new PrivateEnabler ( )                 ;
  ph -> enabler -> shouldLock = lock                      ;
}

Enabler::~Enabler(void)
{
  if ( nullptr != this -> PrivatePacket )                             {
    PrivateHandler * ph                                               ;
    ph = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
    delete ph -> enabler                                              ;
    delete ph                                                         ;
    this -> PrivatePacket = nullptr                                   ;
  }                                                                   ;
}

void Enabler::clear (void)
{
  if ( nullptr == this -> PrivatePacket ) return                     ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> clear ( )                                         ;
}

bool Enabler::setEnabled(int Id,bool enable)
{
  if ( nullptr == this -> PrivatePacket ) return enable              ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> lock   ( )                                        ;
  ph -> enabler -> PrivateEnablings [ Id ] = enable                  ;
  ph -> enabler -> unlock ( )                                        ;
  return enable                                                      ;
}

bool Enabler::hasEnabled(int Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> hasEnabled ( Id )                          ;
}

bool Enabler::isEnabled(int Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) ) return false           ;
  bool enabled                                                       ;
  ph     -> enabler -> lock   ( )                                    ;
  enabled = ph -> enabler -> PrivateEnablings [ Id ]                 ;
  ph     -> enabler -> unlock ( )                                    ;
  return enabled                                                     ;
}

bool & Enabler::operator [ ] (int Id)
{
  if ( nullptr == this -> PrivatePacket ) return alwaysFalse         ;
  ////////////////////////////////////////////////////////////////////
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) )                        {
    ph -> enabler -> PrivateEnablings [ Id ] = false                 ;
  }                                                                  ;
  ////////////////////////////////////////////////////////////////////
  return ph -> enabler -> PrivateEnablings [ Id ]                    ;
}

bool Enabler::setEnabled(SUID Id,bool enable)
{
  if ( nullptr == this -> PrivatePacket ) return enable              ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> lock   ( )                                        ;
  ph -> enabler -> UuidEnablings [ Id ] = enable                     ;
  ph -> enabler -> unlock ( )                                        ;
  return enable                                                      ;
}

bool Enabler::hasEnabled(SUID Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> hasEnabled ( Id )                          ;
}

bool Enabler::isEnabled(SUID Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) ) return false           ;
  bool enabled                                                       ;
  ph     -> enabler -> lock   ( )                                    ;
  enabled = ph -> enabler -> UuidEnablings [ Id ]                    ;
  ph     -> enabler -> unlock ( )                                    ;
  return enabled                                                     ;
}

bool & Enabler::operator [ ] (SUID Id)
{
  if ( nullptr == this -> PrivatePacket ) return alwaysFalse         ;
  ////////////////////////////////////////////////////////////////////
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) )                        {
    ph -> enabler -> UuidEnablings [ Id ] = false                    ;
  }                                                                  ;
  ////////////////////////////////////////////////////////////////////
  return ph -> enabler -> UuidEnablings [ Id ]                       ;
}

bool Enabler::setEnabled(std::string Id,bool enable)
{
  if ( nullptr == this -> PrivatePacket ) return enable              ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> lock   ( )                                        ;
  ph -> enabler -> StringEnablings [ Id ] = enable                   ;
  ph -> enabler -> unlock ( )                                        ;
  return enable                                                      ;
}

bool Enabler::hasEnabled(std::string Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> hasEnabled ( Id )                          ;
}

bool Enabler::isEnabled(std::string Id)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) ) return false           ;
  bool enabled                                                       ;
  ph     -> enabler -> lock   ( )                                    ;
  enabled = ph -> enabler -> StringEnablings [ Id ]                  ;
  ph     -> enabler -> unlock ( )                                    ;
  return enabled                                                     ;
}

bool & Enabler::operator [ ] (std::string Id)
{
  if ( nullptr == this -> PrivatePacket ) return alwaysFalse         ;
  ////////////////////////////////////////////////////////////////////
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  if ( ! ph -> enabler -> hasEnabled ( Id ) )                        {
    ph -> enabler -> StringEnablings [ Id ] = false                  ;
  }                                                                  ;
  ////////////////////////////////////////////////////////////////////
  return ph -> enabler -> StringEnablings [ Id ]                     ;
}

bool Enabler::isAllTrue(void)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> isAllTrue ( )                              ;
}

bool Enabler::isAllFalse(void)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> isAllFalse ( )                             ;
}

bool Enabler::canLock(void)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  return ph -> enabler -> shouldLock                                 ;
}

bool Enabler::setLock(bool lock)
{
  if ( nullptr == this -> PrivatePacket ) return false               ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> shouldLock = lock                                 ;
  return lock                                                        ;
}

void Enabler::lock(void)
{
  if ( nullptr == this -> PrivatePacket ) return                     ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> lock ( )                                          ;
}

void Enabler::unlock(void)
{
  if ( nullptr == this -> PrivatePacket ) return                     ;
  PrivateHandler * ph                                                ;
  ph  = reinterpret_cast<PrivateHandler *> ( this -> PrivatePacket ) ;
  ph -> enabler -> unlock ( )                                        ;
}
