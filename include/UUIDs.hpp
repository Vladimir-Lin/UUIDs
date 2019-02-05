/****************************************************************************\
 *
 *                         SUID and TUID basic functions
 *
\****************************************************************************/

#ifndef UUIDS_HPP
#define UUIDS_HPP

#if defined (WIN32) && defined(BUILD_SHARED_LIBS)
  #if defined (_MSC_VER)
    #pragma warning(disable: 4251)
  #endif
  #if defined(EXPORT_UUIDS)
    #define UUIDs_EXPORT __declspec(dllexport)
  #else
    #define UUIDs_EXPORT __declspec(dllimport)
  #endif
#else
    #define UUIDs_EXPORT
#endif

#include <stdint.h>
#include <stdio.h>

typedef int64_t  TUID ;
typedef uint64_t SUID ;
typedef int32_t  CUID ;
typedef uint64_t FUID ;

// Create SUID number
UUIDs_EXPORT SUID   randomUpperSuid (void) ;
UUIDs_EXPORT SUID   randomUpperSuid (SUID header) ;
UUIDs_EXPORT SUID   randomLongSuid  (void) ;
UUIDs_EXPORT SUID   randomLongSuid  (SUID tailer) ;
UUIDs_EXPORT SUID   randomSuid      (SUID extension=0,bool upper=true) ;
UUIDs_EXPORT TUID   randomTuid      (void) ;
UUIDs_EXPORT TUID   randomTuid      (SUID header) ;

// String operation
UUIDs_EXPORT SUID   suidFromHex     (const char * string,size_t len=0) ;
UUIDs_EXPORT TUID   tuidFromHex     (const char * string,size_t len=0) ;

// Create SUID Memory
UUIDs_EXPORT void * suidArray       (size_t size) ;
UUIDs_EXPORT void * suidResize      (void * block,size_t size) ;
UUIDs_EXPORT void   suidFree        (void * block) ;

// Sorting
UUIDs_EXPORT void   suidSort        (void * block,size_t size) ;
UUIDs_EXPORT void   tuidSort        (void * block,size_t size) ;

// Uniqueness
UUIDs_EXPORT size_t suidUnique      (void * unique,const void * block,size_t size) ;
UUIDs_EXPORT size_t tuidUnique      (void * unique,const void * block,size_t size) ;

// Reversal
UUIDs_EXPORT void   suidReverse     (void * reverse,const void * block,size_t size) ;
UUIDs_EXPORT void   tuidReverse     (void * reverse,const void * block,size_t size) ;

/****************************************************************************\
 *                                                                          *
 *  Destroyer is a class that helps to destroy any classes which does not   *
 *  know when will it is about to be destroyed.                             *
 *                                                                          *
\****************************************************************************/

class UUIDs_EXPORT Destroyer
{
  public:

    explicit     Destroyer  (void) ;
    virtual     ~Destroyer  (void) ;

    virtual bool Recycling  (void) ;
    virtual bool Destructor (void) ;

  protected:

  private:

} ;

#endif
