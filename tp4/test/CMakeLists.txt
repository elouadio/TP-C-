# Créer un executable à partir de fichiers sources
add_executable(test_interraction  test_interraction.cxx)
add_executable(test_univers  test_univers.cxx)
add_executable(test_simulate  test_simuate.cxx)
add_executable(test_graphique  test_graphique.cxx)
add_executable(test_visu  test_visu.cxx)
# Fait le lien avec la bibliothèque créée précedemment
# Les entêtes sont automatiquement détectés.
target_link_libraries(test_interraction particule)
target_link_libraries(test_univers univers simulate)
target_link_libraries(test_simulate univers simulate)
target_link_libraries(test_graphique univers simulate)
target_link_libraries(test_visu univers simulate)