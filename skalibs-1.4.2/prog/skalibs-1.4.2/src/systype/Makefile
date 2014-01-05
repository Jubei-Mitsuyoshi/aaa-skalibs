it: systype


bootcompile: conf-cc make-compile path-include warn-auto.sh
	./make-compile > bootcompile && chmod 755 bootcompile

bootload: conf-ld make-load path-library path-library.so conf-stripbins warn-auto.sh
	./make-load > bootload && chmod 755 bootload

systype: find-systype bootcompile bootload trycpp.c x86cpuid.c
	./find-systype > systype
