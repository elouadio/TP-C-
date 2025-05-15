import pandas as pd
import matplotlib.pyplot as plt

# Chargement des données
data = pd.read_csv("positions_finales.csv")

# 🔹 Filtrage des particules qui sont DANS l'univers uniquement
carres = data[(data['Type'] == "carre") & (data['OutOfBounds'] == False)]
rectangles = data[(data['Type'] == "rectangle") & (data['OutOfBounds'] == False)]

# 🔹 Vérification du contenu (Debugging)
print("=== Carrés dans l'univers ===")
print(carres.head())

print("\n=== Rectangles dans l'univers ===")
print(rectangles.head())

# 🔹 Création du graphique
plt.figure(figsize=(10, 6))

# Points dans l'univers
plt.scatter(carres['X'], carres['Y'], c='red', label='Carré (dans l\'univers)', s=5)
plt.scatter(rectangles['X'], rectangles['Y'], c='blue', label='Rectangle (dans l\'univers)', s=5)

# Affichage des limites de l'univers
plt.xlim(0, 250)
plt.ylim(0, 100)

# Ajustements visuels
plt.title("Positions finales des particules (Dans l'univers uniquement)")
plt.xlabel("Position X")
plt.ylabel("Position Y")
plt.legend()
plt.grid(True)

# Affichage
plt.show()
