# Install script for directory: C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/cegui")
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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/lib/CEGUIBase-0_d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/lib/CEGUIBase-0.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/lib/CEGUIBase-0.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/lib/CEGUIBase-0.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/bin/CEGUIBase-0_d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/bin/CEGUIBase-0.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/bin/CEGUIBase-0.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/bin/CEGUIBase-0.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI" TYPE FILE FILES
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Affector.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Animation.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/AnimationInstance.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/AnimationManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Animation_xmlHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Base.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/BasicImage.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/BasicRenderedStringParser.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/BidiVisualMapping.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/BoundSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/CEGUI.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/CentredRenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ChainedXMLHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Clipboard.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Colour.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ColourRect.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/CompositeResourceProvider.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Config_xmlHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/CoordConverter.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/DataContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultLogger.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultRenderedStringParser.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultResourceProvider.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/DynamicModule.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Element.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Event.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/EventArgs.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/EventSet.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Exceptions.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FactoryModule.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FactoryRegisterer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Font.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FontGlyph.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FontManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Font_xmlHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FormattedRenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ForwardRefs.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FreeFunctionSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FreeTypeFont.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FribidiVisualMapping.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorCopySlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorPointerSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorReferenceBinder.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorReferenceSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/GUIContext.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/GUILayout_xmlHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/GeometryBuffer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/GlobalEventSet.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/IconvStringTranscoder.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Image.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ImageCodec.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ImageFactory.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ImageManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/InjectedInputReceiver.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/InputEvent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Interpolator.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/IteratorBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/JustifiedRenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/KeyFrame.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/LeftAlignedRenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/LinkedEvent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Logger.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemberFunctionSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryAllocatedObject.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryAllocation.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryOgreAllocator.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemorySTLWrapper.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryStdAllocator.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MinibidiVisualMapping.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MinizipResourceProvider.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/MouseCursor.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/NamedElement.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/NamedXMLResourceManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/PCRERegexMatcher.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/PixmapFont.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Property.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/PropertyHelper.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/PropertySet.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Quaternion.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Rect.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RefCounted.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RegexMatcher.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffect.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffectFactory.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffectManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderQueue.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderTarget.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringImageComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringParser.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringTextComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringWidgetComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringWordWrapper.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Renderer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingContext.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingSurface.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingWindow.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ResourceProvider.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/RightAlignedRenderedString.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Scheme.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/SchemeManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Scheme_xmlHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/ScriptModule.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/SimpleTimer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Singleton.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Size.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/SlotFunctorBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/String.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/StringTranscoder.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/SubscriberSlot.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/System.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/SystemKeys.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TextUtils.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Texture.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TextureTarget.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplInterpolators.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplProperty.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWRFactoryRegisterer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowFactory.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowFactoryRegisterer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowProperty.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowRendererFactory.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowRendererProperty.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/TypedProperty.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/UDim.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Vector.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Vertex.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Win32StringTranscoder.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/Window.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/WindowFactory.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/WindowFactoryManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/WindowManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/WindowRenderer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/WindowRendererManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/XMLAttributes.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/XMLHandler.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/XMLParser.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/XMLSerializer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/cegui/src/../include/CEGUI/Config.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/cegui/src/../include/CEGUI/ModuleConfig.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/build/cegui/src/../include/CEGUI/Version.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/widgets" TYPE FILE FILES
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/All.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ButtonBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ClippedContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ComboDropList.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Combobox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/DefaultWindow.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/DragContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Editbox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/FrameWindow.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/GridLayoutContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/GroupBox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/HorizontalLayoutContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemEntry.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemListBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemListbox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/LayoutCell.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/LayoutContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListHeader.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListHeaderSegment.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Listbox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListboxItem.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListboxTextItem.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MenuBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MenuItem.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Menubar.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MultiColumnList.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MultiLineEditbox.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/PopupMenu.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ProgressBar.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/PushButton.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/RadioButton.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrollablePane.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Scrollbar.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrolledContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrolledItemListBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/SequentialLayoutContainer.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Slider.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Spinner.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TabButton.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TabControl.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Thumb.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Titlebar.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ToggleButton.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Tooltip.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Tree.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TreeItem.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/VerticalLayoutContainer.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/falagard" TYPE FILE FILES
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ComponentBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/Dimensions.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/Enums.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/EventAction.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/EventLinkDefinition.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FalagardPropertyBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FormattingSetting.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FrameComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ImageryComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ImagerySection.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/LayerSpecification.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/NamedArea.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/NamedDefinitionCollator.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyDefinition.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyDefinitionBase.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyInitialiser.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyLinkDefinition.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/SectionSpecification.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/StateImagery.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/TextComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetComponent.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetLookFeel.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetLookManager.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/XMLEnumHelper.h"
    "C:/hlocal/Proyecto3/Proyecto_3/SCAMOK/Dependencies/CEGUI/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/XMLHandler.h"
    )
endif()

