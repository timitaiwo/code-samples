from relation_functions import *

main_set = {'a', 'b', 'c'}

relation_1 = {('a', 'a'), ('b', 'b'), ('c', 'c')}
relation_2 = {('b', 'b'), ('b', 'c'), ('c', 'b'), ('a', 'c'), ('c', 'a')}
relation_3 = {('a', 'a'), ('a', 'c'), ('a', 'b'), ('c', 'c'), ('c', 'b'), ('b', 'b')}


print("\nTest reflexivity")
rel_1_reflexive = is_reflexive(relation_1, main_set)
rel_2_reflexive = is_reflexive(relation_2, main_set)
rel_3_reflexive = is_reflexive(relation_3, main_set)

print("Test Symmetricity")
rel_1_symmetric = is_symmetric(relation_1)
rel_2_symmetric = is_symmetric(relation_2)
rel_3_symmetric = is_symmetric(relation_3)

print("Test AntiSymmetricity")
rel_1_antisymmetric = is_antisymmetric(relation_1)
rel_2_antisymmetric = is_antisymmetric(relation_2)
rel_3_antisymmetric = is_antisymmetric(relation_3)
print("")


print("Is Rel 1 reflexive? ", rel_1_reflexive)
print("Is Rel 1 symmetric? ", rel_1_symmetric)
print("Is Rel 1 antisymmetric? ", rel_1_antisymmetric)
print("")


print("Is Rel 2 reflexive? ", rel_2_reflexive)
print("Is Rel 2 symmetric? ", rel_2_symmetric)
print("Is Rel 2 antisymmetric? ", rel_2_antisymmetric)
print("")


print("Is Rel 3 reflexive? ", rel_3_reflexive)
print("Is Rel 3 symmetric? ", rel_3_symmetric)
print("Is Rel 3 antisymmetric? ", rel_3_antisymmetric)
