include $(top_srcdir)/common.mk

SUBDIRS = config

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/common/

noinst_LTLIBRARIES = libcommon.la

libcommon_la_SOURCES = balancemq_plugin.c
libcommon_la_LIBADD =
libcommon_la_LDFLAGS = $(LIB_LDFLAGS)
