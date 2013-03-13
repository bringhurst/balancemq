include $(top_srcdir)/common.mk

AM_YFLAGS = --defines
AM_LFLAGS = -CFa --header-file=balancemq_settings.scanner.h

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/common \
           -I$(top_srcdir)/src/libbalancemq/settings


balancemq_settings.parser.c : balancemq_settings.y
	$(YACC) $(YFLAGS) $(AM_YFLAGS) $< -o $@

balancemq_settings.scanner.c : balancemq_settings.l balancemq_settings.parser.h
	$(LEX) $(LFLAGS) $(AM_LFLAGS) -o$@ $<

noinst_LTLIBRARIES = libbalancemq_startup_settings.la

libbalancemq_startup_settings_la_SOURCES = \
                                           balancemq_settings.parser.c \
										   balancemq_settings.scanner.c \
										   settings.c

libbalancemq_startup_settings_la_LIBADD = $(LEXLIB)
libbalancemq_startup_settings_la_LDFLAGS = $(LIB_LDFLAGS)
