# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Release/RenderSystem_GL.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Release/RenderSystem_GL.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/RelWithDebInfo/RenderSystem_GL.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/RenderSystem_GL.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/MinSizeRel/RenderSystem_GL.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/MinSizeRel/RenderSystem_GL.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Debug/RenderSystem_GL_d.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/RenderSystem_GL_d.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/RenderSystem_GL_d.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/RenderSystem_GL.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE FILE FILES
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLCopyingRenderTexture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLDepthBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLFBOMultiRenderTarget.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLFBORenderTexture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLFrameBufferObject.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLGpuNvparseProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLGpuProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLGpuProgramManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLHardwareBufferManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLHardwareIndexBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLHardwareOcclusionQuery.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLHardwarePixelBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLHardwareVertexBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLPBRenderTexture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLPixelFormat.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLPlugin.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLPrerequisites.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLRenderSystem.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLRenderToVertexBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLStateCacheManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLSupport.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLTexture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/OgreGLTextureManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLExtSupport.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLGpuProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLLinkProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLLinkProgramManager.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLProgram.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/OgreGLSLProgramFactory.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/_ps1.0_parser.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/_rc1.0_parser.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/_ts1.0_parser.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/_vs1.0_parser.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/macro.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/nvparse.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/nvparse_errors.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/nvparse_externs.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/ps1.0_program.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/rc1.0_combiners.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/rc1.0_final.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/rc1.0_general.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/rc1.0_register.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/ts1.0_inst.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/ts1.0_inst_list.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/vs1.0_inst.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/nvparse/vs1.0_inst_list.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLContext.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLHardwarePixelBufferCommon.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLNativeSupport.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLPBuffer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLRenderSystemCommon.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLRenderTexture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLStateCacheManagerCommon.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLTextureCommon.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLUniformCache.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLUtil.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GLSupport/include/OgreGLVertexArrayObject.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/include/OgreGLSupportPrerequisites.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE DIRECTORY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/include/GL")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE DIRECTORY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/RenderSystems/GL/src/GLSL/include/")
endif()

