include $(top_srcdir)/common.mk

SUBDIRS = plugin_loader

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/include/ \
           -I$(top_srcdir)/src/common/

noinst_LTLIBRARIES = libbalancemq_runtime.la

libbalancemq_runtime_la_SOURCES = lib.c
libbalancemq_runtime_la_LIBADD = plugin_loader/libbalancemq_startup_plugin_loader.la
libbalancemq_runtime_la_LDFLAGS = $(LIB_LDFLAGS)
