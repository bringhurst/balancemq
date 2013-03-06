include $(top_srcdir)/common.mk

BUILT_SOURCES = balancemqd_conf.h
PARSER = balancemqd_conf.y balancemqd_conf.l
AM_YFLAGS = -d

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/common/config/

noinst_LTLIBRARIES = libcommon_config_compiler.la

libcommon_config_compiler_la_SOURCES = balancemqd_conf.y
libcommon_config_compiler_la_LIBADD = $(LEXLIB)
libcommon_config_compiler_la_LDFLAGS = $(LIB_LDFLAGS)
