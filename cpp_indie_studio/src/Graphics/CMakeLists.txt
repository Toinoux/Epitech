cmake_minimum_required(VERSION 3.10.0)

project(bomberman)
set(EXECUTABLE_OUTPUT_PATH .)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -g3")

if (UNIX)
  find_package(X11)

  include_directories(
    ${X11_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
  )

  link_directories(./lib/linux)

  add_definitions(-DLINUX)
  add_definitions(-DUNIX)
endif (UNIX)

if (WIN32)

  #set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
  #find_package(SFML 2.4 REQUIRED audio system)
  #if(SFML_FOUND)
  #  include_directories(${SFML_INCLUDE_DIR})
  #  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
  #endif()
  include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
    )

  link_directories(./lib/windows)

  add_definitions(-DWIN32)
endif (WIN32)

add_executable(bomberman
  src/model.cpp

  src/Object/ABomb/DefaultBomb.cpp
  src/Object/ABomb/MineBomb.cpp
  src/Object/ABomb/RedBomb.cpp
  src/Object/ABomb/RemoteBomb.cpp
  src/Object/ABomb/ABomb.cpp

  src/Object/APowerUp/APowerUp.cpp
  src/Object/APowerUp/PowerKick.cpp
  src/Object/APowerUp/PowerChrono.cpp
  src/Object/APowerUp/PowerRange.cpp
  src/Object/APowerUp/PowerSlot.cpp
  src/Object/APowerUp/PowerSpeed.cpp
  src/Object/APowerUp/PowerThrow.cpp

  src/Object/AWall/AWall.cpp
  src/Object/AWall/DestroyableWall.cpp
  src/Object/AWall/SolidWall.cpp

  src/Core/CoreServer.cpp
  src/Core/CoreClient.cpp
  src/Core/CoreAI.cpp
  src/Core/CorePlayer.cpp

  src/Character/ACharacter.cpp
  src/Character/AAI.cpp
  src/Character/Player.cpp

  src/SocketManager.cpp

  src/Parser.cpp

  src/Serializer.cpp

  src/Threads/ThreadPool.cpp
  src/Threads/Thread.cpp

  src/Generator.cpp
  src/Timer.cpp
  src/Sound.cpp

  src/Graphics/Animation.cpp
  src/Graphics/GameMenu.cpp
  src/Graphics/GameRender.cpp
  src/Graphics/LobbySolo.cpp
  src/Graphics/MainMenu.cpp
  src/Graphics/OptionsMenu.cpp
  src/Graphics/PlayMenu.cpp
)

if (UNIX)
  target_link_libraries(bomberman
    ${X11_LIBRARIES}
    Irrlicht
    GL
    Xxf86vm
    pthread
    sfml-audio
    sfml-system
  )
endif (UNIX)

if (WIN32)
  target_link_libraries(bomberman
    ws2_32
    Irrlicht
    pthread
    sfml-audio
    sfml-system
  )
endif (WIN32)
