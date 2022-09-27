cmake_minimum_required(VERSION 3.23)
project(oop_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_project Game/main.cpp Game/Player/Player.cpp Game/Player/Player.h Game/Map/Field/Field.cpp Game/Map/Field/Field.h Game/Map/Field/Cell/Cell.cpp Game/Map/Field/Cell/Cell.h Game/Map/Field/Cell/Cell_Event/Cell_Event.cpp Game/Map/Field/Cell/Cell_Event/Cell_Event.h Game/Map/FieldView.cpp Game/Map/FieldView.h Game/Controller.cpp Game/Controller.h)
