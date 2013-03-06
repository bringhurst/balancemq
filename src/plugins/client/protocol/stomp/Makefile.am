include $(top_srcdir)/common.mk

SUBDIRS = parser

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/plugins/client/protocol/stomp/parser

pkglib_LTLIBRARIES = libclient_protocol_stomp.la

libclient_protocol_stomp_la_SOURCES = stomp_server.c client_protocol_stomp.c
libclient_protocol_stomp_la_LIBADD =
libclient_protocol_stomp_la_LDFLAGS = $(LIB_LDFLAGS) -module -avoid-version -shared
