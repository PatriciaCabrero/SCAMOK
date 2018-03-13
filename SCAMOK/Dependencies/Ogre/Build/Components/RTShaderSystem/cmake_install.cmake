# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Release/OgreRTShaderSystem.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Release/OgreRTShaderSystem.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/RelWithDebInfo/OgreRTShaderSystem.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreRTShaderSystem.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/MinSizeRel/OgreRTShaderSystem.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/MinSizeRel/OgreRTShaderSystem.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Debug/OgreRTShaderSystem_d.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreRTShaderSystem_d.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreRTShaderSystem_d.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreRTShaderSystem.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RTShaderSystem" TYPE FILE FILES
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreRTShaderSystem.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderCGProgramProcessor.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderCGProgramWriter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExDualQuaternionSkinning.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExHardwareSkinning.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExHardwareSkinningTechnique.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExIntegratedPSSM3.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExLayeredBlending.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExLinearSkinning.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExNormalMapLighting.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExPerPixelLighting.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExTextureAtlasSampler.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderExTriplanarTexturing.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPAlphaTest.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPColour.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPFog.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPLighting.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPRenderState.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPRenderStateBuilder.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPTexturing.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFFPTransform.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFunction.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderFunctionAtom.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderGLSLESProgramProcessor.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderGLSLESProgramWriter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderGLSLProgramProcessor.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderGLSLProgramWriter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderGenerator.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderHLSLProgramProcessor.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderHLSLProgramWriter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderMaterialSerializerListener.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderParameter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderPrerequisites.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgramManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgramProcessor.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgramSet.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgramWriter.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderProgramWriterManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderRenderState.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderScriptTranslator.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Components/RTShaderSystem/include/OgreShaderSubRenderState.h"
    )
endif()

