project(adv_cmds)

cmake_minimum_required(VERSION 3.13)

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

include(darling_exe)
# add_definitions(-DSUPPORT_UTMPX)

# Hide warnings
add_definitions(
	-w
	-nostdinc
)

add_compile_definitions(
	__DARWIN_UNIX03

	# this is only defined for some targets in the Xcode build files,
	# but it's probably fine to define it for everyone
	__FBSDID=__RCSID
)

add_compile_options(
	#-U_POSIX_C_SOURCE
	-fblocks
	-fPIC

	-ggdb
	-O0
)

include(InstallSymlink)
set(BINARY_PACKAGING_MODE ON)

#
# ps
#

add_darling_executable(ps
	ps/fmt.c
	ps/keyword.c
	ps/nlist.c
	ps/print.c
	ps/ps.c
	ps/tasks.c
)

#
# stty
#

add_darling_executable(stty
	stty/cchar.c
	stty/gfmt.c
	stty/key.c
	stty/modes.c
	stty/print.c
	stty/stty.c
	stty/util.c
)

#
# cap_mkdb
#

add_darling_executable(cap_mkdb
	cap_mkdb/cap_mkdb.c
)

#
# colldef
#
# requires libl (for `yywrap`)
#
#add_darling_executable(colldef
#	gen/colldef/colldef_vers.c
#	gen/colldef/scan.yy.c
#	gen/colldef/y.tab.c
#)
#target_compile_definitions(colldef PRIVATE
#	COLLATE_DEBUG
#	YY_NO_UNPUT
#)
#target_include_directories(colldef PRIVATE
#	colldef
#	colldef/locale
#)
#target_link_libraries(colldef
#	libl
#)

#
# finger
#

add_darling_executable(finger
	finger/finger.c
	finger/lprint.c
	finger/net.c
	finger/sprint.c
	finger/util.c
)

#
# gencat
#

add_darling_executable(gencat
	gencat/gencat.c
	gencat/genlib.c
)

#
# last
#

add_darling_executable(last
	last/last.c
)

#
# locale
#

add_darling_executable(locale
	locale/locale.cc
)
target_link_libraries(locale
	cxx
)

#
# lsvfs
#

add_darling_executable(lsvfs
	lsvfs/lsvfs.c
)

#
# mklocale
#

add_darling_executable(mklocale
	gen/mklocale/lex.yy.c
	gen/mklocale/mklocale_vers.c
	gen/mklocale/y.tab.c
)
target_include_directories(mklocale PRIVATE
	mklocale
)

#
# tabs
#

add_darling_executable(tabs
	tabs/tabs.c
)
target_link_libraries(tabs
	ncurses
)

#
# tty
#

add_darling_executable(tty
	tty/tty.c
)

#
# whois
#

add_darling_executable(whois
	whois/whois.c
)

#
# pkill
#
# requires libsysmon
#
#add_darling_executable(pkill
#	pkill/pkill.c
#)
#target_link_libraries(pkill
#	libsysmon
#)

#
# install everything
#

install(
	TARGETS
		cap_mkdb
		#colldef
		finger
		gencat
		last
		locale
		lsvfs
		mklocale
		tabs
		tty
		whois
	DESTINATION libexec/darling/usr/bin
)

install(
	TARGETS
		ps
		stty
	DESTINATION libexec/darling/bin
)

set(man1
	cap_mkdb/cap_mkdb.1
	colldef/colldef.1
	finger/finger.1
	gencat/gencat.1
	last/last.1
	locale/locale.1
	localedef/localedef.1
	lsvfs/lsvfs.1
	mklocale/mklocale.1
	pkill/pkill.1
	ps/ps.1
	stty/stty.1
	tabs/tabs.1
	tty/tty.1
	whois/whois.1
)

install(FILES ${man1} DESTINATION libexec/darling/usr/share/man/man1)
install(FILES finger/finger.conf.5 DESTINATION libexec/darling/usr/share/man/man5)

# Apple seems to have removed fingerd from macOS?
#install(FILES fingerd/fingerd.8 DESTINATION libexec/darling/usr/share/man/man8)
