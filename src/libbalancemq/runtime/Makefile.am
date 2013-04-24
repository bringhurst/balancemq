include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/include/ \
           -I$(top_srcdir)/src/common/

noinst_LTLIBRARIES = libbalancemq_runtime.la

libbalancemq_runtime_la_SOURCES = lib.c
libbalancemq_runtime_la_LIBADD =
libbalancemq_runtime_la_LDFLAGS = $(LIB_LDFLAGS)
