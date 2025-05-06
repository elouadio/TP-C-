# Créer un executable à partir de fichiers sources
add_executable(test_interraction  test_interraction.cxx)
add_executable(test_univers  test_univers.cxx)
# Fait le lien avec la bibliothèque créée précedemment
# Les entêtes sont automatiquement détectés.
target_link_libraries(test_interraction particule)
target_link_libraries(test_univers univers simulate)