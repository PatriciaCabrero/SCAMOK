# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Release/OgreMeshLodGenerator.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Release/OgreMeshLodGenerator.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/RelWithDebInfo/OgreMeshLodGenerator.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreMeshLodGenerator.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/MinSizeRel/OgreMeshLodGenerator.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/MinSizeRel/OgreMeshLodGenerator.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Debug/OgreMeshLodGenerator_d.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreMeshLodGenerator_d.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreMeshLodGenerator_d.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreMeshLodGenerator.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/MeshLodGenerator" TYPE FILE FILES
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLod0Stripifier.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapseCost.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapseCostCurvature.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapseCostOutside.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapseCostProfiler.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapseCostQuadric.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodCollapser.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodConfig.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodConfigSerializer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodData.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodInputProvider.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodInputProviderBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodInputProviderMesh.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutputProvider.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutputProviderBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutputProviderCompressedBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutputProviderCompressedMesh.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutputProviderMesh.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodOutsideMarker.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodPrerequisites.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodWorkQueueInjector.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodWorkQueueInjectorListener.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodWorkQueueRequest.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreLodWorkQueueWorker.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreMeshLodGenerator.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreSmallVector.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreVectorSet.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/MeshLodGenerator/include/OgreVectorSetImpl.h"
    )
endif()

