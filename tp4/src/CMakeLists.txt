# Créer une bibliothèque à partir d'un ensemble de fichiers de définitions (.cxx) sans main.
# Ces fichiers ne contiennent pas de fonction main
# Remplacer ... par les fichiers nécessaires 
add_library(vecteur vecteur.cxx)
add_library(particule
    vecteur.cxx
    particule.cxx
)
add_library(univers
    univers.cxx
    particule.cxx
    vecteur.cxx
)
add_library(simulate
    univers.cxx
    particule.cxx
    vecteur.cxx
    simulate.cxx
)
