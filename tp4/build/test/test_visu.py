import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Chargement des données
data = pd.read_csv("positions_finales.csv")

# 🔹 Filtrage des particules qui sont DANS l'univers uniquement
carres = data[(data['Type'] == "carre") & (data['OutOfBounds'] == False)]
rectangles = data[(data['Type'] == "rectangle") & (data['OutOfBounds'] == False)]

# 🔹 Création de la figure
fig, ax = plt.subplots(figsize=(10, 6))
plt.xlim(0, 250)
plt.ylim(0, 100)
plt.title("Simulation des positions des particules dans l'univers")
plt.xlabel("Position X")
plt.ylabel("Position Y")

# 🔹 Initialisation des points
scatter_carres = ax.scatter([], [], c='red', label='Carré (dans l\'univers)', s=5)
scatter_rectangles = ax.scatter([], [], c='blue', label='Rectangle (dans l\'univers)', s=5)
plt.legend()

# 🔹 Fonction d'animation
def update(frame):
    # Récupération des données à chaque frame
    carres_frame = carres[carres['ID'] % 10 == frame]
    rectangles_frame = rectangles[rectangles['ID'] % 10 == frame]

    # Mise à jour des données dans le graphique
    scatter_carres.set_offsets(carres_frame[['X', 'Y']].values)
    scatter_rectangles.set_offsets(rectangles_frame[['X', 'Y']].values)

# 🔹 Animation
ani = FuncAnimation(fig, update, frames=10, interval=500)

# 🔹 Affichage
plt.show()
