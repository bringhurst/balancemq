include $(top_srcdir)/common.mk

SUBDIRS = parser

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/balancemqd/protocol/stomp/parser

noinst_LTLIBRARIES = libprotocol_stomp.la

libprotocol_stomp_la_SOURCES = protocol_stomp.c
libprotocol_stomp_la_LIBADD =
libprotocol_stomp_la_LDFLAGS = $(LIB_LDFLAGS)
