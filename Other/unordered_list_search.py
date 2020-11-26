# Searching for an item in an unordere list
# sometimes called linear Search

# declare list of values to work on
items = [6, 20, 8, 19, 56, 23, 87, 41, 49, 53]

def find_item(item, items):
    for index in range(0, len(items)):
        if item == items[index]:
            return index
    return "None"

def dummy_find(items):
    return find_item(items, 20)

def dummy_find2(items):
    return find_item(items, 8)

print(find_item(87, items))
print(find_item(250, items))
