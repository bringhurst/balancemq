include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/startup/plugin_loader

noinst_LTLIBRARIES = libbalancemq_startup_plugin_loader.la

libbalancemq_startup_plugin_loader_la_SOURCES = balancemq_plugin.c
libbalancemq_startup_plugin_loader_la_LIBADD =
libbalancemq_startup_plugin_loader_la_LDFLAGS = $(LIB_LDFLAGS)
