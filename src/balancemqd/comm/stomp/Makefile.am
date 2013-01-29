include $(top_srcdir)/common.mk

SUBDIRS = compiler

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/balancemqd/comm/stomp/compiler \
           -I$(top_srcdir)/contrib/antlr/libantlr3c-3.4/include \
           -I$(top_srcdir)/contrib/antlr/libantlr3c-3.4

noinst_LTLIBRARIES = libprotocol_stomp.la

libprotocol_stomp_la_SOURCES = protocol_stomp.c
libprotocol_stomp_la_LIBADD = -lantlr3
libprotocol_stomp_la_LDFLAGS = $(LIB_LDFLAGS)
