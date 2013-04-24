include $(top_srcdir)/common.mk

AM_YFLAGS = --defines
AM_LFLAGS = -CFa --header-file=balance_settings.scanner.h

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/include/ \
           -I$(top_srcdir)/src/common/

balance_settings.parser.c : balance_settings.y
	$(YACC) $(YFLAGS) $(AM_YFLAGS) $< -o $@

balance_settings.scanner.c : balance_settings.l #balance_settings.parser.h
	$(LEX) $(LFLAGS) $(AM_LFLAGS) -o$@ $<

noinst_LTLIBRARIES = libbalancemq_startup_settings.la

libbalancemq_startup_settings_la_SOURCES = \
                                           balance_settings.parser.c \
										   balance_settings.scanner.c \
										   settings.c

libbalancemq_startup_settings_la_LIBADD = $(LEXLIB) -lfl
libbalancemq_startup_settings_la_LDFLAGS = $(LIB_LDFLAGS)
