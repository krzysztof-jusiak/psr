include(CTest)

add_executable (unit_controller unit/controller/guards/has_inc_ids.cpp)
target_include_directories(unit_controller PRIVATE include ../include SYSTEM ${CMAKE_SOURCE_DIR}/vendor)
add_test(NAME unit_controller COMMAND unit_controller)

add_executable (unit_model unit/model/model.cpp)
target_include_directories(unit_model PRIVATE include ../include SYSTEM ${CMAKE_SOURCE_DIR}/vendor)
add_test(NAME unit_model COMMAND unit_model)

add_executable (unit_players unit/players/human.cpp)
target_include_directories(unit_players PRIVATE include ../include SYSTEM ${CMAKE_SOURCE_DIR}/vendor)
add_test(NAME unit_players COMMAND unit_players)

add_executable (unit_states unit/states/rounds.cpp)
target_include_directories(unit_states PRIVATE include ../include SYSTEM ${CMAKE_SOURCE_DIR}/vendor)
add_test(NAME unit_states COMMAND unit_states)

add_executable (feature_game feature/controller/game.cpp)
target_include_directories(feature_game PRIVATE include ../include SYSTEM ${CMAKE_SOURCE_DIR}/vendor)
add_test(NAME feature_game COMMAND feature_game)
