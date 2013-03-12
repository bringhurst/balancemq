include $(top_srcdir)/common.mk

BUILT_SOURCES = balancemq_settings.h
PARSER = balancemq_settings.y balancemq_settings.l
AM_YFLAGS = -d

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/settings

noinst_LTLIBRARIES = lib_settings_compiler.la

lib_settings_compiler_la_SOURCES = balancemq_settings.y
lib_settings_compiler_la_LIBADD = $(LEXLIB)
lib_settings_compiler_la_LDFLAGS = $(LIB_LDFLAGS)
