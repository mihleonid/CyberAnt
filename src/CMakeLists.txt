cmake_minimum_required(VERSION 3.5)
project(CyberAnt)

set(src
	acallback.cpp
	ask.cpp
	assets.cpp
	base.cpp
	bigtube.cpp
	building.cpp
	callback.cpp
	configurator.cpp
	controller.cpp
	crazyto.cpp
	event.cpp
	eventlistener.cpp
	eventqueue.cpp
	field.cpp
	fieldcontroller.cpp
	fieldevent.cpp
	fieldeventlistener.cpp
	fieldmodel.cpp
	fieldview.cpp
	fo.cpp
	foenum.cpp
	gamecontroller.cpp
	gamecontrollerevent.cpp
	gameovercontroller.cpp
	gun.cpp
	main.cpp
	menucontroller.cpp
	mine.cpp
	model.cpp
	point.cpp
	putable.cpp
	random.cpp
	resource.cpp
	resourced.cpp
	resourcenode.cpp
	resourceset.cpp
	settingscontroller.cpp
	standingenemy.cpp
	to.cpp
	tubed.cpp
	ui/lbutton.cpp
	ui/lcheckbox.cpp
	ui/lcheckboxswitcher.cpp
	ui/lcolor.cpp
	ui/lcomponent.cpp
	ui/lcontrol.cpp
	ui/ldrawer.cpp
	ui/levent.cpp
	ui/leventsender.cpp
	ui/limage.cpp
	ui/lkeyboardevent.cpp
	ui/lkeyboardlistener.cpp
	ui/lmonocolor.cpp
	ui/lmouseevent.cpp
	ui/lpanel.cpp
	ui/lrectedcomponent.cpp
	ui/lscene.cpp
	ui/lsubscriber.cpp
	ui/ltalk.cpp
	ui/ltextbox.cpp
	ui/lwindow.cpp
	ui/sdl/lsdrawer.cpp
	ui/terminal/ltdrawer.cpp
	ui/terminal/ltsurface.cpp
	view.cpp
	xstack/xstack.cpp
	xstack/xstackiterator.cpp
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cyberant ${src})
target_link_libraries(cyberant asan SDL2 SDL2_ttf pthread)

add_definitions(-std=c++11)
add_definitions(-DDEBUG)
add_definitions(-DSDL)
add_definitions(-g)
add_definitions(-ggdb)
add_definitions(-fsanitize=address)

