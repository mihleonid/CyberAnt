cmake_minimum_required(VERSION 3.5)
project(CyberAnt)

set(src
	assets.cpp
	base.cpp
	building.cpp
	configurator.cpp
	controller.cpp
	event.cpp
	eventqueue.cpp
	field.cpp
	fieldcontroller.cpp
	fieldevent.cpp
	fieldmodel.cpp
	fieldview.cpp
	fo.cpp
	foenum.cpp
	gamecontroller.cpp
	gamecontrollerevent.cpp
	main.cpp
	model.cpp
	point.cpp
	putable.cpp
	random.cpp
	resource.cpp
	resourced.cpp
	resourcenode.cpp
	resourceset.cpp
	tubed.cpp
	view.cpp
	xstack.cpp
	xstackiterator.cpp
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cyberant ${src})
target_link_libraries(cyberant SDL2 SDL2_ttf pthread)

add_definitions(-std=c++11)

