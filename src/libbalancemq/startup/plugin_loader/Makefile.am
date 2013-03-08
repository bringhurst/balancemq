include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/plugins/loader

noinst_LTLIBRARIES = lib_plugin_loader.la

lib_plugin_loader_la_SOURCES = balancemq_plugin.c
lib_plugin_loader_la_LIBADD =
lib_plugin_loader_la_LDFLAGS = $(LIB_LDFLAGS)
