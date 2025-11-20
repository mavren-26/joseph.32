def findMinArrows(points):
    points.sort(key=lambda x: x[1])  # sort by end

    arrows = 1
    end = points[0][1]

    for x, y in points[1:]:
        if x > end:    # need new arrow
            arrows += 1
            end = y
    return arrows

# Driver
print(findMinArrows([[10,16],[2,8],[1,6],[7,12]]))
