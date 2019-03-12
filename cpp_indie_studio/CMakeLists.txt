cmake_minimum_required(VERSION 3.10.0)

project(bomberman)
set(EXECUTABLE_OUTPUT_PATH .)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -isystem ./inc -fsanitize=address -g3")

if (UNIX)
  find_package(X11)

  include_directories(
    ${X11_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
  )

  link_directories(./lib/linux)

  add_definitions(-DLINUX)
  add_definitions(-DUNIX)
endif (UNIX)

if (WIN32)
  include_directories(
    ${PROJECT_SOURCE_DIR}/src
    )

  link_directories(./lib/windows)

  add_definitions(-DWIN32)
endif (WIN32)

add_executable(bomberman
  src/Main.cpp

  src/Object/ABomb/DefaultBomb.cpp
  src/Object/ABomb/ABomb.cpp

  src/Object/APowerUp/APowerUp.cpp
  src/Object/APowerUp/PowerSpeed.cpp

  src/Core/CoreServer.cpp
  src/Core/CoreClient.cpp
  src/Core/CoreAI.cpp
  src/Core/CorePlayer.cpp

  src/Character/ACharacter.cpp
  src/Character/AAI.cpp
  src/Character/Player.cpp

  src/SocketManager.cpp

  src/Parser.cpp

  src/Graphics/Animation.cpp
  src/Graphics/GameMenu.cpp
  src/Graphics/GameRender.cpp
  src/Graphics/LobbySolo.cpp
  src/Graphics/MainMenu.cpp
  src/Graphics/OptionsMenu.cpp
  src/Graphics/PlayMenu.cpp
  src/Serializer.cpp

  src/Threads/ThreadPool.cpp
  src/Threads/Thread.cpp

  src/Generator.cpp

  src/Difficulties/Easy.cpp
  src/Difficulties/ADifficulties.cpp

  src/Timer.cpp
  src/Sound.cpp
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
