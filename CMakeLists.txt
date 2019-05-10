cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_Guschin_Lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(vector vector) #Переменная с именем библиотеки
set(vectorlib vectorlib) #Переменная с именем библиотеки
set(vectortest vectortest)
set(stack stack)
set(stacklib stacklib)
set(stacktest stacktest)
set(exception exception)
set(queue queue)
set(queuetest queuetest)
set(queuelib queuelib)
set(multistack multistack)
set(multistacktest multistacktest)
set(multistacklib multistacklib)
set(list list)
set(listlib listlib)
set(listtest listtest)
set(arrlist arrlist)
set(arrlistlib arrlistlib)
set(arrlisttest arrlisttest)
set(stacklist stacklist)
set(stacklistlib stacklistlib)
set(stacklisttest stacklisttest)
set(polynom polynom)
set(polynomlib polynomlib)
set(polynomtest polynomtest)
set(polish polish)
set(polishlib polishlib)
set(polishtest polishtest)
set(text text)
set(textlib textlib)
set(texttest texttest)
set(plex plex)
set(plexlib plexlib)
set(plextest plextest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vectorlib
 ${CMAKE_CURRENT_SOURCE_DIR}/gtest
 ${CMAKE_CURRENT_SOURCE_DIR}/exception
 ${CMAKE_CURRENT_SOURCE_DIR}/stacklib
 ${CMAKE_CURRENT_SOURCE_DIR}/queuelib
 ${CMAKE_CURRENT_SOURCE_DIR}/multistacklib
 ${CMAKE_CURRENT_SOURCE_DIR}/listlib
 ${CMAKE_CURRENT_SOURCE_DIR}/arrlistlib
 ${CMAKE_CURRENT_SOURCE_DIR}/stacklistlib
 ${CMAKE_CURRENT_SOURCE_DIR}/polynomlib
 ${CMAKE_CURRENT_SOURCE_DIR}/polishlib
 ${CMAKE_CURRENT_SOURCE_DIR}/textlib
 ${CMAKE_CURRENT_SOURCE_DIR}/plexlib
 )

add_subdirectory(vector)
add_subdirectory(vectorlib)
add_subdirectory(gtest)
add_subdirectory(vectortest)
add_subdirectory(stack)
add_subdirectory(stacklib)
add_subdirectory(stacktest)
add_subdirectory(exception)
add_subdirectory(queue)
add_subdirectory(queuetest)
add_subdirectory(queuelib)
add_subdirectory(multistack)
add_subdirectory(multistacktest)
add_subdirectory(multistacklib)
add_subdirectory(list)
add_subdirectory(listlib)
add_subdirectory(listtest)
add_subdirectory(arrlist)
add_subdirectory(arrlistlib)
add_subdirectory(arrlisttest)
add_subdirectory(stacklist)
add_subdirectory(stacklistlib)
add_subdirectory(stacklisttest)
add_subdirectory(polynom)
add_subdirectory(polynomlib)
add_subdirectory(polynomtest)
add_subdirectory(polish)
add_subdirectory(polishlib)
add_subdirectory(polishtest)
add_subdirectory(text)
add_subdirectory(textlib)
add_subdirectory(texttest)
add_subdirectory(plex)
add_subdirectory(plexlib)
add_subdirectory(plextest)
