include $(top_srcdir)/common.mk

BUILT_SOURCES = balancemq_settings.h

AM_YFLAGS = -d
AM_LFLAGS = -CFa

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/common \
           -I$(top_srcdir)/src/libbalancemq/settings

noinst_LTLIBRARIES = libbalancemq_startup_settings.la

libbalancemq_startup_settings_la_SOURCES = \
                                           balancemq_settings.y \
										   settings.c

libbalancemq_startup_settings_la_LIBADD = $(LEXLIB)
libbalancemq_startup_settings_la_LDFLAGS = $(LIB_LDFLAGS)
