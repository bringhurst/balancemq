include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/plugins/server/auth/none

pkglib_LTLIBRARIES = libserver_auth_none.la

libserver_auth_none_la_SOURCES = server_auth_none.c
libserver_auth_none_la_LIBADD =
libserver_auth_none_la_LDFLAGS = $(LIB_LDFLAGS) -module -avoid-version -shared
