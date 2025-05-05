# Créer un executable à partir de fichiers sources
add_executable(test_point  test_point.cxx)
add_executable(collection_particule  collection_particule.cxx)
add_executable(test_performance  test_performance.cxx)
add_executable(test_simulation  test_simulation.cxx)

# Fait le lien avec la bibliothèque créée précedemment
# Les entêtes sont automatiquement détectés.
target_link_libraries(test_point particule)
target_link_libraries(collection_particule particule)
target_link_libraries(test_performance particule)
target_link_libraries(test_simulation simulation)
