include $(top_srcdir)/common.mk

SUBDIRS = include common startup runtime plugins

lib_LTLIBRARIES = libbalancemq.la

libbalancemq_la_SOURCES =
libbalancemq_la_LDFLAGS = $(LIB_LDFLAGS)
libbalancemq_la_CPPFLAGS = \
						   -I$(top_srcdir)/src/libbalancemq/include \
						   -I$(top_srcdir)/src/libbalancemq/common
libbalancemq_la_LIBADD = \
                         common/libbalancemq_common.la \
                         runtime/libbalancemq_runtime.la \
                         startup/libbalancemq_startup.la
