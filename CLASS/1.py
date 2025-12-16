import matplotlib.pyplot as plt
import numpy as np

xp = np.array([600,900, 190, 900]) 
yp = np.array([1000, 2000, 1009, 900]) 


plt.plot(xp, yp, marker = 'o')

plt.ylabel("Average Pulse")
plt.xlabel("Calorie Burnage")

plt.show()

