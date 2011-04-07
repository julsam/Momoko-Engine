set(HELLOBOX2D_SRCS
	main.cpp
	helloBox2d.cpp
)

add_executable(helloBox2d ${HELLOBOX2D_SRCS})

target_link_libraries(helloBox2d Momoko Box2D rapidxml
	${SDL_LIBRARY}
	${DEVIL_LINK}
	${OPENGL_LIBRARIES}
)

