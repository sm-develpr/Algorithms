11206.615
import pandas as pd

# Загрузка датасета
df = pd.read_csv('star_dataset.csv')

# Фильтрация звезд с радиусом больше радиуса Солнца
larger_than_sun = df[df['Radius (R/R0)'] > 1]

# Расчет средней температуры
average_temperature = larger_than_sun['Temperature (K)'].mean()

# Округление до трех знаков после запятой
average_temperature_rounded = round(average_temperature, 3)

# Вывод результата
print(average_temperature_rounded)