
#ifndef TITANIUMKIT_EXPORT_H
#define TITANIUMKIT_EXPORT_H

#ifdef TITANIUMKIT_STATIC_DEFINE
#  define TITANIUMKIT_EXPORT
#  define TITANIUMKIT_NO_EXPORT
#else
#  ifndef TITANIUMKIT_EXPORT
#    ifdef TitaniumKit_EXPORTS
        /* We are building this library */
#      define TITANIUMKIT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define TITANIUMKIT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef TITANIUMKIT_NO_EXPORT
#    define TITANIUMKIT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef TITANIUMKIT_DEPRECATED
#  define TITANIUMKIT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef TITANIUMKIT_DEPRECATED_EXPORT
#  define TITANIUMKIT_DEPRECATED_EXPORT TITANIUMKIT_EXPORT TITANIUMKIT_DEPRECATED
#endif

#ifndef TITANIUMKIT_DEPRECATED_NO_EXPORT
#  define TITANIUMKIT_DEPRECATED_NO_EXPORT TITANIUMKIT_NO_EXPORT TITANIUMKIT_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define TITANIUMKIT_NO_DEPRECATED
#endif

#endif
