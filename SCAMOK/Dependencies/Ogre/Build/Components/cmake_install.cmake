# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/sdk")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Bites/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Paging/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/MeshLodGenerator/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Property/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Terrain/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/RTShaderSystem/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Volume/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/Overlay/cmake_install.cmake")
  include("C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/HLMS/cmake_install.cmake")

endif()

