# Créer un executable à partir de fichiers sources
add_executable(test_vecteur  test_vecteur.cxx)
add_executable(test_particule test_particule.cxx)
add_executable(test_univer test_univer.cxx)
add_executable(test_avancer_univer test_avancer_univer.cxx)
add_executable(test_performance_univer test_performance_univer.cxx)

# Fait le lien avec la bibliothèque créée précedemment
# Les entêtes sont automatiquement détectés.
target_link_libraries(test_vecteur vecteur)
target_link_libraries(test_particule particule)
target_link_libraries(test_univer univers simulate)
target_link_libraries(test_avancer_univer univers simulate)
target_link_libraries(test_performance_univer univers simulate)
