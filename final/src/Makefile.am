## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = final

final_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctions.c fonction.h \
	reservation.c reservation.h \
	reserverVOL.c reserverVOL.h \
	client.c client.h \
	voiture.c voiture.h \
	voitureclient.c voitureclient.h \
	reclamation.c reclamation.h \
	vol.c vol.h \
	fonction.c fonction.h

final_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

