it: sysdeps.h sysdeps socket.lib util.lib rt.lib sysclock.lib taianow.lib

sysdeps: compile load systype sysdeps.h socket.lib util.lib rt.lib sysclock.lib taianow.lib
	: > sysdeps && cat systype compile load socket.lib util.lib rt.lib sysclock.lib taianow.lib >> sysdeps && grep -F sysdep: sysdeps.h >> sysdeps

sysdeps.h: hasdevtcp.h hasdevptc.h hasdevptmx.h hasdevr.h hasdevur.h \
hasdirent.h haseproto.h hasflock.h hasgetpt.h \
hasgpeid.h hassopc.h hasmalloc0.h hasmkffo.h hasnpbg1.h \
haspollh.h hassyspollh.h haspoll.h hassgact.h hassgprm.h \
hassetgroups.h hassysel.h hasrevoke.h haswaitp.h hasulong32.h hasulong64.h \
hasutilh.h haslibutilh.h hasptyh.h hasunixh.h has_getpty.h hasopenpty.h \
hasstreams.h haslendian.h hasbendian.h hasegd.h hastiocr.h hasposixglob.h \
hasstdinth.h hasinttypesh.h hasuint64t.h hasopenat.h \
hasrdtsc.h hasgethrtime.h hassendfile.h hassplice.h haspipe2.h hasaccept4.h \
hasgettimeofday.h hassettimeofday.h haseventfd.h hassignalfd.h hasregex.h \
hasclockrt.h hasclockmon.h hasipv6.h hasancilautoclose.h \
sizeofushort.h sizeofuint.h
	echo '/* ISC license. */' > sysdeps.h
	echo >> sysdeps.h
	echo '#ifndef SYSDEPS_H' >> sysdeps.h
	echo '#define SYSDEPS_H' >> sysdeps.h
	echo >> sysdeps.h
	exec cat hasdevtcp.h hasdevptc.h hasdevptmx.h hasdevr.h hasdevur.h \
	hasdirent.h haseproto.h hasflock.h hasgetpt.h \
	hasgpeid.h hassopc.h hasmalloc0.h hasmkffo.h hasnpbg1.h \
	haspollh.h hassyspollh.h haspoll.h hassgact.h hassgprm.h \
	hassetgroups.h hassysel.h hasrevoke.h haswaitp.h hasulong32.h hasulong64.h \
	hasutilh.h haslibutilh.h hasptyh.h has_getpty.h hasopenpty.h hasunixh.h \
	hasstreams.h haslendian.h hasbendian.h hasegd.h hastiocr.h hasposixglob.h \
	hasstdinth.h hasinttypesh.h hasuint64t.h hasopenat.h \
	hasrdtsc.h hasgethrtime.h hassendfile.h hassplice.h haspipe2.h hasaccept4.h \
	hasgettimeofday.h hassettimeofday.h haseventfd.h hassignalfd.h hasregex.h \
	hasclockrt.h hasclockmon.h hasipv6.h hasancilautoclose.h \
	sizeofushort.h sizeofuint.h >> sysdeps.h
	echo >> sysdeps.h
	echo '#endif' >> sysdeps.h

socket.lib: compile load trylsock.c
	: > socket.lib
	exec ./compile trylsock.c
	./load trylsock 2>/dev/null || { ./load trylsock -lsocket -lnsl 2>/dev/null && echo -lsocket -lnsl > socket.lib ; }
	exec rm -f trylsock.o trylsock

util.lib: compile load trylutil.c
	: > util.lib
	exec ./compile trylutil.c
	./load trylutil 2>/dev/null || { ./load trylutil -lutil 2>/dev/null && echo -lutil > util.lib ; }
	exec rm -f trylutil.o trylutil

rt.lib: hasclockrt.h

sysclock.lib: rt.lib
	if test -f flag-usert ; then cat < rt.lib > sysclock.lib ; else : > sysclock.lib ; fi

taianow.lib: rt.lib
	if test -f flag-usert || test -f flag-usemon ; then cat < rt.lib > taianow.lib ; else : > taianow.lib ; fi

hasdevtcp.h: systype hasdevtcp.h1 hasdevtcp.h2
	case "`cat systype`" in \
	  sunos-5.*) cat hasdevtcp.h2 ;; \
	  *) cat hasdevtcp.h1 ;; \
	esac > hasdevtcp.h

hasdevptc.h: choose compile load trydevptc.c hasdevptc.h1 hasdevptc.h2
	exec ./choose clr trydevptc hasdevptc.h1 hasdevptc.h2 > hasdevptc.h

hasdevptmx.h: choose compile load trydevptmx.c hasdevptmx.h1 hasdevptmx.h2
	exec ./choose clr trydevptmx hasdevptmx.h1 hasdevptmx.h2 > hasdevptmx.h

hasdevr.h: choose compile load trydevr.c hasdevr.h1 hasdevr.h2 warn-trydevr
	if test -f flag-forcedevr ; then cat hasdevr.h2 > hasdevr.h ; else cat < warn-trydevr 1>&2 ; exec ./choose clr trydevr hasdevr.h1 hasdevr.h2 > hasdevr.h ; fi

hasdevur.h: choose compile load trydevur.c hasdevur.h1 hasdevur.h2
	exec ./choose clr trydevur hasdevur.h1 hasdevur.h2 > hasdevur.h

hasdirent.h: choose compile hasdirent.h1 hasdirent.h2 trydrent.c
	exec ./choose c trydrent hasdirent.h1 hasdirent.h2 > hasdirent.h

haseproto.h: choose compile haseproto.h1 haseproto.h2 tryeproto.c
	exec ./choose c tryeproto haseproto.h1 haseproto.h2 > haseproto.h

hasflock.h: choose compile hasflock.h1 hasflock.h2 load tryflock.c
	exec ./choose cl tryflock hasflock.h1 hasflock.h2 > hasflock.h

hasgetpt.h: choose compile hasgetpt.h1 hasgetpt.h2 load trygetpt.c
	exec ./choose cl trygetpt hasgetpt.h1 hasgetpt.h2 > hasgetpt.h

hasgpeid.h: choose compile load hasgpeid.h1 hasgpeid.h2 trygpeid.c
	exec ./choose cl trygpeid hasgpeid.h1 hasgpeid.h2 > hasgpeid.h

hassopc.h: choose compile load hassopc.h1 hassopc.h2 trysopc.c
	exec ./choose cl trysopc hassopc.h1 hassopc.h2 > hassopc.h

hasmalloc0.h: choose compile load hasmalloc0.h1 hasmalloc0.h2 trymalloc0.c
	exec ./choose clr trymalloc0 hasmalloc0.h1 hasmalloc0.h2 > hasmalloc0.h

hasmkffo.h: choose compile hasmkffo.h1 hasmkffo.h2 load trymkffo.c
	exec ./choose cl trymkffo hasmkffo.h1 hasmkffo.h2 > hasmkffo.h

hasnpbg1.h: choose compile hasnpbg1.h1 hasnpbg1.h2 load trynpbg1.c hasmkffo.h hassysel.h
	exec ./choose clr trynpbg1 hasnpbg1.h1 hasnpbg1.h2 > hasnpbg1.h

haspollh.h: choose compile haspollh.h1 haspollh.h2 trypollh.c
	exec ./choose c trypollh haspollh.h1 haspollh.h2 > haspollh.h

hassyspollh.h: choose compile hassyspollh.h1 hassyspollh.h2 trysyspollh.c
	exec ./choose c trysyspollh hassyspollh.h1 hassyspollh.h2 > hassyspollh.h

haspoll.h: choose compile haspoll.h1 haspoll.h2 load trypoll.c haspollh.h hassyspollh.h
	exec ./choose clr trypoll haspoll.h1 haspoll.h2 > haspoll.h

hassgact.h: choose compile hassgact.h1 hassgact.h2 load trysgact.c
	exec ./choose cl trysgact hassgact.h1 hassgact.h2 > hassgact.h

hassgprm.h: choose compile hassgprm.h1 hassgprm.h2 load trysgprm.c
	exec ./choose cl trysgprm hassgprm.h1 hassgprm.h2 > hassgprm.h

hassetgroups.h: choose compile hassetgroups.h1 hassetgroups.h2 load trysetgroups.c
	exec ./choose cl trysetgroups hassetgroups.h1 hassetgroups.h2 > hassetgroups.h

hassysel.h: choose compile hassysel.h1 hassysel.h2 trysysel.c
	exec ./choose c trysysel hassysel.h1 hassysel.h2 > hassysel.h

hasrevoke.h: choose compile hasrevoke.h1 hasrevoke.h2 load tryrevoke.c
	exec ./choose cl tryrevoke hasrevoke.h1 hasrevoke.h2 > hasrevoke.h

haswaitp.h: choose compile haswaitp.h1 haswaitp.h2 load trywaitp.c
	exec ./choose cl trywaitp haswaitp.h1 haswaitp.h2 > haswaitp.h

hasulong32.h: choose compile load tryulong32.c hasulong32.h1 hasulong32.h2
	exec ./choose clr tryulong32 hasulong32.h1 hasulong32.h2 > hasulong32.h

hasulong64.h: choose compile load tryulong64.c hasulong64.h1 hasulong64.h2
	exec ./choose clr tryulong64 hasulong64.h1 hasulong64.h2 > hasulong64.h

hasutilh.h: choose compile tryutilh.c hasutilh.h1 hasutilh.h2
	exec ./choose c tryutilh hasutilh.h1 hasutilh.h2 > hasutilh.h

haslibutilh.h: choose compile trylibutilh.c haslibutilh.h1 haslibutilh.h2
	exec ./choose c trylibutilh haslibutilh.h1 haslibutilh.h2 > haslibutilh.h

hasptyh.h: choose compile tryptyh.c hasptyh.h1 hasptyh.h2
	exec ./choose c tryptyh hasptyh.h1 hasptyh.h2 > hasptyh.h

hasunixh.h: choose compile tryunixh.c hasunixh.h1 hasunixh.h2
	exec ./choose c tryunixh hasunixh.h1 hasunixh.h2 > hasunixh.h

has_getpty.h: choose compile load try_getpty.c has_getpty.h1 has_getpty.h2
	exec ./choose cl try_getpty has_getpty.h1 has_getpty.h2 > has_getpty.h

hasopenpty.h: choose compile load tryopenpty.c hasopenpty.h1 hasopenpty.h2 hasutilh.h haslibutilh.h hasptyh.h util.lib
	exec ./choose cl tryopenpty hasopenpty.h1 hasopenpty.h2 `cat util.lib` > hasopenpty.h

hasstreams.h: choose compile trystreams.c hasstreams.h1 hasstreams.h2
	exec ./choose c trystreams hasstreams.h1 hasstreams.h2 > hasstreams.h

haslendian.h: choose compile load trylendian.c haslendian.h1 haslendian.h2 hasulong32.h hasulong64.h
	exec ./choose clr trylendian haslendian.h1 haslendian.h2 > haslendian.h

hasbendian.h: choose compile load trybendian.c hasbendian.h1 hasbendian.h2 hasulong32.h hasulong64.h
	exec ./choose clr trybendian hasbendian.h1 hasbendian.h2 > hasbendian.h

hasegd.h: conf-egd hasegd.h1 hasegd.h2
	: > egd.h && if test "x`head -n 1 conf-egd`" = "x" ; then cat hasegd.h1 ; else sed "s|EGD_IPCPATH|`head -1 conf-egd`|" < hasegd.h2 ; fi > hasegd.h

hastiocr.h: choose compile trytiocr.c hastiocr.h1 hastiocr.h2
	exec ./choose c trytiocr hastiocr.h1 hastiocr.h2 > hastiocr.h

hasposixglob.h: choose compile tryposixglob.c hasposixglob.h1 hasposixglob.h2
	exec ./choose c tryposixglob hasposixglob.h1 hasposixglob.h2 > hasposixglob.h

hasstdinth.h: choose compile hasstdinth.h1 hasstdinth.h2 trystdinth.c
	exec ./choose c trystdinth hasstdinth.h1 hasstdinth.h2 > hasstdinth.h

hasinttypesh.h: choose compile hasinttypesh.h1 hasinttypesh.h2 tryinttypesh.c
	exec ./choose c tryinttypesh hasinttypesh.h1 hasinttypesh.h2 > hasinttypesh.h

hasuint64t.h: choose compile hasuint64t.h1 hasuint64t.h2 tryuint64t.c
	exec ./choose c tryuint64t hasuint64t.h1 hasuint64t.h2 > hasuint64t.h

hasopenat.h: choose compile load hasopenat.h1 hasopenat.h2 tryopenat.c
	exec ./choose clr tryopenat hasopenat.h1 hasopenat.h2 > hasopenat.h

hasrdtsc.h: choose compile load hasrdtsc.h1 hasrdtsc.h2 tryrdtsc.c
	exec ./choose clr tryrdtsc hasrdtsc.h1 hasrdtsc.h2 > hasrdtsc.h

hasgethrtime.h: choose compile load hasgethrtime.h1 hasgethrtime.h2 trygethrtime.c
	exec ./choose cl trygethrtime hasgethrtime.h1 hasgethrtime.h2 > hasgethrtime.h

hassendfile.h: choose compile load hassendfile.h1 hassendfile.h2 trysendfile.c
	exec ./choose cl trysendfile hassendfile.h1 hassendfile.h2 > hassendfile.h

hassplice.h: choose compile load hassplice.h1 hassplice.h2 trysplice.c
	exec ./choose clr trysplice hassplice.h1 hassplice.h2 > hassplice.h

haspipe2.h: choose compile load haspipe2.h1 haspipe2.h2 trypipe2.c
	exec ./choose clr trypipe2 haspipe2.h1 haspipe2.h2 > haspipe2.h

hasaccept4.h: choose compile load hasaccept4.h1 hasaccept4.h2 tryaccept4.c
	exec ./choose clr tryaccept4 hasaccept4.h1 hasaccept4.h2 > hasaccept4.h

hasgettimeofday.h: choose compile load hasgettimeofday.h1 hasgettimeofday.h2 trygettimeofday.c
	exec ./choose cl trygettimeofday hasgettimeofday.h1 hasgettimeofday.h2 > hasgettimeofday.h

hassettimeofday.h: choose compile load hassettimeofday.h1 hassettimeofday.h2 trysettimeofday.c
	exec ./choose cl trysettimeofday hassettimeofday.h1 hassettimeofday.h2 > hassettimeofday.h

haseventfd.h: choose compile load haseventfd.h1 haseventfd.h2 tryeventfd.c
	exec ./choose clr tryeventfd haseventfd.h1 haseventfd.h2 > haseventfd.h

hassignalfd.h: choose compile load hassignalfd.h1 hassignalfd.h2 trysignalfd.c
	exec ./choose clr trysignalfd hassignalfd.h1 hassignalfd.h2 > hassignalfd.h

hasregex.h: choose compile load hasregex.h1 hasregex.h2 tryregex.c
	exec ./choose cl tryregex hasregex.h1 hasregex.h2 > hasregex.h

hasclockmon.h: choose compile load hasclockmon.h1 hasclockmon.h2 rt.lib
	exec ./choose cl tryclockmon hasclockmon.h1 hasclockmon.h2 `cat rt.lib` > hasclockmon.h

hasclockrt.h: compile load tryclockrt.c hasclockrt.h1 hasclockrt.h2
	exec ./compile tryclockrt.c
	if ./load tryclockrt 2>/dev/null ; then cat hasclockrt.h2 > hasclockrt.h ; : > rt.lib ; \
	elif ./load tryclockrt -lrt 2>/dev/null ; then cat hasclockrt.h2 > hasclockrt.h ; echo -lrt > rt.lib ; \
	else cat hasclockrt.h1 > hasclockrt.h ; : > rt.lib ; \
	fi
	exec rm -f tryclockrt.o tryclockrt

hasipv6.h: choose compile load hasipv6.h1 hasipv6.h2 socket.lib
	exec ./choose cl tryipv6 hasipv6.h1 hasipv6.h2 `cat socket.lib` > hasipv6.h

hasancilautoclose.h: choose compile load hasancilautoclose.h1 hasancilautoclose.h2 socket.lib
	exec ./choose clr tryancilautoclose hasancilautoclose.h1 hasancilautoclose.h2 `cat socket.lib` > hasancilautoclose.h

sizeofushort.h: compile load trysizeofushort.c
	./compile trysizeofushort.c && ./load trysizeofushort
	echo '#define SKALIBS_SIZEOFUSHORT' `./trysizeofushort` > sizeofushort.h
	echo '#define SKALIBS_USHORT_BITS' `expr 8 \* \`./trysizeofushort\`` >> sizeofushort.h
	echo '/* sysdep: sizeofushort:' `./trysizeofushort` '*/' >> sizeofushort.h

sizeofuint.h: compile load trysizeofuint.c
	./compile trysizeofuint.c && ./load trysizeofuint
	echo '#define SKALIBS_SIZEOFUINT' `./trysizeofuint` > sizeofuint.h
	echo '#define SKALIBS_UINT_BITS' `expr 8 \* \`./trysizeofuint\`` >> sizeofuint.h
	echo '/* sysdep: sizeofuint:' `./trysizeofuint` '*/' >> sizeofuint.h
