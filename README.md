# TP de Simulation Numérique – README

Ce dépôt contient l'ensemble des travaux pratiques (Labs) réalisés dans le cadre du cours de simulation numérique. Chaque lab permet de découvrir et implémenter progressivement les éléments constitutifs d'un simulateur de particules.

---

## 📁 Structure des Labs

### 🧪 Lab 1 – Introduction

- Présentation du projet.
- Mise en place d'un squelette de code.
- Objectifs : prise en main de l'environnement de développement et familiarisation avec le langage C++.

📂 **Contenu :**
- Premiers fichiers sources.
- Premiers tests de compilation et d’exécution.

---

### ⚛️ Lab 2 – Particules

- Représentation des particules dans l’espace.
- Gestion des propriétés physiques élémentaires.

📂 **Contenu :**
- Structures de données pour les particules.
- Premiers calculs physiques.

---

### ➕ Lab 3 – Opérateurs & Infrastructure

- Implémentation des opérateurs mathématiques (vecteurs, forces…).
- Organisation du projet avec `CMakeLists.txt`.

📂 **Contenu :**
- Fichiers de base pour la construction du projet.
- Architecture des répertoires (`src/`, `include/`, etc.).

---

### 🧩 Lab 4 – Découpage de l’espace

- Mise en place d’un découpage spatial (grille, cellules, etc.).
- Optimisation de la recherche de voisins.

📂 **Contenu :**
- Structures de partitionnement.
- Préparation pour l’optimisation des calculs.

---

### 🧪 Lab 5 – Tests & Visualisation

- Ajout de tests unitaires pour valider le code.
- Intégration d’un module de visualisation (format VTK).
- Réorganisation du projet avec une infrastructure complète.

📂 **Contenu :**
- Répertoires standardisés.
- Fichier d’exemple `.vtk` pour visualiser les résultats.

---

### 🔍 Lab 6 – Raffinement du modèle

- Amélioration des lois physiques et des algorithmes.
- Optimisations pour les simulations de grande échelle.

📂 **Contenu :**
- Version plus robuste et efficace du simulateur.
- Préparation pour des simulations plus complexes.

---

## 🛠️ Compilation

Chaque lab contient un fichier `CMakeLists.txt` permettant une compilation simple :

```bash
mkdir build
cd build
cmake ..
make
