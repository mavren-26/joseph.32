function markedPrice(cp, profit, discount) {
  let sp = cp * (1 + profit / 100);
  let mp = sp / (1 - discount / 100);
  return mp;
}

let mp = markedPrice(800, 25, 10);
console.log("Required Marked Price: $" + mp);
