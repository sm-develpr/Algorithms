#Alpha Centauri B, Rigil Kentaurus, Barnard's Star
import pandas as pd

# Загрузка датасета
df = pd.read_csv('star_dataset.csv')

# Сортировка по расстоянию и выбор уникальных названий
closest_stars = df.sort_values(by='Distance (ly)').drop_duplicates(subset=['Name']).head(3)

# Извлечение названий звезд
top_3_stars = closest_stars['Name'].tolist()

# Вывод результатов
print(top_3_stars)
