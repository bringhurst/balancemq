include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/plugins/client/protocol/posixmq

pkglib_LTLIBRARIES = libclient_protocol_posixmq.la

libclient_protocol_posixmq_la_SOURCES = client_protocol_posixmq.c
libclient_protocol_posixmq_la_LIBADD =
libclient_protocol_posixmq_la_LDFLAGS = $(LIB_LDFLAGS) -module -avoid-version -shared
