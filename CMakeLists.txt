project(adv_cmds)

cmake_minimum_required(VERSION 2.4.0)

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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -U_POSIX_C_SOURCE -D__DARWIN_UNIX03 -fblocks -fPIC -ggdb -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -U_POSIX_C_SOURCE -D__DARWIN_UNIX03 -fblocks -fPIC -ggdb -O0")

include_directories(${CMAKE_SOURCE_DIR}/src/libc/include/FreeBSD)
include_directories(${CMAKE_SOURCE_DIR}/src/libc/gen)
include_directories(${CMAKE_SOURCE_DIR}/src/libc/darwin)
include_directories(${CMAKE_SOURCE_DIR}/src/ncurses/include)
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/src/external/libcxx/include)
include_directories(${CMAKE_SOURCE_DIR}/src/external/libcxxabi/include)
include_directories(${CMAKE_SOURCE_DIR}/src/launchd/liblaunch)
include_directories(${CMAKE_SOURCE_DIR}/src/kernel/libsyscall/wrappers/libproc)

include(InstallSymlink)
set(BINARY_PACKAGING_MODE ON)

add_darling_executable(locale locale/locale.cc ${CMAKE_SOURCE_DIR}/src/libstdcxx/src/dso_handle.c)
target_link_libraries(locale cxx)

add_darling_executable(tabs tabs/tabs.c)
target_link_libraries(tabs ncurses)

add_darling_executable(tty tty/tty.c)
add_darling_executable(whois whois/whois.c)
add_darling_executable(stty stty/cchar.c  stty/gfmt.c  stty/key.c  stty/modes.c  stty/print.c  stty/stty.c  stty/util.c)
#add_darling_executable(pkill pkill/pkill.c) # doesn't build yet, requires sysmon.h
add_darling_executable(ps ps/fmt.c  ps/keyword.c  ps/nlist.c  ps/print.c  ps/ps.c  ps/tasks.c)

install(TARGETS locale tabs tty whois
	DESTINATION libexec/darling/usr/bin)

install(TARGETS stty ps
	DESTINATION libexec/darling/bin)


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
install(FILES fingerd/fingerd.8 DESTINATION libexec/darling/usr/share/man/man8)
