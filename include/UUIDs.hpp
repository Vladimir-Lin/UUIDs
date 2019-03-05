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

#include <string>

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

    explicit       Destroyer  (void) ;
    virtual       ~Destroyer  (void) ;

    virtual bool   Interrupt  (void) ;
    virtual bool   Recycling  (void) ;
    virtual bool   Destructor (void) ;

    virtual void * Register   (void * package) ;

  protected:

  private:

} ;

class Convoy : public Destroyer
{
  public:

    explicit            Convoy      (void) ;
                        Convoy      (std::string key) ;
    virtual            ~Convoy      (void) ;

    virtual bool        Interrupt   (void) ;
    virtual bool        Recycling   (void) ;
    virtual bool        Destructor  (void) ;

    virtual void      * Register    (void * package) ;

    virtual int         Join        (Destroyer * destroyer) ;
    virtual int         Remove      (Destroyer * destroyer) ;
    virtual Destroyer * Visit       (int index) ;

    virtual void      * Guard       (void) ;
    virtual bool        Prepare     (void) ;
    virtual bool        Discontinue (void) ; // Stop All
    virtual bool        Eliminate   (void) ; // Clean All
    virtual int         Survived    (void) const ;

    virtual void        setKey      (std::string key) ;
    virtual std::string Key         (void) const ;

    static  bool        add         (std::string key,Convoy * convoy) ; // add Convoy By Key
    static  bool        remove      (std::string key) ; // Remove Convoy By Key

    static  Convoy    * find        (std::string key) ; // find Convoy

    static  int         join        (std::string key,Destroyer * destroyer) ;
    static  int         remove      (std::string key,Destroyer * destroyer) ;

  protected:

    void      * PrivatePacket ;
    void      * PrivateGuard  ;
    std::string ConvoyKey     ;

  private:

} ;

#endif
