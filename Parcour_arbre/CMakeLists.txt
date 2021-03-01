cmake_minimum_required(VERSION 3.0)

project(Projet_IN505)

find_package(Qt4)

set(CMAKE_AUTOMOC TRUE)

include_directories(headers)
file(GLOB_RECURSE HEADERS
	headers/*.hpp
)

set(SRCS
	Main.cc
	ArbreB.h
	ArbreB.cc
	Sommet.h
	Sommet.cc
	Fenetre.hh
	Cryptage.h
)

add_executable(main ${SRCS} ${HEADERS})
target_link_libraries(main Qt4::QtCore Qt4::QtGui)
