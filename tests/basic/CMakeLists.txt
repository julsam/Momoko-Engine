set(BASIC_SRCS
	main.cpp
	Basic.cpp
)

add_executable(Basic ${BASIC_SRCS})

target_link_libraries(Basic Momoko rapidxml
	${SDL_LIBRARY}
	${DEVIL_LINK}
	${OPENGL_LIBRARIES}
)

