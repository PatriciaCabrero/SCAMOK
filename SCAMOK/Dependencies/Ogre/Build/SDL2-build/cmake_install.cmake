# Install script for directory: C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/Dependencies")
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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Release/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Debug/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/Release/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/MinSizeRel/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_assert.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_atomic.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_audio.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_bits.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_blendmode.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_clipboard.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_android.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_iphoneos.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_macosx.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_minimal.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_pandora.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_psp.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_windows.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_winrt.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_config_wiz.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_copying.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_cpuinfo.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_egl.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_endian.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_error.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_events.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_filesystem.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_gamecontroller.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_gesture.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_haptic.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_hints.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_joystick.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_keyboard.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_keycode.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_loadso.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_log.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_main.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_messagebox.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_mouse.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_mutex.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_name.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengl.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengl_glext.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles2.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles2_gl2.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles2_gl2ext.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles2_gl2platform.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_opengles2_khrplatform.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_pixels.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_platform.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_power.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_quit.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_rect.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_render.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_revision.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_rwops.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_scancode.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_shape.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_stdinc.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_surface.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_system.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_syswm.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_assert.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_common.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_compare.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_crc32.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_font.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_fuzzer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_harness.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_images.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_log.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_md5.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_test_random.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_thread.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_timer.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_touch.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_types.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_version.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/SDL_video.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/begin_code.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-2.0.5/include/close_code.h"
    "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/include/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/hlocal/Nueva carpeta/P3/ProyectoBasico/Dependencies/Ogre/Build/SDL2-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
