'''
highest height a set of boxes can be stacked when
each stacked box has a smaller width and smaller length 
than the box below it
'''

type Box = tuple[int]

from collections import defaultdict

def height_tallest_stack(boxes : list[Box]):

    boxes.sort()
    total_highest_height : int = 0

    max_heights_per_box  = {} # defaultdict(int)

    for box in boxes:

        valid_box_heights = [max_heights_per_box[smaller_box] for smaller_box in boxes if smaller_box[0] < box[0] and smaller_box[1] < box[0]]
        
        box_max_height = box[2] + max(valid_box_heights, default=0)

        total_highest_height = max(total_highest_height, box_max_height)
        max_heights_per_box[box] = total_highest_height

        print(f"for box {box}, box max height is {box_max_height}, max height is {total_highest_height}, with valid boxes {valid_box_heights}")
    
    return total_highest_height


if __name__ == "__main__":

    boxes1 : list[Box] = [(2, 3, 3), (2, 2, 4), (4, 4, 2)]
    boxes2 : list[Box] = [(4, 5, 3), (2, 3, 2), (3, 6, 2), (1, 5, 4), (2, 4, 1), (1, 2, 2)]

    tallest1 : int = height_tallest_stack(boxes1)
    print(f"with {boxes1}, tallest is {tallest1}")

    print("\n")

    tallest2 : int = height_tallest_stack(boxes2)
    print(f"with {boxes2}, tallest is {tallest2}")