function meetingPoint(distance, speedA, speedB) {
  let relativeSpeed = speedA + speedB;
  let time = distance / relativeSpeed;
  let meetFromA = speedA * time;

  console.log("Time to meet:", time, "hours");
  console.log("Distance from A:", meetFromA, "miles");
}

meetingPoint(24, 6, 10);
