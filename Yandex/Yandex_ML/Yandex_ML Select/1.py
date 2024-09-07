#28

import pandas as pd

# Загрузка датасета
df = pd.read_csv('star_dataset.csv')

# Получение уникальных спектральных классов
unique_spectral_classes = df['Spectral Class'].nunique()

# Вывод количества уникальных спектральных классов
print(unique_spectral_classes)