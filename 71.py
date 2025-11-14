def meeting_point(distance, speed_a, speed_b):
    relative_speed = speed_a + speed_b
    time = distance / relative_speed
    meet_from_a = speed_a * time
    return time, meet_from_a

distance = 24
speed_a = 6
speed_b = 10

time, meet_from_a = meeting_point(distance, speed_a, speed_b)
print("Time to meet:", time, "hours")
print("Distance from A:", meet_from_a, "miles")
