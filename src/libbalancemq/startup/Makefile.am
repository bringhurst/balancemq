SUBDIRS = settings plugin_loader

include $(top_srcdir)/common.mk

noinst_LTLIBRARIES = libbalancemq_startup.la

libbalancemq_startup_la_SOURCES =
libbalancemq_startup_la_LDFLAGS = $(LIB_LDFLAGS)
libbalancemq_startup_la_LIBADD = \
								 plugin_loader/libbalancemq_startup_plugin_loader.la \
								 settings/libbalancemq_startup_settings.la
