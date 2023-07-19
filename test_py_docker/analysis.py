# Import libraries
from pandas import read_csv
from numpy import sort

# Extract years chronologically
movies_data = read_csv("movies_by_genre.csv")
years_covered = movies_data.year.unique()
years_covered = sort(years_covered)

for year in years_covered:
    print(year)