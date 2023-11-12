def is_reflexive(relation: set[tuple], input_set: set) -> bool:
    len_set = len(input_set)

    reflexive_rel = {(x,x) for x in input_set}
    expected_rel_num = len(reflexive_rel)

    if len_set < expected_rel_num:
        return False
    
    num_x_x_pairs = 0

    for rel in reflexive_rel:
        if rel in relation:
            num_x_x_pairs += 1

    if num_x_x_pairs == expected_rel_num:
        return True
    else:
        return False


def is_symmetric(relation:set[tuple]) -> bool:
    for rel in relation:
        val_1 = rel[0]
        val_2 = rel[1]

        if (val_2, val_1) in relation:
            pass
        else:
            return False
        
    return True


def is_antisymmetric(relation:set[tuple]) -> bool:
    for rel in relation:
        val_1 = rel[0]
        val_2 = rel[1]

        if (val_2, val_1) in relation:
            if val_2 == val_1:
                pass
            else:
                return False
    
    return True

                                                                             

def is_transitive(relation, input_set):
    pass

