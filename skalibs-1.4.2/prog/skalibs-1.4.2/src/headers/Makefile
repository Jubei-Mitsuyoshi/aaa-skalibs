it: command include library library.so


skalibs-config.h: stupid skalibs-version.stupid skalibs-nosp skalibs-sp.stupid skalibs-config-header skalibs-config-footer conf-defaultpath conf-etc
	{ \
	  cat skalibs-config-header ; \
	  ./stupid < skalibs-version.stupid ; \
	  if test -f flag-slashpackage ; then ./stupid < skalibs-sp.stupid ; else cat skalibs-nosp ; fi ; \
	  echo -n '#define SKALIBS_DEFAULTPATH "' ; echo -n `head -n 1 conf-defaultpath | ./stupid` ; echo '"' ; echo ; \
	  echo -n '#define SKALIBS_ETC "' ; echo -n `head -n 1 conf-etc | ./stupid` ; echo '"' ; echo ; \
	  if test -f flag-allstatic ; then echo '#define SKALIBS_FLAG_ALLSTATIC' ; else echo '#undef SKALIBS_FLAG_ALLSTATIC' ; fi ; \
	  if test -f flag-replace-libc ; then echo '#define SKALIBS_FLAG_REPLACE_LIBC' ; else echo '#undef SKALIBS_FLAG_REPLACE_LIBC' ; fi ; \
	  if test -f flag-clockistai ; then echo '#define SKALIBS_FLAG_CLOCKISTAI' ; else echo '#undef SKALIBS_FLAG_CLOCKISTAI' ; fi ; \
	  if test -f flag-tzisright ; then echo '#define SKALIBS_FLAG_TZISRIGHT' ; else echo '#undef SKALIBS_FLAG_TZISRIGHT' ; fi ; \
	  if test -f flag-usert ; then echo '#define SKALIBS_FLAG_USERT' ; else echo '#undef SKALIBS_FLAG_USERT' ; fi ; \
	  if test -f flag-usemon ; then echo '#define SKALIBS_FLAG_USEMON' ; else echo '#undef SKALIBS_FLAG_USEMON' ; fi ; \
	  if test -f flag-noipv6 ; then echo '#undef SKALIBS_FLAG_WANTIPV6' ; else echo '#define SKALIBS_FLAG_WANTIPV6' ; fi ; \
	  cat skalibs-config-footer ; \
	} > skalibs-config.h

uint16.h: sysdeps uint64.h uint16-header uint16-footer uint16-stdinth uint16-inttypesh uint16-default uint16-lendian uint16-bendian
	{ \
	  cat uint16-header ; \
	  if grep -F +stdinth sysdeps >/dev/null ; then cat uint16-stdinth ; \
	  elif grep -F +inttypesh sysdeps >/dev/null ; then cat uint16-inttypesh ; \
	  else cat uint16-default ; \
	  fi ; \
	  if grep -F +little_endian sysdeps >/dev/null ; then cat uint16-lendian ; \
	  elif grep -F +big_endian sysdeps >/dev/null ; then cat uint16-bendian ; \
	  else echo "Error ! Unsupported endianness" 1>&2 ; ./crash ; \
	  fi ; \
	  cat uint16-footer ; \
	} > uint16.h

uint32.h: sysdeps uint64.h uint32-header uint32-footer uint32-stdinth uint32-inttypesh uint32-ulong32 uint32-noulong32 uint32-lendian uint32-bendian
	{ \
	  cat uint32-header ; \
	  if grep -F +stdinth sysdeps >/dev/null ; then cat uint32-stdinth ; \
	  elif grep -F +inttypesh sysdeps >/dev/null ; then cat uint32-inttypesh ; \
	  elif grep -F +ulong32 sysdeps >/dev/null ; then cat uint32-ulong32 ; \
	  else cat uint32-noulong32 ; \
	  fi ; \
	  if grep -F +little_endian sysdeps >/dev/null ; then cat uint32-lendian ; \
	  elif grep -F +big_endian sysdeps >/dev/null ; then cat uint32-bendian ; \
	  else echo "Error ! Unsupported endianness" 1>&2 ; ./crash ; \
	  fi ; \
	  cat uint32-footer ; \
	} > uint32.h

uint64.h: sysdeps uint64-header uint64-footer uint64-ulong64 uint64-noulong64 uint64-lendian uint64-bendian
	{ \
	  cat uint64-header ; \
	  if grep -F +uint64t sysdeps >/dev/null ; then cat uint64-stdinth ; \
	  elif grep -F +ulong64 sysdeps >/dev/null ; then cat uint64-ulong64 ; \
	  else cat uint64-noulong64 ; \
          fi ; \
	  if grep -F +little_endian sysdeps >/dev/null ; then cat uint64-lendian ; \
	  elif grep -F +big_endian sysdeps >/dev/null ; then cat uint64-bendian ; \
	  else echo "Error ! Unsupported endianness" 1>&2 ; ./crash ; \
	  fi ; \
	  cat uint64-footer ; \
	} > uint64.h

direntry.h: sysdeps direntry.h1 direntry.h2 direntry-header direntry-footer
	{ \
	  cat direntry-header ; \
	  if grep -F +dirent sysdeps >/dev/null ; then cat direntry.h2 ; \
	  else cat direntry.h1 ; \
	  fi ; \
	  cat direntry-footer ; \
	} > direntry.h

error.h: systype sysdeps error-addrinuse error-already error-proto error-header error-footer
	{ \
	  cat error-header ; \
	  if cut -d- -f1 systype | grep -i -F bsd >/dev/null ; then cat error-addrinuse ; \
	  else cat error-already ; \
	  fi ; \
	  if grep -F +eproto sysdeps >/dev/null ; then true ; \
	  else cat error-proto ; \
	  fi ; \
	  cat error-footer ; \
	} > error.h

select.h: sysdeps select.h1 select.h2
	{ \
	  if grep -F +sysselect sysdeps >/dev/null ; then cat select.h2 ; \
	  else cat select.h1 ; \
	  fi ; \
	} > select.h

iopause.h: sysdeps iopause.h1 iopause.h2 iopause.h3 iopause.h4
	{ \
	  cat iopause-header ; \
	  if grep -F +poll sysdeps >/dev/null ; then \
	    if grep -F +pollh sysdeps >/dev/null ; then cat iopause.h2 ; \
	    elif grep -F +syspollh sysdeps >/dev/null ; then cat iopause.h3 ; \
	    else cat iopause.h4 ; \
	    fi \
	  else cat iopause.h1 ; \
	  fi ; \
	  cat iopause-footer ; \
	} > iopause.h

shglob.h: sysdeps shglob.h1 shglob.h2
	{ \
	  if grep -F +posixglob sysdeps >/dev/null ; then cat shglob.h2 ; \
	  else cat shglob.h1 ; \
	  fi ; \
	} > shglob.h

ushort.h: sysdeps ushort-header ushort-footer ushort-16 ushort-32
	{ \
	  cat ushort-header ; \
	  if grep -F 'sizeofushort: 2' sysdeps >/dev/null ; then cat ushort-16 ; \
	  elif grep -F 'sizeofushort: 4' sysdeps >/dev/null ; then cat ushort-32 ; \
	  else echo "Error ! Unsupported unsigned short size" 1>&2 ; ./crash ; \
	  fi ; \
	  cat ushort-footer ; \
	} > ushort.h

uint.h: sysdeps uint-header uint-footer uint-16 uint-32 uint-64
	{ \
	  cat uint-header ; \
	  if grep -F 'sizeofuint: 2' sysdeps >/dev/null ; then cat uint-16 ; \
	  elif grep -F 'sizeofuint: 4' sysdeps >/dev/null ; then cat uint-32 ; \
	  elif grep -F 'sizeofuint: 8' sysdeps >/dev/null ; then cat uint-64 ; \
	  else echo "Error ! Unsupported unsigned int size" 1>&2 ; ./crash ; \
	  fi ; \
	  cat uint-footer ; \
        } > uint.h

ulong.h: sysdeps ulong-header ulong-footer ulong-32 ulong-64
	{ \
	  cat ulong-header ; \
	  if grep -F +ulong32 sysdeps >/dev/null ; then cat ulong-32 ; \
	  elif grep -F +ulong64 sysdeps >/dev/null ; then cat ulong-64 ; \
	  else echo "Error ! Unsupported unsigned long size" 1>&2 ; ./crash ; \
	  fi ; \
	  cat ulong-footer ; \
	} > ulong.h

command:

include: gccattributes.h skalibs-config.h uint16.h uint32.h uint64.h direntry.h \
error.h select.h iopause.h shglob.h ushort.h uint.h ulong.h

library:

library.so:
