include $(top_srcdir)/common.mk

BUILT_SOURCES = stomp.h
PARSER = stomp.y stomp.l
AM_YFLAGS = -d

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/balancemqd/comm/stomp/compiler

noinst_LTLIBRARIES = libprotocol_stomp_compiler.la

libprotocol_stomp_compiler_la_SOURCES = stomp.y
libprotocol_stomp_compiler_la_LIBADD = $(LEXLIB)
libprotocol_stomp_compiler_la_LDFLAGS = $(LIB_LDFLAGS)
