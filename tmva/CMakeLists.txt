set(CHANZER chansermva)
set(DIRNAME tmva)

include_directories(core)

ROOT_GENERATE_DICTIONARY(G__${CHANZER}   TrainingInterface.h  ResultInterface.h  TrainSignalID.h LINKDEF MvaLinkDef.h)

add_library(${CHANZER} SHARED  TrainingInterface.cpp ResultInterface.cpp  TrainSignalID.cpp G__${CHANZER}.cxx)

target_link_libraries(${CHANZER} ${ROOT_LIBRARIES} )


install(TARGETS ${CHANZER} 
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

FILE(GLOB ROOT_CHANZER_PCM ${CMAKE_BINARY_DIR}/*pcm ${CMAKE_BINARY_DIR}/${DIRNAME}/*pcm)

install (FILES  ${ROOT_CHANZER_PCM}    
  DESTINATION "${CMAKE_INSTALL_LIBDIR}")

