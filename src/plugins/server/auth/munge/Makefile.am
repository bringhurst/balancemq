include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/plugins/server/auth/munge

pkglib_LTLIBRARIES = libserver_auth_munge.la

libserver_auth_munge_la_SOURCES = server_auth_munge.c
libserver_auth_munge_la_LIBADD =
libserver_auth_munge_la_LDFLAGS = $(LIB_LDFLAGS) -module -avoid-version -shared
