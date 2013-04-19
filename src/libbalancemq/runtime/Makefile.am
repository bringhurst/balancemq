include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/include/ \
           -I$(top_srcdir)/src/libbalancemq/common/

noinst_LTLIBRARIES = libbalancemq_core.la

libbalancemq_core_la_SOURCES = lib.c
libbalancemq_core_la_LIBADD = libbalancemq_common.la
libbalancemq_core_la_LDFLAGS = $(LIB_LDFLAGS)
