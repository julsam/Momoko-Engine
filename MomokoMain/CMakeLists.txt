file(
	GLOB 
	ENGINE_SRCS 
	src/*.cpp
	include/*.h
)

file(GLOB
	RAPIDXML_SRCS
	include/rapidxml/*.hpp
)

set(ENGINE_SRCS ${ENGINE_SRCS}
	${RAPIDXML_SRCS}
)



add_library(Momoko
	${ENGINE_SRCS}
)
add_library(rapidxml ${RAPIDXML_SRCS})
SET_TARGET_PROPERTIES(rapidxml PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(Momoko rapidxml
	${SDL_LIBRARY}
	${DEVIL_LINK}
	${OPENGL_LIBRARIES}
)


