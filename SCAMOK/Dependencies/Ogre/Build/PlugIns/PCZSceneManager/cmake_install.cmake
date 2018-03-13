# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Release/Plugin_PCZSceneManager.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Release/Plugin_PCZSceneManager.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/RelWithDebInfo/Plugin_PCZSceneManager.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/Plugin_PCZSceneManager.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/MinSizeRel/Plugin_PCZSceneManager.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/MinSizeRel/Plugin_PCZSceneManager.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Debug/Plugin_PCZSceneManager_d.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/Plugin_PCZSceneManager_d.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/Plugin_PCZSceneManager_d.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/Plugin_PCZSceneManager.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/Plugins/PCZSceneManager" TYPE FILE FILES
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgreAntiPortal.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgreCapsule.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgreDefaultZone.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCPlane.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZCamera.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZFrustum.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZLight.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZPlugin.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZSceneManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZSceneNode.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZSceneQuery.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZone.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePCZoneFactory.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePortal.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgrePortalBase.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/PlugIns/PCZSceneManager/include/OgreSegment.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/include/OgrePCZPrerequisites.h"
    )
endif()

