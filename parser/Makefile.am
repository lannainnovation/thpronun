SUBDIRS = tests

AM_CPPFLAGS = -I. -I$(top_srcdir) $(LIBTHAI_CFLAGS)

noinst_LTLIBRARIES = libparser.la

libparser_la_SOURCES = \
	parser.h	\
	parser.cxx	\
	$(NULL)

libparser_la_LIBADD = \
	$(top_builddir)/sylstring/libsylstring.la	\
	$(top_builddir)/dict/libdict.la			\
	$(LIBTHAI_LIBS)	\
	$(NULL)

