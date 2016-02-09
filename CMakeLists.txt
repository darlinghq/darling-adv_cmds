project(adv_cmds)

cmake_minimum_required(VERSION 2.4.0)

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

include(darling_exe)
add_definitions(-DTARGET_OS_MAC=1)
add_definitions(-D__APPLE__ -D__DYNAMIC__)
# add_definitions(-DSUPPORT_UTMPX)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -U_POSIX_C_SOURCE -D__DARWIN_UNIX03 -nostdinc -fblocks -fPIC -ggdb -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -U_POSIX_C_SOURCE -D__DARWIN_UNIX03 -nostdinc -nostdinc++ -fblocks -fPIC -ggdb -O0")
set(CMAKE_EXE_LINKER_FLAGS "-nodefaultlibs -nostdlib -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")
#set(CMAKE_SHARED_LINKER_FLAGS "-nodefaultlibs -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

include_directories(${CMAKE_SOURCE_DIR}/src/libc/include/FreeBSD)
include_directories(${CMAKE_SOURCE_DIR}/src/libc/gen)
include_directories(${CMAKE_SOURCE_DIR}/src/libc/darwin)
include_directories(${CMAKE_SOURCE_DIR}/src/ncurses/include)
include_directories(${CMAKE_SOURCE_DIR}/src/external/libcxx/include)
include_directories(${CMAKE_SOURCE_DIR}/src/external/libcxxabi/include)

include(InstallSymlink)
set(BINARY_PACKAGING_MODE ON)

add_darling_executable(locale locale/locale.cc ${CMAKE_SOURCE_DIR}/src/libstdcxx/src/dso_handle.c)
target_link_libraries(locale cxx)

add_darling_executable(tabs tabs/tabs.c)
target_link_libraries(tabs ncurses)

add_darling_executable(tty tty/tty.c)
add_darling_executable(whois whois/whois.c)
add_darling_executable(stty stty/cchar.c  stty/gfmt.c  stty/key.c  stty/modes.c  stty/print.c  stty/stty.c  stty/util.c)
#add_darling_executable(pkill pkill/pkill.c) # doesn't build yet
add_darling_executable(ps ps/fmt.c  ps/keyword.c  ps/nlist.c  ps/print.c  ps/ps.c  ps/tasks.c)

install(TARGETS locale stty tabs tty whois ps
	DESTINATION libexec/darling/usr/bin)

