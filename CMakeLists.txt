cmake_minimum_required(VERSION 2.8.8)
if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW) # CMake 3.0
endif()
if(POLICY CMP0043)
  cmake_policy(SET CMP0043 NEW) # CMake 3.0
endif()
if(POLICY CMP0053)
  cmake_policy(SET CMP0053 NEW) # CMake 3.1
endif()
project(EasyGraph)
add_compile_options(-std=c++11)
add_compile_options(-pthread)
find_package(VTK COMPONENTS
  vtkCommonCore
  vtkFiltersCore
  vtkInfovisCore
  vtkInteractionStyle
  vtkViewsQt
)
include(${VTK_USE_FILE})

if("${VTK_QT_VERSION}" STREQUAL "")
  message(FATAL_ERROR "VTK was not built with Qt")
endif()

# Use the include path and library for Qt that is used by VTK.
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(include Parser/include)
# Set your files and resources here
set( Srcs main.cpp
    src/mainwindow.cpp

    src/graficador.cpp
    src/gpadre.cpp

    Parser/src/interprete.cpp
    Parser/src/interprete.cpp
    Parser/src/Nodo_double.cpp
    Parser/src/arbol_binario.cpp
    Parser/src/Nodo.cpp
    Parser/src/Nodo_funcion_binaria.cpp
    Parser/src/Nodo_funcion_unaria.cpp
    Parser/src/procesador_de_arbol.cpp
    Parser/src/Interpretador.cpp
    )

set( Hdrs
    include/mainwindow.h

    include/graficador.h
    include/gpadre.h


    Parser/include/interprete.h
    Parser/include/interprete.h
    Parser/include/interprete.h
    Parser/include/Nodo_double.h
    Parser/include/arbol_binario.h
    Parser/include/Nodo.h
    Parser/include/funciones.h
    Parser/include/Nodo_funcion_binaria.h
    Parser/include/Nodo_funcion_unaria.h
    Parser/include/procesador_de_arbol.h
    Parser/include/Interpretador.h
    )

set( MOC_Hdrs include/mainwindow.h)

set( UIs ui/mainwindow.ui )

set( QRCs Resources/res.qrc )


# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# The rest should just work (sure...)
if(VTK_QT_VERSION VERSION_GREATER "4")
  # We have ui files, this will bring in the macro: qt5_wrap_ui
  find_package(Qt5 COMPONENTS Widgets REQUIRED QUIET)
  qt5_wrap_ui(UI_Srcs ${UIs})
  qt5_add_resources(QRC_Srcs ${QRCs} )

  source_group("Resources" FILES
    ${UIs}
    ${QRCs}
    ${EXE_ICON} # Not present
  )

  source_group("Generated" FILES
    ${UI_Srcs}
    ${MOC_Srcs}
    ${QRC_Srcs}
    ${QRC_Srcs}
  )

  add_executable(EasyGraph MACOSX_BUNDLE
    ${Srcs} ${Hdrs} ${UI_Srcs} ${MOC_Hdrs} ${QRC_Srcs})
  qt5_use_modules(EasyGraph Core Gui Widgets)
  target_link_libraries(EasyGraph ${VTK_LIBRARIES})
else()
  find_package(Qt4 REQUIRED)
  include(${QT_USE_FILE})
  # Use what VTK built with
  set(QT_QMAKE_EXECUTABLE ${VTK_QT_QMAKE_EXECUTABLE} CACHE FILEPATH "")
  set(QT_MOC_EXECUTABLE ${VTK_QT_MOC_EXECUTABLE} CACHE FILEPATH "")
  set(QT_UIC_EXECUTABLE ${VTK_QT_UIC_EXECUTABLE} CACHE FILEPATH "")
  qt4_wrap_ui(UI_Srcs ${UIs})
  qt4_wrap_cpp(MOC_Srcs ${MOC_Hdrs} )
  qt4_add_resources(QRC_Srcs ${QRCs})

  source_group("Resources" FILES
    ${UIs}
    ${QRCs}
    ${EXE_ICON} # Not present
  )

  source_group("Generated" FILES
    ${UI_Srcs}
    ${QRC_Srcs}
    ${QRC_Srcs}
  )

  add_definitions(-DQT_GUI_LIBS -DQT_CORE_LIB -DQT3_SUPPORT)

  add_executable(EasyGraph MACOSX_BUNDLE
    ${Srcs} ${Hdrs} ${UI_Srcs} ${MOC_Hdrs} ${QRC_Srcs})
  target_link_libraries(EasyGraph
    ${QT_LIBRARIES}
    ${VTK_LIBRARIES}
  )
endif()
