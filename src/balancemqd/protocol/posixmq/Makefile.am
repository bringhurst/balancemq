include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/balancemqd/protocol/posixmq

noinst_LTLIBRARIES = libprotocol_posixmq.la

libprotocol_posixmq_la_SOURCES = protocol_posixmq.c
libprotocol_posixmq_la_LIBADD =
libprotocol_posixmq_la_LDFLAGS = $(LIB_LDFLAGS)
