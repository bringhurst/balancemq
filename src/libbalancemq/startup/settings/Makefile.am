include $(top_srcdir)/common.mk

BUILT_SOURCES = balancemq_settings.h
PARSER = balancemq_settings.y balancemq_settings.l
AM_YFLAGS = -d

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/settings

noinst_LTLIBRARIES = libbalancemq_startup_settings.la

libbalancemq_startup_settings_la_SOURCES = settings.c balancemq_settings.y
libbalancemq_startup_settings_la_LIBADD = $(LEXLIB)
libbalancemq_startup_settings_la_LDFLAGS = $(LIB_LDFLAGS)
